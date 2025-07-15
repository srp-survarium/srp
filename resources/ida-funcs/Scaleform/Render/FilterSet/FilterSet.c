void __thiscall Scaleform::Render::FilterSet::FilterSet(
        Scaleform::Render::FilterSet *this,
        Scaleform::GFx::Resource *filter)
{
  this->__vftable = (Scaleform::Render::FilterSet_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::Render::FilterSet_vtbl *)&Scaleform::Render::FilterSet::`vftable';
  this->Filters.Data.Data = 0;
  this->Filters.Data.Size = 0;
  this->Filters.Data.Policy.Capacity = 0;
  this->Frozen = 0;
  this->CacheAsBitmap = 0;
  if ( filter )
    Scaleform::Render::FilterSet::AddFilter(this, filter);
}
