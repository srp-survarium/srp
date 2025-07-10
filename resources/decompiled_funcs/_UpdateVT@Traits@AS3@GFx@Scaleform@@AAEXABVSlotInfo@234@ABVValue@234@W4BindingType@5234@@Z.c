void __thiscall Scaleform::GFx::AS3::Traits::UpdateVT(
        Scaleform::GFx::AS3::Traits *this,
        const Scaleform::GFx::AS3::SlotInfo *si,
        const Scaleform::GFx::AS3::Value *v,
        Scaleform::GFx::AS3::SlotInfo::BindingType new_bt)
{
  Scaleform::GFx::AS3::VTable *VT; // eax

  VT = Scaleform::GFx::AS3::Traits::GetVT(this);
  if ( (int)(*(_DWORD *)si << 22) >> 27 != 11 || new_bt == BT_Code )
    Scaleform::GFx::AS3::VTable::SetMethod(
      VT,
      (Scaleform::GFx::AS3::AbsoluteIndex)((32 * *(_DWORD *)si) >> 15),
      v,
      new_bt);
}
