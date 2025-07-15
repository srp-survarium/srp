BOOL __cdecl Scaleform::GFx::AS3::IsXMLObject(const Scaleform::GFx::AS3::Value *v)
{
  return (v->Flags & 0x1F) - 12 <= 3 && Scaleform::GFx::AS3::IsXMLObject(v->value.VS._1.VObj);
}


bool __cdecl Scaleform::GFx::AS3::IsXMLObject(Scaleform::GFx::AS3::Object *obj)
{
  bool result; // al
  Scaleform::GFx::AS3::Traits *pObject; // ecx

  result = 0;
  if ( obj )
  {
    pObject = obj->pTraits.pObject;
    if ( pObject->TraitsType == Traits_XML )
      return (pObject->Flags & 0x20) == 0;
  }
  return result;
}
