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

void __fastcall TForm1::BGC1Click(TObject *Sender)
{
PaintBox1->Canvas->Pen->Color=230;
PaintBox1->Canvas->MoveTo(0,0);
PaintBox1->Canvas->LineTo(200,0);
PaintBox1->Canvas->LineTo(200,200);
PaintBox1->Canvas->LineTo(0,200);
PaintBox1->Canvas->LineTo(0,0);
for(int i=0;i<=200;i++)
{
 for (int j=0;j<=200;j++)
 {
   PaintBox1->Canvas->Pixels[i][j]=105;
 }
}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BGC2Click(TObject *Sender)
{
PaintBox1->Canvas->Pen->Color=80;
PaintBox1->Canvas->MoveTo(300,0);
PaintBox1->Canvas->LineTo(500,0);
PaintBox1->Canvas->LineTo(500,200);
PaintBox1->Canvas->LineTo(300,200);
PaintBox1->Canvas->LineTo(300,0);
for(int i=300;i<=500;i++)
{
 for (int j=0;j<=200;j++)
 {
   PaintBox1->Canvas->Pixels[i][j]=169;
 }
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CC1Click(TObject *Sender)
{
PaintBox1->Canvas->Pen->Color=150;
PaintBox1->Canvas->MoveTo(80,80);
PaintBox1->Canvas->LineTo(120,80);
PaintBox1->Canvas->LineTo(120,120);
PaintBox1->Canvas->LineTo(80,120);
PaintBox1->Canvas->LineTo(80,80);
for(int i=80;i<=120;i++)
{
 for (int j=80;j<=120;j++)
 {
   PaintBox1->Canvas->Pixels[i][j]=128;
 }
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CC2Click(TObject *Sender)
{
PaintBox1->Canvas->Pen->Color=150;
PaintBox1->Canvas->MoveTo(380,80);
PaintBox1->Canvas->LineTo(420,80);
PaintBox1->Canvas->LineTo(420,120);
PaintBox1->Canvas->LineTo(380,120);
PaintBox1->Canvas->LineTo(380,80);
for(int i=380;i<=420;i++)
{
 for (int j=80;j<=120;j++)
 {
   PaintBox1->Canvas->Pixels[i][j]=128;
 }
}
}
//---------------------------------------------------------------------------

