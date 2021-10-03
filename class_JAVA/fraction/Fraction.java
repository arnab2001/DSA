package fraction;

public class Fraction {
	private int numerator;
	private int denominator;
	
	
	// constructer to construct an object of class Fraction with arguments numerator and denominator
	public Fraction(int numerator,int denominator)
	{
		this.numerator=numerator;
		this.denominator= denominator;
		simplify();
	}
	
	// to get the Fraction in its simplest form// it is private as to simplify, it is an internal process and i dont want to give access of this to anyone
	private void simplify()
	{
		int gcd=1;
		int smallest= Math.min(numerator, denominator);
		for(int i=2;i<=smallest;i++)
		{
			if(numerator%i==0 && denominator%i==0)
			{
				gcd=i;
			}
		}
		//To get the fraction into its simplest form we divide the numerator and denominator with their gcd
		numerator= numerator/gcd;
		denominator= denominator/gcd;
	}
	
	public void print()
	{
		System.out.println(numerator+"/"+denominator);
	}
	
	public void setNumerator(int numerator)// to set numerator according to our choice
	{
		this.numerator= numerator;
		simplify();
	}
	
	public int getNumerator()
	{
		return this.numerator;
	}
	
	public void increment()
	{
		this.numerator= this.numerator+this.denominator;
		simplify();
	}
	
	public int getDenominator()
	{
		return this.denominator;
	}
	public void setDenominator(int denominator)
	{
		if(denominator==0)
		{
			return;
		}
		this.denominator= denominator;
	}
	
	//Function to add one fraction to the this fraction
	// to add a Fraction to another Fraction but by this the original Fraction will be lost and we wont be able to use it for some other purpose
	public void add(Fraction f2)
	{
		int n2= f2.numerator;
		int d2= f2.denominator;
		int n1= this.numerator;
		int d1= this.denominator;
		int lcm=1;
		int greater= Math.max(d1, d2);
		for(int i=greater;i<=d1*d2;i++)
		{
			if(i%d1==0 && i%d2==0)
			{
				lcm=i;
				break;
			}
		}
		this.denominator= lcm;
		this.numerator= ((lcm/d1)*n1)+((lcm/d2)*n2);
		simplify();
		
	}
	
	//Function to add two different fractions and it is static so can be called by class name only
	public static Fraction add(Fraction f1, Fraction f2)// to construct a new object of the same class and store the value of the sum in that object and then return the object
	{
		int num1= f1.numerator*f2.denominator + f2.numerator*f1.denominator;
		int den1= f1.denominator*f2.denominator;
		Fraction f3= new Fraction(num1,den1);
		return f3;
	
}
	public static Fraction subtract(Fraction f1,Fraction f2)// they are static as we are passing the Fractions already that are going to be used so no need to specify an object
	{
		int num1= f1.numerator*f2.denominator - f2.numerator*f1.denominator;
		int den1= f1.denominator*f2.denominator;
		Fraction f3= new Fraction(num1,den1);
		return f3;
	}
	
	public static Fraction multiply(Fraction f1, Fraction f2)
	{
		int num1= f1.numerator * f2.numerator;
		int den1= f1.denominator*f2.denominator;
		Fraction f3= new Fraction(num1,den1);
		return f3;
	}
	
	public static Fraction divide(Fraction f1,Fraction f2)
	{
		int num1= f1.numerator * f2.denominator;
		int den1= f1.denominator*f2.numerator;
		Fraction f3= new Fraction(num1,den1);
		return f3;
	}
	
}
