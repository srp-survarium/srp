void __userpurge survarium::base_project::register_object_to_resolve(
        survarium::base_project::resolve_link_object *obj@<eax>,
        survarium::base_project *this,
        vostok::configs::binary_config_value cfg)
{
  survarium::base_project::resolve_link_object *M_finish; // edi
  unsigned int v4; // [esp+0h] [ebp-2Ch]
  bool v5; // [esp+4h] [ebp-28h]
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > __formal[3]; // [esp+8h] [ebp-24h] BYREF

  qmemcpy(__formal, &cfg, 0x18u);
  __formal[2]._M_start = obj;
  M_finish = this->m_objects_to_resolve._M_impl._M_finish;
  if ( M_finish == this->m_objects_to_resolve._M_impl._M_end_of_storage._M_data )
  {
    stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::_M_insert_overflow_aux(
      __formal,
      (int)&this->m_objects_to_resolve,
      M_finish,
      (const stlp_std::__false_type *)__formal,
      v4,
      v5);
  }
  else
  {
    if ( M_finish )
      qmemcpy(M_finish, __formal, sizeof(survarium::base_project::resolve_link_object));
    ++this->m_objects_to_resolve._M_impl._M_finish;
  }
}
