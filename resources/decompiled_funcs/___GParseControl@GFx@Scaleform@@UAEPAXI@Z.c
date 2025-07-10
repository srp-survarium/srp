Scaleform::GFx::AS3Support *__thiscall Scaleform::GFx::ParseControl::`scalar deleting destructor'(
        Scaleform::GFx::AS3Support *this,
        char a2)
{
  this->__vftable = (Scaleform::GFx::AS3Support_vtbl *)&Scaleform::GFx::State::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
