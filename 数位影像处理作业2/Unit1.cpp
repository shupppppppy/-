//---------------------------------------------------------------------------

#include <vcl.h>
#include <stdio.h>
#include <math.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
unsigned char image_array[512][512];

int height;
int width;
int sizeofimage;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)  //open
{
        height = 512;
        width = 512;
        sizeofimage = height*width;

        FILE *file_open;
        String image_name;
        if(OpenDialog1->Execute())
        {
                image_name = ExtractFilePath(OpenDialog1->FileName);
                image_name = image_name + ExtractFileName(OpenDialog1->FileName);
                file_open = fopen(image_name.c_str(),"rb");
                fread(image_array,sizeof(unsigned char)*512*512,1,file_open);
                for(int x=0;x<512;x++)
                {
                        for(int y = 0;y < 512;y++)
                        {
                                int pic = image_array[y][x];
                                PaintBox1->Canvas->Pixels[x][y]=RGB(pic,pic,pic);
                        }
                }
                fclose(file_open);
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)//64*64
{
        height = 512;
        width = 512;
        sizeofimage = height*width;

        FILE *file_open;
        String image_name;
        int pic;
        if(OpenDialog1->Execute())
        {
                image_name = ExtractFilePath(OpenDialog1->FileName);
                image_name = image_name + ExtractFileName(OpenDialog1->FileName);
                file_open = fopen(image_name.c_str(),"rb");
                fread(image_array,sizeof(unsigned char)*512*512,1,file_open);
               for(int x=0;x<512;x=x+8)
                {
                 for(int y=0;y<512;y=y+8)
                  {
                   pic = image_array[x][y];
                   PaintBox1->Canvas->Pen->Color=RGB(pic,pic,pic);
                   PaintBox1->Canvas->Brush->Color=RGB(pic,pic,pic);
                   PaintBox1->Canvas->Rectangle(y,x,y+8,x+8);
                   }
                }
                fclose(file_open);
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)//32*32
 {
        height = 512;
        width = 512;
        sizeofimage = height*width;

        FILE *file_open;
        String image_name;
        int pic;
        if(OpenDialog1->Execute())
        {
                image_name = ExtractFilePath(OpenDialog1->FileName);
                image_name = image_name + ExtractFileName(OpenDialog1->FileName);
                file_open = fopen(image_name.c_str(),"rb");
                fread(image_array,sizeof(unsigned char)*512*512,1,file_open);
               for(int x=0;x<512;x=x+16)
                {
                 for(int y=0;y<512;y=y+16)
                  {
                   pic = image_array[x][y];
                   PaintBox1->Canvas->Pen->Color=RGB(pic,pic,pic);
                   PaintBox1->Canvas->Brush->Color=RGB(pic,pic,pic);
                   PaintBox1->Canvas->Rectangle(y,x,y+16,x+16);
                   }
                }
                fclose(file_open);
        }
}
//------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)  //16*16
 {
        height = 512;
        width = 512;
        sizeofimage = height*width;

        FILE *file_open;
        String image_name;
        int pic;
        if(OpenDialog1->Execute())
        {
                image_name = ExtractFilePath(OpenDialog1->FileName);
                image_name = image_name + ExtractFileName(OpenDialog1->FileName);
                file_open = fopen(image_name.c_str(),"rb");
                fread(image_array,sizeof(unsigned char)*512*512,1,file_open);
               for(int x=0;x<512;x=x+32)
                {
                 for(int y=0;y<512;y=y+32)
                  {
                   pic = image_array[x][y];
                   PaintBox1->Canvas->Pen->Color=RGB(pic,pic,pic);
                   PaintBox1->Canvas->Brush->Color=RGB(pic,pic,pic);
                   PaintBox1->Canvas->Rectangle(y,x,y+32,x+32);
                   }
                }
                fclose(file_open);
        }
 }
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)    //16gl
{
        height = 512;
        width = 512;
        sizeofimage = height*width;

        FILE *file_open;
        String image_name;
        int pic;
        if(OpenDialog1->Execute())
        {
                image_name = ExtractFilePath(OpenDialog1->FileName);
                image_name = image_name + ExtractFileName(OpenDialog1->FileName);
                file_open = fopen(image_name.c_str(),"rb");
                fread(image_array,sizeof(unsigned char)*512*512,1,file_open);
                for(int x=0;x<512;x++)
                {
                        for(int y = 0;y < 512;y++)
                        {
                                int pic = image_array[y][x];
                                pic = (pic/16)*16;
                                PaintBox1->Canvas->Pixels[x][y]=RGB(pic,pic,pic);
                        }
                }

        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)  //4gl
{
        height = 512;
        width = 512;
        sizeofimage = height*width;

        FILE *file_open;
        String image_name;
        int pic;
        if(OpenDialog1->Execute())
        {
                image_name = ExtractFilePath(OpenDialog1->FileName);
                image_name = image_name + ExtractFileName(OpenDialog1->FileName);
                file_open = fopen(image_name.c_str(),"rb");
                fread(image_array,sizeof(unsigned char)*512*512,1,file_open);
                for(int x=0;x<512;x++)
                {
                        for(int y = 0;y < 512;y++)
                        {
                                int pic = image_array[y][x];
                                pic = (pic/64)*64;
                                PaintBox1->Canvas->Pixels[x][y]=RGB(pic,pic,pic);
                        }
                }

        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)   //bin
{
        height = 512;
        width = 512;
        sizeofimage = height*width;

        FILE *file_open;
        String image_name;
        int pic;
        if(OpenDialog1->Execute())
        {
                image_name = ExtractFilePath(OpenDialog1->FileName);
                image_name = image_name + ExtractFileName(OpenDialog1->FileName);
                file_open = fopen(image_name.c_str(),"rb");
                fread(image_array,sizeof(unsigned char)*512*512,1,file_open);
                for(int x=0;x<512;x++)
                {
                        for(int y = 0;y < 512;y++)
                        {
                                int pic = image_array[y][x];
                                pic = (pic/128)*255;
                                PaintBox1->Canvas->Pixels[x][y]=RGB(pic,pic,pic);
                        }
                }

        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)//dithering
{
        height = 512;
        width = 512;
        sizeofimage = height*width;

        FILE *file_open;
        String image_name;
        int pic;
        int q;
        if(OpenDialog1->Execute())
        {
                image_name = ExtractFilePath(OpenDialog1->FileName);
                image_name = image_name + ExtractFileName(OpenDialog1->FileName);
                file_open = fopen(image_name.c_str(),"rb");
                fread(image_array,sizeof(unsigned char)*512*512,1,file_open);
                for(int x=0;x<512;x=x+2)
                {
                        for(int y = 0;y < 512;y=y+2)
                        {
                                double pic = image_array[y][x];
                                if(pic > 0)
                                {
                                  pic = 255;
                                }
                                else
                                {
                                  pic = 0;
                                }
                                PaintBox1->Canvas->Pixels[x][y]=RGB(pic,pic,pic);
                        }
                }
                 for(int x=1;x<512;x=x+2)
                {
                        for(int y = 0;y < 512;y=y+2)
                        {
                                double pic = image_array[y][x];
                                if(pic > 192)
                                {
                                  pic = 255;
                                }
                                else
                                {
                                  pic = 0;
                                }
                                PaintBox1->Canvas->Pixels[x][y]=RGB(pic,pic,pic);
                        }
                }
                 for(int x=0;x<512;x=x+2)
                {
                        for(int y = 1;y < 512;y=y+2)
                        {
                                double pic = image_array[y][x];
                                if(pic > 128)
                                {
                                  pic = 255;
                                }
                                else
                                {
                                  pic = 0;
                                }
                                PaintBox1->Canvas->Pixels[x][y]=RGB(pic,pic,pic);
                        }
                }
                 for(int x=1;x<512;x=x+2)
                {
                        for(int y = 1;y < 512;y=y+2)
                        {
                                pic = image_array[y][x];
                                if(pic > 64)
                                {
                                  pic = 255;
                                }
                                else
                                {
                                  pic = 0;
                                }
                                PaintBox1->Canvas->Pixels[x][y]=RGB(pic,pic,pic);
                        }
                }
        }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button10Click(TObject *Sender)//IGS
{
        height = 512;
        width = 512;
        sizeofimage = height*width;

        FILE *file_open;
        String image_name;
        int pic;
        if(OpenDialog1->Execute())
        {
                image_name = ExtractFilePath(OpenDialog1->FileName);
                image_name = image_name + ExtractFileName(OpenDialog1->FileName);
                file_open = fopen(image_name.c_str(),"rb");
                fread(image_array,sizeof(unsigned char)*512*512,1,file_open);
               for(int x=0;x<512;x++)
                {
                 for(int y=0;y<512;y++)
                  {
                     int pic1 = image_array[y][x];
                     if (pic1 > 55 )
                     PaintBox1->Canvas->Pixels[x][y]=RGB(pic1,pic1,pic1);
                     else
                     {
                       int pic2 = image_array[y-1][x];
                       pic = pic1 + pic2 % 16;
                       pic = pic/32*32;
                       PaintBox1->Canvas->Pixels[x][y]=RGB(pic,pic,pic);
                     }
                  }
                }
                fclose(file_open);
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button9Click(TObject *Sender)//ROI
{
 height = 512;
        width = 512;
        sizeofimage = height*width;
        int pic;
        FILE *file_open;
        String image_name;
        if(OpenDialog1->Execute())
        {
                image_name = ExtractFilePath(OpenDialog1->FileName);
                image_name = image_name + ExtractFileName(OpenDialog1->FileName);
                file_open = fopen(image_name.c_str(),"rb");
                fread(image_array,sizeof(unsigned char)*512*512,1,file_open);
            for(int y = 0;y <192;y++)
            {
                 for(int x=0;x<512;x++)
                {
                     pic = image_array[y/16*16][x/16*16];
                     PaintBox1->Canvas->Pixels[x][y]=RGB(pic,pic,pic);
                }
            }
            for(int y = 320;y <512;y++)
            {
                 for(int x=0;x<512;x++)
                {
                     pic = image_array[y/16*16][x/16*16];
                     PaintBox1->Canvas->Pixels[x][y]=RGB(pic,pic,pic);
                }
            }

            for(int y = 192;y <320;y++)
            {
                 for(int x=0;x<192;x++)
                {
                     pic = image_array[y/16*16][x/16*16];
                     PaintBox1->Canvas->Pixels[x][y]=RGB(pic,pic,pic);
                }
            }
            for(int y = 192;y<320;y++)
            {
                 for(int x=320;x<512;x++)
                {
                     pic = image_array[y/16*16][x/16*16];
                     PaintBox1->Canvas->Pixels[x][y]=RGB(pic,pic,pic);
                }
            }


                for(int x=192;x<320;x++)
                {
                        for(int y = 192;y <320;y++)
                        {
                                int pic = image_array[y][x];
                                PaintBox1->Canvas->Pixels[x][y]=RGB(pic,pic,pic);
                        }
                }
         fclose(file_open);
        }
}
//---------------------------------------------------------------------------

