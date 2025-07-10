Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::Traits::RegisterWithVT(
        Scaleform::GFx::AS3::Traits *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::ASString *mn_name,
        const Scaleform::GFx::AS3::SlotInfo *nsi,
        const Scaleform::GFx::AS3::Value *v,
        Scaleform::GFx::AS3::SlotInfo::BindingType bt)
{
  const Scaleform::GFx::AS3::SlotInfo *v6; // ebx
  const Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // ebp
  Scaleform::GFx::AS3::Slots *v9; // esi
  const Scaleform::GFx::AS3::SlotInfo *p_Value; // ebx
  int v11; // eax
  Scaleform::GFx::AS3::SlotInfo::BindingType v12; // esi
  Scaleform::GFx::AS3::CheckResult *v13; // eax

  v6 = nsi;
  pObject = nsi->pNs.pObject;
  v9 = &this->Scaleform::GFx::AS3::Slots;
  Scaleform::GFx::AS3::Slots::FindSlotInfoIndex(
    &this->Scaleform::GFx::AS3::Slots,
    (Scaleform::GFx::AS3::AbsoluteIndex *)&nsi,
    mn_name,
    pObject);
  if ( (int)nsi < 0 )
  {
    Scaleform::GFx::AS3::Traits::Add2VT(this, mn_name, pObject, v6, v, bt);
    v13 = result;
    result->Result = 1;
    return v13;
  }
  if ( (unsigned int)nsi >= v9->FirstOwnSlotNum )
    p_Value = &v9->VArray.Data.Data[(unsigned int)nsi - v9->FirstOwnSlotNum].Value;
  else
    p_Value = Scaleform::GFx::AS3::Slots::GetSlotInfo(
                (Scaleform::GFx::AS3::Slots *)v9->Parent,
                (Scaleform::GFx::AS3::AbsoluteIndex)nsi);
  v11 = (int)(*(_DWORD *)p_Value << 22) >> 27;
  if ( v11 && v11 < 11 )
  {
    v13 = result;
    result->Result = 0;
    return v13;
  }
  v12 = bt;
  if ( v11 == 12 )
  {
    if ( bt != BT_Set )
      goto LABEL_13;
    goto LABEL_12;
  }
  if ( v11 == 13 && bt == BT_Get )
LABEL_12:
    v11 = 14;
LABEL_13:
  if ( v11 == bt )
  {
    Scaleform::GFx::AS3::Traits::UpdateVT4IM(this, mn_name, pObject, v, bt);
    Scaleform::GFx::AS3::Traits::UpdateVT(this, p_Value, v, v12);
  }
  else
  {
    Scaleform::GFx::AS3::Traits::Add2VT(this, mn_name, pObject, p_Value, v, bt);
  }
  v13 = result;
  result->Result = 1;
  return v13;
}
