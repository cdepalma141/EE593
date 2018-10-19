/*
 * HW4a - GrowArray
 *
 * Connor DePalma.
 *
 * I pledge my honor that I have abided by the Stevens Honor System.
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>

/*
 * This will first display a 16 by 16 grid to show the sizes of all lists with list[0][0] in the top left corner.
 *
 * Next, a grid representation will be shown with the xmax/ymax and xmin/ymin displayed. If the same values are visible
 * for max and min, then the list only contains that point. If a list is empty then it will display nan as its value.
 *
 * Lastly, a grid with '-' representing empty lists will be displayed.  This grid will display all points in every list
 * that is on the perimeter of the grid (values not on the perimeter will always be '-'). Points in the same list will
 * separated by '|'.
 *
 * Additionally, I only used insertEnd for the list creation since it is O(1) and all that is necessary for this.
 * all other methods for the Growarray are still here just commented out.
 *
 */


using namespace std;


class ConvexHull {

private:

    class List {
    private:

        class Point {
        public:
            double x, y;
            Point(double x = 0, double y = 0): x(x), y(y) {}

            friend ostream& operator<<(ostream& s, const Point& b){
                s << b.x << ", "<< b.y;
                return s;
            }


        };

        int used;
        int capacity;
        Point **p;
        double xmax;
        double ymax;
        double xmin;
        double ymin;
        void checkGrow(){
            if(used >= capacity){
                Point** temp = p;
                p = new Point*[capacity = capacity*2 +1];
                for(int i = 0; i < used; i++)
                    p[i] = temp[i];
                delete[] temp;
            }
        }

    public:

        List(int initialSize) : xmax(INT_MIN), xmin(INT_MAX), ymax(INT_MIN), ymin(INT_MAX), capacity(initialSize), p(new Point*[capacity]){}
        List() : List(100) {}

        ~List(){
            delete [] p;
        }

        List(const List& orig) : used(orig.used), capacity(orig.capacity), p(new Point*[capacity]) {
            for(int i = 0; i < used; i++)
                p[i] = orig.p[i];
        }

        List& operator=(const List& orig) {
            List copy(orig);
            swap(copy.p, p);
            used = orig.used;
            capacity = orig.capacity;
            return *this;
        }

        List (List&& orig) : used(orig.used), capacity(orig.capacity), p(orig.p){
            orig.p = nullptr;
        }

        void findmaxmin(double x, double y){

            if(x < xmin)
                xmin = x;

            if (y < ymin)
                ymin = y;

            if(x > xmax)
                xmax = x;


            if(y > ymax)
                ymax = y;



        }


//        void insertStart(double a, double b){
//            checkGrow();
//            for(int i = used + 1; i > 0; i--)
//                p[i] = p[i-1];
//            p[0]= new Point (a,b);
//           p[0].y = b;
//            used++;
//
//        }

        void insertEnd(double a, double b){
            checkGrow();
            p[used++] = new Point(a , b);
            //p[used].x = a;
           // p[used++].y = b;
            findmaxmin(a, b);
        }

//        void removeStart(){
//            for(int i = 0; i < used -1; i++)
//                p[i] = p[i+1];
//            used--;
//
//        }
//
//        void removeEnd(){
//            used--;
//        }

//        void Insert(int pos, int a, int b){
//            Point* temp = p;
//            p = new Point[used + 1];
//
//            for(int i = 0; i < pos; i++)
//                p[i] = temp[i];
//
//            p[pos].x = a;
//            p[pos].y = b;
//
//            used++;
//            for(int i = pos + 1; i < used; i++)
//                p[i] = temp[i-1];
//
//            delete[] temp;
//
//        }

        int sizeList() {
            return used;
        }

        double getxmax(){
            if(xmax == INT_MIN)
                return NAN;

          return xmax;
        }

        double getxmin(){
            if(xmin == INT_MAX)
                return NAN;

            return xmin;
        }
        double getymax(){
            if(ymax == INT_MIN)
                return NAN;

            return ymax;
        }
        double getymin(){
            if(ymin == INT_MAX)
                return NAN;

            return ymin;
        }

        void getList(){

            for(int i = 0; i < used; i++)
                cout << *p[i] << '|';
            if(used == 0)
                cout << "\t-\t";
        }

        friend ostream& operator <<(ostream& s, const List& b) {
            for(int i = 0; i < b.used; i++)
                s << b.p[i] << '\t';
            return s;
        }



    };

    double xmax;
    double xmin;
    double ymax;
    double ymin;
    uint32_t size;
    List *** hull;

public:



    ConvexHull(uint32_t size) : size(size), xmax(INT_MIN), xmin(INT_MAX), ymax(INT_MIN), ymin(INT_MAX), hull(new List**[size]) {
        for (int i = 0; i < size; i++) {
            hull[i] = new List*[size];
            for(int j = 0; j < size; j++)
                hull[i][j] = new List();
        };


    }

    ConvexHull() : ConvexHull(10) {}


    ~ConvexHull(){
        for (int i = 0; i < size; i++) {
            for(int j = 0; j < size; j++)
                delete hull[i][j];

            delete[] hull[i];
        };

        delete[] hull;

    }

    int getCount(const string& s) {
        int count = 0;
        ifstream f(s);
        char a;
        string linebuffer;
        while (getline(f, linebuffer)){
            if(linebuffer.length() != 0)
                count++;
        }
        return count;

    }


    void read(const string& s) {
        double x;
        double y;
        int c = getCount(s);
        double a[c];
        double b[c];

        int count = 0;
        ifstream f(s);
        string linebuffer;
        while(getline(f, linebuffer)) {
            if(linebuffer.length() != 0) {

                istringstream line(linebuffer);
                line >> x >> y;


                if (x < xmin)
                    xmin = x;

                if (y < ymin)
                    ymin = y;

                if (x > xmax) {
                    xmax = x;
                }

                if (y > ymax) {
                    ymax = y;
                }


                a[count] = x;
                b[count] = y;

                count++;

            }
        }
//        cout << xmax << ' ' << ymax;
//        cout << '\n';
//        cout << xmin << ' ' << ymin;
//        cout << '\n';
//        cout << '\n';
//        for(int i = 0; i < count; i++)
//            cout << a[i] << ' ' << b[i] << '\n';
//        cout << '\n';
//        cout << '\n';


        for(int i = 0; i < count; i++) {
            int yval = int(((b[i]-ymin)/(ymax-ymin))*size);
            int xval = int(((a[i]-xmin)/(xmax-xmin))*size);
           // cout << xval << ' '<< yval << '\n';
            if(yval >= size)
                yval = size-1;
            if(xval >= size)
                xval = size-1;

            hull[yval][xval]->insertEnd(a[i],b[i]);
        }




    }

    void printAllListSizes(){
        for(int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++)
                cout << hull[i][j]->sizeList() << ' ';

        cout << '\n';
        }
        cout << '\n';
    }

    void printMinMax() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                cout << " -- ";
                cout << "max: " <<  hull[i][j]->getxmax() << ' ' << hull[i][j]->getymax() << ' ';
                cout << "min: " <<  hull[i][j]->getxmin() << ' ' << hull[i][j]->getymin();

            }
            cout << "\n\n";
        }
    }

    void printPerimeterClockWiseOrder(){
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (i == 0)
                    hull[i][j]->getList();
                else if (i == size-1)
                    hull[i][j]->getList();
                else if (j == 0)
                    hull[i][j]->getList();
                else if (j == size-1)
                    hull[i][j]->getList();
                else
                    cout << "\t-\t";
            }
            cout << "\n";
        }
    }
};

int main() {
    // for homework n=16
    ConvexHull ch(16); // create a 16x16 grid of GrowArray
    ch.read("convexhullpoints.dat"); //I needed full absolute path for mine to work in CLion
    ch.printAllListSizes(); // tell us how many are in each list
    ch.printMinMax(); // print minx, maxx, miny, maxy for the entire dataset
    ch.printPerimeterClockWiseOrder(); // p1,p2,p3,p4, p8,p12,p16...
    // for each growarray around the perimeter print xmin, xmax, ymin,ymax
    // this is the minimum, maximum for the x,y in THAT BOX
    /*
  example shown n=4
       -----------------------
       | p1 | p2  | p3  | p4 |
       |    |     |     |    |
       +----+-----+-----+----+
       | p5 | p6  | p7  | p8 |
       |    |     |     |    |
       +----+-----+-----+----+
       | p9 | p10 | p11 | p12|
       |    |     |     |    |
       +----+-----+-----+----+
       | p13| p14 | p15 | p16|
       |    |     |     |    |
       +----+-----+-----+----+
     */
}
