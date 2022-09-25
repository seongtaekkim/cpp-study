#include <iostream>
#include <vector>
#include <algorithm>

// Reference : http://thbecher.net/articles/auto_and_decltype/section_01.html

using namespace std;


/**
 * 1. auto -> 매우 긴 타입을 짧게 줄일 수 있다.
 * 
 */
class Examples
{
public:
    void ex1()
    {
        std::vector<int> vect;
        for (std::vector<int>::iterator itr = vect.begin(); itr != vect.end() ; itr++)
            cout << *itr;
        for (auto itr = vect.begin() ; itr != vect.end(); itr++)
            cout << *itr;
        for (auto itr : vect) // for (const auto & itr : vect)
            cout << itr;
    }
    /*
        
    */
    void ex2()
    {
        int x = int();
        auto auto_x = x;
        
        const int &crx = x;
        // type : int -> auto는 const, & 등을 제거한다.
        auto auto_crx1 = crx;
        // &를 유지하려면 auto오른쪽에 &를 붙여준다.
        // const는 똑같이 붙여준다.
        const auto& auto_crx2 = crx;
        

        volatile int vx = 1024;
        auto avx = vx;
        // volatile 을 유지하려면, auto 앞에도 붙여줘야한다.
        volatile auto vavx = vx;
    }

/*     template<class T>
    void func_ex3(T arg)
    {
    } */

    /*
        const, &를 모두 붙여야 적용된다.
     */
    template<class T>
    void func_ex3(const T& arg)
    {
    }

    void ex3()
    {
        const int &crx = 123;
        func_ex3(crx);
    }

    /*
        auto &로 초기화 하면, 그 후 할당은 컴파일 오류다.
    */
    void ex4()
    {
        const int c = 0;
        auto & rc = c;
        //rc = 123; // compile error
    }

    void ex5()
    {
        int i =  42;
        auto&& ri_1 = i;    // l-value
        // int&& ri_3 = i; 자료형이 있다면, 컴파일 오류이다.
        auto&& ri_2 = 42;   // r-value
        
    }

    /*
        auto p2 가 const인 이유는 const는 포인터변수가 아닌, 값(x)이 const이기 때문인듯 ?
    */
    void ex6()
    {
        int x = 42;
        const int *p1 = &x;
        auto p2 = p1;
        //*p2 = 43; // const이기 때문에 error

        const int x2 = 42;
        const int *p3 = &x2;
        auto p4 = *p3;
    }

    /*
        곱셈 결과의 타입이 뭔지 알기 어려워서 auto를 사용한 추론방법을 사용할 수 있다.
    */
    template<typename T, typename S>
    void func_ex7(T lhs, S rhs)
    {
        auto prod1 = lhs * rhs;

        //typedef typeof(lhs * rhs) product_type; // pre-c++11 'some' compile
                                                  // 데이터타입을 리턴
        typedef decltype(lhs * rhs) product_type; // begin modern c++ 
                                                  // 이 시점에 실제 계산을 하는게 아니라 추론만 함

        product_type prod2 = lhs * rhs;
        decltype(lhs * rhs) prod3 = lhs * rhs; // 위와 같은 결과.
    }

    template<typename T, typename S>
    // decltype(lhs * rhs) func_ex8(T lhs, S rhs)
    // -> 컴파일러 구조 상 decltype이 앞에 있을 경우, lhs,rhs 타입을 알 수 없어 아래와같이 선언해야 함.
    auto func_ex8(T lhs, S rhs) -> decltype(lhs * rhs)
    {
        return (lhs * rhs);
    }


    // 반환값 자료형 살펴보기
    void ex7_8()
    {
        func_ex7(1.0, 345);
        func_ex8(1.2, 345);
    }   

    struct S
    {
        int m_x;
        S()
        {
            m_x = 42;
        }
    }; 

    void ex09()
    {
        int x;
        const int cx = 42;
        const int& crx = x;
        const S *p = new S();

        auto a = x;
        auto b = cx;
        auto c = crx;
        auto d = p;
        auto e = p->m_x; // 객체가 const이지만, int 인 맴버변수를 복사하면, const가 아님.

        typedef decltype(x)         x_type;
        typedef decltype(cx)        cx_type;
        typedef decltype(crx)       crx_type;
        typedef decltype(p->m_x)    m_x_type; // int m_x 가 선언이 될때에는 int이기 때문에, const가 붙이 않음.

        typedef decltype((x))       x_with_parens_type; // add reference to lvalues
        typedef decltype((cx))      cx_with_parens_type;
        typedef decltype((crx))     crx_with_parens_type;
        typedef decltype((p->m_x))  m_w_with_parens_type; // 레퍼런스 이기 때문에 변경되면 안되므로, const가 붙음.
    }

    const S foo()
    {
        return S();
    }

    /*
        return by reference 일 경우, local value를 리턴하면,
        해당 정보가 사라지기 때문에 사용하면 안됨.

        auto& a = e.foobar();
        cout << a << endl;
        cout << a << endl;  // 쓰레기값 출력
    */
    const int& foobar()
    {
        return 123;
    }
    
    void ex10()
    {
        std::vector<int> vect = {42, 43};

        auto a = foo();
        typedef decltype(foo()) foo_type;

        auto b = foobar();
        typedef decltype(foobar()) foobar_type;

        auto itr = vect.begin();
        typedef decltype(vect.begin()) iterator_type;

        auto first_element = vect[0];
        // vector의 [] operator overloading 함수 리턴 타입이 레퍼런스라서, decltype()정의 시 레퍼런스가 붙는다.
        decltype(vect[1]) second_element = vect[1];
    }

    void ex11()
    {
        int x = 0;
        int y = 0;
        const int cx = 42;
        const int cy = 43;
        double d1 = 3.14;
        double d2 = 2.72;

        typedef decltype(x * y) prod_xy_type;
        auto a = x * y;

        typedef decltype(cx * cy) prod_cxcy_type; // result is prvalue
        auto b = cx * cy;

        typedef decltype(d1 < d2 ? d1 : d2) cond_type; // result is lvalue. & is added
        auto c = d1 < d2 ? d1 : d2;

        typedef decltype(x < d2 ? x : d2) cond_type_mixed; // promition of x to double
        auto d = x < d2 ? x : d2;

        // 인수 타입이 같을 경우만 작동함.
        //auto e = std::min(x, d2); // error

    }

    /*
        두개 인자 타입이 같으면 decltype에 레퍼런스가 붙게 된다.
    */
    template<typename T, typename S>
    auto fpmin_wrong(T x, S y) -> decltype(x < y ? x : y)
    {
        return (x < y ? x : y);
    }

    /*
        remove_reference : 레퍼런스를 제거한 타입을 사용.
    */
    template<typename T, typename S>
    auto fmin(T x, T y) ->
        typename std::remove_reference<decltype(x < y ? x : y)>::type
    {
        return x < y ? x : y;
    }

    void ex12()
    {
        int i = 42;
        double d = 45.1;
        //auto a = std::min(i, d); // error : 'std::min' : no matching overload function found
        auto a = std::min(static_cast<double>(i), d);
        int &j = i;

        typedef decltype(fpmin_wrong(d, d)) fpmin_return_type1; // double &
        typedef decltype(fpmin_wrong(i, d)) fpmin_return_type2; // double
        typedef decltype(fpmin_wrong(j, d)) fpmin_return_type3; // double
    } 

    void ex13()
    {
        std::vector<int> vect; // vect is empty
        // vect[0]은 컴파일 에러가 나지만, decltype은 타입추론만 하기 때문에 정사처리됨.
        typedef decltype(vect[0]) integer; 
    }

    template<typename R>
    class SomeFunctor
    {
    public:
        typedef R result_type;
        SomeFunctor()
        {}

        result_type operator() ()
        {
            return R();
        }
    };

    void ex14()
    {
        SomeFunctor<int> func;
        typedef decltype(func)::result_type integer; // nested type
    }

    void ex15()
    {
        auto lambda = []() {return 42;};
        decltype(lambda) lambda2(lambda);
        decltype((lambda)) lambda3(lambda); // (()) : add l-reference

        cout << "Lambda functions " << endl;
        cout << &lambda << " " << &lambda2 << endl;
        cout << &lambda << " " << &lambda3 << endl;
    }
    
    void ex16()
    {
        // generic lambda
        auto lambda = [](auto x, auto y)
        {
            return (x + y);
        };

        cout << lambda(1.1, 2) << " " << lambda(3, 4) << " " << lambda(4.2, 2.2) << endl;
    }
};


int main(void)
{
    Examples e;
    e.ex15();

    auto& a = e.foobar();
    cout << a << endl;
    cout << a << endl;
    return (0);
}