void __cdecl Scaleform::GFx::AS3::InstanceTraits::VTableInd::lengthGet(
        const Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // edi
  Scaleform::GFx::AS3::Traits *pTraits; // esi
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  int v7; // eax

  if ( (_this->Flags & 0x1F) == 7 )
    pTraits = _this->value.VS._2.pTraits;
  else
    pTraits = _this->value.VS._2.VObj->pTraits.pObject;
  v4 = _this->value.VS._1;
  v6 = Scaleform::GFx::AS3::Traits::GetVT(pTraits)->VTMethods.Data.Data[v4.VInt].value.VS._1;
  if ( pTraits->GetFilePtr(pTraits) )
  {
    v7 = (int)pTraits->GetFilePtr(pTraits);
    Scaleform::GFx::AS3::Value::SetUInt32(
      result,
      *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v7 + 60) + 120) + 4 * v6.VInt) + 16));
  }
}
