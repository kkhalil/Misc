// Dilpreet Chana
// BasicAssign3.java
// Write a program that allows the user to enter the co-ordinates of a point (x,y) and a line
// (x1, y1, x2, y2) and tells them is the point is on the line or not.

import java.util.*;
import java.awt.geom.*;

public class BasicAssign3 {
	public static void main(String[] args) {
		Scanner kb = new Scanner(System.in);
		double  x = kb.nextDouble(),
				y = kb.nextDouble(),
				x1 = kb.nextDouble(),
				y1 = kb.nextDouble(),
				x2 = kb.nextDouble(),
				y2 = kb.nextDouble();
		 Point2D.Double point = new Point2D.Double(x, y);  // Create point object
		 Line2D.Double line = new Line2D.Double(x1, y1, x2, y2);  // Create line object

		 // Check if the line intersects line
		 // <= 0.000001 is to accomadate for double rounding error
		 if (Math.abs(line.ptLineDist(point)) <= 0.000001) {
		 	System.out.println("Does intersect");
		 } else {
		 	System.out.println("Does not intersect");
		 }
	}
}