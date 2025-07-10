long double __cdecl survarium::distance_from_capsule_center_to_point_on_shape(
        const vostok::math::float4x4 *transform,
        float half_length,
        float radius,
        const vostok::math::float3 *source_position)
{
  survarium::game_camera *v4; // ecx
  vostok::math::float3 *v5; // eax
  vostok::math::float3 *v6; // eax
  vostok::math::float3 *v7; // eax
  vostok::math::float3 *v8; // eax
  vostok::math::float3 *v9; // eax
  vostok::math::float3 *v10; // eax
  vostok::math::float3 *v11; // eax
  vostok::math::float3 *v12; // eax
  vostok::math::float3 *v13; // eax
  vostok::math::float3 *v14; // eax
  vostok::math::float3_pod *v15; // ecx
  vostok::math::float3 *v17; // eax
  vostok::math::float3 *v18; // eax
  vostok::math::float3 *v19; // eax
  vostok::math::float3 *v20; // eax
  vostok::math::float3 *v21; // eax
  vostok::math::float3_pod *v22; // ecx
  vostok::math::float3 *p_bottom_surface_center; // [esp+0h] [ebp-F4h]
  float v24; // [esp+4h] [ebp-F0h]
  vostok::math::float3 v25; // [esp+8h] [ebp-ECh] BYREF
  vostok::math::float3 v26; // [esp+14h] [ebp-E0h] BYREF
  vostok::math::float3 v27; // [esp+20h] [ebp-D4h] BYREF
  vostok::math::float3 v28; // [esp+2Ch] [ebp-C8h] BYREF
  vostok::math::float3 *v29; // [esp+38h] [ebp-BCh]
  vostok::math::float3 v30; // [esp+3Ch] [ebp-B8h] BYREF
  vostok::math::float3 v31; // [esp+48h] [ebp-ACh] BYREF
  vostok::math::float3 v32; // [esp+54h] [ebp-A0h] BYREF
  vostok::math::float3 v33; // [esp+60h] [ebp-94h] BYREF
  vostok::math::float3 v34; // [esp+6Ch] [ebp-88h] BYREF
  vostok::math::float3 v35; // [esp+78h] [ebp-7Ch] BYREF
  vostok::math::float3 v36; // [esp+84h] [ebp-70h] BYREF
  vostok::math::float3 dir; // [esp+90h] [ebp-64h] BYREF
  vostok::math::float3 height_vector_proj_point; // [esp+9Ch] [ebp-58h] BYREF
  float proj_to_y_axis; // [esp+A8h] [ebp-4Ch] BYREF
  vostok::math::float3 bottom_surface_center; // [esp+ACh] [ebp-48h] BYREF
  vostok::math::float3 y_axis; // [esp+B8h] [ebp-3Ch] BYREF
  vostok::math::float3 surface_center; // [esp+C4h] [ebp-30h] BYREF
  vostok::math::float3 top_surface_center; // [esp+D0h] [ebp-24h] BYREF
  vostok::math::float3 height_vector; // [esp+DCh] [ebp-18h] BYREF
  vostok::math::float3 center; // [esp+E8h] [ebp-Ch] BYREF

  survarium::weapon_user_dead_state::finalize(v4);
  center = *v5;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)LODWORD(center.x));
  y_axis = *v6;
  v7 = vostok::math::operator*(&y_axis, &v36, &half_length);
  vostok::math::operator+(v7, &center, &top_surface_center);
  v8 = vostok::math::operator*(&y_axis, &v35, &half_length);
  vostok::math::operator-(v8, &center, &bottom_surface_center);
  vostok::math::operator-(&top_surface_center, &bottom_surface_center, &height_vector);
  v9 = vostok::math::operator-(&top_surface_center, source_position, &v34);
  v24 = vostok::math::float3_pod::dot_product(v9, &height_vector);
  proj_to_y_axis = v24 / vostok::math::float3_pod::dot_product(&height_vector, &height_vector);
  if ( proj_to_y_axis <= 0.0 || *(float *)&clear_value <= proj_to_y_axis )
  {
    if ( proj_to_y_axis >= 0.0 )
      p_bottom_surface_center = &bottom_surface_center;
    else
      p_bottom_surface_center = &top_surface_center;
    v29 = p_bottom_surface_center;
    surface_center = *p_bottom_surface_center;
    v17 = vostok::math::operator-(&surface_center, source_position, &v28);
    v18 = vostok::math::float3_pod::normalize(v17);
    v19 = vostok::math::operator*(v18, &v27, &radius);
    v20 = vostok::math::operator+(v19, &surface_center, &v26);
    v21 = vostok::math::operator-(&center, v20, &v25);
    return vostok::math::float3_pod::length(v22, &v21->x);
  }
  else
  {
    v10 = vostok::math::operator*(&height_vector, &v33, &proj_to_y_axis);
    vostok::math::operator+(v10, &top_surface_center, &height_vector_proj_point);
    vostok::math::operator-(&height_vector_proj_point, source_position, &dir);
    v11 = vostok::math::float3_pod::normalize(&dir);
    v12 = vostok::math::operator*(v11, &v32, &radius);
    v13 = vostok::math::operator+(v12, &height_vector_proj_point, &v31);
    v14 = vostok::math::operator-(&center, v13, &v30);
    return vostok::math::float3_pod::length(v15, &v14->x);
  }
}
