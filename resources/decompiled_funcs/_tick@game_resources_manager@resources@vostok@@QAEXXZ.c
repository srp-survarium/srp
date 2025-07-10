void __usercall vostok::resources::game_resources_manager::tick(
        vostok::resources::game_resources_manager *this@<ecx>,
        vostok::resources::game_resources_manager *a2@<eax>,
        double a3@<st0>)
{
  vostok::resources::game_resources_manager *v4; // ecx
  vostok::resources::memory_type *i; // edi
  vostok::resources::releasing_functionality *v6; // ecx
  vostok::resources::quality_increase_functionality *v7; // ecx
  vostok::resources::quality_increase_functionality quality_increase; // [esp+10h] [ebp-4h] BYREF

  vostok::resources::game_resources_manager::dispatch_capture(this, a2, a3);
  for ( i = a2->m_data.memory_types.m_first; i; i = i->m_next )
    vostok::resources::game_resources_manager::tick_memory_type(a2, i);
  if ( (a2->m_data.flags.m_flags & 1) != 0 )
  {
    vostok::resources::game_resources_manager::dispatch_capture(v4, a2, a3);
    if ( vostok::resources::releasing_functionality::release_all_resources(v6) )
    {
      vostok::threading::interlocked_and(&a2->m_data.flags.m_flags, 0xFFFFFFFE);
      SetEvent(*(HANDLE *)((char *)&dword_203D0 + (unsigned int)vostok::resources::g_resources_manager.m_variable));
    }
  }
  vostok::resources::game_resources_manager::dispatch_resources_to_release(v4, a2);
  vostok::resources::quality_increase_functionality::quality_increase_functionality(&quality_increase, &a2->m_data);
  vostok::resources::quality_increase_functionality::tick(v7, &quality_increase);
}
