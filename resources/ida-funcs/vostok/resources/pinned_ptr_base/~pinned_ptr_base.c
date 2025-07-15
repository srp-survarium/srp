void __thiscall vostok::resources::pinned_ptr_base<unsigned char const>::~pinned_ptr_base<unsigned char const>(
        vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *this)
{
  const unsigned __int8 *v1; // eax

  if ( this->m_resource.m_object )
  {
    if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      v1 = this->m_data - 52;
      _InterlockedExchangeAdd((volatile signed __int32 *)v1 + 11, 0xFFFFFFFF);
      if ( *((_DWORD *)v1 + 4) )
      {
        if ( !*((_DWORD *)v1 + 11) )
        {
          _InterlockedExchangeAdd((volatile signed __int32 *)(*((_DWORD *)v1 + 4) + 40), 1u);
          *((_DWORD *)v1 + 4) = 0;
        }
      }
    }
  }
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&this->m_resource);
}


void __thiscall vostok::resources::pinned_ptr_base<vostok::sound::sound_rms>::~pinned_ptr_base<vostok::sound::sound_rms>(
        vostok::resources::pinned_ptr_base<vostok::sound::sound_rms> *this)
{
  vostok::render::skeleton_model_instance *(__thiscall *v2)(vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *); // [esp+14h] [ebp-4h]

  if ( this->m_resource.m_object )
    v2 = vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr;
  else
    v2 = 0;
  if ( v2 )
    vostok::memory::managed_node_owner::unpin(
      &this->m_resource.m_object->vostok::memory::managed_node_owner,
      this->m_data);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&this->m_resource);
}
