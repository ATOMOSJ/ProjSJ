import java.util.Scanner;

public class Time {
    private int hours;
    private int minutes;
    private int seconds;

    public Time(int hours, int minutes, int seconds) {
        this.hours = hours;
        this.minutes = minutes;
        this.seconds = seconds;
    }

    // Getter and setter methods for hours, minutes and seconds
    public int getHours() {
        return hours;
    }

    public void setHours(int hours) {
        this.hours = hours;
    }

    public int getMinutes() {
        return minutes;
    }

    public void setMinutes(int minutes) {
        this.minutes = minutes;
    }

    public int getSeconds() {
        return seconds;
    }

    public void setSeconds(int seconds) {
        this.seconds = seconds;
    }

    // Function to convert Time object to time string in format "HH:MM:SS"
    public String toString() {
        String timeStr = "";
        if (hours < 10) {
            timeStr += "0";
        }
        timeStr += hours + ":";
        if (minutes < 10) {
            timeStr += "0";
        }
        timeStr += minutes + ":";
        if (seconds < 10) {
            timeStr += "0";
        }
        timeStr += seconds;
        return timeStr;
    }

    // Function to add two Time objects
    public Time add(Time t) {
        int totalSeconds = this.seconds + t.getSeconds() + (this.minutes + t.getMinutes()) * 60 + (this.hours + t.getHours()) * 3600;
        int hours = totalSeconds / 3600;
        int minutes = (totalSeconds % 3600) / 60;
        int seconds = totalSeconds % 60;
        return new Time(hours, minutes, seconds);
    }

    // Function to subtract two Time objects
    public Time subtract(Time t) {
        int totalSeconds = this.seconds - t.getSeconds() + (this.minutes - t.getMinutes()) * 60 + (this.hours - t.getHours()) * 3600;
        int hours = totalSeconds / 3600;
        int minutes = (totalSeconds % 3600) / 60;
        int seconds = totalSeconds % 60;
        return new Time(hours, minutes, seconds);
    }

 public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter first time in HH:MM:SS format");
        String time1 = sc.nextLine();
        Time t1 = createTimeFromTimeString(time1);

        System.out.println("Enter second time in HH:MM:SS format");
        String time2 = sc.nextLine();
        Time t2 = createTimeFromTimeString(time2);

        Time sumTime = t1.add(t2);
        Time diffTime = t1.subtract(t2);

        System.out.println("Sum of times: " + sumTime.toString());
        System.out.println("Difference of times: " + diffTime.toString());

        sc.close();
    }

    // Function to create Time object from time string in format "HH:MM:SS"
    public static Time createTimeFromTimeString(String timeStr) {
        String[] timeArr = timeStr.split(":");
        int hours = Integer.parseInt(timeArr[0]);
        int minutes = Integer.parseInt(timeArr[1]);
        int seconds = Integer.parseInt(timeArr[2]);
        return new Time(hours, minutes, seconds);
    }
}

