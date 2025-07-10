void __cdecl Scaleform::GFx::AS3::InstanceTraits::Thunk::lengthGet(
        const Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result)
{
  int v4; // esi
  unsigned int v5; // edx
  Scaleform::GFx::AS3::Value::V2U v6; // [esp+Ch] [ebp-4h]

  v4 = (*(_DWORD *)(_this->value.VS._1.VInt + 16) >> 10) & 0xFFF;
  if ( v4 == 4095 )
    v4 = (*(_DWORD *)(_this->value.VS._1.VInt + 16) >> 7) & 7;
  if ( (result->Flags & 0x1F) > 9 )
  {
    if ( (result->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(result);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(result);
  }
  v5 = result->Flags & 0xFFFFFFE0 | 3;
  result->value.VS._1.VInt = v4;
  result->Flags = v5;
  result->value.VS._2 = v6;
}
