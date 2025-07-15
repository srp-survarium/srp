void __userpurge vostok::render::lights_db::tick(
        vostok::render::lights_db *this@<eax>,
        vostok::render::renderer_context *context@<edi>,
        float a3@<xmm10>,
        float time_delta)
{
  vostok::render::light_data *m_end; // ebx
  vostok::render::light_data *i; // esi
  float v6; // eax
  float v7; // xmm0_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm3_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm0_4

  m_end = this->m_lights.m_end;
  for ( i = this->m_lights.m_begin; i != m_end; ++i )
  {
    v6 = *(float *)&i->light.m_object;
    *(_DWORD *)(LODWORD(v6) + 620) = 0;
    v7 = context->m_view_pos.x - *(float *)(LODWORD(v6) + 532);
    v8 = context->m_view_pos.z - *(float *)(LODWORD(v6) + 540);
    v9 = context->m_view_pos.y - *(float *)(LODWORD(v6) + 536);
    v10 = (float)(v7 * v7) + (float)(v8 * v8);
    v11 = v9 * v9;
    v12 = *(float *)(LODWORD(v6) + 608);
    v13 = fsqrt(v10 + v11);
    if ( v13 > v12 && (float)(v13 - v12) > s_bm_current_air_resistance )
      *(_DWORD *)(LODWORD(v6) + 620) = 1;
    vostok::render::light::tick_color_animation((vostok::render::light *)(LODWORD(v6) + 532), a3, v6, time_delta);
  }
}
