char __thiscall vostok::configs::binary_config_value::cast_number<signed char,__int64,int>(
        vostok::configs::binary_config_value *this)
{
  survarium::game_camera *v1; // ecx
  const void *value; // [esp+8h] [ebp-8h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  value = this->data.pointer;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  survarium::weapon_user_dead_state::finalize(v1);
  return (char)value;
}
