vostok::resources::unmanaged_cook *__usercall vostok::resources::cook_base::cast_unmanaged_cook@<eax>(
        vostok::resources::cook_base *this@<ecx>,
        vostok::resources::unmanaged_cook *result@<eax>)
{
  if ( (result->m_flags.m_flags & 0x38) != 0 )
    return 0;
  return result;
}
