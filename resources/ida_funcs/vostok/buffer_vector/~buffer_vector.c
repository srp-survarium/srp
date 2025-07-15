void __usercall vostok::buffer_vector<unsigned int>::~buffer_vector<unsigned int>(
        vostok::buffer_vector<vostok::resources::request> *this@<ecx>,
        _DWORD *a2@<eax>)
{
  a2[1] = *a2;
}


void __thiscall vostok::buffer_vector<char const *>::~buffer_vector<char const *>(
        vostok::buffer_vector<void const *> *this)
{
  const void **i; // [esp+4h] [ebp-4h]

  for ( i = this->m_begin; i != this->m_end; ++i )
    ;
  this->m_end = this->m_begin;
}


void __thiscall vostok::buffer_vector<vostok::animation::mixing::animation_interval>::~buffer_vector<vostok::animation::mixing::animation_interval>(
        vostok::buffer_vector<vostok::animation::mixing::animation_interval> *this)
{
  vostok::animation::mixing::animation_interval *i; // [esp+8h] [ebp-8h]

  for ( i = this->m_begin; i != this->m_end; ++i )
    vostok::animation::mixing::animation_interval::`scalar deleting destructor'(i, &i->m_animation, 0);
  this->m_end = this->m_begin;
}


void __thiscall vostok::buffer_vector<vostok::resources::creation_request>::~buffer_vector<vostok::resources::creation_request>(
        vostok::buffer_vector<vostok::resources::creation_request> *this)
{
  vostok::resources::creation_request *i; // [esp+4h] [ebp-4h]

  for ( i = this->m_begin; i != this->m_end; ++i )
    ;
  this->m_end = this->m_begin;
}


void __usercall vostok::buffer_vector<vostok::variant<32>>::~buffer_vector<vostok::variant<32>>(
        vostok::buffer_vector<vostok::variant<32> > *this@<ecx>,
        int a2@<esi>)
{
  vostok::buffer_vector<vostok::variant<32>>::destroy(
    *(vostok::variant<32> **)a2,
    (vostok::variant<32> *const *)(a2 + 4));
  *(_DWORD *)(a2 + 4) = *(_DWORD *)a2;
}
