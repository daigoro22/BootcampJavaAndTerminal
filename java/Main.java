public class Main {
    public static void main(String... args) {
	    Person p = new Person();
	    p.setHeight(300);
	    System.out.println(p.getHeight());
    }
}

class Person{
	private int heightCm;

	public int getHeight(){
		System.out.println("heightCmが参照されました");
		return this.heightCm;
	}	

	public void setHeight(int heightCm){
		if(heightCm>250){
			this.heightCm= 250;
		}else{
			this.heightCm= heightCm;
		}
	}
}	
