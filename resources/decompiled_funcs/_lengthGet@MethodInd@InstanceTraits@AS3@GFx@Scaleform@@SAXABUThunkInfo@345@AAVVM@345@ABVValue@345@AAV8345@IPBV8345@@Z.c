void __cdecl Scaleform::GFx::AS3::InstanceTraits::MethodInd::lengthGet(
        const Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // edi
  Scaleform::GFx::AS3::Traits *VObj; // esi
  int v6; // eax

  v4 = _this->value.VS._1;
  if ( (_this->Flags & 0x1F) == 6 )
    VObj = (Scaleform::GFx::AS3::Traits *)_this->value.VS._2.VObj;
  else
    VObj = _this->value.VS._2.VObj->pTraits.pObject;
  if ( VObj->GetFilePtr(VObj) )
  {
    v6 = (int)VObj->GetFilePtr(VObj);
    Scaleform::GFx::AS3::Value::SetUInt32(
      result,
      *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v6 + 60) + 112) + 4 * v4.VInt) + 16));
  }
}
