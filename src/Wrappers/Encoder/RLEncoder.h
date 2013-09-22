#ifndef _RLEncoder_H_
#define _RLEncoder_H_

#include "PosEncoder.h"
#include "../../common/PosBlock.h"
#include "../RLETriple.h"
#include<queue>
#include<map>
using namespace std;

/*Bitmap Encoder
 *encoder positions into bitmaps. 
 *Only used for positions not values. 
 */
class RLEncoder : public PosEncoder
{
public:
	RLEncoder();
	virtual ~RLEncoder();
	//virtual byte* getPage( ){return NULL;}
	virtual byte* getPageAndValue(byte** value_, unsigned int** valSize_);

	virtual void addValPos(ValPos* vp_);
	virtual void purgeMap2Queue();
protected:
	
	queue<RLETriple*> outPutQ;
	//int bufferSizeInBytes;
	short valSize;
	RLETriple* currTriple;
	RLETriple* outTriple;

	void putTriple2Queue(RLETriple* RLETriple_);
};

#endif //_RLEncoder_H_
