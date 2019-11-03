import java.util.ArrayList;

public class ParallelReader implements Runnable {
	
	private ArrayList<Customer> working_list;
	private int start, stop;
	private int[] count;
	private int pos;

	public ParallelReader(int start, int stop, ArrayList<Customer> list, int[] count, int pos) {
		this.working_list = list;
		this.start = start;
		this.stop = stop;
		this.count = count;
		this.pos = pos;
	}

	public void run() {
		for (int i = this.start; i < this.stop; i++) {
			if (this.working_list.get(i).getBalance() < 1000) {
				this.count[this.pos]++;
			}
		}
	}

}
