void __usercall vostok::buffer_vector<survarium::animations_registry::animations_tuple>::destroy(
        survarium::animations_registry::animations_tuple *begin@<eax>,
        survarium::animations_registry::animations_tuple *const *end@<edi>)
{
  while ( begin != *end )
  {
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&begin->third_view);
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&begin->first_view);
    ++begin;
  }
}


void __usercall vostok::buffer_vector<survarium::particle_game_effect_presenter::effect_data>::destroy(
        survarium::particle_game_effect_presenter::effect_data *begin@<eax>,
        survarium::particle_game_effect_presenter::effect_data *const *end@<edi>)
{
  while ( begin != *end )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&begin->particle_system);
    survarium::loose_ptr<survarium::particle_game_effect const,survarium::loose_ptr_data,vostok::threading::single_threading_policy>::~loose_ptr<survarium::particle_game_effect const,survarium::loose_ptr_data,vostok::threading::single_threading_policy>(&begin->effect);
    ++begin;
  }
}


void __usercall vostok::buffer_vector<survarium::sound_game_effect_presenter::effect_data>::destroy(
        survarium::loose_ptr<survarium::particle_game_effect const ,survarium::loose_ptr_data,vostok::threading::single_threading_policy> *begin@<eax>,
        survarium::loose_ptr<survarium::particle_game_effect const ,survarium::loose_ptr_data,vostok::threading::single_threading_policy> **end@<edi>)
{
  while ( begin != *end )
  {
    vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>::dec((vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *)&begin[2]);
    survarium::loose_ptr<survarium::particle_game_effect const,survarium::loose_ptr_data,vostok::threading::single_threading_policy>::~loose_ptr<survarium::particle_game_effect const,survarium::loose_ptr_data,vostok::threading::single_threading_policy>(begin);
    begin += 3;
  }
}


void __cdecl vostok::buffer_vector<vostok::render::light_data>::destroy(
        vostok::render::light_data *begin,
        vostok::render::light_data *const *end)
{
  vostok::render::light *v2; // ecx
  vostok::render::light *m_object; // eax
  char *v6; // edi
  vostok::memory::doug_lea_allocator *v7; // esi
  vostok::memory::doug_lea_allocator *v8; // ecx
  const char *v9; // [esp+0h] [ebp-Ch]
  const char *v10; // [esp+4h] [ebp-8h]
  unsigned int v11; // [esp+8h] [ebp-4h]

  while ( begin != *end )
  {
    m_object = begin->light.m_object;
    if ( begin->light.m_object )
    {
      if ( m_object->m_reference_count-- == 1 )
      {
        v6 = (char *)begin->light.m_object;
        v7 = vostok::render::g_allocator;
        if ( begin->light.m_object )
        {
          vostok::render::light::remove_collision(v2, (int)v6);
          `vector destructor iterator'(
            v6 + 724,
            4u,
            6,
            (void (__thiscall *)(void *))vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>);
          `vector destructor iterator'(
            v6 + 700,
            4u,
            6,
            (void (__thiscall *)(void *))vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>);
          vostok::memory::doug_lea_allocator::free_impl(v8, (int)v7, v6, v9, v10, v11);
        }
      }
    }
    ++begin;
  }
}


void __usercall vostok::buffer_vector<vostok::render::streaming_ready_texture>::destroy(
        vostok::render::streaming_ready_texture *begin@<eax>,
        vostok::render::streaming_ready_texture *const *end@<edi>)
{
  while ( begin != *end )
  {
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&begin->data);
    vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec(&begin->texture);
    ++begin;
  }
}


void __usercall vostok::buffer_vector<vostok::tasks::thread_tls>::destroy(
        vostok::tasks::thread_tls *begin@<eax>,
        vostok::tasks::thread_tls **end)
{
  vostok::tasks::thread_tls *i; // edi
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v3; // ecx

  for ( i = begin; i != *end; ++i )
  {
    CloseHandle(*(HANDLE *)i->event_wait_for_children.m_event.m_event);
    CloseHandle(*(HANDLE *)i->event_pause_ended.m_event);
    CloseHandle(*(HANDLE *)i->event_start_thread_work.m_event);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v3,
      (int *)&i->user_thread_root_task.m_function);
    CloseHandle(*(HANDLE *)i->event_should_work.m_event);
  }
}
