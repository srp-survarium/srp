char __thiscall survarium::lobby_client::read_ping_server_answer(
        survarium::lobby_client *this,
        vostok::network_core::buffer_reader *reader)
{
  int *v2; // esi
  const unsigned __int8 *m_pointer; // esi
  double v4; // st7
  int v5; // edi
  Scaleform::GFx::Value pargs; // [esp+Ch] [ebp-20h] BYREF
  int v8; // [esp+24h] [ebp-8h]

  v2 = *(int **)&this->account_nickname[4];
  v8 = *v2;
  *(_DWORD *)&this->account_nickname[4] = v2 + 1;
  m_pointer = reader[5].m_pointer;
  v4 = (double)(unsigned int)(*((_DWORD *)m_pointer + 3492) - v8) * 0.5;
  v5 = *((_DWORD *)m_pointer + 3460);
  pargs.pObjectInterface = 0;
  pargs.Type = VT_Undefined;
  survarium::flash_value::SetUInt((survarium::flash_value *)this, (int)&pargs, (unsigned __int64)v4);
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(v5 + 1600) + 264) + 4),
    "root.set_ping",
    0,
    &pargs,
    1u);
  Scaleform::GFx::Value::~Value(&pargs);
  return 1;
}
