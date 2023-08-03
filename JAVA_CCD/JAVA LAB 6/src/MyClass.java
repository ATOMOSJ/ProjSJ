public class MyClass {
        private static int id;
        private String name;

        public MyClass(String name) {
            id ++;
            this.name = name;
        }

        public int getId() {
            return id;
        }

        public String getName() {
            return name;
        }

        public static int getNumObjects() {
            return id;
        }

        public static void main(String[] args) {
            MyClass obj1 = new MyClass("Alice");
            MyClass obj2 = new MyClass("Bob");
            MyClass obj3 = new MyClass("Charlie");

            System.out.println("Number of objects created: " + MyClass.getNumObjects());
        }
    }


