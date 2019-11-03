import java.util.ArrayList;
import java.util.Random;
import java.io.*;
import java.lang.Math;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        ArrayList<Double> act0ve_array = new ArrayList<Double>();
        try {
            PrintStream db = new PrintStream(new File("db.txt"));
            Random rand = new Random();
            int max = (int)Math.pow(10, 9);
            for (int x = 0; x < max; x++) {
                double temp = rand.nextInt(10001) + rand.nextInt(100) / 100.0;
                db.println(temp);
                if (x % 100000 == 0) {
                    double pct = ((double)x / (double)max) * 100;
                    System.out.println("We have " + pct + "% done!");
                }
            }
            Scanner s = new Scanner(new File("db.txt"));
            while(s.hasNextDouble()) {
                act0ve_array.add(s.nextDouble());
            }
            /*int count = 0;
            for (int i = 0; i < act0ve_array.size(); i++) {
                if (act0ve_array.get(i) % 5 == 0.0)
                    count++;
            }*/
            int thread_cnt = 4;
            Runnable r[] = new Runnable[thread_cnt];
            Thread threads[] = new Thread[thread_cnt];
            int[] counts = new int[thread_cnt];
            int chunk = max/thread_cnt;
            for(int x = 0; x < thread_cnt; x++) {
                r[x] = new ParallelChecker(chunk*x, chunk * (x+1), act0ve_array, counts, x);
                threads[x] = new Thread(r[x]);
                threads[x].start();
            }
            for(int x = 0; x < thread_cnt; x++){
                try {
                    threads[x].join();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
            int count = 0;
            for (int x = 0; x < thread_cnt; x++) {
                count += counts[x];
            }
            System.out.println("Found " + count);
        } catch(FileNotFoundException e) {
            System.out.println("I'm a meme");
        }
    }

}