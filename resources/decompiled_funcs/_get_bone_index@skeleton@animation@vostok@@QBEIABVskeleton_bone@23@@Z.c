unsigned int __thiscall vostok::animation::skeleton::get_bone_index(
        vostok::animation::skeleton *this,
        const vostok::animation::skeleton_bone *bone)
{
  unsigned int result; // [esp+Ch] [ebp-4h]

  result = bone - vostok::animation::skeleton::get_root(this, (int)this);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)0x14);
  return result;
}
