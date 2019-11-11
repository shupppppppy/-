//---------------------------------------------------------------------------

#include <vcl.h>
#include <stdio.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

unsigned char image_array[512][512];
int a[256]={0};
int height;
int width;
int sizeofimage;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
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
                for(int y = 0;y < 512;y++)
                {
                        for(int x = 0;x < 512;x++)
                        {
                                int pic = image_array[y][x];
                                PaintBox1->Canvas->Pixels[x][y]=RGB(pic,pic,pic);
                                a[pic] = a[pic] + 1;
                        }
                }

                PaintBox2->Canvas->Pen->Color = RGB(255,255,255);
                PaintBox2->Canvas->Brush->Color = RGB(255,255,255);
                PaintBox2->Canvas->Rectangle(0,0,256,512);
                PaintBox2->Canvas->Pen->Color = RGB(0,0,0);

                for(int k = 0;k < 255;k++)
                        {
                                PaintBox2->Canvas->MoveTo(k,512);
                                PaintBox2->Canvas->LineTo(k,512-a[k]/20);
                        }
                fclose(file_open);
        }
}

void __fastcall TForm1::Button2Click(TObject *Sender)
{
        height = 512;
        width = 512;
        int e = 0;
        sizeofimage = height*width;

        FILE *file_open;
        String image_name;
        if(OpenDialog1->Execute())
        {
                image_name = ExtractFilePath(OpenDialog1->FileName);
                image_name = image_name + ExtractFileName(OpenDialog1->FileName);
                file_open = fopen(image_name.c_str(),"rb");
                fread(image_array,sizeof(unsigned char)*512*512,1,file_open);
                		for(int y = 0;y < 512;y++)
				{
                        for(int x = 0;x < 512;x++)
                        {
                                int pic = image_array[y][x];
                                a[pic] = a[pic] + 1;//a数组用来存储每个像素值的个数
                        }
                }
                fclose(file_open);
        }

        int aa[256] = {0};
        int s[256] = {0};
        int t[256] = {0};
		
        for(int i = 0;i < 256;i++)
        {
                s[i] = s[i-1] + a[i];//s数组存储running sum
        }
        for(int j = 0;j < 256;j++)
        {
                t[j] = (int)(255 * s[j] / s[255]);
                aa[t[j]] = aa[t[j]] + a[j];
        }
		
        PaintBox2->Canvas->Pen->Color = RGB(255,255,255);
        PaintBox2->Canvas->Brush->Color = RGB(255,255,255);
        PaintBox2->Canvas->Rectangle(0,0,256,512);
        PaintBox2->Canvas->Pen->Color = RGB(0,0,0);

        for(int k = 0;k < 255;k++)
        {
                PaintBox2->Canvas->MoveTo(k,512);
                PaintBox2->Canvas->LineTo(k,512-aa[k]/20);
        }
        for(int y = 0;y < 512;y++)
                {
                        for(int x = 0;x < 512;x++)
                        {
                                int c = image_array[y][x];
                                PaintBox1->Canvas->Pixels[x][y]=RGB(t[c],t[c],t[c]);
                        }
                }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
        height = 512;
        width = 512;
        sizeofimage = height*width;
        int pmax = -1;
        int pmin = 100000;

        FILE *file_open;
        String image_name;
        if(OpenDialog1->Execute())
        {
                image_name = ExtractFilePath(OpenDialog1->FileName);
                image_name = image_name + ExtractFileName(OpenDialog1->FileName);
                file_open = fopen(image_name.c_str(),"rb");
                fread(image_array,sizeof(unsigned char)*512*512,1,file_open);
                for(int y = 0;y < 512;y++)
                {
                        for(int x = 0;x < 512;x++)
                        {
                                int pic = image_array[y][x];
                                a[pic] = a[pic] + 1;
                                if(pmax < pic)
                                {
                                        pmax = pic;
                                }
                                if(pmin > pic)
                                {
                                        pmin = pic;
                                }
                        }
                }
                fclose(file_open);
        }

        float fpic[256];
        int aa[256] = {0};
        for(int i = pmin;i < pmax + 1;i++)
        {
                fpic[i] = ((float)(i) - (float)pmin)/((float)pmax - (float)pmin) * 255;
                aa[(int)(fpic[i] + 0.5)] = aa[(int)(fpic[i] + 0.5)] + a[i];
        }

        PaintBox2->Canvas->Pen->Color = RGB(255,255,255);
        PaintBox2->Canvas->Brush->Color = RGB(255,255,255);
        PaintBox2->Canvas->Rectangle(0,0,256,512);
        PaintBox2->Canvas->Pen->Color = RGB(0,0,0);
				
        for(int y = 0;y < 512;y++)
        {
                for(int x = 0;x < 512;x++)
                {
                        int c = image_array[y][x];
                        PaintBox1->Canvas->Pixels[x][y]=RGB((int)(fpic[c]),(int)(fpic[c]),(int)(fpic[c]));
                }
        }

        for(int k = 0;k < 255;k++)
        {
                PaintBox2->Canvas->MoveTo(k,512);
                PaintBox2->Canvas->LineTo(k,512-aa[k]/10);
        }
}
//---------------------------------------------------------------------------
