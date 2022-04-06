
class Base {
    public void printA() {
        System.out.println("base\n");
    }

    public void printB() {
        System.out.println("base\n");
    }
}

class Driver extends Base {
    public void printA() {
        System.out.println("driver\n");
    }

    public void printB(Driver driver) {
        System.out.println("driver\n");

    }
}


public class Main {
    public static void main(String[] args) {
        Base base = new Driver();
        Driver driver = new Driver();

        base.printA();  //- (1)
        driver.printA();  //- (2)

        base.printB(driver); //(3)
        base.printB(driver);
    }
}


