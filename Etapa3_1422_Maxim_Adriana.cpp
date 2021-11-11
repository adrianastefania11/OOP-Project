#include<bits/stdc++.h>
using namespace std ;


/////////////////////////////////////////////////////////////////////////////////


class Desc
{
public :
    virtual void  descjob()=0;
    virtual void login()=0;
    };


class Booking
{
 protected :
     int nb;
 public :
    Booking() {this->nb=0;}
    Booking(int nb){this->nb=nb;}
    virtual void addBooking()=0;
    virtual ostream& AfisareVirtuala(ostream& out) const {out<<"\nNumarul de rezervari introduse ultima data  "<<nb; return out;}
    virtual istream& CitireVirtuala (istream& in){cout<<"\nIntroduceti numarul de rezervari "; in>>nb; return in;}
    friend ostream& operator<<(ostream& out , const Booking& b) { return b.AfisareVirtuala(out); }
    friend istream& operator>>(istream& in,Booking& b ){  return b.CitireVirtuala(in);}
    ~Booking(){};

};

class Event
{
private:
    string eventType;
    char dayOfTheWeek;
    int dayOfEvent;
    char* monthEvent;
    int year;
    int nbOfResouces;
    string* resources;
    int* nbEachRes;
    float totalCost;
    float* costs;
    double numberOfParticipants;
    bool stage;


public:
    static int contorId;

    string getEventType(){return eventType;}
    void setEventType(string nEventType) {eventType=nEventType;}

    char getDayOfTheWeek() {return dayOfTheWeek;}
    void setDayOfTheWeek( char nDay ) { dayOfEvent=nDay;}

    int getDayOfEvent() {return dayOfEvent;}
    void setDayOfEvent (int nval) {dayOfEvent=nval;}

    int getYear() {return year;}
    void setYear (int yy ) { year=yy;}

    int getNbOfResouces() {return nbOfResouces;}
    void setNbOfResources(int nnb) { nbOfResouces=nnb;}

    float getTotalCost()  {return totalCost;}
    void setTotalCost(float ncost){totalCost=ncost;}

    double getNumberOfParticipants() {return numberOfParticipants;}
    void setNumberOfParticipants( double nnbP) {numberOfParticipants=nnbP;}

    bool getstage() { return stage;}
    void setStage(bool nstage) {stage=nstage;}

    char* getMonthEvent(){return monthEvent;}
    void setMonthEvent(char* nMonthEvent)
    {
        if (monthEvent != NULL)
		   delete[] monthEvent;
        monthEvent= new char[strlen(nMonthEvent) + 1];
	    strcpy(monthEvent, nMonthEvent);
    }

    string* getResources() {return resources;}
    void setResources(string* res ,int nbres)
    {
        if(resources!=NULL)
            delete[] resources;
        resources=new string[nbres+1];
        for(int i=0; i<nbres;i++)
            resources[i]=res[i];
    }

    int *getNbEachRes(){return this->nbEachRes;}
    void setNbEachRes(int* newNbEachRes , int nbres)
    {
          if(nbEachRes!=NULL)
                delete[] nbEachRes;
          nbEachRes=new int[nbres];
          for(int i=0;i<nbres;i++)
            nbEachRes[i]=newNbEachRes[i];
    }

    float* getCosts() {return this->costs;}
    void setCosts(float* ncosts , int nbres)
    {
        if(costs!=NULL)
            delete[] costs;
        costs=new float[nbres];
        for(int i=0;i<nbres;i++)
            costs[i]=ncosts[i];
    }


    Event& operator=(const Event& ev);

    virtual ostream& AfisareVirtuala(ostream& out)const;
    virtual istream& CitireVirtuala (istream& in);

    friend ostream& operator<<(ostream& out , const Event& ev);
    friend istream& operator>>(istream& in,Event& ev );

    Event();

    Event(const Event& ev);

    Event(string eventType,char dayOfTheWeek, int dayOfEvent,char* monthEvent, int year,
          int nbOfResouces,string* resources,int* nbEachRes,float* costs,float totalCost, double numberOfParticipants,
          bool stage);

    Event  operator-(int x){this->numberOfParticipants=this->numberOfParticipants-x; return *this;}
    Event operator+(Event ev)
    {  ev.numberOfParticipants=this->numberOfParticipants+ev.numberOfParticipants;
        ev.totalCost=this->totalCost+ev.totalCost;
        return ev;}

    explicit operator int(){return (int)this->totalCost;}
    int&  operator[](int index );
    bool operator==(const Event&ev ){

        if(this->numberOfParticipants==ev.numberOfParticipants && this->totalCost==ev.totalCost)
            return true;
          return false;}

    void CostEachRes();

   virtual ~Event();
};
ostream& Event::AfisareVirtuala (ostream& out) const
{
        out<<"\nTipul evenimentului: " <<eventType;
        out<<"\nZiua saptamanii in care se desfasoara: "<<dayOfTheWeek;
        out<<"\nData: "<<dayOfEvent <<"."<<monthEvent<<"."<<year;
        out<<"\nNumarul de participanti: "<<numberOfParticipants;
        out<<"\nNumarul de resurse disponibile: "<<nbOfResouces;
        out<<"\nResursele:";
        for(int i=0; i<nbOfResouces;i++)
           { out<<"\n  "<<i+1<<" "<<resources[i]<<" in numar de  "<<nbEachRes[i]<<" care a\au costat in total "<<costs[i];  }
        out<<"\nCostul total: "<<totalCost;
        out<<"\nStadiul Evenimentului: "<<stage;

     return out;
}

ostream& operator<<(ostream& out, const Event& ev)
{
      return ev.AfisareVirtuala(out);
}
istream& Event::CitireVirtuala(istream& in)
{
       cout<<"\nIntroduceti: ";
       cout<<"\nTipul evenimetului "; in>> eventType;
       cout<<"\nZiua saptamanii "; in>> dayOfTheWeek ;
       cout<<"\nZiua din luna: "; in>> dayOfEvent;
       cout<<"\nLuna: ";
          char aux[100]; in>>aux;
          if( monthEvent!=NULL)
            delete[]  monthEvent;
           monthEvent=new char[strlen(aux)+1]; strcpy( monthEvent,aux);
       cout<<"\nAnul: ";in>> year;
       cout<<"\nNumarul de resurse disponibile "; in>> nbOfResouces;
       if(nbOfResouces!=0)
         cout<<"\nCare sunt resursele?";
         if( resources!=NULL) delete[]  resources;
         if( costs!=NULL) delete[]  costs;
         if( nbEachRes!=NULL) delete[]  nbEachRes;
          resources=new string[ nbOfResouces];
          costs=new float[ nbOfResouces];
          nbEachRes=new int[ nbOfResouces];
         float s=0.0;
         for(int i=0;i< nbOfResouces;i++)
           {  cout<<"resursa "<<i+1<<" "; in>> resources[i];
              cout<<" in numar de " ; in>> nbEachRes[i];
              cout<<"pretul resursei "<<i+1<<" "; in>> costs[i]; s=s+ costs[i];}
          // totalCost=s;
           setTotalCost(s);  getTotalCost();
       cout<<"\nNumarul de participanti "; in>> numberOfParticipants;
       cout<<"\nStadiul "; in>> stage;

    return in;

}
istream& operator>>(istream& in,Event& ev )
{
      return ev.CitireVirtuala(in);
}

//constructor fara param
Event::Event()
    {

        this->dayOfTheWeek='a';
        this->dayOfEvent=0;
        this->monthEvent=new char[strlen("NoName")+1];
        strcpy(this->monthEvent,"NoName");
        this->nbOfResouces=0;
        this->year=0;
        this->stage=0;
        this->numberOfParticipants=0;
        this->resources=NULL;
        this->nbEachRes=NULL;
        this->totalCost=0;
        this->costs=NULL;

    }
//constructor cu toti param
Event::Event(string eventType,char dayOfTheWeek, int dayOfEvent,char* monthEvent, int year,int nbOfResouces,string* resources,int* nbEachRes,float* costs,
             float totalCost, double numberOfParticipants, bool stage)
    {
        this->eventType=eventType;
        this->dayOfTheWeek=dayOfTheWeek;
        this->dayOfEvent=dayOfEvent;
        this->monthEvent=new char[strlen(monthEvent)+1];
        strcpy(this->monthEvent,monthEvent);
        this->year=year;
        this->nbOfResouces=nbOfResouces;
        this->stage=stage;
        this->numberOfParticipants=numberOfParticipants;
        this->resources=new string [nbOfResouces];
        for(int i=0 ; i<nbOfResouces; i++)
            this->resources[i]=resources[i];
        this->nbEachRes=new int[nbOfResouces];
        for(int i=0;i<nbOfResouces;i++)
            this->nbEachRes[i]=nbEachRes[i];
        this->totalCost=totalCost;
        this->costs=new float[nbOfResouces];
        for(int i=0 ; i<nbOfResouces; i++)
            this->costs[i]=costs[i];
    }
//copy constructor
Event::Event(const Event& ev)
   {
        this->eventType=ev.eventType;
        this->dayOfTheWeek=ev.dayOfTheWeek;
        this->dayOfEvent=ev.dayOfEvent;
        this->monthEvent=new char[strlen(ev.monthEvent)+1];
        strcpy(this->monthEvent,ev.monthEvent);
        this->year=ev.year;
        this->nbOfResouces=ev.nbOfResouces;
        this->stage=ev.stage;
        this->numberOfParticipants=ev.numberOfParticipants;
        this->resources=new string [ev.nbOfResouces];
        for(int i=0 ; i<ev.nbOfResouces; i++)
            this->resources[i]=ev.resources[i];
        this->nbEachRes=new int[ev.nbOfResouces];
        for(int i=0;i<ev.nbOfResouces;i++)
            this->nbEachRes[i]=ev.nbEachRes[i];
        this->totalCost=ev.totalCost;
        this->costs=new float[ev.nbOfResouces];
        for(int i=0 ; i<ev.nbOfResouces; i++)
            this->costs[i]=ev.costs[i];
    }

Event& Event:: operator=(const Event& ev)
{
     if(this!=&ev)
        {
            if( this->monthEvent!=NULL) delete[] this->monthEvent;
            if(this->resources!=NULL) delete[] this->resources;
            if(this->nbEachRes!=NULL) delete[] this->nbEachRes;
            if(this->costs!=NULL) delete[] this->costs;

            this->eventType=ev.eventType;
            this->dayOfTheWeek=ev.dayOfTheWeek;
            this->dayOfEvent=ev.dayOfEvent;
            this->monthEvent=new char[strlen(ev.monthEvent)+1];
            strcpy(this->monthEvent,ev.monthEvent);
            this->year=ev.year;
            this->nbOfResouces=ev.nbOfResouces;
            this->stage=ev.stage;
            this->numberOfParticipants=ev.numberOfParticipants;
            this->resources=new string [ev.nbOfResouces];
            for(int i=0 ; i<ev.nbOfResouces; i++)
                this->resources[i]=ev.resources[i];
            this->nbEachRes=new int[ev.nbOfResouces];
               for(int i=0;i<ev.nbOfResouces;i++)
                   this->nbEachRes[i]=ev.nbEachRes[i];
            this->totalCost=ev.totalCost;
            this->costs=new float[ev.nbOfResouces];
            for(int i=0 ; i<ev.nbOfResouces; i++)
                this->costs[i]=ev.costs[i];
            }


        return *this;
}


  int& Event::operator[](int index){

    if(0<=index && index<this->nbOfResouces)
            return nbEachRes[index];
    else
           cout<<"Ai introduse index gresit";

    }


 void Event::CostEachRes()
 {
     cout<<"Pretul fiecarei resurse: "<<endl;
     for(int i=0;i<this->nbOfResouces;i++)
        cout<<"o bucata din resursa "<<this->resources[i]<<" a costat "<<this->costs[i]/this->nbEachRes[i]<<endl;
 }


//Destructor

Event::~Event()
   {
        if( this->monthEvent!=NULL) delete[] this->monthEvent;
        if(this->resources!=NULL) delete[] this->resources;
        if(this->nbEachRes!=NULL) delete[] this->nbEachRes;
        if(this->costs!=NULL) delete[] this->costs;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////
class Venues :public Event
{
private:
    string venueName;
    string venueAdress;

public:
    string getVenueName(){return venueName;}
    void setVenueName(string nVenueName) {venueName=nVenueName;}

     string getVenueAdress(){return venueAdress;}
     void setVenueAdress(string nVenueAdress) {venueAdress=nVenueAdress;}

     Venues():Event()
     {
         this->venueName=venueName;
         this->venueAdress=venueAdress;
     }

     Venues(string eventType,char dayOfTheWeek, int dayOfEvent,char* monthEvent, int year,int nbOfResouces,string* resources,int* nbEachRes,float* costs,
             float totalCost, double numberOfParticipants, bool stage,string venueName,string venueAdress):Event(eventType,dayOfTheWeek,dayOfEvent,monthEvent,year,nbOfResouces,resources,nbEachRes,costs,
              totalCost,numberOfParticipants,stage)
        {
         this->venueName=venueName;
         this->venueAdress=venueAdress;
        }

     Venues(const Venues& ev):Event(ev)
     {
         this->venueName=ev.venueName;
         this->venueAdress=ev.venueAdress;
     }

    Venues& operator=(const Venues& ev)
    {
        if(this!=&ev)
        {
            Event::operator=(ev);
            this->venueName=ev.venueName;
            this->venueAdress=ev.venueAdress;

        }
     return *this;
    }



    virtual ostream& AfisareVirtuala(ostream& out)const
    {
        Event::AfisareVirtuala(out);
        out<<"\nNumele locatiei: "<<venueName;
        out<<"\nAdresa locatiei:  "<<venueAdress;

        return out;

    }

   virtual istream& CitireVirtuala (istream& in)
    {
        Event::CitireVirtuala(in);
        cout<<"\nNumele locatiei: ";
        in>>venueName;
        cout<<"\nAdresa locatiei: ";
        in>>venueAdress;
        return in;
    }

    ~Venues(){}
    void ChangeVenue()
    {
        string name, adress;
        cout<<"Introduceti numele noii locatii ";
        cin>>name;
        cout<<"Introduceti adresa noii locatii ";
        cin>>adress;
        this->venueName=name;
        this->venueAdress=adress;

    }
};



 //////////////////////////////////////////////////////////////////////////////////////////////////
class Users
{
  private:
    const int userId;
    string userEmail;
    string userPassword;
    int userEvents;
    bool user;

  public:
    static int contorId;


   string getUserEmail(){return userEmail;}
   void setUserEmail(string email){userEmail=email;}

   string getUserPassword() {return userPassword;}
   void setUserPasswor(string password){userPassword=password;}

   int getUserEvents(){return userEvents;}
   void setUserEvents(int nb){userEvents=nb;}

   bool getUser(){return user;}
   void setUser(bool u) {user=u;}



   Users();
   Users( string userEmail,string userPassword, int userEvents,bool user );
   Users(const Users& u);
   Users& operator=(const Users& u);
   bool operator==(const Users& u ){

        if( this->userEmail==u.userEmail && this->userEvents==u.userEvents && this->user==u.user  )
            return true;
          return false;}
    bool operator<(const Users& u) const
     {
      if(this->userEvents<u.userEvents)
            return true;
        return false;
    }


   friend ostream& operator<<(ostream& out, const Users& u);
   friend istream& operator>>(istream& in, Users& u);

   const Users&operator++(){this->userEvents++; return *this;}
   const Users operator++(int){Users aux(*this); this->userEvents++; return aux;}

   void crateaccount();
   void login();
   void uitatparola();
   ~Users() {};
   };
int Users::contorId=20000;
ostream& operator<<(ostream& out, const Users& u)
{
    out<<"\nId-ul user: "<< u.userId;
    out<<"\nEmail user: "<<u.userEmail;
    out<<"\nNumarul de evenimete ale userului: "<<u.userEvents;
    out<<"\nEste user fidel [0-nu / 1-da] : "<<u.user;
    return out;
}
istream& operator>>(istream& in, Users& u)
{
    cout<<"\n\nIntroduceti:";
    cout<<"\nEmail user: "; in>>u.userEmail;
    cout<<"\nParola user: "; in>>u.userPassword;
    cout<<"\nNumar de evenimente: ";in>>u.userEvents;
    cout<<"\nClient fidel: "; in>>u.user;
    return in;
}
Users::Users():userId(contorId++)
{
    this->userEmail="NoEmail";
    this->userPassword="NoPassword";
    this->userEvents=0;
    this->user=false;
}
Users::Users(const Users& u):userId(contorId++)
{
     this->userEmail=u.userEmail;
     this->userPassword=u.userPassword;
     this->userEvents=u.userEvents;
     this->user=u.user;
}

Users::Users(string userEmail,string userPassword,int userEvents,bool user):userId(contorId++)
{

    this->userEmail=userEmail;
    this->userPassword=userPassword;
    this->userEvents=userEvents;
    this->user=user;
}

Users& Users:: operator=(const Users& u)
{
    if(this!=&u)
    {
     this->userEmail=u.userEmail;
     this->userPassword=u.userPassword;
     this->userEvents=u.userEvents;
     this->user=u.user;

    }
    return *this;
}

void Users::crateaccount ()
{
    cout<<"\n\nIntroduceti:";
    cout<<"\nEmail user: "; cin>>userEmail;

    ofstream fout("d:poo\\"+userEmail+".txt");

    cout<<"\nParola user: "; cin>>userPassword;
    cout<<"\nNumarul de evenimete ale userului: "; cin>>userEvents;
    cout<<"\nEste user fidel [0-nu / 1-da] : "; cin>>user;
    fout<<userEmail<<endl;
    fout<<userPassword;

}


void Users::login()
{

	string username, password, un, pw;

	cout << "Enter Username: ";
	cin >> username;
	cout << "Enter Password: ";
	cin >> password;

	ifstream read("d:poo\\"+username+".txt");
	getline(read, un);
	getline(read, pw);

	if (un == username && pw == password)
		cout << "Successfully logged in!";
	else
        {cout << "False login!";
         cout<<"Ai uitat parola ? 1.Da 2.Nu";
         int i; cin>>i;
         if(i==1) {uitatparola();}
        }


    }


void Users::uitatparola()
{
     ofstream fout("useracc.out");
    string mail,npassword1, npassword2;
    cout<<"Introduceti email:"; cin>>mail;
    if(mail==this->userEmail)
         {cout<<"Introduceti parola noua: "; cin>>npassword1;
          cout<<"Reintroduceti parola noua: "; cin>>npassword2;
          if(npassword1==npassword2) this->userPassword=npassword1;
          fout<<userEmail<<endl;
          fout<<userPassword;}
    else cout<<"ai introdus o adersa de email gresita";


}

//////////////////////////////////////////////////////////////////////////////////////////////////////////

class Admin:public Desc
{ protected:

    string adminName;
    string adminEmail;
    string adminPassword;
    set<Users> uSet;
    int nbOfUsers;
  public:
    static int contorId;

  string getAdminName(){return adminName;}
  void setAdminName(string name) { adminName=name;}

  string getAdminEmail(){return adminEmail;}
  void setAdminEmail(string email){adminEmail=email;}

  string getAdminPassword() {return adminPassword;}
  void setAdminPassword(string password){adminPassword=password;}

  set<Users> getuSet(){return uSet;}
  void setAuSet(set<Users> u){uSet=u;}

  int getNbOfUsers() {return nbOfUsers;}
  void setNbOfUsers(int nb){nbOfUsers=nb;}

  Admin();
  Admin(string adminName, string adminEmail,string adminPassword, int nBOfUsers,Users* uVec);
  Admin(string adminName, string adminEmail,string adminPassword);
  Admin(const Admin& ad);
  Admin& operator=(const Admin& ad);
  void login();

    void descjob()
   {
       cout<<"\nDescrierea jobului";
       cout<<"\nAdminul  "<<adminName<<" poate administra organizatorii,userii angajatii ";

        if(nbOfUsers==0)
         cout<<"\nAdminul nu are utilizatori subordonati ";
         else
         {
                 cout<<"\nAdminul administreaza acum"<<nbOfUsers<<" useri ";

   }
   }


   virtual ostream& AfisareVirtuala(ostream& out) const;
   virtual istream& CitireVirtuala (istream& in);

  friend ostream& operator<<(ostream& out, const Admin& ad);
  friend istream& operator>>(istream& in, Admin& ad);

  ~Admin(){};
};


Admin::Admin()
{
    this->adminName="NoName";
    this->adminEmail="NoEmail";
    this->adminPassword="NoPassword";
    //this->uVec=NULL;
    this->nbOfUsers=0;
}
Admin::Admin(const Admin& ad)
{
  this->adminName=ad.adminName;
  this->adminEmail=ad.adminEmail;
  this->adminPassword=ad.adminPassword;
  this->nbOfUsers=ad.nbOfUsers;
  this->uSet=ad.uSet;

}

Admin::Admin(string adminName, string adminEmail,string adminPassword)
{
  this->adminName=adminName;
  this->adminEmail=adminEmail;
  this->adminPassword=adminPassword;
  this->nbOfUsers=this->uSet.size();
}



Admin& Admin:: operator=(const Admin& ad)
{
    if(this!=&ad)
     { this->adminName=ad.adminName;
       this->adminEmail=ad.adminEmail;
       this->adminPassword=ad.adminPassword;
       this->uSet=ad.uSet;}
       return *this;
}

ostream& Admin::AfisareVirtuala (ostream& out) const{
     out<<"\nNumele: "<<adminName;
    out<<"\nEmailul: "<<adminEmail;


    return out;
}


ostream& operator<<(ostream& out, const Admin& ad)
{

    return ad.AfisareVirtuala(out);
}
istream& Admin::CitireVirtuala(istream& in)
{
     Users user;
    cout<<"\nIntroduceti:";
    cout<<"\nNumele : "; in>>adminName;
    cout<<"\nEmailul : "; in>>adminEmail;
    cout<<"\nParola : "; in>>adminPassword;
    cout<<"\nNumarul de utilizatori: ";in>>nbOfUsers;
    if(nbOfUsers!=0)
    {  cout<<"\nIntroduceti utilizatorii: ";
        for(int i=0; i<nbOfUsers;i++)
            cin>>user;
             uSet.insert(user);

    }
    return in;
}
istream& operator>>(istream& in, Admin& ad)
{

return ad.CitireVirtuala(in);
};
void Admin::login()
{

	string username, password, un, pw;

	cout << "Enter Username: ";
	cin >> username;
	cout << "Enter Password: ";
	cin >> password;

	ifstream read("d:poo\\admin.txt");
	getline(read, un);
	getline(read, pw);

	if (un == username && pw == password)
		cout << "Successfully logged in!";
	else
        cout << "False login!";
        }


///////////////////////////////////////////////////////////////////////////////////////////////////////
//Derivata
class Organizer:public Admin
{
    private:
    int nbRoles;
    string* manage;
    public :
    string* getManage() {return manage;}
    void setManage(string* nmanage ,int nbroles)
    {
        if(manage!=NULL)
            delete[] manage;
        manage=new string[nbroles+1];
        for(int i=0; i<nbroles;i++)
            manage[i]=nmanage[i];
    }


     Organizer():Admin()
     {
         this->nbRoles=0;
         this->manage=NULL;
     }
     Organizer(string adminName, string adminEmail,string adminPassword, int nbRoles,string* manage ):Admin(adminName,adminEmail,adminPassword)
     {
         this->nbRoles=nbRoles;
         this->manage=new string [nbRoles];
         for(int i=0 ; i<nbRoles; i++)
            this->manage[i]=manage[i];
     }
    Organizer(const Organizer& ad):Admin(ad)
    {
         this->nbRoles=ad.nbRoles;
         this->manage=new string [ad.nbRoles];
         for(int i=0 ; i<ad.nbRoles; i++)
            this->manage[i]=ad.manage[i];
    }


    Organizer& operator=(const Organizer& ad)
    {
        if(this!=&ad)
        {   if(this->manage!=NULL)  delete[] this->manage;

            Admin::operator=(ad);
            this->nbRoles=ad.nbRoles;
            this->manage=new string [ad.nbRoles];
            for(int i=0 ; i<ad.nbRoles; i++)
               this->manage[i]=ad.manage[i];}
            return *this;}

      void descjob()
   {
       cout<<"\nDescrierea jobului";
       cout<<"\nOrganizatorul "<<adminName<<" se ocupa de administrarea evenimentului ";
       cout<<"\nEl se ocupa de : ";
        for(int i=0 ; i<nbRoles; i++)
             cout<<i+1<<" "<<manage[i];


   }

    virtual ostream& AfisareVirtuala(ostream& out)const
    {
        Admin::AfisareVirtuala(out);
        out<<"\nNumarul de atrubutii ale organizatorului: "<<nbRoles;
        out<<"\nAtributiile: ";
        for(int i=0 ; i<nbRoles; i++)
             out<<manage[i];
        return out;

    }
    virtual istream& CitireVirtuala (istream& in)
    {
        Admin::CitireVirtuala(in);
         cout<<"\nNumarul de atrubutii ale organizatorului: "; in>>nbRoles;
        manage=new string [nbRoles];
        cout<<"\nAtributiile: ";
        for(int i=0 ; i<nbRoles; i++)
            {cout<<"\nAtributia"<<i+1<<" ";in>>manage[i];}

        return in;
    }


    ~Organizer( ){ if(this->manage!=NULL)  delete[] this->manage; }

    void DeleteRole()
    {
        string atrib;
        cout<<"\nIntroduceti ce atributie doriti sa stergeti: "; cin>>atrib;
        for(int i=0;i<this->nbRoles;i++)
            if(this->manage[i]==atrib)
                    {for(int j=i;j<this->nbRoles-1;j++)
                     manage[j]=manage[j+1]; this->nbRoles=this->nbRoles-1;}
        cout<<"\nAtributiile ramase: ";
         for(int i=0 ; i<this->nbRoles; i++)
             cout<<"\n"<<this->manage[i];


    }
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//Derivata
class Employess:public Admin
 {
 private:
    string emplRole;
 public:
    string getEmplRole(){return emplRole ;}
    void setEmplRole(string nEmplRole) {emplRole=nEmplRole;}
    Employess():Admin()
    {
        emplRole='non';
    }

    Employess(string adminName, string adminEmail,string adminPassword,string emplRole):Admin(adminName,adminEmail,adminPassword)
    {

         this->emplRole=emplRole;
    }

     Employess(const Employess& ad):Admin(ad)
    {
         this->emplRole=ad.emplRole;
    }

    Employess& operator=(const Employess& ad)
    {
        if(this!=&ad)
        {
            Admin::operator=(ad);
            this->emplRole=ad.emplRole;
            return *this;

        }}

    virtual ostream& AfisareVirtuala(ostream& out)const
    {
        Admin::AfisareVirtuala(out);
        out<<"\nRolul angajatului: "<<emplRole;
        return out;

    }
    virtual istream& CitireVirtuala (istream& in)
    {
        Admin::CitireVirtuala(in);
         cout<<"\nRolul angajatului: "; in>>emplRole;
        return in;
    }



     void descjob()
   {
       cout<<"\nDescrierea jobului";
       cout<<"\nAngajatul "<<adminName<<"   are rolul de "<<emplRole <<" in organizarea evenimentelor:  ";

   }
 /*  friend ostream& operator<<(ostream& out, const Employess& ad)
    {

        out<<"\nNumele angajatului: "<<ad.adminName;
        out<<"\nEmailul angajatului: "<<ad.adminEmail;
        out<<"\nRolul angajatului: "<<ad.emplRole;
        return out;
    }

    friend istream& operator>>(istream& in,  Employess& ad)
    {
        cout<<"\nIntroduceti:";
        cout<<"\nNumele angajatului: "; in>>ad.adminName;
        cout<<"\nEmailul angajatului: "; in>>ad.adminEmail;
        cout<<"\nParola angajatului: "; in>>ad.adminPassword;
        cout<<"\nRolul angajatului: "; in>>ad.emplRole;
        return in;
    }*/
  ~Employess() {};
 };

////////////////////////////////////////////////////////////////////////////////////////////////////

class Agenda:public Booking
 { private:
     int days[13][32];
     const int year;
   public:
    static int contor;
    Agenda();
    Agenda(int day ,int month );
    Agenda(const Agenda& ag);
    Agenda& operator=(const Agenda& ag);

    void setDays(int day, int month) {this->days[month][day]++;}

    virtual ostream& AfisareVirtuala(ostream& out) const;
    virtual istream& CitireVirtuala (istream& in);

    bool operator>=(const Agenda& ag){
      int s1=0,s2=0;
      for (int i=1;i<=12;i++)
          for (int j=1;j<=31;j++)
          {
              s1=s1+this->days[i][j];
              s2=s1+ag.days[i][j];

          }
        if(s1>=s2)
            return true;
        return false;}

  const int getYear(){return this->year;}
  void ocupat();
  void addBooking()
  {
      int dd , mm;
      cout<<"\nIntroduceti numarul de rezervari dorite ";
      cin>>this->nb;
       cout<<this->nb;

      bool ok=0;
      for ( int i=0;i<this->nb;i++)
      { cout<<"\nRezervarea nr: "<<i+1;
        ok = 0;
       while(ok!=1)
       {
          cout<<"\nIntroduceti data pentru rezervare ";
          cout<<"\n ziua "; cin>>dd;
          cout<<"\n luna "; cin>>mm;
          if(this->days[mm][dd]!=0)
            {cout<<"\nData nu este dispnibila ";
             ok=0;}
             else {cout<<"\nData este disponibila "; this->days[mm][dd]++; ok=1;}}}

  }
    ~Agenda(){};
};
int Agenda::contor=2021;
Agenda::Agenda():year(contor++)
{
    for(int i=0;i<=12;i++)
        for(int j=0;j<=31;j++)
            if(i==0 ) this->days[i][j]=j;
               else if(j==0) this->days[i][j]=i;
                       else  this->days[i][j]=0;
    }
Agenda::Agenda(int day , int month ):year(contor++)
   {
    for(int i=0;i<=12;i++)
        for(int j=0;j<=31;j++)
                this->days[i][j]=0;
      this->days[month][day]++;
        };

Agenda::Agenda (const Agenda& ag):year(contor)
{
          for(int i=0;i<=12;i++)
             for(int j=0;j<=31;j++)
                this->days[i][j]=ag.days[i][j];
}

Agenda& Agenda:: operator=(const Agenda& ag)
{
  if(this!=&ag)
  {
      for(int i=0;i<=12;i++)
             for(int j=0;j<=31;j++)
                this->days[i][j]=ag.days[i][j];
  }

    return *this;
}

ostream& Agenda::AfisareVirtuala (ostream& out) const{
     Booking::AfisareVirtuala(out);
     out<<"\nANUL : " <<year;
     out<<endl;
     for(int i=0;i<=12;i++)
        {
          for(int j=0;j<=31;j++)

            out<<days[i][j]<<"  ";
            out<<endl;}
            return out;}

istream& Agenda::CitireVirtuala(istream& in){
    Booking::CitireVirtuala(in);
    for(int i=0;i<nb;i++)
    {
    cout<<"\nIntroduceti: ";
    int day, month;
    cout<<"\nZiua si Luna : "; in>>day>>month;
    days[month][day]++;}
    return in;

}

void Agenda::ocupat()
{
    int s=0;
    for (int i=1;i<=12;i++)
          for (int j=1;j<=31;j++)
             if(this->days[i][j]!=0)
              s++;
    cout<<"\nanul"<<this->year<<" este ocupat "<<s<<" zile"<<endl;
    cout<<"anul"<<this->year<<" este ocupat  in proportie de "<<(31*12)*s/100 <<"%"<<endl;


}

void createVec(vector<Event>& newVec)
{
 int eSize;
 cout<<"Introduceti numarul de evenimente: ";
 cin>>eSize;
 for(int i=0;i<eSize;i++)
  {
    Event newEvent;
    cin>>newEvent;
    newVec.push_back(newEvent);}


}

void printVec(vector<Event>& newVec)
{
    int vecSize=newVec.size();
    for(int i=0;i<vecSize;i++)
    {
        cout<<newVec[i];
    }
}

void resEvent(vector<Event> eVec)
{
  cout<<"\nIntroduceti data evenimentului cautat: ";
  int day; cout<<"\nzi "; cin>>day;
  string month; cout<<"\nluna ";cin>>month;
  int year; cout<<"\nan ";cin>>year;
  bool exista =0;
  int vecSize=eVec.size();
  for(int i=0;i<vecSize;i++)
    if(eVec[i].getDayOfEvent()==day and eVec[i].getMonthEvent()==month and eVec[i].getYear()==year)
       {   cout<<"Tipul evenimentului: "<<eVec[i].getEventType()<<endl;
           cout<<"Evenimentul costa "<<eVec[i].getTotalCost()<<endl;
           cout<<"Resursele necesare sunt: "<<endl;
           string* res=eVec[i].getResources();
            for(int j=0;j<eVec[i].getNbOfResouces();i++)
                  cout<<j<<" "<<res[i]<<endl;
            exista=1;}


   if(exista==0) cout<<"nu exista evenimente in data respectiva" ;

}



//////////////////////////////////////////////////////////////////////

class MeniuInteractiv{
private:
    static MeniuInteractiv *obiect;
    string data;

    MeniuInteractiv(){
        data="dd/mm/yyyy";
    }
public:
    static MeniuInteractiv* getInstance(){
        if(!obiect)
            obiect=new MeniuInteractiv();


        return obiect;
    }

    string getData(){return this->data;}
    void setData(string a) {this->data=a;}

    void meniu(){

    set<Users> u;
    set<Users>::iterator itr;
    vector<Event> eVec;
    Users u1;
    Agenda a;
    Event e;
    Admin AdminP("Maria Stoica","admin","123");
    map<string,Users> u3;
    map<string,Users>::iterator it3;

    string email;
    list<Admin> listaAdmini;
    list<Admin>::iterator it;


    int k;

    for(;;)
    { k=1;


    cout<<"\n Sunteti .... 1.User .......2. Admin";
    cout<<"\n Apasa 3.Stop ";
    int j;
    cin>>j;
    switch(j){
       case 1:{

        while(k==1){
                cout<<"\n1 Creare cont User ";
                cout<<"\n2 Autentificare User ";
                cout<<"\n3 Rezervare zile (fara adaugare de eveniment)";
                cout<<"\n4 Adauga evenimente";
                cout<<"\n5 Afisare evenimente ";
                cout<<"\n6 Cauta evenimente ";
                cout<<"\n7 Stop ";

        int comanda;
        cin>> comanda;


        switch(comanda){

            case 1:{
                u1.crateaccount();
                u.insert(u1);
                AdminP.setNbOfUsers(u.size());
                AdminP.setAuSet(u);

                email=u1.getUserEmail();
                u3.insert(pair<string,Users>(email,u1));

                break;}


            case 2:{
                u1.login();
                break;
            }


            case 3:{
                 a.addBooking();
                 cout<<a;
                 break;

              }

            case 7:{


                k=0;
                break;



            }
            case 4:{
                  if(eVec.empty()==true)
                      createVec(eVec);
                 else
                     {cin>>e;
                      eVec.insert(eVec.begin(),e);}
                break; }

            case 5:{
                  if(eVec.empty()==true)
                    cout<<"Nu sunt evenimente";
                else printVec(eVec);
                break;}

            case 6:{
                  if(eVec.empty()==true)
                    cout<<"Nu sunt evenimente";
                else resEvent(eVec);
                break;}





        }}
      }



   case 2:{
           while(k==1){

        cout<<"\n1 Admin autentificare";
        cout<<"\n2 Admin(afisare date // este un singur admin prestabilit)";
        cout<<"\n3  Adauga Angajat ";
        cout<<"\n4  Adauga Organizator ";
        cout<<"\n5 Afisare ";
        cout<<"\n6 Afiseaza agenda  ";
        cout<<"\n8 Afisare  useri ";
        cout<<"\n9 Sterge user (map) ";
        cout<<"\n7 Stop \n";


        int comanda;
        cin>> comanda;


        switch(comanda){

            case 1:{


                  AdminP.login();
                   break;

            }

            case 2:{

               cout<<AdminP;
                break;



            }
            case 3:{
                  Employess emp;
                cout<<"la numarul de utilizatori se va adauga 0 ";
                cin>>emp;
                 listaAdmini.push_front(emp);
                 emp.descjob();

                break;

            }

            case 4:{
                Organizer org;
                cout<<"la numarul de utilizatori se va adauga 0 ";
                cin>>org;
                listaAdmini.push_front(org);
                org.descjob();
                break;

            }

            case 7:{

                k=0;
                break;
               }


         case 5:{

             for(it=listaAdmini.begin();it!=listaAdmini.end();it++)
              {
                    cout <<  *it << " ";
                 }
                  cout << "\n";}

         case 6:{
                cout<<a;}

        case 8:{

            // afisare cu set
/*            for (itr = u.begin(); itr != u.end(); itr++)
    {
        cout << *itr<<" ";
    }
    cout << endl;
        }*/
        //afisare cu map ;


         case 9:{
             cout<<"\nafisare inainte de stergere ";
             for (it3 = u3.begin(); it3 != u3.end(); it3++)
    {
        cout <<it3->first<<" ";
         cout <<it3->second<<" ";
    }
    cout << endl;
        }
                cout<<"\n Itroduceti email ";
                cin>>email;
                u3.erase(email);

               cout<<"\nafisare dupa stergere ";
          for (it3 = u3.begin(); it3 != u3.end(); it3++)
    {
        cout <<it3->first<<" ";
         cout <<it3->second<<" ";
    }
    cout << endl;
        }
                break;
               }

    }}}

 if (j==3) break;}
}};
MeniuInteractiv* MeniuInteractiv::obiect=0;

int main()
{

MeniuInteractiv *meniulMeu=meniulMeu->getInstance();
    meniulMeu->setData("5.09.2021");
    meniulMeu->meniu();
    return 0;
}




