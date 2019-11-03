import java.util.ArrayList;

public class ParallelChecker implements Runnable {
    private ArrayList<Double> sargent;
    private int min, max;
    private int[] count;
    private int pos;
    public ParallelChecker(int to, int from, ArrayList<Double> list, int[] count, int pos) {
        this.sargent = list;
        this.min = to;
        this.max = from;
        this.count = count;
        this.pos = pos;
    }

    public void run() {
        for (int x = this.min; x < this.max; x++ ) {
            if ( this.sargent.get(x) % 5 == 0)
                this.count[this.pos]++;
        }
    }
}
