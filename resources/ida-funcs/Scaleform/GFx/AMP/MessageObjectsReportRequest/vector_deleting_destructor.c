Scaleform::GFx::AMP::MessageHeartbeat *__thiscall Scaleform::GFx::AMP::MessageObjectsReportRequest::`vector deleting destructor'(
        Scaleform::GFx::AMP::MessageHeartbeat *this,
        char a2)
{
  this->__vftable = (Scaleform::GFx::AMP::MessageHeartbeat_vtbl *)&Scaleform::GFx::AMP::Message::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
