void __thiscall Scaleform::GFx::AS3::Traits::UpdateVT(
        Scaleform::GFx::AS3::Traits *this,
        const Scaleform::GFx::AS3::SlotInfo *si,
        const Scaleform::GFx::AS3::Value *v,
        Scaleform::GFx::AS3::SlotInfo::BindingType new_bt)
{
  Scaleform::GFx::AS3::VTable *VT; // eax
  int v5; // esi
  Scaleform::GFx::AS3::SlotInfo::BindingType v6; // edx
  Scaleform::GFx::AS3::SlotInfo *pObject; // edi

  VT = Scaleform::GFx::AS3::Traits::GetVT(this);
  v5 = (32 * *(_DWORD *)si) >> 15;
  v6 = new_bt;
  if ( (int)(*(_DWORD *)si << 22) >> 27 != 11 || new_bt == BT_Code )
  {
    pObject = (Scaleform::GFx::AS3::SlotInfo *)si->Name.pObject;
    ++pObject->File.pObject;
    si = pObject;
    Scaleform::GFx::AS3::VTable::SetMethod(
      VT,
      (Scaleform::GFx::AS3::AbsoluteIndex)v5,
      v,
      v6,
      (const Scaleform::GFx::ASString *)&si);
    if ( pObject->File.pObject-- == (Scaleform::GFx::AS3::VMAbcFile *)1 )
      Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)pObject);
  }
}
