/*
 * Preparator.h
 *
 *  Created on: 11 May 2016
 *      Author: Zeyi Wen
 *		@brief: 
 */

#ifndef PREPARATOR_H_
#define PREPARATOR_H_

#include <vector>
#include <map>
#include "../pureHost/GDPair.h"
#include "../pureHost/UpdateOps/NodeStat.h"
#include "../pureHost/UpdateOps/SplitPoint.h"

using std::vector;
using std::map;

class DataPreparator
{
private:
	static int *m_pSNIdToBuffIdHost;//use in two functions
public:
	static void PrepareGDHess(const vector<gdpair> &m_vGDPair_fixedPos);
	static void PrepareSNodeInfo(const map<int, int> &mapNodeIdToBufferPos, const vector<nodeStat> &m_nodeStat);
	static void CopyBestSplitPoint(const map<int, int> &mapNodeIdToBufferPos, vector<SplitPoint> &vBest,
								   vector<nodeStat> &rchildStat, vector<nodeStat> &lchildStat);
	static void ReleaseMem()
	{
		delete []m_pSNIdToBuffIdHost;
	}
};



#endif /* PREPARATOR_H_ */