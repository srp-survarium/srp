char __userpurge Scaleform::GFx::MovieDefImpl::BindTaskData::SetResourceBindData@<al>(
        Scaleform::GFx::MovieDefImpl::BindTaskData *this@<ecx>,
        int a2@<ebp>,
        Scaleform::GFx::ResourceId rid,
        Scaleform::GFx::ResourceBindData *bindData,
        const char *pimportSymbolName)
{
  Scaleform::GFx::MovieDataDef::LoadTaskData *pObject; // ecx
  Scaleform::GFx::Resource *SizeMask; // edi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF> >::TableType v9; // [esp+8h] [ebp-8h] BYREF

  pObject = this->pDataDef.pObject->pData.pObject;
  v9.EntryCount = 0;
  v9.SizeMask = 0;
  if ( Scaleform::GFx::MovieDataDef::LoadTaskData::GetResourceHandle(pObject, &v9, rid) )
  {
    SizeMask = (Scaleform::GFx::Resource *)v9.SizeMask;
    Scaleform::GFx::ResourceBinding::SetBindData(&this->ResourceBinding, a2, v9.SizeMask, bindData);
    if ( !v9.EntryCount )
    {
      if ( SizeMask )
        Scaleform::GFx::Resource::Release(SizeMask);
    }
    return 1;
  }
  else
  {
    if ( !v9.EntryCount && v9.SizeMask )
      Scaleform::GFx::Resource::Release((Scaleform::GFx::Resource *)v9.SizeMask);
    return 0;
  }
}
