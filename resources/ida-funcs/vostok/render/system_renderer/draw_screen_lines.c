void __userpurge vostok::render::system_renderer::draw_screen_lines(
        vostok::render::system_renderer *this@<ecx>,
        unsigned int points,
        _DWORD *count,
        const vostok::math::color *color,
        float width,
        unsigned int pattern,
        bool use_depth,
        bool is_screen_space_coord)
{
  float v8; // ebx
  int z_low; // esi
  vostok::render::backend *v10; // ecx
  pix_event_wrapper_dx11 *v11; // ecx
  char *v12; // eax
  const vostok::math::float3 *v13; // ecx
  float v14; // xmm0_4
  _DWORD *v15; // eax
  const vostok::math::color *v16; // ecx
  _DWORD *v17; // esi
  _DWORD *v18; // edi
  char *v19; // eax
  vostok::render::untyped_buffer *v20; // ecx
  int v21; // edx
  vostok::render::res_geometry *v22; // ecx
  int v23; // eax
  vostok::render::res_effect *v24; // ecx
  vostok::math::float4x4 *v25; // eax
  float z; // esi
  vostok::render::backend *v27; // ecx
  float y; // [esp-8h] [ebp-CCh]
  double v29; // [esp-4h] [ebp-C8h]
  unsigned int v30; // [esp-4h] [ebp-C8h]
  vostok::math::float4x4 v31; // [esp+10h] [ebp-B4h] BYREF
  vostok::math::float4x4 v32; // [esp+50h] [ebp-74h] BYREF
  vostok::math::float3 v33; // [esp+94h] [ebp-30h] BYREF
  vostok::math::float2 v34; // [esp+A0h] [ebp-24h] BYREF
  _DWORD *p_x; // [esp+A8h] [ebp-1Ch]
  char *v36; // [esp+ACh] [ebp-18h]
  unsigned int v_offset; // [esp+B0h] [ebp-14h] BYREF
  unsigned int i_offset; // [esp+B4h] [ebp-10h] BYREF
  vostok::math::float2 v39; // [esp+B8h] [ebp-Ch] BYREF

  v8 = *(float *)&points;
  if ( vostok::render::system_renderer::is_effects_ready(this, (_DWORD *)points) )
  {
    qmemcpy(
      &v32,
      vostok::math::mul4x4(
        (const vostok::math::float4x4 *)(*(_DWORD *)(LODWORD(v8) + 88) + 19828),
        (const vostok::math::float4x4 *)(*(_DWORD *)(LODWORD(v8) + 88) + 19508),
        &v31),
      sizeof(v32));
    z_low = LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z);
    LODWORD(v39.y) = vostok::render::backend::target_width(
                       0,
                       SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z));
    *(float *)&points = COERCE_FLOAT(vostok::render::backend::target_height(v10, z_low));
    pix_event_wrapper_dx11::pix_event_wrapper_dx11(
      v11,
      (pix_event_wrapper_dx11 *)&points + 3,
      (int)L"draw_screen_lines");
    color = (const vostok::math::color *)color->m_value;
    v36 = vostok::render::index_buffer::lock((vostok::render::index_buffer *)(LODWORD(v8) + 140), &i_offset, 2u);
    v12 = vostok::render::vertex_buffer::lock(
            (vostok::render::vertex_buffer *)(LODWORD(v8) + 116),
            &v_offset,
            2u,
            0x24u);
    v13 = (const vostok::math::float3 *)count;
    v33 = *(vostok::math::float3 *)((_BYTE *)count + 1);
    v30 = points;
    *(_DWORD *)v12 = *count;
    *((_DWORD *)v12 + 1) = LODWORD(v13->y);
    y = v39.y;
    *((_DWORD *)v12 + 2) = LODWORD(v13->z);
    *((_DWORD *)v12 + 3) = color;
    *((_DWORD *)v12 + 4) = LODWORD(v13->x);
    *((_DWORD *)v12 + 5) = LODWORD(v13->y);
    *((_DWORD *)v12 + 6) = LODWORD(v13->z);
    *((_DWORD *)v12 + 16) = 0;
    *((_DWORD *)v12 + 7) = 0;
    *((_DWORD *)v12 + 17) = -1;
    *((_DWORD *)v12 + 8) = -1;
    p_x = (_DWORD *)&v13->x;
    count = v12 + 36;
    vostok::render::clip_2_screen(v13, &v32, &v34, LODWORD(y), v30);
    vostok::render::clip_2_screen(&v33, &v32, &v39, LODWORD(v39.y), points);
    LODWORD(v14) = COERCE_UNSIGNED_INT(v39.x - v34.x) & _mask__AbsFloat_;
    if ( v14 <= COERCE_FLOAT(COERCE_UNSIGNED_INT(v39.y - v34.y) & _mask__AbsFloat_) )
      LODWORD(v14) = COERCE_UNSIGNED_INT(v39.y - v34.y) & _mask__AbsFloat_;
    LODWORD(v29) = &points;
    *(float *)&points = v14 * 0.125;
    modf(v14 * 0.125, v29);
    v15 = count;
    v16 = color;
    *(vostok::math::float3 *)count = v33;
    v17 = p_x;
    v15[3] = v16;
    v18 = v15 + 4;
    v19 = v36;
    *v18 = *v17++;
    *++v18 = *v17;
    v18[1] = v17[1];
    *(_WORD *)v19 = 0;
    *((_WORD *)v19 + 1) = 1;
    vostok::render::vertex_buffer::unlock((vostok::render::vertex_buffer *)1, (int *)(LODWORD(v8) + 116));
    v20 = *(vostok::render::untyped_buffer **)(LODWORD(v8) + 156);
    v21 = *(_DWORD *)(LODWORD(v8) + 140);
    *(_DWORD *)(LODWORD(v8) + 148) += v20;
    vostok::render::untyped_buffer::unmap(v20, v21);
    vostok::render::res_geometry::apply(v22, *(_DWORD *)(LODWORD(v8) + 104));
    v23 = *(_DWORD *)(LODWORD(v8) + 92);
    *(_DWORD *)(v23 + 22048) = 1;
    vostok::render::res_effect::apply_pass(v24, v23);
    v25 = vostok::math::transpose(&v32, &v31);
    z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
    vostok::render::backend::set_vs_constant<vostok::math::float4x4>(
      (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      *(const vostok::render::shader_constant_host **)(LODWORD(v8) + 108),
      (const unsigned int *)v25);
    vostok::render::backend::render_indexed(
      (vostok::render::backend *)LODWORD(z),
      2u,
      v27,
      D3D_PRIMITIVE_TOPOLOGY_LINELIST,
      i_offset,
      v_offset);
    D3DPERF_EndEvent();
  }
}
