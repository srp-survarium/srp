Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor> *__thiscall Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::operator=(
        Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor> *this,
        const Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor> *__that)
{
  Scaleform::GFx::ASStringNode *pNode; // edi
  Scaleform::GFx::ASStringNode *v4; // ecx
  Scaleform::GFx::AS2::FunctionObject *pObject; // eax
  Scaleform::GFx::AS2::FunctionObject *v7; // ecx
  unsigned int RefCount; // eax

  pNode = __that->First.pNode;
  ++__that->First.pNode->RefCount;
  v4 = this->First.pNode;
  if ( v4->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v4);
  this->First.pNode = pNode;
  this->Second.RegistrarFunc = __that->Second.RegistrarFunc;
  pObject = __that->Second.ResolvedFunc.pObject;
  if ( pObject )
    pObject->RefCount = (pObject->RefCount + 1) & 0x8FFFFFFF;
  v7 = this->Second.ResolvedFunc.pObject;
  if ( v7 )
  {
    RefCount = v7->RefCount;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
    {
      v7->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v7);
    }
  }
  this->Second.ResolvedFunc.pObject = __that->Second.ResolvedFunc.pObject;
  return this;
}
