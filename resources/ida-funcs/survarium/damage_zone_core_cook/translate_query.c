void __thiscall survarium::damage_zone_core_cook::translate_query(
        survarium::damage_zone_core_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  vostok::variant<32> *m_user_data; // esi
  vostok::configs::binary_config_value *v4; // eax
  vostok::variant<32> *v5; // ecx
  int v6; // esi
  void *v7; // esp
  survarium::damage_zone_core_cook_vtbl *v8; // eax
  survarium::damage_zone_core_cook *v9; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v10; // ecx
  _BYTE v11[44]; // [esp-2Ch] [ebp-A4h] BYREF
  _BYTE v12[12]; // [esp+0h] [ebp-78h] BYREF
  _DWORD v13[10]; // [esp+Ch] [ebp-6Ch] BYREF
  _BYTE f[56]; // [esp+34h] [ebp-44h] BYREF
  const vostok::resources::request *v15; // [esp+6Ch] [ebp-Ch] BYREF
  const vostok::resources::request *v16; // [esp+70h] [ebp-8h]
  _BYTE *v17; // [esp+74h] [ebp-4h]

  m_user_data = parent->m_user_data;
  vostok::configs::binary_config_value::binary_config_value((vostok::configs::binary_config_value *)this, (int)&f[32]);
  vostok::variant<32>::try_get<vostok::configs::binary_config_value>(v5, (int)m_user_data, v4);
  v6 = 8 * this->calculate_max_requests_count(this, (const vostok::configs::binary_config_value *)&f[32]);
  v7 = alloca(v6);
  *(_DWORD *)&v11[40] = &f[32];
  v15 = (const vostok::resources::request *)v12;
  v16 = (const vostok::resources::request *)v12;
  v8 = this->__vftable;
  v17 = &v12[v6];
  v8->query_resources(
    this,
    (vostok::buffer_vector<vostok::resources::request> *)&v15,
    (const vostok::configs::binary_config_value *)&f[32]);
  if ( v15 == v16 )
  {
    survarium::damage_zone_core_cook::create_resource(
      v9,
      (int *)this,
      parent,
      (const vostok::configs::binary_config_value *)&f[32],
      0);
  }
  else
  {
    *(_DWORD *)f = this;
    qmemcpy(&f[8], &f[32], 0x18u);
    v13[0] = survarium::damage_zone_core_cook::on_resources_loaded;
    v13[1] = 0;
    qmemcpy(&v13[2], f, 0x20u);
    *(_DWORD *)v11 = f;
    qmemcpy(&v11[4], v13, 0x28u);
    boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
      0,
      *(boost::_bi::bind_t<void,boost::_mfi::cmf2<void,survarium::damage_zone_core_cook,vostok::resources::queries_result &,vostok::configs::binary_config_value const &>,boost::_bi::list3<boost::_bi::value<survarium::damage_zone_core_cook *>,boost::arg<1>,boost::_bi::value<vostok::configs::binary_config_value> > > *)v11,
      *(int *)&v11[40]);
    vostok::resources::query_resources(
      v15,
      v16 - v15,
      survarium::g_allocator,
      0,
      (const vostok::variant<32> **)parent,
      assert_on_fail_true);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v10,
      (int *)f);
  }
}
