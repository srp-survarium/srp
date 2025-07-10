Scaleform::GFx::ButtonActionBase *__thiscall Scaleform::GFx::ButtonActionBase::`scalar deleting destructor'(
        Scaleform::GFx::ButtonActionBase *this,
        char a2)
{
  this->__vftable = (Scaleform::GFx::ButtonActionBase_vtbl *)&Scaleform::GFx::ButtonActionBase::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
