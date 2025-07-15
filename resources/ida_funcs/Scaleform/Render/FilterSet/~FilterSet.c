void __thiscall Scaleform::Render::FilterSet::~FilterSet(Scaleform::Render::FilterSet *this)
{
  this->__vftable = (Scaleform::Render::FilterSet_vtbl *)&Scaleform::Render::FilterSet::`vftable';
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::Render::Filter>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::Render::Filter>,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Ptr<Scaleform::Render::Filter>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::Render::Filter>,2>,Scaleform::ArrayDefaultPolicy>(&this->Filters.Data);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}
