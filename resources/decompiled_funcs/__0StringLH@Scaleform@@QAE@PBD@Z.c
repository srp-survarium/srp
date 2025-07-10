void __thiscall Scaleform::StringLH::StringLH(Scaleform::StringLH *this, char *pdata)
{
  unsigned int v3; // edi
  Scaleform::MemoryHeap *v4; // eax

  if ( pdata )
    v3 = strlen(pdata);
  else
    v3 = 0;
  v4 = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
  this->HeapTypeBits = (unsigned int)Scaleform::String::AllocDataCopy1(this, v4, v3, 0, pdata, v3) | 1;
}
