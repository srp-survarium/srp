void __thiscall stlp_std::priv::_Impl_vector<vostok::sound::search::vertex_id_type,vostok::sound::std_allocator<vostok::sound::search::vertex_id_type>>::clear(
        stlp_std::priv::_Impl_vector<vostok::sound::search::vertex_id_type,vostok::sound::std_allocator<vostok::sound::search::vertex_id_type> > *this)
{
  stlp_std::__false_type __formal; // [esp+1Fh] [ebp-9h] BYREF
  vostok::sound::search::vertex_id_type *__first; // [esp+20h] [ebp-8h]
  vostok::sound::search::vertex_id_type *__last; // [esp+24h] [ebp-4h]

  __last = this->_M_finish;
  __first = this->_M_start;
  if ( __first != __last )
  {
    __formal = 0;
    stlp_std::priv::_Impl_vector<vostok::sound::search::vertex_id_type,vostok::sound::std_allocator<vostok::sound::search::vertex_id_type>>::_M_erase(
      this,
      __first,
      __last,
      &__formal);
  }
}
