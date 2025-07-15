BOOL __cdecl Scaleform::GFx::AS3::AreDisplayObjectTraits(Scaleform::GFx::AS3::Object *obj)
{
  Scaleform::GFx::AS3::Traits *pObject; // eax

  pObject = obj->pTraits.pObject;
  return (unsigned int)(pObject->TraitsType - 17) < 0xC && (pObject->Flags & 0x20) == 0;
}
