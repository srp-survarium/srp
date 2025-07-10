void __thiscall Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::operator=(
        Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor> *this,
        const Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeRef *src)
{
  const Scaleform::GFx::ResourceHandle *pSecond; // edi
  Scaleform::GFx::Resource *pResource; // ecx
  Scaleform::GFx::Resource *v5; // ecx

  Scaleform::String::operator=(&this->First, src->pFirst);
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
