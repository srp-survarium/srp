void __thiscall Scaleform::GFx::URLBuilder::LocationInfo::~LocationInfo(Scaleform::GFx::URLBuilder::LocationInfo *this)
{
  volatile LONG *v2; // esi
  volatile LONG *v3; // esi

  v2 = (volatile LONG *)(this->ParentPath.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v2 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v2);
  v3 = (volatile LONG *)(this->FileName.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v3 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v3);
}
