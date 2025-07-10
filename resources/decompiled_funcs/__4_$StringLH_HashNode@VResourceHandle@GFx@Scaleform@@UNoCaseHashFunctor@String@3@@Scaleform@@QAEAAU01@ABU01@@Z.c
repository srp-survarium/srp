Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor> *__thiscall Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::operator=(
        Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor> *this,
        const Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor> *__that)
{
  Scaleform::GFx::Resource *pResource; // ecx
  Scaleform::GFx::Resource *v4; // ecx

  Scaleform::String::operator=(&this->First, &__that->First);
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
