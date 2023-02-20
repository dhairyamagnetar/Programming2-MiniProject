package demo;
import ecomm.Portal;
import ecomm.Globals;

import java.io.*;
import java.util.*;

import demo.PortalProduct;

public class DemoPortal extends Portal {
	private final String PortalId; 
	private int RequestId;
	private HashMap<Integer,String> PendingRequestsType; // Map to store the type of each pending requests 
	private HashMap<Integer,String> SortParam; // Map to store the sorting parameter for each pending list command

	public DemoPortal(String PortalId) {
		this.PortalId = PortalId;
		this.RequestId = 1;
		PendingRequestsType = new HashMap<Integer, String>();
		SortParam = new HashMap<Integer, String>();
	}

	public void processUserCommand(String command) {
		String[] input = command.split("\\s+");
		if (input[0].equals("Check")) {
			checkResponse();
		} else if (input[0].equals("Buy")) {
			buyItem(input[1], input[2]);
		} else if (input[0].equals("List")) {
			AskForItems(input[1], input[2]);
		} else if(input[0].equals("Start")){
			start();
		}
		RequestId++;
	}

	private void start() {
		try {
			FileWriter out = new FileWriter(Globals.toPlatform, true);
			out.write("" + PortalId + " " + RequestId + " Start");
			out.write(String.format("%n"));
			out.close();
		} catch (IOException e) {
			System.out.println("IOException");
		}
		PendingRequestsType.put(RequestId, "Start");
	}

	private void AskForItems(String category, String parameter) {
		try {
			FileWriter out = new FileWriter(Globals.toPlatform, true);
			out.write("" + PortalId + " " + RequestId + " List " + category);
			out.write(String.format("%n"));
			out.close();
		} catch (IOException e) {
			System.out.println("IOException");
		}
		PendingRequestsType.put(RequestId, "List");
		SortParam.put(RequestId, parameter);
	}

	private void buyItem(String productId, String numItems) {
		try {
			FileWriter out = new FileWriter(Globals.toPlatform, true);
			out.write("" + PortalId + " " + RequestId + " Buy " + productId + " " + numItems);
			out.write(String.format("%n"));
			out.close();
			PendingRequestsType.put(RequestId, "Buy");
		} catch (IOException e) {
			System.out.println("IOException");
		}
	}

	ArrayList<String> readFileContents() {
		ArrayList<String> ret = new ArrayList<String>();
		try {
			BufferedReader in = new BufferedReader(new FileReader(Globals.fromPlatform));
			String line  = in.readLine();
			while(line.length()>1){
				if(line.length() > 1 && line.split("\\s+")[0].equals(PortalId)) ret.add(line);
				line = in.readLine();
			}
		} catch (Exception e) {
			// System.out.println("Some error occurred.");
		}
		return ret;
	}

	public void checkResponse() {
		ArrayList<String> fileContents = readFileContents();
		HashMap<Integer,ArrayList<PortalProduct>> products = new HashMap<Integer,ArrayList<PortalProduct>>();
		for(String line : fileContents){
			String[] words = line.split("\\s+");
			int reqId = Integer.parseInt(words[1]);
			if(!PendingRequestsType.containsKey(reqId)) continue;
			if(PendingRequestsType.get(reqId).equals("Buy")){
				System.out.println();
				System.out.println(words[2]);
				System.out.println();
				PendingRequestsType.remove(reqId);
			}else if(PendingRequestsType.get(reqId).equals("List")){
				if(products.get(reqId)==null){
					products.put(reqId, new ArrayList<PortalProduct>());
				}
				products.get(reqId).add(new PortalProduct(words));
			}else if(PendingRequestsType.get(reqId).equals("Start")){
				System.out.println();
				for(int i=2;i<words.length;i++){
					System.out.println(words[i]);
				}
				System.out.println();
				PendingRequestsType.remove(reqId);
			}
		}
		for(Map.Entry<Integer, ArrayList<PortalProduct>> m : products.entrySet()){
			ArrayList<PortalProduct> pdts = m.getValue();
			Collections.sort(pdts, new PortalProduct.ProductComp(SortParam.get(m.getKey())));
			System.out.println();
			for(PortalProduct pdt : pdts){
				System.out.println(pdt);
			}
			System.out.println();
			PendingRequestsType.remove(m.getKey());
			SortParam.remove(m.getKey());
		}
	}
}
