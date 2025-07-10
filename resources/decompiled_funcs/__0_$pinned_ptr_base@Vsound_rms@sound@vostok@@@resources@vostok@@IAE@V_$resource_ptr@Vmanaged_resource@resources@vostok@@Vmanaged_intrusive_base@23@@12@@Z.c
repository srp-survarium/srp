void __thiscall vostok::resources::pinned_ptr_base<vostok::sound::sound_rms>::pinned_ptr_base<vostok::sound::sound_rms>(
        vostok::resources::pinned_ptr_base<vostok::sound::sound_rms> *this,
        vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> ptr)
{
  unsigned int size; // [esp+0h] [ebp-38h]
  const unsigned __int8 *v3; // [esp+4h] [ebp-34h]
  vostok::render::skeleton_model_instance *(__thiscall *v5)(vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *); // [esp+20h] [ebp-18h]
  vostok::render::skeleton_model_instance *(__thiscall *v6)(vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *); // [esp+2Ch] [ebp-Ch]

  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>(
    &this->m_resource,
    &ptr);
  if ( ptr.m_object )
    v6 = vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr;
  else
    v6 = 0;
  if ( v6 )
    v3 = vostok::memory::managed_node_owner::pin(&ptr.m_object->vostok::memory::managed_node_owner);
  else
    v3 = 0;
  this->m_data = v3;
  if ( ptr.m_object )
    v5 = vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr;
  else
    v5 = 0;
  if ( v5 )
    size = ptr.m_object->m_memory_usage_self.size;
  else
    size = 0;
  this->m_size = size;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&ptr);
}
