void __userpurge vostok::particle::curve_line_points<float,0>::load<vostok::configs::binary_config_value>(
        vostok::particle::curve_line_points<float,0> *this@<ecx>,
        float x@<xmm0>,
        vostok::configs::binary_config_value keys_config)
{
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v3; // ecx
  const vostok::variant<32> **v4; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v5; // ecx
  const vostok::variant<32> **v6; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v7; // ecx
  const vostok::variant<32> **v8; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v9; // ecx
  const vostok::variant<32> **v10; // eax
  survarium::game_camera *v11; // ecx
  _BYTE *v12; // eax
  const vostok::configs::binary_config_value *v13; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v14; // ecx
  const vostok::variant<32> **v15; // eax
  const vostok::configs::binary_config_value *v16; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v17; // ecx
  const vostok::variant<32> **v18; // eax
  const vostok::configs::binary_config_value *v19; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v20; // ecx
  const vostok::variant<32> **v21; // eax
  vostok::configs::binary_config_value *v22; // ecx
  vostok::math::float2 *v23; // eax
  vostok::math::float2 *v24; // eax
  BOOL v25; // ecx
  const vostok::configs::binary_config_value *v26; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v27; // ecx
  survarium::game_camera *v28; // ecx
  _BYTE *v29; // eax
  const vostok::configs::binary_config_value *v30; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v31; // ecx
  const vostok::variant<32> **v32; // eax
  vostok::configs::binary_config_value *v33; // ecx
  survarium::game_camera *v34; // ecx
  float v35; // [esp+0h] [ebp-120h]
  __int64 v37; // [esp+5Ch] [ebp-C4h]
  vostok::math::float2 v38; // [esp+68h] [ebp-B8h] BYREF
  vostok::math::float2 v39; // [esp+70h] [ebp-B0h] BYREF
  char v40; // [esp+7Bh] [ebp-A5h]
  vostok::math::float4 RGBA; // [esp+7Ch] [ebp-A4h]
  float t0; // [esp+8Ch] [ebp-94h]
  float delta; // [esp+90h] [ebp-90h]
  float t1; // [esp+94h] [ebp-8Ch]
  vostok::math::float2 left_tangent; // [esp+98h] [ebp-88h] BYREF
  float lower_value; // [esp+A0h] [ebp-80h]
  vostok::math::float2 right_tangent; // [esp+A4h] [ebp-7Ch] BYREF
  float upper_value; // [esp+ACh] [ebp-74h]
  vostok::math::float2 position; // [esp+B0h] [ebp-70h] BYREF
  vostok::configs::binary_config_value v50; // [esp+B8h] [ebp-68h] BYREF
  vostok::particle::curve_point<float> point; // [esp+D0h] [ebp-50h]
  vostok::configs::binary_config_value it; // [esp+E8h] [ebp-38h] BYREF
  unsigned int num_keys; // [esp+100h] [ebp-20h]
  unsigned int point_index; // [esp+104h] [ebp-1Ch]
  unsigned int key_index; // [esp+108h] [ebp-18h]
  vostok::fixed_string<8> key_name; // [esp+10Ch] [ebp-14h] BYREF

  num_keys = 0;
  vostok::fixed_string<8>::fixed_string<8>((vostok::fixed_string<8> *)this, (int)&key_name);
  for ( key_index = 0; ; ++key_index )
  {
    vostok::buffer_string::assignf(&key_name, "key%d", key_index);
    v4 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v3, (int)&key_name);
    if ( !vostok::configs::binary_config_value::value_exists(&keys_config, (const char *)v4) )
      break;
    v6 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v5, (int)&key_name);
    it = *vostok::configs::binary_config_value::operator[](&keys_config, (const char *)v6);
    if ( !vostok::configs::binary_config_value::size(&it) )
      break;
  }
  num_keys = key_index;
  vostok::particle::curve_line_points<float,0>::reserve(this, key_index, 1);
  point_index = 0;
  key_index = 0;
  while ( 1 )
  {
    vostok::buffer_string::assignf(&key_name, "key%d", key_index);
    v8 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v7, (int)&key_name);
    if ( !vostok::configs::binary_config_value::value_exists(&keys_config, (const char *)v8) )
      break;
    v10 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v9, (int)&key_name);
    v50 = *vostok::configs::binary_config_value::operator[](&keys_config, (const char *)v10);
    if ( !vostok::configs::binary_config_value::size(&v50) )
      break;
    ++key_index;
    v40 = 1;
    survarium::weapon_user_dead_state::finalize(v11);
    if ( *v12 )
    {
      v13 = vostok::configs::binary_config_value::operator[](&v50, "left_tangent");
      v15 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v14, (int)v13);
      Wm4::Vector2<float>::operator=((vostok::math::float2 *)v15, &left_tangent);
      v16 = vostok::configs::binary_config_value::operator[](&v50, "position");
      v18 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v17, (int)v16);
      Wm4::Vector2<float>::operator=((vostok::math::float2 *)v18, &position);
      v19 = vostok::configs::binary_config_value::operator[](&v50, "right_tangent");
      v21 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v20, (int)v19);
      Wm4::Vector2<float>::operator=((vostok::math::float2 *)v21, &right_tangent);
      if ( vostok::configs::binary_config_value::value_exists(&v50, "delta") )
      {
        vostok::configs::binary_config_value::operator[](&v50, "delta");
        vostok::configs::binary_config_value::operator float(v22);
        v35 = x;
      }
      else
      {
        v35 = *(float *)&FLOAT_0_0;
      }
      delta = v35;
      upper_value = position.y + v35;
      lower_value = position.y - v35;
      point.upper_value = position.y + v35;
      point.lower_value = position.y - v35;
      point.time = position.x;
      v23 = vostok::math::operator-(&left_tangent, &position, &v39);
      t0 = vostok::particle::get_tangent_from_2d_vector(v23);
      v24 = vostok::math::operator-(&position, &right_tangent, &v38);
      t1 = vostok::particle::get_tangent_from_2d_vector(v24);
      point.tangent_in = t0;
      x = t1;
      point.tangent_out = t1;
      if ( vostok::configs::binary_config_value::value_exists(&v50, "key_type") )
      {
        v26 = vostok::configs::binary_config_value::operator[](&v50, "key_type");
        v25 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v27, (int)v26) != (const vostok::variant<32> **)3;
        point.interp_type = v25;
      }
      else
      {
        point.interp_type = curve_interp_type;
      }
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v25);
      this->points.pointer[point_index] = point;
    }
    else
    {
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)(unsigned __int8)*v12);
      if ( *v29 )
      {
        v30 = vostok::configs::binary_config_value::operator[](&v50, (const char *)&stru_955964);
        v32 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v31, (int)v30);
        v37 = *((_QWORD *)v32 + 1);
        *(_QWORD *)&RGBA.x = *(_QWORD *)v32;
        *(_QWORD *)&RGBA.elements[2] = v37;
        point.upper_value = RGBA.x;
        x = RGBA.x;
        point.lower_value = RGBA.x;
        vostok::configs::binary_config_value::operator[](&v50, (const char *)&stru_955964.id_crc);
        vostok::configs::binary_config_value::operator float(v33);
        point.time = x;
        point.interp_type = linear_interp_type;
        survarium::weapon_user_dead_state::finalize(v34);
        this->points.pointer[point_index] = point;
      }
      else
      {
        survarium::weapon_user_dead_state::finalize(v28);
      }
    }
    ++point_index;
  }
  vostok::particle::curve_line_points<float,0>::recalculate_ranges(this);
  vostok::particle::curve_line_points<float,0>::sort_points_by_time(this);
}
