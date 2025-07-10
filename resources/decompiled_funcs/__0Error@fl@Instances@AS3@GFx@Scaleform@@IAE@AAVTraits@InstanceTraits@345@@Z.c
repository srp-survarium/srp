void __thiscall Scaleform::GFx::AS3::Instances::fl::Error::Error(
        Scaleform::GFx::AS3::Instances::fl::Error *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *v2; // edi
  Scaleform::GFx::AS3::Traits *pObject; // eax
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // eax
  Scaleform::GFx::ASStringNode *v6; // eax
  int v7; // eax
  Scaleform::GFx::ASStringNode *v8; // edi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  Scaleform::GFx::ASStringNode *v11; // ecx
  $6995B294EB399C8E7199C0A182ACF77B *v12; // eax

  v2 = t;
  Scaleform::GFx::AS3::Instance::Instance(this, t);
  pObject = this->pTraits.pObject;
  this->__vftable = (Scaleform::GFx::AS3::Instances::fl::Error_vtbl *)&Scaleform::GFx::AS3::Instances::fl::Error::`vftable';
  p_EmptyStringNode = &pObject->pVM->StringManagerRef->pStringManager->EmptyStringNode;
  this->message.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v6 = &this->pTraits.pObject->pVM->StringManagerRef->pStringManager->EmptyStringNode;
  this->name.pNode = v6;
  ++v6->RefCount;
  this->ID = 0;
  v7 = (int)v2->GetName(v2, (Scaleform::GFx::ASString *)&t);
  v8 = *(Scaleform::GFx::ASStringNode **)v7;
  ++*(_DWORD *)(*(_DWORD *)v7 + 12);
  pNode = this->name.pNode;
  if ( pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  v11 = (Scaleform::GFx::ASStringNode *)t;
  v12 = &t->12;
  this->name.pNode = v8;
  if ( !--v12->pPrev )
    Scaleform::GFx::ASStringNode::ReleaseNode(v11);
}
