/*!
* \class CFaceRecognise
*
* \ingroup GroupName
*
* \brief
*
* TODO: detect and get the face info from given image.
*
* \note
*
* \author Xu Hua
*
* \version 1.0
*
* \date 五月 2016
*
* Contact: xh2010wzx@163.com
*
*/

#include "Common.h"


typedef struct _POINT_
{
	int x;		// 
	int y;
	int z;
}POINT;

typedef struct _RECT_
{
	_POINT_ start;
	_POINT_ end;
}RECT, *PRECT;

typedef struct INFOS
{
	int nState;		// 状态
	int nSpecies;

};

typedef struct _EYES_INFO
{
	int l_color;
	int r_color;
	RECT leftEye;
	RECT rightEye;
	POINT l_outline[12];
	POINT r_outline[12];
}EYES_INFO;

typedef struct _NOSE_INFO 
{
	RECT loc;
	POINT outline[14];		
}NOSE_INFO;

typedef struct _MOUTH_INFO
{
	RECT loc;
	POINT outline[16];
	POINT inner[12];	// inner outline
}MOUTH_INFO;

typedef struct _FACE_INFO 
{
	int nFaceColor;
	EYES_INFO eyes;
	NOSE_INFO nose;
	MOUTH_INFO mouth;
	POINT outline[16];
}FACE_INFO;

typedef std::vector<RECT> FACES_LOCACTIONS;		// 脸的位置集

class CFaceRecognise
{
public:
	CFaceRecognise();
	
	int DetectFace(string& filePath, FACES_LOCACTIONS faces);
	int DetectFace(Mat& image, FACES_LOCACTIONS faces);
	int GetFace(string& filePath, FACE_INFO& fi);
	int GetFace(Mat& image, FACE_INFO& fi);
protected:
private:
};