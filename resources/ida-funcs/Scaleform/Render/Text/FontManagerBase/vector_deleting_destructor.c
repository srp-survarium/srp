Scaleform::Render::Text::FontManagerBase *__thiscall Scaleform::Render::Text::FontManagerBase::`vector deleting destructor'(
        Scaleform::Render::Text::FontManagerBase *this,
        char a2)
{
  this->__vftable = (Scaleform::Render::Text::FontManagerBase_vtbl *)&Scaleform::Render::Text::FontManagerBase::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
