void __thiscall Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::operator=(
        Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp> *this,
        const Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeRef *src)
{
  const Scaleform::GFx::ResourceHandle *pSecond; // edi
  Scaleform::GFx::Resource *pResource; // ecx
  Scaleform::GFx::Resource *v5; // ecx

  this->First.Id = src->pFirst->Id;
  pSecond = src->pSecond;
  if ( pSecond->HType == RH_Pointer )
  {
    pResource = pSecond->pResource;
    if ( pResource )
      Scaleform::RefCountImpl::AddRef(pResource);
  }
  if ( this->Second.HType == RH_Pointer )
  {
    v5 = this->Second.pResource;
    if ( v5 )
      Scaleform::GFx::Resource::Release(v5);
  }
  this->Second.HType = pSecond->HType;
  this->Second.BindIndex = pSecond->BindIndex;
}
