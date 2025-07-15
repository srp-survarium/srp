Scaleform::GFx::AMP::MessageAppControl *__thiscall Scaleform::GFx::AMP::MessageAppControl::`vector deleting destructor'(
        Scaleform::GFx::AMP::MessageAppControl *this,
        char a2)
{
  volatile LONG *v3; // edi

  v3 = (volatile LONG *)(this->LoadMovieFile.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v3 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v3);
  this->__vftable = (Scaleform::GFx::AMP::MessageAppControl_vtbl *)&Scaleform::GFx::AMP::Message::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(&this->Scaleform::GFx::AMP::Message);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)this);
  return this;
}
