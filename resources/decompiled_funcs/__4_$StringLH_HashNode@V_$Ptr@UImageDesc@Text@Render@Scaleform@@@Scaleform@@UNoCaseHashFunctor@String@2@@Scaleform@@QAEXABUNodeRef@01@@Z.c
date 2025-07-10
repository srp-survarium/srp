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
