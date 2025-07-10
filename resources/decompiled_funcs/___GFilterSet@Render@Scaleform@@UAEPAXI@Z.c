Scaleform::Render::FilterSet *__thiscall Scaleform::Render::FilterSet::`scalar deleting destructor'(
        Scaleform::Render::FilterSet *this,
        char a2)
{
  this->__vftable = (Scaleform::Render::FilterSet_vtbl *)&Scaleform::Render::FilterSet::`vftable';
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::Render::Filter>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::Render::Filter>,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Ptr<Scaleform::Render::Filter>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::Render::Filter>,2>,Scaleform::ArrayDefaultPolicy>(&this->Filters.Data);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
