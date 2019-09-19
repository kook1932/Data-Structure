#ifndef __SLOT_H__
#define __SLOT_H__

#include"Person.h"

typedef int Key;
typedef Person * Value;

enum SlotStatus { EMPTY, DELETE, INUSE };

typedef struct _slot
{
	Key key;
	Value val;
	enum SlotStatus status;
} Slot;

#endif // !__SLOT_H__

