void __userpurge survarium::player_stamina::load(
        survarium::player_stamina *this@<ecx>,
        float a2@<xmm0>,
        vostok::configs::binary_config_value *config)
{
  vostok::configs::binary_config_value *v3; // ecx
  vostok::configs::binary_config_value *v4; // ecx
  vostok::configs::binary_config_value *v5; // ecx
  float v6; // xmm0_4
  vostok::configs::binary_config_value *v7; // ecx
  vostok::configs::binary_config_value *v8; // ecx
  vostok::configs::binary_config_value *v9; // ecx

  vostok::configs::binary_config_value::operator[](config, "spending_threshold");
  vostok::configs::binary_config_value::operator float(v3);
  this->m_spending_threshold = a2;
  vostok::configs::binary_config_value::operator[](config, "regeneration_threshold");
  vostok::configs::binary_config_value::operator float(v4);
  this->m_regeneration_threshold = a2;
  vostok::configs::binary_config_value::operator[](config, "max_value");
  vostok::configs::binary_config_value::operator float(v5);
  this->m_max_value = a2;
  v6 = this->m_max_value * this->m_max_value_factor;
  this->m_value = v6;
  vostok::configs::binary_config_value::operator[](config, "spending_speed");
  vostok::configs::binary_config_value::operator float(v7);
  this->m_spending_speed = v6;
  vostok::configs::binary_config_value::operator[](config, "regeneration_speed");
  vostok::configs::binary_config_value::operator float(v8);
  this->m_regeneration_speed = v6;
  vostok::configs::binary_config_value::operator[](config, "max_carried_weight");
  vostok::configs::binary_config_value::operator float(v9);
  this->m_max_carried_weight = v6;
}
