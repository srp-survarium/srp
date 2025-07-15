Scaleform::GFx::AMP::MessageObjectsReport *__thiscall Scaleform::GFx::AMP::MessageObjectsReport::`vector deleting destructor'(
        Scaleform::GFx::AMP::MessageObjectsReport *this,
        char a2)
{
  volatile LONG *v3; // edi

  v3 = (volatile LONG *)(this->ObjectsReport.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v3 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v3);
  this->__vftable = (Scaleform::GFx::AMP::MessageObjectsReport_vtbl *)&Scaleform::GFx::AMP::Message::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
