void __thiscall Scaleform::GFx::TextField::SetFilters(
        Scaleform::GFx::TextField *this,
        Scaleform::GFx::Resource *filters)
{
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::GFx::Resource_vtbl *i; // edi
  Scaleform::Render::Text::DocView *v5; // eax
  Scaleform::Render::Text::TextFilter *p_Filter; // esi
  Scaleform::Render::TreeText *RenderNode; // eax
  Scaleform::Render::Text::TextFilter __that; // [esp+8h] [ebp-48h] BYREF

  if ( filters )
  {
    Scaleform::RefCountImpl::AddRef(filters);
    pObject = (Scaleform::RefCountVImpl *)this->pFilters.pObject;
    if ( pObject )
      Scaleform::RefCountImpl::Release(pObject);
    this->pFilters.pObject = (Scaleform::Render::FilterSet *)filters;
    Scaleform::Render::Text::TextFilter::TextFilter(&__that);
    for ( i = 0; i < filters[1].__vftable; i = (Scaleform::GFx::Resource_vtbl *)((char *)i + 1) )
    {
      if ( *((_DWORD *)&filters->pLib->__vftable + (_DWORD)i) )
        Scaleform::Render::Text::TextFilter::LoadFilterDesc(
          &__that,
          *((const Scaleform::Render::Filter **)&filters->pLib->__vftable + (_DWORD)i));
    }
    v5 = this->pDocument.pObject;
    if ( v5 )
    {
      p_Filter = &v5->Filter;
      if ( !Scaleform::Render::Text::TextFilter::operator==(&v5->Filter, &__that) )
      {
        Scaleform::Render::Text::TextFilter::operator=(p_Filter, &__that);
        RenderNode = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
        Scaleform::Render::TreeText::NotifyLayoutChanged(RenderNode);
      }
    }
    Scaleform::RefCountNTSImplCore::~RefCountNTSImplCore(&__that);
  }
}
