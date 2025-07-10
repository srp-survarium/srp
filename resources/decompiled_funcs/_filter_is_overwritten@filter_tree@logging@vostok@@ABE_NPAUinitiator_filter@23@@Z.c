char __thiscall vostok::logging::filter_tree::filter_is_overwritten(
        vostok::logging::filter_tree *this,
        vostok::logging::initiator_filter *filter)
{
  vostok::logging::initiator_filter *next; // ecx
  const vostok::variant<32> **v3; // eax
  vostok::logging::initiator_filter *it; // [esp+Ch] [ebp-4h]

  next = filter->next;
  for ( it = filter->next; it; it = it->next )
  {
    v3 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
           (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)next,
           (int)&it->initiator);
    if ( !vostok::buffer_string::find((vostok::buffer_string *)v3, (unsigned __int8 **)&filter->initiator) )
      return 1;
  }
  return 0;
}
