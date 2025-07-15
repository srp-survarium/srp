void __thiscall survarium::single_player_respawn_rule::spawn_player(
        survarium::single_player_respawn_rule *this,
        survarium::base_player *player,
        unsigned int current_time_in_ms)
{
  const vostok::math::float4x4 *v4; // eax
  _DWORD *p_z; // esi
  survarium::collision_user_vtbl *v6; // eax
  vostok::math::float4x4 *v7; // ecx
  vostok::math::float3 *angles; // eax
  vostok::math::float3 *v9; // [esp+8h] [ebp-24h]
  vostok::math::axis_rotation_order v10; // [esp+Ch] [ebp-20h]
  _DWORD v11[3]; // [esp+20h] [ebp-Ch] BYREF

  v4 = player->transform(&player->survarium::collision_user);
  v11[0] = LODWORD(v4->c.x);
  v11[1] = LODWORD(v4->c.y);
  p_z = (_DWORD *)&v4->c.z;
  v6 = player->survarium::collision_user::__vftable;
  v11[2] = *p_z;
  v6->transform(&player->survarium::collision_user);
  angles = vostok::math::float4x4::get_angles(v7, v9, v10);
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))player->initialize)(
    player,
    current_time_in_ms,
    v11,
    angles->y,
    0.0);
  player->insert(player, 1);
}
