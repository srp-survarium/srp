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
