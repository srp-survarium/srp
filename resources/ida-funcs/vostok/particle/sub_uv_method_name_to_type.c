vostok::particle::enum_particle_subuv_method __usercall vostok::particle::sub_uv_method_name_to_type@<eax>(
        const vostok::fixed_string<128> *name@<eax>)
{
  char *m_begin; // esi
  vostok::particle::enum_particle_subuv_method result; // eax

  m_begin = name->m_begin;
  result = (vostok::particle::enum_particle_subuv_method)vostok::detail::strcmp_s(name->m_begin, "Linear");
  if ( result )
  {
    if ( vostok::detail::strcmp_s(m_begin, "LinearSmooth") )
    {
      if ( vostok::detail::strcmp_s(m_begin, "Random") )
        return vostok::detail::strcmp_s(m_begin, "RandomSmooth") != 0 ? 0 : 3;
      else
        return 2;
    }
    else
    {
      return 1;
    }
  }
  return result;
}
