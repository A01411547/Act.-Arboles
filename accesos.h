#ifndef accesos_h
#define accesos_h
using namespace std; 

class accesos {
  public:
  
    string mes;
    int apariciones;
    void aumentarapariciones();
    string imprimir();
   
    inline bool operator < (   accesos& der  ) {
         return apariciones < der.apariciones;
     }
    inline bool operator > (   accesos& der ) {
         return apariciones > der.apariciones;

     }
    inline bool operator >= (   accesos& der ) {
         return apariciones >= der.apariciones;

     }
    inline bool operator <= (   accesos& der ) {
         return apariciones <= der.apariciones;

     }
    inline bool operator == (  accesos& der ) {
         return apariciones == der.apariciones;

     }
    accesos();
    accesos(string);

    
};
accesos::accesos(){
 mes  = "";
 apariciones = 1;
}

accesos::accesos(string _mes){
   mes = _mes;
   apariciones = 1;
}


void accesos::aumentarapariciones() {
  apariciones++;
}

string accesos::imprimir(){
  string printing = mes;
  printing.append(" with ");
  printing.append(  to_string(apariciones)  );
  printing.append( " accesses.");

  return printing;
}

#endif