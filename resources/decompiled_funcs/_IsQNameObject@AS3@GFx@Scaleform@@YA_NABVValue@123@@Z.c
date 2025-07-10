bool __cdecl Scaleform::GFx::AS3::IsQNameObject(const Scaleform::GFx::AS3::Value *v)
{
  bool result; // al
  Scaleform::GFx::AS3::Value::V1U v2; // ecx
  int v3; // ecx

  result = 0;
  if ( (v->Flags & 0x1F) - 12 <= 3 )
  {
    v2 = v->value.VS._1;
    if ( v2.VInt )
    {
      v3 = *(_DWORD *)(v2.VInt + 20);
      if ( *(_DWORD *)(v3 + 60) == 12 )
        return (*(_DWORD *)(v3 + 56) & 0x20) == 0;
    }
  }
  return result;
}
