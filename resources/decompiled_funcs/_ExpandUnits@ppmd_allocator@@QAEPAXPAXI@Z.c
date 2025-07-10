char *__userpurge ppmd_allocator::ExpandUnits@<eax>(
        ppmd_allocator *this@<edi>,
        ppmd_allocator *OldPtr@<esi>,
        unsigned int OldNU)
{
  int v4; // ebx
  char *result; // eax
  void *v6; // [esp+0h] [ebp-8h]
  char *ptr; // [esp+Ch] [ebp+4h]

  v4 = this->Indx2Units[OldNU + 37];
  if ( v4 == this->Units2Indx[OldNU] )
    return (char *)OldPtr;
  result = (char *)ppmd_allocator::AllocUnits(this, OldNU + 1);
  ptr = result;
  if ( result )
  {
    ppmd_allocator::UnitsCpy(result, OldNU, OldPtr, v6);
    result = ptr;
    OldPtr->BList[0].Stamp = (unsigned int)this->BList[v4].next;
    this->BList[v4].next = (BLK_NODE *)OldPtr;
    OldPtr->m_allocator = (vostok::memory::base_allocator *)-1;
    OldPtr->BList[0].next = (BLK_NODE *)OldNU;
    ++this->BList[v4].Stamp;
  }
  return result;
}
