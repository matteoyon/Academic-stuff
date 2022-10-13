import SDes.SDes;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Scrivi 12 bit");
        String l1r1 = input.nextLine();
        System.out.println("Scrivi una Chiave di 9 bit");
        String key = input.nextLine();

        String l4r4 = SDes.cypher(l1r1,key);
        System.out.println("Il testo cifrato è " + l4r4);
        return;
    }
}