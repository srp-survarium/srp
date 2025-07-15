void __thiscall vostok::sound::sound_scene::delete_statistic(
        vostok::sound::sound_scene *this,
        vostok::sound::sound_scene_statistic *statistic)
{
  vostok::memory::detail::call_destructor_predicate call_destructor_predicate; // [esp+43h] [ebp-31h] BYREF
  vostok::sound::propagator_statistic *v3; // [esp+5Ch] [ebp-18h]
  vostok::sound::proxy_statistic *m_first; // [esp+60h] [ebp-14h]
  vostok::sound::propagator_statistic *prop_stats_next; // [esp+64h] [ebp-10h]
  vostok::sound::propagator_statistic *prop_stats; // [esp+68h] [ebp-Ch] BYREF
  vostok::sound::proxy_statistic *prx_stats_next; // [esp+6Ch] [ebp-8h]
  vostok::sound::proxy_statistic *prx_stats; // [esp+70h] [ebp-4h] BYREF

  if ( statistic )
  {
    m_first = statistic->m_proxies_statistic.m_first;
    for ( prx_stats = m_first; prx_stats; prx_stats = prx_stats_next )
    {
      prx_stats_next = prx_stats->next;
      v3 = prx_stats->m_propagator_statistics.m_first;
      for ( prop_stats = v3; prop_stats; prop_stats = prop_stats_next )
      {
        prop_stats_next = prop_stats->next;
        vostok::intrusive_list<vostok::sound::proxy_statistic,vostok::sound::proxy_statistic *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::erase(
          (vostok::intrusive_list<vostok::sound::proxy_statistic,vostok::sound::proxy_statistic *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)&prx_stats->m_propagator_statistics,
          (vostok::sound::proxy_statistic *)prop_stats);
        call_destructor_predicate = 0;
        vostok::memory::detail::delete_helper_impl<vostok::memory::doug_lea_allocator,vostok::sound::propagator_statistic,vostok::memory::detail::call_destructor_predicate>(
          (vostok::memory::doug_lea_allocator *)vostok::sound::g_allocator.m_object,
          &prop_stats,
          &call_destructor_predicate);
      }
      vostok::intrusive_list<vostok::sound::proxy_statistic,vostok::sound::proxy_statistic *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::erase(
        &statistic->m_proxies_statistic,
        prx_stats);
      vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::sound::proxy_statistic>(
        (vostok::memory::doug_lea_allocator *)vostok::sound::g_allocator.m_object,
        (vostok::sound::sound_scene_statistic **)&prx_stats);
    }
    vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::sound::proxy_statistic>(
      (vostok::memory::doug_lea_allocator *)vostok::sound::g_allocator.m_object,
      &statistic);
  }
}
