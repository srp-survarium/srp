Scaleform::GFx::AS3::Instances::fl_events::AsyncErrorEvent *__thiscall Scaleform::GFx::AS3::Instances::fl_events::AsyncErrorEvent::`scalar deleting destructor'(
        Scaleform::GFx::AS3::Instances::fl_events::AsyncErrorEvent *this,
        char a2)
{
  Scaleform::GFx::AS3::Instances::fl::Error *pObject; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::ASStringNode *pNode; // ecx

  this->__vftable = (Scaleform::GFx::AS3::Instances::fl_events::AsyncErrorEvent_vtbl *)&Scaleform::GFx::AS3::Instances::fl_events::AsyncErrorEvent::`vftable';
  pObject = this->error.pObject;
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      this->error.pObject = (Scaleform::GFx::AS3::Instances::fl::Error *)((char *)pObject - 1);
    }
    else
    {
      RefCount = pObject->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
  }
  pNode = this->Text.pNode;
  if ( pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  Scaleform::GFx::AS3::Instances::fl_events::Event::~Event(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
