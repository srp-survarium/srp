void __thiscall vostok::particle::particle_action_trail::load_impl<vostok::configs::binary_config_value>(
        vostok::particle::particle_action_trail *this,
        const vostok::configs::binary_config_value *prop_config)
{
  const char *v2; // eax
  char *default_value; // [esp+10h] [ebp-90h] BYREF
  vostok::fixed_string<128> name; // [esp+14h] [ebp-8Ch] BYREF

  default_value = (char *)&buf;
  v2 = vostok::particle::read_config_value<char const *,vostok::configs::binary_config_value>(
         prop_config,
         "ScreenAlignment",
         (const char *const *)&default_value);
  vostok::fixed_string<128>::fixed_string<128>(&name, v2);
  this->m_screen_alignment = vostok::particle::screen_alignment_name_to_type(&name);
  this->m_beamtrail_parameters.num_sheets = vostok::particle::read_config_value<unsigned int,vostok::configs::binary_config_value>(
                                              prop_config,
                                              "SheetsCount",
                                              &this->m_beamtrail_parameters.num_sheets);
  this->m_beamtrail_parameters.num_texture_tiles = vostok::particle::read_config_value<unsigned int,vostok::configs::binary_config_value>(
                                                     prop_config,
                                                     "TextureTile",
                                                     &this->m_beamtrail_parameters.num_texture_tiles);
}
