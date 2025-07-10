void __thiscall vostok::sound::sound_scene::init_allocators(
        vostok::sound::sound_scene *this,
        vostok::resources::query_result_for_cook *parent)
{
  vostok::physics::bt_collision_shape *v2; // eax
  vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> *v3; // eax
  vostok::physics::bt_collision_shape *v4; // eax
  vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> *v5; // eax
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > v6; // [esp-14h] [ebp-11Ch]
  unsigned int v7; // [esp-4h] [ebp-10Ch]
  unsigned int v8; // [esp-4h] [ebp-10Ch]
  vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> *v10; // [esp+88h] [ebp-80h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > result; // [esp+98h] [ebp-70h] BYREF
  void (__thiscall *f)(vostok::sound::sound_scene *, vostok::resources::queries_result *); // [esp+A8h] [ebp-60h]
  int f_4; // [esp+ACh] [ebp-5Ch]
  boost::function1<void,vostok::resources::queries_result &> v14; // [esp+B0h] [ebp-58h] BYREF
  unsigned int proxies_size; // [esp+D4h] [ebp-34h]
  unsigned int receiver_collisions_size; // [esp+D8h] [ebp-30h]
  unsigned int receivers_positions_offset; // [esp+DCh] [ebp-2Ch]
  unsigned int receivers_collisions_offset; // [esp+E0h] [ebp-28h]
  unsigned int allocation_size; // [esp+E4h] [ebp-24h]
  vostok::resources::creation_request request; // [esp+E8h] [ebp-20h] BYREF
  unsigned int propagators_size; // [esp+F8h] [ebp-10h]
  unsigned int receiver_positions_size; // [esp+FCh] [ebp-Ch]
  unsigned int proxies_offset; // [esp+100h] [ebp-8h]
  unsigned int propagators_offset; // [esp+104h] [ebp-4h]

  proxies_size = 536 * this->m_proxies_count;
  propagators_size = 108 * this->m_propagators_count;
  receiver_positions_size = 8 * this->m_receivers_count;
  receiver_collisions_size = 16 * this->m_receivers_count;
  allocation_size = receiver_collisions_size + receiver_positions_size + propagators_size + proxies_size;
  vostok::resources::creation_request::creation_request(
    &request,
    "unmanaged_sound_resources_allocation",
    allocation_size,
    unmanaged_allocation_class);
  f = vostok::sound::sound_scene::on_unmanaged_resources_allocated;
  f_4 = 0;
  v6 = *boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>(
          (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&result,
          (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)vostok::sound::sound_scene::on_unmanaged_resources_allocated,
          (survarium::weapon_core_animation_end_aware_state *)this);
  boost::function1<void,vostok::resources::queries_result &>::function1<void,vostok::resources::queries_result &>(
    &v14,
    (boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_scene,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_scene *>,boost::arg<1> > >)v6,
    0);
  vostok::resources::query_create_resources_and_wait(
    &request,
    1u,
    (const boost::function<void __cdecl(vostok::resources::queries_result &)> *)&v14,
    (vostok::memory::base_allocator *)vostok::sound::g_allocator.m_object,
    0,
    parent,
    assert_on_fail_true);
  boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&v14);
  proxies_offset = 0;
  if ( this != (vostok::sound::sound_scene *)-328 )
    vostok::memory::single_size_buffer_allocator<536,vostok::threading::multi_threading_policy>::single_size_buffer_allocator<536,vostok::threading::multi_threading_policy>(
      (vostok::memory::single_size_buffer_allocator<536,vostok::threading::multi_threading_policy> *)&this->m_proxies_allocator,
      &this->m_memory_arena_resources_ptr.m_object->buffer[proxies_offset],
      proxies_size);
  _InterlockedExchange(&this->m_proxies_allocator.m_initialized, 1);
  propagators_offset = proxies_size + proxies_offset;
  if ( this != (vostok::sound::sound_scene *)-368 )
    vostok::memory::single_size_buffer_allocator<108,vostok::threading::single_threading_policy>::single_size_buffer_allocator<108,vostok::threading::single_threading_policy>(
      (vostok::memory::single_size_buffer_allocator<108,vostok::threading::single_threading_policy> *)&this->m_propagators_allocator,
      &this->m_memory_arena_resources_ptr.m_object->buffer[propagators_offset],
      propagators_size);
  _InterlockedExchange(&this->m_propagators_allocator.m_initialized, 1);
  receivers_positions_offset = propagators_size + propagators_offset;
  if ( this == (vostok::sound::sound_scene *)-400 )
  {
    vostok::uninitialized_reference<vostok::memory::single_size_buffer_allocator<8,vostok::threading::single_threading_policy>>::operator+(
      0,
      0);
  }
  else
  {
    v7 = receiver_positions_size;
    v2 = vostok::intrusive_ptr<vostok::resources::unmanaged_allocation_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator->((vostok::intrusive_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_memory_arena_resources_ptr);
    vostok::memory::single_size_buffer_allocator<8,vostok::threading::single_threading_policy>::single_size_buffer_allocator<8,vostok::threading::single_threading_policy>(
      (vostok::memory::single_size_buffer_allocator<8,vostok::threading::single_threading_policy> *)&this->m_receiver_positions_allocator,
      (char *)&v2->m_tri_face_data + receivers_positions_offset,
      v7);
    vostok::uninitialized_reference<vostok::memory::single_size_buffer_allocator<8,vostok::threading::single_threading_policy>>::operator+(
      (vostok::uninitialized_reference<vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> > *)&this->m_receiver_positions_allocator,
      v3);
  }
  receivers_collisions_offset = receiver_positions_size + receivers_positions_offset;
  v10 = vostok::uninitialized_reference<vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy>>::construction_memory(&this->m_receiver_collisions_allocator);
  if ( v10 )
  {
    v8 = receiver_collisions_size;
    v4 = vostok::intrusive_ptr<vostok::resources::unmanaged_allocation_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator->((vostok::intrusive_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_memory_arena_resources_ptr);
    vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy>::single_size_buffer_allocator<16,vostok::threading::single_threading_policy>(
      v10,
      (char *)&v4->m_tri_face_data + receivers_collisions_offset,
      v8);
    vostok::uninitialized_reference<vostok::memory::single_size_buffer_allocator<8,vostok::threading::single_threading_policy>>::operator+(
      &this->m_receiver_collisions_allocator,
      v5);
  }
  else
  {
    vostok::uninitialized_reference<vostok::memory::single_size_buffer_allocator<8,vostok::threading::single_threading_policy>>::operator+(
      &this->m_receiver_collisions_allocator,
      0);
  }
}
