void __thiscall Scaleform::String::String(
        Scaleform::String *this,
        Scaleform::String::InitStruct *src,
        unsigned int size)
{
  unsigned int v4; // eax

  if ( size )
  {
    v4 = (unsigned int)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, size + 12, 0);
    *(_BYTE *)(v4 + size + 8) = 0;
    *(_DWORD *)(v4 + 4) = 1;
    *(_DWORD *)v4 = size;
  }
  else
  {
    InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1);
    v4 = (unsigned int)&Scaleform::String::NullData;
  }
  this->HeapTypeBits = v4;
  src->InitString(src, (char *)((v4 & 0xFFFFFFFC) + 8), size);
}
