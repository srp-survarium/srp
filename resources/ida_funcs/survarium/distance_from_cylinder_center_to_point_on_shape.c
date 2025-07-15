long double __cdecl survarium::distance_from_cylinder_center_to_point_on_shape(
        const vostok::math::float4x4 *transform,
        float radius,
        float half_length,
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
  vostok::math::float3_pod *v19; // ecx
  vostok::math::float3 *p_bottom_surface_center; // [esp+0h] [ebp-108h]
  float v21; // [esp+4h] [ebp-104h]
  vostok::math::float3 v22; // [esp+Ch] [ebp-FCh] BYREF
  vostok::math::float3 v23; // [esp+18h] [ebp-F0h] BYREF
  float value[2]; // [esp+24h] [ebp-E4h] BYREF
  vostok::math::float3 v25; // [esp+2Ch] [ebp-DCh] BYREF
  vostok::math::float3 v26; // [esp+38h] [ebp-D0h] BYREF
  vostok::math::float3 v27; // [esp+44h] [ebp-C4h] BYREF
  vostok::math::float3 v28; // [esp+50h] [ebp-B8h] BYREF
  vostok::math::float3 v29; // [esp+5Ch] [ebp-ACh] BYREF
  vostok::math::float3 v30; // [esp+68h] [ebp-A0h] BYREF
  vostok::math::float3 v31; // [esp+74h] [ebp-94h] BYREF
  vostok::math::float3 dir; // [esp+80h] [ebp-88h] BYREF
  vostok::math::float3 height_vector_proj_point; // [esp+8Ch] [ebp-7Ch] BYREF
  float proj_to_y_axis; // [esp+98h] [ebp-70h] BYREF
  vostok::math::float3 circle_point_dir; // [esp+9Ch] [ebp-6Ch] BYREF
  vostok::math::float3 bottom_surface_center; // [esp+A8h] [ebp-60h] BYREF
  vostok::math::float3 circle_proj_vec; // [esp+B4h] [ebp-54h] BYREF
  vostok::math::float3 proj; // [esp+C0h] [ebp-48h] BYREF
  vostok::math::float3 y_axis; // [esp+CCh] [ebp-3Ch] BYREF
  vostok::math::float3 surface_center; // [esp+D8h] [ebp-30h] BYREF
  vostok::math::float3 top_surface_center; // [esp+E4h] [ebp-24h] BYREF
  vostok::math::float3 height_vector; // [esp+F0h] [ebp-18h] BYREF
  vostok::math::float3 center; // [esp+FCh] [ebp-Ch] BYREF

  survarium::weapon_user_dead_state::finalize(v4);
  center = *v5;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)LODWORD(center.x));
  y_axis = *v6;
  v7 = vostok::math::operator*(&y_axis, &v31, &half_length);
  vostok::math::operator+(v7, &center, &top_surface_center);
  v8 = vostok::math::operator*(&y_axis, &v30, &half_length);
  vostok::math::operator-(v8, &center, &bottom_surface_center);
  vostok::math::operator-(&top_surface_center, &bottom_surface_center, &height_vector);
  v9 = vostok::math::operator-(&top_surface_center, source_position, &v29);
  v21 = vostok::math::float3_pod::dot_product(v9, &height_vector);
  proj_to_y_axis = v21 / vostok::math::float3_pod::dot_product(&height_vector, &height_vector);
  if ( proj_to_y_axis <= 0.0 || *(float *)&clear_value <= proj_to_y_axis )
  {
    if ( proj_to_y_axis >= 0.0 )
      p_bottom_surface_center = &bottom_surface_center;
    else
      p_bottom_surface_center = &top_surface_center;
    LODWORD(value[1]) = p_bottom_surface_center;
    surface_center = *p_bottom_surface_center;
    vostok::math::operator-(&surface_center, source_position, &circle_point_dir);
    value[0] = vostok::math::float3_pod::dot_product(&circle_point_dir, &y_axis);
    vostok::math::operator*(&y_axis, &proj, value);
    vostok::math::operator-(&proj, &circle_point_dir, &circle_proj_vec);
    v17 = vostok::math::operator+(&circle_proj_vec, &surface_center, &v23);
    v18 = vostok::math::operator-(&center, v17, &v22);
    return vostok::math::float3_pod::length(v19, &v18->x);
  }
  else
  {
    v10 = vostok::math::operator*(&height_vector, &v28, &proj_to_y_axis);
    vostok::math::operator+(v10, &top_surface_center, &height_vector_proj_point);
    vostok::math::operator-(&height_vector_proj_point, source_position, &dir);
    v11 = vostok::math::float3_pod::normalize(&dir);
    v12 = vostok::math::operator*(v11, &v27, &radius);
    v13 = vostok::math::operator+(v12, &height_vector_proj_point, &v26);
    v14 = vostok::math::operator-(&center, v13, &v25);
    return vostok::math::float3_pod::length(v15, &v14->x);
  }
}
