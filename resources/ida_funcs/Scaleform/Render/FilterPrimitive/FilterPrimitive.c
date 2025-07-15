void __thiscall Scaleform::Render::FilterPrimitive::FilterPrimitive(
        Scaleform::Render::FilterPrimitive *this,
        Scaleform::Render::HAL *hal,
        Scaleform::GFx::Resource *filters,
        bool maskPresent)
{
  this->Scaleform::RefCountBase<Scaleform::Render::FilterPrimitive,68>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,68>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::Render::FilterPrimitive_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->Scaleform::Render::RenderQueueItem::Interface::__vftable = (Scaleform::Render::RenderQueueItem::Interface_vtbl *)&Scaleform::Render::RenderQueueItem::Interface::`vftable';
  this->Scaleform::RefCountBase<Scaleform::Render::FilterPrimitive,68>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,68>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::Render::FilterPrimitive_vtbl *)&Scaleform::Render::FilterPrimitive::`vftable'{for `Scaleform::RefCountBase<Scaleform::Render::FilterPrimitive,68>'};
  this->Scaleform::Render::RenderQueueItem::Interface::__vftable = (Scaleform::Render::RenderQueueItem::Interface_vtbl *)&Scaleform::Render::FilterPrimitive::`vftable'{for `Scaleform::Render::RenderQueueItem::Interface'};
  this->pHAL = hal;
  if ( filters )
    Scaleform::RefCountImpl::AddRef(filters);
  this->pFilters.pObject = (Scaleform::Render::FilterSet *)filters;
  this->FilterArea.pHandle = &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle;
  this->CacheResults[0].pObject = 0;
  this->CacheResults[1].pObject = 0;
  this->MaskPresent = maskPresent;
  Scaleform::Render::FilterPrimitive::SetCacheResults(this, Cache_Mesh, 0, 0);
}
