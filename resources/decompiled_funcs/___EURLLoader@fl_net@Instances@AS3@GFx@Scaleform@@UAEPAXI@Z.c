Scaleform::GFx::AS3::Instances::fl_net::URLLoader *__thiscall Scaleform::GFx::AS3::Instances::fl_net::URLLoader::`vector deleting destructor'(
        Scaleform::GFx::AS3::Instances::fl_net::URLLoader *this,
        char a2)
{
  Scaleform::GFx::ASStringNode *pNode; // ecx
  Scaleform::GFx::AS3::Value *p_data; // ecx

  pNode = this->dataFormat.pNode;
  if ( pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  p_data = &this->data;
  if ( (this->data.Flags & 0x1F) > 9 )
  {
    if ( (this->data.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(p_data);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(p_data);
  }
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::~EventDispatcher(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
