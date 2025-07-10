char __thiscall Scaleform::Render::TreeCacheShapeLayer::updateMeshKey(
        Scaleform::Render::TreeCacheShapeLayer *this,
        Scaleform::Render::Renderer2DImpl *r2D,
        Scaleform::Render::ShapeMeshProvider *provider,
        float morphRatio,
        const Scaleform::Render::Matrix2x4<float> *viewMatrix,
        unsigned int meshGenFlags,
        unsigned int *meshKeyFlags)
{
  unsigned int Layer; // esi
  int v9; // edi
  unsigned int v10; // eax
  Scaleform::Render::MeshKeyManager *pObject; // edi
  Scaleform::Render::MeshKey *v12; // ecx
  Scaleform::Render::MeshKey *MatchingKey; // eax
  Scaleform::Render::MeshKey *v14; // edi
  Scaleform::Render::ComplexMesh *v15; // eax
  Scaleform::Render::MeshBase *v16; // eax
  Scaleform::Render::MeshBase *v17; // esi
  Scaleform::Render::Mesh *v18; // eax
  Scaleform::Render::MeshBase *v19; // eax
  Scaleform::RefCountVImpl *v20; // ecx
  Scaleform::Render::Scale9GridData *v22; // eax
  Scaleform::GFx::Resource *v23; // eax
  Scaleform::GFx::Resource *v24; // esi
  Scaleform::Render::MeshKey *v25; // ecx
  const Scaleform::Render::ToleranceParams *p_Tolerances; // [esp+31Ch] [ebp-F0h]
  unsigned int v27; // [esp+320h] [ebp-ECh]
  int v28; // [esp+324h] [ebp-E8h] BYREF
  int v29; // [esp+328h] [ebp-E4h] BYREF
  Scaleform::Render::Scale9GridData __that; // [esp+32Ch] [ebp-E0h] BYREF
  float v31[20]; // [esp+3BCh] [ebp-50h] BYREF

  p_Tolerances = &r2D->Tolerances;
  Layer = this->Layer;
  v9 = 0;
  if ( (meshGenFlags & 1) != 0 )
    v9 = 64;
  if ( (meshGenFlags & 2) != 0 )
    v9 |= 0x80u;
  __that.RefCount = 1;
  __that.__vftable = (Scaleform::Render::Scale9GridData_vtbl *)&Scaleform::Render::Matrix4x4Ref<float>::`vftable';
  v10 = v9
      | Scaleform::Render::TreeCacheShapeLayer::calcMeshKey(this, provider, viewMatrix, Layer, v31, &__that, morphRatio);
  v27 = v10;
  if ( meshKeyFlags )
    *meshKeyFlags = v10;
  pObject = r2D->pMeshKeyManager.pObject;
  v12 = this->pMeshKey.pObject;
  if ( v12 )
  {
    if ( Scaleform::Render::MeshKey::Match(v12, Layer, v10, v31, p_Tolerances) )
    {
LABEL_23:
      Scaleform::RefCountImplCore::~RefCountImplCore(&__that);
      return 0;
    }
    MatchingKey = Scaleform::Render::MeshKeyManager::CreateMatchingKey(
                    pObject,
                    this->pMeshKey.pObject->pKeySet,
                    Layer,
                    v27,
                    v31,
                    p_Tolerances);
  }
  else
  {
    MatchingKey = Scaleform::Render::MeshKeyManager::CreateMatchingKey(pObject, provider, Layer, v10, v31, p_Tolerances);
  }
  v14 = MatchingKey;
  if ( !MatchingKey )
    goto LABEL_23;
  if ( MatchingKey->pMesh.pObject )
    goto LABEL_30;
  if ( !this->ComplexShape )
  {
    v29 = 70;
    v18 = (Scaleform::Render::Mesh *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                       Scaleform::Memory::pGlobalHeap,
                                       this,
                                       176,
                                       &v29);
    if ( v18 )
    {
      Scaleform::Render::Mesh::Mesh(v18, r2D, v14->pKeySet, viewMatrix, morphRatio, Layer, meshGenFlags);
      v17 = v19;
      goto LABEL_19;
    }
LABEL_18:
    v17 = 0;
    goto LABEL_19;
  }
  v28 = 70;
  v15 = (Scaleform::Render::ComplexMesh *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                            Scaleform::Memory::pGlobalHeap,
                                            this,
                                            224,
                                            &v28);
  if ( !v15 )
    goto LABEL_18;
  Scaleform::Render::ComplexMesh::ComplexMesh(
    v15,
    r2D,
    v14->pKeySet,
    &r2D->FillManager,
    viewMatrix,
    morphRatio,
    Layer,
    meshGenFlags);
  v17 = v16;
LABEL_19:
  v20 = (Scaleform::RefCountVImpl *)v14->pMesh.pObject;
  if ( v20 )
    Scaleform::RefCountImpl::Release(v20);
  v14->pMesh.pObject = v17;
  if ( !v17 )
  {
    Scaleform::Render::MeshKey::Release(v14);
    goto LABEL_23;
  }
  if ( (v27 & 0x10) != 0 )
  {
    v22 = (Scaleform::Render::Scale9GridData *)Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::operator new(
                                                 0x90u,
                                                 (Scaleform::MemAddressStub *)this);
    if ( v22 )
    {
      Scaleform::Render::Scale9GridData::Scale9GridData(v22, &__that);
      v24 = v23;
    }
    else
    {
      v24 = 0;
    }
    Scaleform::Render::MeshBase::SetScale9Grid(v14->pMesh.pObject, v24);
    if ( v24 )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v24);
  }
LABEL_30:
  v25 = this->pMeshKey.pObject;
  if ( v25 )
    Scaleform::Render::MeshKey::Release(v25);
  this->pMeshKey.pObject = v14;
  Scaleform::RefCountImplCore::~RefCountImplCore(&__that);
  return 1;
}
