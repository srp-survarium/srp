void __usercall vostok::resources::resources_manager::init_new_autoselect_quality_queries(
        vostok::resources::resources_manager *this@<ecx>,
        int a2@<eax>,
        double m_current_satisfaction@<st0>)
{
  vostok::resources::resource_quality *v4; // ebx
  int v5; // ecx
  vostok::resources::resource_quality *v6; // esi
  vostok::resources::resource_quality *m_lock; // ebx
  vostok::resources::game_resources_manager *m_variable; // edi
  vostok::resources::cook_base *cook; // eax
  bool v10; // zf
  unsigned int m_current_quality_level; // eax
  unsigned __int64 QuadPart; // rax
  boost::intrusive::rbtree_node<void *> *p_header; // edi
  boost::intrusive::rbtree_node<void *> *v14; // esi
  boost::intrusive::detail::tree_algorithms<boost::intrusive::rbtree_node_traits<void *,0> >::insert_commit_data comp; // [esp+10h] [ebp-10h] BYREF
  LARGE_INTEGER PerformanceCount; // [esp+18h] [ebp-8h] BYREF

  if ( *(_DWORD *)((char *)&loc_2030B + a2 + 1) )
  {
    vostok::threading::mutex::lock((vostok::threading::mutex *)((char *)&loc_202EF + a2 + 1));
    v4 = *(vostok::resources::resource_quality **)((char *)&loc_2030B + a2 + 1);
    *(_DWORD *)((char *)&loc_2030B + a2 + 1) = 0;
    *(_DWORD *)((char *)&loc_20310 + a2) = 0;
    *(_DWORD *)((char *)&loc_202E7 + a2 + 1) = 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)((char *)&loc_202EF + a2 + 1));
    v6 = v4;
    if ( v4 )
    {
      do
      {
        m_lock = (vostok::resources::resource_quality *)v6[4].m_parent_resources.m_lock;
        m_variable = vostok::resources::g_game_resources_manager.m_variable;
        cook = vostok::resources::resources_manager::find_cook(v5, v6->m_class_id);
        v6->m_quality_levels_count = cook->calculate_quality_levels_count(
                                       cook,
                                       (const vostok::resources::query_result_for_cook *)v6);
        vostok::resources::resource_quality::update_satisfaction(
          v6,
          m_current_satisfaction,
          m_variable->m_data.current_increase_quality_tick);
        v10 = !vostok::resources::quality_increase_functionality::s_started_tick_timer;
        m_current_satisfaction = v6->m_current_satisfaction;
        m_current_quality_level = v6->m_current_quality_level;
        v6->m_target_satisfaction = v6->m_current_satisfaction;
        v6->m_target_quality_level = m_current_quality_level;
        if ( v10 )
        {
          vostok::resources::quality_increase_functionality::s_started_tick_timer = 1;
          if ( vostok::timing::g_cpu_supports_time_stamp )
          {
            QuadPart = __rdtsc();
          }
          else
          {
            QueryPerformanceCounter(&PerformanceCount);
            QuadPart = PerformanceCount.QuadPart;
          }
          vostok::resources::quality_increase_functionality::s_tick_timer.m_start_time = QuadPart;
          vostok::resources::quality_increase_functionality::s_tick_timer.m_current_time = 0;
        }
        vostok::threading::interlocked_or(&v6->m_flags.m_flags, 0x80u);
        p_header = &m_variable->m_data.increase_quality_tree.tree_.data_.node_plus_pred_.header_plus_size_.header_;
        v14 = (boost::intrusive::rbtree_node<void *> *)&v6[1];
        comp.link_left = 0;
        comp.node = 0;
        boost::intrusive::detail::tree_algorithms<boost::intrusive::rbtree_node_traits<void *,0>>::insert_equal_check_impl<boost::intrusive::detail::key_nodeptr_comp<vostok::resources::compare_by_target_satisfaction,boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::resources::resource_base,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,136>,vostok::resources::compare_by_target_satisfaction,unsigned int,0>>>>(
          v14,
          p_header,
          p_header,
          &comp);
        boost::intrusive::detail::tree_algorithms<boost::intrusive::rbtree_node_traits<void *,0>>::insert_commit(
          p_header,
          v14,
          &comp);
        boost::intrusive::rbtree_algorithms<boost::intrusive::rbtree_node_traits<void *,0>>::rebalance_after_insertion(
          p_header,
          v14);
        v6 = m_lock;
      }
      while ( m_lock );
    }
  }
}
