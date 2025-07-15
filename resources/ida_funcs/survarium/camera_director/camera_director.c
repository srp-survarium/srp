void __userpurge survarium::camera_director::camera_director(
        survarium::base_game_scene *w@<eax>,
        survarium::camera_director *this)
{
  long double v3; // st7
  vostok::math::float3 v4; // [esp-14h] [ebp-88h]
  vostok::math::float3 v5; // [esp-8h] [ebp-7Ch]
  float v6; // [esp+Ch] [ebp-68h]
  float v7; // [esp+10h] [ebp-64h]
  float v8; // [esp+14h] [ebp-60h]
  vostok::math::float3 p; // [esp+1Ch] [ebp-58h] BYREF
  vostok::math::float3 d; // [esp+28h] [ebp-4Ch] BYREF
  float thisa; // [esp+78h] [ebp+4h]

  this->m_game_scene = w;
  this->__vftable = (survarium::camera_director_vtbl *)&survarium::camera_director::`vftable';
  this->m_active_camera = 0;
  if ( (_S6_4 & 1) == 0 )
  {
    _S6_4 |= 1u;
    p.x = 1000.0;
    *(_QWORD *)&p.elements[1] = 0x447A0000447A0000LL;
    d.x = -1000.0;
    *(_QWORD *)&d.elements[1] = 0xC47A0000C47A0000uLL;
    *(_QWORD *)&v5.x = *(_QWORD *)&p.x;
    v5.z = 1000.0;
    *(_QWORD *)&v4.x = *(_QWORD *)&d.x;
    v4.z = -1000.0;
    vostok::console_commands::cc_value<vostok::math::float3>::cc_value<vostok::math::float3>(
      (vostok::console_commands::cc_value<vostok::math::float3> *)0x447A0000,
      (int)&cc_cam_pos,
      "camera_pos",
      (vostok::math::float3 *)&this->m_inverted_view.lines[3],
      v4,
      v5,
      0,
      command_type_user_specific,
      SLODWORD(v6));
    cc_cam_pos.__vftable = (vostok::console_commands::cc_float3_vtbl *)stru_95AF78.m_key_bindings[53].m_keyboard;
    atexit(survarium::camera_director::camera_director_::_2_::_dynamic_atexit_destructor_for__cc_cam_pos__);
  }
  v3 = 1.0 / sqrtf(2.0);
  thisa = v3;
  d.x = thisa * -1.0;
  d.y = thisa * -1.0;
  d.z = v3 * 0.0;
  p.x = 16.0;
  *(_QWORD *)&p.elements[1] = LODWORD(FLOAT_10_0);
  survarium::camera_director::set_position_direction(&p, &d, this);
  qmemcpy(
    (void *)&this->m_projection,
    vostok::math::create_perspective_projection(
      COERCE_VOSTOK_MATH_(1.3333334),
      COERCE_STRUCT_VOSTOK_MATH_FLOAT4X4_(0.2),
      5000.0,
      v6,
      v7,
      v8),
    sizeof(this->m_projection));
}
