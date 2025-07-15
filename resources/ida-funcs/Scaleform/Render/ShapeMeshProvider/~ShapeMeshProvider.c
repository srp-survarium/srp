void __thiscall Scaleform::Render::ShapeMeshProvider::~ShapeMeshProvider(Scaleform::Render::ShapeMeshProvider *this)
{
  unsigned int v2; // edi
  Scaleform::Render::ShapeMeshProvider::DrawLayerType *Data; // eax
  unsigned int Size; // ecx
  unsigned int *p_StrokeStyle; // eax
  Scaleform::AmpServer *Instance; // eax
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::RefCountVImpl *v8; // ecx

  v2 = 0;
  this->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::RefCountBase<Scaleform::Render::MeshProvider_RCImpl,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::Render::ShapeMeshProvider_vtbl *)&Scaleform::Render::ShapeMeshProvider::`vftable'{for `Scaleform::RefCountBase<Scaleform::Render::MeshProvider_RCImpl,2>'};
  this->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::Render::MeshProvider::__vftable = (Scaleform::Render::MeshProvider_vtbl *)&Scaleform::Render::ShapeMeshProvider::`vftable'{for `Scaleform::Render::MeshProvider'};
  if ( this->DrawLayers.Data.Size )
  {
    Data = this->DrawLayers.Data.Data;
    Size = this->DrawLayers.Data.Size;
    p_StrokeStyle = &Data->StrokeStyle;
    do
    {
      if ( *p_StrokeStyle )
        ++v2;
      p_StrokeStyle += 5;
      --Size;
    }
    while ( Size );
  }
  Instance = Scaleform::AmpServer::GetInstance();
  Instance->RemoveStrokes(Instance, v2);
  pObject = (Scaleform::RefCountVImpl *)this->pMorphData.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  v8 = (Scaleform::RefCountVImpl *)this->pShapeData.pObject;
  if ( v8 )
    Scaleform::RefCountImpl::Release(v8);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->FillToStyleTable.Data.Data);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->DrawLayers.Data.Data);
  this->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::RefCountBase<Scaleform::Render::MeshProvider_RCImpl,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::Render::ShapeMeshProvider_vtbl *)&Scaleform::Render::MeshProvider_KeySupport::`vftable'{for `Scaleform::RefCountBase<Scaleform::Render::MeshProvider_RCImpl,2>'};
  this->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::Render::MeshProvider::__vftable = (Scaleform::Render::MeshProvider_vtbl *)&Scaleform::Render::MeshProvider_KeySupport::`vftable'{for `Scaleform::Render::MeshProvider'};
  Scaleform::Render::MeshKeySetHandle::releaseCache(&this->hKeySet);
  this->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::Render::MeshProvider::__vftable = (Scaleform::Render::MeshProvider_vtbl *)&Scaleform::Render::MeshProvider::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}
