Scaleform::GFx::AMP::MessageSourceFile *__thiscall Scaleform::GFx::AMP::MessageSourceFile::`scalar deleting destructor'(
        Scaleform::GFx::AMP::MessageSourceFile *this,
        char a2)
{
  volatile LONG *v3; // edi

  v3 = (volatile LONG *)(this->Filename.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v3 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v3);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->FileData.Data.Data);
  this->__vftable = (Scaleform::GFx::AMP::MessageSourceFile_vtbl *)&Scaleform::GFx::AMP::Message::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
