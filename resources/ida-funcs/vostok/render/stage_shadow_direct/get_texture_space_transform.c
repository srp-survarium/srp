vostok::math::float4x4 *__usercall vostok::render::stage_shadow_direct::get_texture_space_transform@<eax>(
        vostok::render::stage_shadow_direct *this@<ecx>,
        vostok::math::float4x4 *a2@<eax>)
{
  float v2; // xmm2_4

  v2 = s_bm_current_air_resistance;
  *(_QWORD *)&a2->i.x = LODWORD(c_anim_center);
  *(_QWORD *)&a2->lines[0].elements[2] = 0;
  a2->j.x = 0.0;
  *(_QWORD *)&a2->lines[1].elements[1] = LODWORD(FLOAT_N0_5);
  *(_QWORD *)&a2->lines[1].elements[3] = 0;
  a2->k.y = 0.0;
  *(_QWORD *)&a2->lines[2].elements[2] = LODWORD(v2);
  a2->c.x = c_anim_center;
  a2->c.y = c_anim_center;
  a2->c.z = FLOAT_N0_0;
  a2->c.w = v2;
  return a2;
}
