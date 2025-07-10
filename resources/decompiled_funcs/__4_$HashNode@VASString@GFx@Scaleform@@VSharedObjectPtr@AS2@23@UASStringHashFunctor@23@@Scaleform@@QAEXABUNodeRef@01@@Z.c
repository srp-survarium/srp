void __thiscall Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::operator=(
        Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor> *this,
        const Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeRef *src)
{
  Scaleform::GFx::ASStringNode *pNode; // edi
  Scaleform::GFx::ASStringNode *v4; // ecx
  const Scaleform::GFx::AS2::SharedObjectPtr *pSecond; // eax
  Scaleform::GFx::AS2::SharedObject **p_pObject; // edi
  Scaleform::GFx::AS2::SharedObject *pObject; // ecx
  unsigned int RefCount; // eax

  pNode = src->pFirst->pNode;
  ++pNode->RefCount;
  v4 = this->First.pNode;
  if ( v4->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v4);
  this->First.pNode = pNode;
  pSecond = src->pSecond;
  if ( pSecond )
    p_pObject = &pSecond->pObject;
  else
    p_pObject = 0;
  if ( *p_pObject )
    (*p_pObject)->RefCount = ((*p_pObject)->RefCount + 1) & 0x8FFFFFFF;
  pObject = this->Second.pObject;
  if ( pObject )
  {
    RefCount = pObject->RefCount;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
    {
      pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
    }
    this->Second.pObject = *p_pObject;
  }
  else
  {
    this->Second.pObject = *p_pObject;
  }
}
