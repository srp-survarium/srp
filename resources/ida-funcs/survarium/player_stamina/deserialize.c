void __fastcall survarium::player_stamina::deserialize(
        int a1,
        const unsigned int time_offset,
        vostok::threading::mutex *this,
        vostok::network_core::buffer_reader *reader)
{
  const unsigned __int8 *m_pointer; // esi
  float v6; // xmm0_4
  const unsigned __int8 *v7; // esi
  const unsigned __int8 *v8; // esi
  unsigned int v9; // ecx
  const unsigned __int8 *v10; // esi
  float v11; // xmm0_4
  const unsigned __int8 *v12; // esi
  float v13; // xmm0_4
  vostok::intrusive_list<survarium::player_params_modifier,survarium::player_params_modifier *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v14; // esi
  vostok::threading::mutex *v15; // ecx
  int v16; // [esp+1Ch] [ebp+Ch]
  int v17; // [esp+1Ch] [ebp+Ch]

  m_pointer = reader->m_pointer;
  v6 = *(float *)m_pointer;
  reader->m_pointer = m_pointer + 4;
  *((float *)&this[5].m_mutex.m_mutex[2] + 1) = v6;
  v7 = reader->m_pointer;
  v16 = *(_DWORD *)v7;
  reader->m_pointer = v7 + 4;
  LODWORD(this[6].m_mutex.m_mutex[0]) = time_offset + v16;
  v8 = reader->m_pointer;
  v17 = *(_DWORD *)v8;
  reader->m_pointer = v8 + 4;
  if ( v17 == -1 )
    v9 = -1;
  else
    v9 = time_offset + v17;
  HIDWORD(this[6].m_mutex.m_mutex[0]) = v9;
  LOBYTE(this[6].m_mutex.m_mutex[1]) = vostok::network_core::buffer_reader::r<bool>(reader);
  v10 = reader->m_pointer;
  v11 = *(float *)v10;
  reader->m_pointer = v10 + 4;
  *((float *)this[5].m_mutex.m_mutex + 1) = v11;
  v12 = reader->m_pointer;
  v13 = *(float *)v12;
  reader->m_pointer = v12 + 4;
  v14 = (vostok::intrusive_list<survarium::player_params_modifier,survarium::player_params_modifier *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)(LODWORD(this[5].m_mutex.m_mutex[0]) + 992);
  *((float *)&this[5].m_mutex.m_mutex[1] + 1) = v13;
  vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
    v14,
    (survarium::player_params_modifier *)((char *)this[5].m_mutex.m_mutex + 4),
    this);
  vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
    (vostok::intrusive_list<survarium::player_params_modifier,survarium::player_params_modifier *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)(LODWORD(this[5].m_mutex.m_mutex[0]) + 272),
    (survarium::player_params_modifier *)((char *)&this[5].m_mutex.m_mutex[1] + 4),
    v15);
}
