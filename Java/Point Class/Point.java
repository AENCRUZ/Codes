public class Point {
    private int x;
    private int y;

    // setters
    public void setX(int x) {
        this.x = x;
    }

    public void setY(int y) {
        this.y = y;
    }

    // getters
    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public void printCoordinates() {
        System.out.println("(" + x + "," + y + ")");
    }

    public double calculateDistance() {
        return Math.sqrt((x * x) + (y * y));
    }
}
