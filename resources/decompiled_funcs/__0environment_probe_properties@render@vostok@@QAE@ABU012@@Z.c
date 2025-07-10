void __thiscall vostok::render::environment_probe_properties::environment_probe_properties(
        vostok::render::environment_probe_properties *this,
        const vostok::render::environment_probe_properties *__that,
        const vostok::render::environment_probe_properties *__thata)
{
  unsigned __int8 *m_begin; // edx
  unsigned int v4; // ecx
  unsigned int v5; // esi

  m_begin = (unsigned __int8 *)__thata->texture_name.m_begin;
  v4 = __thata->texture_name.m_end - __thata->texture_name.m_begin;
  __that->texture_name.m_max_end = (char *)&__that->transform;
  v5 = v4;
  __that->texture_name.m_begin = __that->texture_name.m_buffer;
  __that->texture_name.m_end = __that->texture_name.m_buffer;
  memcpy((unsigned __int8 *)__that->texture_name.m_buffer, m_begin, v4);
  __that->texture_name.m_end += v5;
  *__that->texture_name.m_end = 0;
  qmemcpy((void *)&__that->transform, &__thata->transform, 0x68u);
}
