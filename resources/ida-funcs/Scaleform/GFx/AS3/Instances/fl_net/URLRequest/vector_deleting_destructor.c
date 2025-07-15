Scaleform::GFx::AS3::Instances::fl_net::URLRequest *__thiscall Scaleform::GFx::AS3::Instances::fl_net::URLRequest::`vector deleting destructor'(
        Scaleform::GFx::AS3::Instances::fl_net::URLRequest *this,
        char a2)
{
  Scaleform::GFx::AS3::Instances::fl::Object *pObject; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::ASStringNode *pNode; // ecx

  pObject = this->DataObj.pObject;
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      this->DataObj.pObject = (Scaleform::GFx::AS3::Instances::fl::Object *)((char *)pObject - 1);
    }
    else
    {
      RefCount = pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
  }
  pNode = this->Url.pNode;
  if ( pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  Scaleform::GFx::AS3::Instance::~Instance(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
