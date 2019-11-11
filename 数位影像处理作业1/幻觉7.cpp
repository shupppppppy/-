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
PaintBox1->Canvas->MoveTo(100,50);
PaintBox1->Canvas->LineTo(200,50);
PaintBox1->Canvas->MoveTo(100,250);
PaintBox1->Canvas->LineTo(200,250);
PaintBox1->Canvas->MoveTo(100,25);
PaintBox1->Canvas->LineTo(25,300);
PaintBox1->Canvas->MoveTo(200,25);
PaintBox1->Canvas->LineTo(275,300);
}
//---------------------------------------------------------------------------
