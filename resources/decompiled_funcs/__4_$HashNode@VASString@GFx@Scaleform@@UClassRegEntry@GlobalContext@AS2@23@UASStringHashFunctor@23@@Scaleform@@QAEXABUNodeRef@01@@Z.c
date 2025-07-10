void __thiscall Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::operator=(
        Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor> *this,
        const Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeRef *src)
{
  Scaleform::GFx::ASStringNode *pNode; // edi
  Scaleform::GFx::ASStringNode *v4; // ecx
  const Scaleform::GFx::AS2::GlobalContext::ClassRegEntry *pSecond; // edi
  Scaleform::GFx::AS2::FunctionObject *pObject; // eax
  Scaleform::GFx::AS2::FunctionObject *v8; // ecx
  unsigned int RefCount; // eax

  pNode = src->pFirst->pNode;
  ++pNode->RefCount;
  v4 = this->First.pNode;
  if ( v4->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v4);
  this->First.pNode = pNode;
  pSecond = src->pSecond;
  this->Second.RegistrarFunc = pSecond->RegistrarFunc;
  pObject = pSecond->ResolvedFunc.pObject;
  if ( pObject )
    pObject->RefCount = (pObject->RefCount + 1) & 0x8FFFFFFF;
  v8 = this->Second.ResolvedFunc.pObject;
  if ( v8 )
  {
    RefCount = v8->RefCount;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
    {
      v8->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v8);
    }
    this->Second.ResolvedFunc.pObject = pSecond->ResolvedFunc.pObject;
  }
  else
  {
    this->Second.ResolvedFunc.pObject = pSecond->ResolvedFunc.pObject;
  }
}
