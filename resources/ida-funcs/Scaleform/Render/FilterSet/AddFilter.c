void __thiscall Scaleform::Render::FilterSet::AddFilter(
        Scaleform::Render::FilterSet *this,
        Scaleform::GFx::Resource *filter)
{
  Scaleform::RefCountVImpl **Data; // edi
  unsigned int Size; // ecx
  Scaleform::Array<Scaleform::Ptr<Scaleform::Render::Filter>,2,Scaleform::ArrayDefaultPolicy> *p_Filters; // esi
  Scaleform::Ptr<Scaleform::Render::Filter> *v6; // esi

  if ( this->Filters.Data.Size == 1
    && (Data = (Scaleform::RefCountVImpl **)this->Filters.Data.Data,
        (*Data)[1].__vftable == (Scaleform::RefCountVImpl_vtbl *)11) )
  {
    if ( filter )
      Scaleform::RefCountImpl::AddRef(filter);
    if ( *Data )
      Scaleform::RefCountImpl::Release(*Data);
    *Data = (Scaleform::RefCountVImpl *)filter;
  }
  else
  {
    if ( filter )
      Scaleform::RefCountImpl::AddRef(filter);
    Size = this->Filters.Data.Size;
    p_Filters = &this->Filters;
    Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::Render::Filter>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::Render::Filter>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &p_Filters->Data,
      p_Filters,
      Size + 1);
    v6 = &p_Filters->Data.Data[p_Filters->Data.Size - 1];
    if ( v6 )
    {
      if ( filter )
        Scaleform::RefCountImpl::AddRef(filter);
      v6->pObject = (Scaleform::Render::Filter *)filter;
    }
    if ( filter )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)filter);
  }
}
