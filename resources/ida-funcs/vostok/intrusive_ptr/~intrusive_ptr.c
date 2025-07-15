void __thiscall vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock>::~intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock>(
        vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *this)
{
  if ( this->m_object )
  {
    if ( !_InterlockedExchangeAdd(&this->m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::render::custom_config::destroy(this->m_object, this->m_object);
  }
}


void __thiscall vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
        vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *this)
{
  vostok::render::light *m_object; // eax
  vostok::render::light *v3; // edi
  vostok::render::grass_render_model *v4; // esi

  m_object = this->m_object;
  if ( this->m_object )
  {
    if ( m_object->m_reference_count-- == 1 )
    {
      v3 = this->m_object;
      v4 = vostok::render::g_allocator.m_object;
      if ( this->m_object )
      {
        vostok::render::light::~light((vostok::render::light *)this);
        BYTE2(v4->m_children_resources.m_lock) = 0;
        vostok_mspace_free((void *)HIDWORD(v4->m_reconstruction_info_actuality_tick), v3);
      }
    }
  }
}


void __thiscall vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *this)
{
  if ( this->m_object )
  {
    if ( !_InterlockedExchangeAdd(&this->m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::managed_intrusive_base::destroy(
        &this->m_object->vostok::resources::managed_intrusive_base,
        this->m_object);
  }
}


void __thiscall vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
        vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *this)
{
  vostok::render::render_target *m_object; // eax

  m_object = this->m_object;
  if ( this->m_object )
  {
    if ( m_object->m_reference_count-- == 1 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (const vostok::render::render_target *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
  }
}


void __thiscall vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
        vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *this)
{
  vostok::render::res_texture *m_object; // eax

  m_object = this->m_object;
  if ( this->m_object )
  {
    if ( m_object->m_reference_count-- == 1 )
      vostok::render::res_texture::destroy_impl((vostok::render::res_texture *)this);
  }
}


void __thiscall vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy>::~intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy>(
        vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy> *this)
{
  vostok::network_core::udp_match_packets_allocator *m_object; // eax
  vostok::memory::base_allocator *m_allocator; // ecx

  if ( this->m_object && !_InterlockedExchangeAdd(&this->m_object->m_reference_count, 0xFFFFFFFF) )
  {
    m_object = this->m_object;
    m_allocator = this->m_object->m_allocator;
    if ( m_object )
      m_allocator->call_free(m_allocator, m_object);
  }
}


// attributes: thunk
void __thiscall vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
        vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *this)
{
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::dec(this);
}
