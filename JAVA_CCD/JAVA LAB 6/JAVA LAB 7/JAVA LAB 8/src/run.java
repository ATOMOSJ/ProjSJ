 class address {
    String ad;
    public void setAd(String ad) {
        this.ad = ad;
    }

    public String getAd() {
        return this.ad;
    }
}
class homeaddress extends address{
    public String getad(){
        return "HOME AD"+ super.getAd();
    }
}
class officeaddress extends address{
    public String getad(){
        return "office"+ super.getAd();
    }
}class schooladdress extends address{
    public String getad(){
        return "school"+ super.getAd();
    }
}
public class run{
    public static void main(String[] args) {
        address h1=new schooladdress();
        h1.setAd("bbsr");
        System.out.println(h1.getAd());
        address h2 =new officeaddress();
        h2.setAd("bbsr location 2");
        System.out.println(h2.getAd());
        address h3 =new homeaddress();
        h3.setAd("bbsr locatin 3");
        System.out.println(h3.getAd());


    }
}
