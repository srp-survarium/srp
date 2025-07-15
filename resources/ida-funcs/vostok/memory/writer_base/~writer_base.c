void __thiscall vostok::memory::writer_base::~writer_base(vostok::memory::writer_base *this)
{
  this->__vftable = (vostok::memory::writer_base_vtbl *)&vostok::memory::writer_base::`vftable';
  stlp_std::priv::_Vector_base<unsigned int,vostok::vectora_allocator<unsigned int>>::~_Vector_base<unsigned int,vostok::vectora_allocator<unsigned int>>(
    (stlp_std::priv::_Vector_base<unsigned int,vostok::vectora_allocator<unsigned int> > *)this,
    (int)&this->m_chunk_pos);
}
