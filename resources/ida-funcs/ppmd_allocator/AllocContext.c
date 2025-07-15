unsigned __int8 *__thiscall ppmd_allocator::AllocContext(ppmd_allocator *this)
{
  unsigned __int8 *HiUnit; // eax
  unsigned __int8 *result; // eax
  BLK_NODE *v3; // edx

  HiUnit = this->HiUnit;
  if ( HiUnit == this->LoUnit )
  {
    if ( this->BList[0].next )
    {
      result = (unsigned __int8 *)this->BList[0].next;
      v3 = (BLK_NODE *)*((_DWORD *)result + 1);
      --this->BList[0].Stamp;
      this->BList[0].next = v3;
    }
    else
    {
      return ppmd_allocator::AllocUnitsRare(this, 0);
    }
  }
  else
  {
    result = HiUnit - 12;
    this->HiUnit = result;
  }
  return result;
}
