void __thiscall vostok::animation::animation_player::reset(
        vostok::animation::animation_player *this,
        vostok::animation::animation_player *clear_callbacks,
        bool clear_callbacksa)
{
  vostok::animation::mixing::n_ary_tree *v3; // ecx
  vostok::animation::mixing::n_ary_tree other; // [esp+10h] [ebp-30h] BYREF

  memset((void *)&other, 0, 45);
  vostok::animation::mixing::n_ary_tree::operator=(&clear_callbacks->m_mixing_tree, &other);
  vostok::animation::mixing::n_ary_tree::destroy(v3);
  if ( other.m_reference_counter.m_object )
    --other.m_reference_counter.m_object->m_reference_count;
  clear_callbacks->m_mixing_tree_buffer_size = 0;
  if ( clear_callbacksa )
  {
    vostok::animation::animation_player::destroy_subscriptions(clear_callbacks->m_first_subscribed_channel);
    clear_callbacks->m_first_subscribed_channel = 0;
    if ( clear_callbacks != (vostok::animation::animation_player *)-34104 )
      boost::_bi::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>(
        &clear_callbacks->m_callbacks_buffer,
        (unsigned __int8 *)clear_callbacks->m_callbacks_buffer_raw,
        0x500u);
  }
}
