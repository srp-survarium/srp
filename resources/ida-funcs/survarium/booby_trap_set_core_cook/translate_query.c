void __thiscall survarium::booby_trap_set_core_cook::translate_query(
        survarium::booby_trap_set_core_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  void *v2; // esp
  vostok::resources::query_result_for_cook *v3; // ebx
  const char *requested_path; // eax
  vostok::buffer_string *v5; // ecx
  int m_helper_storage; // eax
  vostok::resources::query_result_for_cook *v7; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v8; // ecx
  _BYTE v9[28]; // [esp-2Ch] [ebp-120h] BYREF
  const char *v10[4]; // [esp-10h] [ebp-104h] BYREF
  int v11; // [esp+0h] [ebp-F4h] BYREF
  _DWORD v12[3]; // [esp+Ch] [ebp-E8h] BYREF
  _BYTE v13[260]; // [esp+18h] [ebp-DCh] BYREF
  char v14; // [esp+11Ch] [ebp+28h] BYREF
  int f[5]; // [esp+120h] [ebp+2Ch] BYREF
  survarium::booby_trap_set_cook_data f_20; // [esp+134h] [ebp+40h]
  survarium::booby_trap_set_core_cook *v17; // [esp+140h] [ebp+4Ch]
  survarium::booby_trap_set_cook_data v18[2]; // [esp+144h] [ebp+50h] BYREF
  vostok::buffer_vector<vostok::resources::request> v19; // [esp+15Ch] [ebp+68h] BYREF

  v17 = this;
  v2 = alloca(16);
  v3 = parent;
  v19.m_begin = (vostok::resources::request *)v10;
  v19.m_end = (vostok::resources::request *)v10;
  v19.m_max_end = (vostok::resources::request *)&v11;
  v12[0] = v13;
  v12[1] = v13;
  v12[2] = &v14;
  v13[0] = 0;
  v14 = 47;
  requested_path = vostok::resources::query_result_for_user::get_requested_path(parent);
  vostok::fs_new::path_string_impl::assignf(v12, v5, (vostok::buffer_string *)"resources/%s", requested_path);
  v18[1].physics_world = (vostok::physics::world *)v12[0];
  v18[1].game_world = (void *)32;
  vostok::buffer_vector<vostok::resources::request>::push_back(
    &v19,
    (const vostok::resources::request *)&v18[1].physics_world);
  v18[1].physics_world = (vostok::physics::world *)"game_material_manager";
  v18[1].game_world = (void *)82;
  vostok::buffer_vector<vostok::resources::request>::push_back(
    &v19,
    (const vostok::resources::request *)&v18[1].physics_world);
  m_helper_storage = (int)v3->m_user_data->m_helper_storage;
  if ( !m_helper_storage )
  {
    v18[1].game_world = 0;
    v18[1].is_local_player = 0;
    v18[1].stack_size = 1;
    goto LABEL_9;
  }
  if ( vostok::variant<32>::try_get<survarium::booby_trap_set_cook_data>(
         (vostok::variant<32> *)&v18[1],
         m_helper_storage,
         &v18[1]) )
  {
LABEL_9:
    f[4] = (int)v17;
    f_20 = v18[1];
    v18[0].physics_world = 0;
    *(_DWORD *)&v18[0].is_local_player = survarium::booby_trap_set_core_cook::on_resources_loaded;
    v18[0].game_world = v17;
    *(_DWORD *)v9 = f;
    qmemcpy(&v9[4], v18, 0x18u);
    boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
      0,
      *(boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::booby_trap_set_core_cook,vostok::resources::queries_result &,survarium::booby_trap_set_cook_data>,boost::_bi::list3<boost::_bi::value<survarium::booby_trap_set_core_cook *>,boost::arg<1>,boost::_bi::value<survarium::booby_trap_set_cook_data> > > *)v9,
      *(int *)&v9[24]);
    vostok::resources::query_resources(
      v19.m_begin,
      v19.m_end - v19.m_begin,
      survarium::g_allocator,
      0,
      (const vostok::variant<32> **)v3,
      assert_on_fail_true);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v8, f);
    return;
  }
  if ( !debug_macro_helper_ignore_always_44 )
  {
    HIBYTE(parent) = 0;
    vostok::debug::on_error(
      (bool *)&parent + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      ".\\booby_trap_set_core_cook.cpp",
      "survarium::booby_trap_set_core_cook::translate_query",
      (const char *)0x23,
      "This cook requires booby_trap_set_cook_data as user data.",
      v10[0]);
    if ( vostok::debug::is_debugger_present() || HIBYTE(parent) )
      __debugbreak();
  }
  vostok::resources::query_result_for_cook::finish_query_impl(
    v7,
    (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)v3,
    result_success,
    assert_on_fail_true,
    result_out_of_memory|0x8);
}
