void __thiscall survarium::player::time_warp(
        survarium::player *this,
        survarium::player *action,
        survarium::player *time_in_ms,
        unsigned int time_in_msa)
{
  unsigned int v4; // eax
  int v5; // eax
  vostok::physics::bullet_character_controller **v6; // edx
  const btTransform *v7; // eax
  survarium::player *v8; // ecx
  unsigned int v9; // esi
  unsigned int v10; // edx
  unsigned __int64 v11; // kr00_8
  unsigned int v12; // eax
  survarium::client_player_history_item *v13; // edi
  const survarium::client_player_history_item *v14; // eax
  int v15; // eax
  __int64 v16; // xmm0_8
  bool *v17; // [esp+148h] [ebp-A0h]
  vostok::physics::bullet_character_controller **v18; // [esp+160h] [ebp-88h]
  unsigned int v19; // [esp+164h] [ebp-84h]
  _BYTE v20[64]; // [esp+168h] [ebp-80h] BYREF
  vostok::math::float4x4 v21; // [esp+1A8h] [ebp-40h] BYREF
  unsigned int time_in_msc; // [esp+1F8h] [ebp+10h]
  int time_in_msb; // [esp+1F8h] [ebp+10h]

  v4 = *(int *)((char *)&dword_10F14 + (_DWORD)action);
  if ( !v4 || time_in_msa >= v4 )
  {
    v5 = *(int *)((char *)&dword_10E28 + (_DWORD)action);
    if ( v5 != *(int *)((char *)&dword_10E2C + (_DWORD)action) )
    {
      if ( action->is_local )
      {
        v9 = *(int *)((char *)&dword_10E24 + (_DWORD)action);
        if ( time_in_msa <= *(_DWORD *)(96 * ((v5 + v9 - 1) % v9) + *(int *)((char *)&dword_10E1C + (_DWORD)action) + 92)
          && time_in_msa + 1000 >= *(_DWORD *)(96 * ((*(int *)((char *)&dword_10E28 + (_DWORD)action) + v9 - 1) % v9)
                                             + *(int *)((char *)&dword_10E1C + (_DWORD)action)
                                             + 92) )
        {
          v10 = *(int *)((char *)&dword_10F0C + (_DWORD)action);
          v11 = time_in_msa - (unsigned __int64)v10;
          time_in_msb = v10 + (v11 & HIDWORD(v11));
          v12 = survarium::player::history_lower_bound_index((survarium::player *)v11, (int)action, time_in_msb);
          if ( v12 != -1 )
          {
            v19 = v12 + 1;
            if ( (v12 + 1) % *(int *)((char *)&dword_10E24 + (_DWORD)action) != *(int *)((char *)&dword_10E28
                                                                                       + (_DWORD)action) )
            {
              qmemcpy(v20, (char *)&unk_10D44 + (_DWORD)action, sizeof(v20));
              v13 = (survarium::client_player_history_item *)(*(int *)((char *)&dword_10E1C + (_DWORD)action) + 96 * v12);
              action->m_is_replaying_history = 1;
              survarium::player::remove_oldest_history_items(action, v13->time_in_ms);
              if ( action->is_local )
                v14 = (const survarium::client_player_history_item *)(*(int *)((char *)&dword_10E1C + (_DWORD)action)
                                                                    + 96
                                                                    * (v19
                                                                     % *(int *)((char *)&dword_10E24 + (_DWORD)action)));
              else
                v14 = 0;
              survarium::player::update_history_item(
                v14,
                time_in_ms,
                action,
                v13,
                (const survarium::server_player_update *)time_in_ms,
                time_in_msb,
                &v21,
                v17);
              survarium::player::replay_history(
                action,
                (unsigned int)(*(int *)((char *)&dword_10E2C + (_DWORD)action) + 1)
              % *(int *)((char *)&dword_10E24 + (_DWORD)action),
                &v21);
              v15 = *(int *)((char *)&dword_10D7C + (_DWORD)action);
              v16 = *(_QWORD *)&action->m_target.transform.lines[3].x;
              qmemcpy((char *)&unk_10D44 + (_DWORD)action, v20, 0x40u);
              *(_QWORD *)&action->m_target.transform.lines[3].x = v16;
              *(int *)((char *)&dword_10D7C + (_DWORD)action) = v15;
              vostok::physics::bt_character_controller::set_transform(
                (const vostok::math::float4x4 *)((char *)&unk_10D44 + (_DWORD)action),
                *(vostok::physics::bt_character_controller **)((char *)&dword_10DC8 + (_DWORD)action));
              action->m_is_replaying_history = 0;
              *(int *)((char *)&dword_10F14 + (_DWORD)action) = time_in_msb;
            }
          }
        }
      }
      else
      {
        time_in_msc = *(int *)((char *)&dword_10F0C + (_DWORD)action)
                    + (time_in_msa < *(int *)((char *)&dword_10F0C + (_DWORD)action)
                     ? time_in_msa - *(int *)((char *)&dword_10F0C + (_DWORD)action)
                     : 0);
        *(_DWORD *)(96
                  * ((unsigned int)(*(int *)((char *)&dword_10E28 + (_DWORD)action)
                                  + *(int *)((char *)&dword_10E24 + (_DWORD)action)
                                  - 1)
                   % *(int *)((char *)&dword_10E24 + (_DWORD)action))
                  + *(int *)((char *)&dword_10E1C + (_DWORD)action)
                  + 92) = time_in_msc;
        survarium::server_player_update::operator=(
          (const survarium::server_player_update *)time_in_ms,
          (survarium::server_player_update *)(*(int *)((char *)&dword_10E1C + (_DWORD)action)
                                            + 96
                                            * ((unsigned int)(*(int *)((char *)&dword_10E28 + (_DWORD)action)
                                                            + *(int *)((char *)&dword_10E24 + (_DWORD)action)
                                                            - 1)
                                             % *(int *)((char *)&dword_10E24 + (_DWORD)action))));
        v6 = *(vostok::physics::bullet_character_controller ***)((char *)&dword_10DC8 + (_DWORD)action);
        qmemcpy((char *)&unk_10D44 + (_DWORD)action, &time_in_ms->m_usable_object_user_data.current_object, 0x40u);
        v18 = v6;
        action->m_target.look_pitch = time_in_ms->m_character_head_transform.i.w;
        v7 = vostok::physics::from_vostok((const vostok::math::float4x4 *)((char *)&unk_10D44 + (_DWORD)action));
        vostok::physics::bullet_character_controller::set_transform(*v18, v7, (btMatrix3x3 *)v18);
        *(int *)((char *)&dword_10F14 + (_DWORD)action) = time_in_msc;
        survarium::player::process_quick_slots_for_proxy_player(v8);
      }
    }
  }
}
