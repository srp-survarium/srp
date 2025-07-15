Scaleform::GFx::AS3::Instances::fl::XMLComment *__thiscall Scaleform::GFx::AS3::Instances::fl::XMLComment::`scalar deleting destructor'(
        Scaleform::GFx::AS3::Instances::fl::XMLComment *this,
        char a2)
{
  Scaleform::GFx::AS3::Instances::fl::XML *pObject; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::ASStringNode *pNode; // ecx

  this->__vftable = (Scaleform::GFx::AS3::Instances::fl::XMLComment_vtbl *)&Scaleform::GFx::AS3::Instances::fl::XML::`vftable';
  pObject = this->Parent.pObject;
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      this->Parent.pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)((char *)pObject - 1);
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
  pNode = this->Text.pNode;
  if ( pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  Scaleform::GFx::AS3::Instance::~Instance(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
