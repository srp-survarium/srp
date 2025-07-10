BLK_NODE *__usercall ppmd_allocator::AllocContext@<eax>(ppmd_allocator *this@<ecx>, ppmd_allocator *a2@<eax>)
{
  unsigned __int8 *HiUnit; // eax
  BLK_NODE *result; // eax
  BLK_NODE *next; // ecx
  unsigned int v6; // [esp+0h] [ebp-4h]

  HiUnit = a2->HiUnit;
  if ( HiUnit == a2->LoUnit )
  {
    if ( a2->BList[0].next )
    {
      result = a2->BList[0].next;
      next = result->next;
      --a2->BList[0].Stamp;
      a2->BList[0].next = next;
    }
    else
    {
      return ppmd_allocator::AllocUnitsRare(a2, 0, v6);
    }
  }
  else
  {
    result = (BLK_NODE *)(HiUnit - 12);
    a2->HiUnit = (unsigned __int8 *)result;
  }
  return result;
}
