vostok::resources::inplace_managed_cook *__usercall vostok::resources::cook_base::cast_inplace_managed_cook@<eax>(
        vostok::resources::cook_base *this@<ecx>,
        vostok::resources::inplace_managed_cook *result@<eax>)
{
  unsigned int m_flags; // ecx

  m_flags = result->m_flags.m_flags;
  if ( (m_flags & 0x20) == 0 || (m_flags & 0x10) == 0 || (m_flags & 8) != 0 )
    return 0;
  return result;
}
