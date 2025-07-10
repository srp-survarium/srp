Scaleform::GFx::ResourceFileInfo *__thiscall Scaleform::GFx::ResourceFileInfo::`scalar deleting destructor'(
        Scaleform::GFx::ResourceFileInfo *this,
        char a2)
{
  volatile LONG *v3; // esi

  v3 = (volatile LONG *)(this->FileName.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v3 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v3);
  Scaleform::RefCountNTSImplCore::~RefCountNTSImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
