#include "CountersList.h"

Counter* CountersList::addString(const char * str) {
	if (m_curCounters==0) {
		m_pHead = new Counter();
		m_pHead->m_pStr = const_cast<char*>(str);
		m_curCounters++;
		return m_pHead;
	}
	Counter* current = m_pHead;
	
	if(m_curCounters!=0){
		
		//current = m_pHead->next();
		while (current->pNext !=nullptr) {
			if (current->m_pStr == str) {
				current->m_nOwners++;
				return current;
			}
			current = current->pNext;
		}

	}
	Counter* lastStr = new Counter();
	lastStr->m_pStr = const_cast<char*>(str);
	lastStr->pNext = nullptr;
	current->pNext = lastStr;
	m_curCounters++;
	return lastStr;
}


