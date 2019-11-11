//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
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

for(int i=0;i<=700;i++)
{
 for (int j=0;j<=700;j++)
 {
   PaintBox1->Canvas->Pixels[i][j]=RGB(195,195,195);
 }

PaintBox1->Canvas->Brush->Color=RGB(0,0,0);

}
for(int i=0;i<=5;i++)
{
  PaintBox1->Canvas->Rectangle(0+i*110,0,100+i*110,100);
}
for(int i=0;i<=5;i++)
{
  PaintBox1->Canvas->Rectangle(0+i*110,110,100+i*110,210);
}
for(int i=0;i<=5;i++)
{
  PaintBox1->Canvas->Rectangle(0+i*110,220,100+i*110,320);
}
for(int i=0;i<=5;i++)
{
  PaintBox1->Canvas->Rectangle(0+i*110,330,100+i*110,430);
}
PaintBox1->Canvas->Pen->Color=RGB(255,255,255);
PaintBox1->Canvas->Brush->Color=RGB(255,255,255);
for(int i=0;i<=4;i++)
{
  PaintBox1->Canvas->Ellipse(97+i*110,97,113+i*110,113);
}
for(int i=0;i<=4;i++)
{
  PaintBox1->Canvas->Ellipse(97+i*110,207,113+i*110,223);
}
for(int i=0;i<=4;i++)
{
  PaintBox1->Canvas->Ellipse(97+i*110,317,113+i*110,333);
}
for(int i=0;i<=4;i++)
{
  PaintBox1->Canvas->Ellipse(97+i*110,427,113+i*110,443);
}
}
//---------------------------------------------------------------------------
 