unsigned __int8 *__thiscall Scaleform::StatBag::AllocStatData(
        Scaleform::StatBag *this,
        unsigned int statId,
        unsigned int size)
{
  unsigned __int16 v3; // si
  unsigned int v4; // edi
  unsigned int MemAllocOffset; // eax
  unsigned __int8 *result; // eax
  unsigned __int8 *v7; // eax
  unsigned int v8; // eax
  unsigned int v9; // edx

  v3 = this->IdPageTable[statId >> 4];
  v4 = (size + 7) & 0xFFFFFFF8;
  if ( v3 == 0xFFFF )
  {
    MemAllocOffset = this->MemAllocOffset;
    if ( this->MemSize < MemAllocOffset + 32 )
      return 0;
    v3 = MemAllocOffset >> 3;
    this->IdPageTable[statId >> 4] = v3;
    v7 = &this->pMem[this->MemAllocOffset];
    *(_DWORD *)v7 = -1;
    *((_DWORD *)v7 + 1) = -1;
    *((_DWORD *)v7 + 2) = -1;
    *((_DWORD *)v7 + 3) = -1;
    *((_DWORD *)v7 + 4) = -1;
    *((_DWORD *)v7 + 5) = -1;
    *((_DWORD *)v7 + 6) = -1;
    *((_DWORD *)v7 + 7) = -1;
    this->MemAllocOffset += 32;
  }
  v8 = this->MemAllocOffset;
  if ( this->MemSize < v8 + v4 )
    return 0;
  *(_WORD *)&this->pMem[8 * v3 + 2 * (statId & 0xF)] = v8 >> 3;
  v9 = this->MemAllocOffset;
  result = &this->pMem[v9];
  this->MemAllocOffset = v4 + v9;
  return result;
}
