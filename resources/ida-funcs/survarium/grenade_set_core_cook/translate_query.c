void __thiscall survarium::grenade_set_core_cook::translate_query(
        survarium::grenade_set_core_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  const char *requested_path; // eax
  vostok::buffer_string *v4; // ecx
  vostok::variant<32> *m_user_data; // esi
  vostok::resources::query_result_for_cook *v6; // ecx
  void *game_world; // edx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v8; // ecx
  _BYTE v9[28]; // [esp-1Ch] [ebp-17Ch] BYREF
  const char *v10; // [esp+0h] [ebp-160h]
  bool v11; // [esp+13h] [ebp-14Dh] BYREF
  survarium::grenade_set_cook_data out_value; // [esp+14h] [ebp-14Ch] BYREF
  survarium::grenade_set_core_cook *v13; // [esp+1Ch] [ebp-144h]
  int v14; // [esp+20h] [ebp-140h]
  void *v15; // [esp+24h] [ebp-13Ch]
  int f[8]; // [esp+28h] [ebp-138h] BYREF
  const char *v17[3]; // [esp+48h] [ebp-118h] BYREF
  _BYTE v18[260]; // [esp+54h] [ebp-10Ch] BYREF
  char v19; // [esp+158h] [ebp-8h] BYREF

  v17[0] = v18;
  v17[1] = v18;
  v17[2] = &v19;
  v18[0] = 0;
  v19 = 47;
  requested_path = vostok::resources::query_result_for_user::get_requested_path(parent);
  vostok::fs_new::path_string_impl::assignf(v17, v4, (vostok::buffer_string *)"resources/%s", requested_path);
  m_user_data = parent->m_user_data;
  if ( !m_user_data )
  {
    out_value.is_local_player = 0;
    out_value.stack_size = 1;
    game_world = 0;
LABEL_10:
    v14 = *(_DWORD *)&out_value.is_local_player;
    f[1] = 0;
    f[0] = (int)survarium::grenade_set_core_cook::on_config_ready;
    v15 = game_world;
    v13 = this;
    f[2] = (int)this;
    f[3] = *(_DWORD *)&out_value.is_local_player;
    f[4] = (int)game_world;
    *(_DWORD *)v9 = f;
    qmemcpy(&v9[4], f, 0x18u);
    boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
      0,
      *(boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::grenade_set_core_cook,vostok::resources::queries_result &,survarium::grenade_set_cook_data>,boost::_bi::list3<boost::_bi::value<survarium::grenade_set_core_cook *>,boost::arg<1>,boost::_bi::value<survarium::grenade_set_cook_data> > > *)v9,
      *(int *)&v9[24]);
    vostok::resources::query_resource(
      v17[0],
      (vostok::variant<32> *)0x20,
      survarium::g_allocator,
      0,
      (const vostok::variant<32> **)parent,
      assert_on_fail_true);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v8, f);
    return;
  }
  if ( vostok::variant<32>::try_get<survarium::grenade_set_cook_data>(m_user_data, &out_value) )
  {
    game_world = out_value.game_world;
    goto LABEL_10;
  }
  if ( !debug_macro_helper_ignore_always_45 )
  {
    v11 = 0;
    vostok::debug::on_error(
      &v11,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      ".\\grenade_set_core_cook.cpp",
      "survarium::grenade_set_core_cook::translate_query",
      (const char *)0x1E,
      "This cook requires grenade_set_cook_data as user data.",
      v10);
    if ( vostok::debug::is_debugger_present() || v11 )
      __debugbreak();
  }
  vostok::resources::query_result_for_cook::finish_query_impl(
    v6,
    (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)parent,
    result_success,
    assert_on_fail_true,
    result_out_of_memory|0x8);
}
