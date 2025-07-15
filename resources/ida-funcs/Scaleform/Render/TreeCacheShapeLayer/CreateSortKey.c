Scaleform::Render::SortKey *__cdecl Scaleform::Render::TreeCacheShapeLayer::CreateSortKey(
        Scaleform::Render::SortKey *result,
        Scaleform::Render::TreeCacheNode *refNode,
        Scaleform::Render::ShapeMeshProvider *provider,
        unsigned int drawLayer,
        __int16 flags,
        Scaleform::Ptr<Scaleform::Render::Image> *gradientImage,
        float morphRatio)
{
  Scaleform::Render::TreeCacheNode *v7; // eax
  char v8; // cl
  unsigned __int16 v9; // dx
  Scaleform::Render::MeshProvider *v10; // esi
  Scaleform::Render::HAL *HAL; // eax
  Scaleform::Render::TextureManager *v13; // edi
  Scaleform::Render::PrimitiveFillManager *PrimitiveFillManager; // ebx
  Scaleform::Render::PrimitiveFill *v15; // esi
  unsigned int meshGenFlags; // [esp+2Ch] [ebp-18h]
  Scaleform::Render::FillData fillData; // [esp+30h] [ebp-14h] BYREF
  bool is3D; // [esp+58h] [ebp+14h]

  meshGenFlags = (flags & 0xC) == 4;
  if ( (flags & 0x40) != 0 )
    meshGenFlags = 2;
  if ( (flags & 0x80u) != 0 )
    meshGenFlags |= 8u;
  v7 = refNode;
  v8 = (flags & 0x200) != 0;
  do
  {
    v9 = v7->Flags;
    v7 = v7->pParent;
    v8 |= (v9 & 0x200) != 0;
  }
  while ( v7 && !v8 );
  is3D = v8;
  v10 = &provider->Scaleform::Render::MeshProvider;
  if ( provider->GetFillCount(&provider->Scaleform::Render::MeshProvider, drawLayer, meshGenFlags) <= 1 )
  {
    HAL = Scaleform::Render::TreeCacheNode::GetHAL(refNode);
    v13 = HAL->GetTextureManager(HAL);
    PrimitiveFillManager = Scaleform::Render::TreeCacheNode::GetPrimitiveFillManager(refNode);
    Scaleform::Render::FillData::FillData(&fillData, Fill_VColor);
    v10->GetFillData(v10, &fillData, drawLayer, 0, meshGenFlags);
    v15 = Scaleform::Render::PrimitiveFillManager::CreateFill(
            PrimitiveFillManager,
            &fillData,
            gradientImage,
            v13,
            morphRatio);
    Scaleform::Render::SortKey::SortKey(result, v15, is3D);
    if ( v15 )
      Scaleform::RefCountNTSImpl::Release(v15);
    return result;
  }
  else
  {
    Scaleform::Render::SortKey::SortKey(result, v10, is3D);
    return result;
  }
}
