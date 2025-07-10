int __thiscall Scaleform::GFx::AS3::Instances::fl::XMLElement::ForEachAttr(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        Scaleform::GFx::AS3::SoundObject *prop_name,
        Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBack *cb)
{
  int v4; // ebp
  unsigned int v5; // esi
  unsigned int size; // [esp+8h] [ebp-4h]

  v4 = 0;
  if ( ((int)prop_name->Scaleform::GFx::ASSoundIntf::__vftable & 0x1F) != 0xA )
    return 0;
  v5 = 0;
  size = this->Attrs.Data.Size;
  if ( !size )
    return 0;
  do
  {
    if ( Scaleform::GFx::AS3::Instances::fl::XML::Matches(this->Attrs.Data.Data[v5].pObject, prop_name) )
    {
      ++v4;
      if ( !cb->Call(cb, v5) )
        break;
    }
    ++v5;
  }
  while ( v5 < size );
  return v4;
}
