import java.io.*;
import java.util.Scanner;

public class basic_search {
	
	public static void main(String[] args) {

		System.out.println("Line Entry: ");
		Scanner sc = new Scanner(System.in);
		String line = sc.nextLine();

		System.out.println("Token Entry: ");
		Scanner sc2 = new Scanner(System.in);
		String token = sc2.nextLine();

		if (line.contains(token)) {
			System.out.println("FOUND");
		}
		else {
			System.out.println("NOT FOUND");
		}


	}

}
