void __userpurge vostok::render::effect_manager::add_effect(
        const vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *in_config@<ecx>,
        vostok::render::res_effect *in_effect@<eax>,
        vostok::render::effect_manager *this,
        vostok::render::effect_descriptor *in_descriptor)
{
  vostok::render::custom_config *m_object; // ecx
  vostok::render::custom_config *v6; // eax
  stlp_std::priv::_Impl_vector<vostok::render::effect_manager::effect_holder_struct,vostok::render::std_allocator<vostok::render::effect_manager::effect_holder_struct> > *M_finish; // ecx
  const stlp_std::__false_type *v8; // [esp+0h] [ebp-14h]
  unsigned int v9; // [esp+4h] [ebp-10h]
  vostok::render::effect_manager::effect_holder_struct holder; // [esp+8h] [ebp-Ch] BYREF

  m_object = in_config->m_object;
  v6 = 0;
  holder.effect = in_effect;
  if ( m_object )
  {
    v6 = m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  M_finish = (stlp_std::priv::_Impl_vector<vostok::render::effect_manager::effect_holder_struct,vostok::render::std_allocator<vostok::render::effect_manager::effect_holder_struct> > *)this->m_effects._M_impl._M_finish;
  holder.config.m_object = v6;
  holder.descriptor = in_descriptor;
  if ( M_finish == (stlp_std::priv::_Impl_vector<vostok::render::effect_manager::effect_holder_struct,vostok::render::std_allocator<vostok::render::effect_manager::effect_holder_struct> > *)this->m_effects._M_impl._M_end_of_storage._M_data )
  {
    stlp_std::priv::_Impl_vector<vostok::render::effect_manager::effect_holder_struct,vostok::render::std_allocator<vostok::render::effect_manager::effect_holder_struct>>::_M_insert_overflow_aux(
      M_finish,
      (stlp_std::reverse_iterator<vostok::render::effect_manager::effect_holder_struct *> *)&this->m_effects,
      (vostok::render::effect_manager::effect_holder_struct *)M_finish,
      &holder,
      v8,
      v9,
      (bool)holder.descriptor);
    v6 = holder.config.m_object;
  }
  else
  {
    if ( M_finish )
    {
      M_finish->_M_start = (vostok::render::effect_manager::effect_holder_struct *)in_descriptor;
      M_finish->_M_finish = 0;
      if ( v6 )
      {
        M_finish->_M_finish = (vostok::render::effect_manager::effect_holder_struct *)v6;
        _InterlockedExchangeAdd(&v6->m_reference_count, 1u);
      }
      M_finish->_M_end_of_storage._M_data = (vostok::render::effect_manager::effect_holder_struct *)in_effect;
    }
    ++this->m_effects._M_impl._M_finish;
  }
  if ( v6 )
  {
    if ( !_InterlockedExchangeAdd(&v6->m_reference_count, 0xFFFFFFFF) )
      vostok::render::custom_config::destroy(v6, v6);
  }
}
