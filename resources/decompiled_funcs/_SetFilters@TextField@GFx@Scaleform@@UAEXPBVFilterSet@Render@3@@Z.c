void __thiscall Scaleform::GFx::TextField::SetFilters(
        Scaleform::GFx::TextField *this,
        Scaleform::GFx::Resource *filters)
{
  Scaleform::RefCountVImpl *pObject; // ecx
  unsigned int i; // edi
  Scaleform::Render::Text::DocView *v5; // eax
  Scaleform::Render::Text::TextFilter *p_Filter; // esi
  Scaleform::Render::TreeText *RenderNode; // eax
  Scaleform::Render::Text::TextFilter f; // [esp+8h] [ebp-48h] BYREF

  if ( filters )
  {
    Scaleform::RefCountImpl::AddRef(filters);
    pObject = (Scaleform::RefCountVImpl *)this->pFilters.pObject;
    if ( pObject )
      Scaleform::RefCountImpl::Release(pObject);
    this->pFilters.pObject = (Scaleform::Render::FilterSet *)filters;
    Scaleform::Render::Text::TextFilter::TextFilter(&f);
    for ( i = 0; (Scaleform::GFx::Resource_vtbl *)i < filters[1].__vftable; ++i )
    {
      if ( *((_DWORD *)&filters->pLib->__vftable + i) )
        Scaleform::Render::Text::TextFilter::LoadFilterDesc(
          &f,
          *((const Scaleform::Render::Filter **)&filters->pLib->__vftable + i));
    }
    v5 = this->pDocument.pObject;
    if ( v5 )
    {
      p_Filter = &v5->Filter;
      if ( !Scaleform::Render::Text::TextFilter::operator==(&v5->Filter, &f) )
      {
        Scaleform::Render::Text::TextFilter::operator=(p_Filter, &f);
        RenderNode = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
        Scaleform::Render::TreeText::NotifyLayoutChanged(RenderNode);
      }
    }
    Scaleform::RefCountNTSImplCore::~RefCountNTSImplCore(&f);
  }
}
