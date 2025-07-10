vostok::detail::abstract_type_helper *__thiscall vostok::detail::concrete_type_helper<vostok::configs::binary_config_value>::copy_helper(
        vostok::detail::concrete_type_helper<vostok::configs::binary_config_value> *this,
        vostok::mutable_buffer dest_buffer)
{
  vostok::detail::abstract_type_helper *result; // eax

  result = (vostok::detail::abstract_type_helper *)dest_buffer.m_data;
  if ( !dest_buffer.m_data )
    return 0;
  *(_DWORD *)dest_buffer.m_data = &vostok::detail::abstract_type_helper::`vftable';
  *(_DWORD *)dest_buffer.m_data = &vostok::detail::concrete_type_helper<vostok::configs::binary_config_value>::`vftable';
  return result;
}
