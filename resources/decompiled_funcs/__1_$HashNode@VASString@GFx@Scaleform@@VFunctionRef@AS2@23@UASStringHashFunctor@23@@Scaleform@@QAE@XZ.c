void __thiscall Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::~HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>(
        Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor> *this)
{
  Scaleform::GFx::AS2::FunctionObject *Function; // ecx
  unsigned int RefCount; // eax
  bool v4; // zf
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // ecx
  unsigned int v6; // eax
  Scaleform::GFx::ASStringNode *pNode; // ecx

  if ( (this->Second.Flags & 2) == 0 )
  {
    Function = this->Second.Function;
    if ( Function )
    {
      RefCount = Function->RefCount;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
      {
        Function->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
      }
    }
  }
  v4 = (this->Second.Flags & 1) == 0;
  this->Second.Function = 0;
  if ( v4 )
  {
    pLocalFrame = this->Second.pLocalFrame;
    if ( pLocalFrame )
    {
      v6 = pLocalFrame->RefCount;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v6) != 0 )
      {
        pLocalFrame->RefCount = v6 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
      }
    }
  }
  this->Second.pLocalFrame = 0;
  pNode = this->First.pNode;
  v4 = this->First.pNode->RefCount-- == 1;
  if ( v4 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}
