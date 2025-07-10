bool __cdecl Scaleform::GFx::AS3::IsXMLListObject(Scaleform::GFx::AS3::Object *obj)
{
  bool result; // al
  Scaleform::GFx::AS3::Traits *pObject; // ecx

  result = 0;
  if ( obj )
  {
    pObject = obj->pTraits.pObject;
    if ( pObject->TraitsType == Traits_XMLList )
      return (pObject->Flags & 0x20) == 0;
  }
  return result;
}
