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


__int16 __thiscall vostok::configs::binary_config_value::cast_number<short,__int64,int>(
        vostok::configs::binary_config_value *this)
{
  survarium::game_camera *v1; // ecx
  const void *value; // [esp+Ch] [ebp-8h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  value = this->data.pointer;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  survarium::weapon_user_dead_state::finalize(v1);
  return (__int16)value;
}


unsigned __int16 __thiscall vostok::configs::binary_config_value::cast_number<unsigned short,unsigned __int64,unsigned int>(
        vostok::configs::binary_config_value *this)
{
  return (unsigned __int16)this->data.pointer;
}
