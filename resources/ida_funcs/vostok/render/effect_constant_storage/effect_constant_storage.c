void __usercall vostok::render::effect_constant_storage::effect_constant_storage(
        vostok::render::effect_constant_storage *this@<ecx>,
        vostok::render::effect_constant_storage *a2@<eax>)
{
  a2->m_indexers._M_impl._M_start = 0;
  a2->m_indexers._M_impl._M_finish = 0;
  a2->m_indexers._M_impl._M_end_of_storage._M_data = 0;
  vostok::quasi_singleton<vostok::render::effect_constant_storage>::pinst = a2;
  a2->m_constant_buffer = 0;
}
