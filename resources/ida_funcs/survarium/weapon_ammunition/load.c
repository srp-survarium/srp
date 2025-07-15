void __userpurge survarium::weapon_ammunition::load(
        survarium::weapon_ammunition *this@<ecx>,
        float a2@<xmm0>,
        vostok::configs::binary_config_value *cfg)
{
  vostok::configs::binary_config_value *v3; // ecx
  vostok::configs::binary_config_value *v4; // ecx
  vostok::configs::binary_config_value *v5; // ecx
  vostok::configs::binary_config_value *v6; // ecx
  vostok::configs::binary_config_value *v7; // ecx
  vostok::configs::binary_config_value *v8; // ecx
  vostok::configs::binary_config_value *v9; // eax
  vostok::configs::binary_config_value *v10; // ecx
  const vostok::configs::binary_config_value *v11; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v12; // ecx
  vostok::configs::binary_config_value *v13; // ecx
  vostok::configs::binary_config_value *v15; // [esp+38h] [ebp-20h]
  vostok::configs::binary_config_value *v16; // [esp+4Ch] [ebp-Ch]

  vostok::configs::binary_config_value::operator[](cfg, "distance_coef");
  vostok::configs::binary_config_value::operator float(v3);
  this->m_distance = a2;
  vostok::configs::binary_config_value::operator[](cfg, "dispersion");
  vostok::configs::binary_config_value::operator float(v4);
  this->m_dispersion = a2;
  vostok::configs::binary_config_value::operator[](cfg, "k_damage");
  vostok::configs::binary_config_value::operator float(v5);
  this->m_damage = a2;
  vostok::configs::binary_config_value::operator[](cfg, "impulse_coef");
  vostok::configs::binary_config_value::operator float(v6);
  this->m_impulse = a2;
  vostok::configs::binary_config_value::operator[](cfg, "k_arp");
  vostok::configs::binary_config_value::operator float(v7);
  this->m_pierce = a2;
  vostok::configs::binary_config_value::operator[](cfg, "air_resistance");
  vostok::configs::binary_config_value::operator float(v8);
  this->m_air_resistance = a2;
  v16 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](cfg, "buck_shot");
  this->m_buck_shot = vostok::configs::binary_config_value::cast_number<short,__int64,int>(v16);
  v15 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                  cfg,
                                                  "game_material_id");
  this->m_game_material_id = vostok::configs::binary_config_value::cast_number<short,__int64,int>(v15);
  v9 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](cfg, "tracer");
  this->m_tracer = vostok::configs::binary_config_value::operator bool(v9);
  vostok::configs::binary_config_value::operator[](cfg, "ricochet_angle");
  vostok::configs::binary_config_value::operator float(v10);
  this->m_ricochet_angle = a2;
  v11 = vostok::configs::binary_config_value::operator[](cfg, "ammo_type");
  this->m_ammo_type = (survarium::ammo_type_enum)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                                   v12,
                                                   (int)v11);
  vostok::configs::binary_config_value::operator[](cfg, "muzzle_speed");
  vostok::configs::binary_config_value::operator float(v13);
  this->m_muzzle_speed = a2;
}
