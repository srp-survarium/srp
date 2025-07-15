void __thiscall vostok::particle::particle_action_billboard::load_impl<vostok::configs::binary_config_value>(
        vostok::particle::particle_action_billboard *this,
        vostok::configs::binary_config_value *prop_config)
{
  const vostok::configs::binary_config_value *v2; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v3; // ecx
  const vostok::variant<32> **v4; // eax
  const vostok::configs::binary_config_value *v5; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v6; // ecx
  const vostok::variant<32> **v7; // eax
  const vostok::configs::binary_config_value *v8; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v9; // ecx
  const vostok::variant<32> **v10; // eax
  vostok::configs::binary_config_value v11; // [esp-18h] [ebp-1F4h]
  vostok::fixed_string<128> v13; // [esp+38h] [ebp-1A4h] BYREF
  vostok::fixed_string<128> v14; // [esp+C4h] [ebp-118h] BYREF
  vostok::fixed_string<128> name; // [esp+150h] [ebp-8Ch] BYREF

  this->m_use_sub_uv = vostok::particle::read_config_value<bool,vostok::configs::binary_config_value>(
                         prop_config,
                         "UseSubUV",
                         &this->m_use_sub_uv);
  this->m_sub_image_horizontal = vostok::particle::read_config_value<unsigned int,vostok::configs::binary_config_value>(
                                   prop_config,
                                   "SubImgHorizontal",
                                   &this->m_sub_image_horizontal);
  this->m_sub_image_vertical = vostok::particle::read_config_value<unsigned int,vostok::configs::binary_config_value>(
                                 prop_config,
                                 "SubImgVertical",
                                 &this->m_sub_image_vertical);
  this->m_use_movie = vostok::particle::read_config_value<bool,vostok::configs::binary_config_value>(
                        prop_config,
                        "UseMovie",
                        &this->m_use_movie);
  this->m_movie_frame_rate = vostok::particle::read_config_value<float,vostok::configs::binary_config_value>(
                               prop_config,
                               "MovieFrameRate",
                               &this->m_movie_frame_rate);
  this->m_movie_start_frame = vostok::particle::read_config_value<float,vostok::configs::binary_config_value>(
                                prop_config,
                                "MovieStartFrame",
                                &this->m_movie_start_frame);
  this->m_billboard_parameters.sub_image_changes = vostok::particle::read_config_value<unsigned int,vostok::configs::binary_config_value>(
                                                     prop_config,
                                                     "SubImgChange",
                                                     &this->m_billboard_parameters.sub_image_changes);
  this->m_billboard_parameters.sub_image_horizontal = this->m_sub_image_horizontal;
  this->m_billboard_parameters.sub_image_vertical = this->m_sub_image_vertical;
  if ( vostok::configs::binary_config_value::value_exists(prop_config, "ScreenAlignment") )
  {
    v2 = vostok::configs::binary_config_value::operator[](prop_config, "ScreenAlignment");
    v4 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v3, (int)v2);
    vostok::fixed_string<128>::fixed_string<128>(&name, (const char *)v4);
    this->m_billboard_parameters.screen_alignment = vostok::particle::screen_alignment_name_to_type(&name);
  }
  if ( vostok::configs::binary_config_value::value_exists(prop_config, "LockAxisFlags") )
  {
    v5 = vostok::configs::binary_config_value::operator[](prop_config, "LockAxisFlags");
    v7 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v6, (int)v5);
    vostok::fixed_string<128>::fixed_string<128>(&v14, (const char *)v7);
    this->m_billboard_parameters.locked_axis = vostok::particle::locked_axis_name_to_type(&v14);
  }
  if ( vostok::configs::binary_config_value::value_exists(prop_config, "Method") )
  {
    v8 = vostok::configs::binary_config_value::operator[](prop_config, "Method");
    v10 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v9, (int)v8);
    vostok::fixed_string<128>::fixed_string<128>(&v13, (const char *)v10);
    this->m_billboard_parameters.subuv_method = vostok::particle::sub_uv_method_name_to_type(&v13);
  }
  v11 = *vostok::configs::binary_config_value::operator[](prop_config, "SubImgIndex");
  vostok::particle::curve_line_ranged_float::load<vostok::configs::binary_config_value>(&this->m_subimage_index, v11);
}
