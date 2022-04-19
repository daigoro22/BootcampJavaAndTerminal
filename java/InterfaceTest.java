import java.util.Scanner;

interface Animal{
	public void Bark();
}

class Dog implements Animal{
	public void Bark(){
		System.out.println("ワン");
	}
}

class Cat implements Animal{
	public void Bark(){
		System.out.println("ニャー");
	}
}

public class InterfaceTest{
	public static void main(String... args){
		Animal unknownAnimal;
		Scanner sc = new Scanner(System.in);
		System.out.println("Input \"c\" or \"d\".");
		String input = sc.nextLine();

		if(input.equals("c")){
			unknownAnimal = new Cat();
		}
		else if(input.equals("d")){
			unknownAnimal = new Dog();
		}else{
			System.out.println("cかdを入力してください");
			unknownAnimal = new Cat();
			System.exit(0);
		}

		unknownAnimal.Bark();
	}
}
		
