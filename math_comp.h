#include"mge.h"
using namespace std;
template<typename T1>
// we need interpolation algorithms, orthographic projection, perspective projection, Quaternions, ray,line segment,AABB,meshes,animations......,rendering algorithms.....,
//all will be attached to uniform variables in opengl....
struct Vec2{
    T1 x,y;
    Vec2():x{0},y{0}{}
    Vec2(T1 _x,T1 _y):x{_x},y{_y}{}
    Vec2& operator+=(Vec2 r1){
        this->x+=r1.x;
        this->y+=r1.y;
        return *this;
    }
    Vec2& operator-=(Vec2 r1){
        this->x-=r1.x;
        this->y-=r1.y;
        return *this;
    }
    T1& operator[ ](unsigned int idx){
        assert(idx==0 || idx==1);
        if(idx==0) return this->x;
        if(idx==1) return this->y;
    }
    Vec2* get_vector(){
        return this;
    }
    Vec2 operator+(const Vec2 r1){
        Vec2 r2;
        r2.x=this->x+r1.x;
        r2.y=this->y+r1.y;
        return r2;
    }
    Vec2 operator*(T1 scalar){
        Vec2 r2;
        r2.x=this->x*scalar;
        r2.y=this->y*scalar;
        return r2;
    }
    Vec2 operator-(const Vec2 r2){
        Vec2 r1;
        r1.x=this->x-r2.x;
        r1.y=this->y-r2.y;
        return r1;
    }
    
};
template<class T>
std::ostream& operator<<(std::ostream& os,Vec2<T>& R1){
    os<<"x:"<<R1.x<<std::endl;
    os<<"y:"<<R1.y<<std::endl;
    return os;}

typedef Vec2<float> Point2f;
typedef Vec2<int> Point2i;
typedef Vec2<unsigned int> Point2ui;
typedef Vec2<float> Vec2f;
typedef Vec2<int> Vec2i;



template<typename V>
struct Vec3{
    V x,y,z;
    Vec3():x{0},y{0},z{0}{}
    Vec3(V _x,V _y,V _z):x{_x},y{_y},z{_z}{}
     Vec3 operator+(Vec3 F){
         V g=x+F.x;
         V h=y+ F.y;
         V i=z+F.z;
         Vec3 r1=Vec3<V>(g,h,i);
         return r1;
     }
     Vec3 operator*(V scalar){
         V g=x*scalar;
         V h=y*scalar;
         V j=z*scalar;
         Vec3 r1=Vec3<V>(g,h,j);
         return r1;
     }
     Vec3* get_vec3(){
         return this;
     }
     Vec3 operator-(Vec3& r2){
         Vec3 r1=(x-r2.x,y-r2.y,z-r2.z);
         return r1;
     }
     V&  operator[ ](unsigned int idx){
         assert(idx==0||idx==1||idx==2);
         if(idx==0) return x;
         if(idx==1) return y;
         if(idx==2) return z;
     }
};
 template<class T>
 struct Vec_op{
  inline   static T mag2(const Vec2<T>& v1){
         return (v1.x*v1.x +v1.y*v1.y)^0.5;
     }
    inline  static T mag3(const Vec3<T>& v1){
         return (v1.x*v1.x+v1.y*v1.y+v1.z*v1.z)^0.5;
     }
   inline static T dot2(const Vec2<T>& v1,const Vec2<T>& v2){
         return v1.x*v2.x+v1.y*v2.y;
     }
  inline static T dot3(const Vec3<T>& v1,const Vec3<T>& v2){
      return v1.x*v2.x+v1.y*v2.y+v1.z*v2.z;
  }
  inline static Vec3<T> cross(const Vec3<T>& v1,const Vec3<T>& v2){
      return Vec3<T>(1*(v1.y*v2.z-v1.z*v2.y),  1*(v1.x*v2.z-v1.z*v2.x),1*(v1.x*v2.y-v2.x*v1.y));
  }
  inline static Vec2<T>norm2D(const Vec2<T>& r2){
      T mag=Vec_op<T>::mag2(r2);
      Vec2<T> ret=Vec2<T>(r2.x/mag,r2.y/mag);
      return ret;
  }
  inline static Vec3<T> norm3D(const Vec3<T>& r2){
      T mag=Vec_op<T>::mag3(r2);
      Vec3<T> ret=Vec3<T>(r2.x/mag,r2.y/mag,r2.z/mag);
      return ret;
  }
      
};
//matrix multiplication is done by multiplying row by column
template<class T>
struct Point4{
    T x,y,z,w;
    Point4()=default;
    Point4(T _x,T _y,T _z,T _w):x{_x},y{_y},z{_z},w{_w}{}
    Point4& operator-=(const Point4& r1){
        x-=r1.x;
        y-=r1.y;
        z-=r1.z;
        w-=r1.w;
        return *this;
    }
   Point4& operator+=(const Vec3<T>& v){
       x+=v.x;
       y+=v.y;
       z+=v.z;
       w+=0;
       return *this;
   }
   T& operator[ ](int idx){
       assert(idx==0||idx==1||idx==2||idx==3);      if(idx==0)return x;
       if(idx==1) return y;
       if(idx==2) return z;
       if(idx==3) return w;
   }
   Point4& operator=(const Point4& b1){
       x=b1.x;
       y=b1.y;
       z=b1.z;
       w=b1.w;
       return *this;
   }
   Point4 operator*(T& s){
       Point4<T> v=Point4<T>(*this);
       v.x*=s;
       v.y*=s;
       v.z*=s;
       v.w*=s;
       return v;
   }
   Point4 operator-(Point4& v1){
       Point4 h;
       h.x=x-v1.x;
       h.y=y-v1.y;
       h.z=z-v1.z;
       h.w=w-v1.w;
       return h;
   }
   Point4 operator+(Point4& v1){
       Point4 h;
       h.x=x+v1.x;
       h.y=y+v1.y;
       h.z=z+v1.z;
       h.w=w+v1.w;
       return h;
   }
       
   
       
   
};
typedef Vec3<float> Vec3f;
typedef Vec3<int> Vec3i;
typedef Vec3<float> Point3f;
typedef Vec3<int> Point3i;
typedef Point4<float> Vec4f;
typedef Point4<float> Point4f;
typedef Point4<int> Point4i;

template<typename T>
struct Matrix{
    public:
    T mat[4][4];
    Matrix()=default;
    Matrix(Vec3<T> v1,Vec3<T> v2,Vec3<T> v3,Vec3<T> v4){
        mat[0][0]=v1.x;
        mat[0][1]=v1.y;
        mat[0][2]=v1.z;
        mat[0][3]=0;
        mat[1][0]=v2.x;
        mat[1][1]=v2.y;
        mat[1][2]=v2.z;
        mat[1][3]=0;
        mat[2][0]=v3.x;
        mat[2][1]=v3.y;
        mat[2][2]=v3.z;
        mat[2][3]=0;
        mat[3][0]=v4.x;
        mat[3][1]=v4.y;
        mat[3][2]=v4.z;
        mat[3][3]=1;
    }
   
    
   Matrix& operator=(const Matrix& m) 
   {
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                mat[i][j]=m.mat[i][j];
            }
        }
        return *this;
   }
    
     
};

typedef Matrix<float> Mat4x4f;    
template <class R>
struct Mat_op
{
    static Point4<R> mul(Point4<R>& l2,Matrix<R>& r2,bool is_transpose ){
        Point4<R> m2;
        if(is_transpose){
           Matrix<R> m1;
           for(int i=0;i<4;i++){
               for(int j=0;j<4;j++){
                   m1.mat[i][j]=r2.mat[j][i];
               }
           }
           R v1=m1.mat[0][0]*l2.x+m1.mat[0][1]*l2.y+m1.mat[0][2]*l2.z+m1.mat[0][3]*l2.w;
           R v2=m1.mat[1][0]*l2.x+m1.mat[1][1]*l2.y+m1.mat[1][2]*l2.z+m1.mat[1][3]*l2.w;
           R v3=m1.mat[2][0]*l2.x+m1.mat[2][1]*l2.y+m1.mat[2][2]*l2.z+m1.mat[2][3]*l2.w;
           R v4=m1.mat[3][0]*l2.x+m1.mat[3][1]*l2.y+m1.mat[3][2]*l2.z+m1.mat[3][3]*l2.w;
         m2=Point4<R>(v1,v2,v3,v4);
           
       }
       else{
           R v1=l2.x*r2.mat[0][0]+l2.y*r2.mat[1][0]+l2.z*r2.mat[2][0]+1*r2.mat[3][0]; 
           R v2=l2.x*r2.mat[0][1]+l2.y*r2.mat[1][1]+l2.z*r2.mat[2][1]+1*r2.mat[3][1];
           R v3=l2.x*r2.mat[0][2]+l2.y*r2.mat[1][2]+l2.z*r2.mat[2][2]+1*r2.mat[3][2];
           R v4=l2.x*r2.mat[0][3]+l2.y*r2.mat[1][3]+l2.z*r2.mat[2][3]+1*r2.mat[3][3];
          m2=Point4<R>(v1,v2,v3,v4);
           
       
       }
       return m2;
       
    }
    static Matrix<R> mat_mul();
    // assuming the scaling is uniform along the axes of the mesh,along the object coordinate spaces  |_
                                       //    /
                                       
   
};
template<typename T>
struct Transform{
            static Point4<T> translation( Point4<T>& point ,  Vec3<T>& translate){
        
        Vec3<T> v1={1.0f,0.0f,0.0f};
        Vec3<T> v2={0.0f,1.0f,0.0f};
        Vec3<T> v3={0.0f,0.0f,1.0f};
      Matrix<T> m2=Matrix<T>(v1,v2,v3,translate);
        return Mat_op<T>::mul(point,m2,false);
            }
    static Point4<T>rotate_x(Point4<T>& r1, T& alpha){
        Vec3<T> v1={1.0f,1.0f,1.0f};
        Vec3<T> v2={0.0f,cos(alpha),sin(alpha)};
        Vec3<T> v3={0.0f,-sin(alpha),cos(alpha)};
        Vec3<T> v4={0.0f,0.0f,0.0f};
        Matrix<T> m2=Matrix<T>(v1,v2,v3,v4);
        return Mat_op<T>::mul(r1,m2,false);
    }
    static T deg_to_rad( const T& val){
        const float pi=3.141592654f;
        T val_1=(pi/180)*val;
        return val_1;
    }
    static T rad_to_deg(const T& rad){
        const float pi=3.141592654f;
        T rad_1= (180/pi)*rad;
        return rad_1;
    }
       
   static Point4<T> rotate_y(Point4<T>&r1,T& gamma){
             Vec3<T> v1={cos(gamma),0,-sin(gamma)};
             Vec3<T> v2={ 0,1,0};
             Vec3<T> v3={sin(gamma),0,cos(gamma)};
             Vec3<T> v4={0.0f,0.0f,0.0f};
             Matrix<T> m2=Matrix<T>(v1,v2,v3,v4);
          return Mat_op<T>::mul(r1,m2,true);
   }
 static Point4<T> rotate_z(Point4<T>& r1,const T& theta){
             Vec3<T> v1={cos(theta),sin(theta),0.0f};
             Vec3<T> v2={-sin(theta),cos(theta),0.0f};
             Vec3<T> v3={0.0f,0.0f,1.0f};
             Vec3<T> v4={0.0f,0.0f,0.0f};
             Matrix<T> m2=Matrix<T>(v1,v2,v3,v4);
             return Mat_op<T>::mul(r1,m2,false);            
      }
  static Point4<T> uscaling(Point4<T>& r1,const T &s){
        Vec3<T> v1={s,0.0f,0.0f};
        Vec3<T> v2={0.0f,s,0.0f};
        Vec3<T> v3={0.0f,0.0f,s};
        Vec3<T> v4={ 0.0f,0.0f,0.0f};
        Matrix<T> m2=Matrix<T>(v1,v2,v3,v4);        return Mat_op<T>::mul(r1,m2,false);
  }
};

                     
        
            

typedef Point4<float> quat4f;
template<class Q>
struct Quat4{
    // axis is always a unit vector so that ||axis||² =1
    Point4<Q> quat;
    Quat4(Vec3<Q>& axis,Q angle){
        quat.x=axis.x*sin(angle/2);
        quat.y=axis.y*sin(angle/2);
        quat.z=axis.z*sin(angle/2);
        quat.w=cos(angle/2);
    }
    Q& operator[ ](const int idx) {
 assert(idx==0||idx==1||idx==2||idx==3);
      if(idx==0) return quat.x;
      if(idx==1) return quat.y;
      if(idx==2) return quat.z;
      if(idx==3) return quat.w;
    }
    Quat4(Q a,Q b,Q c,Q d){
        quat.x=a;
        quat.y=b;
        quat.z=c;
        quat.w=d;
    }
        
    
    
    };
 template<class T>
 struct Quat4_op{
     static Quat4<T> quat4(const Vec3<T>& V1,const T& val){
         return Quat4<T>(V1.x,V1.y,V1.z,val);
     }
      static Quat4<T> quat_mul(const Quat4<T>& q1,const Quat4<T>& q2){
          Vec3<T> m1={q1.quat.x,q1.quat.y,q1.quat.z};
          Vec3<T> m2={q2.quat.x,q2.quat.y,q2.quat.z};
          auto w2=Vec_op<T>::cross(m1,m2);
          auto m3=m1*q1.quat.w;
          auto m4=m2*q1.quat.w;
          auto m5=q1.quat.w*q2.quat.w-Vec_op<T>::dot3(m1,m2);
          auto v1=w2+m3+m4;
          return Quat4<T>(v1,m5);
         }
     static Quat4<T> quat_add(const Quat4<T>& t1,const Quat4<T>& t2){
          Vec3<T>n1={t1.quat.x,t1.quat.y,t1.quat.z};
          Vec3<T>n2={t2.quat.x,t2.quat.y,t2.quat.z};
          auto w=n1+n2;
          auto w1=t1.w+t2.w;
          return Quat4<T>(w,w1);
          }
      static Quat4<T> conjugate(const Quat4<T>& m){
          return Quat4<T>(-m[0],-m[1],-m[2],m[3]);
      }
    static T quat_norm(const Quat4<T>& m1){
      return sqrt(m1[0]*m1[0]+m1[1]*m1[1]+m1[2]*m1[2]+m1[3]*m1[3]);
    }
         
     
 };
 template<class T>
 std::ostream& operator<<(std::ostream& os,Quat4<T>& m1){
     for(int i=0;i<4;i++){
     os<<"quat["<<i<<"]:"<<m1[i]<<std::endl;
     }
     return os;
 }
 struct Ray{
     Point4<float> origin;
      Point4<float> dest;
 };
 struct Lineseg{
     Point4<float> origin;
     Point4<float> dest;
 };
 struct Ray_op{
     static Point4<float> Ray(Ray& r1,float t){
     assert(t>=0);
     Point4<float>dist=r1.dest-r1.origin;
     Point4<float> rem=dist*t;
     Point4<float> get=r1.origin+rem;
     return get;
     }
     static Point4<float>Lineseg(Lineseg& l1,float t){
         assert(t>=0 and t<=1);
         Point4<float>dist=l1.dest-l1.origin;
         Point4<float>rem=dist*t;
         Point4<float> get=l1.origin+rem;
         return get;
     }
     
  };  
   template<class C>
 struct Cast{
         static Vec3<C> Vec2to3(  Vec2<C>& r1,const C& v){
            return Vec3<C>(r1.x,r1.y,v);
         }
         static Point4<C> Vec3to4( Vec3<C>& r1, const C& v)
         {  return Point4<C>(r1.x,r1.y,r1.z,v);
         }
     static Vec3<C>Vec4to3( Point4<C>& c){
         return Vec3<C>(c.x,c.y,c.z);
     }
     static Matrix<C> arrtoMat(C mat[][4]){
         Matrix<C> vert;
         for(int i=0;i<4;i++){
             for(int j=0;j<4;j++){
                 vert.mat[i][j]=mat[i][j];
             }
         }
         return vert;
     }
         
 };
 struct Color{
  float r,g,b,a;

  Color():r{0},g{0},b{0},a{0}{}
  Color(float x,float y,float z,float w):r{x},g{y},b{z},a{w}{}
 };
struct Color_ops{
static   Color add(const Color& c1,const Color& c2){
      float x= c1.r+c2.r;
      float y=c1.g+ c2.g;
      float z=c1.b+ c2.b;
      float w=c1.a+ c2.a;
      Color c3=Color(x,y,z,w);
      return c3;
}
 static Color Subtract(const Color& c1,const Color& c2){
  float x=c1.r-c2.r;
  float y=c1.g-c2.g;
  float z=c1.b-c2.b;
  float w=c1.a-c2.a;
  Color c3=Color(x,y,z,w);
  return c3;
 }
 static Color Multiply(const Color& c1,const Color& c2){
  float x=c1.r*c2.r;
  float y=c1.g*c2.g;
  float z=c1.b*c2.b;
  float w=c1.a*c2.a;
  Color c3=Color(x,y,z,w);
  return c3;
 }
 static Color Divide(const  Color& c1, const Color& c2){
  float x=c1.r/c2.r;
  float y=c1.g/c2.g;
  float z=c1.b/c2.b;
  float w=c1.a/c2.a;
  Color c3=Color(x,y,z,w);
  return c3;
 }
static Color Multiplybyscalar(const float& sc,const Color& c1){
  float x=c1.r*sc;
  float y=c1.g*sc;
  float z=c1.b*sc;
  float w=c1.a*sc;
  Color c3=Color(x,y,z,w);
  return c3;
  }
  template<typename T>
  static T max(const T& ref,const T& val){
      if(val>ref){
          return ref;
      }
      else{
          return val;
      }
  }
  template<typename T>
  static T min(T& ref,T& val){
      if(val<ref){
          return ref;
      }
      else{
          return val;
      }
  }
 static Color interpolate(const Color& c1,const Color& c2,float value){
     assert(value>=0 or value<=1);
     float s=1-value;
     Color c3=Color_ops::Multiplybyscalar(s,c2);
     Color c4=Color_ops::add(c1,c3);
 return c4;
 }
     
 
  
  }; 
  ostream& operator<<(ostream& os,Color& c1){
      os<<"r:"<<c1.r<<","<<"g:"<<c1.g<<","<<"b:"<<c1.b<<","<<"a:"<<c1.a;
  return os;
  }
  //let values range between 0.0f  to 1.0f
enum lighttype{
	POINT=0,
	SPOT=12,
	AREA,
	DIRECTIONAL
};
enum lightning{
    AMBIENT,
    DIFFUSE,
    SPECULAR
};
enum Attenuate{
    CONST,
    LINEAR,
    QUAD
};

    
class Light{
      private:
      Vec3<float> pos;
      Color color;
      public:
      Light(const Vec3<float>& a,Color& c1):pos{a.x,a.y,a.z},color{c1.r,c1.g,c1.b,c1.a}{}
      Light()=default;
     
};
class Spotlight:public Light{
    
    private:
     Vec3<float>conedir;
     float spot_atten;
     float spotcos;
     float spot_expo;
     public:
     Spotlight(Vec3<float>& li,Color& c2, Vec3<float>& cone, float& a, float& b,float& c):Light{li,c2},conedir{cone.x,cone.y,cone.z},spot_atten{a},spotcos{b},spot_expo{c}{}
     
 }; //for directionallight, the half_vector is constant across shader stages....
class  Directionallight:public Light{
    
    private:
    Vec3<float> half_vector;
    float shininess;
    float strength;
    public:
    Directionallight( Vec3<float>& dir, Color& g, Vec3<float>& h1, float& sh, float& strg):Light(dir,g),half_vector(h1),shininess{sh},strength{strg}{}
};
//half_vector for this case(pointlight) varies with shader stages or shader invocation
class Pointlight:public Light{
    private:
    float shi;
    float str1;
    public:
    Pointlight(const Vec3<float>& v1, Color& v2,float& g1, float& g2):Light(v1,v2),shi{g1},str1{g2}{}
};
struct Material{
    Color ambient;
    Color specular;
    Color emission;
    float shininess;
    float albedo;
    Color diffuse;
};
    

         