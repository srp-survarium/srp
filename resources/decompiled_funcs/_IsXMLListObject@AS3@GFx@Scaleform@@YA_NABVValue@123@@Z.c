BOOL __cdecl Scaleform::GFx::AS3::IsXMLListObject(const Scaleform::GFx::AS3::Value *v)
{
  return (v->Flags & 0x1F) - 12 <= 3 && Scaleform::GFx::AS3::IsXMLListObject(v->value.VS._1.VObj);
}
