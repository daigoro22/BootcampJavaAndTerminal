import static java.lang.System.*;

public class ThreadSubject1{
	public static Object waitObj = new Object();

	public static void main(String... args){
		Thread t1 = new Thread(()->{
			synchronized(ThreadSubject1.waitObj){
				try{
					ThreadSubject1.waitObj.wait();
				}catch(Exception e){
					out.println(e);
				}
			}
			out.println("Thread1 running..");
		});	

		Thread t2 = new Thread(){
			@Override
			public void run(){
				out.println("Thread2 running...");
				try{
					Thread.sleep(1000);
				}catch(Exception e){
					out.print(e);
				}
				synchronized(ThreadSubject1.waitObj){
					ThreadSubject1.waitObj.notifyAll();
				}
			}
		};

		t1.start();
		t2.start();
	}
}
