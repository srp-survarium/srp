void __userpurge survarium::game_material::load_from_config(
        survarium::game_material *this@<ecx>,
        float a2@<xmm0>,
        vostok::configs::binary_config_value *val)
{
  const vostok::configs::binary_config_value *v3; // eax
  vostok::configs::binary_config_value *v4; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v5; // ecx
  const vostok::variant<32> **v6; // eax
  vostok::configs::binary_config_value *v7; // eax
  vostok::configs::binary_config_value *v8; // ecx
  vostok::configs::binary_config_value *v9; // eax
  vostok::configs::binary_config_value *v10; // ecx
  vostok::configs::binary_config_value *v11; // eax
  vostok::configs::binary_config_value *v12; // ecx
  vostok::configs::binary_config_value *v13; // eax
  vostok::configs::binary_config_value *v14; // ecx
  vostok::configs::binary_config_value *v15; // eax
  vostok::configs::binary_config_value *v16; // eax
  vostok::configs::binary_config_value *v17; // eax
  vostok::configs::binary_config_value *v18; // eax
  vostok::configs::binary_config_value *v19; // eax
  vostok::configs::binary_config_value *v20; // eax
  vostok::configs::binary_config_value *v21; // eax
  vostok::configs::binary_config_value *v22; // eax
  const vostok::configs::binary_config_value *v24; // [esp+Ch] [ebp-10h]
  unsigned __int16 physics_group; // [esp+18h] [ebp-4h]

  v3 = vostok::configs::binary_config_value::operator[](val, "id");
  this->m_id = vostok::configs::binary_config_value::operator unsigned short(v4, (int)v3);
  v24 = vostok::configs::binary_config_value::operator[](val, "name");
  v6 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v5, (int)v24);
  vostok::buffer_string::operator=(&this->m_name, (const char *)v6);
  v7 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](val, "physic");
  vostok::configs::binary_config_value::operator[](v7, "resistance");
  vostok::configs::binary_config_value::operator float(v8);
  this->m_material_resistance = a2;
  v9 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](val, "physic");
  vostok::configs::binary_config_value::operator[](v9, "reflection_speed_down");
  vostok::configs::binary_config_value::operator float(v10);
  this->m_bullet_reflection_speed_down = a2;
  v11 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](val, "physic");
  vostok::configs::binary_config_value::operator[](v11, "width");
  vostok::configs::binary_config_value::operator float(v12);
  this->m_width = a2;
  v13 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](val, "physic");
  vostok::configs::binary_config_value::operator[](v13, "k_ricochet");
  vostok::configs::binary_config_value::operator float(v14);
  this->m_ricochet_koef = a2;
  physics_group = 0;
  v15 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](val, "mine");
  v16 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](v15, "can_place");
  this->m_mine_can_place = vostok::configs::binary_config_value::operator bool(v16);
  v17 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](val, "mine");
  v18 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](v17, "can_stick");
  this->m_mine_can_stick = vostok::configs::binary_config_value::operator bool(v18);
  v19 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](val, "physic");
  v20 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](v19, "hittable");
  if ( vostok::configs::binary_config_value::operator bool(v20) )
    physics_group = 8;
  v21 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](val, "physic");
  v22 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](v21, "walkable");
  if ( vostok::configs::binary_config_value::operator bool(v22) )
    physics_group |= 2u;
  survarium::g_material_physics_group[this->m_id] = physics_group;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
}
