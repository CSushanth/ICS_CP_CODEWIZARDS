#include<stdio.h>
#include<math.h>
#define pi 3.14159


 struct Rectangle{
     float length;
     float width;
     }; 
struct Triangle{
    float base;
    float height;
    };
struct Trapezoid{
    float base1; 
    float base2;
    float height;
    };
struct Ellipse{
    float majorAxis;
    float minorAxis;
    };
struct Parallelogram{
    float base;
    float height;
    };
struct Rhombus{
    float diagonal1; 
    float diagonal2;
    };
    
struct regularpolygon{
    int n;
    float side;
    float perimeter,apothem;
    
    };
 
struct Point {
    double x;
    double y;
};


float calculateRectangleArea(struct Rectangle rect);
float calculateTriangleArea(struct Triangle tri);
float calculateTrapezoidArea(struct Trapezoid trap);
float calculateEllipseArea(struct Ellipse esp);
float calculateParallelogramArea(struct Parallelogram para);
float calculateRhombusArea(struct Rhombus rhom);
float calculateregularpolygon(struct regularpolygon polygon);
double calTriangleArea(struct Point a, struct Point b, struct Point c);
double calculateIrregularShapeArea(struct Point vertices[], int numVertices);


int main() {
    int choice;

    do {
        
        printf("\nAREAS CALCULATOR\n");
        printf("1. Rectangle\n");
        printf("2. Triangle\n");
        printf("3. Trapezoid\n");
        printf("4. Ellipse\n");
         printf("5. Parallelogram\n");
         printf("6.Rhombus\n");
         printf("7.regular polygon\n");
         printf("8.irregularshape\n");
         printf("0.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
    struct Rectangle rect;
    printf("Enter length and width of the rectangle: ");
      scanf("%f %f", &rect.length, &rect.width);
    float area = calculateRectangleArea(rect);
     printf("Area of the rectangle: %.2f\n", area);
                break;
            }
            
        case 2: {
     struct Triangle tri;
printf("Enter the base and height of the triangle: ");
        scanf("%f %f", &tri.base, &tri.height);
    float area = calculateTriangleArea(tri);
     printf("Area of the triangle: %.2f\n", area);
                break;
            }
            case 3: {
    struct Trapezoid trap;
    printf("Enter the two bases and height of the trapezoid: ");
   scanf("%f %f %f", &trap.base1, &trap.base2, &trap.height);
     float area = calculateTrapezoidArea( trap);
         printf("Area of the trapezoid: %.2f\n", area);
                break;
            }
            case 4: {
                struct Ellipse esp;
    printf("Enter the major and minor axes of the ellipse: ");
    scanf("%f %f", &esp.majorAxis, &esp.minorAxis);
    float area = calculateEllipseArea(esp);
         printf("Area of the ellipse: %.2f\n", area);
                break;
  }
            case 5: {
                struct Parallelogram para;
printf("Enter the base and height of the parallelogram: ");
    scanf("%f %f", &para.base, &para.height);
 float area = calculateParallelogramArea(para);
     printf("Area of the parallelogram: %.2f\n", area);
                break;
            }
            
      case 6:{
          struct Rhombus rhom;
          printf("Enter the lengths of the diagonals of the rhombus: ");
     scanf("%f %f", &rhom.diagonal1, &rhom.diagonal2);
            float area=calculateRhombusArea(rhom);
            printf("Area of the rhombus: %.2f\n",  area);
            break;
  }
  
        case 7:{
        struct regularpolygon polygon;
        printf("number of sides of polygon:");
         scanf("%d",&polygon.n);
         printf("length of side of poygon:");
         scanf("%f",&polygon.side);
         printf("apothem(distance between center and midpoint of any side of polygon):");
         scanf("%f",&polygon.apothem);
         polygon.perimeter=polygon.n*polygon.side;
         float area=calculateregularpolygon(polygon);
         printf("%f",area);
         break;
        
        }
        case 8:{
          int numVertices;

    printf("Enter the number of vertices in the irregular shape: ");
    scanf("%d", &numVertices);

    if (numVertices < 3) {
        printf("Invalid number of vertices. An irregular shape must have at least 3 vertices.\n");
        return 1;
    }

    struct Point vertices[numVertices];

    for (int i = 0; i < numVertices; ++i) {
        printf("Enter the coordinates of vertex %d (x y): ", i + 1);
        scanf("%lf %lf", &vertices[i].x, &vertices[i].y);
    }

    double area = calculateIrregularShapeArea(vertices, numVertices);

    printf("Area of the irregular shape: %.2f square units\n", area);


        }
            case 0:{
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
        }
    }
    while (choice != 0);

    return 0;
}

// Function definitions
float calculateRectangleArea(struct Rectangle rect) {
    return rect.length * rect.width;
}

float calculateTriangleArea(struct Triangle tri) {
    return 0.5 * tri.base * tri.height;
}

float calculateTrapezoidArea( struct Trapezoid trap) {
    return 0.5 * (trap.base1 + trap.base2) *trap.height;
}

float calculateEllipseArea( struct Ellipse esp) {
    return M_PI *esp.majorAxis * esp.minorAxis;
}

float calculateParallelogramArea( struct Parallelogram para) {
    return para.base *para.height;
}
float calculateRhombusArea(struct Rhombus rhom){
    return 0.5*rhom.diagonal1*rhom.diagonal2;
}

float calculateregularpolygon(struct regularpolygon polygon){
    return 0.5*polygon.perimeter*polygon.apothem;

}
double calTriangleArea(struct Point a, struct Point b, struct Point c) {
    return fabs((a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)) / 2.0);
}

double calculateIrregularShapeArea(struct Point vertices[], int numVertices) {
    double totalArea = 0.0;

    // Assuming vertices are given in a counterclockwise or clockwise order
    for (int i = 1; i < numVertices - 1; ++i) {
        totalArea += calTriangleArea(vertices[0], vertices[i], vertices[i + 1]);
    }

    return totalArea;
}