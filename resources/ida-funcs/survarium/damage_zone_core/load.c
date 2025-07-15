void __thiscall survarium::damage_zone_core::load(
        survarium::damage_zone_core *this,
        const vostok::configs::binary_config_value *t)
{
  const vostok::configs::binary_config_value *v3; // eax
  vostok::configs::binary_config_value *v4; // esi
  vostok::configs::binary_config_value *v5; // ecx
  const vostok::configs::binary_config_value *v6; // eax
  const vostok::configs::binary_config_value *v7; // eax
  float pointer; // xmm0_4
  const vostok::configs::binary_config_value *v9; // eax
  float v10; // xmm0_4
  vostok::configs::binary_config_value *v11; // ecx
  bool v12; // al
  char **v13; // eax
  vostok::fixed_string<16> *v14; // ecx
  char *v15; // edi
  vostok::vfs::base_node<1> **p_m_link_target; // ebx
  vostok::fixed_string<16> *v17; // esi
  _BYTE v18[28]; // [esp-1Ch] [ebp-4Ch] BYREF
  unsigned int v19; // [esp+0h] [ebp-30h]
  bool v20; // [esp+4h] [ebp-2Ch]
  char *m_begin; // [esp+Ch] [ebp-24h]
  vostok::fixed_string<16> __formal; // [esp+10h] [ebp-20h] BYREF

  survarium::collision_sensor::load((survarium::collision_sensor *)this, t);
  v3 = vostok::configs::binary_config_value::operator[](t, "hit_curve");
  *(_DWORD *)v18 = survarium::g_allocator;
  qmemcpy(&v18[4], v3, 0x18u);
  vostok::math::curve_line_points<float,0>::load<vostok::configs::binary_config_value>(
    0,
    (vostok::math::curve_line_points<float,0> *)&this->m_current_satisfaction_update_tick,
    *(vostok::configs::binary_config_value *)v18,
    *(int *)&v18[24]);
  v4 = t;
  if ( vostok::configs::binary_config_value::value_exists(v5, (int)t, (unsigned int)"speed_curve") )
  {
    v6 = vostok::configs::binary_config_value::operator[](t, "speed_curve");
    *(_DWORD *)v18 = survarium::g_allocator;
    qmemcpy(&v18[4], v6, 0x18u);
    vostok::math::curve_line_points<float,0>::load<vostok::configs::binary_config_value>(
      0,
      (vostok::math::curve_line_points<float,0> *)&this->m_target_quality_level,
      *(vostok::configs::binary_config_value *)v18,
      *(int *)&v18[24]);
    v4 = t;
  }
  v7 = vostok::configs::binary_config_value::operator[](v4, "max_hit");
  if ( v7->type == 2 )
    pointer = *(float *)&v7->data.pointer;
  else
    pointer = (float)(int)v7->data.pointer;
  *(float *)&this->m_next_for_grm_observer_list = pointer;
  v9 = vostok::configs::binary_config_value::operator[](v4, "max_armor_piercing");
  if ( v9->type == 2 )
    v10 = *(float *)&v9->data.pointer;
  else
    v10 = (float)(int)v9->data.pointer;
  *(float *)&this->m_destruction_observer = v10;
  this->m_creation_source = (vostok::resources::resource_base::creation_source_enum)vostok::configs::binary_config_value::operator[](
                                                                                      v4,
                                                                                      "interval_in_msec")->data.pointer;
  v12 = vostok::configs::binary_config_value::value_exists(v11, (int)v4, (unsigned int)"continuous_hit")
     && vostok::configs::binary_config_value::operator[](v4, "continuous_hit")->data.pointer != 0;
  LOBYTE(this->m_parent_resources.m_first) = v12;
  v13 = (char **)vostok::configs::binary_config_value::operator[](v4, "damage_type");
  this->m_next_for_query_finished_callback = (vostok::resources::resource_base *)survarium::hit_type(*v13);
  qmemcpy(&__formal, vostok::configs::binary_config_value::operator[](v4, "hit_parts_filter"), 0x18u);
  v14 = 0;
  v15 = &__formal.m_begin[24 * HIWORD(*(_DWORD *)&__formal.m_buffer[8])];
  m_begin = __formal.m_begin;
  if ( __formal.m_begin != v15 )
  {
    p_m_link_target = &this->m_fat_it.m_link_target;
    do
    {
      vostok::fixed_string<16>::fixed_string<16>(v14, &__formal, *(char **)m_begin);
      v17 = (vostok::fixed_string<16> *)p_m_link_target[1];
      if ( v17 == (vostok::fixed_string<16> *)p_m_link_target[2] )
      {
        stlp_std::priv::_Impl_vector<vostok::fixed_string<16>,survarium::std_allocator<vostok::fixed_string<16>>>::_M_insert_overflow_aux(
          (stlp_std::priv::_Impl_vector<vostok::fixed_string<16>,survarium::std_allocator<vostok::fixed_string<16> > > *)v14,
          (int)p_m_link_target,
          v17,
          &__formal,
          v19,
          v20);
      }
      else
      {
        if ( v17 )
          vostok::fixed_string<16>::fixed_string<16>(v17, &__formal);
        p_m_link_target[1] = (vostok::vfs::base_node<1> *)((char *)p_m_link_target[1] + 28);
      }
      m_begin += 24;
    }
    while ( m_begin != v15 );
  }
}
