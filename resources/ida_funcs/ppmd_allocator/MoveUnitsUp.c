BLK_NODE *__userpurge ppmd_allocator::MoveUnitsUp@<eax>(
        BLK_NODE *OldPtr@<edi>,
        unsigned int NU@<edx>,
        void *a3@<esi>,
        ppmd_allocator *this)
{
  int v5; // ebp
  BLK_NODE *next; // eax
  BLK_NODE *v7; // ecx
  unsigned __int8 *UnitsStart; // eax
  unsigned int v9; // ecx
  BLK_NODE *result; // eax
  unsigned __int8 *v11; // edx
  ppmd_allocator *thisa; // [esp+Ch] [ebp+4h]

  v5 = this->Indx2Units[NU + 37];
  if ( (unsigned __int8 *)OldPtr > this->UnitsStart + 0x4000 || OldPtr > this->BList[v5].next )
    return OldPtr;
  next = this->BList[v5].next;
  v7 = next->next;
  --this->BList[v5].Stamp;
  thisa = (ppmd_allocator *)next;
  this->BList[v5].next = v7;
  ppmd_allocator::UnitsCpy((char *)next, NU, (ppmd_allocator *)OldPtr, a3);
  UnitsStart = this->UnitsStart;
  v9 = this->Indx2Units[v5];
  if ( OldPtr == (BLK_NODE *)UnitsStart )
  {
    v11 = &UnitsStart[12 * v9];
    result = (BLK_NODE *)thisa;
    this->UnitsStart = v11;
  }
  else
  {
    result = (BLK_NODE *)thisa;
    OldPtr->next = this->BList[v5].next;
    this->BList[v5].next = OldPtr;
    OldPtr->Stamp = -1;
    OldPtr[1].Stamp = v9;
    ++this->BList[v5].Stamp;
  }
  return result;
}
