#ifndef _READ_DATA_H_
#define _READ_DATA_H_

#include <string>

/**
	@brief	読み込んだデータの構造体
 */
struct ReadData
{
	std::string		textureName;	// テクスチャの名前
	int				positionX;		// X軸の座標
	int				positionY;		// Y軸の座標
	float			scaleX;			// X軸の拡大率
	float			scaleY;			// Y軸の拡大率
};

#endif