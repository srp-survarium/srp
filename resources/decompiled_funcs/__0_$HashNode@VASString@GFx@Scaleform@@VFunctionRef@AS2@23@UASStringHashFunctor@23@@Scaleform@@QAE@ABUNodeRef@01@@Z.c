void __thiscall Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>(
        Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor> *this,
        const Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeRef *src)
{
  Scaleform::GFx::ASStringNode *pNode; // eax
  const Scaleform::GFx::AS2::FunctionRef *pSecond; // edx
  Scaleform::GFx::AS2::FunctionRef *p_Second; // ecx
  Scaleform::GFx::AS2::FunctionObject *Function; // eax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // eax

  pNode = src->pFirst->pNode;
  this->First.pNode = pNode;
  ++pNode->RefCount;
  pSecond = src->pSecond;
  p_Second = &this->Second;
  this->Second.Flags = 0;
  Function = pSecond->Function;
  this->Second.Function = pSecond->Function;
  if ( Function )
    Function->RefCount = (Function->RefCount + 1) & 0x8FFFFFFF;
  this->Second.pLocalFrame = 0;
  pLocalFrame = pSecond->pLocalFrame;
  if ( pLocalFrame )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(p_Second, pLocalFrame, pSecond->Flags & 1);
}
