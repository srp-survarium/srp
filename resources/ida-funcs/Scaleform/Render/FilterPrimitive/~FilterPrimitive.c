void __thiscall Scaleform::Render::FilterPrimitive::~FilterPrimitive(Scaleform::Render::FilterPrimitive *this)
{
  Scaleform::Ptr<Scaleform::Render::RenderTarget> *CacheResults; // esi
  int v3; // edi
  bool *p_MaskPresent; // esi
  int i; // edi
  int v6; // ecx
  Scaleform::Render::MatrixPoolImpl::EntryHandle *pHandle; // eax
  Scaleform::RefCountVImpl *pObject; // ecx

  this->Scaleform::RefCountBase<Scaleform::Render::FilterPrimitive,68>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,68>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::Render::FilterPrimitive_vtbl *)&Scaleform::Render::FilterPrimitive::`vftable'{for `Scaleform::RefCountBase<Scaleform::Render::FilterPrimitive,68>'};
  this->Scaleform::Render::RenderQueueItem::Interface::__vftable = (Scaleform::Render::RenderQueueItem::Interface_vtbl *)&Scaleform::Render::FilterPrimitive::`vftable'{for `Scaleform::Render::RenderQueueItem::Interface'};
  CacheResults = this->CacheResults;
  v3 = 2;
  do
  {
    if ( CacheResults->pObject )
      CacheResults->pObject->Release(CacheResults->pObject);
    CacheResults->pObject = 0;
    ++CacheResults;
    --v3;
  }
  while ( v3 );
  p_MaskPresent = &this->MaskPresent;
  for ( i = 1; i >= 0; --i )
  {
    v6 = *((_DWORD *)p_MaskPresent - 1);
    p_MaskPresent -= 4;
    if ( v6 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 8))(v6);
  }
  pHandle = this->FilterArea.pHandle;
  if ( pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
    Scaleform::Render::MatrixPoolImpl::DataHeader::Release(pHandle->pHeader);
  pObject = (Scaleform::RefCountVImpl *)this->pFilters.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->Scaleform::Render::RenderQueueItem::Interface::__vftable = (Scaleform::Render::RenderQueueItem::Interface_vtbl *)&Scaleform::Render::RenderQueueItem::Interface::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}
