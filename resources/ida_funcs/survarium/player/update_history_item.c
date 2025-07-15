void __userpurge survarium::player::update_history_item(
        const survarium::client_player_history_item *next_item@<eax>,
        survarium::player *a2@<ecx>,
        survarium::player *this,
        survarium::client_player_history_item *item,
        const survarium::server_player_update *server_action,
        unsigned int server_action_time_in_ms,
        vostok::math::float4x4 *previous_transform,
        bool *__formal)
{
  const btTransform *v9; // eax
  float amount; // [esp+0h] [ebp-54h]
  vostok::physics::bullet_character_controller **v11; // [esp+10h] [ebp-44h]
  vostok::math::float4x4 result; // [esp+14h] [ebp-40h] BYREF

  survarium::player::restore_history_item(a2, (int)this, item);
  amount = (double)(server_action_time_in_ms - item->time_in_ms) / (double)(next_item->time_in_ms - item->time_in_ms);
  qmemcpy(
    (void *)previous_transform,
    vostok::math::lerp(&result, &item->action.state.transform, &next_item->action.state.transform, amount),
    sizeof(vostok::math::float4x4));
  item->action.input.angular_velocity = server_action->input.angular_velocity;
  item->action.input.angular_acceleration = server_action->input.angular_acceleration;
  item->action.input.actions_mask = server_action->input.actions_mask;
  qmemcpy(&item->action.state, &server_action->state, sizeof(item->action.state));
  survarium::weapon_state::operator=(&item->action.weapon_state, &server_action->weapon_state);
  qmemcpy((char *)&unk_10D44 + (_DWORD)this, &server_action->state, 0x40u);
  this->m_target.look_pitch = server_action->state.look_pitch;
  v11 = *(vostok::physics::bullet_character_controller ***)((char *)&dword_10DC8 + (_DWORD)this);
  v9 = vostok::physics::from_vostok((const vostok::math::float4x4 *)((char *)&unk_10D44 + (_DWORD)this));
  vostok::physics::bullet_character_controller::set_transform(*v11, v9, (btMatrix3x3 *)v11);
  if ( item->time_in_ms != server_action_time_in_ms )
    item->time_in_ms = server_action_time_in_ms;
}
