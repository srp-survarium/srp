Scaleform::Render::TreeCacheNode *__usercall Scaleform::Render::TreeCacheShapeLayer::Create@<eax>(
        int a1@<edi>,
        Scaleform::Render::TreeCacheNode *pparent,
        Scaleform::Render::ShapeMeshProvider *provider,
        unsigned int drawLayer,
        __int16 flags,
        Scaleform::Render::TreeShape *shapeNode,
        Scaleform::Render::TreeShape *morphRatio)
{
  Scaleform::Render::TreeCacheShapeLayer *v7; // eax
  int v8; // eax
  int v9; // esi
  int v11; // ecx
  int v12; // eax
  Scaleform::Ptr<Scaleform::Render::Image> v13; // [esp+10h] [ebp-10h] BYREF
  int v14; // [esp+14h] [ebp-Ch] BYREF
  Scaleform::Render::SortKey v15; // [esp+18h] [ebp-8h] BYREF
  void *retaddr; // [esp+20h] [ebp+0h]

  v13.pObject = 0;
  Scaleform::Render::TreeCacheShapeLayer::CreateSortKey(
    &v15,
    pparent,
    provider,
    drawLayer,
    flags,
    &v13,
    *(float *)&morphRatio);
  v14 = 74;
  v7 = (Scaleform::Render::TreeCacheShapeLayer *)((int (__thiscall *)(Scaleform::MemoryHeap *, Scaleform::Render::TreeCacheNode *, int, int *, int))Scaleform::Memory::pGlobalHeap->AllocAutoHeap)(
                                                   Scaleform::Memory::pGlobalHeap,
                                                   pparent,
                                                   144,
                                                   &v14,
                                                   a1);
  if ( v7
    && (Scaleform::Render::TreeCacheShapeLayer::TreeCacheShapeLayer(
          v7,
          morphRatio,
          (const Scaleform::Render::SortKey *)&v15.Data,
          drawLayer,
          pparent->pRenderer2D,
          flags),
        (v9 = v8) != 0) )
  {
    v11 = v14;
    if ( v14 )
    {
      (*(void (__thiscall **)(int))(*(_DWORD *)v14 + 4))(v14);
      v11 = v14;
    }
    v12 = *(_DWORD *)(v9 + 132);
    if ( v12 )
    {
      (*(void (__thiscall **)(_DWORD))(*(_DWORD *)v12 + 8))(*(_DWORD *)(v9 + 132));
      v11 = v14;
    }
    *(_DWORD *)(v9 + 132) = v11;
    (*(void (__thiscall **)(void *, void *))(*(_DWORD *)v15.Data + 8))(v15.Data, retaddr);
    if ( v13.pObject )
      v13.pObject->Release(v13.pObject);
    return (Scaleform::Render::TreeCacheNode *)v9;
  }
  else
  {
    (*(void (__thiscall **)(void *, void *))(*(_DWORD *)v15.Data + 8))(v15.Data, retaddr);
    if ( v13.pObject )
      v13.pObject->Release(v13.pObject);
    return 0;
  }
}
