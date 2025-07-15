Scaleform::GFx::AS3::Instances::fl::XML *__thiscall Scaleform::GFx::AS3::Instances::fl::XMLElement::ToXML(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        const Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::Value::V1U v3; // esi

  if ( (value->Flags & 0x1F) - 12 <= 3 && Scaleform::GFx::AS3::IsXMLObject(value->value.VS._1.VObj) )
    return (Scaleform::GFx::AS3::Instances::fl::XML *)value->value.VS._1.VInt;
  if ( (value->Flags & 0x1F) - 12 <= 3 && Scaleform::GFx::AS3::IsXMLListObject(value->value.VS._1.VObj) )
  {
    v3 = value->value.VS._1;
    if ( *(_DWORD *)(v3.VInt + 48) == 1 )
      return **(Scaleform::GFx::AS3::Instances::fl::XML ***)(v3.VInt + 44);
  }
  return 0;
}
