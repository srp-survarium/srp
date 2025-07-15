void __userpurge survarium::player_stealth::load(
        survarium::player_stealth *this@<ecx>,
        float a2@<xmm0>,
        vostok::configs::binary_config_value *config)
{
  vostok::configs::binary_config_value *v3; // ecx
  vostok::configs::binary_config_value *v4; // ecx
  vostok::configs::binary_config_value *v5; // ecx
  vostok::configs::binary_config_value *v6; // ecx
  vostok::configs::binary_config_value *v7; // ecx
  vostok::configs::binary_config_value *v8; // ecx
  vostok::configs::binary_config_value *v9; // ecx
  vostok::configs::binary_config_value *v10; // ecx
  vostok::configs::binary_config_value *v11; // ecx
  vostok::configs::binary_config_value *v12; // ecx
  vostok::configs::binary_config_value *v13; // ecx

  vostok::configs::binary_config_value::operator[](config, (const char *)&stru_960860);
  vostok::configs::binary_config_value::operator float(v3);
  this->m_default_value = a2;
  vostok::configs::binary_config_value::operator[](config, "default_sound_value");
  vostok::configs::binary_config_value::operator float(v4);
  this->m_default_sound_value = a2;
  vostok::configs::binary_config_value::operator[](config, "stand_factor");
  vostok::configs::binary_config_value::operator float(v5);
  this->m_stand_factor = a2;
  vostok::configs::binary_config_value::operator[](config, "crouch_factor");
  vostok::configs::binary_config_value::operator float(v6);
  this->m_crouch_factor = a2;
  vostok::configs::binary_config_value::operator[](config, "crouch_sound_factor");
  vostok::configs::binary_config_value::operator float(v7);
  this->m_crouch_sound_factor = a2;
  vostok::configs::binary_config_value::operator[](config, "walk_factor");
  vostok::configs::binary_config_value::operator float(v8);
  this->m_walk_factor = a2;
  vostok::configs::binary_config_value::operator[](config, "walk_sound_factor");
  vostok::configs::binary_config_value::operator float(v9);
  this->m_walk_sound_factor = a2;
  vostok::configs::binary_config_value::operator[](config, "sprint_factor");
  vostok::configs::binary_config_value::operator float(v10);
  this->m_sprint_factor = a2;
  vostok::configs::binary_config_value::operator[](config, "sprint_sound_factor");
  vostok::configs::binary_config_value::operator float(v11);
  this->m_sprint_sound_factor = a2;
  vostok::configs::binary_config_value::operator[](config, "detection_level");
  vostok::configs::binary_config_value::operator float(v12);
  this->m_detection_level = a2;
  vostok::configs::binary_config_value::operator[](config, "always_visible_distance");
  vostok::configs::binary_config_value::operator float(v13);
  this->m_always_visible_distance = a2;
}
