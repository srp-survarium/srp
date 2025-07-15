void __thiscall Scaleform::GFx::ExporterInfoImpl::~ExporterInfoImpl(Scaleform::GFx::ExporterInfoImpl *this)
{
  unsigned int *Data; // eax
  volatile LONG *v3; // esi
  volatile LONG *v4; // esi

  Data = this->CodeOffsets.Data.Data;
  if ( Data )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, Data);
  v3 = (volatile LONG *)(this->SWFName.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v3 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v3);
  v4 = (volatile LONG *)(this->Prefix.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v4 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v4);
}
