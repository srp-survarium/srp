void __userpurge vostok::render::debug::renderer::draw_frustum(
        const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *scene@<edi>,
        const vostok::math::color *color@<esi>,
        vostok::render::debug::renderer *this,
        float fov_in_radians,
        float near_plane_distance,
        float far_plane_distance,
        const vostok::math::float3 *aspect_ratio,
        const vostok::math::float3 *position,
        const vostok::math::float3 *direction,
        vostok::math::float3 up_vector,
        bool use_depth)
{
  long double v11; // st7
  long double v12; // st7
  unsigned int v13; // eax
  float y; // xmm2_4
  float x; // xmm4_4
  float v16; // xmm0_4
  float v17; // xmm3_4
  float v18; // xmm0_4
  float v19; // xmm4_4
  float v20; // xmm1_4
  float v21; // xmm7_4
  float v22; // xmm5_4
  float v23; // xmm4_4
  float v24; // xmm5_4
  float v25; // xmm4_4
  float v26; // xmm1_4
  float v27; // xmm2_4
  float v28; // xmm0_4
  bool do_debug_break; // [esp+Bh] [ebp-D1h] BYREF
  float v30; // [esp+Ch] [ebp-D0h]
  float v31; // [esp+10h] [ebp-CCh]
  float v32; // [esp+14h] [ebp-C8h]
  float v33; // [esp+18h] [ebp-C4h]
  float v34; // [esp+1Ch] [ebp-C0h]
  float v35; // [esp+20h] [ebp-BCh]
  float v36; // [esp+24h] [ebp-B8h]
  float v37; // [esp+28h] [ebp-B4h]
  float v38; // [esp+2Ch] [ebp-B0h]
  float v39; // [esp+30h] [ebp-ACh]
  float v40; // [esp+34h] [ebp-A8h]
  float window_top_coord; // [esp+38h] [ebp-A4h]
  float v42; // [esp+3Ch] [ebp-A0h]
  float v43; // [esp+40h] [ebp-9Ch]
  float window_bottom_coord; // [esp+44h] [ebp-98h]
  float v45; // [esp+48h] [ebp-94h]
  float v46; // [esp+4Ch] [ebp-90h]
  float window_left_coord; // [esp+50h] [ebp-8Ch]
  float z; // [esp+54h] [ebp-88h]
  float window_right_coord; // [esp+58h] [ebp-84h]
  vostok::math::float3 far_plane_points[4]; // [esp+5Ch] [ebp-80h] BYREF
  float v51; // [esp+8Ch] [ebp-50h]
  float v52; // [esp+90h] [ebp-4Ch]
  float v53; // [esp+94h] [ebp-48h]
  vostok::math::float3 projectors[4]; // [esp+98h] [ebp-44h]
  float v55; // [esp+C8h] [ebp-14h]
  float v56; // [esp+CCh] [ebp-10h]
  float v57; // [esp+D0h] [ebp-Ch]
  float v58; // [esp+D4h] [ebp-8h]

  v11 = tanf((float)(fov_in_radians * far_plane_distance) * 0.5);
  window_right_coord = v11;
  window_left_coord = -v11;
  v12 = tanf(fov_in_radians * 0.5);
  window_top_coord = v12;
  window_bottom_coord = -v12;
  if ( debug_macro_helper_ignore_always_1
    || (v34 = sqrtf(
                (float)((float)(position->y * position->y) + (float)(position->z * position->z))
              + (float)(position->x * position->x))
            - *(float *)&clear_value,
        LODWORD(v34) &= ~0x80000000,
        v34 < 0.0000099999997) )
  {
    y = position->y;
    x = position->x;
    v16 = (float)(position->z * up_vector.x) - (float)(y * up_vector.y);
    z = position->z;
    v43 = y;
    v45 = x;
    v38 = (float)(y * *(float *)&direction) - (float)(x * up_vector.x);
    v34 = sqrtf(
            (float)((float)(v16 * v16) + (float)(v38 * v38))
          + (float)((float)((float)(x * up_vector.y) - (float)(z * *(float *)&direction))
                  * (float)((float)(x * up_vector.y) - (float)(z * *(float *)&direction))));
    v17 = (float)(*(float *)&clear_value / v34) * v16;
    v18 = (float)(*(float *)&clear_value / v34) * v38;
    v19 = (float)(*(float *)&clear_value / v34) * (float)((float)(x * up_vector.y) - (float)(z * *(float *)&direction));
    v53 = v18;
    v51 = v17;
    v36 = (float)(y * v18) - (float)(z * v19);
    v38 = (float)(v45 * v19) - (float)(v17 * y);
    v52 = v19;
    v37 = (float)(v17 * z) - (float)(v45 * v18);
    v34 = sqrtf((float)((float)(v36 * v36) + (float)(v38 * v38)) + (float)(v37 * v37));
    v20 = (float)(*(float *)&clear_value / v34) * v36;
    v56 = v20 * window_top_coord;
    v31 = v20 * window_top_coord;
    v55 = (float)((float)(*(float *)&clear_value / v34) * v37) * window_top_coord;
    v32 = v55;
    v21 = window_right_coord;
    v30 = (float)((float)(*(float *)&clear_value / v34) * v38) * window_top_coord;
    v33 = v30;
    window_right_coord = v17 * window_right_coord;
    v57 = window_right_coord;
    v42 = v19 * v21;
    v58 = v19 * v21;
    v46 = v18 * v21;
    v22 = aspect_ratio->z;
    v23 = aspect_ratio->y;
    v40 = aspect_ratio->x;
    v35 = v22;
    v24 = v22 + z;
    v39 = v23;
    v25 = v23 + y;
    window_top_coord = (float)((float)(*(float *)&clear_value / v34) * v37) * window_bottom_coord;
    v34 = (float)((float)(*(float *)&clear_value / v34) * v38) * window_bottom_coord;
    window_bottom_coord = v20 * window_bottom_coord;
    far_plane_points[1].x = (float)(window_right_coord + (float)(v40 + v45)) + window_bottom_coord;
    far_plane_points[1].y = (float)((float)(v52 * v21) + v25) + window_top_coord;
    far_plane_points[1].z = (float)((float)(v18 * v21) + v24) + v34;
    v26 = v52 * window_left_coord;
    v27 = v18 * window_left_coord;
    window_left_coord = v17 * window_left_coord;
    far_plane_points[2].x = (float)(window_left_coord + (float)(v40 + v45)) + v56;
    far_plane_points[2].y = (float)(v26 + v25) + v55;
    far_plane_points[2].z = (float)(v27 + v24) + v30;
    far_plane_points[3].x = (float)(window_left_coord + (float)(v40 + v45)) + window_bottom_coord;
    far_plane_points[3].y = (float)(v26 + v25) + window_top_coord;
    far_plane_points[3].z = (float)(v27 + v24) + v34;
    v32 = (float)((float)((float)(v52 * v21) + v25) + v55) - v39;
    v31 = (float)((float)(window_right_coord + (float)(v40 + v45)) + v31) - v40;
    v33 = (float)((float)((float)(v18 * v21) + v24) + v30) - v35;
    v30 = sqrtf((float)((float)(v33 * v33) + (float)(v32 * v32)) + (float)(v31 * v31));
    projectors[0].x = v31 * (float)(*(float *)&clear_value / v30);
    projectors[0].y = (float)(*(float *)&clear_value / v30) * v32;
    projectors[0].z = (float)(*(float *)&clear_value / v30) * v33;
    v30 = sqrtf(
            (float)((float)((float)(far_plane_points[1].z - v35) * (float)(far_plane_points[1].z - v35))
                  + (float)((float)(far_plane_points[1].y - v39) * (float)(far_plane_points[1].y - v39)))
          + (float)((float)(far_plane_points[1].x - v40) * (float)(far_plane_points[1].x - v40)));
    projectors[1].x = (float)(far_plane_points[1].x - v40) * (float)(*(float *)&clear_value / v30);
    projectors[1].y = (float)(*(float *)&clear_value / v30) * (float)(far_plane_points[1].y - v39);
    projectors[1].z = (float)(*(float *)&clear_value / v30) * (float)(far_plane_points[1].z - v35);
    v30 = sqrtf(
            (float)((float)((float)(far_plane_points[2].z - v35) * (float)(far_plane_points[2].z - v35))
                  + (float)((float)(far_plane_points[2].y - v39) * (float)(far_plane_points[2].y - v39)))
          + (float)((float)(far_plane_points[2].x - v40) * (float)(far_plane_points[2].x - v40)));
    projectors[2].x = (float)(far_plane_points[2].x - v40) * (float)(*(float *)&clear_value / v30);
    projectors[2].z = (float)(*(float *)&clear_value / v30) * (float)(far_plane_points[2].z - v35);
    projectors[2].y = (float)(*(float *)&clear_value / v30) * (float)(far_plane_points[2].y - v39);
    v30 = sqrtf(
            (float)((float)((float)(far_plane_points[3].x - v40) * (float)(far_plane_points[3].x - v40))
                  + (float)((float)(far_plane_points[3].z - v35) * (float)(far_plane_points[3].z - v35)))
          + (float)((float)(far_plane_points[3].y - v39) * (float)(far_plane_points[3].y - v39)));
    projectors[3].x = (float)(far_plane_points[3].x - v40) * (float)(*(float *)&clear_value / v30);
    projectors[3].z = (float)(*(float *)&clear_value / v30) * (float)(far_plane_points[3].z - v35);
    projectors[3].y = (float)(*(float *)&clear_value / v30) * (float)(far_plane_points[3].y - v39);
    v30 = sqrtf(
            (float)((float)(projectors[0].z * projectors[0].z) + (float)(projectors[0].y * projectors[0].y))
          + (float)(projectors[0].x * projectors[0].x));
    v28 = near_plane_distance
        / (float)((float)((float)(v43 * (float)((float)(*(float *)&clear_value / v30) * projectors[0].y))
                        + (float)(z * (float)((float)(*(float *)&clear_value / v30) * projectors[0].z)))
                + (float)((float)(projectors[0].x * (float)(*(float *)&clear_value / v30)) * v45));
    far_plane_points[0].x = (float)(projectors[0].x * v28) + v40;
    far_plane_points[0].y = v39 + (float)(v28 * projectors[0].y);
    far_plane_points[1].x = (float)(projectors[1].x * v28) + v40;
    far_plane_points[0].z = v35 + (float)(v28 * projectors[0].z);
    far_plane_points[1].y = v39 + (float)(v28 * projectors[1].y);
    far_plane_points[1].z = v35 + (float)(v28 * projectors[1].z);
    far_plane_points[2].x = (float)(projectors[2].x * v28) + v40;
    far_plane_points[2].y = v39 + (float)(v28 * projectors[2].y);
    far_plane_points[2].z = v35 + (float)(v28 * projectors[2].z);
    far_plane_points[3].x = (float)(projectors[3].x * v28) + v40;
    far_plane_points[3].y = v39 + (float)(v28 * projectors[3].y);
    far_plane_points[3].z = v35 + (float)(v28 * projectors[3].z);
    vostok::render::debug::renderer::draw_line(aspect_ratio, far_plane_points, this, scene, color, 1);
    vostok::render::debug::renderer::draw_line(aspect_ratio, &far_plane_points[1], this, scene, color, 1);
    vostok::render::debug::renderer::draw_line(aspect_ratio, &far_plane_points[2], this, scene, color, 1);
    vostok::render::debug::renderer::draw_line(aspect_ratio, &far_plane_points[3], this, scene, color, 1);
    vostok::render::debug::renderer::draw_line(far_plane_points, &far_plane_points[1], this, scene, color, 1);
    vostok::render::debug::renderer::draw_line(&far_plane_points[1], &far_plane_points[3], this, scene, color, 1);
    vostok::render::debug::renderer::draw_line(&far_plane_points[3], &far_plane_points[2], this, scene, color, 1);
    vostok::render::debug::renderer::draw_line(&far_plane_points[2], far_plane_points, this, scene, color, 1);
  }
  else
  {
    v13 = occurances_left_1;
    if ( occurances_left_1 == -1 )
      v13 = 10;
    occurances_left_1 = v13 - 1;
    if ( v13 )
    {
      do_debug_break = 0;
      vostok::debug::on_error(
        (unsigned int)this,
        &do_debug_break,
        process_error_false,
        &debug_macro_helper_ignore_always_1,
        assert_untyped,
        "assertion_failed",
        "math::is_similar( direction.length(), 1.f, math::epsilon_5 )",
        ".\\debug_renderer.cpp",
        "vostok::render::debug::renderer::draw_frustum",
        0x9Fu,
        "given direction vector isn't normalized");
      if ( vostok::debug::is_debugger_present() || do_debug_break )
        __debugbreak();
    }
  }
}
