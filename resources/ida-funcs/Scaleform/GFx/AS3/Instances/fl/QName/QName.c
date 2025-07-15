void __thiscall Scaleform::GFx::AS3::Instances::fl::QName::QName(
        Scaleform::GFx::AS3::Instances::fl::QName *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Traits *pObject; // eax
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v5; // eax

  Scaleform::GFx::AS3::Instance::Instance(this, t);
  pObject = this->pTraits.pObject;
  this->__vftable = (Scaleform::GFx::AS3::Instances::fl::QName_vtbl *)&Scaleform::GFx::AS3::Instances::fl::QName::`vftable';
  p_EmptyStringNode = &pObject->pVM->StringManagerRef->pStringManager->EmptyStringNode;
  this->LocalName.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v5 = t->pVM->PublicNamespace.pObject;
  this->Ns.pObject = v5;
  if ( v5 )
    v5->RefCount = (v5->RefCount + 1) & 0x8FBFFFFF;
}
