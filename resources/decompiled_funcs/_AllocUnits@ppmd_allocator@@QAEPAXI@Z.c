BLK_NODE *__usercall ppmd_allocator::AllocUnits@<eax>(ppmd_allocator *this@<ecx>, unsigned int NU@<eax>)
{
  ppmd_allocator *v3; // ecx
  BLK_NODE *result; // eax
  BLK_NODE *next; // edx
  unsigned __int8 *v6; // edx
  unsigned int v7; // [esp+0h] [ebp-4h]

  v3 = (ppmd_allocator *)this->Indx2Units[NU + 37];
  if ( this->BList[(_DWORD)v3].next )
  {
    result = this->BList[(_DWORD)v3].next;
    next = result->next;
    --this->BList[(_DWORD)v3].Stamp;
    this->BList[(_DWORD)v3].next = next;
  }
  else
  {
    result = (BLK_NODE *)this->LoUnit;
    v6 = (unsigned __int8 *)result + 12 * this->Indx2Units[(_DWORD)v3];
    this->LoUnit = v6;
    if ( v6 > this->HiUnit )
    {
      this->LoUnit = &v6[-12 * this->Indx2Units[(_DWORD)v3]];
      return ppmd_allocator::AllocUnitsRare(this, v3, v7);
    }
  }
  return result;
}
