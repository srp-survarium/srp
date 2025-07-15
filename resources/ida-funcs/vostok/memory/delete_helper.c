void __cdecl vostok::memory::delete_helper<vostok::memory::base_allocator,vostok::vfs::node_to_expand>(
        vostok::memory::base_allocator *allocator,
        vostok::vfs::node_to_expand **pointer)
{
  if ( *pointer )
  {
    vostok::memory::base_allocator::free_impl(allocator, *pointer);
    *pointer = 0;
  }
}


void __usercall vostok::memory::delete_helper<vostok::memory::base_allocator,Opcode::AABBTree>(
        Opcode::AABBTree **pointer@<edi>,
        Opcode::AABBTree *a2@<ecx>,
        vostok::memory::base_allocator *allocator)
{
  void *v3; // esi

  v3 = *pointer;
  if ( *pointer )
  {
    Opcode::AABBTree::Release(a2);
    allocator->call_free(allocator, v3);
    *pointer = 0;
  }
}


void __cdecl vostok::memory::delete_helper<vostok::memory::base_allocator,vostok::logging::filter_tree>(
        vostok::memory::base_allocator *allocator,
        vostok::logging::filter_tree **pointer)
{
  vostok::logging::filter_tree *v2; // [esp+8h] [ebp-8h]

  if ( *pointer )
  {
    v2 = *pointer;
    vostok::logging::filter_tree::~filter_tree(*pointer);
    vostok::memory::base_allocator::free_impl(allocator, v2);
    *pointer = 0;
  }
}


void __cdecl vostok::memory::delete_helper<vostok::memory::base_allocator,vostok::logging::log_file>(
        vostok::memory::base_allocator *allocator,
        vostok::logging::log_file **pointer)
{
  vostok::logging::log_file *v2; // [esp+8h] [ebp-8h]

  if ( *pointer )
  {
    v2 = *pointer;
    vostok::logging::log_file::~log_file(*pointer);
    vostok::memory::base_allocator::free_impl(allocator, v2);
    *pointer = 0;
  }
}


void __cdecl vostok::memory::delete_helper<vostok::memory::base_allocator,vostok::logging::node>(
        vostok::memory::base_allocator *allocator,
        vostok::logging::node **pointer)
{
  vostok::logging::node *v2; // [esp+8h] [ebp-8h]

  if ( *pointer )
  {
    v2 = *pointer;
    vostok::logging::node::~node(*pointer);
    vostok::memory::base_allocator::free_impl(allocator, v2);
    *pointer = 0;
  }
}


void __cdecl vostok::memory::delete_helper<vostok::memory::base_allocator,vostok::resources::resource_base>(
        vostok::memory::base_allocator *allocator,
        vostok::resources::resource_base **pointer)
{
  void *v2; // [esp+0h] [ebp-8h]

  if ( *pointer )
  {
    v2 = vostok::memory::detail::get_top_pointer<vostok::resources::resource_base>(pointer);
    vostok::memory::detail::call_destructor_predicate::operator()<vostok::resources::resource_base>((vostok::memory::detail::call_destructor_predicate *)*pointer);
    vostok::memory::base_allocator::free_impl(allocator, v2);
    *pointer = 0;
  }
}


void __cdecl vostok::memory::delete_helper<vostok::memory::base_allocator,vostok::vfs::vfs_mount>(
        vostok::memory::base_allocator *allocator,
        vostok::vfs::vfs_mount **pointer)
{
  vostok::vfs::vfs_mount *v2; // [esp+14h] [ebp-8h]

  if ( *pointer )
  {
    v2 = *pointer;
    vostok::vfs::vfs_mount::~vfs_mount(*pointer);
    vostok::memory::base_allocator::free_impl(allocator, v2);
    *pointer = 0;
  }
}


void __cdecl vostok::memory::delete_helper<vostok::memory::base_allocator,vostok::vectora<unsigned __int64>>(
        vostok::memory::base_allocator *allocator,
        vostok::vectora<unsigned __int64> **pointer)
{
  void *v2; // [esp+5Ch] [ebp-8h]

  if ( *pointer )
  {
    v2 = *pointer;
    stlp_std::priv::_Impl_vector<unsigned __int64,vostok::vectora_allocator<unsigned __int64>>::~_Impl_vector<unsigned __int64,vostok::vectora_allocator<unsigned __int64>>(&(*pointer)->_M_impl);
    vostok::memory::base_allocator::free_impl(allocator, v2);
    *pointer = 0;
  }
}


void __usercall vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::light const>(
        vostok::memory::doug_lea_allocator *allocator@<eax>,
        vostok::render::light *a2@<ecx>,
        const vostok::render::light **pointer)
{
  void *v3; // edi

  v3 = (void *)*pointer;
  if ( *pointer )
  {
    vostok::render::light::~light(a2);
    allocator->m_out_of_memory = 0;
    vostok_mspace_free(allocator->m_arena, v3);
    *pointer = 0;
  }
}


void __cdecl vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::sound::proxy_statistic>(
        vostok::memory::doug_lea_allocator *allocator,
        vostok::sound::sound_scene_statistic **pointer)
{
  if ( *pointer )
  {
    vostok::memory::doug_lea_allocator::free_impl(allocator, *pointer);
    *pointer = 0;
  }
}


void __cdecl vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::ai::sensed_visual_object>(
        vostok::memory::doug_lea_allocator *allocator,
        survarium::game_camera **pointer)
{
  survarium::game_camera *v2; // [esp+8h] [ebp-8h]

  if ( *pointer )
  {
    v2 = *pointer;
    survarium::weapon_user_dead_state::finalize(*pointer);
    vostok::memory::doug_lea_allocator::free_impl(allocator, v2);
    *pointer = 0;
  }
}


void __usercall vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,survarium::collision_geometry>(
        survarium::collision_geometry **pointer@<edi>,
        vostok::memory::doug_lea_allocator *allocator)
{
  void *v2; // esi
  void *v3; // eax
  void *m_arena; // esi

  if ( *pointer )
  {
    v2 = __RTCastToVoid(*pointer);
    ((void (__thiscall *)(_DWORD, _DWORD))(*pointer)->~collision_geometry)(*pointer, 0);
    if ( v2 )
    {
      v3 = v2;
      m_arena = allocator->m_arena;
      allocator->m_out_of_memory = 0;
      vostok_mspace_free(m_arena, v3);
    }
    *pointer = 0;
  }
}


void __cdecl vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::ai::planning::generalized_action>(
        vostok::memory::doug_lea_allocator *allocator,
        vostok::ai::planning::generalized_action **pointer)
{
  vostok::ai::planning::generalized_action *v2; // [esp+8h] [ebp-8h]

  if ( *pointer )
  {
    v2 = *pointer;
    vostok::ai::planning::generalized_action::~generalized_action(*pointer);
    vostok::memory::doug_lea_allocator::free_impl(allocator, (void *)v2);
    *pointer = 0;
  }
}


void __cdecl vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::ai::planning::goal_selector>(
        vostok::memory::doug_lea_allocator *allocator,
        vostok::ai::planning::goal_selector **pointer)
{
  vostok::ai::planning::goal_selector *v2; // [esp+8h] [ebp-8h]

  if ( *pointer )
  {
    v2 = *pointer;
    vostok::ai::planning::goal_selector::~goal_selector(*pointer);
    vostok::memory::doug_lea_allocator::free_impl(allocator, v2);
    *pointer = 0;
  }
}


void __cdecl vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::ai::planning::goal_specificator>(
        vostok::memory::doug_lea_allocator *allocator,
        vostok::ai::planning::goal_specificator **pointer)
{
  vostok::ai::planning::goal_specificator *v2; // [esp+8h] [ebp-8h]

  if ( *pointer )
  {
    v2 = *pointer;
    vostok::ai::planning::goal_specificator::~goal_specificator(*pointer);
    vostok::memory::doug_lea_allocator::free_impl(allocator, v2);
    *pointer = 0;
  }
}


void __cdecl vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::network_core::http_client>(
        vostok::memory::doug_lea_allocator *allocator,
        vostok::network_core::http_client **pointer)
{
  vostok::network_core::http_client *v2; // [esp+40h] [ebp-8h]

  if ( *pointer )
  {
    v2 = *pointer;
    vostok::network_core::http_client::~http_client(*pointer);
    vostok::memory::doug_lea_allocator::free_impl(allocator, v2);
    *pointer = 0;
  }
}


void __cdecl vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,survarium::landing_point>(
        vostok::memory::doug_lea_allocator *allocator,
        survarium::landing_point **pointer)
{
  survarium::landing_point *v2; // [esp+Ch] [ebp-8h]

  if ( *pointer )
  {
    v2 = *pointer;
    survarium::landing_point::`scalar deleting destructor'(*pointer, 0);
    vostok::memory::doug_lea_allocator::free_impl(allocator, v2);
    *pointer = 0;
  }
}


void __cdecl vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::network::login_client_impl>(
        vostok::memory::doug_lea_allocator *allocator,
        vostok::network::login_client_impl **pointer)
{
  vostok::network::login_client_impl *v2; // [esp+8h] [ebp-8h]

  if ( *pointer )
  {
    v2 = *pointer;
    vostok::network::login_client_impl::~login_client_impl(*pointer);
    vostok::memory::doug_lea_allocator::free_impl(allocator, v2);
    *pointer = 0;
  }
}


void __cdecl vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::network::match_client_impl>(
        vostok::memory::doug_lea_allocator *allocator,
        vostok::network::match_client_impl **pointer)
{
  vostok::network::match_client_impl *v2; // [esp+8h] [ebp-8h]

  if ( *pointer )
  {
    v2 = *pointer;
    vostok::network::match_client_impl::~match_client_impl(*pointer);
    vostok::memory::doug_lea_allocator::free_impl(allocator, v2);
    *pointer = 0;
  }
}


void __cdecl vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::ai::planning::oracle>(
        vostok::memory::doug_lea_allocator *allocator,
        vostok::ai::planning::oracle **pointer)
{
  void *v2; // [esp+4h] [ebp-8h]

  if ( *pointer )
  {
    v2 = __RTCastToVoid(*pointer);
    ((void (__thiscall *)(_DWORD, _DWORD))(*pointer)->~vostok::ai::planning::oracle)(*pointer, 0);
    vostok::memory::doug_lea_allocator::free_impl(allocator, v2);
    *pointer = 0;
  }
}


void __cdecl vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::ai::planning::pddl_domain>(
        vostok::memory::doug_lea_allocator *allocator,
        vostok::ai::planning::pddl_domain **pointer)
{
  vostok::ai::planning::pddl_domain *v2; // [esp+8h] [ebp-8h]

  if ( *pointer )
  {
    v2 = *pointer;
    vostok::ai::planning::pddl_domain::~pddl_domain(*pointer);
    vostok::memory::doug_lea_allocator::free_impl(allocator, (void *)v2);
    *pointer = 0;
  }
}


void __cdecl vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::ai::planning::pddl_planner>(
        vostok::memory::doug_lea_allocator *allocator,
        vostok::ai::planning::pddl_planner **pointer)
{
  vostok::ai::planning::pddl_planner *v2; // [esp+8h] [ebp-8h]

  if ( *pointer )
  {
    v2 = *pointer;
    vostok::ai::planning::pddl_planner::~pddl_planner(*pointer);
    vostok::memory::doug_lea_allocator::free_impl(allocator, v2);
    *pointer = 0;
  }
}


void __cdecl vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::ai::planning::pddl_problem>(
        vostok::memory::doug_lea_allocator *allocator,
        vostok::ai::planning::pddl_problem **pointer)
{
  vostok::memory::detail::call_destructor_predicate call_destructor_predicate; // [esp+13h] [ebp-1h] BYREF

  call_destructor_predicate = 0;
  vostok::memory::detail::delete_helper_impl<vostok::memory::doug_lea_allocator,vostok::ai::planning::pddl_problem,vostok::memory::detail::call_destructor_predicate>(
    allocator,
    pointer,
    &call_destructor_predicate);
}


void __cdecl vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::ai::planning::plan_tracker>(
        vostok::memory::doug_lea_allocator *allocator,
        vostok::ai::planning::plan_tracker **pointer)
{
  vostok::ai::planning::plan_tracker *v2; // [esp+10h] [ebp-8h]

  if ( *pointer )
  {
    v2 = *pointer;
    vostok::ai::planning::plan_tracker::~plan_tracker(*pointer);
    vostok::memory::doug_lea_allocator::free_impl(allocator, v2);
    *pointer = 0;
  }
}


void __cdecl vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::sound::receiver_collision>(
        vostok::memory::doug_lea_allocator *allocator,
        vostok::sound::receiver_collision **pointer)
{
  vostok::sound::receiver_collision *v2; // [esp+8h] [ebp-8h]

  if ( *pointer )
  {
    v2 = *pointer;
    vostok::sound::receiver_collision::~receiver_collision(*pointer);
    vostok::memory::doug_lea_allocator::free_impl(allocator, v2);
    *pointer = 0;
  }
}


void __cdecl vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::sound::sound_buffer_factory>(
        vostok::memory::doug_lea_allocator *allocator,
        vostok::sound::sound_buffer_factory **pointer)
{
  vostok::sound::sound_buffer_factory *v2; // [esp+8h] [ebp-8h]

  if ( *pointer )
  {
    v2 = *pointer;
    vostok::sound::sound_buffer_factory::~sound_buffer_factory(*pointer);
    vostok::memory::doug_lea_allocator::free_impl(allocator, v2);
    *pointer = 0;
  }
}


void __cdecl vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::ai::planning::specified_problem>(
        vostok::memory::doug_lea_allocator *allocator,
        vostok::ai::planning::specified_problem **pointer)
{
  vostok::ai::planning::specified_problem *v2; // [esp+8h] [ebp-8h]

  if ( *pointer )
  {
    v2 = *pointer;
    vostok::ai::planning::specified_problem::~specified_problem(*pointer);
    vostok::memory::doug_lea_allocator::free_impl(allocator, v2);
    *pointer = 0;
  }
}


void __usercall vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::stage>(
        vostok::render::stage **pointer@<edi>,
        vostok::memory::doug_lea_allocator *allocator)
{
  void *v2; // esi
  void *v3; // eax
  void *m_arena; // esi

  if ( *pointer )
  {
    v2 = __RTCastToVoid(*pointer);
    ((void (__thiscall *)(_DWORD, _DWORD))(*pointer)->~vostok::render::stage)(*pointer, 0);
    if ( v2 )
    {
      v3 = v2;
      m_arena = allocator->m_arena;
      allocator->m_out_of_memory = 0;
      vostok_mspace_free(m_arena, v3);
    }
    *pointer = 0;
  }
}


void __cdecl vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::network_core::tcp_packet_client>(
        vostok::memory::doug_lea_allocator *allocator,
        vostok::network_core::tcp_packet_client **pointer)
{
  vostok::network_core::tcp_packet_client *v2; // [esp+8h] [ebp-8h]

  if ( *pointer )
  {
    v2 = *pointer;
    vostok::network_core::tcp_packet_client::~tcp_packet_client(*pointer);
    vostok::memory::doug_lea_allocator::free_impl(allocator, v2);
    *pointer = 0;
  }
}


void __cdecl vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::network_core::udp_network_flow_emulator>(
        vostok::memory::doug_lea_allocator *allocator,
        vostok::network_core::udp_network_flow_emulator **pointer)
{
  vostok::network_core::udp_network_flow_emulator *v2; // [esp+8h] [ebp-8h]

  if ( *pointer )
  {
    v2 = *pointer;
    vostok::network_core::udp_network_flow_emulator::~udp_network_flow_emulator(*pointer);
    vostok::memory::doug_lea_allocator::free_impl(allocator, v2);
    *pointer = 0;
  }
}


void __cdecl vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::sound::voice_factory>(
        vostok::memory::doug_lea_allocator *allocator,
        vostok::sound::voice_factory **pointer)
{
  vostok::sound::voice_factory *v2; // [esp+8h] [ebp-8h]

  if ( *pointer )
  {
    v2 = *pointer;
    vostok::sound::voice_factory::~voice_factory(*pointer);
    vostok::memory::doug_lea_allocator::free_impl(allocator, v2);
    *pointer = 0;
  }
}


void __cdecl vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::memory::writer>(
        vostok::memory::doug_lea_allocator *allocator,
        vostok::memory::writer **pointer)
{
  void *v2; // esi
  void *v3; // eax
  void *m_arena; // esi

  if ( *pointer )
  {
    v2 = __RTCastToVoid(*pointer);
    ((void (__thiscall *)(_DWORD, _DWORD))(*pointer)->~vostok::memory::writer)(*pointer, 0);
    if ( v2 )
    {
      v3 = v2;
      m_arena = allocator->m_arena;
      allocator->m_out_of_memory = 0;
      vostok_mspace_free(m_arena, v3);
    }
    *pointer = 0;
  }
}
