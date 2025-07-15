void __thiscall survarium::weapon_preview_state_cook::create_resource(
        survarium::weapon_preview_state_cook *this,
        const vostok::variant<32> **parent,
        vostok::const_buffer raw_file_data,
        vostok::mutable_buffer buffer)
{
  vostok::configs::binary_config_value *v4; // eax
  vostok::variant<32> *v5; // ecx
  vostok::resources::query_result_for_cook *v6; // ecx
  int v7; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v8; // ecx
  _BYTE v9[28]; // [esp-1Ch] [ebp-74h] BYREF
  survarium::weapon_preview_state_cook *v10; // [esp+Ch] [ebp-4Ch]
  survarium::weapon_preview_state_cook *v11; // [esp+10h] [ebp-48h]
  vostok::mutable_buffer v12; // [esp+14h] [ebp-44h]
  int v13; // [esp+1Ch] [ebp-3Ch]
  int f[8]; // [esp+20h] [ebp-38h] BYREF
  const char *v15; // [esp+40h] [ebp-18h] BYREF

  v10 = this;
  vostok::configs::binary_config_value::binary_config_value((vostok::configs::binary_config_value *)this, (int)&v15);
  if ( vostok::variant<32>::try_get<vostok::configs::binary_config_value>(v5, (int)parent[66], v4) )
  {
    v7 = *((_DWORD *)raw_file_data.m_data + 1);
    v11 = v10;
    v12 = buffer;
    v13 = v7;
    f[0] = (int)survarium::weapon_preview_state_cook::on_preview_animation_ready;
    f[1] = 0;
    f[2] = (int)v10;
    *(vostok::mutable_buffer *)&f[3] = buffer;
    f[5] = v7;
    *(_DWORD *)v9 = f;
    qmemcpy(&v9[4], f, 0x18u);
    boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
      0,
      *(boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::weapon_preview_state_cook,vostok::resources::queries_result &,vostok::mutable_buffer,survarium::weapon_core &>,boost::_bi::list4<boost::_bi::value<survarium::weapon_preview_state_cook *>,boost::arg<1>,boost::_bi::value<vostok::mutable_buffer>,boost::reference_wrapper<survarium::weapon_core> > > *)v9,
      *(int *)&v9[24]);
    vostok::resources::query_resource(
      v15,
      (vostok::variant<32> *)0x32,
      survarium::g_allocator,
      0,
      parent,
      assert_on_fail_true);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v8, f);
    *(_DWORD *)&v9[24] = 0;
    *(_DWORD *)&v9[20] = 1;
    *(_DWORD *)&v9[16] = 2;
  }
  else
  {
    __debugbreak();
    *(_DWORD *)&v9[24] = 11;
    *(_DWORD *)&v9[20] = 1;
    *(_DWORD *)&v9[16] = 1;
  }
  vostok::resources::query_result_for_cook::finish_query_impl(
    v6,
    (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)parent,
    *(vostok::resources::cook_base::result_enum *)&v9[16],
    *(const assert_on_fail_bool *)&v9[20],
    *(vostok::resources::cook_base::result_enum *)&v9[24]);
}
