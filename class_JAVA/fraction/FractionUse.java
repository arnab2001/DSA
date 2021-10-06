package fraction;

public class FractionUse {

	public static void main(String[] args) {
		Fraction f1= new Fraction(4,6);
		f1.print();
		f1.setNumerator(8);
		System.out.println(f1.getNumerator());
		f1.increment();
		f1.print();
		Fraction f2= new Fraction(2,3);
		f2.print();
		f2.setNumerator(7);
		System.out.println(f2.getNumerator());
		f1.add(f2);
		f1.print();
		Fraction f3= Fraction.add(f1,f2);
		f3.print();
		Fraction f4= Fraction.subtract(f1, f2);
		f4.print();
		Fraction f5= Fraction.multiply(f1, f2);
		f5.print();
		Fraction f6= Fraction.divide(f1, f2);
		f6.print();
		
		
		


	}

}
