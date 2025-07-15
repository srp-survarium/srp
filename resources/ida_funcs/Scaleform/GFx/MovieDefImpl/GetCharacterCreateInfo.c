Scaleform::GFx::CharacterCreateInfo *__thiscall Scaleform::GFx::MovieDefImpl::GetCharacterCreateInfo(
        Scaleform::GFx::MovieDefImpl *this,
        Scaleform::GFx::ResourceBinding *result,
        Scaleform::GFx::ResourceId rid)
{
  Scaleform::GFx::CharacterCreateInfo *v3; // esi
  Scaleform::GFx::MovieDataDef::LoadTaskData *pObject; // ecx
  Scaleform::GFx::Resource *ResourceAndBinding; // edi
  unsigned int (__thiscall *GetResourceTypeCode)(Scaleform::GFx::Resource *); // edx
  unsigned int Id; // [esp-4h] [ebp-18h]
  Scaleform::GFx::ResourceHandle rh; // [esp+Ch] [ebp-8h] BYREF

  v3 = (Scaleform::GFx::CharacterCreateInfo *)result;
  Id = rid.Id;
  pObject = this->pBindData.pObject->pDataDef.pObject->pData.pObject;
  rh.HType = RH_Pointer;
  rh.BindIndex = 0;
  result->pHeap = 0;
  v3->pBindDefImpl = 0;
  v3->pResource = 0;
  if ( Scaleform::GFx::MovieDataDef::LoadTaskData::GetResourceHandle(
         pObject,
         (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF> >::TableType *)&rh,
         (Scaleform::GFx::ResourceId)Id) )
  {
    ResourceAndBinding = Scaleform::GFx::ResourceHandle::GetResourceAndBinding(
                           &rh,
                           &this->pBindData.pObject->ResourceBinding,
                           &result);
    if ( ResourceAndBinding )
    {
      GetResourceTypeCode = ResourceAndBinding->GetResourceTypeCode;
      v3->pResource = ResourceAndBinding;
      if ( (GetResourceTypeCode(ResourceAndBinding) & 0x8000) != 0 )
      {
        v3->pBindDefImpl = result->pOwnerDefImpl;
        v3->pCharDef = (Scaleform::GFx::CharacterDef *)ResourceAndBinding;
      }
    }
  }
  if ( rh.HType == RH_Pointer && rh.BindIndex )
    Scaleform::GFx::Resource::Release(rh.pResource);
  return v3;
}
