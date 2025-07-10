void __userpurge survarium::player::restore_history_item(
        survarium::player *this@<ecx>,
        int a2@<eax>,
        survarium::client_player_history_item *item)
{
  vostok::physics::bullet_character_controller **v3; // ebx
  const btTransform *v4; // eax
  btMatrix3x3 *v5; // ecx

  qmemcpy((char *)&unk_10D44 + a2, &item->action.state, 0x40u);
  *(float *)(a2 + 69068) = item->action.state.look_pitch;
  v3 = *(vostok::physics::bullet_character_controller ***)((char *)&dword_10DC8 + a2);
  v4 = vostok::physics::from_vostok((const vostok::math::float4x4 *)((char *)&unk_10D44 + a2));
  vostok::physics::bullet_character_controller::set_transform(*v3, v4, v5);
}
