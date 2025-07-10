char __thiscall Scaleform::GFx::MovieDefImpl::BindTaskData::SetResourceBindData(
        Scaleform::GFx::MovieDefImpl::BindTaskData *this,
        Scaleform::GFx::ResourceId rid,
        Scaleform::GFx::ResourceBindData *bindData,
        const char *pimportSymbolName)
{
  Scaleform::GFx::MovieDataDef::LoadTaskData *pObject; // ecx
  Scaleform::GFx::Resource *pResource; // edi
  Scaleform::GFx::ResourceHandle rh; // [esp+8h] [ebp-8h] BYREF

  pObject = this->pDataDef.pObject->pData.pObject;
  rh.HType = RH_Pointer;
  rh.BindIndex = 0;
  if ( Scaleform::GFx::MovieDataDef::LoadTaskData::GetResourceHandle(
         pObject,
         (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF> >::TableType *)&rh,
         rid) )
  {
    pResource = rh.pResource;
    Scaleform::GFx::ResourceBinding::SetBindData(&this->ResourceBinding, rh.BindIndex, bindData);
    if ( rh.HType == RH_Pointer )
    {
      if ( pResource )
        Scaleform::GFx::Resource::Release(pResource);
    }
    return 1;
  }
  else
  {
    if ( rh.HType == RH_Pointer && rh.BindIndex )
      Scaleform::GFx::Resource::Release(rh.pResource);
    return 0;
  }
}
