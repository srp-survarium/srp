Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp> *__thiscall Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::operator=(
        Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp> *this,
        const Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp> *__that)
{
  Scaleform::GFx::Resource *pResource; // ecx
  Scaleform::GFx::Resource *v4; // ecx

  this->First.Id = __that->First.Id;
  if ( __that->Second.HType == RH_Pointer )
  {
    pResource = __that->Second.pResource;
    if ( pResource )
      Scaleform::RefCountImpl::AddRef(pResource);
  }
  if ( this->Second.HType == RH_Pointer )
  {
    v4 = this->Second.pResource;
    if ( v4 )
      Scaleform::GFx::Resource::Release(v4);
  }
  this->Second = __that->Second;
  return this;
}
