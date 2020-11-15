#include<iostream>
#include<string>
#include <ctime>
using namespace std;
string getCurrentDate();

class item
{
private:
    int id;
    string name;
    float price;
    string discription;
    string createdAt;
    string updatedAt;
    string type;
public:
    item()
    {
        id=0;
        name=" ";
        price=0.0;
        discription=" ";
        createdAt="00.00";
        updatedAt="00.00";
        type=" ";
    }
	

    int getId() const {
        return id;
    }

    void setId(int iid) {
        this->id = iid;
    }

    const string getName() const {
        return name;
    }

    void setName(const string iname) {
        this->name = iname;
    }

    float getPrice() const {
        return price;
    }

    void setPrice(float iprice) {
        this->price = iprice;
    }

    const string getDiscription() const {
        return discription;
    }

    void setDiscription(const string idiscription) {
        this->discription = idiscription;
    }

    string getCreatedAt() const {
        return createdAt;
    }

    void setCreatedAt(string icreatedAt) {
			this->createdAt = icreatedAt;
    }

    string getUpdatedAt() const {
        return updatedAt;
    }

    void setUpdatedAt(string iupdatedAt) {
        this->updatedAt = iupdatedAt;
    }

    const string getType() const {
        return type;
    }

    void setType(const string itype) {
        this->type = itype;
    }
};
class Orderdetail
{
private:
    int id;
    double orderId;
    int Quantity;
	item *itm; 

public:
    Orderdetail()
    {
        int id=0;
        double orderId=0;
        double itemId=0;
        int Quantity=0;
    }
    Orderdetail(int od_id,	double od_orderId,	int od_Quantity)
    {
        this->id=od_id;
        this->orderId=od_orderId;
        this->Quantity=od_Quantity;
    }

    void setId(int od_id) {
		this->id = od_id;
    }

    void setOrderId(double od_orderId) {
       this->orderId = od_orderId;
    }

    void setItm(item * od_itm)
	{
		this->itm = od_itm;
	}

    void setQuantity(int od_quantity) {
       this->Quantity = od_quantity;
    }

    int getId() const {
        return id;
    }

    double getOrderId() const {
        return orderId;
    }

    item* getItem() const {
        return itm;
    }

    int getQuantity() const {
        return Quantity;
    }
    void display()
    {
        cout<<"Id: "<<id<<" "<<" Order Id:  "<<orderId<<" Item Id: "<<itm->getId()<<" Item Name: "<<itm->getName() <<" Quantity: "<<Quantity<<endl;
    }
};

class order
{
private:
    int id;
    string discription;
    string createdAt;
	string updatedAt;
    string username;
    string pickuptime;
    string pickupform;
    string deliveryTime;
    string deliveryTo;
    string status;
    Orderdetail ** orddtl  ;
	int odCount ;
public:
    order()
    {
        id=0;
         discription=" ";
         createdAt="";
         updatedAt="";
         username=" ";
         pickuptime = "";
         pickupform = "";
         deliveryTime = "";
         deliveryTo = "";
         status=" ";
		 odCount =0;
    }

    int getId() const {
        return id;
    }

    void setId(int id) {
       this->id = id;
    }

	void setOrderDetail( Orderdetail ** IOrdrDtl)
	{
		orddtl = IOrdrDtl;
	}
	Orderdetail ** getOrderDetail()
	{
		return orddtl;
	}
    const string getDiscription() const {
        return discription;
    }

    void setDiscription(const string &discription) {
        this->discription = discription;
    }

    string getCreatedAt() const {
        return createdAt;
    }

    void setCreatedAt(string createdAt) {
       this->createdAt = createdAt;
    }

    string getUpdatedAt() const {
        return updatedAt;
    }

    void setUpdatedAt(string updatedAt) {
        this->updatedAt = updatedAt;
    }

    const string getUsername() const {
        return username;
    }

    void setUsername(const string &username) {
        this->username = username;
    }

    string getPickuptime() const {
        return pickuptime;
    }

    void setPickuptime(string pickuptime) {
        this->pickuptime = pickuptime;
    }

    string getPickupform() const {
        return pickupform;
    }

    void setPickupform(string pickupform) {
        this->pickupform = pickupform;
    }

    string getDeliveryTime() const {
        return deliveryTime;
    }

    void setDeliveryTime(string deliveryTime) {
       this->deliveryTime = deliveryTime;
    }

    string getDeliveryTo() const {
        return deliveryTo;
    }

    void setDeliveryTo(string o_deliveryTo) {
        this->deliveryTo = o_deliveryTo;
    }

    const string getStatus() const {
        return status;
    }

    void setStatus(const string istatus) {
        this->status = istatus;
    }

	int getodCount()
	{
		return odCount;
	}
	void setodCount(int o_odCount)
	{
		this->odCount = o_odCount;
	}
	void display()
	{
		 cout<<"_______________________________________________________"<<endl;
		 cout<<discription<<endl;
         cout<<createdAt<<endl;
         cout<<updatedAt<<endl;
         cout<<username<<endl;
         cout<<pickuptime<<endl;;
         cout<<pickupform<<endl;
         cout<<deliveryTime<<endl;;
         cout<<deliveryTo<<endl;
         cout<<status<<endl;
		 cout<<"_________________Order Detail__________________"<<endl;

		 for(int i = 0; i < odCount; i++) 
		 {
			 orddtl[i]->display();
		 }
		 cout<<endl;
	}

};
int main()
{
    item itm [20];
	
	for (int i = 0; i < 20; i++)
	{
		itm[i].setId(i+1);
		itm[i].setName("item "  + to_string(i+1));
		itm[i].setPrice((float)10*(i+1));
		itm[i].setDiscription("Discription "+to_string(i+1));
		itm[i].setType("Type "+ to_string(i+1));
		itm[i].setCreatedAt(getCurrentDate());
		itm[i].setUpdatedAt(getCurrentDate());
	}
	
	order ordr[5];

	string OrdrDesc;
	string usrName ;
	int ODNo;
	for(int j = 0; j <5;j++)
	{
		ordr[j].setId(j+1);
		ordr[j].setDiscription("Order No: " + to_string(j+1));
		ordr[j].setCreatedAt(getCurrentDate());
		ordr[j].setUpdatedAt(getCurrentDate());
		ordr[j].setUsername("Ali");
		ordr[j].setPickuptime(getCurrentDate());
		ordr[j].setPickupform("Store");
		ordr[j].setDeliveryTime("10 pm");
		ordr[j].setDeliveryTo("Customer");
		ordr[j].setStatus("Delivered");
		
		/*cout<<endl<<"How many are Order Details: ";
		cin>> ODNo; */
		ODNo = 5;
		Orderdetail ** od;
		od  =   new Orderdetail * [ODNo];
		for(int t = 0; t<ODNo; t++)
		{
			od [t] = new Orderdetail();
			od [t]->setId(t+1);
			od [t]->setOrderId(j+1);
			od [t]->setQuantity(50);
			od [t]->setItm(&itm[t]);
		}

		ordr[j].setOrderDetail(od);
		ordr[j].setodCount(ODNo);
	}
	for(int i = 0; i < 5; i++)
	{
		ordr[i].display();
	}
    return 0;
}

string getCurrentDate()
{
	time_t t = time(0);
	return ctime(&t);
}