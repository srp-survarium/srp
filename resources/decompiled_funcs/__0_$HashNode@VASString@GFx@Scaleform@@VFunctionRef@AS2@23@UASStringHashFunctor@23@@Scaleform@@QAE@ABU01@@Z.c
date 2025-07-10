void __thiscall Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>(
        Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor> *this,
        const Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor> *src)
{
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS2::FunctionRef *p_Second; // ecx
  Scaleform::GFx::AS2::FunctionObject *Function; // eax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // eax

  pNode = src->First.pNode;
  this->First.pNode = src->First.pNode;
  ++pNode->RefCount;
  p_Second = &this->Second;
  p_Second->Flags = 0;
  Function = src->Second.Function;
  p_Second->Function = Function;
  if ( Function )
    Function->RefCount = (Function->RefCount + 1) & 0x8FFFFFFF;
  p_Second->pLocalFrame = 0;
  pLocalFrame = src->Second.pLocalFrame;
  if ( pLocalFrame )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(p_Second, pLocalFrame, src->Second.Flags & 1);
}
