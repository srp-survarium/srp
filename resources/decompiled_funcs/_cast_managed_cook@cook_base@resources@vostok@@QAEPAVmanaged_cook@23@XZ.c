vostok::resources::managed_cook *__usercall vostok::resources::cook_base::cast_managed_cook@<eax>(
        vostok::resources::cook_base *this@<ecx>,
        vostok::resources::managed_cook *result@<eax>)
{
  unsigned int m_flags; // ecx

  m_flags = result->m_flags.m_flags;
  if ( (m_flags & 0x20) == 0 || (m_flags & 0x18) != 0 )
    return 0;
  return result;
}
