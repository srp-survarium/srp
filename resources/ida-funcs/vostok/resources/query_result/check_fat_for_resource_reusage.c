bool __usercall vostok::resources::query_result::check_fat_for_resource_reusage@<al>(
        vostok::resources::query_result *this@<ecx>,
        int a2@<esi>)
{
  void *m_object; // edi
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v4; // [esp+8h] [ebp-8h] BYREF
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> result; // [esp+Ch] [ebp-4h] BYREF

  if ( vostok::resources::cook_base::reuse_type(*(vostok::resources::class_id_enum *)(a2 + 132)) != reuse_true
    || !*(_DWORD *)(a2 + 164) )
  {
    return 0;
  }
  m_object = 0;
  vostok::resources::get_associated_unmanaged_resource_ptr(
    (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v4,
    *(vostok::vfs::vfs_iterator *)(a2 + 160));
  if ( v4.m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
      (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v4,
      (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)(a2 + 220));
    m_object = v4.m_object;
  }
  else
  {
    vostok::resources::get_associated_managed_resource_ptr(&result, *(vostok::vfs::vfs_iterator *)(a2 + 160));
    if ( result.m_object
      && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
      && (result.m_object->m_flags.m_flags & 0x10) == 0 )
    {
      vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::operator=(
        &result,
        (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)(a2 + 216));
      m_object = result.m_object;
    }
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&result);
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v4);
  if ( m_object )
  {
    _InterlockedOr((volatile signed __int32 *)(a2 + 704), (unsigned int)&loc_3FFFF + 1);
    vostok::resources::query_result::end_query_might_destroy_this((vostok::resources::query_result *)(a2 + 704), a2);
  }
  return m_object != 0;
}
