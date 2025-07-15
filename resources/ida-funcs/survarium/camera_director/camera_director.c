void __userpurge survarium::camera_director::camera_director(
        survarium::base_game_scene *w@<eax>,
        vostok::console_commands::cc_float3 *a2@<ecx>,
        long double a3@<esi:edi>,
        survarium::camera_director *this)
{
  bool v4; // zf
  float v5; // xmm1_4
  vostok::math::float3 v6; // [esp-14h] [ebp-8Ch]
  vostok::math::float3 v7; // [esp-8h] [ebp-80h] BYREF
  vostok::console_commands::execution_filter v8; // [esp+Ch] [ebp-6Ch]
  _BYTE v9[64]; // [esp+1Ch] [ebp-5Ch] BYREF
  vostok::math::float3 p; // [esp+5Ch] [ebp-1Ch] BYREF
  vostok::math::float3 d; // [esp+68h] [ebp-10h] BYREF

  this->m_active_camera = 0;
  v4 = (_S9_1 & 1) == 0;
  this->__vftable = (survarium::camera_director_vtbl *)&survarium::camera_director::`vftable';
  this->m_game_scene = w;
  if ( v4 )
  {
    _S9_1 |= 1u;
    d.x = FLOAT_1000_0;
    d.y = FLOAT_1000_0;
    d.z = FLOAT_1000_0;
    v7.x = FLOAT_1000_0;
    v7.y = FLOAT_1000_0;
    v7.z = FLOAT_1000_0;
    p.x = FLOAT_N1000_0;
    p.y = FLOAT_N1000_0;
    p.z = FLOAT_N1000_0;
    v6.x = FLOAT_N1000_0;
    v6.y = FLOAT_N1000_0;
    v6.z = FLOAT_N1000_0;
    HIDWORD(a3) = &d;
    LODWORD(a3) = &v7;
    vostok::console_commands::cc_float3::cc_float3(
      a2,
      (int)&cc_cam_pos,
      "camera_pos",
      (vostok::math::float3 *)&this->m_inverted_view.lines[3],
      v6,
      v7,
      0,
      command_type_user_specific,
      v8);
    atexit((int (__cdecl *)())survarium::camera_director::camera_director_::_2_::_dynamic_atexit_destructor_for__cc_cam_pos__);
  }
  v5 = sqrt(2.0);
  d.x = (float)(s_bm_current_air_resistance / v5) * -1.0;
  d.y = d.x;
  d.z = (float)(s_bm_current_air_resistance / v5) * 0.0;
  p.x = vostok::render::grass_patch_size;
  *(_QWORD *)&p.elements[1] = LODWORD(FLOAT_10_0);
  survarium::camera_director::set_position_direction(&d, this, &p);
  qmemcpy(
    &this->m_projection,
    vostok::math::create_perspective_projection(
      a3,
      (float)(survarium::default_vertical_fov * 0.017453292) * 0.75,
      (vostok::math *)v9,
      COERCE_STRUCT_VOSTOK_MATH_FLOAT4X4_(1.3333334),
      0.2,
      5000.0),
    sizeof(this->m_projection));
}
