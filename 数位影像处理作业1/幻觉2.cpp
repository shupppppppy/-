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

void __fastcall TForm1::Button1Click(TObject *Sender)
{
for(int i=0;i<=100;i++)
{
 for (int j=0;j<=200;j++)
 {
   PaintBox1->Canvas->Pixels[i][j]=1;
 }
}


for(int i=100;i<=200;i++)
{
 for (int j=0;j<=200;j++)
 {
   PaintBox1->Canvas->Pixels[i][j]=80;
 }
}

for(int i=200;i<=300;i++)
{
 for (int j=0;j<=200;j++)
 {
   PaintBox1->Canvas->Pixels[i][j]=140;
 }
}

for(int i=300;i<=400;i++)
{
 for (int j=0;j<=200;j++)
 {
   PaintBox1->Canvas->Pixels[i][j]=190;
 }
}

for(int i=400;i<=500;i++)
{
 for (int j=0;j<=200;j++)
 {
   PaintBox1->Canvas->Pixels[i][j]=240;
 }
}

}
//---------------------------------------------------------------------------



