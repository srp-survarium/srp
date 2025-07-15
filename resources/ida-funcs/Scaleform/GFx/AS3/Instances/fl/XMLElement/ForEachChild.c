int __thiscall Scaleform::GFx::AS3::Instances::fl::XMLElement::ForEachChild(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        Scaleform::GFx::AS3::SoundObject *prop_name,
        Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBack *cb)
{
  int v4; // ebp
  unsigned int v5; // esi
  unsigned int size; // [esp+Ch] [ebp-4h]

  v4 = 0;
  v5 = 0;
  size = this->Children.Data.Size;
  if ( !size )
    return 0;
  do
  {
    if ( Scaleform::GFx::AS3::Instances::fl::XML::Matches(this->Children.Data.Data[v5].pObject, prop_name) )
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
