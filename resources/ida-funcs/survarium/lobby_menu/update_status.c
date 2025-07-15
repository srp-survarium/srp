void __thiscall survarium::lobby_menu::update_status(survarium::lobby_menu *this, int a2)
{
  int v3; // esi
  int v4; // eax
  int v5; // eax
  survarium::flash_value *v6; // ecx
  survarium::lobby_menu *v7; // ecx
  char v8[128]; // [esp+1Ch] [ebp-168h] BYREF
  char *value[3]; // [esp+A0h] [ebp-E4h] BYREF
  _BYTE v10[128]; // [esp+ACh] [ebp-D8h] BYREF
  char v11; // [esp+12Ch] [ebp-58h] BYREF
  Scaleform::GFx::Value v12; // [esp+134h] [ebp-50h] BYREF
  survarium::flash_value v13; // [esp+14Ch] [ebp-38h] BYREF
  Scaleform::GFx::Value pvalue; // [esp+164h] [ebp-20h] BYREF
  int v15; // [esp+17Ch] [ebp-8h]
  int v16; // [esp+18Ch] [ebp+8h]

  v3 = a2 + 160;
  v4 = *(_DWORD *)(a2 + 160);
  v8[0] = 0;
  v16 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(v4 + 13912) + 56))(*(_DWORD *)(v4 + 13912));
  v15 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)v3 + 13912) + 60))(*(_DWORD *)(*(_DWORD *)v3 + 13912));
  v5 = *(_DWORD *)(a2 + 1600);
  pvalue.pObjectInterface = 0;
  pvalue.Type = VT_Undefined;
  Scaleform::GFx::Movie::CreateArray(*(Scaleform::GFx::Movie **)(*(_DWORD *)(v5 + 264) + 4), &pvalue);
  survarium::flash_value::SetElement((survarium::flash_value *)&pvalue, s_net_client_account_name, 0);
  survarium::flash_value::SetElement((survarium::flash_value *)&pvalue, (const char *)(v16 + 340), 1u);
  v12.pObjectInterface = 0;
  v12.Type = VT_Undefined;
  survarium::flash_value::SetUInt(v6, (int)&v12, *(unsigned __int16 *)(v16 + 404));
  pvalue.pObjectInterface->SetElement(pvalue.pObjectInterface, (void *)pvalue.mValue.IValue, 2u, &v12);
  value[0] = v10;
  value[1] = v10;
  value[2] = &v11;
  v10[0] = 0;
  vostok::fs_new::path_string_impl::assignf(
    value,
    (vostok::buffer_string *)*(unsigned __int16 *)(v15 + 72),
    (vostok::buffer_string *)"%s:%d",
    (const char *)(v15 + 74),
    *(unsigned __int16 *)(v15 + 72));
  survarium::flash_value::SetElement((survarium::flash_value *)&pvalue, value[0], 3u);
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(a2 + 1600) + 264) + 4),
    "root.lobby_menu.set_account_info",
    0,
    &pvalue,
    1u);
  *(_DWORD *)v13.body = 0;
  *(_DWORD *)&v13.body[4] = 0;
  survarium::flash_value::SetString(&v13, v8);
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(a2 + 1600) + 264) + 4),
    "root.set_status_info",
    0,
    (const Scaleform::GFx::Value *)&v13,
    1u);
  survarium::lobby_menu::update_play_button_lock(v7, a2);
  Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&v13);
  Scaleform::GFx::Value::~Value(&v12);
  Scaleform::GFx::Value::~Value(&pvalue);
}
