//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <stdio.h>
#include <time.h>
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

void __fastcall TForm1::Button1Click(TObject *Sender)//open
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
                        }
                }
                fclose(file_open);
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)//mean 5*5
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
                int a = 0;
                for(int y=0;y<512;y++)
                {
	                for(int x=0;x<512;x++)
	                {
		                for(int j=y;j<y+5;j++)
		                {
			                for(int k=x;k<x+5;k++)
			                {
				                a = a + image_array[j][k];
			                }
		                }
                        PaintBox1->Canvas->Pixels[x+2][y+2]=RGB(a/25,a/25,a/25);
                        a = 0;
	                }
                }
        fclose(file_open);
        }                
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)//mean 9*9
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
                int a = 0;
                for(int y=0;y<512;y++)
                {
	                for(int x=0;x<512;x++)
	                {
		                for(int j=y;j<y+9;j++)
		                {
			                for(int k=x;k<x+9;k++)
			                {
				                a = a + image_array[j][k];
			                }
		                }
                        PaintBox1->Canvas->Pixels[x+4][y+4]=RGB(a/81,a/81,a/81);
                        a = 0;
	                }
                }
        fclose(file_open);
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)//medium 5*5
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
                int a[25] = {0};
                int i = 0;
                for(int y=0;y<512;y++)
                {
	                for(int x=0;x<512;x++)
	                {
	                	for(int j=y;j<y+5;j++)
		                {
		                	for(int k=x;k<x+5;k++)
			                {
				                a[i] = image_array[j][k];
				                i++;
			                }
	                	}
		                int temp = 0;
		                for(int n=0;n<24;n++)
                        {
							for(int m=1;m<25;m++)
							{				
								if(a[m]<a[n])
								{
									temp = a[m];
									a[m] = a[n];
									a[n] = temp;
								}
							}		
						}
		                PaintBox1->Canvas->Pixels[x+2][y+2]=RGB(a[12],a[12],a[12]);
						i = 0;//i要重新赋值为0
	                }
                }
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)//medium 9*9 
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
                int a[81] = {0};
                int i = 0;
                for(int y=0;y<512;y++)
                {
	                for(int x=0;x<512;x++)
	                {
	                	for(int j=y;j<y+9;j++)
		                {
		                	for(int k=x;k<x+9;k++)
			                {
				                a[i] = image_array[j][k];
				                i++;
			                }
	                	}
		                int temp = 0;
						for(int n=0;n<80;n++)
                        {
							for(int m=1;m<81;m++)
							{				
								if(a[m]<a[n])
								{
									temp = a[m];
									a[m] = a[n];
									a[n] = temp;
								}
							}		
						}
		                PaintBox1->Canvas->Pixels[x+4][y+4]=RGB(a[40],a[40],a[40]);
						i = 0;//i要重新赋值为0
	                }
                }
        }        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)//alpha 5*5
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
                int a[25] = {0};
                int i = 0;
                for(int y=0;y<512;y++)
                {
	                for(int x=0;x<512;x++)
	                {
	                	for(int j=y;j<y+5;j++)
		                {
		                	for(int k=x;k<x+5;k++)
			                {
				                a[i] = image_array[j][k];
				                i++;
			                }
	                	}
		                int temp = 0;
						int b = 0;
						for(int n=0;n<24;n++)
                        {
							for(int m=1;m<25;m++)
							{				
								if(a[m]<a[n])
								{
									temp = a[m];
									a[m] = a[n];
									a[n] = temp;
								}
							}		
						}
						for(int n=2;n<23;n++)
						{
							b = b + a[n];
						}
		                PaintBox1->Canvas->Pixels[x+2][y+2]=RGB(b/21,b/21,b/21);
						i = 0;
	                }
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)//alpha 9*9
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
                int a[81] = {0};
                int i = 0;
                for(int y=0;y<512;y++)
                {
	                for(int x=0;x<512;x++)
	                {
	                	for(int j=y;j<y+9;j++)
		                {
		                	for(int k=x;k<x+9;k++)
			                {
				                a[i] = image_array[j][k];
				                i++;
			                }
	                	}
		                int temp = 0;
						int b = 0;
						for(int n=0;n<80;n++)
                        {
							for(int m=1;m<81;m++)
							{				
								if(a[m]<a[n])
								{
									temp = a[m];
									a[m] = a[n];
									a[n] = temp;
								}
							}		
						}
						for(int n=2;n<79;n++)
						{
							b = b + a[n];
						}
		                PaintBox1->Canvas->Pixels[x+4][y+4]=RGB(b/77,b/77,b/77);
						i = 0;
	                }
                }
        }        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)//mean 5*5 with pepper salt 
{
        height = 512;
        width = 512;
        sizeofimage = height*width;
		srand((unsigned)time(NULL));
		int rh,rw,flag;
		int rnum = height * width * 35 / 100;
        FILE *file_open;
        String image_name;
        if(OpenDialog1->Execute())
        {
                image_name = ExtractFilePath(OpenDialog1->FileName);
                image_name = image_name + ExtractFileName(OpenDialog1->FileName);
                file_open = fopen(image_name.c_str(),"rb");
                fread(image_array,sizeof(unsigned char)*512*512,1,file_open);
				for (int i=0;i<rnum;i++)
				{
					rh = rand() % (height);
					rw = rand() % (width);
					int flag = rand() % 2;
					if(flag == 0)
					{
						image_array[rh][rw] = 0;
					}
					else
					{
						image_array[rh][rw] = 255;
					}
				}
				for(int y = 0;y < 512;y++)
                {
                        for(int x = 0;x < 512;x++)
                        {
                                int pic = image_array[y][x];
                                PaintBox1->Canvas->Pixels[x][y]=RGB(pic,pic,pic);
                        }
                }
                int a = 0;
                for(int y=0;y<512;y++)
                {
	                for(int x=0;x<512;x++)
	                {
		                for(int j=y;j<y+5;j++)
		                {
			                for(int k=x;k<x+5;k++)
			                {
				                a = a + image_array[j][k];
			                }
		                }
                        PaintBox1->Canvas->Pixels[x+2][y+2]=RGB(a/25,a/25,a/25);
                        a = 0;
	                }
                }
        fclose(file_open);
        }             
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button9Click(TObject *Sender)//mean 9*9 with pepper salt 
{
        height = 512;
        width = 512;
        sizeofimage = height*width;
		srand((unsigned)time(NULL));
		int rh,rw,flag;
		int rnum = height * width * 35 / 100;
        FILE *file_open;
        String image_name;
        if(OpenDialog1->Execute())
        {
                image_name = ExtractFilePath(OpenDialog1->FileName);
                image_name = image_name + ExtractFileName(OpenDialog1->FileName);
                file_open = fopen(image_name.c_str(),"rb");
                fread(image_array,sizeof(unsigned char)*512*512,1,file_open);
				for (int i=0;i<rnum;i++)
				{
					rh = rand() % (height);
					rw = rand() % (width);
					int flag = rand() % 2;
					if(flag == 0)
					{
						image_array[rh][rw] = 0;
					}
					else
					{
						image_array[rh][rw] = 255;
					}
				}
                int a = 0;
                for(int y=0;y<512;y++)
                {
	                for(int x=0;x<512;x++)
	                {
		                for(int j=y;j<y+9;j++)
		                {
			                for(int k=x;k<x+9;k++)
			                {
				                a = a + image_array[j][k];
			                }
		                }
                        PaintBox1->Canvas->Pixels[x+4][y+4]=RGB(a/81,a/81,a/81);
                        a = 0;
	                }
                }
        fclose(file_open);
        }        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button10Click(TObject *Sender)//medium 5*5 with pepper salt 
{
 height = 512;
        width = 512;
        sizeofimage = height*width;
		srand((unsigned)time(NULL));
		int rh,rw,flag;
		int rnum = height * width * 35 / 100;
        FILE *file_open;
        String image_name;
        if(OpenDialog1->Execute())
        {
                image_name = ExtractFilePath(OpenDialog1->FileName);
                image_name = image_name + ExtractFileName(OpenDialog1->FileName);
                file_open = fopen(image_name.c_str(),"rb");
                fread(image_array,sizeof(unsigned char)*512*512,1,file_open);
				for (int i=0;i<rnum;i++)
				{
					rh = rand() % (height);
					rw = rand() % (width);
					int flag = rand() % 2;
					if(flag == 0)
					{
						image_array[rh][rw] = 0;
					}
					else
					{
						image_array[rh][rw] = 255;
					}
				}
                int a[25] = {0};
                int i = 0;
                for(int y=0;y<512;y++)
                {
	                for(int x=0;x<512;x++)
	                {
	                	for(int j=y;j<y+5;j++)
		                {
		                	for(int k=x;k<x+5;k++)
			                {
				                a[i] = image_array[j][k];
				                i++;
			                }
	                	}
		                int temp = 0;
						for(int n=0;n<24;n++)
                        {
							for(int m=1;m<25;m++)
							{				
								if(a[m]<a[n])
								{
									temp = a[m];
									a[m] = a[n];
									a[n] = temp;
								}
							}		
						}
		                PaintBox1->Canvas->Pixels[x+2][y+2]=RGB(a[12],a[12],a[12]);
						i = 0;
	                }
                }
        }        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button11Click(TObject *Sender)//medium 9*9 with pepper salt 
{
height = 512;
        width = 512;
        sizeofimage = height*width;
		srand((unsigned)time(NULL));
		int rh,rw,flag;
		int rnum = height * width * 35 / 100;
        FILE *file_open;
        String image_name;
        if(OpenDialog1->Execute())
        {
                image_name = ExtractFilePath(OpenDialog1->FileName);
                image_name = image_name + ExtractFileName(OpenDialog1->FileName);
                file_open = fopen(image_name.c_str(),"rb");
                fread(image_array,sizeof(unsigned char)*512*512,1,file_open);
				for (int i=0;i<rnum;i++)
				{
					rh = rand() % (height);
					rw = rand() % (width);
					int flag = rand() % 2;
					if(flag == 0)
					{
						image_array[rh][rw] = 0;
					}
					else
					{
						image_array[rh][rw] = 255;
					}
				}
                int a[81] = {0};
                int i = 0;
                for(int y=0;y<512;y++)
                {
	                for(int x=0;x<512;x++)
	                {
	                	for(int j=y;j<y+9;j++)
		                {
		                	for(int k=x;k<x+9;k++)
			                {
				                a[i] = image_array[j][k];
				                i++;
			                }
	                	}
		                int temp = 0;
						for(int n=0;n<80;n++)
                        {
							for(int m=1;m<81;m++)
							{				
								if(a[m]<a[n])
								{
									temp = a[m];
									a[m] = a[n];
									a[n] = temp;
								}
							}		
						}
		                PaintBox1->Canvas->Pixels[x+4][y+4]=RGB(a[40],a[40],a[40]);
						i = 0;
	                }
                }
        }                
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button13Click(TObject *Sender)//alpha 5*5 with pepper salt 
{
height = 512;
        width = 512;
        sizeofimage = height*width;
		srand((unsigned)time(NULL));
		int rh,rw,flag;
		int rnum = height * width * 35 / 100;
        FILE *file_open;
        String image_name;
        if(OpenDialog1->Execute())
        {
                image_name = ExtractFilePath(OpenDialog1->FileName);
                image_name = image_name + ExtractFileName(OpenDialog1->FileName);
                file_open = fopen(image_name.c_str(),"rb");
                fread(image_array,sizeof(unsigned char)*512*512,1,file_open);
				for (int i=0;i<rnum;i++)
				{
					rh = rand() % (height);
					rw = rand() % (width);
					int flag = rand() % 2;
					if(flag == 0)
					{
						image_array[rh][rw] = 0;
					}
					else
					{
						image_array[rh][rw] = 255;
					}
				}
                int a[25] = {0};
                int i = 0;
                for(int y=0;y<512;y++)
                {
	                for(int x=0;x<512;x++)
	                {
	                	for(int j=y;j<y+5;j++)
		                {
		                	for(int k=x;k<x+5;k++)
			                {
				                a[i] = image_array[j][k];
				                i++;
			                }
	                	}
		                int temp = 0;
						int b = 0;
						for(int n=0;n<24;n++)
                        {
							for(int m=1;m<25;m++)
							{				
								if(a[m]<a[n])
								{
									temp = a[m];
									a[m] = a[n];
									a[n] = temp;
								}
							}		
						}
						for(int n=2;n<23;n++)
						{
							b = b + a[n];
						}
		                PaintBox1->Canvas->Pixels[x+2][y+2]=RGB(b/21,b/21,b/21);
						i = 0;
	                }
                }
        }        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button14Click(TObject *Sender)//alpha 9*9 with pepper salt 
{
		height = 512;
        width = 512;
        sizeofimage = height*width;
		srand((unsigned)time(NULL));
		int rh,rw,flag;
		int rnum = height * width * 35 / 100;
        FILE *file_open;
        String image_name;
        if(OpenDialog1->Execute())
        {
                image_name = ExtractFilePath(OpenDialog1->FileName);
                image_name = image_name + ExtractFileName(OpenDialog1->FileName);
                file_open = fopen(image_name.c_str(),"rb");
                fread(image_array,sizeof(unsigned char)*512*512,1,file_open);
				for (int i=0;i<rnum;i++)
				{
					rh = rand() % (height);
					rw = rand() % (width);
					int flag = rand() % 2;
					if(flag == 0)
					{
						image_array[rh][rw] = 0;
					}
					else
					{
						image_array[rh][rw] = 255;
					}
				}
                int a[81] = {0};
                int i = 0;
                for(int y=0;y<512;y++)
                {
	                for(int x=0;x<512;x++)
	                {
	                	for(int j=y;j<y+9;j++)
		                {
		                	for(int k=x;k<x+9;k++)
			                {
				                a[i] = image_array[j][k];
				                i++;
			                }
	                	}
		                int temp = 0;
						int b = 0;
						for(int n=0;n<80;n++)
                        {
							for(int m=1;m<81;m++)
							{				
								if(a[m]<a[n])
								{
									temp = a[m];
									a[m] = a[n];
									a[n] = temp;
								}
							}		
						}
						for(int n=2;n<79;n++)
						{
							b = b + a[n];
						}
		                PaintBox1->Canvas->Pixels[x+4][y+4]=RGB(b/77,b/77,b/77);
						i = 0;
	                }
                }
        }                
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button12Click(TObject *Sender)//pepper salt noise
{
        height = 512;
        width = 512;
        sizeofimage = height*width;
		srand((unsigned)time(NULL));
		int rh,rw,flag;
		int rnum = height * width * 35 / 100;
        FILE *file_open;
        String image_name;
        if(OpenDialog1->Execute())
        {
                image_name = ExtractFilePath(OpenDialog1->FileName);
                image_name = image_name + ExtractFileName(OpenDialog1->FileName);
                file_open = fopen(image_name.c_str(),"rb");
                fread(image_array,sizeof(unsigned char)*512*512,1,file_open);
				for (int i=0;i<rnum;i++)
				{
					rh = rand() % (height);
					rw = rand() % (width);
					int flag = rand() % 2;
					if(flag == 0)
					{
						image_array[rh][rw] = 0;
					}
					else
					{
						image_array[rh][rw] = 255;
					}
				}
				for(int y = 0;y < 512;y++)
                {
                        for(int x = 0;x < 512;x++)
                        {
                            int pic = image_array[y][x];
                            PaintBox1->Canvas->Pixels[x][y]=RGB(pic,pic,pic);
                        }
                }
        fclose(file_open);
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button15Click(TObject *Sender)//high-pass filter
{
        height = 512;
        width = 512;
        sizeofimage = height*width;
        int hpf[9] = {-2,-5,-2,-5,28,-5,-2,-5,-2};

        FILE *file_open;
        String image_name;
        if(OpenDialog1->Execute())
        {
                image_name = ExtractFilePath(OpenDialog1->FileName);
                image_name = image_name + ExtractFileName(OpenDialog1->FileName);
                file_open = fopen(image_name.c_str(),"rb");
                fread(image_array,sizeof(unsigned char)*512*512,1,file_open);
                int a = 0;
				int i = 0;
                for(int y=0;y<512;y++)
                {
	                for(int x=0;x<512;x++)
	                {
		                for(int j=y;j<y+3;j++)
		                {
			                for(int k=x;k<x+3;k++)
			                {
				                a = a + image_array[j][k] * hpf[i];
								i++;
			                }
		                }
						if(a < 0)
						{
							a = 0;
						}
						if(a > 255)
						{
							a = 255;
						}
                        PaintBox1->Canvas->Pixels[x+1][y+1]=RGB(a,a,a);
                        a = 0;
						i = 0;
	                }
                }
                fclose(file_open);
        }
}
//---------------------------------------------------------------------------

