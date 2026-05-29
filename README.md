bool login(){
         string userid,pass;
        cout<<"Enter Your Login Id : ";
        cin>>userid;
        cout<<"Enter Your Password : ";
        cin>>pass;
        if(userid==id){
            if(pass == password){
              cout<<"[STATUS] Logging In .";
              Sleep(1500);
              cout<<" . ";
              Sleep(1500);
              cout<<" . ";
              Sleep(1500);
              cout<<" . ";
              cout<<"[STATUS] Succesfully Login"<<endl;
              isLoggedIn=true;
              return true;
            }else{
              cout<<"Invalid Password. Try Again!"<<endl;
            }
            
          }else{
            cout<<"Invalid Creadential. Try Again!"<<endl;
          }
          
          return false;
      }
      bool logouot(){
          cout<<"[STATUS] Logging out .";
              Sleep(1500);
              cout<<" . ";
              Sleep(1500);
              cout<<" . ";
              Sleep(1500);
              cout<<" . ";
              cout<<"[STATUS] Succesfully Log Out"<<endl;
              isLoggedIn=false;
              return true;
      }
      void updtatePassword(){
        string userid,pass,npass,cpass;
        bool cond =true ;
        do{
        cout<<"Enter Your Login Id : ";
        cin>>userid;
        cout<<"Enter Your Password : ";
        cin>>pass;
        if(userid==id){
            if(pass == password){
               do{
               cout<<"Enter Your New Password : ";
               cin>>npass;
               cout<<endl;
               cout<<"Enter Again : ";
               cin>>cpass;
               cout<<endl;
               if(npass!=cpass) cout<<"Passwords Mismatch. Try Again!"<<endl;
              }while(npass!=cpass);
              cond=false;
            }else{
              cout<<"Invalid Password. Try Again!"<<endl;
            }
            
          }else{
            cout<<"Invalid Creadential. Try Again!"<<endl;
          }
        }while(cond);
          
      }
        void signIn(){
        cout<<"=====( Student Sign In )====="<<endl;
        cout<<"Enter your Name : ";
        getline(cin,name);
        cout<<endl;
        cout<<"Enter your ID : ";
        cin>>id;
        cout<<endl;
        do{
        cout<<"Enter Your Password (Length of 8) : ";
        cin>>password;
        if(password.length()!=8) cout<<"Invalid Password Length Must be 8"<<endl;
        }while(password.length()!=8);
        cout<<"Enter Your Registration Number : ";
        cin>>registrationNumber;
        isLoggedIn=true;
      }