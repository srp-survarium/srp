char __thiscall Scaleform::GFx::AS3::Instances::fl::XMLElement::FindAttr(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        Scaleform::GFx::AS3::SoundObject *prop_name,
        unsigned int *i)
{
  Scaleform::GFx::AS3::SoundObject *v3; // eax
  Scaleform::GFx::ASStringNode *Pan; // edi
  unsigned int Size; // ebx
  bool v7; // zf

  v3 = prop_name;
  if ( ((int)prop_name->Scaleform::GFx::ASSoundIntf::__vftable & 0x1F) != 0xA )
    return 0;
  Pan = (Scaleform::GFx::ASStringNode *)prop_name->Pan;
  ++Pan->RefCount;
  Size = this->Attrs.Data.Size;
  *i = 0;
  if ( !Size )
  {
LABEL_3:
    v7 = Pan->RefCount-- == 1;
    if ( v7 )
      Scaleform::GFx::ASStringNode::ReleaseNode(Pan);
    return 0;
  }
  while ( !Scaleform::GFx::AS3::Instances::fl::XML::Matches(this->Attrs.Data.Data[*i].pObject, v3) )
  {
    if ( ++*i >= Size )
      goto LABEL_3;
    v3 = prop_name;
  }
  v7 = Pan->RefCount-- == 1;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(Pan);
  return 1;
}
