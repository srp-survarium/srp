void __thiscall Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>(
        Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> *this,
        const Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> *e)
{
  Scaleform::GFx::ASStringNode *pNode; // edx
  Scaleform::GFx::AS2::FunctionObject *pObject; // edx

  this->NextInChain = e->NextInChain;
  pNode = e->Value.First.pNode;
  this->Value.First.pNode = pNode;
  ++pNode->RefCount;
  this->Value.Second.RegistrarFunc = e->Value.Second.RegistrarFunc;
  pObject = e->Value.Second.ResolvedFunc.pObject;
  if ( pObject )
    pObject->RefCount = (pObject->RefCount + 1) & 0x8FFFFFFF;
  this->Value.Second.ResolvedFunc.pObject = e->Value.Second.ResolvedFunc.pObject;
}
