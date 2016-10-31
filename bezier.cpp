#include <iostream>

using namespace std;

// This code requires ilmbase library as I use the vectors from that
//
Imath::Vec3<float> bezier(float t, Imath::Vec3<float> p0,
                          Imath::Vec3<float> p1, 
                          Imath::Vec3<float> p2, 
                          Imath::Vec3<float> p3)
{
    float u = 1 - t;
    float tt = t*t;
    float uu = u*u;
    float uuu = uu * u;
    float ttt = tt * t;

    Imath::Vec3<float> p = uuu * p0;
    p += 3 *uu * t * p1;
    p += 3 *u * tt * p2;
    p += ttt *p3;

    return p;
}

int main()
{
    for(int i =0; i<11; i++)
    {
        Imath::Vec3<float> Pa(0.0,0.0,0.0);
        Imath::Vec3<float> Pb(1.0,4.0,0.0);
        Imath::Vec3<float> Pc(3.5,6.0,0.0);
        Imath::Vec3<float> Pd(5.5,3.5,0.0);

        Imath::Vec3<float> result;

        float t= i/11.0;
        result = bezier(t, Pa, Pb, Pc, Pd);

        cout<<"T value: "<<t<<endl;
        cout<<"result: "<<result.x<<", "<<result.y<<", "<<result.x<<endl;
    }
}
