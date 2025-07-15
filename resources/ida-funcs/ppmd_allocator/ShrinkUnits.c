ppmd_allocator *__usercall ppmd_allocator::ShrinkUnits@<eax>(
        ppmd_allocator *this@<esi>,
        ppmd_allocator *OldPtr@<edi>,
        unsigned int OldNU@<eax>,
        unsigned int NewNU@<edx>,
        void *a5@<ebp>)
{
  unsigned int v5; // ecx
  int v6; // ebx
  BLK_NODE *next; // ebp
  BLK_NODE *v8; // eax
  BLK_NODE *v9; // eax
  ppmd_allocator *result; // eax

  v5 = this->Indx2Units[NewNU + 37];
  v6 = this->Indx2Units[OldNU + 37];
  if ( v6 != v5 )
  {
    if ( this->BList[v5].next )
    {
      next = this->BList[v5].next;
      v8 = next->next;
      --this->BList[v5].Stamp;
      this->BList[v5].next = v8;
      ppmd_allocator::UnitsCpy((char *)next, NewNU, OldPtr, a5);
      v9 = (BLK_NODE *)this->Indx2Units[v6];
      OldPtr->BList[0].Stamp = (unsigned int)this->BList[v6].next;
      this->BList[v6].next = (BLK_NODE *)OldPtr;
      OldPtr->BList[0].next = v9;
      result = (ppmd_allocator *)next;
      OldPtr->m_allocator = (vostok::memory::base_allocator *)-1;
      ++this->BList[v6].Stamp;
      return result;
    }
    ppmd_allocator::SplitBlock(this, v5, (char *)OldPtr, this->Indx2Units[OldNU + 37]);
  }
  return OldPtr;
}
