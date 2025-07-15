void __thiscall survarium::base_player::generate_killed_event(
        survarium::base_player *this,
        unsigned int current_time_in_ms,
        unsigned int killer_id,
        const char *body_part_name,
        char *hit_dict_id,
        const survarium::bullet *bullet,
        int a7)
{
  int v8; // ecx
  int v9; // eax
  survarium::game_world_core *v10; // ecx
  _DWORD *p_x; // eax
  vostok::memory::single_size_buffer_allocator<44,vostok::threading::single_threading_policy>::node *v12; // eax
  void (__thiscall ***v13)(_DWORD, unsigned int, const char *, int, const survarium::bullet *, _DWORD *, char *, _DWORD, char *, bool, int, int, int); // ecx
  _DWORD v14[3]; // [esp+Ch] [ebp-24h] BYREF
  _DWORD v15[3]; // [esp+18h] [ebp-18h] BYREF
  int v16; // [esp+24h] [ebp-Ch]
  int v17; // [esp+28h] [ebp-8h]
  int v18; // [esp+2Ch] [ebp-4h]
  survarium::base_player *v19; // [esp+38h] [ebp+8h]

  if ( (_BYTE)body_part_name == 0xFF )
    v19 = 0;
  else
    v19 = survarium::game_world_core::player(
            *(survarium::game_world_core **)(current_time_in_ms + 316),
            (unsigned __int8)body_part_name);
  v8 = *(_DWORD *)(*(_DWORD *)(current_time_in_ms + 268) + 380);
  if ( !v8 || (v9 = (*(int (__thiscall **)(int))(*(_DWORD *)v8 + 128))(v8), LOBYTE(v18) = 1, !v9) )
    LOBYTE(v18) = 0;
  if ( a7 )
    v17 = *(_DWORD *)(*(_DWORD *)(a7 + 56) + 292);
  else
    v17 = 23;
  if ( a7 )
    v16 = *(_DWORD *)(a7 + 88);
  else
    v16 = -1;
  v10 = (survarium::game_world_core *)v19;
  if ( v19 )
  {
    p_x = (_DWORD *)&v19->transform(&v19->survarium::collision_user)->c.x;
  }
  else
  {
    memset(v15, 0, sizeof(v15));
    p_x = v15;
  }
  v14[0] = *p_x;
  v14[1] = p_x[1];
  v14[2] = p_x[2];
  if ( a7 && !*(_BYTE *)(a7 + 137) )
  {
    if ( !vostok::strings::compare(hit_dict_id, "brain")
      || (LOBYTE(a7) = 0, !vostok::strings::compare(hit_dict_id, "face")) )
    {
      LOBYTE(a7) = 1;
    }
  }
  else
  {
    LOBYTE(a7) = 0;
  }
  if ( v19 )
    LOBYTE(hit_dict_id) = v19->m_inside_anomalies_counter != 0;
  else
    LOBYTE(hit_dict_id) = 0;
  v12 = survarium::game_world_core::new_game_statistic_event_history_item(
          v10,
          *(_DWORD *)(current_time_in_ms + 316),
          killer_id);
  *(_DWORD *)&v12->data[24] = 0;
  v12->data[0] = *(_BYTE *)(current_time_in_ms + 304);
  v12->data[1] = (char)body_part_name;
  v12->data[2] = (_BYTE)a7 != 0;
  *(_WORD *)&v12->data[4] = (_WORD)bullet;
  survarium::game_world_core::commit_game_statistic_event_history_item(
    *(survarium::game_world_core **)(current_time_in_ms + 316),
    (survarium::game_statistic_event_history_item *)v12);
  v13 = *(void (__thiscall ****)(_DWORD, unsigned int, const char *, int, const survarium::bullet *, _DWORD *, char *, _DWORD, char *, bool, int, int, int))(*(_DWORD *)(current_time_in_ms + 316) + 51168);
  if ( v13 )
    (**v13)(
      v13,
      killer_id,
      body_part_name,
      v16,
      bullet,
      v14,
      hit_dict_id,
      *(unsigned __int8 *)(current_time_in_ms + 304),
      &byte_10E5C[current_time_in_ms],
      *(_BYTE *)(current_time_in_ms + 708) != 0,
      v17,
      a7,
      v18);
}
