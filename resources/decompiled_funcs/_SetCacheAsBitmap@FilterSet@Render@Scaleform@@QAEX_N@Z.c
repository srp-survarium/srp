void __thiscall Scaleform::Render::FilterSet::SetCacheAsBitmap(Scaleform::Render::FilterSet *this, bool enable)
{
  Scaleform::GFx::Resource *Instance; // eax
  Scaleform::Ptr<Scaleform::Render::Filter> *Data; // eax
  Scaleform::Array<Scaleform::Ptr<Scaleform::Render::Filter>,2,Scaleform::ArrayDefaultPolicy> *p_Filters; // ecx

  this->CacheAsBitmap = enable;
  if ( enable )
  {
    if ( !this->Filters.Data.Size )
    {
      Instance = (Scaleform::GFx::Resource *)Scaleform::Render::CacheAsBitmapFilter::GetInstance();
      Scaleform::Render::FilterSet::AddFilter(this, Instance);
    }
  }
  else if ( this->Filters.Data.Size == 1 )
  {
    Data = this->Filters.Data.Data;
    p_Filters = &this->Filters;
    if ( Data->pObject->Type == Filter_CacheAsBitmap )
      Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Ptr<Scaleform::Render::Filter>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::Render::Filter>,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
        p_Filters,
        0);
  }
}
