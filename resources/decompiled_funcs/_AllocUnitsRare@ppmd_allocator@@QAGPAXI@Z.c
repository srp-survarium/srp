BLK_NODE *__userpurge ppmd_allocator::AllocUnitsRare@<eax>(
        ppmd_allocator *a1@<esi>,
        ppmd_allocator *this,
        unsigned int indx)
{
  unsigned int v3; // edi
  BLK_NODE *result; // eax
  BLK_NODE *v5; // ecx
  BLK_NODE **p_next; // eax
  BLK_NODE *next; // ebp
  BLK_NODE *v8; // eax
  int v9; // eax
  unsigned __int8 *v10; // ecx

  v3 = (unsigned int)this;
  if ( a1->GlueCount || (ppmd_allocator::GlueFreeBlocks(a1), !a1->BList[(_DWORD)this].next) )
  {
    p_next = &a1->BList[(_DWORD)this].next;
    while ( 1 )
    {
      ++v3;
      p_next += 2;
      if ( v3 == 38 )
        break;
      if ( *p_next )
      {
        next = a1->BList[v3].next;
        v8 = next->next;
        --a1->BList[v3].Stamp;
        a1->BList[v3].next = v8;
        ppmd_allocator::SplitBlock(a1, (unsigned int)this, (char *)next, v3);
        return next;
      }
    }
    --a1->GlueCount;
    v9 = 12 * a1->Indx2Units[(_DWORD)this];
    if ( a1->UnitsStart - a1->pText <= v9 )
    {
      return 0;
    }
    else
    {
      v10 = &a1->UnitsStart[-v9];
      a1->UnitsStart = v10;
      return (BLK_NODE *)v10;
    }
  }
  else
  {
    result = a1->BList[(_DWORD)this].next;
    v5 = result->next;
    --a1->BList[(_DWORD)this].Stamp;
    a1->BList[(_DWORD)this].next = v5;
  }
  return result;
}
