void __thiscall survarium::base_player::hit_impl(survarium::base_player *this, survarium::base_player *info, int a3)
{
  survarium::damage_model *m_object; // esi
  survarium::damage_model *v5; // ecx
  void *v6; // esp
  vostok::buffer_vector<float> *v7; // ecx
  survarium::body_part_parameters *m_first; // eax
  survarium::damage_model *v9; // esi
  survarium::body_part_parameters *body_part; // eax
  survarium::damage_model *v11; // ecx
  survarium::bullet *v12; // edi
  float v13; // xmm0_4
  survarium::game_world_core *v14; // ecx
  survarium::base_player *v16; // esi
  float v17; // xmm1_4
  survarium::body_part_parameters *v18; // edx
  survarium::body_part_parameters *v19; // eax
  survarium::base_player *v20; // esi
  int v21; // eax
  char v22; // al
  survarium::game_world_core *m_game_world_core; // esi
  survarium::base_player *m_begin; // eax
  survarium::base_player *m_end; // ecx
  _DWORD v26[3]; // [esp+18h] [ebp-30h] BYREF
  _DWORD v27[3]; // [esp+24h] [ebp-24h] BYREF
  survarium::body_part_parameters *v28; // [esp+30h] [ebp-18h] BYREF
  char v29; // [esp+34h] [ebp-14h]
  float v30; // [esp+38h] [ebp-10h]
  float m_health; // [esp+3Ch] [ebp-Ch] BYREF
  bool bullet_first_hit[4]; // [esp+40h] [ebp-8h]
  float *v33; // [esp+44h] [ebp-4h]
  survarium::base_player *i; // [esp+50h] [ebp+8h]
  survarium::base_player *v35; // [esp+50h] [ebp+8h]
  survarium::base_player *v36; // [esp+50h] [ebp+8h]
  unsigned int m_size; // [esp+54h] [ebp+Ch]
  survarium::base_player *v38; // [esp+54h] [ebp+Ch]

  if ( info->m_is_alive && !info->m_has_to_die )
  {
    m_object = info->m_damage_model.m_object;
    if ( survarium::damage_model::get_invulnerability(m_object) < 1.0 )
    {
      m_size = m_object->m_body_parts.m_size;
      v6 = alloca(4 * m_size);
      v27[0] = v26;
      v27[1] = v26;
      v27[2] = &v26[m_size];
      if ( (_BYTE)m_size )
      {
        v33 = 0;
        *(_DWORD *)bullet_first_hit = (unsigned __int8)m_size;
        do
        {
          v7 = (vostok::buffer_vector<float> *)v33;
          m_first = info->m_damage_model.m_object->m_body_parts.m_first;
          if ( v33 )
          {
            do
            {
              v7 = (vostok::buffer_vector<float> *)((char *)v7 - 1);
              m_first = m_first->next;
            }
            while ( v7 );
          }
          m_health = m_first->m_health;
          vostok::buffer_vector<float>::push_back(v7, (int)v27, &m_health);
          v33 = (float *)((char *)v33 + 1);
          --*(_DWORD *)bullet_first_hit;
        }
        while ( *(_DWORD *)bullet_first_hit );
      }
      v9 = info->m_damage_model.m_object;
      body_part = survarium::damage_model::get_body_part(v5, (int)v9, "pain");
      v12 = *(survarium::bullet **)(a3 + 32);
      v13 = body_part->m_health;
      v28 = body_part;
      v30 = v13;
      if ( v12 )
        bullet_first_hit[0] = v12->m_last_hitted_player == 0xFF;
      else
        bullet_first_hit[0] = 0;
      if ( survarium::damage_model::hit_body_part(
             v9,
             v12,
             v11,
             *(char **)a3,
             *(survarium::hit_type_enum *)(a3 + 28),
             *(float *)(a3 + 52),
             *(float *)(a3 + 56),
             *(float **)(a3 + 60),
             *(survarium::triangle_orientation *)(a3 + 48)) )
      {
        v16 = *(survarium::base_player **)((char *)&dword_10EA8 + (_DWORD)info);
        for ( i = *(survarium::base_player **)((char *)&dword_10EAC + (_DWORD)info);
              v16 != i;
              v16 = (survarium::base_player *)((char *)v16 + 4) )
        {
          (*(void (__stdcall **)(survarium::hit_receiver *, int, _DWORD))v16->~survarium::base_player)(
            &info->survarium::hit_receiver,
            4,
            *(float *)(a3 + 52));
        }
        v17 = 0.0;
        m_health = 0.0;
        if ( (_BYTE)m_size )
        {
          v18 = info->m_damage_model.m_object->m_body_parts.m_first;
          v35 = 0;
          v14 = (survarium::game_world_core *)(unsigned __int8)m_size;
          v33 = (float *)v27[0];
          do
          {
            v19 = v18;
            if ( v35 )
            {
              v20 = v35;
              do
              {
                v20 = (survarium::base_player *)((char *)v20 - 1);
                v19 = v19->next;
              }
              while ( v20 );
            }
            if ( v17 <= (float)(*v33 - v19->m_health) )
              v17 = *v33 - v19->m_health;
            v35 = (survarium::base_player *)((char *)v35 + 1);
            ++v33;
            v14 = (survarium::game_world_core *)((char *)v14 - 1);
          }
          while ( v14 );
          m_health = v17;
        }
        survarium::base_player::generate_hit_event(
          *(const survarium::bullet **)(a3 + 32),
          v14,
          info,
          *(_DWORD *)(a3 + 60),
          *(unsigned __int8 *)(a3 + 66),
          (survarium::damage_model *)info->id,
          m_health,
          v30 - v28->m_health,
          *(int *)bullet_first_hit);
        if ( info->m_has_to_die )
        {
          LOBYTE(v28) = *(_BYTE *)(a3 + 66);
          BYTE1(v28) = info->id;
          HIWORD(v28) = *(_WORD *)(a3 + 64);
          v21 = *(_DWORD *)(a3 + 32);
          if ( v21 )
            v22 = *(_BYTE *)(v21 + 137);
          else
            v22 = 0;
          m_game_world_core = info->m_game_world_core;
          v29 = v22;
          m_begin = (survarium::base_player *)m_game_world_core->m_game_rules.m_begin;
          m_end = (survarium::base_player *)m_game_world_core->m_game_rules.m_end;
          v36 = m_begin;
          v38 = m_end;
          if ( m_begin != m_end )
          {
            while ( 1 )
            {
              (*((void (__thiscall **)(survarium::base_player_vtbl *, _DWORD, survarium::body_part_parameters **, unsigned int))m_begin->~survarium::base_player
               + 8))(
                m_begin->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable,
                0,
                &v28,
                m_game_world_core->m_current_time_in_ms);
              v36 = (survarium::base_player *)((char *)v36 + 4);
              if ( v36 == v38 )
                break;
              m_begin = v36;
            }
          }
          survarium::base_player::generate_killed_event(
            m_end,
            (unsigned int)info,
            *(_DWORD *)(a3 + 60),
            (const char *)*(unsigned __int8 *)(a3 + 66),
            *(char **)a3,
            (const survarium::bullet *)*(unsigned __int16 *)(a3 + 64),
            *(_DWORD *)(a3 + 32));
        }
      }
    }
  }
}
