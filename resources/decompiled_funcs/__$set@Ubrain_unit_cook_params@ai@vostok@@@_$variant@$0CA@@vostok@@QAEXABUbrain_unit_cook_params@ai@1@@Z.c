void __userpurge vostok::variant<32>::set<vostok::ai::brain_unit_cook_params>(
        vostok::variant<32> *this@<ecx>,
        vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *a2@<esi>,
        const vostok::ai::brain_unit_cook_params *value)
{
  vostok::configs::binary_config *m_object; // ecx

  m_object = a2[10].m_object;
  if ( m_object )
  {
    m_object->log_string(m_object, (vostok::fixed_string<512> *)&a2[2]);
    a2[10].m_object = 0;
  }
  a2[11].m_object = (vostok::configs::binary_config *)vostok::detail::type_to_int<vostok::ai::brain_unit_cook_params>::get();
  if ( a2 != (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)-8 )
  {
    a2[2].m_object = (vostok::configs::binary_config *)value->sound_world_user;
    a2[3].m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      a2 + 3,
      (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&value->sound_scene);
    a2[4].m_object = (vostok::configs::binary_config *)value->npc;
  }
  a2[10].m_object = (vostok::configs::binary_config *)a2;
  a2->m_object = (vostok::configs::binary_config *)&vostok::detail::concrete_type_helper<vostok::ai::brain_unit_cook_params>::`vftable';
}
