_STLP_atomic_freelist *dynamic_initializer_for__stlp_std::__node_alloc_impl::_S_free_list__()
{
  _STLP_atomic_freelist *result; // eax
  int i; // ecx

  result = stlp_std::__node_alloc_impl::_S_free_list;
  for ( i = 15; i >= 0; --i )
  {
    result->_M._M_data._M_top = 0;
    result->_M._M_data._M_sequence = 0;
    ++result;
  }
  return result;
}
