void __thiscall Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::getQualifiedClassName(
        Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *this,
        Scaleform::GFx::ASString *result,
        Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *InstanceTraits; // eax
  int v4; // eax
  Scaleform::GFx::ASStringNode *v5; // esi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  Scaleform::GFx::ASStringNode *v8; // eax

  InstanceTraits = Scaleform::GFx::AS3::VM::GetInstanceTraits(this->pTraits.pObject->pVM, value);
  v4 = (int)InstanceTraits->GetQualifiedName(InstanceTraits, (Scaleform::GFx::ASString *)&value, qnfWithColons);
  v5 = *(Scaleform::GFx::ASStringNode **)v4;
  ++*(_DWORD *)(*(_DWORD *)v4 + 12);
  pNode = result->pNode;
  if ( result->pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  v8 = (Scaleform::GFx::ASStringNode *)value;
  result->pNode = v5;
  if ( !--v8->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
}
