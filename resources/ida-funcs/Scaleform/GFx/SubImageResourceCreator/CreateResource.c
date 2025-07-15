char __thiscall Scaleform::GFx::SubImageResourceCreator::CreateResource(
        Scaleform::GFx::SubImageResourceCreator *this,
        const Scaleform::Render::Rect<unsigned long> *hdata,
        Scaleform::GFx::ResourceBindData *pbindData,
        Scaleform::GFx::LoadStates *pls,
        Scaleform::MemoryHeap *pbindHeap)
{
  Scaleform::GFx::ResourceBinding *pBinding; // ecx
  unsigned int x2; // eax
  Scaleform::GFx::ResourceBinding *v8; // ecx
  Scaleform::GFx::Resource *pObject; // esi
  Scaleform::GFx::SubImageResource *v10; // eax
  Scaleform::GFx::Resource *v11; // eax
  Scaleform::GFx::Resource *v12; // esi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF> >::TableType v14; // [esp+10h] [ebp-10h] BYREF
  Scaleform::GFx::ResourceBindData v15; // [esp+18h] [ebp-8h] BYREF
  unsigned int y2; // [esp+24h] [ebp+4h]

  y2 = hdata->y2;
  if ( !y2 )
  {
    pBinding = pbindData->pBinding;
    x2 = hdata->x2;
    v14.EntryCount = 0;
    v14.SizeMask = 0;
    Scaleform::GFx::MovieDataDef::LoadTaskData::GetResourceHandle(
      *(Scaleform::GFx::MovieDataDef::LoadTaskData **)(*(_DWORD *)(pBinding->pOwnerDefRes[2].RefCount.Value + 12) + 32),
      &v14,
      (Scaleform::GFx::ResourceId)x2);
    v8 = pbindData->pBinding;
    if ( v14.EntryCount )
    {
      v15.pResource.pObject = 0;
      v15.pBinding = 0;
      Scaleform::GFx::ResourceBinding::GetResourceData(v8, &v15, v14.SizeMask);
      pObject = v15.pResource.pObject;
      if ( v15.pResource.pObject )
        Scaleform::GFx::Resource::Release(v15.pResource.pObject);
    }
    else
    {
      pObject = (Scaleform::GFx::Resource *)v14.SizeMask;
    }
    if ( pObject && (pObject->GetResourceTypeCode(pObject) & 0xFF00) == 0x100 )
      y2 = (unsigned int)pObject;
    if ( !v14.EntryCount && v14.SizeMask )
      Scaleform::GFx::Resource::Release((Scaleform::GFx::Resource *)v14.SizeMask);
    if ( !y2 )
      return 0;
  }
  v10 = (Scaleform::GFx::SubImageResource *)pbindHeap->Alloc(pbindHeap, 72, 0);
  if ( v10 )
  {
    Scaleform::GFx::SubImageResource::SubImageResource(v10, y2, 0, hdata + 1, pbindHeap);
    v12 = v11;
  }
  else
  {
    v12 = 0;
  }
  if ( pbindData->pResource.pObject )
    Scaleform::GFx::Resource::Release(pbindData->pResource.pObject);
  pbindData->pResource.pObject = v12;
  return 1;
}
