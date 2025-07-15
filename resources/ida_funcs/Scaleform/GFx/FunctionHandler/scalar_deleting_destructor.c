Scaleform::GFx::FunctionHandler *__thiscall Scaleform::GFx::FunctionHandler::`scalar deleting destructor'(
        Scaleform::GFx::FunctionHandler *this,
        char a2)
{
  this->__vftable = (Scaleform::GFx::FunctionHandler_vtbl *)&Scaleform::GFx::FunctionHandler::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
