// Dinlon5566(408261292)
#include <iostream>
#include <vector>

using namespace std;

// Function to perform bilinear interpolation : https://en.wikipedia.org/wiki/Bilinear_interpolation
// x1, x2, y1, y2 = the surrounding points
// fQab = f(a, b)
double bilinearInterpolation(double x1, double x2, double y1, double y2, double fQ11, double fQ12, double fQ21, double fQ22, double x, double y)
{
    double fR1 = ((x2 - x) / (x2 - x1)) * fQ11 + ((x - x1) / (x2 - x1)) * fQ21;
    double fR2 = ((x2 - x) / (x2 - x1)) * fQ12 + ((x - x1) / (x2 - x1)) * fQ22;

    return ((y2 - y) / (y2 - y1)) * fR1 + ((y - y1) / (y2 - y1)) * fR2;
}

int main()
{
    // Given x, y and z values [8]*[9] => arr[8][9]
    vector<double> x{0.25, 0.37, 0.49, 0.61, 0.73, 0.85, 0.97, 1.09};
    vector<double> y{0.1, 0.3, 0.5, 0.7, 0.9, 1.1, 1.3, 1.5, 1.7};
    vector<vector<double>> z{
        {6.9975, 7.7967, 8.6823, 9.6543, 10.7127, 11.8575, 13.0887, 14.4063},
        {6.1775, 6.9287, 7.7663, 8.6903, 9.7007, 10.7975, 11.9807, 13.2503},
        {5.4375, 6.1407, 6.9303, 7.8063, 8.7687, 9.8175, 10.9527, 12.1743},
        {4.7775, 5.4327, 6.1743, 7.0023, 7.9167, 8.9175, 10.0047, 11.1783},
        {4.1975, 4.8047, 5.4983, 6.2783, 7.1447, 8.0975, 9.1367, 10.2623},
        {3.6975, 4.2567, 4.9023, 5.6343, 6.4527, 7.3575, 8.3487, 9.4263},
        {3.2775, 3.7887, 5.8407, 4.3863, 5.0703, 6.6975, 7.6407, 8.6703},
        {2.9375, 3.4007, 3.9503, 4.5863, 5.3087, 6.1175, 7.0127, 7.9943},
        {2.6775, 3.0927, 3.5943, 4.1823, 4.8567, 5.6175, 6.4647, 7.3983}};

    // The points we want to estimate
    vector<vector<double>> points{{0.6, 0.7}, {0.24, 0.9}, {0.42, 0.48}};

    for (auto &point : points)
    {
        try
        {
            // if the point is out of range
            if (point[0] < x[0] || point[0] > x[x.size() - 1] || point[1] < y[0] || point[1] > y[y.size() - 1])
                throw "The point is out of range.";

            // Find the surrounding points
            int x1Idx = 0, x2Idx = 0, y1Idx = 0, y2Idx = 0;
            for (int i = 0; i < x.size(); i++)
            {
                if (x[i] <= point[0])
                    x1Idx = i;
                if (x[i] > point[0])
                {
                    x2Idx = i;
                    break;
                }
            }
            for (int i = 0; i < y.size(); i++)
            {
                if (y[i] <= point[1])
                    y1Idx = i;
                if (y[i] > point[1])
                {
                    y2Idx = i;
                    break;
                }
            }

            double result = bilinearInterpolation(x[x1Idx], x[x2Idx], y[y1Idx], y[y2Idx],
                                                  z[y1Idx][x1Idx], z[y2Idx][x1Idx], z[y1Idx][x2Idx], z[y2Idx][x2Idx],
                                                  point[0], point[1]);

            cout << "f(" << point[0] << "," << point[1] << ") = " << result << endl;
        }
        catch (const char *e)
        {
            // if the point is out of range(maybe)
            cout << e << endl;
            continue;
        }
    }

    return 0;
}
