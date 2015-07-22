//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
 this->ServerSocket1->Port = 23;
 this->ServerSocket1->Active = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
        this->ServerSocket1->Active = false;        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ServerSocket1ClientRead(TObject *Sender,
      TCustomWinSocket *Socket)
{
        this->Edit1->Clear();
        AnsiString messageRecu = Socket->ReceiveText();
        this->Edit1->Text = messageRecu;

        if(messageRecu == "salut")
                Socket->SendText("salut");
        else if(messageRecu == "sa va ?")
                Socket->SendText("oui et toi comment vas tu ?");
        else if(messageRecu == "tu fais quoi ?")
                Socket->SendText("rien et toi ?");
        else if(messageRecu == "rien")
                Socket->SendText("bonne journée ;)");
        else if(messageRecu == "merde")
                Socket->SendText("banni");

}
//---------------------------------------------------------------------------
