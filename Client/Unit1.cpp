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
        this->EditPort->Text = "2013";
        this->EditAdresse->Text = "192.168.1.150";
        this->RichEdit1->Lines->Clear();
        this->RichEdit1->Lines->Add("Connectez vous pour commencer...");

        //if(touche 'entrée' appuyée) this->ButtonSendClick(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
        this->ClientSocket1->Active = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonConnexionClick(TObject *Sender)
{
        if(this->ButtonConnexion->Caption == "Deconnexion")
        {
                this->ClientSocket1->Active = false;
                this->ButtonConnexion->Caption = "Connexion";
                this->EditAdresse->Enabled = true;
                this->EditPort->Enabled = true;
                this->EditSend->Enabled = false;
                this->Label1->Caption = "Deconnecté";
                this->FormCreate(NULL);
        }
        else
        {
                this->ClientSocket1->Host = this->EditAdresse->Text;
                this->ClientSocket1->Port = this->EditPort->Text.ToInt();
                this->ClientSocket1->Active = true;

                this->ButtonConnexion->Caption = "Deconnexion";
                this->EditAdresse->Enabled = false;
                this->EditPort->Enabled = false;
                this->EditSend->Enabled = true;
                this->Label1->Caption = "Connecté";
                this->RichEdit1->Lines->Clear();
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ClientSocket1Read(TObject *Sender,
      TCustomWinSocket *Socket)
{
        AnsiString b = this->ClientSocket1->Socket->ReceiveText();
        this->RichEdit1->Lines->Add("\n"+b+"\n");
        if(b == "merde")  {
                this->ButtonConnexionClick(NULL);
                this->RichEdit1->Lines->Clear(); }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ImageRefreshClick(TObject *Sender)
{
        this->RichEdit1->Lines->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ImageSendClick(TObject *Sender)
{
        if(this->ButtonConnexion->Caption == "Deconnexion")
        {
                AnsiString a = this->EditSend->Text;
                this->ClientSocket1->Socket->SendText(a);
                this->RichEdit1->Lines->Add(a);
        }
}
//---------------------------------------------------------------------------

