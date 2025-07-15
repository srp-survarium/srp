void __usercall vostok::intrusive_ptr<survarium::empty_hands,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::empty_hands,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
        vostok::intrusive_ptr<survarium::empty_hands,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *this@<esi>,
        const vostok::intrusive_ptr<survarium::empty_hands,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *other@<edi>)
{
  survarium::empty_hands *m_object; // eax

  this->m_object = 0;
  if ( other->m_object )
  {
    vostok::intrusive_ptr<survarium::empty_hands,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(this);
    m_object = other->m_object;
    this->m_object = other->m_object;
    if ( m_object )
      _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
}


void __usercall vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock>(
        vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock> *this@<esi>,
        const vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock> *other@<edi>)
{
  vostok::resources::fs_task_unmount *m_object; // eax

  this->m_object = 0;
  if ( other->m_object )
  {
    vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock>::dec(this);
    m_object = other->m_object;
    this->m_object = other->m_object;
    if ( m_object )
      _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
}


void __usercall vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *this@<esi>,
        const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *other@<edi>)
{
  vostok::resources::managed_resource *m_object; // eax

  this->m_object = 0;
  if ( other->m_object )
  {
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(this);
    m_object = other->m_object;
    this->m_object = other->m_object;
    if ( m_object )
      _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
}


void __usercall vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *this@<esi>,
        vostok::resources::managed_resource *object@<edi>)
{
  this->m_object = 0;
  if ( object )
  {
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(this);
    this->m_object = object;
    _InterlockedExchangeAdd(&object->m_reference_count, 1u);
  }
}


void __usercall vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy>(
        vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *this@<esi>,
        const vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *other@<edi>)
{
  vostok::animation::mixing::n_ary_tree_intrusive_base *m_object; // eax

  this->m_object = 0;
  if ( other->m_object )
  {
    vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy>::dec(this);
    m_object = other->m_object;
    this->m_object = other->m_object;
    if ( m_object )
      ++m_object->m_reference_count;
  }
}


void __usercall vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
        vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *this@<esi>,
        const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *other@<edi>)
{
  vostok::particle::particle_system_instance_impl *m_object; // eax

  this->m_object = 0;
  if ( other->m_object )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(this);
    m_object = other->m_object;
    this->m_object = other->m_object;
    if ( m_object )
      _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
}


void __usercall vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>(
        vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *this@<esi>,
        const vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *other@<edi>)
{
  vostok::strings::shared::profile *m_object; // eax

  this->m_object = 0;
  if ( other->m_object )
  {
    vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::dec(this);
    m_object = other->m_object;
    this->m_object = other->m_object;
    if ( m_object )
      _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
}


void __usercall vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
        vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *this@<esi>,
        const vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *other@<edi>)
{
  vostok::render::render_target *m_object; // eax

  this->m_object = 0;
  if ( other->m_object )
  {
    vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec(this);
    m_object = other->m_object;
    this->m_object = other->m_object;
    if ( m_object )
      ++m_object->m_reference_count;
  }
}


void __usercall vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
        vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *this@<edi>,
        vostok::render::render_target *object@<esi>)
{
  this->m_object = 0;
  if ( object )
  {
    vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec(this);
    this->m_object = object;
    ++object->m_reference_count;
  }
}


void __thiscall vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
        vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *this,
        const vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *other)
{
  vostok::render::res_geometry *m_object; // eax

  this->m_object = 0;
  if ( other->m_object )
  {
    vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec(this);
    m_object = other->m_object;
    this->m_object = other->m_object;
    if ( m_object )
      ++m_object->m_reference_count;
  }
}


void __usercall vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
        vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *this@<esi>,
        const vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *other@<edi>)
{
  vostok::render::res_pass *m_object; // eax

  this->m_object = 0;
  if ( other->m_object )
  {
    vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec(this);
    m_object = other->m_object;
    this->m_object = other->m_object;
    if ( m_object )
      ++m_object->m_reference_count;
  }
}


void __usercall vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
        vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *this@<esi>,
        const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *other@<edi>)
{
  vostok::render::res_texture *m_object; // eax

  this->m_object = 0;
  if ( other->m_object )
  {
    vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec(this);
    m_object = other->m_object;
    this->m_object = other->m_object;
    if ( m_object )
      ++m_object->m_reference_count;
  }
}


void __usercall vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
        vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *this@<edi>,
        vostok::render::res_texture *object@<esi>)
{
  this->m_object = 0;
  if ( object )
  {
    vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec(this);
    this->m_object = object;
    ++object->m_reference_count;
  }
}


void __usercall vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
        vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *this@<esi>,
        const vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *other@<edi>)
{
  vostok::render::shader_buffer *m_object; // eax

  this->m_object = 0;
  if ( other->m_object )
  {
    vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec(this);
    m_object = other->m_object;
    this->m_object = other->m_object;
    if ( m_object )
      ++m_object->m_reference_count;
  }
}


void __usercall vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>(
        vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *this@<esi>,
        const vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *other@<edi>)
{
  vostok::sound::sound_instance_proxy *m_object; // eax

  this->m_object = 0;
  if ( other->m_object )
  {
    vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>::dec(this);
    m_object = other->m_object;
    this->m_object = other->m_object;
    if ( m_object )
      ++m_object->m_reference_count;
  }
}


void __usercall vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>(
        vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *this@<edi>,
        vostok::sound::sound_instance_proxy *object@<esi>)
{
  this->m_object = 0;
  if ( object )
  {
    vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>::dec(this);
    this->m_object = object;
    ++object->m_reference_count;
  }
}


void __usercall vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy>::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy>(
        vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy> *this@<esi>,
        const vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy> *other@<edi>,
        vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy> *a3@<ecx>)
{
  vostok::network_core::udp_match_packets_allocator *m_object; // eax

  this->m_object = 0;
  if ( other->m_object )
  {
    vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy>::dec(a3);
    m_object = other->m_object;
    this->m_object = other->m_object;
    if ( m_object )
      _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
}


void __usercall vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
        vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *this@<esi>,
        const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *other@<edi>)
{
  survarium::pure_game_effect_emitter_base *m_object; // eax

  this->m_object = 0;
  if ( other->m_object )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)this);
    m_object = other->m_object;
    this->m_object = other->m_object;
    if ( m_object )
      _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
}


void __thiscall vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
        vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *this,
        const vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *other)
{
  vostok::render::untyped_buffer *m_object; // edx

  this->m_object = 0;
  m_object = other->m_object;
  if ( other->m_object )
  {
    this->m_object = m_object;
    ++m_object->m_reference_count;
  }
}


void __usercall vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
        vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *this@<esi>,
        const vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *other@<edi>)
{
  vostok::vfs::vfs_mount *m_object; // eax

  this->m_object = 0;
  if ( other->m_object )
  {
    vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::dec(this);
    m_object = other->m_object;
    this->m_object = other->m_object;
    if ( m_object )
      _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
}


void __thiscall vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
        vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *this,
        vostok::vfs::vfs_mount *object)
{
  this->m_object = 0;
  if ( object )
  {
    vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::dec(this);
    this->m_object = object;
    _InterlockedExchangeAdd(&object->m_reference_count, 1u);
  }
}


void __thiscall vostok::intrusive_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
        vostok::intrusive_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *this,
        vostok::resources::vfs_sub_fat_resource *object)
{
  this->m_object = 0;
  if ( object )
  {
    vostok::intrusive_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(this);
    this->m_object = object;
    _InterlockedExchangeAdd(&object->m_reference_count, 1u);
  }
}


void __usercall vostok::intrusive_ptr<survarium::victory_items_container_core,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::victory_items_container_core,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
        vostok::intrusive_ptr<survarium::victory_items_container_core,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *this@<esi>,
        const vostok::intrusive_ptr<survarium::victory_items_container_core,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *other@<edi>)
{
  survarium::victory_items_container_core *m_object; // eax

  this->m_object = 0;
  if ( other->m_object )
  {
    vostok::intrusive_ptr<survarium::victory_items_container_core,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(this);
    m_object = other->m_object;
    this->m_object = other->m_object;
    if ( m_object )
      _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
}


void __usercall vostok::intrusive_ptr<survarium::victory_item_core,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::victory_item_core,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
        vostok::intrusive_ptr<survarium::victory_item_core,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *this@<esi>,
        const vostok::intrusive_ptr<survarium::victory_item_core,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *other@<edi>)
{
  survarium::victory_item_core *m_object; // eax

  this->m_object = 0;
  if ( other->m_object )
  {
    vostok::intrusive_ptr<survarium::victory_item_core,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(this);
    m_object = other->m_object;
    this->m_object = other->m_object;
    if ( m_object )
      _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
}


void __usercall vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
        vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *this@<esi>,
        const vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *other@<edi>)
{
  survarium::weapon_core_base_state *m_object; // eax

  this->m_object = 0;
  if ( other->m_object )
  {
    vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(this);
    m_object = other->m_object;
    this->m_object = other->m_object;
    if ( m_object )
      _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
}


void __usercall vostok::intrusive_ptr<vostok::render::res_xs<vostok::render::ps_data>,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_xs<vostok::render::ps_data>,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
        vostok::intrusive_ptr<vostok::render::res_xs<vostok::render::ps_data>,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *this@<esi>,
        const vostok::intrusive_ptr<vostok::render::res_xs<vostok::render::ps_data>,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *other@<edi>)
{
  vostok::render::res_xs<vostok::render::ps_data> *m_object; // eax

  this->m_object = 0;
  if ( other->m_object )
  {
    vostok::intrusive_ptr<vostok::render::res_xs<vostok::render::ps_data>,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec(this);
    m_object = other->m_object;
    this->m_object = other->m_object;
    if ( m_object )
      ++m_object->m_reference_count;
  }
}
