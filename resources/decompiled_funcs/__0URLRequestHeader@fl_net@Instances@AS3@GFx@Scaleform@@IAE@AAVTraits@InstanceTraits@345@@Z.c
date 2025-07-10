void __thiscall Scaleform::GFx::AS3::Instances::fl_net::URLRequestHeader::URLRequestHeader(
        Scaleform::GFx::AS3::Instances::fl_net::URLRequestHeader *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Traits *pObject; // ecx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // eax
  Scaleform::GFx::ASStringNode *v5; // eax

  Scaleform::GFx::AS3::Instances::fl::Object::Object((Scaleform::GFx::AS3::Instances::fl::Catch *)this, t);
  pObject = this->pTraits.pObject;
  this->__vftable = (Scaleform::GFx::AS3::Instances::fl_net::URLRequestHeader_vtbl *)&Scaleform::GFx::AS3::Instances::fl_net::URLRequestHeader::`vftable';
  p_EmptyStringNode = &pObject->pVM->StringManagerRef->pStringManager->EmptyStringNode;
  this->name.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v5 = &this->pTraits.pObject->pVM->StringManagerRef->pStringManager->EmptyStringNode;
  this->value.pNode = v5;
  ++v5->RefCount;
}
