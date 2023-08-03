interface Employee {
        double earnings(double basic);
        double deductions(double basic);
        double bonus(double basic);
        }

class Manager implements Employee  {
    @Override
    public double earnings(double basic) {
        return basic + 0.8*basic + 0.15*basic;
    }

    @Override
    public double deductions(double basic) {
        return 0.12*basic;
    }

    @Override
    public double bonus(double basic) {
        throw new UnsupportedOperationException("Not implemented");
    }
}

class Substaff extends Manager {
    @Override
    public double bonus(double basic) {
        return 0.5*basic;
    }
}

public class kol
{
    public static void main(String[] args) {
        double basic = Double.parseDouble(args[0]);
        Substaff substaff = new Substaff();

        double earnings = substaff.earnings(basic);
        double deductions = substaff.deductions(basic);
        double bonus = substaff.bonus(basic);

        System.out.println("Earnings: " + earnings);
        System.out.println("Deductions: " + deductions);
        System.out.println("Bonus: " + bonus);
    }
}
