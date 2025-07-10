void __thiscall vostok::console_commands::cc_token::fill_command_args_list(
        vostok::console_commands::cc_token *this,
        vostok::vectora<char const *> *dest)
{
  unsigned int i; // edi
  const char **p_name; // ecx
  const void **M_finish; // eax
  const stlp_std::__true_type *v6; // [esp+0h] [ebp-Ch]
  unsigned int v7; // [esp+4h] [ebp-8h]
  bool v8; // [esp+8h] [ebp-4h]

  if ( dest->_M_impl._M_start != dest->_M_impl._M_finish )
    dest->_M_impl._M_finish = dest->_M_impl._M_start;
  for ( i = 0; i < this->m_num_commands; ++i )
  {
    p_name = &this->m_commands[i].name;
    M_finish = dest->_M_impl._M_finish;
    if ( M_finish == dest->_M_impl._M_end_of_storage._M_data )
    {
      stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int>>::_M_insert_overflow(
        (stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > *)p_name,
        (unsigned __int8 **)dest,
        (int)M_finish,
        (const unsigned int *)&this->m_commands[i].name,
        v6,
        v7,
        v8);
    }
    else
    {
      *M_finish = *p_name;
      ++dest->_M_impl._M_finish;
    }
  }
}
