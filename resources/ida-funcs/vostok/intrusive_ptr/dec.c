void __thiscall vostok::intrusive_ptr<vostok::render::res_signature const,vostok::render::res_signature const,vostok::threading::single_threading_policy>::dec(
        vostok::intrusive_ptr<vostok::render::res_signature const ,vostok::render::res_signature const ,vostok::threading::single_threading_policy> *this)
{
  const vostok::render::res_signature *m_object; // eax

  m_object = this->m_object;
  if ( this->m_object )
  {
    if ( m_object->m_reference_count-- == 1 )
      vostok::render::resource_manager::release(
        vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
        (vostok::render::res_pass *)this->m_object);
  }
}


void __usercall vostok::intrusive_ptr<vostok::render::decal_instance,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec(
        vostok::intrusive_ptr<vostok::render::decal_instance,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *this@<ecx>,
        vostok::render::decal_instance **a2@<eax>,
        const char *a3@<edi>,
        const char *a4@<esi>)
{
  vostok::render::decal_instance *v4; // ecx
  int v6; // edi
  vostok::memory::doug_lea_allocator *v7; // esi
  vostok::memory::doug_lea_allocator *v8; // ecx

  v4 = *a2;
  if ( *a2 )
  {
    if ( v4->m_reference_count-- == 1 )
    {
      v6 = (int)*a2;
      v7 = vostok::render::g_allocator;
      if ( *a2 )
      {
        vostok::render::decal_instance::remove_collision(v4, v6);
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(v6 + 68));
        vostok::memory::doug_lea_allocator::free_impl(v8, (int)v7, (char *)v6, a3, a4, (const unsigned int)this);
      }
    }
  }
}


void __thiscall vostok::intrusive_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(
        vostok::intrusive_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *this)
{
  survarium::booby_trap_core *m_object; // eax
  vostok::resources::unmanaged_resource *v2; // ecx

  if ( this->m_object && !_InterlockedExchangeAdd(&this->m_object->m_reference_count, 0xFFFFFFFF) )
  {
    m_object = this->m_object;
    if ( this->m_object )
      v2 = &m_object->vostok::resources::unmanaged_resource;
    else
      v2 = 0;
    vostok::resources::unmanaged_intrusive_base::destroy(&m_object->vostok::resources::unmanaged_intrusive_base, v2);
  }
}


void __thiscall vostok::intrusive_ptr<survarium::empty_hands,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(
        vostok::intrusive_ptr<survarium::empty_hands,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *this)
{
  survarium::empty_hands *m_object; // eax
  vostok::resources::unmanaged_resource *v2; // ecx

  if ( this->m_object && !_InterlockedExchangeAdd(&this->m_object->m_reference_count, 0xFFFFFFFF) )
  {
    m_object = this->m_object;
    if ( this->m_object )
      v2 = &m_object->vostok::resources::unmanaged_resource;
    else
      v2 = 0;
    vostok::resources::unmanaged_intrusive_base::destroy(&m_object->vostok::resources::unmanaged_intrusive_base, v2);
  }
}


void __thiscall vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock>::dec(
        vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock> *this)
{
  vostok::resources::fs_task_unmount *m_object; // eax

  if ( this->m_object )
  {
    if ( !_InterlockedExchangeAdd(&this->m_object->m_reference_count, 0xFFFFFFFF) )
    {
      m_object = this->m_object;
      _InterlockedExchangeAdd(&s_resources_manager_buffer.m_pending_mount_operations_count, 1u);
      vostok::resources::resources_manager::add_fs_task(m_object, (vostok::resources::resources_manager *)this);
    }
  }
}


void __thiscall vostok::intrusive_ptr<survarium::generic_anomaly_core,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(
        vostok::intrusive_ptr<survarium::generic_anomaly_core,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *this)
{
  survarium::generic_anomaly_core *m_object; // eax
  vostok::resources::unmanaged_resource *v2; // ecx

  if ( this->m_object && !_InterlockedExchangeAdd(&this->m_object->m_reference_count, 0xFFFFFFFF) )
  {
    m_object = this->m_object;
    if ( this->m_object )
      v2 = &m_object->vostok::resources::unmanaged_resource;
    else
      v2 = 0;
    vostok::resources::unmanaged_intrusive_base::destroy(&m_object->vostok::resources::unmanaged_intrusive_base, v2);
  }
}


void __thiscall vostok::intrusive_ptr<survarium::grenade_core,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(
        vostok::intrusive_ptr<survarium::grenade_core,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *this)
{
  survarium::grenade_core *m_object; // eax
  vostok::resources::unmanaged_resource *v2; // ecx

  if ( this->m_object && !_InterlockedExchangeAdd(&this->m_object->m_reference_count, 0xFFFFFFFF) )
  {
    m_object = this->m_object;
    if ( this->m_object )
      v2 = &m_object->vostok::resources::unmanaged_resource;
    else
      v2 = 0;
    vostok::resources::unmanaged_intrusive_base::destroy(&m_object->vostok::resources::unmanaged_intrusive_base, v2);
  }
}


void __thiscall vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *this)
{
  if ( this->m_object )
  {
    if ( !_InterlockedExchangeAdd(&this->m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::managed_intrusive_base::destroy(
        this->m_object,
        &this->m_object->vostok::resources::managed_intrusive_base);
  }
}


void __thiscall vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy>::dec(
        vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *this)
{
  vostok::animation::mixing::n_ary_tree_intrusive_base *m_object; // eax
  vostok::animation::mixing::n_ary_tree_intrusive_base *v3; // esi

  m_object = this->m_object;
  if ( this->m_object )
  {
    if ( m_object->m_reference_count-- == 1 )
    {
      v3 = this->m_object;
      vostok::animation::mixing::n_ary_tree::destroy(
        (vostok::animation::mixing::n_ary_tree *)this,
        &this->m_object->m_reference_count);
      v3[-2].m_reference_count = -4334115;
    }
  }
}


void __thiscall vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::dec(
        vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *this)
{
  if ( this->m_object )
  {
    if ( !_InterlockedExchangeAdd(&this->m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::strings::shared::detail::intrusive_base::destroy(
        (vostok::strings::shared::detail::intrusive_base *)this,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this->m_object);
  }
}


void __thiscall vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec(
        vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *this)
{
  vostok::render::render_target *m_object; // eax

  m_object = this->m_object;
  if ( this->m_object )
  {
    if ( m_object->m_reference_count-- == 1 )
      vostok::render::resource_manager::release(
        this->m_object,
        vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
  }
}


void __thiscall vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec(
        vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *this)
{
  vostok::render::res_geometry *m_object; // eax

  m_object = this->m_object;
  if ( this->m_object )
  {
    if ( m_object->m_reference_count-- == 1 )
      vostok::render::resource_manager::release(
        vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
        (vostok::render::res_pass *)this->m_object);
  }
}


void __thiscall vostok::intrusive_ptr<vostok::render::res_input_layout,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec(
        vostok::intrusive_ptr<vostok::render::res_input_layout,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *this)
{
  vostok::render::res_input_layout *m_object; // eax

  m_object = this->m_object;
  if ( this->m_object )
  {
    if ( m_object->m_reference_count-- == 1 )
      vostok::render::resource_manager::release(
        vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
        (vostok::render::res_pass *)this->m_object);
  }
}


void __thiscall vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec(
        vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *this)
{
  vostok::render::res_pass *m_object; // eax

  m_object = this->m_object;
  if ( this->m_object )
  {
    if ( m_object->m_reference_count-- == 1 )
      vostok::render::effect_manager::delete_pass(
        (vostok::render::effect_manager *)this,
        (int)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
        this->m_object);
  }
}


void __thiscall vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec(
        vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *this)
{
  vostok::render::res_texture *m_object; // eax

  m_object = this->m_object;
  if ( this->m_object )
  {
    if ( m_object->m_reference_count-- == 1 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)this,
        (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
        this->m_object);
  }
}


void __thiscall vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec(
        vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *this)
{
  vostok::render::shader_buffer *m_object; // eax
  const char *v3; // [esp+0h] [ebp-8h]
  vostok::render::shader_buffer *pointer; // [esp+4h] [ebp-4h] BYREF
  unsigned int savedregs; // [esp+8h] [ebp+0h]

  m_object = this->m_object;
  if ( this->m_object )
  {
    if ( m_object->m_reference_count-- == 1 && !this->m_object->m_reference_count )
      vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::shader_buffer>(
        vostok::render::g_allocator,
        &pointer,
        v3,
        (const char *const)this->m_object,
        savedregs);
  }
}


void __thiscall vostok::intrusive_ptr<vostok::render::shader_constant_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec(
        vostok::intrusive_ptr<vostok::render::shader_constant_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *this)
{
  vostok::render::shader_constant_buffer *m_object; // eax

  m_object = this->m_object;
  if ( this->m_object )
  {
    if ( m_object->m_reference_count-- == 1 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)this,
        (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
        (vostok::render::res_pass *)this->m_object);
  }
}


void __thiscall vostok::intrusive_ptr<survarium::simple_game_project,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(
        vostok::intrusive_ptr<survarium::simple_game_project,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *this)
{
  survarium::simple_game_project *m_object; // eax
  vostok::resources::unmanaged_resource *v2; // ecx

  if ( this->m_object && !_InterlockedExchangeAdd(&this->m_object->m_reference_count, 0xFFFFFFFF) )
  {
    m_object = this->m_object;
    if ( this->m_object )
      v2 = &m_object->vostok::resources::unmanaged_resource;
    else
      v2 = 0;
    vostok::resources::unmanaged_intrusive_base::destroy(&m_object->vostok::resources::unmanaged_intrusive_base, v2);
  }
}


void __thiscall vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>::dec(
        vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *this)
{
  vostok::sound::sound_instance_proxy *m_object; // eax

  m_object = this->m_object;
  if ( this->m_object )
  {
    if ( m_object->m_reference_count-- == 1 )
      this->m_object->free_object(this->m_object);
  }
}


void __usercall vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy>::dec(
        vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy> *this@<ecx>,
        int **a2@<eax>)
{
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v2; // ecx
  int *v3; // esi
  int v4; // edi

  if ( *a2 )
  {
    v2 = (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)(*a2 + 15);
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)v2, 0xFFFFFFFF) )
    {
      v3 = *a2;
      v4 = (*a2)[14];
      if ( *a2 )
      {
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v2, v3);
        (*(void (__thiscall **)(int, int *, const char *, const char *, int))(*(_DWORD *)v4 + 24))(
          v4,
          v3,
          "vostok::network_core::udp_match_packets_allocator::destroy",
          "c:\\survarium.deploy\\sources\\vostok/network_core/udp_match_packets_allocator.h",
          27);
      }
    }
  }
}


void __thiscall vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::dec(
        vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *this)
{
  if ( this->m_object )
  {
    if ( !_InterlockedExchangeAdd(&this->m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::vfs::vfs_intrusive_mount_base::destroy((vostok::vfs::vfs_intrusive_mount_base *)this, this->m_object);
  }
}


void __thiscall vostok::intrusive_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(
        vostok::intrusive_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *this)
{
  if ( this->m_object )
  {
    if ( !_InterlockedExchangeAdd(&this->m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &this->m_object->vostok::resources::unmanaged_intrusive_base,
        this->m_object);
  }
}


void __thiscall vostok::intrusive_ptr<survarium::victory_items_container_core,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(
        vostok::intrusive_ptr<survarium::victory_items_container_core,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *this)
{
  survarium::victory_items_container_core *m_object; // eax
  vostok::resources::unmanaged_resource *v2; // ecx

  if ( this->m_object && !_InterlockedExchangeAdd(&this->m_object->m_reference_count, 0xFFFFFFFF) )
  {
    m_object = this->m_object;
    if ( this->m_object )
      v2 = &m_object->vostok::resources::unmanaged_resource;
    else
      v2 = 0;
    vostok::resources::unmanaged_intrusive_base::destroy(&m_object->vostok::resources::unmanaged_intrusive_base, v2);
  }
}


void __thiscall vostok::intrusive_ptr<survarium::victory_item_core,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(
        vostok::intrusive_ptr<survarium::victory_item_core,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *this)
{
  survarium::victory_item_core *m_object; // eax
  vostok::resources::unmanaged_resource *v2; // ecx

  if ( this->m_object && !_InterlockedExchangeAdd(&this->m_object->m_reference_count, 0xFFFFFFFF) )
  {
    m_object = this->m_object;
    if ( this->m_object )
      v2 = &m_object->vostok::resources::unmanaged_resource;
    else
      v2 = 0;
    vostok::resources::unmanaged_intrusive_base::destroy(&m_object->vostok::resources::unmanaged_intrusive_base, v2);
  }
}


void __thiscall vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(
        vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *this)
{
  survarium::weapon_core_base_state *m_object; // eax
  vostok::resources::unmanaged_resource *v2; // ecx

  if ( this->m_object && !_InterlockedExchangeAdd(&this->m_object->m_reference_count, 0xFFFFFFFF) )
  {
    m_object = this->m_object;
    if ( this->m_object )
      v2 = &m_object->vostok::resources::unmanaged_resource;
    else
      v2 = 0;
    vostok::resources::unmanaged_intrusive_base::destroy(&m_object->vostok::resources::unmanaged_intrusive_base, v2);
  }
}


void __thiscall vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(
        vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *this)
{
  if ( this->m_object )
  {
    if ( !_InterlockedExchangeAdd(&this->m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &this->m_object->vostok::resources::unmanaged_intrusive_base,
        this->m_object);
  }
}


void __thiscall vostok::intrusive_ptr<vostok::render::res_xs<vostok::render::gs_data>,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec(
        vostok::intrusive_ptr<vostok::render::res_xs<vostok::render::gs_data>,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *this)
{
  vostok::render::res_xs<vostok::render::gs_data> *m_object; // eax

  m_object = this->m_object;
  if ( this->m_object )
  {
    if ( m_object->m_reference_count-- == 1 )
      vostok::render::resource_manager::release(
        vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
        (vostok::render::res_pass *)this->m_object);
  }
}


void __thiscall vostok::intrusive_ptr<vostok::render::res_xs<vostok::render::ps_data>,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec(
        vostok::intrusive_ptr<vostok::render::res_xs<vostok::render::ps_data>,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *this)
{
  vostok::render::res_xs<vostok::render::ps_data> *m_object; // eax

  m_object = this->m_object;
  if ( this->m_object )
  {
    if ( m_object->m_reference_count-- == 1 )
      vostok::render::resource_manager::release(
        vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
        (vostok::render::res_pass *)this->m_object);
  }
}


void __thiscall vostok::intrusive_ptr<vostok::render::res_xs<vostok::render::vs_data>,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec(
        vostok::intrusive_ptr<vostok::render::res_xs<vostok::render::vs_data>,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *this)
{
  vostok::render::res_xs<vostok::render::vs_data> *m_object; // eax

  m_object = this->m_object;
  if ( this->m_object )
  {
    if ( m_object->m_reference_count-- == 1 )
      vostok::render::resource_manager::release(
        vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
        (vostok::render::res_pass *)this->m_object);
  }
}


void __thiscall vostok::intrusive_ptr<vostok::render::res_xs_hw<vostok::render::gs_data>,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec(
        vostok::intrusive_ptr<vostok::render::res_xs_hw<vostok::render::gs_data>,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *this)
{
  vostok::render::res_xs_hw<vostok::render::gs_data> *m_object; // eax

  m_object = this->m_object;
  if ( this->m_object )
  {
    if ( m_object->m_reference_count-- == 1 )
      vostok::render::resource_manager::release_impl<vostok::render::gs_data>(
        (vostok::render::resource_manager *)this,
        (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
        this->m_object);
  }
}


void __thiscall vostok::intrusive_ptr<vostok::render::res_xs_hw<vostok::render::ps_data>,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec(
        vostok::intrusive_ptr<vostok::render::res_xs_hw<vostok::render::ps_data>,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *this)
{
  vostok::render::res_xs_hw<vostok::render::ps_data> *m_object; // eax

  m_object = this->m_object;
  if ( this->m_object )
  {
    if ( m_object->m_reference_count-- == 1 )
      vostok::render::resource_manager::release_impl<vostok::render::ps_data>(
        (vostok::render::resource_manager *)this,
        (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
        (vostok::render::res_xs_hw<vostok::render::gs_data> *)this->m_object);
  }
}


void __thiscall vostok::intrusive_ptr<vostok::render::res_xs_hw<vostok::render::vs_data>,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec(
        vostok::intrusive_ptr<vostok::render::res_xs_hw<vostok::render::vs_data>,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *this)
{
  vostok::render::res_xs_hw<vostok::render::vs_data> *m_object; // eax

  m_object = this->m_object;
  if ( this->m_object )
  {
    if ( m_object->m_reference_count-- == 1 )
      vostok::render::resource_manager::release_impl<vostok::render::vs_data>(
        (vostok::render::resource_manager *)this,
        (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
        this->m_object);
  }
}
