public class Main {
    public static void reportPoint(double x, double y){
        System.out.print("Point(" + x + ", " + y + ") ");
        return;
    }

    public static void reportCircle(double x, double y, double r){
        System.out.print("Circle(" + x + ", " + y + ") Radius: " + r + " ");
        return;
    }

    public static void reportRectangle(double left, double top, double width, double height){
        double right = left + width;
        double bottom = top - height;
        System.out.print("Rectangle(" + left + ", " + top + ", " + width + ", " + height + ") ");
        return;
    }

    public static boolean isPointInsideCircle(double ptx, double pty, double circlex, double circley, double circler){
        if((ptx - circlex) * 2 + (pty - circley) * 2 <  circler * 2) {
            return true;
        }
        else return false;
    }

    public static boolean isPointInsideRectangle(double ptx, double pty, double rectleft, double recttop, double rectwidth, double rectheight){
        double rectright = rectleft + rectwidth;
        double rectbottom = recttop - rectheight;
        if(ptx >= rectleft && ptx <= rectright && pty <= recttop && pty >= rectbottom){
            return true;
        }
        else return false;
    }

    public static void main(String[] args) {
        double[] ptX = { 1, 2, 3, 4 };
        double[] ptY = { 1, 2, 3, 4 };
        double[] circleX = { 0, 5 };
        double[] circleY = { 0, 5 };
        double[] circleRadius = { 3, 3 };
        double[] rectLeft = { -2.5, -2.5 };
        double[] rectTop = { 2.5, 5.0 };
        double[] rectWidth = { 6.0, 5.0 };
        double[] rectHeight = { 5.0, 2.5 };

        //circles
        System.out.println("\n --- Report of Points and Circles --- \n");
        for(int i = 0; i < ptX.length; i++){
            for(int j = 0; j < circleX.length; j++){
                reportPoint(ptX[i], ptY[i]);
                System.out.print("is ");
                if(isPointInsideCircle(ptX[i], ptY[i], circleX[j], circleY[j], circleRadius[j])){
                    System.out.print("inside ");
                }
                else System.out.print("outside ");
                reportCircle(circleX[j], circleY[j], circleRadius[j]);
                System.out.print("\n");
            }
        }

        //rectangles
        System.out.println("\n --- Report of Points and Rectangles --- \n");
        for(int i = 0; i < ptX.length; i++){
            for(int j = 0; j < rectLeft.length; j++){
                reportPoint(ptX[i], ptY[i]);
                System.out.print("is ");
                if(isPointInsideRectangle(ptX[i], ptY[i], rectLeft[j], rectTop[j], rectWidth[j], rectHeight[j])){
                    System.out.print("inside ");
                }
                else System.out.print("outside ");
                reportRectangle(rectLeft[j], rectTop[j], rectWidth[j], rectHeight[j]);
                System.out.print("\n");
            }
        }
    }
}

