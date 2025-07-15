void __userpurge vostok::intrusive_ptr<vostok::render::decal_instance,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
        vostok::intrusive_ptr<vostok::render::decal_instance,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *this@<ecx>,
        vostok::memory::detail::call_destructor_predicate *a2@<edi>,
        vostok::intrusive_ptr<vostok::render::decal_instance,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *object,
        vostok::render::decal_instance *objecta)
{
  vostok::render::decal_instance *m_object; // eax
  vostok::render::decal_instance *v6; // esi
  vostok::render::grass_render_model *v7; // edi
  vostok::render::decal_instance *v8; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi

  m_object = object->m_object;
  if ( object->m_object != objecta )
  {
    if ( m_object )
    {
      if ( m_object->m_reference_count-- == 1 )
      {
        v6 = object->m_object;
        v7 = vostok::render::g_allocator.m_object;
        if ( object->m_object )
        {
          vostok::memory::detail::call_destructor_predicate::operator()<vostok::render::decal_instance>(
            v6,
            (vostok::render::decal_instance *)this,
            a2);
          v8 = v6;
          m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(v7->m_reconstruction_info_actuality_tick);
          BYTE2(v7->m_children_resources.m_lock) = 0;
          vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v8);
        }
      }
    }
    object->m_object = objecta;
    if ( objecta )
      ++objecta->m_reference_count;
  }
}


void __thiscall vostok::intrusive_ptr<vostok::resources::unmanaged_allocation_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *this,
        survarium::weapon_user_animations_container *object)
{
  if ( this->m_object != object )
  {
    vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(this);
    this->m_object = object;
    if ( this->m_object )
      vostok::threading::interlocked_increment(&this->m_object->vostok::resources::unmanaged_intrusive_base);
  }
}


void __thiscall vostok::intrusive_ptr<survarium::artefact_base,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
        vostok::intrusive_ptr<survarium::artefact_base,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *this,
        const vostok::intrusive_ptr<survarium::artefact_base,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *object)
{
  if ( this->m_object != object->m_object )
  {
    vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)this);
    this->m_object = object->m_object;
    if ( this->m_object )
      vostok::threading::interlocked_increment(&this->m_object->vostok::resources::unmanaged_intrusive_base);
  }
}


void __thiscall vostok::intrusive_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
        vostok::intrusive_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *this,
        survarium::booby_trap_core *object)
{
  if ( this->m_object != object )
  {
    vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)this);
    this->m_object = object;
    if ( this->m_object )
      vostok::threading::interlocked_increment(&this->m_object->vostok::resources::unmanaged_intrusive_base);
  }
}


void __thiscall vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
        vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *this,
        const vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *object)
{
  if ( this->m_object != object->m_object )
  {
    vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)this);
    this->m_object = object->m_object;
    if ( this->m_object )
      _InterlockedExchangeAdd(&this->m_object->m_reference_count, 1u);
  }
}


void __thiscall vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
        vostok::intrusive_ptr<vostok::sound::sound_spl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *this,
        vostok::sound::sound_spl *object)
{
  if ( this->m_object != object )
  {
    vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)this);
    this->m_object = object;
    if ( this->m_object )
      _InterlockedExchangeAdd(&this->m_object->m_reference_count, 1u);
  }
}


void __usercall vostok::intrusive_ptr<survarium::human_npc,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
        vostok::intrusive_ptr<survarium::human_npc,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *this@<esi>,
        const vostok::intrusive_ptr<survarium::human_npc,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *object@<edi>)
{
  survarium::human_npc *m_object; // eax
  survarium::human_npc *v3; // eax
  vostok::resources::unmanaged_resource *v4; // ecx
  survarium::human_npc *v5; // eax

  m_object = this->m_object;
  if ( this->m_object != object->m_object )
  {
    if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    {
      v3 = this->m_object;
      if ( this->m_object )
        v4 = &v3->survarium::game_object_;
      else
        v4 = 0;
      vostok::resources::unmanaged_intrusive_base::destroy(&v3->vostok::resources::unmanaged_intrusive_base, v4);
    }
    v5 = object->m_object;
    this->m_object = object->m_object;
    if ( v5 )
      _InterlockedExchangeAdd(&v5->m_reference_count, 1u);
  }
}


void __usercall vostok::intrusive_ptr<survarium::human_npc,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
        vostok::intrusive_ptr<survarium::human_npc,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *this@<edi>,
        survarium::human_npc *object@<esi>)
{
  survarium::human_npc *m_object; // eax
  survarium::human_npc *v3; // eax
  vostok::resources::unmanaged_resource *v4; // ecx

  m_object = this->m_object;
  if ( this->m_object != object )
  {
    if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    {
      v3 = this->m_object;
      if ( this->m_object )
        v4 = &v3->survarium::game_object_;
      else
        v4 = 0;
      vostok::resources::unmanaged_intrusive_base::destroy(&v3->vostok::resources::unmanaged_intrusive_base, v4);
    }
    this->m_object = object;
    if ( object )
      _InterlockedExchangeAdd(&object->m_reference_count, 1u);
  }
}


void __thiscall vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
        vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *this,
        survarium::inventory_item *object)
{
  if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)this) != (vostok::render::skeleton_model_instance *)object )
  {
    vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)this);
    this->m_object = object;
    if ( this->m_object )
      vostok::threading::interlocked_increment(&this->m_object->vostok::resources::unmanaged_intrusive_base);
  }
}


void __thiscall vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
        vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *this,
        const vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *object,
        const vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *objecta)
{
  vostok::render::light *m_object; // eax
  vostok::render::light *v5; // edi
  vostok::render::grass_render_model *v6; // esi
  vostok::render::light *v7; // eax

  m_object = object->m_object;
  if ( object->m_object != objecta->m_object )
  {
    if ( m_object )
    {
      if ( m_object->m_reference_count-- == 1 )
      {
        v5 = object->m_object;
        v6 = vostok::render::g_allocator.m_object;
        if ( object->m_object )
        {
          vostok::render::light::~light((vostok::render::light *)this);
          BYTE2(v6->m_children_resources.m_lock) = 0;
          vostok_mspace_free((void *)HIDWORD(v6->m_reconstruction_info_actuality_tick), v5);
        }
      }
    }
    v7 = objecta->m_object;
    object->m_object = objecta->m_object;
    if ( v7 )
      ++v7->m_reference_count;
  }
}


void __thiscall vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
        vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *this,
        vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *object,
        vostok::render::light *objecta)
{
  vostok::render::light *m_object; // eax
  vostok::render::light *v5; // edi
  vostok::render::grass_render_model *v6; // esi

  m_object = object->m_object;
  if ( object->m_object != objecta )
  {
    if ( m_object )
    {
      if ( m_object->m_reference_count-- == 1 )
      {
        v5 = object->m_object;
        v6 = vostok::render::g_allocator.m_object;
        if ( object->m_object )
        {
          vostok::render::light::~light((vostok::render::light *)this);
          BYTE2(v6->m_children_resources.m_lock) = 0;
          vostok_mspace_free((void *)HIDWORD(v6->m_reconstruction_info_actuality_tick), v5);
        }
      }
    }
    object->m_object = objecta;
    if ( objecta )
      ++objecta->m_reference_count;
  }
}


void __thiscall vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *this,
        const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *object)
{
  vostok::resources::managed_resource *m_object; // eax
  vostok::resources::managed_resource *v4; // eax

  m_object = this->m_object;
  if ( this->m_object != object->m_object )
  {
    if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::managed_intrusive_base::destroy(
        &this->m_object->vostok::resources::managed_intrusive_base,
        this->m_object);
    v4 = object->m_object;
    this->m_object = object->m_object;
    if ( v4 )
      _InterlockedExchangeAdd(&v4->m_reference_count, 1u);
  }
}


void __thiscall vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *this,
        vostok::resources::managed_resource *object)
{
  vostok::resources::managed_resource *m_object; // eax

  m_object = this->m_object;
  if ( this->m_object != object )
  {
    if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::managed_intrusive_base::destroy(
        &this->m_object->vostok::resources::managed_intrusive_base,
        this->m_object);
    this->m_object = object;
    if ( object )
      _InterlockedExchangeAdd(&object->m_reference_count, 1u);
  }
}


void __thiscall vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
        vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *this,
        const vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *object)
{
  if ( this->m_object != object->m_object )
  {
    vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)this);
    this->m_object = object->m_object;
    if ( this->m_object )
      vostok::threading::interlocked_increment(&this->m_object->vostok::resources::unmanaged_intrusive_base);
  }
}


void __usercall vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
        vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *this@<esi>,
        const vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *object@<edi>)
{
  vostok::strings::shared::profile *m_object; // eax
  vostok::strings::shared::profile *v3; // eax

  m_object = this->m_object;
  if ( this->m_object != object->m_object )
  {
    if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
    v3 = object->m_object;
    this->m_object = object->m_object;
    if ( v3 )
      _InterlockedExchangeAdd(&v3->m_reference_count, 1u);
  }
}


void __usercall vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
        vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *this@<edi>,
        vostok::strings::shared::profile *object@<eax>)
{
  vostok::strings::shared::profile *m_object; // eax

  m_object = this->m_object;
  if ( this->m_object != object )
  {
    if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
    this->m_object = object;
    if ( object )
      _InterlockedExchangeAdd(&object->m_reference_count, 1u);
  }
}


void __usercall vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
        vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *this@<esi>,
        const vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *object@<edi>)
{
  vostok::render::render_target *m_object; // eax
  vostok::render::render_target *v4; // eax

  m_object = this->m_object;
  if ( this->m_object != object->m_object )
  {
    if ( m_object )
    {
      if ( m_object->m_reference_count-- == 1 )
        vostok::render::resource_manager::release(
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          (const vostok::render::render_target *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
    }
    v4 = object->m_object;
    this->m_object = object->m_object;
    if ( v4 )
      ++v4->m_reference_count;
  }
}


void __userpurge vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
        vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *this@<ecx>,
        vostok::render::res_texture **a2@<edi>,
        const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *object)
{
  vostok::render::res_texture *v3; // eax
  vostok::render::res_texture *m_object; // eax

  v3 = *a2;
  if ( *a2 != object->m_object )
  {
    if ( v3 )
    {
      if ( v3->m_reference_count-- == 1 )
        vostok::render::res_texture::destroy_impl((vostok::render::res_texture *)this);
    }
    m_object = object->m_object;
    *a2 = object->m_object;
    if ( m_object )
      ++m_object->m_reference_count;
  }
}


void __thiscall vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>::set(
        vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *this,
        const vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *object)
{
  vostok::sound::sound_instance_proxy *m_object; // eax
  vostok::sound::sound_instance_proxy *v5; // eax

  m_object = this->m_object;
  if ( this->m_object != object->m_object )
  {
    if ( m_object )
    {
      if ( m_object->m_reference_count-- == 1 )
        ((void (*)(void))this->m_object->free_object)();
    }
    v5 = object->m_object;
    this->m_object = object->m_object;
    if ( v5 )
      ++v5->m_reference_count;
  }
}


void __thiscall vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>::set(
        vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *this,
        vostok::sound::sound_instance_proxy *object)
{
  vostok::sound::sound_instance_proxy *m_object; // eax

  m_object = this->m_object;
  if ( this->m_object != object )
  {
    if ( m_object )
    {
      if ( m_object->m_reference_count-- == 1 )
        ((void (*)(void))this->m_object->free_object)();
    }
    this->m_object = object;
    if ( object )
      ++object->m_reference_count;
  }
}


void __thiscall vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
        vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *this,
        const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *object)
{
  vostok::configs::binary_config *m_object; // eax
  vostok::configs::binary_config *v4; // eax

  m_object = this->m_object;
  if ( this->m_object != object->m_object )
  {
    if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &this->m_object->vostok::resources::unmanaged_intrusive_base,
        this->m_object);
    v4 = object->m_object;
    this->m_object = object->m_object;
    if ( v4 )
      _InterlockedExchangeAdd(&v4->m_reference_count, 1u);
  }
}


void __thiscall vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
        vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *this,
        vostok::configs::binary_config *object)
{
  vostok::configs::binary_config *m_object; // eax

  m_object = this->m_object;
  if ( this->m_object != object )
  {
    if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &this->m_object->vostok::resources::unmanaged_intrusive_base,
        this->m_object);
    this->m_object = object;
    if ( object )
      _InterlockedExchangeAdd(&object->m_reference_count, 1u);
  }
}


void __userpurge vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
        vostok::render::untyped_buffer *object@<esi>,
        vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *this)
{
  vostok::render::untyped_buffer *m_object; // eax

  m_object = this->m_object;
  if ( this->m_object != object )
  {
    if ( m_object )
    {
      if ( m_object->m_reference_count-- == 1 )
        vostok::render::resource_manager::release(
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          this->m_object);
    }
    this->m_object = object;
    if ( object )
      ++object->m_reference_count;
  }
}


void __thiscall vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::set(
        vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *this,
        vostok::vfs::vfs_mount *object)
{
  vostok::vfs::vfs_mount *m_object; // eax

  m_object = this->m_object;
  if ( this->m_object != object )
  {
    if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::vfs::vfs_intrusive_mount_base::destroy(this->m_object, this->m_object);
    this->m_object = object;
    if ( object )
      _InterlockedExchangeAdd(&object->m_reference_count, 1u);
  }
}


void __usercall vostok::intrusive_ptr<survarium::victory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
        vostok::intrusive_ptr<survarium::victory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *this@<esi>,
        const vostok::intrusive_ptr<survarium::victory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *object@<edi>)
{
  survarium::victory_item *m_object; // eax
  survarium::victory_item *v3; // eax
  vostok::resources::unmanaged_resource *v4; // ecx
  survarium::victory_item *v5; // eax

  m_object = this->m_object;
  if ( this->m_object != object->m_object )
  {
    if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    {
      v3 = this->m_object;
      if ( this->m_object )
        v4 = &v3->vostok::resources::unmanaged_resource;
      else
        v4 = 0;
      vostok::resources::unmanaged_intrusive_base::destroy(&v3->vostok::resources::unmanaged_intrusive_base, v4);
    }
    v5 = object->m_object;
    this->m_object = object->m_object;
    if ( v5 )
      _InterlockedExchangeAdd(&v5->m_reference_count, 1u);
  }
}


void __usercall vostok::intrusive_ptr<survarium::victory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
        vostok::intrusive_ptr<survarium::victory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *this@<edi>,
        survarium::victory_item *object@<esi>)
{
  survarium::victory_item *m_object; // eax
  survarium::victory_item *v3; // eax
  vostok::resources::unmanaged_resource *v4; // ecx

  m_object = this->m_object;
  if ( this->m_object != object )
  {
    if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    {
      v3 = this->m_object;
      if ( this->m_object )
        v4 = &v3->vostok::resources::unmanaged_resource;
      else
        v4 = 0;
      vostok::resources::unmanaged_intrusive_base::destroy(&v3->vostok::resources::unmanaged_intrusive_base, v4);
    }
    this->m_object = object;
    if ( object )
      _InterlockedExchangeAdd(&object->m_reference_count, 1u);
  }
}


void __thiscall vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
        vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *this,
        const vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *object)
{
  if ( this->m_object != object->m_object )
  {
    vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(this);
    this->m_object = object->m_object;
    if ( this->m_object )
      vostok::threading::interlocked_increment(&this->m_object->vostok::resources::unmanaged_intrusive_base);
  }
}


void __thiscall vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
        vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *this,
        survarium::weapon_core_base_state *object)
{
  if ( this->m_object != object )
  {
    vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(this);
    this->m_object = object;
    if ( this->m_object )
      vostok::threading::interlocked_increment(&this->m_object->vostok::resources::unmanaged_intrusive_base);
  }
}


void __usercall vostok::intrusive_ptr<survarium::weapon_core_shotgun_reload_base_substate,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
        vostok::intrusive_ptr<survarium::weapon_core_shotgun_reload_base_substate,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *this@<esi>,
        const vostok::intrusive_ptr<survarium::weapon_core_shotgun_reload_base_substate,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *object@<edi>)
{
  survarium::weapon_core_shotgun_reload_base_substate *m_object; // eax
  survarium::weapon_core_shotgun_reload_base_substate *v3; // eax
  vostok::resources::unmanaged_resource *v4; // ecx
  survarium::weapon_core_shotgun_reload_base_substate *v5; // eax

  m_object = this->m_object;
  if ( this->m_object != object->m_object )
  {
    if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    {
      v3 = this->m_object;
      if ( this->m_object )
        v4 = &v3->vostok::resources::unmanaged_resource;
      else
        v4 = 0;
      vostok::resources::unmanaged_intrusive_base::destroy(&v3->vostok::resources::unmanaged_intrusive_base, v4);
    }
    v5 = object->m_object;
    this->m_object = object->m_object;
    if ( v5 )
      _InterlockedExchangeAdd(&v5->m_reference_count, 1u);
  }
}
