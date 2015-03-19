#ifndef _RESULT_DATA_H_
#define _RESULT_DATA_H_

/**
	@brief	リザルトで使用する海ほたる情報の構造体
 */
struct ResultData
{
	int		findSFF;		// 見つけた数
	int		overlookedSFF;	// 見落とした数
	int		lostSFF;		// 失った数
	bool	isPerfect;		// 全部見つけたか否か
	
	/**
		@brief	コンストラクタ
	 
		@param	findSFF			見つけた数
		@param	overlookedSFF	見落とした数
	 	@param	lostSFF			失った数
	 	@param	isPerfect		全部見つけたか否か
	 */
	ResultData( int findSFF, int overlookedSFF, int lostSFF, bool isPerfect )
	{
		this->findSFF		= findSFF;
		this->overlookedSFF	= overlookedSFF;
		this->lostSFF		= lostSFF;
		this->isPerfect		= isPerfect;
	}
};

#endif