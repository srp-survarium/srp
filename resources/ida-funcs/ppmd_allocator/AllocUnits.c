unsigned __int8 *__usercall ppmd_allocator::AllocUnits@<eax>(ppmd_allocator *this@<ecx>, unsigned int NU@<eax>)
{
  unsigned int v2; // eax
  char *v3; // edx
  unsigned __int8 *result; // eax
  int v5; // ecx
  unsigned __int8 *v6; // esi
  unsigned __int8 *LoUnit; // edi
  unsigned __int8 *v8; // edx

  v2 = this->Indx2Units[NU + 37];
  v3 = (char *)this + 8 * v2;
  if ( *((_DWORD *)v3 + 2) )
  {
    result = (unsigned __int8 *)*((_DWORD *)v3 + 2);
    v5 = *((_DWORD *)result + 1);
    --*((_DWORD *)v3 + 1);
    *((_DWORD *)v3 + 2) = v5;
  }
  else
  {
    v6 = &this->Indx2Units[v2];
    LoUnit = this->LoUnit;
    v8 = &LoUnit[12 * *v6];
    this->LoUnit = v8;
    if ( v8 > this->HiUnit )
    {
      this->LoUnit = &v8[-12 * *v6];
      return ppmd_allocator::AllocUnitsRare(this, v2);
    }
    else
    {
      return LoUnit;
    }
  }
  return result;
}
