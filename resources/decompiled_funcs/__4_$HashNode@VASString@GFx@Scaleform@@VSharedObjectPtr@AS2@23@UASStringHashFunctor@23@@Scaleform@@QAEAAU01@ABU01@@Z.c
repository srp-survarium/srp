Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor> *__thiscall Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::operator=(
        Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor> *this,
        const Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor> *__that)
{
  Scaleform::GFx::ASStringNode *pNode; // esi
  Scaleform::GFx::ASStringNode *v4; // ecx
  Scaleform::Ptr<Scaleform::GFx::AS2::SharedObject> *v6; // esi
  Scaleform::GFx::AS2::SharedObject *pObject; // ecx
  unsigned int RefCount; // eax

  pNode = __that->First.pNode;
  ++__that->First.pNode->RefCount;
  v4 = this->First.pNode;
  if ( v4->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v4);
  this->First.pNode = pNode;
  if ( __that == (const Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor> *)-4 )
    v6 = 0;
  else
    v6 = &__that->Second.Scaleform::Ptr<Scaleform::GFx::AS2::SharedObject>;
  if ( v6->pObject )
    v6->pObject->RefCount = (v6->pObject->RefCount + 1) & 0x8FFFFFFF;
  pObject = this->Second.pObject;
  if ( pObject )
  {
    RefCount = pObject->RefCount;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
    {
      pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
    }
  }
  this->Second.Scaleform::Ptr<Scaleform::GFx::AS2::SharedObject> = (Scaleform::Ptr<Scaleform::GFx::AS2::SharedObject>)v6->pObject;
  return this;
}
