void __thiscall Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>::Clear(
        Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> *this)
{
  Scaleform::GFx::ASStringNode *pNode; // ecx

  Scaleform::GFx::AS2::Object::Watchpoint::~Watchpoint(&this->Value.Second);
  pNode = this->Value.First.pNode;
  if ( pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  this->NextInChain = -2;
}


void __thiscall Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>::Clear(
        Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> *this)
{
  bool v2; // cf
  Scaleform::GFx::AS2::Member *p_Second; // ecx
  Scaleform::GFx::ASStringNode *pNode; // ecx

  v2 = this->Value.Second.mValue.T.Type < 5u;
  p_Second = &this->Value.Second;
  if ( !v2 )
    Scaleform::GFx::AS2::Value::DropRefs(&p_Second->mValue);
  pNode = this->Value.First.pNode;
  if ( pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  this->NextInChain = -2;
}
