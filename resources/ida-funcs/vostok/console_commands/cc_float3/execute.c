void __thiscall vostok::console_commands::cc_float3::execute(vostok::console_commands::cc_float3 *this, char *args)
{
  vostok::console_commands::console_command *v3; // ecx
  float z; // edx
  int v5; // ecx
  vostok::math::float3 v; // [esp+8h] [ebp-Ch] BYREF

  if ( sscanf_s(args, (const char *)&stru_95AF78.m_key_bindings[24], &v, &v.elements[1], &v.elements[2]) == 3
    && this->m_min.x <= v.x
    && this->m_min.y <= v.y
    && this->m_min.z <= v.z
    && v.x <= this->m_max.x
    && v.y <= this->m_max.y
    && v.y <= this->m_max.z )
  {
    *this->m_value = v;
  }
  else
  {
    vostok::console_commands::console_command::on_invalid_syntax(v3, (const char **)this, args);
    z = this->m_min.z;
    *(_QWORD *)&v.x = *(_QWORD *)&this->m_min.x;
    v.z = z;
  }
  v5 = -(this->m_on_change_event.vtable != 0);
  if ( ((unsigned int)survarium::weapon_user_dead_state::finalize & v5) != 0 )
    boost::function1<void,vostok::render::ambient_volume_properties const &>::operator()(
      (boost::function1<void,char const *> *)v5,
      &this->m_on_change_event.vtable,
      args);
}
