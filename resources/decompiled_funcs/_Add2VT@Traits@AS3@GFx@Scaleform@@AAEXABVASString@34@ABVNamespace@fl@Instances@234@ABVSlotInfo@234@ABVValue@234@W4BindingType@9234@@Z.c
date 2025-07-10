void __thiscall Scaleform::GFx::AS3::Traits::Add2VT(
        Scaleform::GFx::AS3::Traits *this,
        Scaleform::GFx::ASString *mn_name,
        const Scaleform::GFx::AS3::Instances::fl::Namespace *mn_ns,
        const Scaleform::GFx::AS3::SlotInfo *nsi,
        const Scaleform::GFx::AS3::Value *v,
        Scaleform::GFx::AS3::SlotInfo::BindingType bt)
{
  Scaleform::GFx::AS3::Slots *v7; // edi
  Scaleform::GFx::AS3::SlotInfo::BindingType v8; // ebp
  Scaleform::GFx::AS3::SlotInfo *p_Value; // edi

  v7 = &this->Scaleform::GFx::AS3::Slots;
  Scaleform::GFx::AS3::Slots::Add(
    &this->Scaleform::GFx::AS3::Slots,
    (Scaleform::GFx::AS3::AbsoluteIndex *)&nsi,
    mn_name,
    nsi);
  v8 = bt;
  p_Value = &v7->VArray.Data.Data[(unsigned int)nsi - v7->FirstOwnSlotNum].Value;
  Scaleform::GFx::AS3::Traits::UpdateVT4IM(this, mn_name, mn_ns, v, bt);
  Scaleform::GFx::AS3::Traits::Add2VT(this, p_Value, v, v8);
}
