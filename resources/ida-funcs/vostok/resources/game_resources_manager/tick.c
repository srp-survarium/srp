void __usercall vostok::resources::game_resources_manager::tick(
        vostok::resources::game_resources_manager *this@<ecx>,
        vostok::resources::game_resources_manager *a2@<eax>)
{
  vostok::resources::game_resources_manager *v3; // ecx
  vostok::resources::game_resources_manager *v4; // ecx
  vostok::resources::releasing_functionality *v5; // ecx
  vostok::resources::quality_increase_functionality *v6; // ecx
  vostok::resources::quality_increase_functionality v7; // [esp+8h] [ebp-8h] BYREF
  vostok::resources::game_resources_manager_data *p_m_data; // [esp+Ch] [ebp-4h] BYREF

  vostok::resources::game_resources_manager::dispatch_capture(this, a2);
  vostok::resources::game_resources_manager::tick_memory_types(v3, a2);
  if ( (a2->m_data.flags.m_flags & 1) != 0 )
  {
    vostok::resources::game_resources_manager::dispatch_capture(v4, a2);
    p_m_data = &a2->m_data;
    if ( vostok::resources::releasing_functionality::release_all_resources(
           v5,
           (vostok::resources::resource_base *)&p_m_data) )
    {
      _InterlockedAnd(&a2->m_data.flags.m_flags, 0xFFFFFFFE);
      SetEvent(*(HANDLE *)s_resources_manager_buffer.m_resources_wakeup_event.m_event.m_event);
    }
  }
  vostok::resources::game_resources_manager::dispatch_resources_to_release(v4, (int)a2);
  vostok::resources::quality_increase_functionality::quality_increase_functionality(&v7, &a2->m_data);
  vostok::resources::quality_increase_functionality::tick(v6, &v7);
}
