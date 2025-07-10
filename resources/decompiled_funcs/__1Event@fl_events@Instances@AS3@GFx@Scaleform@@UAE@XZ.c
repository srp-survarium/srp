void __thiscall Scaleform::GFx::AS3::Instances::fl_events::Event::~Event(
        Scaleform::GFx::AS3::Instances::fl_events::Event *this)
{
  Scaleform::GFx::AS3::Instances::fl::Object *pObject; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Instances::fl::Object *v4; // ecx
  unsigned int v5; // eax
  Scaleform::GFx::ASStringNode *pNode; // ecx

  this->__vftable = (Scaleform::GFx::AS3::Instances::fl_events::Event_vtbl *)&Scaleform::GFx::AS3::Instances::fl_events::Event::`vftable';
  pObject = this->Target.pObject;
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      this->Target.pObject = (Scaleform::GFx::AS3::Instances::fl::Object *)((char *)pObject - 1);
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
  v4 = this->CurrentTarget.pObject;
  if ( v4 )
  {
    if ( ((unsigned __int8)v4 & 1) != 0 )
    {
      this->CurrentTarget.pObject = (Scaleform::GFx::AS3::Instances::fl::Object *)((char *)v4 - 1);
    }
    else
    {
      v5 = v4->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & v5) != 0 )
      {
        v4->RefCount = v5 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v4);
      }
    }
  }
  pNode = this->Type.pNode;
  if ( pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  Scaleform::GFx::AS3::Instance::~Instance(&this->Scaleform::GFx::AS3::Instances::fl::Object);
}
