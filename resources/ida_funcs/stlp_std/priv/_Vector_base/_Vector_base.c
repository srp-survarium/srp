void __thiscall stlp_std::priv::_Vector_base<char,stlp_std::allocator<char>>::_Vector_base<char,stlp_std::allocator<char>>(
        stlp_std::priv::_Vector_base<char,stlp_std::allocator<char> > *this,
        const stlp_std::allocator<char> *__a)
{
  this->_M_start = 0;
  this->_M_finish = 0;
  stlp_std::priv::_STLP_alloc_proxy<char *,char,stlp_std::allocator<char>>::_STLP_alloc_proxy<char *,char,stlp_std::allocator<char>>(
    &this->_M_end_of_storage,
    __a,
    0);
}


void __thiscall stlp_std::priv::_Vector_base<unsigned int,vostok::ai::std_allocator<unsigned int>>::_Vector_base<unsigned int,vostok::ai::std_allocator<unsigned int>>(
        stlp_std::priv::_Vector_base<unsigned int,vostok::ai::std_allocator<unsigned int> > *this,
        unsigned int __n,
        const vostok::ai::std_allocator<unsigned int> *__a)
{
  const unsigned int *v3; // eax
  unsigned int v5; // [esp+8h] [ebp-14h] BYREF
  unsigned int __b; // [esp+10h] [ebp-Ch] BYREF
  char v7; // [esp+17h] [ebp-5h]
  stlp_std::priv::_STLP_alloc_proxy<unsigned int *,unsigned int,vostok::ai::std_allocator<unsigned int> > *p_M_end_of_storage; // [esp+18h] [ebp-4h]

  this->_M_start = 0;
  this->_M_finish = 0;
  p_M_end_of_storage = &this->_M_end_of_storage;
  this->_M_end_of_storage._M_data = 0;
  v7 = 0;
  v5 = __n;
  __b = 1;
  v3 = stlp_std::max<unsigned int>(&v5, &__b);
  this->_M_start = (unsigned int *)vostok::memory::doug_lea_allocator::realloc_impl(vostok::ai::g_allocator, 0, 4 * *v3);
  this->_M_finish = this->_M_start;
  this->_M_end_of_storage._M_data = &this->_M_start[__n];
}


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


void __thiscall stlp_std::priv::_Vector_base<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32>>>::_Vector_base<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32>>>(
        stlp_std::priv::_Vector_base<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32> > > *this,
        const vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32> > *__a)
{
  this->_M_start = 0;
  this->_M_finish = 0;
  this->_M_end_of_storage.m_allocator = __a->m_allocator;
  this->_M_end_of_storage._M_data = 0;
}
