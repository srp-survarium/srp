void __thiscall vostok::render::material::material(
        vostok::render::material *this,
        vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> in_config,
        vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> a3)
{
  boost::intrusive::rbtree_node<void *> *v3; // eax

  vostok::resources::unmanaged_resource::unmanaged_resource(this, in_config.m_object, fs_iterator_class);
  in_config.m_object->__vftable = (vostok::configs::binary_config_vtbl *)&vostok::render::material::`vftable';
  in_config.m_object->m_root = (vostok::configs::binary_config_value *)&in_config.m_object[1].type;
  *((_DWORD *)&in_config.m_object->m_root + 1) = (char *)in_config.m_object + 276;
  in_config.m_object[1].__vftable = (vostok::configs::binary_config_vtbl *)&in_config.m_object[1].m_class_id;
  LOBYTE(in_config.m_object[1].type) = 0;
  LOBYTE(in_config.m_object[1].type) = 0;
  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&in_config.m_object[1].m_class_id,
    &a3);
  v3 = (boost::intrusive::rbtree_node<void *> *)s_unique_ids++;
  in_config.m_object[1].grm_satisfaction_tree_hook.parent_ = v3;
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&a3);
}
