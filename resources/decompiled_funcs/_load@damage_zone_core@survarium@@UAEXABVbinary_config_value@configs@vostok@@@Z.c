void __userpurge survarium::damage_zone_core::load(
        survarium::damage_zone_core *this@<ecx>,
        float a2@<xmm0>,
        vostok::configs::binary_config_value *t)
{
  const vostok::configs::binary_config_value *v3; // eax
  vostok::configs::binary_config_value *v4; // ecx
  vostok::configs::binary_config_value *v5; // ecx
  vostok::configs::binary_config_value *v6; // ecx
  vostok::configs::binary_config_value *v7; // ecx
  vostok::configs::binary_config_value *v8; // ecx
  const vostok::configs::binary_config_value *v9; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v10; // ecx
  const vostok::configs::binary_config_value *v11; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v12; // ecx
  const vostok::variant<32> **v13; // eax
  vostok::configs::binary_config_value v14; // [esp-18h] [ebp-134h]
  vostok::configs::binary_config_value v15; // [esp-18h] [ebp-134h]
  vostok::configs::binary_config_value v16; // [esp-18h] [ebp-134h]
  vostok::fixed_string<16> __x; // [esp+DCh] [ebp-40h] BYREF
  const vostok::configs::binary_config_value *end; // [esp+F8h] [ebp-24h]
  vostok::configs::binary_config_value bone_parts_filter; // [esp+FCh] [ebp-20h] BYREF
  const vostok::configs::binary_config_value *it; // [esp+118h] [ebp-4h]

  survarium::collision_sensor::load(this, t);
  v14 = *vostok::configs::binary_config_value::operator[](t, "hit_curve");
  vostok::math::curve_line_points<float,0>::load<vostok::configs::binary_config_value>(&this->m_hit_curve, a2, v14);
  v15 = *vostok::configs::binary_config_value::operator[](t, "on_bound_motion_curve");
  vostok::math::curve_line_points<float,0>::load<vostok::configs::binary_config_value>(
    &this->m_motion_on_bound_curve,
    a2,
    v15);
  v16 = *vostok::configs::binary_config_value::operator[](t, "on_center_motion_curve");
  vostok::math::curve_line_points<float,0>::load<vostok::configs::binary_config_value>(
    &this->m_motion_on_center_curve,
    a2,
    v16);
  v3 = vostok::configs::binary_config_value::operator[](t, "apply_hit_type");
  this->m_apply_hit_type = vostok::configs::binary_config_value::operator unsigned char(v4, (int)v3);
  vostok::configs::binary_config_value::operator[](t, "max_hit");
  vostok::configs::binary_config_value::operator float(v5);
  this->m_max_hit = a2;
  vostok::configs::binary_config_value::operator[](t, "min_hit");
  vostok::configs::binary_config_value::operator float(v6);
  this->m_min_hit = a2;
  vostok::configs::binary_config_value::operator[](t, "max_armor_piercing");
  vostok::configs::binary_config_value::operator float(v7);
  this->m_max_armor_piercing = a2;
  vostok::configs::binary_config_value::operator[](t, "min_armor_piercing");
  vostok::configs::binary_config_value::operator float(v8);
  this->m_min_armor_piercing = a2;
  v9 = vostok::configs::binary_config_value::operator[](t, "interval_in_msec");
  this->m_hit_interval_ms = (unsigned int)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                            v10,
                                            (int)v9);
  v11 = vostok::configs::binary_config_value::operator[](t, "damage_type");
  vostok::fixed_string<260>::operator=<vostok::configs::binary_config_value>(
    (vostok::fixed_string<260> *)&this->m_damage_type,
    v11);
  bone_parts_filter = *vostok::configs::binary_config_value::operator[](t, "hit_parts_filter");
  it = (const vostok::configs::binary_config_value *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&bone_parts_filter);
  end = vostok::configs::binary_config_value::end(&bone_parts_filter);
  while ( it != end )
  {
    v13 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v12, (int)it);
    vostok::fixed_string<16>::fixed_string<16>(&__x, (const char *)v13);
    stlp_std::priv::_Impl_vector<vostok::fixed_string<16>,survarium::std_allocator<vostok::fixed_string<16>>>::push_back(
      &this->m_body_parts_filter._M_impl,
      &__x);
    v12 = (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)&it[1];
    ++it;
  }
}
