void __thiscall Scaleform::StatDescRegistry::RegisterDesc(
        Scaleform::StatDescRegistry *this,
        Scaleform::StatDesc *pdesc)
{
  unsigned int v2; // eax
  unsigned __int16 v3; // dx
  unsigned __int16 *v4; // eax
  Scaleform::StatDesc **v5; // eax

  v2 = pdesc->Id >> 3;
  v3 = this->IdPageTable[v2];
  v4 = &this->IdPageTable[v2];
  if ( !v3 )
  {
    if ( this->DescAllocOffset + 8 > 0x400 )
      return;
    v3 = LOWORD(this->DescAllocOffset) + 1;
    *v4 = v3;
    v5 = &this->DescMem[this->DescAllocOffset];
    *v5 = 0;
    v5[1] = 0;
    v5[2] = 0;
    v5[3] = 0;
    v5[4] = 0;
    v5[5] = 0;
    v5[6] = 0;
    v5[7] = 0;
    this->DescAllocOffset += 8;
  }
  *(_DWORD *)&this->IdPageTable[2 * v3 + 510 + 2 * (pdesc->Id & 7)] = pdesc;
}
