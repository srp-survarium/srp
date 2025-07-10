void __thiscall Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::operator=(
        Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> > *this,
        const Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >::NodeRef *src)
{
  const Scaleform::Ptr<Scaleform::GFx::AS2::Object> *pSecond; // edi
  Scaleform::GFx::AS2::Object *pObject; // ecx
  unsigned int RefCount; // eax

  this->First = *src->pFirst;
  pSecond = src->pSecond;
  if ( pSecond->pObject )
    pSecond->pObject->RefCount = (pSecond->pObject->RefCount + 1) & 0x8FFFFFFF;
  pObject = this->Second.pObject;
  if ( pObject )
  {
    RefCount = pObject->RefCount;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
    {
      pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
    }
    this->Second = (Scaleform::Ptr<Scaleform::GFx::AS2::Object>)pSecond->pObject;
  }
  else
  {
    this->Second = (Scaleform::Ptr<Scaleform::GFx::AS2::Object>)pSecond->pObject;
  }
}
