vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *__usercall vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::operator=@<eax>(
        vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *this@<ecx>,
        vostok::animation::mixing::binary_tree_base_node **a2@<esi>)
{
  vostok::animation::mixing::binary_tree_base_node *m_object; // ecx
  vostok::animation::mixing::binary_tree_base_node *v3; // eax
  vostok::animation::mixing::binary_tree_base_node *v4; // ecx

  m_object = this->m_object;
  v3 = 0;
  if ( m_object )
  {
    v3 = m_object;
    ++m_object->m_reference_count;
  }
  v4 = *a2;
  *a2 = v3;
  if ( v4 )
  {
    if ( v4->m_reference_count-- == 1 )
      ((void (__thiscall *)(vostok::animation::mixing::binary_tree_base_node *, _DWORD))v4->~vostok::animation::mixing::binary_tree_base_node)(
        v4,
        0);
  }
  return (vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *)a2;
}


vostok::intrusive_ptr<survarium::artefact_base,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *__thiscall vostok::intrusive_ptr<survarium::artefact_base,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator=(
        vostok::intrusive_ptr<survarium::artefact_base,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *this,
        survarium::game_world_object *object)
{
  survarium::game_world_object *m_object; // [esp+Ch] [ebp-Ch]
  vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> v5; // [esp+14h] [ebp-4h] BYREF

  v5.m_object = 0;
  if ( object )
  {
    vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v5);
    v5.m_object = object;
    vostok::threading::interlocked_increment(&object->vostok::resources::unmanaged_intrusive_base);
  }
  m_object = v5.m_object;
  v5.m_object = (survarium::game_world_object *)this->m_object;
  this->m_object = (survarium::artefact_base *)m_object;
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v5);
  return this;
}


vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *__thiscall vostok::intrusive_ptr<vostok::sound::encoded_sound_with_qualities,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator=(
        vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *this,
        vostok::sound::sound_spl *object)
{
  vostok::sound::encoded_sound_interface *m_object; // [esp+Ch] [ebp-18h]
  vostok::intrusive_ptr<vostok::sound::sound_spl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v5; // [esp+20h] [ebp-4h] BYREF

  v5.m_object = 0;
  vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v5,
    object);
  m_object = (vostok::sound::encoded_sound_interface *)v5.m_object;
  v5.m_object = (vostok::sound::sound_spl *)this->m_object;
  this->m_object = m_object;
  vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v5);
  return this;
}


vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *__userpurge vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=@<eax>(
        const vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *object@<eax>,
        vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *this)
{
  vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v2; // ebp
  vostok::render::light *v3; // ecx
  vostok::render::light *m_object; // edi
  vostok::render::grass_render_model *v6; // esi

  v2 = this;
  this = 0;
  vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
    (vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&this,
    (const vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&this,
    object);
  m_object = v2->m_object;
  v2->m_object = (vostok::render::light *)this;
  if ( m_object )
  {
    if ( m_object->m_reference_count-- == 1 )
    {
      v6 = vostok::render::g_allocator.m_object;
      vostok::render::light::~light(v3);
      BYTE2(v6->m_children_resources.m_lock) = 0;
      vostok_mspace_free((void *)HIDWORD(v6->m_reconstruction_info_actuality_tick), m_object);
    }
  }
  return v2;
}


vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *__userpurge vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=@<eax>(
        vostok::render::light *object@<eax>,
        vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *this)
{
  vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v2; // ebp
  vostok::render::light *v3; // ecx
  vostok::render::light *m_object; // edi
  vostok::render::grass_render_model *v6; // esi

  v2 = this;
  this = 0;
  vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
    (vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&this,
    (vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&this,
    object);
  m_object = v2->m_object;
  v2->m_object = (vostok::render::light *)this;
  if ( m_object )
  {
    if ( m_object->m_reference_count-- == 1 )
    {
      v6 = vostok::render::g_allocator.m_object;
      vostok::render::light::~light(v3);
      BYTE2(v6->m_children_resources.m_lock) = 0;
      vostok_mspace_free((void *)HIDWORD(v6->m_reconstruction_info_actuality_tick), m_object);
    }
  }
  return v2;
}


vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *__thiscall vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::operator=(
        vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *this,
        const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *object)
{
  vostok::resources::managed_resource *m_object; // eax
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v5; // [esp+4h] [ebp-4h] BYREF

  v5.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    &v5,
    object);
  m_object = v5.m_object;
  v5.m_object = this->m_object;
  this->m_object = m_object;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&v5);
  return this;
}


vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *__thiscall vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator=(
        vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *this,
        const vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *object)
{
  vostok::sound::panning_lut **v2; // eax
  vostok::sound::panning_lut *v5; // [esp+10h] [ebp-18h]
  vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v6; // [esp+24h] [ebp-4h] BYREF

  vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v6,
    object);
  v5 = *v2;
  *v2 = this->m_object;
  this->m_object = v5;
  vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v6);
  return this;
}


vostok::render::resource_manager **__usercall vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=@<eax>(
        vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *this@<ecx>,
        vostok::render::resource_manager **a2@<esi>)
{
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v2; // eax
  vostok::render::resource_manager *v3; // ecx
  vostok::render::resource_manager *v4; // eax

  v2 = 0;
  if ( this )
  {
    ++this->m_object;
    v2 = this;
  }
  v3 = (vostok::render::resource_manager *)v2;
  v4 = *a2;
  *a2 = v3;
  if ( v4 )
  {
    if ( v4->sh_created-- == 1 )
      vostok::render::resource_manager::release(
        v3,
        (const vostok::render::render_target *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
  }
  return a2;
}


vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *__usercall vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=@<eax>(
        vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *this@<ecx>,
        const vostok::render::res_geometry **a2@<esi>)
{
  vostok::render::res_geometry *m_object; // ecx
  vostok::render::res_geometry *v3; // eax
  const vostok::render::res_geometry *v4; // ecx
  const vostok::render::res_geometry *v5; // eax

  m_object = this->m_object;
  v3 = 0;
  if ( m_object )
  {
    v3 = m_object;
    ++m_object->m_reference_count;
  }
  v4 = v3;
  v5 = *a2;
  *a2 = v4;
  if ( v5 )
  {
    if ( v5->m_reference_count-- == 1 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v5);
  }
  return (vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)a2;
}


vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *__usercall vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=@<eax>(
        vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *this@<ecx>,
        const vostok::render::res_geometry **a2@<esi>)
{
  vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v2; // eax
  vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v3; // ecx
  const vostok::render::res_geometry *v4; // eax

  v2 = 0;
  if ( this )
  {
    ++this->m_object;
    v2 = this;
  }
  v3 = v2;
  v4 = *a2;
  *a2 = (const vostok::render::res_geometry *)v3;
  if ( v4 )
  {
    if ( v4->m_reference_count-- == 1 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v4);
  }
  return (vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)a2;
}


vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *__usercall vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=@<eax>(
        vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *this@<ecx>,
        vostok::render::res_texture **a2@<edi>)
{
  vostok::render::res_texture *m_object; // ecx
  vostok::render::res_texture *v3; // eax
  vostok::render::res_texture *v4; // esi

  m_object = this->m_object;
  v3 = 0;
  if ( m_object )
  {
    v3 = m_object;
    ++m_object->m_reference_count;
  }
  v4 = *a2;
  *a2 = v3;
  if ( v4 )
  {
    if ( v4->m_reference_count-- == 1 )
      vostok::render::res_texture::destroy_impl(m_object);
  }
  return (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)a2;
}


vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **__usercall vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=@<eax>(
        vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *this@<ecx>,
        vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **a2@<edi>)
{
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v2; // eax
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v3; // esi

  v2 = 0;
  if ( this )
  {
    ++this[1].m_object;
    v2 = this;
  }
  v3 = *a2;
  *a2 = v2;
  if ( v3 )
  {
    if ( v3[1].m_object-- == (vostok::render::res_texture *)1 )
      vostok::render::res_texture::destroy_impl((vostok::render::res_texture *)this);
  }
  return a2;
}


vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *__thiscall vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>::operator=(
        vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *this,
        const vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *object)
{
  vostok::sound::sound_instance_proxy *m_object; // eax
  vostok::sound::sound_instance_proxy *v4; // ecx

  m_object = 0;
  if ( object->m_object )
  {
    m_object = object->m_object;
    ++object->m_object->m_reference_count;
  }
  v4 = this->m_object;
  this->m_object = m_object;
  if ( v4 )
  {
    if ( v4->m_reference_count-- == 1 )
      v4->free_object(v4);
  }
  return this;
}


vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy> **__usercall vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy>::operator=@<eax>(
        vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy> *this@<ecx>,
        vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy> **a2@<esi>)
{
  vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy> *v2; // eax
  vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy> *v3; // ecx
  vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy> *v4; // eax

  v2 = 0;
  if ( this )
  {
    v2 = this;
    _InterlockedExchangeAdd((volatile signed __int32 *)&this[4], 1u);
  }
  v3 = v2;
  v4 = *a2;
  *a2 = v3;
  if ( v4 && !_InterlockedExchangeAdd((volatile signed __int32 *)&v4[4], 0xFFFFFFFF) )
    (*(void (__thiscall **)(vostok::network_core::udp_match_packets_allocator *, vostok::intrusive_ptr<vostok::network_core::udp_match_packets_allocator,vostok::network_core::udp_match_packets_allocator,vostok::threading::multi_threading_policy> *))&v4[3].m_object->m_free_list_head.pointer->data[24])(
      v4[3].m_object,
      v4);
  return a2;
}


vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *__thiscall vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator=(
        vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *this,
        const vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *object)
{
  vostok::resources::unmanaged_resource *m_object; // eax
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v5; // [esp+4h] [ebp-4h] BYREF

  v5.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v5,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)object);
  m_object = this->m_object;
  this->m_object = v5.m_object;
  if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &m_object->vostok::resources::unmanaged_intrusive_base,
      m_object);
  return this;
}


vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *__usercall vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=@<eax>(
        vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *this@<ecx>,
        const vostok::render::untyped_buffer **a2@<esi>)
{
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v2; // eax
  const vostok::render::untyped_buffer *v3; // edi

  v2 = 0;
  if ( this )
  {
    ++this->m_object;
    v2 = this;
  }
  v3 = *a2;
  *a2 = (const vostok::render::untyped_buffer *)v2;
  if ( v3 )
  {
    if ( v3->m_reference_count-- == 1 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v3);
  }
  return (vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)a2;
}


vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *__usercall vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::operator=@<eax>(
        vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *this@<edi>,
        const vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *object@<esi>)
{
  vostok::vfs::vfs_mount *m_object; // eax
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> v4; // [esp+0h] [ebp-4h] BYREF

  m_object = 0;
  v4.m_object = 0;
  if ( object->m_object )
  {
    vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::dec(&v4);
    m_object = object->m_object;
    v4.m_object = m_object;
    if ( m_object )
    {
      _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
      m_object = v4.m_object;
    }
  }
  v4.m_object = this->m_object;
  this->m_object = m_object;
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::dec(&v4);
  return this;
}


vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *__usercall vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::operator=@<eax>(
        vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *this@<esi>,
        vostok::vfs::vfs_mount *object@<eax>,
        vostok::vfs::vfs_mount *a3@<ecx>)
{
  vostok::vfs::vfs_mount **v3; // eax
  vostok::vfs::vfs_mount *v4; // ecx
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> v6; // [esp+0h] [ebp-4h] BYREF

  v6.m_object = a3;
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
    &v6,
    object);
  v4 = *v3;
  *v3 = this->m_object;
  this->m_object = v4;
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::dec(&v6);
  return this;
}


vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *__thiscall vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator=(
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *this,
        const vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *object)
{
  survarium::weapon_user_animations_container *m_object; // [esp+Ch] [ebp-Ch]
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v5; // [esp+14h] [ebp-4h] BYREF

  v5.m_object = 0;
  if ( object->m_object )
  {
    vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v5);
    v5.m_object = object->m_object;
    if ( v5.m_object )
      vostok::threading::interlocked_increment(&v5.m_object->vostok::resources::unmanaged_intrusive_base);
  }
  m_object = v5.m_object;
  v5.m_object = this->m_object;
  this->m_object = m_object;
  vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v5);
  return this;
}


BOOL __thiscall vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator!(
        vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *this)
{
  return this->m_object == 0;
}


BOOL __thiscall vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator==(
        vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *this,
        const survarium::inventory_item *const object)
{
  return this->m_object == object;
}


BOOL __usercall vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::operator==@<eax>(
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *this@<eax>,
        const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *object@<edx>)
{
  return this->m_object == object->m_object;
}


BOOL __usercall vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::operator!=@<eax>(
        const stlp_std::reverse_iterator<unsigned int *> *__x@<eax>,
        const stlp_std::reverse_iterator<unsigned int *> *__y@<edx>)
{
  return __x->current != __y->current;
}


BOOL __thiscall vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::operator!=(
        vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *this,
        const vostok::vfs::vfs_mount *const object)
{
  return this->m_object != object;
}


vostok::physics::bt_collision_shape *__thiscall vostok::intrusive_ptr<vostok::resources::unmanaged_allocation_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator->(
        vostok::intrusive_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *this)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  return this->m_object;
}
