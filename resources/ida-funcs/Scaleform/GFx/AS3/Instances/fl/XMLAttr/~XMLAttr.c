void __thiscall Scaleform::GFx::AS3::Instances::fl::XMLAttr::~XMLAttr(
        Scaleform::GFx::AS3::Instances::fl::XMLAttr *this)
{
  Scaleform::GFx::ASStringNode *pNode; // ecx
  bool v3; // zf
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Instances::fl::XML *v6; // ecx
  unsigned int v7; // eax
  Scaleform::GFx::ASStringNode *v8; // ecx

  pNode = this->Data.pNode;
  this->__vftable = (Scaleform::GFx::AS3::Instances::fl::XMLAttr_vtbl *)&Scaleform::GFx::AS3::Instances::fl::XMLAttr::`vftable';
  v3 = pNode->RefCount-- == 1;
  if ( v3 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  pObject = this->Ns.pObject;
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      this->Ns.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)pObject - 1);
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
  this->__vftable = (Scaleform::GFx::AS3::Instances::fl::XMLAttr_vtbl *)&Scaleform::GFx::AS3::Instances::fl::XML::`vftable';
  v6 = this->Parent.pObject;
  if ( v6 )
  {
    if ( ((unsigned __int8)v6 & 1) != 0 )
    {
      this->Parent.pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)((char *)v6 - 1);
    }
    else
    {
      v7 = v6->RefCount;
      if ( (v7 & 0x3FFFFF) != 0 )
      {
        v6->RefCount = v7 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v6);
      }
    }
  }
  v8 = this->Text.pNode;
  v3 = v8->RefCount-- == 1;
  if ( v3 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  Scaleform::GFx::AS3::Instance::~Instance(this);
}
