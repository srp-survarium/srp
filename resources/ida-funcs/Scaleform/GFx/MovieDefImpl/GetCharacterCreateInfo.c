Scaleform::GFx::ResourceBinding *__thiscall Scaleform::GFx::MovieDefImpl::GetCharacterCreateInfo(
        Scaleform::GFx::MovieDefImpl *this,
        Scaleform::GFx::ResourceBinding *result,
        Scaleform::GFx::ResourceId rid)
{
  Scaleform::GFx::ResourceBinding *v3; // esi
  Scaleform::GFx::MovieDataDef::LoadTaskData *pObject; // ecx
  Scaleform::GFx::Resource *ResourceAndBinding; // edi
  unsigned int (__thiscall *GetResourceTypeCode)(Scaleform::GFx::Resource *); // edx
  unsigned int Id; // [esp-4h] [ebp-18h]
  Scaleform::GFx::ResourceHandle v10; // [esp+Ch] [ebp-8h] BYREF

  v3 = result;
  Id = rid.Id;
  pObject = this->pBindData.pObject->pDataDef.pObject->pData.pObject;
  v10.HType = RH_Pointer;
  v10.BindIndex = 0;
  result->pHeap = 0;
  v3->ResourceCount = 0;
  v3->pResources = 0;
  if ( Scaleform::GFx::MovieDataDef::LoadTaskData::GetResourceHandle(
         pObject,
         (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF> >::TableType *)&v10,
         (Scaleform::GFx::ResourceId)Id) )
  {
    ResourceAndBinding = Scaleform::GFx::ResourceHandle::GetResourceAndBinding(
                           &v10,
                           &this->pBindData.pObject->ResourceBinding,
                           &result);
    if ( ResourceAndBinding )
    {
      GetResourceTypeCode = ResourceAndBinding->GetResourceTypeCode;
      v3->pResources = (Scaleform::GFx::ResourceBindData *volatile)ResourceAndBinding;
      if ( (GetResourceTypeCode(ResourceAndBinding) & 0x8000) != 0 )
      {
        v3->ResourceCount = (volatile unsigned int)result->pOwnerDefRes;
        v3->pHeap = (Scaleform::MemoryHeap *)ResourceAndBinding;
      }
    }
  }
  if ( v10.HType == RH_Pointer && v10.BindIndex )
    Scaleform::GFx::Resource::Release(v10.pResource);
  return v3;
}
