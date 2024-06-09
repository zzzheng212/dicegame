#pragma once

struct bits
{
	unsigned char hit : 1;
	unsigned char speedup : 1;
	unsigned char sp_disable : 1;
	unsigned char mp_disbale : 1;
	unsigned char freeze : 1;
	unsigned char sp_up : 1;
	unsigned char mp_up : 1;
	unsigned char hp_up : 1;
};
union byte_bits
{
	bits b;
	unsigned char B;
};
struct position
{
	float X;
	float Y;
	float Theta = 1.57;
};
struct vw
{
	float V;
	float W;
};
struct points
{
	float HP;
	float SP;
	float MP;
	float EXP;
};
struct profile
{
	char name[20];
	struct position pos;
	struct vw vel;
	struct points point;
	int t;
	union byte_bits status;
};

struct vxy
{
	float Vx;
	float Vy;
};
struct dice_profile/////»ë¤l
{
	char name[20];
	struct position pos;
	struct points point;
	float Velocity;
	struct vxy V;
	float range;
	float theta[10];
	int counter = 1;
	float diameter = 10;//////¤l¼u¥b®|
	bool enable = 0;
	bool dice_no_picture = true;
};
struct dice_weapon_profile
{
	struct position pos;
	struct points point;
	float Velocity;
	struct vxy V;
	float range;
	float theta[10];
	int counter;
	float diameter = 10;//////¤l¼u¥b®|
	bool enable = 0;

};
struct freeze_dice_profile/////´H¦B»ë¤l
{
	struct position pos;
	struct points point;
	float Velocity;
	struct vxy V;
	float range;
	float theta;
	int counter;
	float diameter = 10;//////¤l¼u¥b®|
	bool enable = 0;
	bool dice_no_picture = true;

};
struct freeze_bullet_profile/////´H¦B»ë¤lªZ¾¹
{
	struct position pos;
	struct points point;
	float Velocity;
	struct vxy V;
	float range;
	float theta;
	int counter = 20;
	float diameter = 10;//////¤l¼u¥b®|
	bool enable = 0;
};
struct nuclear_dice_profile/////®Ö¼u»ë¤l
{
	struct position pos;
	struct points point;
	float Velocity;
	struct vxy V;
	float range;
	float theta;
	int counter = 20;
	float diameter = 20;//////¤l¼u¥b®|
	bool enable = 0;
	bool dice_no_picture = true;

};
struct nuclear_weapon_profile/////®Ö¼u»ë¤lªZ¾¹
{
	struct position pos;
	struct points point;
	float Velocity;
	struct vxy V;
	float range;
	float theta;
	int counter = 20;
	float diameter = 10;//////¤l¼u¥b®|
	bool enable = 0;

};
struct AOE_dice_profile/////¤j½d³ò§ðÀ»»ë¤l
{
	struct position pos;
	struct points point;
	float Velocity;
	struct vxy V;
	float range;
	float theta;
	int counter;
	float diameter = 5;//////¤l¼u¥b®|
	float Attack_Range = 10;
	bool enable = 0;
	bool dice_no_picture = true;
};
struct AOEdice_weapon_profile
{
	struct position pos;
	struct points point;
	float Velocity;
	struct vxy V;
	float range;
	float theta[10];
	int counter;
	float diameter = 10;//////¤l¼u¥b®|
	bool enable = 0;
};
struct enemy_profile///////¼Ä¤H
{
	char name[20];
	struct position pos;
	struct vxy V;
	struct points point;
	union byte_bits status;
	int EXPcout;
	int random;
	int counter;
	float width = 20;
	bool enable = 0;
	bool collide = 0;
};