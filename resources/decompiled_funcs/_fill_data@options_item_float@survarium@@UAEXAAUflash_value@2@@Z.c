void __userpurge survarium::options_item_float::fill_data(
        survarium::options_item_float *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        survarium::flash_value *val)
{
  float m_step; // xmm0_4
  vostok::console_commands::console_command *m_console_command; // edi
  int v6; // ecx
  int v7; // edx
  int v8; // xmm0_4
  int v9; // ecx
  int v10; // edx
  int m_next; // xmm0_4
  int v12; // ecx
  int v13; // edx
  BOOL v14; // [esp+2Ch] [ebp-2Ch]
  BOOL v16; // [esp+34h] [ebp-24h]
  BOOL v17; // [esp+34h] [ebp-24h]
  survarium::flash_value slider_data_member; // [esp+40h] [ebp-18h] BYREF

  m_step = this->m_step;
  m_console_command = this->m_console_command;
  v6 = *(_DWORD *)val->body;
  v14 = (*(_DWORD *)&val->body[4] & 0x8F) == 10;
  v7 = *(_DWORD *)&val->body[8];
  *(_DWORD *)slider_data_member.body = 0;
  *(_DWORD *)&slider_data_member.body[4] = 5;
  *(double *)&slider_data_member.body[8] = m_step;
  (*(void (__thiscall **)(int, int, const char *, survarium::flash_value *, BOOL, int, int))(*(_DWORD *)v6 + 20))(
    v6,
    v7,
    "snapInterval",
    &slider_data_member,
    v14,
    a2,
    a3);
  if ( m_console_command )
    v8 = *((_DWORD *)&m_console_command[1].__vftable + 1);
  else
    v8 = 0;
  *(_DWORD *)&slider_data_member.body[4] = v8;
  if ( (slider_data_member.body[12] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, char *, _DWORD))(**(_DWORD **)&slider_data_member.body[8] + 8))(
      *(_DWORD *)&slider_data_member.body[8],
      &slider_data_member.body[8],
      *(_DWORD *)&slider_data_member.body[16]);
    *(_DWORD *)&slider_data_member.body[8] = 0;
  }
  v9 = *(_DWORD *)val->body;
  v16 = (*(_DWORD *)&val->body[4] & 0x8F) == 10;
  v10 = *(_DWORD *)&val->body[8];
  *(_DWORD *)&slider_data_member.body[12] = 5;
  *(double *)&slider_data_member.body[16] = *(float *)&slider_data_member.body[4];
  (*(void (__thiscall **)(int, int, const char *, char *, BOOL))(*(_DWORD *)v9 + 20))(
    v9,
    v10,
    "minimum",
    &slider_data_member.body[8],
    v16);
  if ( m_console_command )
    m_next = (int)m_console_command[1].m_next;
  else
    m_next = 1120403456;
  *(_DWORD *)&slider_data_member.body[4] = m_next;
  if ( (slider_data_member.body[12] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, char *, _DWORD))(**(_DWORD **)&slider_data_member.body[8] + 8))(
      *(_DWORD *)&slider_data_member.body[8],
      &slider_data_member.body[8],
      *(_DWORD *)&slider_data_member.body[16]);
    *(_DWORD *)&slider_data_member.body[8] = 0;
  }
  v12 = *(_DWORD *)val->body;
  v17 = (*(_DWORD *)&val->body[4] & 0x8F) == 10;
  v13 = *(_DWORD *)&val->body[8];
  *(_DWORD *)&slider_data_member.body[12] = 5;
  *(double *)&slider_data_member.body[16] = *(float *)&slider_data_member.body[4];
  (*(void (__thiscall **)(int, int, const char *, char *, BOOL))(*(_DWORD *)v12 + 20))(
    v12,
    v13,
    "maximum",
    &slider_data_member.body[8],
    v17);
  if ( (slider_data_member.body[12] & 0x40) != 0 )
    (*(void (__thiscall **)(_DWORD, char *, _DWORD))(**(_DWORD **)&slider_data_member.body[8] + 8))(
      *(_DWORD *)&slider_data_member.body[8],
      &slider_data_member.body[8],
      *(_DWORD *)&slider_data_member.body[16]);
}
