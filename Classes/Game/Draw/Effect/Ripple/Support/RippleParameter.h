#ifndef _RIPPLE_PARAMETER_H_
#define _RIPPLE_PARAMETER_H_

#include <string>

/**
	@class	：	RippleParameter
	@brief	：	波紋クラスのパラメータ構造体
	@author	：	利川聖太
 */
struct RippleParameter
{
	std::string	fileName;		// ファイルの名前
	float		scaleValue;		// 拡大値に加算する値
};

#endif