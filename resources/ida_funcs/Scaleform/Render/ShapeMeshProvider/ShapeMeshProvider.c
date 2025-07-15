void __thiscall Scaleform::Render::ShapeMeshProvider::ShapeMeshProvider(
        Scaleform::Render::ShapeMeshProvider *this,
        Scaleform::GFx::Resource *shape,
        Scaleform::GFx::Resource *shapeMorph)
{
  Scaleform::Render::MorphShapeData *v4; // eax
  Scaleform::Render::MorphShapeData *v5; // eax
  Scaleform::Render::MorphShapeData *v6; // edi
  Scaleform::RefCountVImpl *pObject; // ecx
  int v8; // [esp+Ch] [ebp-4h] BYREF

  this->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::RefCountBase<Scaleform::Render::MeshProvider_RCImpl,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::Render::ShapeMeshProvider_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::Render::MeshProvider::__vftable = (Scaleform::Render::MeshProvider_vtbl *)&Scaleform::Render::MeshProvider::`vftable';
  this->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::RefCountBase<Scaleform::Render::MeshProvider_RCImpl,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::Render::ShapeMeshProvider_vtbl *)&Scaleform::Render::MeshProvider_KeySupport::`vftable'{for `Scaleform::RefCountBase<Scaleform::Render::MeshProvider_RCImpl,2>'};
  this->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::Render::MeshProvider::__vftable = (Scaleform::Render::MeshProvider_vtbl *)&Scaleform::Render::MeshProvider_KeySupport::`vftable'{for `Scaleform::Render::MeshProvider'};
  this->hKeySet.pManager.Value = 0;
  this->hKeySet.pKeySet = 0;
  this->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::RefCountBase<Scaleform::Render::MeshProvider_RCImpl,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::Render::ShapeMeshProvider_vtbl *)&Scaleform::Render::ShapeMeshProvider::`vftable'{for `Scaleform::RefCountBase<Scaleform::Render::MeshProvider_RCImpl,2>'};
  this->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::Render::MeshProvider::__vftable = (Scaleform::Render::MeshProvider_vtbl *)&Scaleform::Render::ShapeMeshProvider::`vftable'{for `Scaleform::Render::MeshProvider'};
  this->DrawLayers.Data.Data = 0;
  this->DrawLayers.Data.Size = 0;
  this->DrawLayers.Data.Policy.Capacity = 0;
  this->FillToStyleTable.Data.Data = 0;
  this->FillToStyleTable.Data.Size = 0;
  this->FillToStyleTable.Data.Policy.Capacity = 0;
  if ( shape )
    Scaleform::RefCountImpl::AddRef(shape);
  this->pShapeData.pObject = (Scaleform::Render::ShapeDataInterface *)shape;
  this->IdentityBounds.x1 = 0.0;
  this->IdentityBounds.y1 = 0.0;
  this->pMorphData.pObject = 0;
  this->IdentityBounds.x2 = 0.0;
  this->IdentityBounds.y2 = 0.0;
  this->GradientMorph = 0;
  this->Strokes = 0;
  if ( shapeMorph )
  {
    v8 = 2;
    v4 = (Scaleform::Render::MorphShapeData *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                Scaleform::Memory::pGlobalHeap,
                                                this,
                                                156,
                                                &v8);
    if ( v4 )
    {
      Scaleform::Render::MorphShapeData::MorphShapeData(v4, shapeMorph);
      v6 = v5;
    }
    else
    {
      v6 = 0;
    }
    pObject = (Scaleform::RefCountVImpl *)this->pMorphData.pObject;
    if ( pObject )
      Scaleform::RefCountImpl::Release(pObject);
    this->pMorphData.pObject = v6;
    Scaleform::Render::ShapeMeshProvider::createMorphData(this);
  }
  Scaleform::Render::ShapeMeshProvider::acquireShapeData(this);
}


void __thiscall Scaleform::Render::ShapeMeshProvider::ShapeMeshProvider(Scaleform::Render::ShapeMeshProvider *this)
{
  this->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::RefCountBase<Scaleform::Render::MeshProvider_RCImpl,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::Render::ShapeMeshProvider_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::Render::MeshProvider::__vftable = (Scaleform::Render::MeshProvider_vtbl *)&Scaleform::Render::MeshProvider::`vftable';
  this->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::RefCountBase<Scaleform::Render::MeshProvider_RCImpl,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::Render::ShapeMeshProvider_vtbl *)&Scaleform::Render::MeshProvider_KeySupport::`vftable'{for `Scaleform::RefCountBase<Scaleform::Render::MeshProvider_RCImpl,2>'};
  this->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::Render::MeshProvider::__vftable = (Scaleform::Render::MeshProvider_vtbl *)&Scaleform::Render::MeshProvider_KeySupport::`vftable'{for `Scaleform::Render::MeshProvider'};
  this->hKeySet.pManager.Value = 0;
  this->hKeySet.pKeySet = 0;
  this->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::RefCountBase<Scaleform::Render::MeshProvider_RCImpl,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::Render::ShapeMeshProvider_vtbl *)&Scaleform::Render::ShapeMeshProvider::`vftable'{for `Scaleform::RefCountBase<Scaleform::Render::MeshProvider_RCImpl,2>'};
  this->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::Render::MeshProvider::__vftable = (Scaleform::Render::MeshProvider_vtbl *)&Scaleform::Render::ShapeMeshProvider::`vftable'{for `Scaleform::Render::MeshProvider'};
  this->DrawLayers.Data.Data = 0;
  this->DrawLayers.Data.Size = 0;
  this->DrawLayers.Data.Policy.Capacity = 0;
  this->FillToStyleTable.Data.Data = 0;
  this->FillToStyleTable.Data.Size = 0;
  this->FillToStyleTable.Data.Policy.Capacity = 0;
  this->IdentityBounds.x1 = 0.0;
  this->IdentityBounds.y1 = 0.0;
  this->pShapeData.pObject = 0;
  this->IdentityBounds.x2 = 0.0;
  this->pMorphData.pObject = 0;
  this->IdentityBounds.y2 = 0.0;
}
