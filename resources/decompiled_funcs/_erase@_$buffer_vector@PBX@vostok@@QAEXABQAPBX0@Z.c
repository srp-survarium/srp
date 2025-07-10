void __thiscall vostok::buffer_vector<void const *>::erase(
        vostok::buffer_vector<void const *> *this,
        vostok::buffer_vector<void const *> *begin,
        const void ***end,
        const void **const *enda)
{
  const void **v4; // ebx
  const void **v5; // esi
  const void ***i; // edi
  signed int v7; // esi
  int v8; // esi

  v4 = *end;
  v5 = *enda;
  if ( *end != *enda )
  {
    for ( i = &begin->m_end; v5 != *i; ++v4 )
    {
      boost::intrusive::detail::destructor_impl<boost::intrusive::detail::generic_hook<boost::intrusive::get_set_node_algo<void *,0>,boost::intrusive::member_tag,1,0>>();
      vostok::buffer_vector<void const *>::construct(v4, v5++);
    }
    v7 = *enda - *end;
    v8 = vostok::buffer_vector<void const *>::size(begin) - v7;
    vostok::buffer_vector<void const *>::destroy(&begin->m_begin[v8], &begin->m_end);
    *i = &begin->m_begin[v8];
  }
}
