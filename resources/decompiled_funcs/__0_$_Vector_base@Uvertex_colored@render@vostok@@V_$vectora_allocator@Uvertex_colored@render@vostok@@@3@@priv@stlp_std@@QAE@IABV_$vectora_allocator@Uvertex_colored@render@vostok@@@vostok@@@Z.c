void __usercall stlp_std::priv::_Vector_base<vostok::render::vertex_colored,vostok::vectora_allocator<vostok::render::vertex_colored>>::_Vector_base<vostok::render::vertex_colored,vostok::vectora_allocator<vostok::render::vertex_colored>>(
        stlp_std::priv::_Vector_base<vostok::render::vertex_colored,vostok::vectora_allocator<vostok::render::vertex_colored> > *this@<esi>,
        unsigned int __n@<ecx>,
        const vostok::vectora_allocator<vostok::render::vertex_colored> *__a@<eax>)
{
  vostok::memory::base_allocator *m_allocator; // ecx
  unsigned int *v5; // eax
  vostok::render::vertex_colored *v6; // eax
  int v7; // [esp+8h] [ebp-8h] BYREF
  unsigned int v8; // [esp+Ch] [ebp-4h] BYREF

  this->_M_start = 0;
  this->_M_finish = 0;
  m_allocator = __a->m_allocator;
  this->_M_end_of_storage.m_allocator = __a->m_allocator;
  this->_M_end_of_storage._M_data = 0;
  v8 = __n;
  v7 = 1;
  v5 = (unsigned int *)&v7;
  if ( __n )
    v5 = &v8;
  v6 = (vostok::render::vertex_colored *)m_allocator->call_realloc(m_allocator, 0, 16 * *v5);
  this->_M_end_of_storage._M_data = &v6[__n];
  this->_M_start = v6;
  this->_M_finish = v6;
}
