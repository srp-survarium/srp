Scaleform::Render::FilterBundle *__thiscall Scaleform::Render::FilterBundle::`vector deleting destructor'(
        Scaleform::Render::FilterBundle *this,
        char a2)
{
  Scaleform::Render::FilterPrimitive::~FilterPrimitive(&this->Prim);
  this->__vftable = (Scaleform::Render::FilterBundle_vtbl *)&Scaleform::Render::Bundle::`vftable';
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Entries.Data.Data);
  Scaleform::RefCountNTSImplCore::~RefCountNTSImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
