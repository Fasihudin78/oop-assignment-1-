#include<iostream>
using namespace std;
class Rectangle
{
private:
	float length;
	float width;
public:
	Rectangle()
	{
		length=1;
		width=1;
	}
	Rectangle(float length, float width)
	{
		this->length=length;
		this->width=width;
	}
	void setlength(float len)
	{
		if(len>0.0 && len<20.0)
		{
		this->length=len;
		}
		else
		{
			cout<<"Number Not Valid"<<endl;
		}
		
	}
	void setwidth(float wid)
	{
		if(wid>0.0 && wid<20.0)
		{
		this->width=wid;
		}
		else
		{
			cout<<"Number Not Valid"<<endl;
		}
		
		
	}
	float Perimeter()
	{
		return 2*(length+width);
	}
	float Area()
	{
		return length*width;
	}

	
	void display()
	{
		if (length>0.0 && width<=20.0)
		{
		float rec;
		rec=length*width;
		cout<<"Area is "<<rec<<endl;
		}
		else 
		{
			cout<<"Measurment is not reliable"<<endl;
		}
	}
};
int main()
{
	 Rectangle r1(2.1,19.5);
	
	
	cout<<r1.Perimeter()<<endl;
	cout<<r1.Area()<<endl;
	
	
	return 0;
}