TStringList* Convert1(TStringList* wejscie,String wskaznik){
int a=0,b=0;
TStringList *baza = new TStringList;
for(int i=0; i<wejscie->Count; i++){
        String zmienna; zmienna=wejscie->Strings[i];
        if(zmienna=="\t<"+wskaznik+">" || zmienna=="<"+wskaznik+">" ){
                a=i;
                }
        else if(zmienna=="\t</"+wskaznik+">" || zmienna=="</"+wskaznik+">" ){
                b=i;
                }
        }
for(int i=a+1;i<b;i++){baza->Add(wejscie->Strings[i]);}

return baza;
}
// Route
void FillVectors(TStringList *wejscie,std::vector<double> *end, std::vector<double> *begin, std::vector<int> *speed, std::vector<bool> *spot){
        double Start=0;
        int Speed=0;
        int id,l1=0,l2=0;
        //int Control=0;
        for(int i=0; i<wejscie->Count; i++){
                String zmienna = wejscie->Strings[i];
                int p=0,k=0;
                //looking for <section id="x">
                for(int j=0; j<40; j++){
                        if(zmienna.SubString(j,13)=="<section id=\""){

                                p=j+13;

                        }
                        else if(zmienna.SubString(j,2)=="\">"){
                                 k=j;


                        }
                        if(p!=0 && k!=0){
                                 id = atoi(zmienna.SubString(p,k-p).c_str());
                                 l1=i;
                                 break;
                        }
                }
                //looking for </section>
                for(int j=0; j<40; j++){
                        if(zmienna.SubString(j,10)=="</section>"){
                        l2=i;
                        break;
                        }
                }
                // reading data beetween <section ... > and </section>
                int Control=0;
                if(l2>l1){
                        String zmienna1;
                        Control=0;
                        for(int j=l1+1; j<l2; j++){
                                int p1=0,p2=0,p3=0,p4=0;
                                zmienna1 = wejscie -> Strings[j];
                                //looking data between <end> and </end>
                                for(int k=0;k<40;k++){
                                        if(zmienna1.SubString(k,5)=="<end>"){
                                                 p1=k+5;
                                        }
                                        else if(zmienna1.SubString(k,6)=="</end>"){
                                                 p2=k;
                                                 break;
                                        }
                                }
                                if(p2>p1){
                                begin -> insert(begin -> begin() + id,Start);
                                Start = atof(zmienna1.SubString(p1,p2-p1).c_str());
                                end -> insert(end -> begin() + id, Start);
                                }
                                  //looking data between <speed> and </speed>
                                for(int k=0;k<40;k++){
                                        if(zmienna1.SubString(k,7)=="<speed>"){
                                                 p3=k+7;
                                        }
                                        else if(zmienna1.SubString(k,8)=="</speed>"){
                                                 p4=k;
                                                 break;
                                        }
                                }
                                if(p4>p3){
                                Speed = atof(zmienna1.SubString(p3,p4-p3).c_str());
                                speed -> insert(speed -> begin() + id, Speed);
                                }
                                // looking for <spot>
                                for(int k=0;k<40;k++){
                                        if(zmienna1.SubString(k,14)=="<spot>1</spot>"){
                                          Control=1;
                                        }
                                }
                        }
                        if (Control==1){
                                spot -> insert(spot ->begin() + id, 1);
                        }
                        else {
                                spot -> insert(spot ->begin() + id, 0);
                        }
                }
        }
}



void FillDescriptions(TStringList *t, std::vector<String> *a, std::vector<double> *b){
        int p1,p2,p3,p4;
        for(int i=0;i<t->Count;i++){
                String zmienna; zmienna = t->Strings[i];
                for(int j=0;j<20;j++){
                        if(zmienna.SubString(j,13)=="<point place="){
                                p1=j+13;
                                for(int k=j+13;k<60;k++){
                                        if(zmienna.SubString(k,1)=="\""){
                                                p2=k;
                                                }
                                        else if(zmienna.SubString(k,1)==">"){
                                                p3=k;
                                                }
                                        else if(zmienna.SubString(k,2)=="</"){
                                                p4=k;
                                                break;
                                                }
                                        else if (zmienna.SubString(k,2)=="\0"){

                                                break;
                                                }
                                        }
                                 a->push_back(zmienna.SubString(p3+1,p4-p3-1));
                                 b->push_back(atof(zmienna.SubString(p1+1,p2-p1-1).c_str()));
                                 break;
                                }

                }

}
}

Route::Route(TStringList *wejscie,bool empty){
        begin = new std::vector<double>;
        end = new std::vector<double>;
        speed = new std::vector<int>;
        spot = new std::vector<bool>;
        description = new std::vector<String>;
        points = new std::vector<double>;
        if(empty==0)
        {
                TStringList *predkosci, *opisy;
                predkosci=Convert1(wejscie,"line");
                opisy=Convert1(wejscie,"description");
               // TStringList *opis=Convert1(wejscie,"description");
                FillVectors(predkosci,end,begin,speed,spot);
                FillDescriptions(opisy,description,points);
        }
        else
        {
        begin -> push_back(0);
        end -> push_back(200);
        speed -> push_back(40);
        spot -> push_back(0);
        description -> push_back("Start");
        points -> push_back(0);
        description -> push_back("End");
        points -> push_back(end->back());
        }
}

Route::~Route(){
begin -> erase (begin->begin(), begin->end());
end -> erase (end -> begin(), end -> end());
speed -> erase (speed -> begin(), speed ->end());
spot -> erase (spot -> begin(), spot ->end());
description -> erase (description -> begin(), description ->end());
points -> erase (points -> begin(), points ->end());


}

void Route::DeleteSection(){
begin->pop_back();
end->pop_back();
speed->pop_back();
spot->pop_back();

}

void Route::AddSection(double a,double b,int c,bool d){
begin->push_back(a);
end->push_back(b);
speed->push_back(c);
spot->push_back(d);

}

double Route::ShowLength()const{
        if(end->empty()!=1)
                {
                double a = end->back();
                return a;
                }
        else    {
                return 0;
                }
}

int Route::Size(){
int a,b,c;
a=begin->size();
b=end->size();
c=speed->size();
if(a==b && b==c){
return a;
}
else
{
return 0;
}
}

AnsiString Route::ShowSection(int i){
        if(spot->at(i)==0){
                return "od " + CurrToStr(begin->at(i))+"m do "+CurrToStr(end->at(i))+"m, V="+CurrToStr(speed->at(i))+" km/h";}
        else{
                return "od " + CurrToStr(begin->at(i))+"m do "+CurrToStr(end->at(i))+"m, V="+CurrToStr(speed->at(i))+" km/h, ogr. punktowe.";
        }
}

AnsiString Route::ShowStart(int i){
      return CurrToStr(begin->at(i));
}

AnsiString Route::ShowEnd(int i){
      return CurrToStr(end->at(i));
}

AnsiString Route::ShowSpeed(int i){
      return CurrToStr(speed->at(i));
}

bool Route::ShowSpot(int i){
      return spot->at(i);
}
int Route::FindSection(int meters){
        int i=0;
    for(;i<Size();i++){
    if(meters>=begin->at(i) && meters<end->at(i)){break;}
    }
        return i;

}

void Route::ChangeSection(bool del, int i, double start, double ends, int speeds, bool spots){
       if(del==1){
                //delete of section
                if(i>0){
                        if(i<Size()-1){
                                end->at(i-1) = end->at(i);
                                begin -> erase(begin->begin()+i);
                                end -> erase(end->begin()+i);
                                speed -> erase(speed->begin()+i);
                                spot -> erase(spot->begin()+i);
                        }
                        if(i==Size()-1){
                                begin -> erase(begin->begin()+i);
                                end -> erase(end->begin()+i);
                                speed -> erase(speed->begin()+i);
                                spot -> erase(spot->begin()+i);
                        }
                }
                else if(i==0){
                Application->MessageBoxA("Nie mo¿na usun¹c pierwszego odcinka","B³¹d",MB_ICONWARNING);

                }
       }
        else if(del==0){
                if(i==-1){
                        bool check=0;
                        int nr=0;
                        for(;nr<Size();nr++){
                                if(start>=begin->at(nr) && start<end->at(nr)){
                                         check=1;
                                        break;
                                }
                        }
                        if(check==0){
                              //
                              if(ends > ShowLength()){
                                        begin->push_back(ShowLength());
                                        end->push_back(ends);
                                        speed->push_back(speeds);
                                        spot->push_back(spots);
                                        }
                              else {

                                Application->MessageBoxA("Niespójnosc odcinka","B³¹d",MB_ICONWARNING);
                              }
                        }
                        else {
                        if(ends<end->at(nr)){
                                int tpoint=end->at(nr);
                                end->at(nr)=start;

                                         begin->insert(begin->begin()+nr+1,start);
                                          end->insert(end->begin()+nr+1,ends);
                                          speed->insert(speed->begin()+nr+1,speeds);
                                         spot->insert(spot->begin()+nr+1,spots);


                                begin->insert(begin->begin()+nr+2,ends);
                                end->insert(end->begin()+nr+2,tpoint);
                                speed->insert(speed->begin()+nr+2,speed->at(nr));
                                spot->insert(spot->begin()+nr+2,spot->at(nr));

                        }
                        else {
                          end->at(nr)=start;
                          if (nr+1<Size()){
                                 begin->at(nr+1)=ends;
                                begin->insert(begin->begin()+nr+1,start);
                                end->insert(end->begin()+nr+1,ends);
                                speed->insert(speed->begin()+nr+1,speeds);
                                spot->insert(spot->begin()+nr+1,spots);
                          }
                                for(int j=nr+1;j<Size();j++){
                                        if(begin->at(j)!=end->at(j-1)){ begin->at(j)=end->at(j-1);}
                                        if(begin->at(j)>end->at(j)){end->at(j)=begin->at(j);}
                                }
                                for(int j=nr+1;j<Size();j++){
                                if(begin->at(j)==end->at(j)){
                                         begin -> erase(begin->begin()+j);
                                        end -> erase(end->begin()+j);
                                        speed -> erase(speed->begin()+j);
                                        spot -> erase(spot->begin()+j);
                                        j--;


                                }
                        }

                        }


                       }
                }
                else {
                        if(start<ends)
                        {
                                if(start<0){start=0;}
                                if(i>0 && i<Size()-1){

                                        end->at(i-1) = start;
                                        begin->at(i) = start;
                                        end->at(i) = ends;
                                        speed->at(i) = speeds;
                                        spot->at(i) = spots;
                                        if(i+1<Size()){
                                                begin->at(i+1) = ends;
                                        }
                        }
                        else if(i==0){
                                begin->at(i) = 0;
                                end->at(i) = ends;
                                speed->at(i) = speeds;
                                spot->at(i) = spots;
                                if(i+1<Size()){
                                         begin->at(i+1) = ends;
                                }
                        }
                        else if(i==Size()-1){
                                if(Size()>1){
                                         end->at(i-1) = start;
                                         }
                                begin->at(i) = start;
                                end->at(i) = ends;
                                speed->at(i) = speeds;
                                spot->at(i) = spots;
                        }
                        for(int j=0;j<Size();j++){
                                if(begin->at(j)> end->at(j)){
                                        if(j<i){begin->at(j)=end->at(j);}
                                        else if(j>i){end->at(j)=begin->at(j);};
                                }

                         }

                        for(int j=i-1;j>=0;j--){
                                if(end->at(j)!=begin->at(j+1)){ end->at(j)=begin->at(j+1);}
                                if(begin->at(j)>end->at(j)){ begin->at(j)=end->at(j);}
                        }
                        for(int j=i+1;j<Size();j++){
                                if(begin->at(j)!=end->at(j-1)){ begin->at(j)=end->at(j-1);}
                                if(begin->at(j)>end->at(j)){end->at(j)=begin->at(j);}
                        }
                        for(int j=i+1;j<Size();j++){
                                if(begin->at(j)==end->at(j)){
                                         begin -> erase(begin->begin()+j);
                                        end -> erase(end->begin()+j);
                                        speed -> erase(speed->begin()+j);
                                        spot -> erase(spot->begin()+j);
                                        j--;


                                }
                        }
                        for(int j=i-1;j>=0;j--){
                                if(begin->at(j)==end->at(j)){
                                begin -> erase(begin->begin()+j);
                                end -> erase(end->begin()+j);
                                speed -> erase(speed->begin()+j);
                                spot -> erase(spot->begin()+j);
                                }
                        }
                }

        else
        {
        Application->MessageBoxA("Wartosc startowa musi byc wieksza od koncowej","B³¹d!", MB_ICONWARNING);
        }
       }
   }
}


AnsiString Route::ShowDescribe(int i){

return CurrToStr(points->at(i)) +" - " +(description->at(i));
}

int Route::DescribeLocation(int i){

        return points->at(i);
}


void Route::AddDescribe(double a, String b){
        int i=0;
        bool c=1;
        while(i<DescriptionCount())
        {
                if(a==points->at(i)){
                c=0;
                break;
                }
                if(i==0 && a<points->at(i)){
                        break;
                }
                if(i==DescriptionCount()-1){
                       i=i+1;
                        break;
                }
                if(i<DescriptionCount()-1 && a>points->at(i) && a<points->at(i+1)){
                        i=i+1;
                        break;
                }
                i++;

        }
        if(c==0 && a>0 && a<ShowLength()){
             ShowMessage("Nie mozesz dodac infopointu w istniejacym punkcie: "+CurrToStr(a)+" m.");
        }
        else {
        points->insert(points->begin()+i,a);
        description->insert(description->begin()+i,b);
        }

}

void Route::DeleteDescribe(int i){
        /*
        if(i==0)
        {
        Application->MessageBoxA("Nie mozna usunac punktu start.","B³¹d!",MB_ICONWARNING);

        }
        else if(points->begin()+i==points->end()-1)
        {
           Application->MessageBoxA("Nie mozna usunac punktu koniec.","B³¹d!",MB_ICONWARNING);
        }
        */
        if(i==-1)
        {
                points -> pop_back();
                description -> pop_back();
        }
        else
        {
        points -> erase((points->begin())+i);
        description -> erase((description->begin())+i);
        }
}

void Route::DeleteDescribes(int point){
        std::vector<double>::iterator it= points->end()-1;
        std::vector<AnsiString>::iterator it2 = description->end()-1;
        int i=0;
        while(it!=points->begin() || it2!=description->begin()){
                int a = *it;
                AnsiString b = *it2;
                if(a>=point)
                {
               // ShowMessage(CurrToStr(a)+"-"+b);
                points->erase(it);
                description->erase(it2);
                }
        it--;
        it2--;
        }



}


int Route::DescriptionCount(){
int a = points -> size();
int b = description -> size();
if(a==b){
return a;
}
else
{
return 0;
}
}

TStringList* Route::SaveToFile(){
        TStringList *wynik = new TStringList;
        wynik -> Add("<?xml version=\"1.0\" encoding=\"UTF-8\"?>");
        wynik -> Add ("<route>");
        wynik -> Add ("\t<line>");
        for(int i=0;i<Size();i++){
                wynik->Add("\t\t<section id=\""+CurrToStr(i)+"\">");
                wynik->Add("\t\t\t<end>"+CurrToStr(end->at(i))+"</end>");
                wynik->Add("\t\t\t<speed>"+CurrToStr(speed->at(i))+"</speed>");
                if(spot->at(i) == 1){
                        wynik->Add("\t\t\t<spot>1</spot>");
                }
                wynik->Add("\t\t</section>");
                }
        wynik -> Add ("\t</line>");
        wynik -> Add ("\t<description>");
        for(int i=0;i<DescriptionCount();i++){ wynik->Add("\t\t<point place=\""+CurrToStr(points->at(i))+"\">"+description->at(i)+"</point>");}
        wynik -> Add ("\t</description>");
        wynik -> Add ("</route>");
        return wynik;

}

int Route::Vmax(int PointOfTrain, int TrainLength, int TrainMaxSpeed)
{
  int i=0;
  int CurrentSpeed;
  int PreviousSpeed=500;
  if(PointOfTrain>ShowLength()-3){
                return 0;}
  else {

        for(;i<Size();i++){
                        if(PointOfTrain>=begin->at(i) && PointOfTrain<end->at(i)){
                        CurrentSpeed = speed->at(i);
                        if(i>0)
                                {
                                PreviousSpeed = speed->at(i-1);
                                }
                        break;}
                        }
        if(CurrentSpeed>PreviousSpeed && PointOfTrain<begin->at(i)+TrainLength && spot->at(i-1)==0){
                                CurrentSpeed=PreviousSpeed;
                        }

         if(TrainMaxSpeed!=0 && TrainMaxSpeed<CurrentSpeed){
         CurrentSpeed=TrainMaxSpeed;
         }
         return CurrentSpeed;
         }
}

int Route::NextSpeed(double PointOfTrain, int TrainLength, int TrainMaxSpeed)
{

  if(PointOfTrain>ShowLength()-3){
                return 0;}

  else
  {
        int CurrentSpeed = Vmax(PointOfTrain,TrainLength,TrainMaxSpeed);
        int NextSpeed = CurrentSpeed;
        while(NextSpeed>=CurrentSpeed){
         if(PointOfTrain>ShowLength()-3){
                return 0;}
        ++PointOfTrain;
        NextSpeed  = Vmax(PointOfTrain,TrainLength,TrainMaxSpeed);
        }

        return NextSpeed;
  }
}


int Route::DistanceToSpeedChange(double PointOfTrain, int TrainLength, int TrainMaxSpeed)
{
  int CurrentSpeed = Vmax(PointOfTrain,TrainLength,TrainMaxSpeed);
  int start = PointOfTrain;
  int NextSpeed=CurrentSpeed;
  if(PointOfTrain>ShowLength()-3){
                return 0;}
  else
  {
        while(NextSpeed>=CurrentSpeed){
          if(PointOfTrain>ShowLength()-3){
                return 0;}
        ++PointOfTrain;
        NextSpeed  = Vmax(PointOfTrain,TrainLength,TrainMaxSpeed);
        }
        return PointOfTrain - start;
  }
}


int Route::DistanceToVmax(double PointOfTrain, int TrainLength, int TrainMaxSpeed){
  int CurrentSpeed = Vmax(PointOfTrain,TrainLength,TrainMaxSpeed);
  int start = PointOfTrain;
  int NextSpeed=CurrentSpeed;

  if(PointOfTrain>ShowLength()-3){
                return 0;}
  else
  {
        while(NextSpeed==CurrentSpeed){
        ++PointOfTrain;
        NextSpeed  = Vmax(PointOfTrain,TrainLength,TrainMaxSpeed);
        }
        return PointOfTrain - start;
  }

}

int Route::NextVmax(double PointOfTrain, int TrainLength, int TrainMaxSpeed){
  int CurrentSpeed = Vmax(PointOfTrain,TrainLength,TrainMaxSpeed);
  int NextSpeed=CurrentSpeed;
  /*
  if (CurrentSpeed == 0)
  {
       return 0;
  }
  */
   if(PointOfTrain>ShowLength()-3){
                return 0;}
  else
  {
        while(NextSpeed==CurrentSpeed){
        ++PointOfTrain;
        NextSpeed  = Vmax(PointOfTrain,TrainLength,TrainMaxSpeed);
        }
        return NextSpeed;
  }

}

String Route::Show(int Point)
{
        String score="null";
        for(int i=0; i<DescriptionCount(); i++){
                if(Point==points->at(i)){
                score=description->at(i);
                }
        }
        return score;
}


std::map<std::pair<int,int>,int> Route::StartPoints(Train *t) const
{
        std::map<std::pair<int,int>,int> goal;
        int point = 0;
        int speed = 0;
        while(point!=ShowLength()-3){
                int point2;
                double TemporarySpeed;
                double Accelaration;
                if(speed<Vmax(point,t->TrainLength(),t->TrainMaxSpeed())){
                      point2=point-1;
                      TemporarySpeed=speed;
                       while(point2-point<20000){
                        Accelaration = t->AccValue(TemporarySpeed);
                        if(Accelaration<0.2){break;}
                        point2 = point2 + TemporarySpeed/3.6 + Accelaration/(2*3.6);
                        TemporarySpeed=TemporarySpeed + Accelaration;
                        if(point2>point && TemporarySpeed>=Vmax(point2,t->TrainLength(),t->TrainMaxSpeed())){break;}
                         }
                 std::pair<int,int> goal1(point,point2);
                goal.insert(std::pair<std::pair<int,int>,int>(goal1,speed));
               // ShowMessage(CurrToStr(point)+"\n"+CurrToStr(speed)+"\n"+CurrToStr(point2));
                }
        speed = Vmax(point,t->TrainLength(),t->TrainMaxSpeed());
        point++;
        }
        return goal;
}

Route::TheHighestSpeed(){
        std::vector<int>::iterator iterator = speed->begin();
        int goal = *iterator;
        while(iterator!=speed->end()){
                if(*iterator>goal){
                        goal=*iterator;
                }
                iterator++;
        }

return goal;

}
// Vehicle

void FillData(TStringList* data, AnsiString &name,int &wheels, double &length, double &weight, std::map<int,double> *map){
        int l1=0,l2=0;

        for(int i=0; i<data->Count; i++){
                String zmienna = data->Strings[i];
                int p1=0;
                bool n=0,n1=0,n2=0,n3=0;
                for(int j=0; j<40; j++){
                        //name
                        if(zmienna.SubString(j,6)=="<name>"){
                                p1=j+6;
                                n=1;
                        }
                        else if(zmienna.SubString(j,7)=="</name>" && n==1){
                                name = zmienna.SubString(p1,j-p1);
                        }
                        //wheels
                        if(zmienna.SubString(j,8)=="<wheels>"){
                                p1=j+8;
                                n1=1;
                        }
                        else if(zmienna.SubString(j,9)=="</wheels>" && n1==1){
                                wheels = atoi(zmienna.SubString(p1,j-p1).c_str());
                        }
                        //weight
                        if(zmienna.SubString(j,8)=="<weight>"){
                                p1=j+8;
                                n2=1;
                        }
                        else if(zmienna.SubString(j,9)=="</weight>" && n2==1){
                                weight = atof(zmienna.SubString(p1,j-p1).c_str());
                        }
                        //
                        //length
                        if(zmienna.SubString(j,8)=="<length>"){
                                p1=j+8;
                                n3=1;
                        }
                        else if(zmienna.SubString(j,9)=="</length>" && n3==1){
                                length = atof(zmienna.SubString(p1,j-p1).c_str());
                        }
                        // charectiristic
                        if(zmienna.SubString(j,16)=="<characteristic>"){
                                l1=i;
                                break;
                        }
                        else if(zmienna.SubString(j,17)=="</characteristic>"){
                                l2=i;
                                break;
                        }


                }
        }

        if(l1!=0 && l2!=0){
                TStringList *speedforces = new TStringList;
                for (int i=l1+1; i<l2; i++){
                        speedforces->Add(data->Strings[i]);
                }
                int charcount;
                std::vector <int> speeds;
                std::vector <double> forces;
                for (int i=0; i<speedforces->Count; i++){
                        String zmienna = speedforces -> Strings[i];
                        int p1=0,p2=0,p3=0;
                        bool t;
                        for(int j=0; j<50; j++){
                                //speeds
                                if(zmienna.SubString(j,11)=="<speed id=\"" ){
                                        p1=j+11;
                                        t=0;
                                }
                                else if(zmienna.SubString(j,11)=="<force id=\"" ){
                                        p1=j+11;
                                        t=1;
                                }
                                else if(zmienna.SubString(j,2)=="\">") {
                                        p2=j;
                                }
                                else if(zmienna.SubString(j,8)=="</speed>"){
                                        p3=j;
                                }
                                else if(zmienna.SubString(j,8)=="</force>"){
                                        p3=j;
                                }
                        }
                                speeds.reserve(100);
                                forces.reserve(100);
                        if(p1!=0 && p2!=0 && p3!=0){
                                  charcount = atoi(zmienna.SubString(p1,p2-p1).c_str());
                                 if(t==0){
                                        //ShowMessage("id ="+zmienna.SubString(p1,p2-p1)+" speed="+zmienna.SubString(p2+2,p3-p2-2));
                                        speeds.insert(speeds.begin()+atoi(zmienna.SubString(p1,p2-p1).c_str()),atoi(zmienna.SubString(p2+2,p3-p2-2).c_str()));
                                 }
                                 else {
                                        forces.insert(forces.begin()+atoi(zmienna.SubString(p1,p2-p1).c_str()),atof(zmienna.SubString(p2+2,p3-p2-2).c_str()));
                                        //ShowMessage("id ="+zmienna.SubString(p1,p2-p1)+" force="+zmienna.SubString(p2+2,p3-p2-2));
                                 }


                        }

                }

                         speeds.resize(charcount+1);
                         forces.resize(charcount+1);
                         for(int i=0; i<=charcount; i++){
                          map -> insert(std::pair<int,double>(speeds[i],forces[i]));

                         }




        }

}

Vehicle::Vehicle(TStringList* wejscie){
        characteristic = new std::map<int,double>;
        TStringList *data = Convert1(wejscie,"vehicle");
        FillData(data,name,wheels,length,weight, characteristic);
        String test = "";
        std::map<int,double>::iterator  iterator= characteristic->begin();
        /*
        for(;iterator!=characteristic->end(); iterator++){
        test= test + "For speed: "+CurrToStr(iterator->first)+"km/h Force is "+CurrToStr(iterator->second)+" kN \n";
        }
       ShowMessage("Name: "+name+"\n Wheels"+CurrToStr(wheels)+"\n Weight"+CurrToStr(weight)+"\n Length: "+CurrToStr(length)+"\n"+test);
       */
}

Vehicle::~Vehicle(){
        characteristic -> clear();
}

AnsiString Vehicle:: ShowName() {
        return name;
}

AnsiString Vehicle:: ShowWheels() {
        return CurrToStr(wheels);
}

AnsiString Vehicle:: ShowWeight() {
        return CurrToStr(weight);
}

AnsiString Vehicle:: ShowLength() {
        return CurrToStr(length);
}

AnsiString Vehicle::ShowChar(int i,std::map<int,double>::iterator iterator) {
iterator = characteristic -> begin();
std::advance(iterator,i);
return "F(V="+CurrToStr(iterator->first)+"km/h)="+CurrToStr(iterator->second)+"kN";

}

int Vehicle::CharSize(){
return characteristic->size();

}

void Vehicle::ChangeName(AnsiString entry){
        name = entry;
}
void Vehicle::ChangeWheels(AnsiString entry){
       wheels = atoi(entry.c_str());
}

void Vehicle::ChangeWeight(AnsiString entry){
        weight = atof(entry.c_str());
}
void Vehicle::ChangeLength(AnsiString entry){
       length = atof(entry.c_str());
}

void Vehicle::DeleteChar(int entry){
       std::map<int,double>::iterator  iterator= characteristic->begin();
       std::advance(iterator,entry);
       characteristic -> erase(iterator);
}

void Vehicle::AddChar(int Speed, double Force){
       std::map<int,double>::iterator  iterator= characteristic->find(Speed);
       if(std::distance(characteristic->begin(),iterator)<CharSize()){
                ShowMessage("Ju¿ istnieje zdefiniowana si³a dla pktu V="+CurrToStr(Speed));
       }
       else
       {
                iterator=characteristic->begin();
                int speeda=iterator->first;
                while(speeda<Speed){
                        iterator++;
                        speeda=iterator->first;
                        if(iterator == characteristic->end()){
                        break;
                        }
                };
               // ShowMessage(CurrToStr(std::distance(characteristic->begin(),iterator)));
                 characteristic -> insert(iterator,std::pair<int,double>(Speed,Force));
       }
}

double Vehicle::MaxForce(){
        double a = characteristic -> begin() -> second;
        for(std::map<int,double>::iterator  iterator=characteristic->begin();iterator!=characteristic->end();iterator++){
                double b = iterator -> second;
                if(b>a){
                        a=iterator -> second;
                }
        }
        return a;
}

int Vehicle::Vmax(){
        int a = characteristic -> begin() -> first;
        for(std::map<int,double>::iterator  iterator=characteristic->begin();iterator!=characteristic->end();iterator++){
                int b = iterator -> first;
                if(b>a){
                        a=iterator -> first;
                }
        }
        return a;
}

int Vehicle::ShowSpeed(int entry){
        std::map<int,double>::iterator  iterator=characteristic->begin();
        std::advance(iterator,entry);
        return iterator->first;
}

double Vehicle::ShowForce(int entry){
        std::map<int,double>::iterator  iterator=characteristic->begin();
        std::advance(iterator,entry);
        return iterator->second;
}

TStringList* Vehicle::SaveToFile(){
        TStringList *wynik = new TStringList;
        wynik -> Add("<?xml version=\"1.0\" encoding=\"UTF-8\"?>");
        wynik -> Add ("<vehicle>");
        wynik -> Add ("\t<name>"+name+"</name>");
        wynik -> Add ("\t<wheels>"+ShowWheels()+"</wheels>");
        wynik -> Add ("\t<weight>"+ShowWeight()+"</weight>");
        wynik -> Add ("\t<length>"+ShowLength()+"</length>");
        wynik -> Add ("\t<characteristic>");
        for(int i=0;i<CharSize();i++){
                wynik -> Add ("\t\t<speed id=\""+CurrToStr(i)+"\">"+CurrToStr(ShowSpeed(i))+"</speed>");
                wynik -> Add ("\t\t<force id=\""+CurrToStr(i)+"\">"+CurrToStr(ShowForce(i))+"</force>");
        }
        wynik -> Add ("\t</characteristic>");
        wynik -> Add ("</vehicle>");
        return wynik;
}

double Vehicle::Force(int speed){
     std::map<int,double>::iterator  iterator=characteristic->find(speed);
     if(speed>Vmax() || speed<0){ return 0; }
     else {
        if(std::distance(characteristic->begin(),iterator)!=CharSize()){
                return iterator -> second;

        }
        else
        {
                for(iterator=characteristic->begin();iterator->first<speed;iterator++){}
                double force2=iterator->second;
                int speed2=iterator->first;
                iterator--;
                double force1=iterator->second;
                int speed1=iterator->first;
                // y = ax + b
                // y1 = ax1 +b
                // y2 = ax2+ b
                // b = y1 - ax1
                // y2 = ax2 + y1 -ax1
                // y2 - y1 =  ax2 - ax1
                // (y2 - y1)/(x2-x1) = a
                // y1 - (y2 - y1)/(x2-x1)*x1 =b
                // y1 = force1
                // y2 = force2
                // x1 = speed1
                // x2 = speed2
                double a = (force2-force1)/(speed2-speed1);
                double b = force1-(force2-force1)/(speed2-speed1)*speed1;
                return a*speed+b;

        }
     }
}
double Vehicle::CountWeight(){
        return weight;
}


bool Vehicle::ReadyToGo(){
        std::map<int,double>::iterator  iterator=characteristic->find(0);
        if(Vmax()>0 && CountWeight()>0 && std::distance(characteristic->begin(),iterator)!=CharSize()){
                return 1;
        }
        else {
                return 0;
        }


}
Vehicle::Vehicle(Vehicle *V1){
        name = V1->name;
        wheels = V1->wheels;
        weight = V1->weight;
        length = V1->length;
        characteristic = V1->characteristic;
};


Train::Train(Vehicle *poj,int loc,int CarWheel ,double CarWeigh ,int CarLengt ,int PercentOfBrakingMas, int Vmax):
        Vehicle(poj)
{
        Locos = loc;
        CarWheels = CarWheel;
        CarLength = CarLengt;
        CarWeight = CarWeigh;
        PercentOfBrakingMass = PercentOfBrakingMas;
        if(Vmax>poj->Vmax()){
                MaxSpeed=poj->Vmax();
        }
        else {
                MaxSpeed=Vmax;
        }

}

int Train::TrainLength(){
        return length*Locos + CarLength;


}

int Train::TrainMaxSpeed(){
        return MaxSpeed;
}

double Train::TrainWeight(){
        return Locos*weight + CarWeight;
}

int Train::LWheels(){
       return Locos*wheels;

}
int Train::CWheels(){
      return CarWheels;

}

double Train::AccValue(int CurrentSpeed){
        double BowResistance=0; //future
        double HillResistance=0; //future;
        double VehicleForce = Locos*Force(CurrentSpeed);
       // VehicleForce[3][i]=((6.5+1.5*VehicleForce[0][i])*locoweight+(VehicleForce[0][i]/10)*(VehicleForce[0][i]/10)+150*axes)/1000+((6.5+1.5*VehicleForce[0][i]/10)*atof(masabrutto.c_str())+(VehicleForce[0][i]/10)*(VehicleForce[0][i]/10)*10*(2.5+cars)+150*axes2)/1000;
          double Resistance = ((6.5+1.5*CurrentSpeed)*weight*Locos+(CurrentSpeed/10)*(CurrentSpeed/10)+150*wheels)/1000+((6.5+1.5*CurrentSpeed/10)*CarWeight+(CurrentSpeed/10)*(CurrentSpeed/10)*10*(2.5+(CarWheels)/4)+150*CarWheels)/1000;
        return 3.6*(VehicleForce -(Resistance))/TrainWeight();
        //
         }



int Train::AccSpeed(int PointOfTrain,int StartPoint, int StartSpeed){
        double TemporarySpeed = StartSpeed;
        while(StartPoint<PointOfTrain){
                double Accelaration = AccValue(TemporarySpeed);
                if(Accelaration<0.2){
                break;
                }
                StartPoint = StartPoint + TemporarySpeed/3.6 + Accelaration/(2*3.6);
                TemporarySpeed=TemporarySpeed + AccValue(TemporarySpeed);
               // ShowMessage(CurrToStr(StartSpeed)+"\n"+CurrToStr(EndSpeed)+"\n"+CurrToStr(TemporarySpeed)+"\n"+CurrToStr(Distance)+"\n"+CurrToStr( AccValue(TemporarySpeed)));
        }

        return TemporarySpeed;



}

std::map<std::pair<int,int>,std::pair<int,int> > Train::AccSpeeds(Route *line){
        std::map<std::pair<int,int>,std::pair<int,int> > goal;
        int point = 0;
        int speed = 0;
        while(point!=line->ShowLength()-3){
                int point2;
                int point3;
                double TemporarySpeed;
                double Accelaration;
                if(speed<line->Vmax(point,TrainLength(),TrainMaxSpeed())){
                      point2=point-1;
                      point3=point2+1;
                      while(line->Vmax(point3,TrainLength(),TrainMaxSpeed())>=line->Vmax(point2+1,TrainLength(),TrainMaxSpeed()) && point3!=line->ShowLength()-3  ){
                      point3++;
                      }
                      TemporarySpeed=speed;
                      bool LoopBrake=0;
                       while(point2-point<20000){
                                Accelaration = AccValue(TemporarySpeed);
                                point2 = point2 + TemporarySpeed/3.6 + Accelaration/(2*3.6);
                                TemporarySpeed=TemporarySpeed + Accelaration;
                               // ShowMessage("start point ="+ CurrToStr(point)+"\n start speed ="+CurrToStr(speed)+"\n temporary point ="+CurrToStr(point2)+"\n temporary speed ="+CurrToStr(TemporarySpeed));
                               if(point2>point3 && line->Vmax(point2,TrainLength(),TrainMaxSpeed())>line->Vmax(point3,TrainLength(),TrainMaxSpeed())){
                                        point2 = point3;
                                        LoopBrake=1;}
                                std::pair<int,int> goal1 (point,speed);
                                std::pair<int,int> goal2 (point2,TemporarySpeed);
                                goal.insert(std::pair<std::pair<int,int>,std::pair<int,int> >(goal2,goal1));
                                if(Accelaration<0.1){break;}

                                if(point2>point && TemporarySpeed>=line->Vmax(point2,TrainLength(),TrainMaxSpeed())){break;}
                                if(LoopBrake==1){break;}




                         }

                }
        speed = line->Vmax(point,TrainLength(),TrainMaxSpeed());
        point++;
        }
        return goal;

}

Brake::Brake(TStringList* entry){
        int l1=0,l2=0;
       //bool a=0;
        int level=0;
        for (int i=0; i<entry->Count; i++){
                String zmienna = entry -> Strings[i];
                int p1=0,p2=0;
                int t=0;
                for(int j=0; j<50; j++){
                        //<level>
                        if(zmienna.SubString(j,8)=="<level=\"" ){
                                        p1=j+8;
                                        t++;
                        }
                        else if(t==1 && zmienna.SubString(j,2)=="\">") {
                                        p2=j;
                                        t++;
                                        l1=i;
                                        break;
                        }
                        //</level>
                        else if(l1<i && zmienna.SubString(j,8)=="</level>"){
                                        l2=i;
                                       // a=1;
                        }
                }
                if(t==2){
                        //ShowMessage(zmienna.SubString(p1,p2-p1));
                        level = (atoi(zmienna.SubString(p1,p2-p1).c_str()));
                        //ShowMessage(CurrToStr(level));
                        }
                if(l2>l1){
                           //ShowMessage(CurrToStr(level));
                         for (int j=l1+1; j<l2; j++){
                        // ShowMessage(entry -> Strings[j]);
                         String zmienna2 = entry -> Strings[j];
                         String wynik;
                         int pa1,pa2,pa3;
                         int q=0;
                                for(int k=0;k<60;k++){
                                        //<speed>
                                        if(zmienna2.SubString(k,8)=="<speed=\"" ){
                                                pa1=k+8;
                                                q++;
                                               // ShowMessage(zmienna2.SubString(k,8));
                                        }
                                        else if(zmienna2.SubString(k,2)=="\">") {
                                                pa2=k+2;
                                                q++;
                                        }
                                        else if(l1<i && zmienna2.SubString(k,8)=="</speed>"){
                                                pa3=k;
                                                q++;
                                        }
                                        if(q==3){
                                                int iteracja = atoi(zmienna2.SubString(pa1,pa2-pa1-2).c_str());
                                                for(int l=j;l<l2;l++)
                                                {
                                                String zmienna3 = entry -> Strings[l];
                                                int pb1,pb2,pb3;
                                                int v=0;
                                                        for(int m=0;m<60;m++){
                                                                if(zmienna3.SubString(m,15)=="<acceleration=\""){
                                                                v++;
                                                                pb1=m+15;
                                                                }
                                                                else if(zmienna3.SubString(m,2)=="\">"){
                                                                v++;
                                                                pb2=m;
                                                                }
                                                                else if(zmienna3.SubString(m,15)=="</acceleration>"){
                                                                v++;
                                                                pb3=m;
                                                                }
                                                        }
                                                if(v==3){
                                                        int iteracja1= atoi(zmienna3.SubString(pb1,pb2-pb1).c_str());
                                                        if(iteracja1==iteracja){
                                                        wynik = zmienna3.SubString(pb2+2,pb3-pb2-2);
                                                        break;
                                                        }

                                                }

                                                }
                                                 q=0;
                                                curves[level][atoi(zmienna2.SubString(pa2,pa3-pa2).c_str())]=atof(wynik.c_str());
                                        }

                                }

                        }
                           l1=l2;
                }
        }

}

double Brake::BrakeValue(int percent, double speed, bool mode) {
        std::map<int,std::map<int,double> >::iterator iterator;
        std::map<int,double>::iterator iterator2;
        iterator=curves.begin();
        double target = 0;
        if(speed>199){speed=199;}
        if(mode==0)
        {
                while(iterator!=curves.end()){
                        ++iterator;
                        if(iterator->first>percent)
                        {
                                --iterator;
                                        iterator2=iterator->second.begin();
                                        while(iterator2!=iterator->second.end()){
                                        ++iterator2;
                                                if(iterator2->first>speed)
                                                {
                                                --iterator2;
                                                target = iterator2 -> second;
                                                break;
                                                }


                                        }
                                break;
                        }
                }
        }
        else
        {
                while(iterator!=curves.end()){
                        ++iterator;
                        if(iterator->first>percent)
                        {
                                --iterator;
                                        iterator2=iterator->second.end();
                                        while(iterator2!=iterator->second.begin()){
                                        --iterator2;
                                                if(iterator2->first<speed)
                                                {
                                                target = iterator2 -> second;
                                                iterator2--;
                                                break;
                                                }

                                        }
                                break;
                        }
                }

        }
        return target;
}


int Brake::DistanceOfBraking(int CurrentSpeed, int NextSpeed, int percent)const{
       double Speed = CurrentSpeed;
       double distance=0;
        while(Speed>=NextSpeed){
        Speed = Speed - BrakeValue(percent,Speed)*3,6;
        distance = distance + Speed/3,6 + BrakeValue(percent,Speed)/2;
        }
        return distance;
}


int  Brake::BrakingSpeed(int End,int EndSpeed,int DistanceFromEnd ,Train *train)const{
        double Distance=End;
        double Speed = EndSpeed;
        double difference= BrakeValue(train->PercentOfBrakingMass,Speed);
        while(Distance>DistanceFromEnd){
                Speed = Speed + difference*3,6;
                difference =  BrakeValue(train->PercentOfBrakingMass,Speed);
                Distance = Distance -  Speed/3,6 - difference/2;
        }
        return Speed;
}

std::pair<std::pair<int,int>,std::pair<int,int> > Brake::BrakeLaunch(int PointOfTrain, Route *line,Train *train) const{
        int test;
        int goal;
        int Vstart;
        int Vend;
       // int Vmax = line->Vmax(PointOfTrain,train->TrainLength(),train->TrainMaxSpeed());
       int Vmax = train->TrainMaxSpeed();
        int *DistancesToSpeedChange = new int[5];
        *(DistancesToSpeedChange)  = line->DistanceToSpeedChange(PointOfTrain,train->TrainLength(),train->TrainMaxSpeed());
        int SumDistanceChange = *(DistancesToSpeedChange);
        int *NextSpeeds = new int[5];
        *(NextSpeeds)=line->NextSpeed(PointOfTrain,train->TrainLength(),train->TrainMaxSpeed());
        test = PointOfTrain + SumDistanceChange;
        int *BrakingDistances = new int [5];
        *(BrakingDistances)= PointOfTrain + SumDistanceChange - DistanceOfBraking(Vmax,*NextSpeeds,train->PercentOfBrakingMass);


           goal = *BrakingDistances;

                for(int i=1; i<5; i++){
                        *(NextSpeeds+i)=line->NextSpeed(PointOfTrain+*(DistancesToSpeedChange+i-1),train->TrainLength(),train->MaxSpeed);
                        *(DistancesToSpeedChange+i)=line->DistanceToSpeedChange(PointOfTrain+*(DistancesToSpeedChange+i-1),train->TrainLength(),train->TrainMaxSpeed());
                         SumDistanceChange = SumDistanceChange + *(DistancesToSpeedChange+i);
                        *(BrakingDistances+i)= PointOfTrain + SumDistanceChange - DistanceOfBraking(Vmax,*(NextSpeeds+i),train->PercentOfBrakingMass);

                      //  if(line->Vmax(PointOfTrain,train->TrainLength(),train->TrainMaxSpeed())!=line->Vmax(*(BrakingDistances+i),train->TrainLength(),train->TrainMaxSpeed()))
                     //   {
                     //    Vmax = line->Vmax(*(BrakingDistances+i),train->TrainLength(),train->TrainMaxSpeed());
                     //   *(BrakingDistances+i)= PointOfTrain + SumDistanceChange - DistanceOfBraking(Vmax,*NextSpeeds,train->PercentOfBrakingMass);
                     //   }

                        if(*(BrakingDistances+i)<goal && *(BrakingDistances+i)!=0){
                                goal = *(BrakingDistances+i);
                                test = PointOfTrain + SumDistanceChange;
                        }

        }
        Vend = line->Vmax(test,train->TrainLength(),train->MaxSpeed);
        Vstart = line->Vmax(goal,train->TrainLength(),train->TrainMaxSpeed());
        if(goal<0){
        goal=0;
        }


        if(goal + line->DistanceToVmax(goal,train->TrainLength(),train->MaxSpeed)<test && line->NextVmax(goal,train->TrainLength(),train->TrainMaxSpeed())>Vstart){
               Vstart =  line->NextVmax(goal,train->TrainLength(),train->MaxSpeed);
        }

        std::pair<int,int> goals1(Vstart,Vend);
        std::pair<int,int> goals(goal,test);
        std::pair<std::pair<int,int>,std::pair<int,int> >Goals(goals,goals1);
       return Goals;
}


std::map<std::pair<int,int>,std::pair<int,int> > brakecount(Train *train,Route *line, Brake *brake){
        std::map<std::pair<int,int>,std::pair<int,int> > goal;
        int PointOfTrain=0;
        while(PointOfTrain<line->ShowLength()-5){
        goal.insert(brake->BrakeLaunch(PointOfTrain,line,train));

         PointOfTrain = PointOfTrain + line->DistanceToVmax(PointOfTrain,train->TrainLength(),train->MaxSpeed);

        }
        return goal;


}

std::map<int,int> staticprofile(Route *line,Train *train){
        std::map<int,int> goal;
        if(train==NULL){
                for(int i=0;i<line->ShowLength();i++){goal.insert(std::pair<int,int>(i,line->Vmax(i)));}
         }
         else {
                 for(int i=0;i<line->ShowLength();i++){goal.insert(std::pair<int,int>(i,line->Vmax(i,train->TrainLength(),train->TrainMaxSpeed())));}
        }
        return goal;
}



std::map<int,int> trainride(Train *train,Route *line, Brake *brake){

        Form9->Show();
        Form9->Visible=True;
        Form9->Canvas->TextOut(104,56,"Wyliczanie profilu dynamicznego");
         //Form9->ProgressBar1->Refresh();

        Form9->ProgressBar1->Position=0;
        std::map<std::pair<int,int>,std::pair<int,int> >BrakeDistances = brakecount(train, line, brake);
          Form9->Canvas->TextOut(104,72,"1. Krzywe hamowania.");
        Form9->ProgressBar1->StepIt();
        std::map<std::pair<int,int>,int> Starts = line->StartPoints(train);
                Form9->Canvas->TextOut(104,88,"2. Punkty rozruchu.");
          //Form9->ProgressBar1->StepIt();
        std::map<int,int> goal;
        std::map<std::pair<int,int>,std::pair<int,int> > test = train->AccSpeeds(line);
            Form9->Canvas->TextOut(104,104,"3. Krzywe rozruchu.");
          Form9->ProgressBar1->StepIt();

        int PointOfTrain=0;

         int Progres=(line->ShowLength()-3)/8;
        while(PointOfTrain<line->ShowLength()-3){
                bool BrakeActive=0;
                bool AccActive=0;
                int TemporarySpeed=line->Vmax(PointOfTrain,train->TrainLength(),train->TrainMaxSpeed());
                int TemporarySpeed2=0;
                int TemporarySpeed3=0;
                std::map<std::pair<int,int>,std::pair<int,int> >::iterator  iterator=BrakeDistances.begin();
                std::map<std::pair<int,int>,int>::iterator iterator1=Starts.begin();
                std::map<std::pair<int,int>,std::pair<int,int> >::iterator iterator1test=test.begin();
                int start;
                int end;
                int VSpeedbrake;
                int Vend;
                int NextSpeed;
                int StartPoint;
                int StartEndPoint;
                int StartSpeed;
                //wyszukiwanie pktow hamowania
                while(iterator!=BrakeDistances.end()){
                        start = iterator -> first.first ;
                        end = iterator -> first.second;
                        Vend = iterator -> second.second;
                        if(PointOfTrain>=start && PointOfTrain<end){
                                BrakeActive=1;
                                break;
                        }
                        iterator++;
                }

                //wyszukiwanie pktow przyspieszanie
             /*
                while(iterator1!=Starts.end()){

                        if(PointOfTrain>=iterator1 -> first.first && PointOfTrain<iterator1 -> first.second){
                        AccActive=1;
                        //StartPoint = iterator1 -> first.first;
                        //StartEndPoint = iterator1 -> first.second;
                        //StartSpeed = iterator1-> second;
                        }

                        iterator1++;
                }
               */
                bool SpeedModify=0;
                int TemporaryStart;
                while(iterator1test!=test.end()){

                         if(PointOfTrain>=iterator1test -> second.first && PointOfTrain<iterator1test -> first.first){
                                AccActive=1;
                                StartPoint = iterator1test -> second.first;
                                StartSpeed = iterator1test-> second.second;
                                StartEndPoint = iterator1test -> first.first;
                        }
                        if(PointOfTrain>=iterator1test -> second.first && PointOfTrain<iterator1test -> first.first && SpeedModify==0){
                                TemporarySpeed3 = iterator1test -> first.second;
                               // ShowMessage(CurrToStr(PointOfTrain)+"\n"+CurrToStr(TemporarySpeed3));
                                SpeedModify=1;
                                TemporaryStart=iterator1test -> second.first;
                        }

                        if(PointOfTrain>iterator1test -> second.first  && PointOfTrain<iterator1test -> first.first && SpeedModify==1 && TemporaryStart>iterator1test -> second.first){
                                TemporarySpeed3 = iterator1test -> first.second;
                               TemporaryStart=iterator1test -> second.first;;
                               break;
                        }

                        iterator1test++;

                }

                  if(BrakeActive==1){
                        TemporarySpeed2=brake->BrakingSpeed(end,Vend,PointOfTrain,train);
                        if(AccActive==1 && TemporarySpeed3<TemporarySpeed2){ if(TemporarySpeed3<TemporarySpeed){TemporarySpeed = TemporarySpeed3;}}
                        else {
                                if(TemporarySpeed2>goal[PointOfTrain-1]) { TemporarySpeed =goal[PointOfTrain-1];}
                                else {TemporarySpeed=TemporarySpeed2;}}




                 }
                 else if(AccActive==1){
                  if(TemporarySpeed3<TemporarySpeed){TemporarySpeed = TemporarySpeed3;}
                  }
                 else {
                 TemporarySpeed=goal[PointOfTrain-1];
                 }



                if(TemporarySpeed>line->Vmax(PointOfTrain,train->TrainLength(),train->TrainMaxSpeed())){TemporarySpeed=line->Vmax(PointOfTrain,train->TrainLength(),train->TrainMaxSpeed());}

                 if(TemporarySpeed>goal[PointOfTrain-1]){
                           if(TemporarySpeed == line->Vmax(PointOfTrain-1,train->TrainLength(),train->TrainMaxSpeed())){
                                if(line->Vmax(PointOfTrain,train->TrainLength(),train->TrainMaxSpeed())>line->Vmax(PointOfTrain-1,train->TrainLength(),train->TrainMaxSpeed())){
                                 //ShowMessage("Exception catched at point "+CurrToStr(PointOfTrain));
                               //   TemporarySpeed=goal[PointOfTrain-1];
                                }
                          }
                 }

                    if(TemporarySpeed>goal[PointOfTrain-1]+10){
                     TemporarySpeed=goal[PointOfTrain-1]+train->AccValue(goal[PointOfTrain-1]);

                    }

                goal.insert(std::pair<int,int>(PointOfTrain,TemporarySpeed));
                //Show Progress
                if(PointOfTrain>Progres){
                        Form9->ProgressBar1->StepIt();
                        Progres=Progres+(line->ShowLength()-3)/8;

                }
                 Form9->Canvas->TextOut(104,120,"Wyliczanie profilu jazdy - " + CurrToStr(100* (PointOfTrain/(line->ShowLength())))+" % ");
                //
                PointOfTrain++;
        }

        Form9->Close();
        return goal;
}

TimeTable::TimeTable (std::map<int,int> DynamicProfile, Route *r){
        double time =0;
        int start=0;
        int d=DynamicProfile.size();
        std::pair<int,int> goal(0,0);
        Times.insert(std::pair<std::pair<int,int>,double>(goal,0));
        Stops.insert(std::pair<int,int>(0,0));
        Points.insert(std::pair<int,AnsiString>(0,r->Show(0)));
        for(int i=0;i<d;i++){
                double ttime=0;
                if(DynamicProfile[i]!=0 && r->Show(i)=="null"){
                        ttime=1/(DynamicProfile[i]/3.6);
                        time = time+ttime;
                }
                else if(DynamicProfile[i]==0 || r->Show(i)!="null"){
                        std::pair<int,int> goal(start,i);
                        start=i;
                        Times.insert(std::pair<std::pair<int,int>,double>(goal,time));
                        Points.insert(std::pair<int,AnsiString>(i,r->Show(i)));
                        time=0;
                        if(DynamicProfile[i]==0 && i<d-3){Stops.insert(std::pair<int,int>(i,60));}
                        else {Stops.insert(std::pair<int,int>(i,0))                       ;}
                }
        }
        StartTime=0;
        int cumulatedtime=StartTime;
        int point;
        double departure,arrival;
        for(int i=0;i<Times.size();i++){
                std::map<std::pair<int,int>,double>::iterator it = Times.begin();
                std::map<int,int>::iterator it1 = Stops.begin();
                std::advance(it,i);
                std::advance(it1,i);
                point = it->first.second;
                cumulatedtime =  cumulatedtime + it->second;
                arrival = cumulatedtime;
                cumulatedtime =  cumulatedtime + it1->second;
                departure =  cumulatedtime;
                std::pair<double,double>goal(arrival,departure);
                std::pair<int,std::pair<double,double> >Goal(point,goal);
                Schedule.insert(Goal);
        }

}

int TimeTable::CountSection(){
        return Times.size();
}

AnsiString TimeTable::ShowStart(int i){
       std::map<std::pair<int,int>,double>::iterator it= Times.begin();
       std::advance(it,i);
       return CurrToStr(it->first.first);

}

AnsiString TimeTable::ShowEnd(int i){
       std::map<std::pair<int,int>,double>::iterator it= Times.begin();
       std::advance(it,i);
       return CurrToStr(it->first.second)+" - "+Points[it->first.second];

}

AnsiString TimeTable::ShowTime(int i){
       std::map<std::pair<int,int>,double>::iterator it= Times.begin();
       std::advance(it,i);
       int time = it->second;
       int hour = time/3600;
       int minute = (time-hour*3600)/60;
       int seconds = (time - hour*3600 - minute*60);

       AnsiString shour = CurrToStr(hour);
       AnsiString sminute = CurrToStr(minute);
       AnsiString sseconds = CurrToStr(seconds);
       if(hour<10){shour = "0"+shour;}
       if(minute<10){sminute = "0"+sminute;}
       if(seconds<10){sseconds = "0"+sseconds;}
       return shour+":"+sminute+":"+sseconds;

}

AnsiString TimeTable::ShowStop(int i){
       std::map<int,int>::iterator it= Stops.begin();
       std::advance(it,i);
       int time = it->second;
       int hour = time/3600;
       int minute = (time-hour*3600)/60;
       int seconds = (time - hour*3600 - minute*60);
       if(time>0){
                AnsiString shour = CurrToStr(hour);
                AnsiString sminute = CurrToStr(minute);
                AnsiString sseconds = CurrToStr(seconds);
                if(hour<10){shour = "0"+shour;}
                if(minute<10){sminute = "0"+sminute;}
                if(seconds<10){sseconds = "0"+sseconds;}
                return shour+":"+sminute+":"+sseconds;
                }
       else     {

                return "-";

                }

}

AnsiString TimeTable::ShowSchedule(int i){
        std::map<int,std::pair<double,double> >::iterator it= Schedule.begin();
        std::advance(it,i);
        if( it->second.first!=it->second.second){ return ConvertTime(it->second.first) + " \\ " + ConvertTime(it->second.second);}
        else { return ConvertTime(it->second.first);}

}

AnsiString TimeTable::ShowNamePoint(int i){
        std::map<std::pair<int,int>,double>::iterator it= Times.begin();
       std::advance(it,i);
       return Points[it->first.second];


}

AnsiString TimeTable::ConvertTime(int time){
       int hour = time/3600;
       int minute = (time-hour*3600)/60;
       int seconds = (time - hour*3600 - minute*60);
       AnsiString shour = CurrToStr(hour);
       AnsiString sminute = CurrToStr(minute);
       AnsiString sseconds = CurrToStr(seconds);
                if(hour<10){shour = "0"+shour;}
                if(minute<10){sminute = "0"+sminute;}
                if(seconds<10){sseconds = "0"+sseconds;}
       return shour+":"+sminute+":"+sseconds;



}

void TimeTable::ChangeStartTime(int a,int b,int c, bool d){
//a - hours, b - minutes, c - section of start, d - departure (false), arrival (true)
        StartTime = a *3600 + b*60;
        int point;
        double departure,arrival,arr;
        Schedule.clear();
        std::map<std::pair<int,int>,double>::iterator it = Times.begin();
        std::advance(it,c);
        point = it->first.second;
        std::map<int,int>::iterator it1 = Stops.begin();
        std::advance(it1,c);
        std::pair<double,double> goal;
        if(d==0){ arrival=StartTime-it1->second; departure=StartTime;}
        else {arrival=StartTime; departure=StartTime+it1->second;}
        goal = std::make_pair(arrival,departure);
        std::pair<int,std::pair<double,double> >Goal(point,goal);
        Schedule.insert(Goal);
        arr=arrival;

        for(int i=c+1; i<Times.size(); i++){
                it = Times.begin();
                it1 = Stops.begin();
             std::advance(it,i);
             std::advance(it1,i);
             point = it->first.second;
             arrival=departure+it->second;
             departure=arrival+it1->second;
             goal = std::make_pair(arrival,departure);
             std::pair<int,std::pair<double,double> >Goal(point,goal);
             Schedule.insert(Goal);
        }

        for(int i=c-1; i>=0; --i){
             it = Times.begin();
             it1 = Stops.begin();
            //
             std::advance(it,i);
             point = it->first.second;
             it = Times.begin();
             std::advance(it,i+1);

             std::advance(it1,i);

             departure=arr-it->second;
             arr=departure-it1->second;
             goal = std::make_pair(arr,departure);
             std::pair<int,std::pair<double,double> >Goal(point,goal);
             Schedule.insert(Goal);
        }

        /*
        for(int i=0;i<Times.size();i++){
                std::map<std::pair<int,int>,double>::iterator it = Times.begin();
                std::map<int,int>::iterator it1 = Stops.begin();
                std::advance(it,i);
                std::advance(it1,i);
                point = it->first.second;
                cumulatedtime =  cumulatedtime + it->second;
                arrival = cumulatedtime;
                cumulatedtime =  cumulatedtime + it1->second;
                departure =  cumulatedtime;
                std::pair<double,double>goal(arrival,departure);
                std::pair<int,std::pair<double,double> >Goal(point,goal);
                Schedule.insert(Goal);
        }
        */


}

std::map<int,int> GetTimetable (std::map<int,int> DynamicProfile) {
        std::map<int,int> goal;
        double time = 0;
        goal.insert(std::pair<int,int>(0,time));
        int d=DynamicProfile.size();
        for(int i=0;i<d;i++){
                double ttime=0;
                if(DynamicProfile[i]!=0){ttime=1/(DynamicProfile[i]/3.6);}
                time = time+ttime;
        }
        goal.insert(std::pair<int,int>(d,time));
        return goal;
}


