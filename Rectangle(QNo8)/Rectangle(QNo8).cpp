#include<iostream>
#include<math.h>
using namespace std;
class point
{
private:
	float x;
	float y;
public:
	point()
	{
		x= 1;
		y = 1;
	}
	point(float p_x,float p_y)
	{
		
	setX(p_x);
	setY(p_y);
	}

	void setX( float p_x)
	{
		if(p_x<0)
		{
			p_x=1;
		}
		else if(p_x>20.0)
		{
			p_x=20.0;
		}
		this->x=p_x;
	}
	void setY( float p_y)
	{
		if(p_y<0)
		{
			p_y=1;
		}
		else if(p_y>20.0)
		{
			p_y=20.0;
		}
		this->y=p_y;
	}
	float getX()
	{
		return this->x;
	}
	float getY()
	{
		return this->y;
	}
};
class Rectangle
{
	private:
		point Lr;
		point Ll;
		point tr;
		point tl;
		float length;
		float width;
	public:
		Rectangle()
		{
			length = 0;
			width = 0;
		}
		Rectangle(point r_Lr,point r_LL, point r_TR, point r_TL)
		{
			this->Lr=r_Lr;
			this->Ll=r_LL;
			this->tr=r_TR;
			this->tl=r_TL;
		}
		float getDistance(point a, point b)
		{
			float res;
			res= sqrt(pow((b.getX()-a.getX()),2) +pow((b.getY()-a.getY()),2));
			return res;
		}
		bool isRectangle()
		{
			float tl_tr = this->getDistance(tl,tr);
			float Ll_Lr = this->getDistance(Ll,Lr);
			if (tl_tr != Ll_Lr) return false;
			float tl_ll = this->getDistance(tl,Ll);
			float tr_Lr = this->getDistance(tr,Lr);
			if (tl_tr != Ll_Lr) return false;
			float tl_lr = this->getDistance(tl,Lr);
			float tr_Ll = this->getDistance(tr,Ll);
			if (tl_lr != tr_Ll) return false;

			return true;
		}
		void setDimension()
		{
			float tl_tr = this->getDistance(tl,tr);
			float tl_ll = this->getDistance(tl,Ll);
			if(tl_tr >= tl_ll) 
			{
					length = tl_tr;
					width = tl_ll;
			}
			else
			{
				width = tl_tr;
				length = tl_ll;
			}
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
	float getPerimeter()
	{
		return 2*(length+width);
	}
	float getArea()
	{
		return length*width;
		}
	float getLength()
	{
		return this->length;
	}
	float getWidth()
	{
		return this->width;
	}
	 void display()
	{
		if( isRectangle())
		{
			setDimension();
			cout<<"Given Coordinates are a rectangle"<<endl;
			cout<<"Length of Rectabgle: "<<getLength()<<endl;
			cout<<"Width of Rectabgle: "<<getWidth()<<endl;
			cout<<"Area of Rectabgle: "<<getArea()<<endl;
			cout<<"Perimeter of Rectabgle: "<<getPerimeter()<<endl;
			if(isSquare())	cout<<"This a Square"<<endl;
		}
		else
		{
				cout<<"Given Coordinates are not a rectangle"<<endl;
		}
		
	}
	 bool isSquare()
	 {
		 if(isRectangle())
		 {
			 setDimension();
			return (length == width);
		 }
		 else
			 return false;
	 }
		
	};
	int main()
	{
		float x;
		float y;
		cout<<"Top_Left coordinate x: ";
		cin>>x;
		cout<<endl<<"Top_Left coordinate y: ";
		cin>>y;
		point T_L (x,y);
		cout<<"Top_Right coordinate: x: ";
		cin>>x;
		cout<<endl<<"Top_Right coordinate y: ";
		cin>>y;
		point T_R (x,y);
		cout<<"Lower_Left coordinate x:";
		cin>>x;
		cout<<endl<<"Lower_Left coordinate y: ";
		cin>>y;
		point L_L (x,y);
		cout<<"Lower_Right coordinate x:";
		cin>>x;
		cout<<endl<<"Lower_Right coordinate y: ";
		cin>>y;
		point L_R (x,y);
		Rectangle r (L_R,L_L,T_R,T_L);
		r.display();
		return 0;

	}
	