void __thiscall survarium::lobby_menu::reset_account_money(survarium::lobby_menu *this, int a2)
{
  int v2; // eax
  survarium::lobby_menu *v3; // ecx
  survarium::lobby_client *v4; // eax
  survarium::flash_value *v5; // ecx
  survarium::lobby_menu *v6; // ecx
  survarium::lobby_client *v7; // eax
  survarium::flash_value *v8; // ecx
  survarium::flash_value *v9; // ecx
  survarium::lobby_menu *v10; // ecx
  survarium::lobby_client *v11; // eax
  survarium::flash_value *v12; // ecx
  survarium::flash_value *v13; // ecx
  Scaleform::GFx::Value pargs; // [esp+10h] [ebp-34h] BYREF
  survarium::flash_value value; // [esp+28h] [ebp-1Ch] BYREF

  v2 = *(_DWORD *)(a2 + 1600);
  pargs.pObjectInterface = 0;
  pargs.Type = VT_Undefined;
  survarium::flash_movie::CreateObject((survarium::flash_movie *)this, *(survarium::flash_value **)(v2 + 264), &pargs);
  *(_DWORD *)value.body = 0;
  *(_DWORD *)&value.body[4] = 0;
  v4 = survarium::lobby_menu::lobby_client(v3, a2);
  survarium::flash_value::SetString(&value, v4->account_nickname);
  survarium::flash_value::SetMember(v5, &pargs, "nickname", &value);
  v7 = survarium::lobby_menu::lobby_client(v6, a2);
  survarium::flash_value::SetUInt(v8, (int)&value, v7->m_account_money.generic_money);
  survarium::flash_value::SetMember(v9, &pargs, "generic_money", &value);
  v11 = survarium::lobby_menu::lobby_client(v10, a2);
  survarium::flash_value::SetUInt(v12, (int)&value, v11->m_account_money.premium_money);
  survarium::flash_value::SetMember(v13, &pargs, "premium_money", &value);
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(a2 + 1600) + 264) + 4),
    "root.setPlayerInfo",
    0,
    &pargs,
    1u);
  Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&value);
  Scaleform::GFx::Value::~Value(&pargs);
}
