void __thiscall Scaleform::GFx::AS3::Traits::Add2VT(
        Scaleform::GFx::AS3::Traits *this,
        Scaleform::GFx::AS3::SlotInfo *si,
        const Scaleform::GFx::AS3::Value *v,
        Scaleform::GFx::AS3::SlotInfo::BindingType new_bt)
{
  Scaleform::GFx::AS3::VTable *VT; // eax
  int v5; // esi
  int v6; // edx
  Scaleform::GFx::AS3::SlotInfo::BindingType v7; // ebp
  int v8; // edi
  int v9; // eax
  char v10; // si

  VT = Scaleform::GFx::AS3::Traits::GetVT(this);
  v5 = (32 * *(_DWORD *)si) >> 15;
  v6 = *(_DWORD *)si | 0x10;
  *(_DWORD *)si = v6;
  if ( v5 < 0 )
  {
    v10 = new_bt;
    *(_DWORD *)si = *(_DWORD *)si & 0xF800001F
                  | (32
                   * (v10 & 0x1F
                    | (32
                     * (Scaleform::GFx::AS3::VTable::AddMethod(
                          VT,
                          (Scaleform::GFx::AS3::AbsoluteIndex *)&new_bt,
                          v,
                          new_bt)->Index
                      & 0x1FFFF))));
    return;
  }
  v7 = new_bt;
  v8 = v6 << 22 >> 27;
  if ( v8 != 11 || new_bt == BT_Code )
  {
    Scaleform::GFx::AS3::VTable::SetMethod(VT, (Scaleform::GFx::AS3::AbsoluteIndex)v5, v, new_bt);
    v9 = v8;
    if ( v8 == 12 )
    {
      if ( v7 != BT_Set )
      {
LABEL_10:
        if ( v9 != v8 )
          *(_DWORD *)si = *(_DWORD *)si & 0xF800001F | (32 * (v9 & 0x1F | (32 * (v5 & 0x1FFFF))));
        return;
      }
    }
    else
    {
      if ( v8 != 13 )
        return;
      if ( v7 != BT_Get )
        goto LABEL_10;
    }
    v9 = 14;
    goto LABEL_10;
  }
}
