void __thiscall vostok::resources::game_resources_manager::dispatch_capture(
        vostok::resources::game_resources_manager *this,
        vostok::resources::game_resources_manager *resource,
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> a3)
{
  survarium::pure_game_effect_emitter_base *m_object; // ebx
  char v4; // al
  vostok::resources::managed_resource *v5; // esi
  vostok::resources::base_of_intrusive_base *v6; // eax

  m_object = (survarium::pure_game_effect_emitter_base *)a3.m_object;
  vostok::resources::game_resources_manager::capture_resource(this, resource, a3.m_object);
  v4 = (m_object->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags
      & 1)
     - 1;
  a3.m_object = 0;
  v5 = v4 == 0 ? (vostok::resources::managed_resource *)m_object : 0;
  if ( v5 )
  {
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&a3);
    a3.m_object = v5;
    _InterlockedExchangeAdd(&v5->m_reference_count, 1u);
  }
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
    (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&resource,
    (unsigned __int8)((m_object->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags
                     & 4)
                    - 4) == 0
  ? m_object
  : 0);
  v6 = vostok::resources::resource_flags::cast_base_of_intrusive_base(m_object);
  _InterlockedExchangeAdd(&v6->m_reference_count, 0xFFFFFFFF);
  _InterlockedAnd(&v6->m_flags.m_flags, 0xFFFFFFFD);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&resource);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&a3);
}


void __usercall vostok::resources::game_resources_manager::dispatch_capture(
        vostok::resources::game_resources_manager *this@<ecx>,
        vostok::resources::game_resources_manager *a2@<eax>)
{
  vostok::resources::resource_base *v3; // eax
  vostok::resources::game_resources_manager *v4; // ecx
  vostok::resources::resource_base *m_next_for_query_finished_callback; // edi

  if ( a2->m_resources_to_capture.m_first )
  {
    v3 = vostok::intrusive_list<vostok::resources::resource_base,vostok::resources::resource_base *,180,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::pop_all_and_clear(
           &this->m_resources_to_capture,
           (int)a2);
    if ( v3 )
    {
      do
      {
        m_next_for_query_finished_callback = v3->m_next_for_query_finished_callback;
        vostok::resources::game_resources_manager::dispatch_capture(
          v4,
          a2,
          (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>)v3);
        v3 = m_next_for_query_finished_callback;
      }
      while ( m_next_for_query_finished_callback );
    }
  }
}
