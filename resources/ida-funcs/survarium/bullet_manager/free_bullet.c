void __userpurge survarium::bullet_manager::free_bullet(
        survarium::bullet_manager *this@<ecx>,
        survarium::bullet *bullet@<eax>,
        bool notification_needed)
{
  survarium::statistics_events_handler *m_statistics_events_handler; // ecx
  vostok::memory::single_size_buffer_allocator<140,vostok::threading::simple_lock> *m_variable; // edi
  vostok::memory::multi_threading_single_size_allocator_policy<vostok::memory::single_size_buffer_allocator<140,vostok::threading::simple_lock>::node>::free_list_type v7; // [esp+Ch] [ebp-Ch] BYREF

  if ( notification_needed && bullet->m_last_hitted_player != 0xFF )
  {
    m_statistics_events_handler = this->m_game_world_core->m_statistics_events_handler;
    if ( m_statistics_events_handler )
      ((void (__stdcall *)(_DWORD, survarium::profile_slot_enum, survarium::player_stances_enum, float))m_statistics_events_handler->on_hitting_bullet_destruction)(
        bullet->m_initiator->id,
        bullet->m_weapon->m_slot_id,
        bullet->m_initiator_stance,
        bullet->m_max_damage_dealt);
  }
  if ( this->m_engine && bullet->m_tracer_idx != 0xFFFF )
    this->m_engine->detach_tracer(this->m_engine, bullet);
  m_variable = this->m_bullets_allocator_ref.m_variable;
  if ( bullet )
  {
    v7.pointer = (vostok::memory::single_size_buffer_allocator<140,vostok::threading::simple_lock>::node *)bullet;
    vostok::memory::multi_threading_single_size_allocator_policy<vostok::memory::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy>::node>::deallocate(
      &v7,
      &m_variable->m_free_list_head);
    _InterlockedExchangeAdd(&m_variable->m_allocated_count, 0xFFFFFFFF);
  }
}
