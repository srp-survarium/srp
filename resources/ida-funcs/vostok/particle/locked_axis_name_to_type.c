vostok::particle::enum_particle_locked_axis __usercall vostok::particle::locked_axis_name_to_type@<eax>(
        const vostok::fixed_string<128> *name@<eax>)
{
  char *m_begin; // esi
  vostok::particle::enum_particle_locked_axis result; // eax

  m_begin = name->m_begin;
  result = (vostok::particle::enum_particle_locked_axis)vostok::detail::strcmp_s(name->m_begin, "X");
  if ( result )
  {
    if ( !vostok::detail::strcmp_s(m_begin, "Y") )
      return 1;
    if ( !vostok::detail::strcmp_s(m_begin, "Z") )
      return 2;
    if ( !vostok::detail::strcmp_s(m_begin, "-X") )
      return 3;
    if ( !vostok::detail::strcmp_s(m_begin, "-Y") )
      return 4;
    if ( !vostok::detail::strcmp_s(m_begin, "-Z") )
      return 5;
    if ( !vostok::detail::strcmp_s(m_begin, "RotateX") )
      return 6;
    if ( !vostok::detail::strcmp_s(m_begin, "RotateY") )
      return 7;
    return (vostok::detail::strcmp_s(m_begin, "RotateZ") != 0) + 8;
  }
  return result;
}
