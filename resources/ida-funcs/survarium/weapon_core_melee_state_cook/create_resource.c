void __thiscall survarium::weapon_core_melee_state_cook::create_resource(
        survarium::weapon_core_melee_state_cook *this,
        const vostok::variant<32> **parent,
        vostok::const_buffer raw_file_data,
        vostok::mutable_buffer in_out_unmanaged_resource_buffer)
{
  vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *v4; // edi
  vostok::configs::binary_config_value *v5; // eax
  vostok::variant<32> *v6; // ecx
  vostok::resources::query_result_for_cook *v7; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v8; // ecx
  _BYTE v9[28]; // [esp-1Ch] [ebp-84h] BYREF
  survarium::weapon_core_melee_state_cook *v10; // [esp+10h] [ebp-58h]
  const char *m_data; // [esp+14h] [ebp-54h]
  survarium::weapon_core_melee_state_cook *v12; // [esp+18h] [ebp-50h] BYREF
  vostok::mutable_buffer v13; // [esp+1Ch] [ebp-4Ch]
  const char *v14; // [esp+24h] [ebp-44h]
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::weapon_core_melee_state_cook,vostok::resources::queries_result &,vostok::mutable_buffer,survarium::weapon_state_creation_params const *>,boost::_bi::list4<boost::_bi::value<survarium::weapon_core_melee_state_cook *>,boost::arg<1>,boost::_bi::value<vostok::mutable_buffer>,boost::_bi::value<survarium::weapon_state_creation_params const *> > > f; // [esp+28h] [ebp-40h] BYREF
  vostok::buffer_vector<vostok::resources::request> v16; // [esp+4Ch] [ebp-1Ch] BYREF
  _BYTE v17[16]; // [esp+58h] [ebp-10h] BYREF
  char vars0; // [esp+68h] [ebp+0h] BYREF

  m_data = raw_file_data.m_data;
  v10 = this;
  vostok::configs::binary_config_value::binary_config_value((vostok::configs::binary_config_value *)this, (int)&f);
  v4 = (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)parent;
  if ( vostok::variant<32>::try_get<vostok::configs::binary_config_value>(v6, (int)parent[66], v5) )
  {
    v16.m_begin = (vostok::resources::request *)v17;
    v16.m_end = (vostok::resources::request *)v17;
    v16.m_max_end = (vostok::resources::request *)&vars0;
    v12 = *(survarium::weapon_core_melee_state_cook **)vostok::configs::binary_config_value::operator[](
                                                         (vostok::configs::binary_config_value *)&f,
                                                         "user_animations")->data.pointer;
    v13.m_data = (char *)50;
    vostok::buffer_vector<vostok::resources::request>::push_back(&v16, (const vostok::resources::request *)&v12);
    v12 = (survarium::weapon_core_melee_state_cook *)*((_DWORD *)vostok::configs::binary_config_value::operator[](
                                                                   (vostok::configs::binary_config_value *)&f,
                                                                   "user_animations")->data.pointer
                                                     + 6);
    v13.m_data = (char *)50;
    vostok::buffer_vector<vostok::resources::request>::push_back(&v16, (const vostok::resources::request *)&v12);
    v12 = v10;
    v13 = in_out_unmanaged_resource_buffer;
    HIDWORD(f.f_.f_) = 0;
    v14 = m_data;
    LODWORD(f.f_.f_) = survarium::weapon_core_melee_state_cook::on_subresources_ready;
    f.l_.a1_.t_ = v10;
    f.l_.a3_.t_ = in_out_unmanaged_resource_buffer;
    f.l_.a4_.t_ = (const survarium::weapon_state_creation_params *)m_data;
    *(_DWORD *)v9 = &f;
    qmemcpy(&v9[4], &f, 0x18u);
    boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
      0,
      *(boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::weapon_core_melee_state_cook,vostok::resources::queries_result &,vostok::mutable_buffer,survarium::weapon_state_creation_params const *>,boost::_bi::list4<boost::_bi::value<survarium::weapon_core_melee_state_cook *>,boost::arg<1>,boost::_bi::value<vostok::mutable_buffer>,boost::_bi::value<survarium::weapon_state_creation_params const *> > > *)v9,
      *(int *)&v9[24]);
    v4 = (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)parent;
    vostok::resources::query_resources(
      v16.m_begin,
      v16.m_end - v16.m_begin,
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
