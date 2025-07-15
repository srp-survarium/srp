char __usercall survarium::lobby_client::read_status_info@<al>(
        survarium::lobby_client *this@<ecx>,
        _DWORD *reader@<eax>)
{
  unsigned __int8 *v2; // esi
  unsigned int *v3; // esi
  unsigned int *v4; // esi
  unsigned int *v5; // esi
  unsigned int *v6; // esi
  unsigned int *v7; // esi
  unsigned int *v8; // esi
  unsigned int *v9; // esi
  vostok::fixed_string<128> *p_m_last_status_message; // eax
  char *m_begin; // ecx
  unsigned int v13; // [esp+Ch] [ebp-8h]
  unsigned int v14; // [esp+Ch] [ebp-8h]
  unsigned int v15; // [esp+Ch] [ebp-8h]
  unsigned int v16; // [esp+Ch] [ebp-8h]
  unsigned int v17; // [esp+Ch] [ebp-8h]
  unsigned int v18; // [esp+Ch] [ebp-8h]
  unsigned int v19; // [esp+Ch] [ebp-8h]
  unsigned __int8 v20; // [esp+13h] [ebp-1h]
  unsigned __int8 v21; // [esp+13h] [ebp-1h]

  v2 = (unsigned __int8 *)reader[1];
  v20 = *v2;
  reader[1] = v2 + 1;
  this->m_status = v20;
  if ( v20 )
  {
    if ( v20 == 1 )
    {
      v5 = (unsigned int *)reader[1];
      v15 = *v5;
      reader[1] = v5 + 1;
      this->m_match_order_id = v15;
      v6 = (unsigned int *)reader[1];
      v16 = *v6;
      reader[1] = v6 + 1;
      this->m_match_order_place = v16;
      v7 = (unsigned int *)reader[1];
      v17 = *v7;
      reader[1] = v7 + 1;
      this->m_match_orders_total = v17;
      v8 = (unsigned int *)reader[1];
      v18 = *v8;
      reader[1] = v8 + 1;
      this->m_match_order_current_time_sec = v18;
      v9 = (unsigned int *)reader[1];
      v19 = *v9;
      reader[1] = v9 + 1;
      this->m_match_id = -1;
      this->m_match_order_avg_wait_sec = v19;
      this->m_team_id = team_undefined;
      goto LABEL_8;
    }
    if ( v20 != 2 )
      goto LABEL_8;
    v3 = (unsigned int *)reader[1];
    v13 = *v3;
    reader[1] = v3 + 1;
    this->m_match_order_id = v13;
    v4 = (unsigned int *)reader[1];
    v14 = *v4;
    reader[1] = v4 + 1;
    this->m_match_id = v14;
    v21 = *(_BYTE *)reader[1]++;
    this->m_team_id = v21;
  }
  else
  {
    this->m_match_order_id = -1;
    this->m_match_id = -1;
    this->m_team_id = team_undefined;
  }
  this->m_match_order_avg_wait_sec = 0;
  this->m_match_order_current_time_sec = 0;
  this->m_match_orders_total = 0;
  this->m_match_order_place = 0;
LABEL_8:
  if ( reader[1] == *reader + reader[2] )
  {
    p_m_last_status_message = &this->m_last_status_message;
    m_begin = this->m_last_status_message.m_begin;
    p_m_last_status_message->m_end = m_begin;
    *m_begin = 0;
  }
  else
  {
    vostok::network_core::buffer_reader::r_string(
      (vostok::network_core::buffer_reader *)&this->m_last_status_message,
      (int)reader);
  }
  return 1;
}
