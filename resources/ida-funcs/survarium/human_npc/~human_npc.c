void __thiscall survarium::human_npc::~human_npc(survarium::human_npc *this)
{
  int f; // ebp
  survarium::animations_selector *m_animations_selector; // esi
  survarium::animations_selector *v4; // eax
  void *v5; // esi
  survarium::animation_space_graph *m_object; // eax
  boost::detail::function::vtable_base *vtable; // eax
  void (__cdecl *v8)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::resources::unmanaged_resource *v9; // eax
  vostok::render::base_scene *v10; // eax
  survarium::animated_model_instance *v11; // eax
  vostok::resources::unmanaged_resource *v12; // eax
  survarium::human_npc *v13; // eax
  survarium::human_npc *v14; // eax
  vostok::resources::unmanaged_resource *v15; // ecx
  vostok::loose_ptr_data *m_pointer; // eax
  vostok::loose_ptr_data *v17; // eax

  f = (int)survarium::g_allocator.f_.f_;
  this->vostok::ai::npc::__vftable = (survarium::human_npc_vtbl *)&survarium::human_npc::`vftable'{for `vostok::ai::npc'};
  this->vostok::ai::game_object::__vftable = (vostok::ai::game_object_vtbl *)&survarium::human_npc::`vftable'{for `vostok::ai::game_object'};
  this->vostok::sound::sound_producer::__vftable = (vostok::sound::sound_producer_vtbl *)&survarium::human_npc::`vftable'{for `vostok::sound::sound_producer'};
  this->vostok::sound::sound_receiver::__vftable = (vostok::sound::sound_receiver_vtbl *)&survarium::human_npc::`vftable'{for `vostok::sound::sound_receiver'};
  this->survarium::hit_receiver::vostok::collision::game_object::__vftable = (survarium::hit_receiver_vtbl *)&survarium::human_npc::`vftable'{for `survarium::hit_receiver'};
  this->survarium::game_object_::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (survarium::game_object__vtbl *)&survarium::human_npc::`vftable'{for `survarium::game_object_'};
  m_animations_selector = this->m_animations_selector;
  if ( m_animations_selector )
  {
    survarium::animations_selector::~animations_selector(
      (survarium::animations_selector *)this,
      (int)m_animations_selector);
    v4 = m_animations_selector;
    v5 = *(void **)(f + 20);
    *(_BYTE *)(f + 42) = 0;
    vostok_mspace_free(v5, v4);
    this->m_animations_selector = 0;
  }
  m_object = this->m_animation_space_graph.m_object;
  if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &this->m_animation_space_graph.m_object->vostok::resources::unmanaged_intrusive_base,
      this->m_animation_space_graph.m_object);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&this->m_default_animation);
  vtable = this->m_affects_subscription.subscription_callback.vtable;
  if ( vtable )
  {
    if ( ((unsigned __int8)vtable & 1) == 0 )
    {
      v8 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((unsigned int)vtable & 0xFFFFFFFE);
      if ( v8 )
        v8(
          &this->m_affects_subscription.subscription_callback.functor,
          &this->m_affects_subscription.subscription_callback.functor,
          2);
    }
    this->m_affects_subscription.subscription_callback.vtable = 0;
  }
  v9 = this->m_sound_scene.m_object;
  if ( v9 && !_InterlockedExchangeAdd(&v9->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &this->m_sound_scene.m_object->vostok::resources::unmanaged_intrusive_base,
      this->m_sound_scene.m_object);
  v10 = this->m_scene.m_object;
  if ( v10 && !_InterlockedExchangeAdd(&v10->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &this->m_scene.m_object->vostok::resources::unmanaged_intrusive_base,
      this->m_scene.m_object);
  DeleteCriticalSection((LPCRITICAL_SECTION)&this->m_game_attributes.weapons.vostok::threading::mutex);
  v11 = this->m_model_instance.m_object;
  if ( v11 && !_InterlockedExchangeAdd(&v11->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &this->m_model_instance.m_object->vostok::resources::unmanaged_intrusive_base,
      this->m_model_instance.m_object);
  v12 = this->m_brain_unit.m_object;
  if ( v12 && !_InterlockedExchangeAdd(&v12->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &this->m_brain_unit.m_object->vostok::resources::unmanaged_intrusive_base,
      this->m_brain_unit.m_object);
  v13 = this->next_npc.m_object;
  if ( v13 && !_InterlockedExchangeAdd(&v13->m_reference_count, 0xFFFFFFFF) )
  {
    v14 = this->next_npc.m_object;
    if ( v14 )
      v15 = &v14->survarium::game_object_;
    else
      v15 = 0;
    vostok::resources::unmanaged_intrusive_base::destroy(&v14->vostok::resources::unmanaged_intrusive_base, v15);
  }
  vostok::resources::unmanaged_resource::~unmanaged_resource(&this->survarium::game_object_);
  this->survarium::hit_receiver::vostok::collision::game_object::__vftable = (survarium::hit_receiver_vtbl *)&survarium::hit_receiver::`vftable';
  if ( --this->survarium::hit_receiver::vostok::loose_ptr_base::m_pointer->m_reference_count )
  {
    this->survarium::hit_receiver::vostok::loose_ptr_base::m_pointer->survarium::hit_receiver::vostok::loose_ptr_base::m_pointer = 0;
  }
  else
  {
    m_pointer = this->survarium::hit_receiver::vostok::loose_ptr_base::m_pointer;
    if ( m_pointer )
    {
      pt3free(m_pointer);
      this->survarium::hit_receiver::vostok::loose_ptr_base::m_pointer = 0;
    }
  }
  vostok::sound::sound_receiver::~sound_receiver(&this->vostok::sound::sound_receiver);
  vostok::sound::sound_producer::~sound_producer(&this->vostok::sound::sound_producer);
  if ( --this->vostok::ai::game_object::vostok::loose_ptr_base::m_pointer->vostok::sound::sound_producer::m_reference_count )
  {
    this->vostok::ai::game_object::vostok::loose_ptr_base::m_pointer->vostok::ai::game_object::vostok::loose_ptr_base::m_pointer = 0;
  }
  else
  {
    v17 = this->vostok::ai::game_object::vostok::loose_ptr_base::m_pointer;
    if ( v17 )
    {
      pt3free(v17);
      this->vostok::ai::game_object::vostok::loose_ptr_base::m_pointer = 0;
    }
  }
}
