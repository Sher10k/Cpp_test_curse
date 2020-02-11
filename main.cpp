#include <iostream>
#include <fstream>
//#include <string>

#include <cmath>
//#include <math.h>
#include <cstdlib>
//#include <stdlib.h>

#include <cstddef> // size_t
#include <cstring> // strlen, strcpy

using namespace std;

int power(int x, unsigned p) {
    int answer = 1;
    for (unsigned i = 0; i < p; i++) {
        answer *= x; 
    }
    return answer;
}

int power2(int x, unsigned p) {                                                                               
    return p ? x * power(x, --p) : 1;
}

int power3(int x, unsigned p) {
    return p == 0 ? 1 : p & 1 ? x * power3(x, p - 1) : power3(x * x, p / 2);
}

//#define MAX(x, y, r) (r = int((x > y) ? (x) : (y)))
#define MAX(x, y, r) {int a_ = (x); int b_ = (y); int c_ = ((a_ > b_) ? (a_) : (b_)); r = c_;}

int foo(){
    std::cout << "Hello" << std::endl;
    return 2;
}

int bar(){
    int * m[1];
    m[2] = (int *) &foo;
    return 1;
}

int factorial(int n) {
    if (n == 0)
        return 1;
    return factorial(n - 1) * n;
}

int fibonacci(int n) {
    if (n < 2)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

unsigned gcd(unsigned a, unsigned b)
{
    if( (a == 0) || (b == 0) )
        return a + b;
    return (a > b) ? gcd( a %= b, b ) : gcd( a, b %= a );
}
unsigned gcd2(unsigned a, unsigned b) {return b ? gcd2(b, a%b): a;}

void revers_str(){
    unsigned a = 0;
    std::cin >> a;
    if(a){ 
        revers_str();
        std::cout << a << " ";
    }
}

void rotate(int *a, unsigned size, int shift){   // int a[]
    for ( int i = 0; i < int(shift % size); ++i ){
        int temp = *(a + 0);                    // a[0]
        for ( int *p = a; p < a + size; ++p )
            *p = *(p + 1);                      // p[1]
        *(a + size-1) = temp;                   // a[size-1]
    }
}
void rotate2(int a[], unsigned size, int shift) {
    if(!shift) return;
    int n = *a, *p = a;
    while(p - a < size - 1) *p++ = *p;
    *p = n;
    rotate2(a, size, --shift);
}

unsigned strlen5(const char *str) {
    unsigned len = 0;
//    for( ; *str != '\0'; str++ )
//        len++;
    while (*str++) ++len;   // while (*(str++) != '\0')
    return len;
}
unsigned strlen2(const char *str) {return *str ? 1 + strlen2(++str) : 0;}

void strcat5(char *to, const char *from) {
    while(*to) to++;
    while(*from){
        *to = *from;
        to++;
        from++;
    }
    *to = *from;
}
void strcat2(char *to, const char *from)
{
    while (*to) to++;   // for(;*to;to++);
    while (*to++ = *from++);
}

int strstr5(const char *text, const char *pattern) 
{
    int pos = 0;
    if( !(*pattern) ) return pos;
    
    const char * tt = text;
    const char * pt = pattern;
    while(*pt++) 
    {
        if(!(*tt++)) return -1;
    }
    
    while(*text) 
    {
        if(*text == *pattern) 
        {
            const char * text_temp = text;
            const char * pattern_temp = pattern;
            while( *(++text_temp) ) 
            {
                pattern_temp++;
                if( !(*pattern_temp) ) break;  // if( *pattern_temp == '\0' )
                if(*pattern_temp != *text_temp) break;
            }
            if( !(*pattern_temp) ) return pos;
            if( !(*text_temp) && !(*(pattern_temp+1)) ) return pos;
            pos++;
            text++;
        }
        else 
        {
            pos++;
            text++;
        }
    }
    return -1;
}
int strstr2(const char *text, const char *pattern)
{
    for(int i = 0; *text != '\0' || *pattern == '\0'; i++, text++)
        for(int j = 0; *(text + j) == *(pattern + j) || *pattern == '\0'; j++)
            if(*(pattern + j + 1) == '\0' || *pattern == '\0')
                return i;
    return -1; 
}
int strstr3(const char *text, const char *pattern){
    for(auto i = 0; *text || !*pattern; i++, text++)
        for(auto j = 0; *(text + j) == *(pattern + j) || !*pattern; j++)
            if(!*(pattern + j + 1)|| !*pattern)
                return i;
    return -1;
}
struct test{
    int ret_value;
    const char *text;
    const char *pattern;
};
test tests[] = {
        {0, "", ""}, //0
        {0, "a", ""}, //1
        {0, "a", "a"}, //2
        {-1, "a", "b"}, //3
        {0, "aa", ""}, //4
        {0, "aa", "a"}, //5
        {0, "ab", "a"}, //6
        {1, "ba", "a"}, //7
        {-1, "bb", "a"}, //8
        {0, "aaa", ""}, //9
        {0, "aaa", "a"}, //10
        {1, "abc", "b"}, //11
        {2, "abc", "c"}, //12
        {-1, "abc", "d"}, //13
        {-1, "a", "aa"}, //14
        {-1, "a", "ba"}, //15
        {-1, "a", "ab"}, //16
        {-1, "a", "bb"}, //17
        {-1, "a", "aaa"}, //18
        {-1, "aa", "aaa"}, //19
        {0, "aaa", "aaa"}, //20
        {0, "aaab", "aaa"}, //21
        {1, "baaa", "aaa"}, //22
        {1, "baaaa", "aaa"}, //23
        {1, "baaab", "aaa"}, //24
        {-1, "abd", "abc"}, //25
        {2, "ababc", "abc"}, //26
        {3, "abdabc", "abc"}, //27
        {-1, "", "a"}, //28
        {2, "asasaf", "asaf"}, //29
        {2, "ababac", "abac"}, //30
        {-1, "cbaa", "aab"} //31
};

char *resize(const char *str, unsigned size, unsigned new_size)
{
	if(!str) return 0;
    
    char * new_str = new char[new_size];
    const char * old_ptr = str;
    unsigned temp_num = 0;
    for( char * ptr = new_str; ptr < (new_str + ((size < new_size) ? size : new_size) ); ptr++, old_ptr++ )
    {
        if (temp_num < size) *ptr = *old_ptr;
        else break;
        temp_num++;
    }
    delete [] str;
    return new_str;
}
char *resize2(const char *str, unsigned size, unsigned new_size)
{
	char *new_str = new char[new_size];
    int min = size < new_size ? size : new_size;
	for (int i = 0; i < min; new_str[i] = str[i], ++i);
	delete[] str;
	return new_str;
}

char *getline()
{
    unsigned size = 1;
    char * line = new char[size];
    char ch = '\0';
    unsigned num_ch = 0;
    while ( std::cin.get(ch) && ch != '\n' )
    {
        if( num_ch == size ) line = resize( line, num_ch, size *= 2 );
        line[num_ch++] = ch;
    }
    line[num_ch] = '\0';
    return line;
}

int ** create_array2d( std::size_t rows, std::size_t cols )
{
    int ** m = new int *[rows];
    m[0] = new int[rows * cols];
    for ( std::size_t i = 1; i != rows; ++i )
        m[i] = m[i - 1] + cols;
    return m;
}
void free_array2d( int ** m )
{
    delete [] m[0];
    delete [] m;
}
void print_array2d( int ** m, unsigned rows, unsigned cols )
{
    for ( size_t j = 0; j < rows; j++ ) {
        for ( size_t i = 0; i < cols; i++ )
            cout << m[j][i] << '\t';
        cout << endl;
    }
}

int ** transpose(const int * const * m, unsigned rows, unsigned cols)
{
    int ** mt = create_array2d( cols, rows );
    for ( std::size_t i = 0; i < rows; i++ )
        for ( std::size_t j = 0; j < cols; j++ )
            mt[j][i] = m[i][j];
    
    return mt;
}

void swap_min(int *m[], unsigned rows, unsigned cols)
{
    unsigned row = 0, col = 0;
    for ( size_t j = 0; j < rows; j++ ) 
        for ( size_t i = 0; i < cols; i++ ) 
            if (m[j][i] < m[row][col])
            {
                col = i;
                row = j;
            }
    if (row)
    {
        int * temp_m = m[row];    // *(m + row)
        m[row] = m[0];
        m[0] = temp_m;
    }
}

struct ivector3d 
{
    int *array;
};
void scale(ivector3d v, int k) 
{
    for (int i = 0; i != 3; ++i)
        v.array[i] *= k;
}

struct String 
{
    String(const char *str = "")
    {
//        for ( ; *str == ' '; str++ );
//        size_t size_line = strlen( str );
//        char * line = new char[size_line];
//        strcpy( line, str );
//        //line = str;
        
//        unsigned num_prob = 0;
//        while ( *str != '\0' )
//        {
//            if ( *str == ' ' ) num_prob++;
//            else num_prob = 0;
//            str++;
//        }
//        size_line = strlen( line );
//        char * line2 = new char[size_line - num_prob + 1];
//        for ( size_t i = 0; i <= size_line - num_prob; i++ )
//            line2[i] = line[i];
//        line2[size_line - num_prob] = '\0';
//        this->size = size_line - num_prob;
//        this->str = line2;
        this->size = strlen(str);
        this->str = strcpy(new char[size+1], str);
        
    }
    String( size_t n, char c ) : size(n)
    {
        this->str = new char[n+1];
        str[n+1] = '\0';
        for ( size_t i = 0; i < n; i++ )
            str[i] = c;
    }
    String(const String &other)  // Конструктор копирования
        : size(other.size), str(new char[size+1])
    {
        for ( size_t i = 0; i <= size; i++ )
            str[i] = other.str[i];
    }
//    String(const String &other) {
//        new (this) String(other.str);
//    }
    
//    String(const String &other) : String{other.str} {};
    
    /* Реализуйте оператор присваивания */
	String &operator=(const String &other)
    {
        if (this != &other)
        {
//            delete [] this->str;
//            this->size = other.size;
//            this->str = new char[this->size + 1];
//            strcpy( this->str, other.str );
            
            delete [] str;
            size = other.size;
            str = new char[size + 1];
            strcpy( str, other.str );
        }
        return *this;
    }
    
    char & at(size_t idx)       { return str[idx]; }
    char   at(size_t idx) const { return str[idx]; }
    
    void append(String &other)
    {
        char *temp = new char[this->size + other.size + 1];
        for ( size_t i = 0; i < this->size; i++ )
            temp[i] = this->str[i];
        for( size_t j = 0; j < other.size; j++ )
            temp[this->size + j] = other.str[j];
        temp[this->size + other.size] = '\0';
        delete [] this->str;
        this->str = temp;
        this->size += other.size;
        
//        size+=other.size;
//        char * m=new char[size+1];
//        strcpy(m,str);
//        strcat(m,other.str);
	    
//        delete [] str;
//        str=m;
    }
    
    ~String() {
        delete[] this->str;
    }
    
	size_t size;
	char *str;
};


//Класс Cls определен точно таким образом:
struct Cls {
    Cls(char c, double d, int i) : c(c), d(d), i(i) {}
    
private:
    char c;
    double d;
    int i;
};

// Эта функция должна предоставить доступ к полю c объекта cls.
// Обратите внимание, что возвращается ссылка на char, т. е.
// доступ предоставляется на чтение и запись.
char &get_c(Cls &cls) {
    return *( (char*)(&cls) );
}

// Эта функция должна предоставить доступ к полю d объекта cls.
// Обратите внимание, что возвращается ссылка на double, т. е.
// доступ предоставляется на чтение и запись.
double &get_d(Cls &cls) {
    return *( (double*)(&cls) + 1 );
}

// Эта функция должна предоставить доступ к полю i объекта cls.
// Обратите внимание, что возвращается ссылка на int, т. е.
// доступ предоставляется на чтение и запись.
int &get_i(Cls &cls) {
    return *( (int*)(&cls) + 4 );
}


struct Foo 
{
    void say() const { std::cout << "Foo says: " << msg << "\n"; }
    
protected:
    Foo(const char *msg) : msg(msg) { }
    
private:
    const char *msg;
};

void foo_says(const Foo &foo) 
{ 
    foo.say();
}

// Вам нужно определить функцию get_foo, как описано в задании,
// чтобы компилировался и работал как ожидается следующий код:
// foo_says(get_foo("Hello!"));
const Foo get_foo(const char *msg) 
{
    struct iFoo : public Foo
    {
        iFoo(const char *msg) : Foo(msg) { }
    };
    iFoo ifoo(msg);
    return ifoo;
}
//struct get_foo : public Foo
//{
//    get_foo(const char *msg) : Foo(msg) {}
//};

void foo(char) { std::cout << "char" << std::endl; }
void foo(signed char) { std::cout << "signed char" << std::endl; }
void foo(unsigned char) { std::cout << "unsigned char" << std::endl; }

float  square(float value) { return value * value; }
//double square(float value) { return (double)value * value; }  // error compile

void promotion(char &) { std::cout << "char" << std::endl; }
void promotion(int  &) { std::cout << "int"  << std::endl; }
void promotion(long &) { std::cout << "long" << std::endl; }



struct Number;
struct BinaryOperation;

struct Visitor {
    virtual void visitNumber(Number const * number) = 0;
    virtual void visitBinaryOperation(BinaryOperation const * operation) = 0;
    virtual ~Visitor() { }
};

struct Expression
{
    virtual double evaluate() const = 0;
    virtual void visit(Visitor * vistitor) const = 0;
    virtual ~Expression() { }
};

struct Number : Expression
{
    Number(double value)
        : value(value)
    {}
    ~Number(){}
    
    double evaluate() const
    {
        return this->value;
    }
    
    double get_value() const { return value; }

    void visit(Visitor * visitor) const { visitor->visitNumber(this); }
    
private:
    double value;
};

struct BinaryOperation : Expression
{
    BinaryOperation(Expression const * left, char op, Expression const * right)
        : left(left), right(right), op(op)
    { }
    ~BinaryOperation()
    {
        delete this->left;
        delete this->right;
    }
    
    double evaluate() const
    {
        switch(this->op)
        {
            case '+' : return this->left->evaluate() + this->right->evaluate();
            case '-' : return this->left->evaluate() - this->right->evaluate();
            case '*' : return this->left->evaluate() * this->right->evaluate();
            case '/' : {
                if(this->right->evaluate())
                    return this->left->evaluate() / this->right->evaluate();
            }
            default : return 0.0;
        }
    }
    
    Expression const * get_left() const { return left; }
    Expression const * get_right() const { return right; }
    char get_op() const { return op; }

    void visit(Visitor * visitor) const { visitor->visitBinaryOperation(this); }

private:
    Expression const * left;
    Expression const * right;
    char op;
};

bool check_equals(Expression const *left, Expression const *right)
{
    return ( ((void ***)left)[0][0] == ((void ***)right)[0][0] );
    //return *((void**)left) == *((void**)right);
}

struct PrintVisitor : Visitor 
{
    void visitNumber(Number const * number)
    {
        std::cout << "(";
        std::cout << number->get_value();
        std::cout << ") ";
    }

    void visitBinaryOperation(BinaryOperation const * bop)
    {
        std::cout << "( ";
        bop->get_left()->visit(this);
        std::cout << bop->get_op() << " ";
        bop->get_right()->visit(this);
        std::cout << ") ";
    }
};


int main()
{
 
    {
        
        {
    //        int x = 2;
    //        unsigned p = 16;
    //        cout << "x= " << x << endl;
    //        cout << "p= " << p << endl;
    //        int y = power2(x, p);
    //        cout << "y= " << y << endl << endl;
        }
        
        
        {
    //        int a = 10;
    //        int b = 20;
    //        int c = 0;
    //        MAX(a, b, c); // теперь c равно 20
    //        cout << "a1= " << a << endl;
    //        cout << "b1= " << b << endl;
    //        cout << "c1= " << c << endl << endl;
    //        MAX(a += b, b, c); // теперь a = с = 30
    //        //(c = ((a += b > b) ? (a += b) : (b)));
    //        cout << "a2= " << a << endl;
    //        cout << "b2= " << b << endl;
    //        cout << "c2= " << c << endl << endl;
        }
        
        
        {
    //        int T = 0;
    //        //cout << "Enter T = ";
    //        cin >> T;
    //        cout << endl;
    //        int a = 0;
    //        int b = 0;
    //        for(int i = 0; i < T; i++){
    //            cin >> a >> b;
    //            cout << (a + b) << endl;
    //        }
        }
        
        
        {
    //        int a, b, c;
    //        cin >> a >> b >> c;
    //        cout << endl;
    //        double D = (b * b) - 4 * a * c;
    //        if(D >= 0.0) 
    //            cout << double( (-b + sqrt(D)) / (2 * a) ) << " " << double( (-b - sqrt(D)) / (2 * a) );
    //        else cout << "No real roots" << endl;
        }
        
        
        {
    //        unsigned num_gap = 0;
    //        char c = '\0';
    //        while (cin.get(c)) {
    //            if ( c != ' ') {
    //                cout << c;
    //                num_gap = 0;
    //            } else {
    //                num_gap++;
    //                if(num_gap < 2) {
    //                    cout << c;
    //                } else continue;
    //            }
    //        }
        }
        
        
        {
    //        int T = 0;
    //        cin >> T;
    //        cout << endl;
    //        int a = 0;
    //        int p = 0;
    //        for(int i = 0; i < T; i++){
    //            cin >> a;
    //            while(a /= 2){
    //                p++;
    //            }
    //            cout << p << endl;
    //            p = 0;
    //        }
        }
        
        
        {
            // Break brain
    //        bar();
        }
        
        
        {
    //        int c = fibonacci(0);
    //        cout << "c = " << c << endl;
    //        c = fibonacci(1);
    //        cout << "c = " << c << endl;
    //        c = fibonacci(2);
    //        cout << "c = " << c << endl;
    //        c = fibonacci(3);
    //        cout << "c = " << c << endl;
    //        c = fibonacci(4);
    //        cout << "c = " << c << endl;
    //        c = fibonacci(5);
    //        cout << "c = " << c << endl;
    //        c = fibonacci(6);
    //        cout << "c = " << c << endl;
    //        c = fibonacci(7);
    //        cout << "c = " << c << endl;
        }
        
        
        {
    //        unsigned z = gcd2(24, 54);
    //        cout << "z = " << z << endl;
        }
        
        
        {
    //        revers_str();
    //        int n = 0;
    //        cin >> n;
    //        if (n != 0) {main(); cout << n << " ";} return 0;
        }
        
        
        {
    //        int a[] = { 1, 2, 3, 4, 5 }; 
    //        unsigned size = 5;
    //        int shift = 7;
    //        rotate( a, size, shift );   // &a[0]
    //        //rotate2( a, size, shift );
    //        cout << "end" << endl;
        }
        
        
        {
    //        const char * str = "C-style";
    //        cout << "str: " << str << endl;
    //        unsigned num_len = strlen(str);
    //        cout << "len = " << num_len << endl;
        }
        
        
        {
    //        char str_to[15] = "C-";
    //        const char * str_from = "style";
    //        cout << "str_to: " << str_to << endl;
    //        cout << "str_from: " << str_from << endl;
    //        strcat( str_to, str_from );
    //        cout << "str_to + str_from: " << str_to << endl;
        }
        
        
        {
    //        for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); ++i) {
    //            int ret = strstr(tests[i].text, tests[i].pattern);
    //            (tests[i].ret_value == ret) ? cout << "OK" : cout << "Failed";
    //             cout << " : " << i << " (" << tests[i].ret_value << " : " << ret << ")" << endl;
    //        }
        }
        
        
        {
    //        int b = 19;
    //        int & l = b;
    //        cout << "b= " << b << endl;
    //        cout << "&b= " << &b << endl;
    //        cout << "&l= "<< &l << endl;
    //        int a = 42;
    //        int * p = &a;
    //        int ** pp = &p;
    //        int & d = a;
    //        int * pd = &d;
    //        cout << "a= "<< a << endl;
    //        cout << "p= "<< p << endl;
    //        cout << "pp= "<< pp << endl;
    //        cout << "d= "<< d << endl;
    //        cout << "pd= "<< pd << endl;
    //        cout << "*pd= "<< *pd << endl;
        }
        
        
        {
    //        int * m = (int *)malloc( 1000 * sizeof (int));
    //        m[9] = 9;
    //        *(m+10) = 10;
    //        free(m);
    //        m = 0;
            
    //        int * n = new int(5);
    //        delete n;
    //        int * t = new int[1000];
    //        delete [] t;
            
            
    //        unsigned size = 5;
    //        char * str = new char[size];
            
    //        cout << "str[size] = ";
    //        for ( unsigned i = 0; i < size ; i++ )
    //        {   
    //            str[i] = 0b01000110;
    //            cout << str[i];
    //        }
    //        cout << endl;
            
    //        unsigned new_size = 15;
    //        char * new_str = resize( str, size, new_size );
            
    //        cout << "new_str[new_size] = ";
    //        for ( char * ptr = new_str ; ptr <= new_str + new_size ; ptr++ )
    //        {
    //            cout << *ptr;
    //        }
    //        cout << endl;
            
    //        delete [] new_str;
        }
        
        
        {
    //        for ( char * str = getline(); (*str != '\n') && (*str != '\0'); cout << *str++ );
        }
        
        
        {
    //        unsigned rows = 7;
    //        unsigned cols = 9;
    //        cout << " rows = " << rows << endl;
    //        cout << " cols = " << cols << endl;
    //        int ** m = create_array2d( rows, cols );
    //        for ( size_t i = 0; i < cols; i++ )
    //            for ( size_t j = 0; j < rows; j++ )
    //                m[j][i] = int( (i - rows/2)*(i - rows/2) + (j - cols/2)*(j - cols/2) );
    //        cout << "m[rows][cols] = " << endl;
    //        print_array2d( m, rows, cols );
            
    //        int ** mt = transpose( m, rows, cols );
    //        cout << "mt[cols][rows] = " << endl;
    //        print_array2d( mt, cols, rows );
            
    //        swap_min( m, rows, cols );
    //        cout << "m_swap_min[rows][cols] = " << endl;
    //        print_array2d( m, rows, cols );        
            
    //        free_array2d( mt );
    ////        free_array2d( m );
        }
        
        
        {
    //        string str = "hello";
    //        ivector3d iv3d;
    //        iv3d.array = new int [3];
    //        for ( int i = 0; i < 3; i++ ) 
    //        {
    //            iv3d.array[i] = i + 1;
    //            cout << iv3d.array[i] << '\t';
    //        }
    //        cout << endl;
    //        scale(iv3d, 2);
    //        for ( int i = 0; i < 3; i++ )
    //            cout << iv3d.array[i] << '\t';
        }
        
        
        {
    //        //String str = " H ";
    //        String str2( 5, 'F' );
    //        //cout << strlen( "Hello world   " ) << endl;
    //        for ( const char * a = str2.str; *a; a++ )
    //            cout << *a;
    //        cout << endl << endl;
            
    //        String s1("Hello,");
    //        String s2(" world!");
    //        s1.append(s2); // теперь s1 хранит "Hello, world!"
    //        for ( const char * a = s1.str; *a; a++ )
    //            cout << *a;
    //        cout << endl;
        }
        
        
        {
    //        Cls cdi('F', 2.64, 1031);
    //        Cls cdi2('A', 3.78, 842);
    //        Cls & link = cdi;
    //        cout << "Size of CLS = " << sizeof(link) << endl << endl;
    //        //char & ccc = *link.c;
    //        cout << "cast char = \t" << *( (char*)(&link) ) << endl;
    //        cout << "cast double = \t" << *( (double*)(&link) + 1 ) << endl;
    //        cout << "cast int = \t" << *( (int*)(&link) + 4 ) << endl << endl;
            
    //        for ( unsigned i = 0; i < sizeof(link); i++ )
    //            cout << short( *( (uint8_t*)(&link) + i ) ) << endl;
    //        cout << endl;
            
    //        cout << "get_c(cdi) = \t" << get_c(cdi) << endl;
    //        cout << "get_d(cdi) = \t" << get_d(cdi) << endl;
    //        cout << "get_i(cdi) = \t" << get_i(cdi) << endl << endl;
            
    //        cout << "get_c(cdi2) = \t" << get_c(cdi2) << endl;
    //        cout << "get_d(cdi2) = \t" << get_d(cdi2) << endl;
    //        cout << "get_i(cdi2) = \t" << get_i(cdi2) << endl << endl;
            
    //        cout << " change cdi" << endl;
    //        char &cc = get_c(cdi);
    //        cc = 'G';
    //        double &dd = get_d(cdi);
    //        dd = 4.348;
    //        int &ii = get_i(cdi);
    //        ii = 413;
    //        cout << "get_c(cdi) = \t" << get_c(cdi) << endl;
    //        cout << "get_d(cdi) = \t" << get_d(cdi) << endl;
    //        cout << "get_i(cdi) = \t" << get_i(cdi) << endl << endl;
        }
        
        
        {
//            String abc = "abc";
//            cout << "abc = " << abc.str << endl;
//            String def = abc;
//            cout << "def = " << def.str << endl;
        }
        
        
        {
//            foo_says(get_foo("Hello!"));
        }
        
        
        {
    //        foo('a');
    //        //foo(97); // error compile
            
    //        String greet("Hello");
    //        char ch1 = greet.at(0);
    //        String const const_greet("Hello, Const!");
    //        char const &ch2 = const_greet.at(0);
            
    //        short sh = 10;
    //        //promotion(sh);  // error compile
        }
        
        
        {
    //        // сначала создаём объекты для подвыражения 4.5 * 5
    //        Expression * sube = new BinaryOperation(new Number(4.5), '*', new Number(5));
    //        // потом используем его в выражении для +
    //        Expression * expr = new BinaryOperation(new Number(3), '+', sube);
    //        // вычисляем и выводим результат: 25.5
    //        std::cout << expr->evaluate() << std::endl;
            
    //        Expression *a = new BinaryOperation(new Number(1), '/', new Number(2));
    //        Expression *b = new BinaryOperation(new Number(5), '+', a);
    //        // вычисляем и выводим результат: 5.5
    //        std::cout << b->evaluate() << std::endl;
            
    //        // тут освобождаются *все* выделенные объекты
    //        // (например, sube будет правым операндом expr, поэтому его удалять не нужно)
    //        delete expr;
    //        delete b;
        }
        
        
        {
//            Expression *a = new BinaryOperation(new Number(1), '/', new Number(2));
//            Expression *b = new BinaryOperation(new Number(6), '+', a);
//            Expression *c = new Number(9.1);
            
//            cout << check_equals(a, b) << endl; // a & b - same class
//            cout << check_equals(a, c) << endl; // a & c - different class
            
//            //delete a;BinaryOperation bo(new Number(35), '/', new Number(7)); 
//            Number num(10.3);
//            delete b;
//            delete c;
        }
        
    }
    
    
    {
        Expression *a = new BinaryOperation(new Number(1), '+', new Number(-2));
        Expression *b = new BinaryOperation(new Number(6), '/', a);
        Expression *c = new Number(9.1);
        Expression *d = new BinaryOperation(b, '/', c);
        
        PrintVisitor visitor;
        a->visit(&visitor);
        cout << " = " << a->evaluate() << endl;
        b->visit(&visitor);
        cout << " = " << b->evaluate() << endl;
        c->visit(&visitor);
        cout << " = " << c->evaluate() << endl;
        d->visit(&visitor);
        cout << " = " << d->evaluate() << endl;
        
        //delete a;
        //delete b;
        //delete c;
        delete d;
    }
    
    
    return 0;
}
