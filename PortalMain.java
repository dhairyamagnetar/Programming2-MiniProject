import demo.DemoPortal;
import java.util.Scanner;

public class PortalMain {
	public static void main(String[] args) {
		DemoPortal portal = new DemoPortal("unqid1");
		
		Scanner sc = new Scanner(System.in);
		String line;
		while(true){
			line = sc.nextLine();
			portal.processUserCommand(line);
		}
	}
}