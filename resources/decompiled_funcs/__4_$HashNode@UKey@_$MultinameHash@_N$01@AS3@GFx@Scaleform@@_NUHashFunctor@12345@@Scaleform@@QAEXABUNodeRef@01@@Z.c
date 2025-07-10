void __thiscall Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::operator=(
        Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor> *this,
        const Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeRef *src)
{
  const Scaleform::GFx::AS3::MultinameHash<bool,2>::Key *pFirst; // ebx
  Scaleform::GFx::ASStringNode *pNode; // edi
  Scaleform::GFx::ASStringNode *v5; // ecx

  pFirst = src->pFirst;
  pNode = src->pFirst->Name.pNode;
  ++pNode->RefCount;
  v5 = this->First.Name.pNode;
  if ( v5->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v5);
  this->First.Name.pNode = pNode;
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>::Set(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&this->First.pNs,
    (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&pFirst->pNs);
  this->Second = *src->pSecond;
}
