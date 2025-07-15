unsigned __int8 *__usercall ppmd_allocator::AllocUnitsRare@<eax>(ppmd_allocator *this@<ecx>, unsigned int indx@<eax>)
{
  unsigned int v4; // ebx
  char *v5; // ecx
  unsigned __int8 *result; // eax
  int v7; // edx
  BLK_NODE **p_next; // eax
  BLK_NODE *v9; // eax
  BLK_NODE *next; // ebx
  BLK_NODE *v11; // ecx
  int v12; // eax
  unsigned __int8 *v13; // edx
  unsigned int v14; // [esp+Ch] [ebp-4h]

  v4 = indx;
  if ( this->GlueCount
    || (ppmd_allocator::GlueFreeBlocks(this, this), v5 = (char *)this + 8 * indx, !*((_DWORD *)v5 + 2)) )
  {
    p_next = &this->BList[indx].next;
    while ( 1 )
    {
      ++v4;
      p_next += 2;
      v14 = v4;
      if ( v4 == 38 )
        break;
      if ( *p_next )
      {
        v9 = &this->BList[v4];
        next = this->BList[v4].next;
        v11 = next->next;
        --v9->Stamp;
        v9->next = v11;
        ppmd_allocator::SplitBlock(this, indx, (char *)next, v14);
        return (unsigned __int8 *)next;
      }
    }
    --this->GlueCount;
    v12 = 12 * this->Indx2Units[indx];
    if ( this->UnitsStart - this->pText <= v12 )
    {
      return 0;
    }
    else
    {
      v13 = &this->UnitsStart[-v12];
      this->UnitsStart = v13;
      return v13;
    }
  }
  else
  {
    result = (unsigned __int8 *)*((_DWORD *)v5 + 2);
    v7 = *((_DWORD *)result + 1);
    --*((_DWORD *)v5 + 1);
    *((_DWORD *)v5 + 2) = v7;
  }
  return result;
}
