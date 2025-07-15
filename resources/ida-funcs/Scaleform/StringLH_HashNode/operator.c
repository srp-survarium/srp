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


void __thiscall Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::operator=(
        Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor> *this,
        const Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeRef *src)
{
  const Scaleform::Ptr<Scaleform::Render::Text::ImageDesc> *pSecond; // edi
  Scaleform::Render::Text::ImageDesc *pObject; // ecx

  Scaleform::String::operator=(&this->First, src->pFirst);
  pSecond = src->pSecond;
  if ( pSecond->pObject )
    ++pSecond->pObject->RefCount;
  pObject = this->Second.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  this->Second = (Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>)pSecond->pObject;
}
