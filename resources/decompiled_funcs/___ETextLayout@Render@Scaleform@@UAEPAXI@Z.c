Scaleform::Render::TextLayout *__thiscall Scaleform::Render::TextLayout::`vector deleting destructor'(
        Scaleform::Render::TextLayout *this,
        char a2)
{
  this->__vftable = (Scaleform::Render::TextLayout_vtbl *)&Scaleform::Render::TextLayout::`vftable';
  Scaleform::Render::TextLayout::Clear(this);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Data.Data.Data);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
