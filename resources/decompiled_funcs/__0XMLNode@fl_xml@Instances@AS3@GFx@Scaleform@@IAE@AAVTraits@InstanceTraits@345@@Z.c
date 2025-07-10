void __thiscall Scaleform::GFx::AS3::Instances::fl_xml::XMLNode::XMLNode(
        Scaleform::GFx::AS3::Instances::fl_xml::XMLNode *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // eax
  Scaleform::GFx::AS3::Traits *pObject; // eax
  Scaleform::GFx::ASStringNode *v5; // eax

  Scaleform::GFx::AS3::Instances::fl::Object::Object((Scaleform::GFx::AS3::Instances::fl::Catch *)this, t);
  this->__vftable = (Scaleform::GFx::AS3::Instances::fl_xml::XMLNode_vtbl *)&Scaleform::GFx::AS3::Instances::fl_xml::XMLNode::`vftable';
  this->firstChild.pObject = 0;
  this->lastChild.pObject = 0;
  this->nextSibling.pObject = 0;
  p_EmptyStringNode = &this->pTraits.pObject->pVM->StringManagerRef->pStringManager->EmptyStringNode;
  this->nodeName.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  pObject = this->pTraits.pObject;
  this->nodeType = 0;
  v5 = &pObject->pVM->StringManagerRef->pStringManager->EmptyStringNode;
  this->nodeValue.pNode = v5;
  ++v5->RefCount;
  this->parentNode.pObject = 0;
  this->previousSibling.pObject = 0;
}
