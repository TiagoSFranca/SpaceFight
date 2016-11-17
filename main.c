#include <allegro.h>

#define ALTURA 640
#define LARGURA 480
#define INFO 200
BITMAP *buffer;
BITMAP *fundo;
BITMAP *informe;
BITMAP *status;

void Init();
void Atirar();
void MoverNave();
void MoverNaveInimiga();
void StartNave();
void StartNaveInimiga();
void MostrarTela();
void Status();
struct Nave
{
	int x,y;
	int hp;
	int tam_x,tam_y;
	int velocidade;
	BITMAP *img;
}MinhaNave,NaveInimiga[4];

int main()
{
	Init();
	StartNave();
	while(!key[KEY_ESC])
	{
		//rest(30);
		MoverNave();
		MostrarTela();
	blit(buffer, screen, 0, 0, 0, 0, LARGURA, ALTURA);
	blit(informe, screen, 0, 0, LARGURA, 0, INFO, ALTURA);
	clear(buffer);
	} 
	return 0;
}
END_OF_MAIN();

void MoverNave(){
	
	if(key[KEY_UP] && MinhaNave.y>0) MinhaNave.y -=MinhaNave.velocidade;
	if(key[KEY_DOWN] && MinhaNave.y<(ALTURA-MinhaNave.tam_y) ) MinhaNave.y +=MinhaNave.velocidade;
	if(key[KEY_LEFT] && MinhaNave.x>0) MinhaNave.x -=MinhaNave.velocidade;
	if(key[KEY_RIGHT] && MinhaNave.x<(LARGURA-MinhaNave.tam_x)) MinhaNave.x +=MinhaNave.velocidade;
	
}

void Init()
{
	allegro_init();
	set_color_depth(32);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, LARGURA+INFO, ALTURA, 0, 0);
	install_keyboard();
	buffer = create_bitmap(LARGURA, ALTURA);
	informe =  create_bitmap(INFO, ALTURA);
	//informe = load_bitmap("tiro-1.bmp", NULL);
	fundo = load_bitmap("fundo-1.bmp", NULL);
	status = load_bitmap("STATUS.bmp", NULL);
}

void MostrarTela(){
	Status();
	draw_sprite(buffer,fundo,0,0);
	draw_sprite(informe,fundo,LARGURA,0);
	draw_sprite(informe,status,0,0);
	draw_sprite(buffer,MinhaNave.img,MinhaNave.x,MinhaNave.y);
//	clear(buffer);
}
void StartNave(){
	MinhaNave.hp = 15;
	MinhaNave.tam_x = 65;
	MinhaNave.tam_y = 92;
	MinhaNave.x = (LARGURA/2)-(MinhaNave.tam_x/2);
	MinhaNave.y = ALTURA-MinhaNave.tam_y;
	MinhaNave.velocidade=1.5;	
	MinhaNave.img = load_bitmap("nave-1.bmp", NULL);
}
/*void StartNaveInimiga(){
	int i;
	for(i=0;i<4;i++){
		NaveInimiga[i].hp = 10;
		NaveInimiga[i].tam_x = 
		
	}
	
}*/

void Status(){	
	textprintf_centre_ex(informe, font,INFO/2, 50, makecol(255, 0, 0), 2, "HP: %d", MinhaNave.hp);
}