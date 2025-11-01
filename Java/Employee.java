public class Employee {

    private int id;
    private String name;
    private String role;
    private int yearEmployed;

    public Employee(int id, String name, String role, int yearEmployed) {
        this.id = id;
        this.name = name;
        this.role = role;
        this.yearEmployed = yearEmployed;
    }

    public void setId(int id) {
        this.id = id;
    }

    public int getId() {
        return id;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public void setRole(String role) {
        this.role = role;
    }

    public String getRole() {
        return role;
    }

    public void setYearEmployed(int yearEmployed) {
        this.yearEmployed = yearEmployed;
    }

    public int getYearEmployed() {
        return yearEmployed;
    }
}
