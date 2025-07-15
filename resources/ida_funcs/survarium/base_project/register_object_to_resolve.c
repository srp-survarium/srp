void __userpurge survarium::base_project::register_object_to_resolve(
        survarium::base_project *this@<ecx>,
        survarium::link_resolver *obj@<eax>,
        vostok::configs::binary_config_value cfg)
{
  survarium::vector<survarium::base_project::resolve_link_object> *p_m_objects_to_resolve; // ecx
  survarium::base_project::resolve_link_object *M_finish; // eax
  __int64 v5; // xmm0_8
  survarium::base_project::resolve_link_object __x; // [esp+0h] [ebp-24h] BYREF

  p_m_objects_to_resolve = &this->m_objects_to_resolve;
  __x.object = obj;
  M_finish = p_m_objects_to_resolve->_M_impl._M_finish;
  __x.config = cfg;
  if ( M_finish == p_m_objects_to_resolve->_M_impl._M_end_of_storage._M_data )
  {
    stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::_M_insert_overflow_aux(
      &p_m_objects_to_resolve->_M_impl,
      M_finish,
      &__x,
      (const stlp_std::__false_type *)__x.config.data.pointer,
      HIDWORD(__x.config.data.max_storage),
      (bool)__x.config.id.pointer);
  }
  else
  {
    if ( M_finish )
    {
      M_finish->config.data.max_storage = cfg.data.max_storage;
      v5 = *(_QWORD *)&__x.object;
      M_finish->config.id.max_storage = cfg.id.max_storage;
      *(_QWORD *)&M_finish->config.id_crc = *(_QWORD *)&cfg.id_crc;
      *(_QWORD *)&M_finish->object = v5;
    }
    ++p_m_objects_to_resolve->_M_impl._M_finish;
  }
}
