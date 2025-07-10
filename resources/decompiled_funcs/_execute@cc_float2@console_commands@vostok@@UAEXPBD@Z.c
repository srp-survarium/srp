void __thiscall vostok::console_commands::cc_float2::execute(vostok::console_commands::cc_float2 *this, char *args)
{
  vostok::console_commands::console_command *v3; // ecx
  float y; // eax
  int v5; // ecx
  vostok::math::float2 v; // [esp+0h] [ebp-8h] BYREF

  v.x = SNaN;
  v.y = SNaN;
  if ( sscanf_s(args, (const char *)&stru_95AF78.m_key_bindings[18], &v, &v.elements[1]) == 2
    && this->m_min.x <= v.x
    && this->m_min.y <= v.y
    && v.x <= this->m_max.x
    && v.y <= this->m_max.y )
  {
    *this->m_value = v;
  }
  else
  {
    vostok::console_commands::console_command::on_invalid_syntax(v3, (const char **)this, args);
    y = this->m_min.y;
    v.x = this->m_min.x;
    v.y = y;
  }
  v5 = -(this->m_on_change_event.vtable != 0);
  if ( ((unsigned int)survarium::weapon_user_dead_state::finalize & v5) != 0 )
    boost::function1<void,vostok::render::ambient_volume_properties const &>::operator()(
      (boost::function1<void,char const *> *)v5,
      &this->m_on_change_event.vtable,
      args);
}
