bool __thiscall vostok::ai::sensors::vision_sensor::check_if_in_blind_zones(
        vostok::ai::sensors::vision_sensor *this,
        const vostok::ai::game_object *const ai_game_object)
{
  const vostok::math::float3 *v2; // eax
  const vostok::math::float3 *v3; // esi
  const vostok::math::float3 *v4; // eax
  vostok::math::float4x4 *v5; // eax
  vostok::math::float3 *v6; // eax
  vostok::math::float3 *v7; // eax
  vostok::math::float3 *v8; // esi
  vostok::math::float3 *v9; // eax
  float v10; // xmm0_4
  __int128 v11; // xmm1
  vostok::math::float3 *v12; // eax
  vostok::math::float3 *v13; // eax
  vostok::math::float3_pod *v14; // ecx
  long double v15; // st6
  long double v17; // [esp+20h] [ebp-100h]
  float v19; // [esp+34h] [ebp-ECh]
  vostok::math::float3 v20; // [esp+4Ch] [ebp-D4h] BYREF
  _BYTE v21[12]; // [esp+58h] [ebp-C8h] BYREF
  _BYTE v22[12]; // [esp+64h] [ebp-BCh] BYREF
  float v23[3]; // [esp+70h] [ebp-B0h] BYREF
  vostok::math::float3 v24; // [esp+7Ch] [ebp-A4h] BYREF
  _BYTE v25[12]; // [esp+88h] [ebp-98h] BYREF
  _BYTE v26[12]; // [esp+94h] [ebp-8Ch] BYREF
  vostok::math::float3 v27; // [esp+A0h] [ebp-80h] BYREF
  _BYTE v28[64]; // [esp+ACh] [ebp-74h] BYREF
  _BYTE v29[12]; // [esp+ECh] [ebp-34h] BYREF
  vostok::math::float3 v30; // [esp+F8h] [ebp-28h] BYREF
  float horizontal_fov_d2; // [esp+104h] [ebp-1Ch]
  const vostok::ai::npc *npc_object; // [esp+108h] [ebp-18h]
  float angles_ratio; // [esp+10Ch] [ebp-14h]
  float blind_zone_bound; // [esp+110h] [ebp-10h]
  float peripheral_view_angle; // [esp+114h] [ebp-Ch]
  const vostok::math::float3 *object_position; // [esp+118h] [ebp-8h]
  float side_plane; // [esp+11Ch] [ebp-4h]

  npc_object = ai_game_object->cast_npc(ai_game_object);
  vostok::math::float3::float3(&v27, COERCE_UNSIGNED_INT(0.0), COERCE_UNSIGNED_INT(0.0), 0.0);
  v3 = npc_object->get_position(npc_object, v26, v2);
  v4 = this->m_npc->get_eyes_position(this->m_npc, v29);
  v5 = ai_game_object->local_to_cell(ai_game_object, v28, v4);
  vostok::math::float4x4::transform_position(v3, &v30, v5);
  object_position = &v30;
  v6 = this->m_npc->get_eyes_position(this->m_npc, v25);
  v7 = vostok::math::operator-(v6, object_position, &v24);
  v8 = vostok::math::normalize(v7, v23);
  v9 = this->m_npc->get_eyes_direction(this->m_npc, v22);
  v10 = vostok::math::operator|(v9, v8);
  peripheral_view_angle = vostok::math::acos(v10);
  v19 = vostok::math::tan(this->m_parameters.vertical_fov / 2.0) * (1.0 / this->m_parameters.aspect_ratio);
  __libm_sse2_atan(v17);
  horizontal_fov_d2 = v19;
  v11 = LODWORD(peripheral_view_angle);
  *(float *)&v11 = peripheral_view_angle / v19;
  angles_ratio = vostok::math::clamp_r<float>((__m128)*(unsigned int *)&FLOAT_0_0, v11, 1.0).m128_f32[0];
  side_plane = this->m_parameters.min_indirect_view_factor * this->m_parameters.far_plane_distance;
  blind_zone_bound = (float)((float)(side_plane - this->m_parameters.far_plane_distance) * angles_ratio)
                   + this->m_parameters.far_plane_distance;
  v12 = this->m_npc->get_eyes_position(this->m_npc, v21);
  v13 = vostok::math::operator-(v12, object_position, &v20);
  v15 = vostok::math::float3_pod::length(v14, &v13->x);
  return v15 > blind_zone_bound;
}
