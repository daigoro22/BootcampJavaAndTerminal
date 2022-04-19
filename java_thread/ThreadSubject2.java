import java.util.ArrayList;
import java.util.Arrays;

class NameAddThread extends Thread{
	private ArrayList list;

	public NameAddThread(ArrayList list){
		synchronized(list){
			this.list = list;
		}
	}
	@Override
	public void run(){
		String[] nameList = new String[100];
		Arrays.fill(nameList,Thread.currentThread().getName());
		synchronized(this.list){
			this.list.addAll(Arrays.asList(nameList));
		}
	}
}

class ThreadSubject2{
	public static void main(String... args){
		var list = new ArrayList<String>();
		var listThread = new ArrayList<NameAddThread>();
		
		for(int i=0;i<10;i++){
			listThread.add(new NameAddThread(list));
		}
		listThread.forEach(Thread::start);

		listThread.forEach(t->{
			try{
				t.join();
			}catch(Exception e){
				System.out.println(e);
			}
		});

		synchronized(list){
			list.forEach(System.out::println);
		}
	}
}
