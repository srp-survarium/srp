void __thiscall survarium::lobby_menu::update_play_button_lock(survarium::lobby_menu *this, int a2)
{
  int v2; // edi
  survarium::lobby_client *v3; // esi
  survarium::lobby_client *v4; // ecx
  vostok::lobby::client_state_enum v5; // eax
  survarium::flash_value *ready; // ecx
  vostok::fixed_string<128> dest; // [esp+10h] [ebp-B4h] BYREF
  char v8; // [esp+9Ch] [ebp-28h] BYREF
  Scaleform::GFx::Value pargs; // [esp+A4h] [ebp-20h] BYREF
  bool value[8]; // [esp+BCh] [ebp-8h]

  v2 = a2;
  v3 = survarium::lobby_menu::lobby_client(this, a2);
  dest.m_begin = dest.m_buffer;
  dest.m_end = dest.m_buffer;
  dest.m_max_end = &v8;
  dest.m_buffer[0] = 0;
  v5 = survarium::lobby_client::status(v4, (int)v3, &dest);
  pargs.pObjectInterface = 0;
  pargs.Type = VT_Undefined;
  if ( v5 || *(_DWORD *)(a2 + 1620) <= 0x1Eu )
  {
    value[0] = 0;
  }
  else
  {
    value[0] = 1;
    if ( v3->m_is_squad_commander )
    {
      ready = (survarium::flash_value *)survarium::lobby_client::squad_ready_count(v3);
      v2 = a2;
      value[0] = ready == (survarium::flash_value *)(v3->m_squad_members.m_end - v3->m_squad_members.m_begin - 1);
    }
  }
  survarium::flash_value::SetBoolean(ready, (int)&pargs, value[0]);
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(v2 + 1600) + 264) + 4),
    "root.lock_play_button",
    0,
    &pargs,
    1u);
  Scaleform::GFx::Value::~Value(&pargs);
}
