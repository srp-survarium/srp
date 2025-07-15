void __thiscall Scaleform::GFx::AS3::Instances::fl::XMLProcInstr::~XMLProcInstr(
        Scaleform::GFx::AS3::Instances::fl::XMLProcInstr *this)
{
  Scaleform::GFx::ASStringNode *pNode; // ecx
  bool v3; // zf
  Scaleform::GFx::AS3::Instances::fl::XML *pObject; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::ASStringNode *v6; // ecx

  pNode = this->Data.pNode;
  v3 = pNode->RefCount-- == 1;
  if ( v3 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  this->__vftable = (Scaleform::GFx::AS3::Instances::fl::XMLProcInstr_vtbl *)&Scaleform::GFx::AS3::Instances::fl::XML::`vftable';
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
  v6 = this->Text.pNode;
  v3 = v6->RefCount-- == 1;
  if ( v3 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v6);
  Scaleform::GFx::AS3::Instance::~Instance(this);
}
