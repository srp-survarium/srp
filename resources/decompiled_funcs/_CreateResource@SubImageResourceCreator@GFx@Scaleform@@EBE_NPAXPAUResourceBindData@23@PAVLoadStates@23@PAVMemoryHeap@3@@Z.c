char __thiscall Scaleform::GFx::SubImageResourceCreator::CreateResource(
        Scaleform::GFx::SubImageResourceCreator *this,
        const Scaleform::Render::Rect<unsigned long> *hdata,
        Scaleform::GFx::ResourceBindData *pbindData,
        Scaleform::GFx::LoadStates *pls,
        Scaleform::MemoryHeap *pbindHeap)
{
  Scaleform::GFx::ResourceBinding *pBinding; // ecx
  Scaleform::GFx::ResourceId v7; // eax
  Scaleform::GFx::ResourceBinding *v8; // ecx
  Scaleform::GFx::Resource *pObject; // esi
  Scaleform::GFx::SubImageResource *v10; // eax
  Scaleform::GFx::Resource *v11; // eax
  Scaleform::GFx::Resource *v12; // esi
  Scaleform::GFx::ResourceHandle rh; // [esp+10h] [ebp-10h] BYREF
  Scaleform::GFx::ResourceBindData pdata; // [esp+18h] [ebp-8h] BYREF
  Scaleform::GFx::ImageResource *pimageRes; // [esp+24h] [ebp+4h]

  pimageRes = (Scaleform::GFx::ImageResource *)hdata->y2;
  if ( !pimageRes )
  {
    pBinding = pbindData->pBinding;
    v7.Id = hdata->x2;
    rh.HType = RH_Pointer;
    rh.BindIndex = 0;
    Scaleform::GFx::MovieDataDef::LoadTaskData::GetResourceHandle(
      *(Scaleform::GFx::MovieDataDef::LoadTaskData **)(*(_DWORD *)(pBinding->pOwnerDefRes[2].RefCount.Value + 12) + 32),
      (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF> >::TableType *)&rh,
      v7);
    v8 = pbindData->pBinding;
    if ( rh.HType )
    {
      pdata.pResource.pObject = 0;
      pdata.pBinding = 0;
      Scaleform::GFx::ResourceBinding::GetResourceData(v8, &pdata, rh.BindIndex);
      pObject = pdata.pResource.pObject;
      if ( pdata.pResource.pObject )
        Scaleform::GFx::Resource::Release(pdata.pResource.pObject);
    }
    else
    {
      pObject = rh.pResource;
    }
    if ( pObject && (pObject->GetResourceTypeCode(pObject) & 0xFF00) == 0x100 )
      pimageRes = (Scaleform::GFx::ImageResource *)pObject;
    if ( rh.HType == RH_Pointer && rh.BindIndex )
      Scaleform::GFx::Resource::Release(rh.pResource);
    if ( !pimageRes )
      return 0;
  }
  v10 = (Scaleform::GFx::SubImageResource *)pbindHeap->Alloc(pbindHeap, 72, 0);
  if ( v10 )
  {
    Scaleform::GFx::SubImageResource::SubImageResource(v10, (int)pimageRes, 0, hdata + 1, pbindHeap);
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
