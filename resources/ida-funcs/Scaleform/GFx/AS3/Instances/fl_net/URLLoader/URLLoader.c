void __thiscall Scaleform::GFx::AS3::Instances::fl_net::URLLoader::URLLoader(
        Scaleform::GFx::AS3::Instances::fl_net::URLLoader *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // eax

  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::EventDispatcher(this, t);
  this->bytesLoaded = 0;
  this->bytesTotal = 0;
  this->__vftable = (Scaleform::GFx::AS3::Instances::fl_net::URLLoader_vtbl *)&Scaleform::GFx::AS3::Instances::fl_net::URLLoader::`vftable';
  this->data.Flags = 0;
  this->data.Bonus.pWeakProxy = 0;
  p_EmptyStringNode = &this->pTraits.pObject->pVM->StringManagerRef->pStringManager->EmptyStringNode;
  this->dataFormat.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  Scaleform::GFx::ASString::operator=(&this->dataFormat, (Scaleform::GFx::ASStringNode *)"text");
}
