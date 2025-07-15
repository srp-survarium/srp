void __thiscall survarium::weapon_core_throw_grenade_state_cook::create_resource(
        survarium::weapon_core_throw_grenade_state_cook *this,
        const vostok::variant<32> **parent,
        vostok::const_buffer raw_file_data,
        vostok::mutable_buffer in_out_unmanaged_resource_buffer)
{
  vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *v4; // edi
  vostok::configs::binary_config_value *v5; // eax
  vostok::variant<32> *v6; // ecx
  vostok::resources::query_result_for_cook *v7; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v8; // ecx
  _BYTE v9[28]; // [esp-1Ch] [ebp-D4h] BYREF
  survarium::weapon_core_throw_grenade_state_cook *v10; // [esp+Ch] [ebp-ACh]
  vostok::configs::binary_config_value v11; // [esp+10h] [ebp-A8h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::weapon_core_throw_grenade_state_cook,vostok::resources::queries_result &,vostok::mutable_buffer,survarium::weapon_state_creation_params const *>,boost::_bi::list4<boost::_bi::value<survarium::weapon_core_throw_grenade_state_cook *>,boost::arg<1>,boost::_bi::value<vostok::mutable_buffer>,boost::_bi::value<survarium::weapon_state_creation_params const *> > > f; // [esp+28h] [ebp-90h] BYREF
  vostok::buffer_vector<vostok::resources::request> v13; // [esp+48h] [ebp-70h] BYREF
  _BYTE v14[96]; // [esp+54h] [ebp-64h] BYREF
  char v15; // [esp+B4h] [ebp-4h] BYREF

  v10 = this;
  vostok::configs::binary_config_value::binary_config_value((vostok::configs::binary_config_value *)this, (int)&v11);
  v4 = (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)parent;
  if ( vostok::variant<32>::try_get<vostok::configs::binary_config_value>(v6, (int)parent[66], v5) )
  {
    v13.m_begin = (vostok::resources::request *)v14;
    v13.m_end = (vostok::resources::request *)v14;
    v13.m_max_end = (vostok::resources::request *)&v15;
    qmemcpy(&v9[4], vostok::configs::binary_config_value::operator[](&v11, (char *)survarium::substate_names[0]), 0x18u);
    survarium::fill_state_request(&v13, *(vostok::configs::binary_config_value *)&v9[4]);
    qmemcpy(&v9[4], vostok::configs::binary_config_value::operator[](&v11, off_87EF8C[0]), 0x18u);
    survarium::fill_state_request(&v13, *(vostok::configs::binary_config_value *)&v9[4]);
    qmemcpy(&v9[4], vostok::configs::binary_config_value::operator[](&v11, off_87EF90[0]), 0x18u);
    survarium::fill_state_request(&v13, *(vostok::configs::binary_config_value *)&v9[4]);
    v11.data.pointer = v10;
    *(vostok::mutable_buffer *)((char *)&v11.data.max_storage + 4) = in_out_unmanaged_resource_buffer;
    HIDWORD(f.f_.f_) = 0;
    LODWORD(f.f_.f_) = survarium::weapon_core_throw_grenade_state_cook::on_subresources_ready;
    HIDWORD(v11.id.max_storage) = raw_file_data.m_data;
    f.l_.a1_.t_ = v10;
    f.l_.a3_.t_ = in_out_unmanaged_resource_buffer;
    f.l_.a4_.t_ = (const survarium::weapon_state_creation_params *)raw_file_data.m_data;
    *(_DWORD *)v9 = &f;
    qmemcpy(&v9[4], &f, 0x18u);
    boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
      0,
      *(boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::weapon_core_throw_grenade_state_cook,vostok::resources::queries_result &,vostok::mutable_buffer,survarium::weapon_state_creation_params const *>,boost::_bi::list4<boost::_bi::value<survarium::weapon_core_throw_grenade_state_cook *>,boost::arg<1>,boost::_bi::value<vostok::mutable_buffer>,boost::_bi::value<survarium::weapon_state_creation_params const *> > > *)v9,
      *(int *)&v9[24]);
    v4 = (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)parent;
    vostok::resources::query_resources(
      v13.m_begin,
      v13.m_end - v13.m_begin,
      survarium::g_allocator,
      0,
      parent,
      assert_on_fail_true);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v8,
      (int *)&f);
    *(_DWORD *)&v9[24] = 0;
    *(_DWORD *)&v9[20] = 1;
    *(_DWORD *)&v9[16] = 2;
  }
  else
  {
    *(_DWORD *)&v9[24] = 11;
    *(_DWORD *)&v9[20] = 1;
    *(_DWORD *)&v9[16] = 1;
  }
  vostok::resources::query_result_for_cook::finish_query_impl(
    v7,
    v4,
    *(vostok::resources::cook_base::result_enum *)&v9[16],
    *(const assert_on_fail_bool *)&v9[20],
    *(vostok::resources::cook_base::result_enum *)&v9[24]);
}
