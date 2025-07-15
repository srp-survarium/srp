void __thiscall Scaleform::GFx::AS3::Instances::fl_accessibility::AccessibilityProperties::AccessibilityProperties(
        Scaleform::GFx::AS3::Instances::fl_accessibility::AccessibilityProperties *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Traits *pObject; // ecx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // eax
  Scaleform::GFx::AS3::Traits *v5; // eax
  Scaleform::GFx::ASStringNode *v6; // eax
  Scaleform::GFx::AS3::Traits *v7; // eax
  Scaleform::GFx::ASStringNode *v8; // eax

  Scaleform::GFx::AS3::Instances::fl::Object::Object((Scaleform::GFx::AS3::Instances::fl::Catch *)this, t);
  pObject = this->pTraits.pObject;
  this->__vftable = (Scaleform::GFx::AS3::Instances::fl_accessibility::AccessibilityProperties_vtbl *)&Scaleform::GFx::AS3::Instances::fl_accessibility::AccessibilityProperties::`vftable';
  p_EmptyStringNode = &pObject->pVM->StringManagerRef->pStringManager->EmptyStringNode;
  this->description.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v5 = this->pTraits.pObject;
  this->forceSimple = 0;
  v6 = &v5->pVM->StringManagerRef->pStringManager->EmptyStringNode;
  this->name.pNode = v6;
  ++v6->RefCount;
  v7 = this->pTraits.pObject;
  this->noAutoLabeling = 0;
  v8 = &v7->pVM->StringManagerRef->pStringManager->EmptyStringNode;
  this->shortcut.pNode = v8;
  ++v8->RefCount;
  this->silent = 0;
}
