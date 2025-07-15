void __thiscall vostok::render::system_renderer::draw_aabb(
        vostok::render::system_renderer *this,
        vostok::render::system_renderer *aabb,
        const vostok::math::color *color,
        int *a4)
{
  int v4; // eax
  float y; // xmm0_4
  float v6; // xmm1_4
  unsigned int m_value; // xmm3_4
  float v8; // xmm4_4
  unsigned int v9; // xmm2_4
  _DWORD v10[32]; // [esp+10h] [ebp-94h] BYREF
  vostok::render::vertex_colored v11; // [esp+90h] [ebp-14h] BYREF

  if ( vostok::render::system_renderer::is_effects_ready(this, aabb) )
  {
    v4 = *a4;
    v6 = *(float *)&color[1].m_value;
    m_value = color[5].m_value;
    LODWORD(v11.position.elements[1]) = (vostok::math::color)color->m_value;
    y = v11.position.y;
    v8 = *(float *)&color[4].m_value;
    v9 = color[2].m_value;
    v11.position.z = v6;
    v11.color.m_value = m_value;
    v10[0] = color->m_value;
    v10[1] = color[1].m_value;
    v10[2] = color[2].m_value;
    v10[3] = v4;
    v10[4] = LODWORD(v11.position.y);
    *(float *)&v10[5] = v6;
    v10[6] = m_value;
    v10[7] = v4;
    v10[8] = LODWORD(v11.position.y);
    *(float *)&v10[9] = v8;
    v10[10] = v9;
    v10[11] = v4;
    v11.position.z = v6;
    v11.color.m_value = v9;
    LODWORD(v11.position.elements[1]) = (vostok::math::color)color[3].m_value;
    v10[12] = LODWORD(v11.position.y);
    *(float *)&v10[13] = v6;
    v10[14] = v9;
    v10[15] = v4;
    *(float *)&v10[16] = y;
    *(float *)&v10[17] = v8;
    v10[18] = m_value;
    v10[19] = v4;
    v10[20] = LODWORD(v11.position.y);
    *(float *)&v10[21] = v6;
    v10[22] = m_value;
    v10[23] = v4;
    v11.color.m_value = v9;
    v11.position.z = v8;
    v10[24] = LODWORD(v11.position.y);
    *(float *)&v10[25] = v8;
    v10[26] = v9;
    v10[27] = v4;
    v10[28] = color[3].m_value;
    v10[29] = color[4].m_value;
    v10[30] = color[5].m_value;
    v10[31] = v4;
    vostok::render::system_renderer::draw_lines(
      &v11,
      (vostok::render::system_renderer *)&color[3],
      aabb,
      (unsigned int)v10,
      (unsigned __int8 *)vostok::render::aabb_indices,
      (char *)&bad_alloc_Message_180,
      0);
  }
}
