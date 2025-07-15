void __thiscall survarium::shotgun_weapon_reload_state_cook::create_resource(
        survarium::shotgun_weapon_reload_state_cook *this,
        const vostok::variant<32> **parent,
        vostok::const_buffer raw_file_data,
        vostok::mutable_buffer in_out_unmanaged_resource_buffer)
{
  vostok::configs::binary_config_value *v4; // eax
  vostok::variant<32> *v5; // ecx
  vostok::resources::query_result_for_cook *v6; // ecx
  int v7; // ecx
  char *v8; // eax
  const vostok::configs::binary_config_value *v9; // ebx
  vostok::resources::creation_request *v10; // esi
  const vostok::configs::binary_config_value *v11; // eax
  vostok::variant<32> *v12; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v13; // ecx
  vostok::resources::query_result_for_cook *v14; // ecx
  vostok::variant<32> *v15; // ecx
  char *v16; // esi
  int i; // edi
  int v18; // [esp+Ch] [ebp-114h]
  _BYTE v20[32]; // [esp+18h] [ebp-108h] BYREF
  const vostok::variant<32> *v21[3]; // [esp+3Ch] [ebp-E4h] BYREF
  _DWORD v22[6]; // [esp+48h] [ebp-D8h] BYREF
  vostok::resources::creation_request v23; // [esp+60h] [ebp-C0h] BYREF
  const char *v24; // [esp+70h] [ebp-B0h]
  vostok::const_buffer v25; // [esp+74h] [ebp-ACh]
  int v26; // [esp+7Ch] [ebp-A4h]
  const char *v27; // [esp+80h] [ebp-A0h]
  vostok::const_buffer v28; // [esp+84h] [ebp-9Ch]
  int v29; // [esp+8Ch] [ebp-94h]
  _BYTE v30[44]; // [esp+90h] [ebp-90h] BYREF
  char v31; // [esp+BCh] [ebp-64h] BYREF
  char v32; // [esp+C0h] [ebp-60h] BYREF
  char v33; // [esp+F0h] [ebp-30h] BYREF
  char vars0; // [esp+120h] [ebp+0h] BYREF

  vostok::configs::binary_config_value::binary_config_value((vostok::configs::binary_config_value *)this, (int)v20);
  if ( vostok::variant<32>::try_get<vostok::configs::binary_config_value>(v5, (int)parent[66], v4) )
  {
    v23.m_data = raw_file_data;
    v25 = raw_file_data;
    v28 = raw_file_data;
    v23.m_name = "start_substate";
    v23.m_id = weapon_shotgun_reload_start_substate_class;
    v24 = "reload_one_substate";
    v26 = 308;
    v27 = "finish_substate";
    v29 = 309;
    v7 = 2;
    v8 = &v31;
    do
    {
      *((_DWORD *)v8 - 1) = 0;
      *(_DWORD *)v8 = 0;
      v8 += 48;
      --v7;
    }
    while ( v7 >= 0 );
    v9 = (const vostok::configs::binary_config_value *)v30;
    v10 = &v23;
    v18 = 3;
    do
    {
      v11 = vostok::configs::binary_config_value::operator[](
              (vostok::configs::binary_config_value *)v20,
              (char *)v10->m_name);
      vostok::variant<32>::set<vostok::configs::binary_config_value>(v12, v9, v11);
      ++v10;
      v9 += 2;
      --v18;
    }
    while ( v18 );
    v21[0] = (const vostok::variant<32> *)v30;
    v21[1] = (const vostok::variant<32> *)&v32;
    v21[2] = (const vostok::variant<32> *)&v33;
    *(_DWORD *)&v20[4] = 0;
    *(_DWORD *)v20 = survarium::shotgun_weapon_reload_state_cook::on_substates_ready;
    *(_DWORD *)&v20[8] = this;
    *(vostok::mutable_buffer *)&v20[12] = in_out_unmanaged_resource_buffer;
    *(_DWORD *)&v20[20] = raw_file_data.m_data;
    qmemcpy(v22, v20, sizeof(v22));
    if ( Scaleform::Render::RenderEvent::GetListenerStatus(0) )
    {
      *(_DWORD *)v20 = 0;
    }
    else
    {
      qmemcpy(&v20[8], v22, 0x18u);
      *(_DWORD *)v20 = (char *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::shotgun_weapon_reload_state_cook,vostok::resources::queries_result &,vostok::mutable_buffer,survarium::weapon_state_creation_params const *>,boost::_bi::list4<boost::_bi::value<survarium::shotgun_weapon_reload_state_cook *>,boost::arg<1>,boost::_bi::value<vostok::mutable_buffer>,boost::_bi::value<survarium::weapon_state_creation_params const *>>>>'::`2'::stored_vtable
                     + 1;
    }
    vostok::resources::query_create_resources(&v23, 3u, survarium::g_allocator, v21, parent);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v13,
      (int *)v20);
    vostok::resources::query_result_for_cook::finish_query_impl(
      v14,
      (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)parent,
      result_need_async,
      assert_on_fail_true,
      result_fail);
    v16 = &vars0;
    for ( i = 2; i >= 0; --i )
    {
      v16 -= 48;
      vostok::variant<32>::destroy_previous_variable_if_needed(v15, (int)v16);
    }
  }
  else
  {
    __debugbreak();
    vostok::resources::query_result_for_cook::finish_query_impl(
      v6,
      (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)parent,
      result_success,
      assert_on_fail_true,
      result_out_of_memory|0x8);
  }
}
