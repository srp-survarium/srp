vostok::detail::abstract_type_helper *__thiscall vostok::detail::concrete_type_helper<vostok::sound::sound_collection_cook_user_data>::copy_helper(
        vostok::detail::concrete_type_helper<vostok::sound::sound_collection_cook_user_data> *this,
        vostok::mutable_buffer dest_buffer)
{
  if ( !dest_buffer.m_data )
    return 0;
  *(_DWORD *)dest_buffer.m_data = &vostok::detail::abstract_type_helper::`vftable';
  *(_DWORD *)dest_buffer.m_data = &vostok::detail::concrete_type_helper<vostok::sound::sound_collection_cook_user_data>::`vftable';
  return (vostok::detail::abstract_type_helper *)dest_buffer.m_data;
}
