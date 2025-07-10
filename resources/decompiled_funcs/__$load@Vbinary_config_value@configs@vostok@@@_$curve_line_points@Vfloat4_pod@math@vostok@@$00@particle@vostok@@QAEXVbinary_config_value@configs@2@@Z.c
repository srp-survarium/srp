void __userpurge vostok::particle::curve_line_points<vostok::math::float4_pod,1>::load<vostok::configs::binary_config_value>(
        vostok::particle::curve_line_points<vostok::math::float4_pod,1> *this@<ecx>,
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
  vostok::configs::binary_config_value *v32; // ecx
  survarium::game_camera *v33; // ecx
  float v34; // [esp+8h] [ebp-158h]
  vostok::math::float2 v36; // [esp+78h] [ebp-E8h] BYREF
  vostok::math::float2 v37; // [esp+80h] [ebp-E0h] BYREF
  char v38; // [esp+8Bh] [ebp-D5h]
  vostok::math::float4 RGBA; // [esp+8Ch] [ebp-D4h]
  unsigned int t0; // [esp+9Ch] [ebp-C4h]
  unsigned int delta; // [esp+A0h] [ebp-C0h]
  unsigned int t1; // [esp+A4h] [ebp-BCh]
  vostok::math::float2 left_tangent; // [esp+A8h] [ebp-B8h] BYREF
  unsigned int lower_value; // [esp+B0h] [ebp-B0h]
  vostok::math::float2 right_tangent; // [esp+B4h] [ebp-ACh] BYREF
  float upper_value; // [esp+BCh] [ebp-A4h]
  vostok::math::float2 position; // [esp+C0h] [ebp-A0h] BYREF
  vostok::configs::binary_config_value v48; // [esp+C8h] [ebp-98h] BYREF
  vostok::particle::curve_point<vostok::math::float4_pod> point; // [esp+E0h] [ebp-80h] BYREF
  vostok::configs::binary_config_value it; // [esp+128h] [ebp-38h] BYREF
  unsigned int num_keys; // [esp+140h] [ebp-20h]
  unsigned int point_index; // [esp+144h] [ebp-1Ch]
  unsigned int key_index; // [esp+148h] [ebp-18h]
  vostok::fixed_string<8> key_name; // [esp+14Ch] [ebp-14h] BYREF

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
  vostok::particle::curve_line_points<vostok::math::float4_pod,1>::reserve(this, key_index, 1);
  point_index = 0;
  key_index = 0;
  while ( 1 )
  {
    vostok::buffer_string::assignf(&key_name, "key%d", key_index);
    v8 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v7, (int)&key_name);
    if ( !vostok::configs::binary_config_value::value_exists(&keys_config, (const char *)v8) )
      break;
    v10 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v9, (int)&key_name);
    v48 = *vostok::configs::binary_config_value::operator[](&keys_config, (const char *)v10);
    if ( !vostok::configs::binary_config_value::size(&v48) )
      break;
    ++key_index;
    v38 = 0;
    survarium::weapon_user_dead_state::finalize(v11);
    if ( *v12 )
    {
      v13 = vostok::configs::binary_config_value::operator[](&v48, "left_tangent");
      v15 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v14, (int)v13);
      Wm4::Vector2<float>::operator=((vostok::math::float2 *)v15, &left_tangent);
      v16 = vostok::configs::binary_config_value::operator[](&v48, "position");
      v18 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v17, (int)v16);
      Wm4::Vector2<float>::operator=((vostok::math::float2 *)v18, &position);
      v19 = vostok::configs::binary_config_value::operator[](&v48, "right_tangent");
      v21 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v20, (int)v19);
      Wm4::Vector2<float>::operator=((vostok::math::float2 *)v21, &right_tangent);
      if ( vostok::configs::binary_config_value::value_exists(&v48, "delta") )
      {
        vostok::configs::binary_config_value::operator[](&v48, "delta");
        vostok::configs::binary_config_value::operator float(v22);
        v34 = x;
      }
      else
      {
        v34 = *(float *)&FLOAT_0_0;
      }
      delta = LODWORD(v34);
      upper_value = position.y + v34;
      *(float *)&lower_value = position.y - v34;
      point.upper_value.x = position.y + v34;
      *(vostok::math::float2 *)&point.upper_value.elements[1] = position;
      LODWORD(point.upper_value.w) = v48.data.pointer;
      point.lower_value.x = position.y - v34;
      *(vostok::math::float2 *)&point.lower_value.elements[1] = right_tangent;
      point.lower_value.w = position.y + v34;
      x = position.x;
      point.time = position.x;
      v23 = vostok::math::operator-(&left_tangent, &position, &v37);
      *(float *)&t0 = vostok::particle::get_tangent_from_2d_vector(v23);
      v24 = vostok::math::operator-(&position, &right_tangent, &v36);
      *(float *)&t1 = vostok::particle::get_tangent_from_2d_vector(v24);
      *(_QWORD *)&point.tangent_in.x = __PAIR64__(delta, t0);
      *(_QWORD *)&point.tangent_in.elements[2] = __PAIR64__(LODWORD(left_tangent.x), t1);
      *(_QWORD *)&point.tangent_out.x = __PAIR64__(LODWORD(left_tangent.x), t1);
      *(_QWORD *)&point.tangent_out.elements[2] = __PAIR64__(lower_value, LODWORD(left_tangent.y));
      if ( vostok::configs::binary_config_value::value_exists(&v48, "key_type") )
      {
        v26 = vostok::configs::binary_config_value::operator[](&v48, "key_type");
        v25 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v27, (int)v26) != (const vostok::variant<32> **)3;
        point.interp_type = v25;
      }
      else
      {
        point.interp_type = curve_interp_type;
      }
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v25);
      qmemcpy(&this->points.pointer[point_index], &point, sizeof(this->points.pointer[point_index]));
    }
    else
    {
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)(unsigned __int8)*v12);
      if ( *v29 )
      {
        v30 = vostok::configs::binary_config_value::operator[](&v48, (const char *)&stru_955964);
        RGBA = *(vostok::math::float4 *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                          v31,
                                          (int)v30);
        point.upper_value = RGBA.vostok::math::float4_pod;
        point.lower_value = RGBA.vostok::math::float4_pod;
        vostok::configs::binary_config_value::operator[](&v48, (const char *)&stru_955964.id_crc);
        vostok::configs::binary_config_value::operator float(v32);
        point.time = x;
        point.interp_type = linear_interp_type;
        survarium::weapon_user_dead_state::finalize(v33);
        qmemcpy(&this->points.pointer[point_index], &point, sizeof(this->points.pointer[point_index]));
      }
      else
      {
        survarium::weapon_user_dead_state::finalize(v28);
      }
    }
    ++point_index;
  }
  vostok::particle::curve_line_points<vostok::math::float4_pod,1>::recalculate_ranges(this);
  vostok::particle::curve_line_points<vostok::math::float4_pod,1>::sort_points_by_time(this);
}
