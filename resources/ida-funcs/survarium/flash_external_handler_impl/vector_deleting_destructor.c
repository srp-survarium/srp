survarium::flash_external_handler_impl *__thiscall survarium::flash_external_handler_impl::`vector deleting destructor'(
        survarium::flash_external_handler_impl *this,
        char a2)
{
  this->__vftable = (survarium::flash_external_handler_impl_vtbl *)&Scaleform::GFx::State::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
