void __usercall vostok::ai::path_constructor::edge::impl<survarium::animations_search_service::vertex_type,survarium::vector<unsigned int>>::construct_path(
        vostok::ai::path_constructor::edge::impl<survarium::animations_search_service::vertex_type,survarium::vector<unsigned int> > *this@<edi>,
        survarium::animations_search_service::vertex_type *best@<eax>)
{
  survarium::vector<unsigned int> *m_path; // eax
  survarium::animations_search_service::vertex_type *m_back; // ecx
  int i; // edx
  unsigned int *M_finish; // eax
  unsigned int *M_start; // edx
  survarium::animations_search_service::vertex_type *j; // ecx
  unsigned int __x; // [esp+4h] [ebp-4h] BYREF

  m_path = this->m_path;
  if ( this->m_path )
  {
    m_back = best->m_back;
    __x = 0;
    for ( i = 1; m_back; ++i )
      m_back = m_back->m_back;
    stlp_std::priv::_Impl_vector<unsigned int,survarium::std_allocator<unsigned int>>::resize(
      &m_path->_M_impl,
      i - 1,
      &__x);
    M_finish = this->m_path->_M_impl._M_finish;
    M_start = this->m_path->_M_impl._M_start;
    for ( j = best; M_finish != M_start; --M_finish )
    {
      *(M_finish - 1) = j->m_edge_id;
      j = j->m_back;
    }
  }
}
