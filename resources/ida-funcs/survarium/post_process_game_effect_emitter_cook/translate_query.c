void __thiscall survarium::post_process_game_effect_emitter_cook::translate_query(
        survarium::post_process_game_effect_emitter_cook *this,
        const vostok::variant<32> **parent)
{
  const vostok::variant<32> *v2; // esi
  vostok::configs::binary_config_value *v3; // ecx
  void *v4; // esp
  void *v5; // esp
  const vostok::configs::binary_config_value *v6; // esi
  bool v7; // zf
  const vostok::configs::binary_config_value *v8; // eax
  unsigned int v9; // ebx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v10; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::post_process_game_effect_emitter_cook,vostok::resources::queries_result &,vostok::configs::binary_config_value const *>,boost::_bi::list3<boost::_bi::value<survarium::post_process_game_effect_emitter_cook *>,boost::arg<1>,boost::_bi::value<vostok::configs::binary_config_value const *> > > v11; // [esp-80h] [ebp-CCh]
  _BYTE v12[36]; // [esp-6Ch] [ebp-B8h] BYREF
  _BYTE v13[72]; // [esp-48h] [ebp-94h] BYREF
  int v14; // [esp+0h] [ebp-4Ch] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::post_process_game_effect_emitter_cook,vostok::resources::queries_result &,vostok::configs::binary_config_value const *>,boost::_bi::list3<boost::_bi::value<survarium::post_process_game_effect_emitter_cook *>,boost::arg<1>,boost::_bi::value<vostok::configs::binary_config_value const *> > > f; // [esp+Ch] [ebp-40h] BYREF
  void (__thiscall *v16)(survarium::post_process_game_effect_emitter_cook *, vostok::resources::queries_result *, const vostok::configs::binary_config_value *); // [esp+1Ch] [ebp-30h]
  int v17; // [esp+20h] [ebp-2Ch]
  survarium::post_process_game_effect_emitter_cook *v18; // [esp+24h] [ebp-28h]
  const vostok::configs::binary_config_value *v19; // [esp+28h] [ebp-24h]
  vostok::buffer_vector<vostok::variant<32> const *> user_data_ptrs; // [esp+2Ch] [ebp-20h] BYREF
  vostok::buffer_vector<vostok::resources::request> requests; // [esp+38h] [ebp-14h] BYREF
  survarium::post_process_game_effect_emitter_cook *v22; // [esp+44h] [ebp-8h]
  const vostok::configs::binary_config_value *cfg; // [esp+48h] [ebp-4h] BYREF

  v2 = parent[66];
  v22 = this;
  if ( vostok::variant<32>::try_get<vostok::configs::binary_config_value const *>(
         (vostok::variant<32> *)this,
         (int)v2,
         &cfg) )
  {
    v4 = alloca(72);
    requests.m_begin = (vostok::resources::request *)v13;
    requests.m_end = (vostok::resources::request *)v13;
    requests.m_max_end = (vostok::resources::request *)&v14;
    v5 = alloca(36);
    v6 = cfg;
    user_data_ptrs.m_begin = (const vostok::variant<32> **)v12;
    user_data_ptrs.m_end = (const vostok::variant<32> **)v12;
    user_data_ptrs.m_max_end = (const vostok::variant<32> **)v13;
    v7 = !vostok::configs::binary_config_value::value_exists(v3, (int)cfg, (unsigned int)"properties");
    v8 = v6;
    if ( !v7 )
      v8 = vostok::configs::binary_config_value::operator[](v6, "properties");
    vostok::render::environment_texture_request_helper::add_requests<vostok::configs::binary_config_value>(
      (vostok::render::environment_texture_request_helper *)&requests,
      v8,
      &requests,
      &user_data_ptrs);
    v9 = requests.m_end - requests.m_begin;
    if ( v9 )
    {
      v19 = v6;
      v16 = survarium::post_process_game_effect_emitter_cook::on_textures_loaded;
      v18 = v22;
      v17 = 0;
      HIDWORD(v11.f_.f_) = survarium::post_process_game_effect_emitter_cook::on_textures_loaded;
      v11.l_ = (boost::_bi::list3<boost::_bi::value<survarium::post_process_game_effect_emitter_cook *>,boost::arg<1>,boost::_bi::value<vostok::configs::binary_config_value const *> >)__PAIR64__((unsigned int)v22, 0);
      LODWORD(v11.f_.f_) = &f;
      boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
        0,
        v11,
        (int)v6);
      vostok::resources::query_resources(
        requests.m_begin,
        v9,
        survarium::g_allocator,
        user_data_ptrs.m_begin,
        parent,
        assert_on_fail_true);
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        v10,
        (int *)&f);
    }
    else
    {
      survarium::post_process_game_effect_emitter_cook::finish_query(
        0,
        (vostok::resources::query_result_for_cook *)parent,
        v6,
        0);
    }
  }
  else
  {
    vostok::resources::query_result_for_cook::finish_query_impl(
      (vostok::resources::query_result_for_cook *)v3,
      (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)parent,
      result_success,
      assert_on_fail_true,
      result_out_of_memory|0x8);
  }
}
