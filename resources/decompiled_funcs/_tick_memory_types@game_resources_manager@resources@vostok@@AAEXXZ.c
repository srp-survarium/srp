void __usercall vostok::resources::game_resources_manager::tick_memory_types(
        vostok::resources::game_resources_manager *this@<ecx>,
        vostok::resources::game_resources_manager *a2@<esi>,
        double a3@<st0>)
{
  vostok::resources::memory_type *i; // edi

  for ( i = a2->m_data.memory_types.m_first; i; i = i->m_next )
    vostok::resources::game_resources_manager::tick_memory_type(i, a3, a2);
}
