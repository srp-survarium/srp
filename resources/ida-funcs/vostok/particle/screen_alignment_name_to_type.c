vostok::particle::enum_particle_screen_alignment __usercall vostok::particle::screen_alignment_name_to_type@<eax>(
        const vostok::fixed_string<128> *name@<eax>)
{
  char *m_begin; // esi
  vostok::particle::enum_particle_screen_alignment result; // eax

  m_begin = name->m_begin;
  result = (vostok::particle::enum_particle_screen_alignment)vostok::detail::strcmp_s(name->m_begin, "Square");
  if ( result )
  {
    if ( vostok::detail::strcmp_s(m_begin, "Rectangle") )
    {
      if ( vostok::detail::strcmp_s(m_begin, "ToPath") )
        return vostok::detail::strcmp_s(m_begin, "ToAxis") != 0 ? 1 : 3;
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
