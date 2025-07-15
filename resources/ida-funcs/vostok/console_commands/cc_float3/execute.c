void __thiscall vostok::console_commands::cc_float3::execute(vostok::console_commands::cc_float3 *this, char *args)
{
  vostok::console_commands::console_command *v3; // ecx
  vostok::math::float3 *m_value; // edi
  vostok::math::float3 *p_m_min; // esi
  _DWORD *v6; // edi
  _DWORD *p_y; // esi
  float v8; // [esp+Ch] [ebp-Ch] BYREF
  float v9; // [esp+10h] [ebp-8h] BYREF
  float v10; // [esp+14h] [ebp-4h] BYREF

  if ( sscanf_s(args, "%f,%f,%f", &v8, &v9, &v10) == 3
    && this->m_min.x <= v8
    && this->m_min.y <= v9
    && this->m_min.z <= v10
    && v8 <= this->m_max.x
    && v9 <= this->m_max.y
    && v9 <= this->m_max.z )
  {
    m_value = this->m_value;
    p_m_min = (vostok::math::float3 *)&v8;
  }
  else
  {
    vostok::console_commands::console_command::on_invalid_syntax(
      v3,
      (void (__thiscall ***)(const char **, char *))this,
      args);
    p_m_min = &this->m_min;
    m_value = (vostok::math::float3 *)&v8;
  }
  m_value->x = p_m_min->x;
  p_y = (_DWORD *)&p_m_min->y;
  v6 = (_DWORD *)&m_value->y;
  *v6 = *p_y;
  v6[1] = p_y[1];
  vostok::console_commands::console_command::on_changed(
    v3,
    (int)this,
    (const vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> *)args);
}
