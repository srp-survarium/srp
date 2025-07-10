void __userpurge vostok::math::curve_line_points<float,0>::load<vostok::configs::binary_config_value>(
        vostok::math::curve_line_points<float,0> *this@<ecx>,
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
  const vostok::configs::binary_config_value *v25; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v26; // ecx
  survarium::game_camera *v27; // ecx
  _BYTE *v28; // eax
  const vostok::configs::binary_config_value *v29; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v30; // ecx
  const vostok::variant<32> **v31; // eax
  vostok::configs::binary_config_value *v32; // ecx
  vostok::math::curve_point<float> v33; // [esp-18h] [ebp-130h]
  float v34; // [esp+0h] [ebp-118h]
  __int64 v36; // [esp+54h] [ebp-C4h]
  vostok::math::float2 v37; // [esp+60h] [ebp-B8h] BYREF
  vostok::math::float2 v38; // [esp+68h] [ebp-B0h] BYREF
  char v39; // [esp+73h] [ebp-A5h]
  vostok::math::float4 RGBA; // [esp+74h] [ebp-A4h]
  float t0; // [esp+84h] [ebp-94h]
  float delta; // [esp+88h] [ebp-90h]
  float t1; // [esp+8Ch] [ebp-8Ch]
  vostok::math::float2 left_tangent; // [esp+90h] [ebp-88h] BYREF
  float lower_value; // [esp+98h] [ebp-80h]
  vostok::math::float2 right_tangent; // [esp+9Ch] [ebp-7Ch] BYREF
  float upper_value; // [esp+A4h] [ebp-74h]
  vostok::math::float2 position; // [esp+A8h] [ebp-70h] BYREF
  vostok::configs::binary_config_value v49; // [esp+B0h] [ebp-68h] BYREF
  vostok::math::curve_point<float> point; // [esp+C8h] [ebp-50h]
  vostok::configs::binary_config_value it; // [esp+E0h] [ebp-38h] BYREF
  unsigned int num_keys; // [esp+F8h] [ebp-20h]
  unsigned int point_index; // [esp+FCh] [ebp-1Ch]
  unsigned int key_index; // [esp+100h] [ebp-18h]
  vostok::fixed_string<8> key_name; // [esp+104h] [ebp-14h] BYREF

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
  vostok::math::curve_line_points<float,0>::reserve(this, key_index, 1);
  point_index = 0;
  key_index = 0;
  while ( 1 )
  {
    vostok::buffer_string::assignf(&key_name, "key%d", key_index);
    v8 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v7, (int)&key_name);
    if ( !vostok::configs::binary_config_value::value_exists(&keys_config, (const char *)v8) )
      break;
    v10 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v9, (int)&key_name);
    v49 = *vostok::configs::binary_config_value::operator[](&keys_config, (const char *)v10);
    if ( !vostok::configs::binary_config_value::size(&v49) )
      break;
    ++key_index;
    v39 = 1;
    survarium::weapon_user_dead_state::finalize(v11);
    if ( *v12 )
    {
      v13 = vostok::configs::binary_config_value::operator[](&v49, "left_tangent");
      v15 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v14, (int)v13);
      Wm4::Vector2<float>::operator=((vostok::math::float2 *)v15, &left_tangent);
      v16 = vostok::configs::binary_config_value::operator[](&v49, "position");
      v18 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v17, (int)v16);
      Wm4::Vector2<float>::operator=((vostok::math::float2 *)v18, &position);
      v19 = vostok::configs::binary_config_value::operator[](&v49, "right_tangent");
      v21 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v20, (int)v19);
      Wm4::Vector2<float>::operator=((vostok::math::float2 *)v21, &right_tangent);
      if ( vostok::configs::binary_config_value::value_exists(&v49, "delta") )
      {
        vostok::configs::binary_config_value::operator[](&v49, "delta");
        vostok::configs::binary_config_value::operator float(v22);
        v34 = x;
      }
      else
      {
        v34 = *(float *)&FLOAT_0_0;
      }
      delta = v34;
      upper_value = position.y + v34;
      lower_value = position.y - v34;
      point.upper_value = position.y + v34;
      point.lower_value = position.y - v34;
      point.time = position.x;
      v23 = vostok::math::operator-(&left_tangent, &position, &v38);
      t0 = vostok::math::get_tangent_from_2d_vector(v23);
      v24 = vostok::math::operator-(&position, &right_tangent, &v37);
      t1 = vostok::math::get_tangent_from_2d_vector(v24);
      point.tangent_in = t0;
      x = t1;
      point.tangent_out = t1;
      if ( vostok::configs::binary_config_value::value_exists(&v49, "key_type") )
      {
        v25 = vostok::configs::binary_config_value::operator[](&v49, "key_type");
        point.interp_type = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                              v26,
                              (int)v25) != (const vostok::variant<32> **)3;
      }
      else
      {
        point.interp_type = curve_interp_type;
      }
      vostok::math::curve_line_points<float,0>::set_point(this, point_index, point);
    }
    else
    {
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)(unsigned __int8)*v12);
      if ( *v28 )
      {
        v29 = vostok::configs::binary_config_value::operator[](&v49, (const char *)&stru_955964);
        v31 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v30, (int)v29);
        v36 = *((_QWORD *)v31 + 1);
        *(_QWORD *)&RGBA.x = *(_QWORD *)v31;
        *(_QWORD *)&RGBA.elements[2] = v36;
        point.upper_value = RGBA.x;
        x = RGBA.x;
        point.lower_value = RGBA.x;
        vostok::configs::binary_config_value::operator[](&v49, (const char *)&stru_955964.id_crc);
        vostok::configs::binary_config_value::operator float(v32);
        point.time = x;
        point.interp_type = linear_interp_type;
        *(_QWORD *)&v33.upper_value = *(_QWORD *)&point.upper_value;
        *(_QWORD *)&v33.tangent_in = *(_QWORD *)&point.tangent_in;
        *(_QWORD *)&v33.time = LODWORD(x);
        vostok::math::curve_line_points<float,0>::set_point(this, point_index, v33);
      }
      else
      {
        survarium::weapon_user_dead_state::finalize(v27);
      }
    }
    ++point_index;
  }
  vostok::math::curve_line_points<float,0>::recalculate_ranges(this);
  vostok::math::curve_line_points<float,0>::sort_points_by_time(this);
}
