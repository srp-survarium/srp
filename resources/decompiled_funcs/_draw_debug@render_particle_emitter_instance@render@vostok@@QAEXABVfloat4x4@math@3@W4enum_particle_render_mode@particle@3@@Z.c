void __userpurge vostok::render::render_particle_emitter_instance::draw_debug(
        vostok::render::render_particle_emitter_instance *this@<ecx>,
        int a2@<eax>,
        const vostok::math::float4x4 *view_matrix,
        vostok::particle::enum_particle_render_mode debug_mode)
{
  float v5; // xmm0_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm4_4
  float v9; // xmm6_4
  float v10; // xmm7_4
  int v11; // esi
  float v12; // xmm3_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm4_4
  vostok::particle::base_particle *v18; // esi
  bool v19; // [esp+4h] [ebp-104h]
  bool v20; // [esp+4h] [ebp-104h]
  bool v21; // [esp+8h] [ebp-100h]
  bool v22; // [esp+8h] [ebp-100h]
  float v23; // [esp+18h] [ebp-F0h]
  float v24; // [esp+20h] [ebp-E8h]
  float v25; // [esp+20h] [ebp-E8h]
  int width; // [esp+24h] [ebp-E4h] BYREF
  float v27; // [esp+28h] [ebp-E0h]
  float v28; // [esp+2Ch] [ebp-DCh]
  int v29; // [esp+30h] [ebp-D8h]
  int v30; // [esp+34h] [ebp-D4h]
  vostok::particle::base_particle *P; // [esp+38h] [ebp-D0h]
  int v32; // [esp+3Ch] [ebp-CCh]
  int v33; // [esp+40h] [ebp-C8h]
  int v34; // [esp+44h] [ebp-C4h]
  int v35; // [esp+48h] [ebp-C0h]
  int v36; // [esp+4Ch] [ebp-BCh]
  int v37; // [esp+50h] [ebp-B8h]
  float v38; // [esp+54h] [ebp-B4h]
  float v39; // [esp+58h] [ebp-B0h]
  float v40; // [esp+5Ch] [ebp-ACh]
  float v41; // [esp+60h] [ebp-A8h]
  float v42; // [esp+64h] [ebp-A4h]
  float v43; // [esp+68h] [ebp-A0h]
  __int64 v44; // [esp+6Ch] [ebp-9Ch]
  float v45; // [esp+74h] [ebp-94h]
  vostok::math::float3 v46; // [esp+78h] [ebp-90h]
  vostok::math::float3 v47; // [esp+84h] [ebp-84h]
  vostok::math::float3 v48; // [esp+90h] [ebp-78h]
  vostok::math::float3 points[2]; // [esp+9Ch] [ebp-6Ch] BYREF
  vostok::math::float4x4 camera_to_world; // [esp+B4h] [ebp-54h] BYREF
  float v51; // [esp+100h] [ebp-8h]

  vostok::math::float4x4::try_invert(&camera_to_world, view_matrix);
  v5 = (float)((float)(camera_to_world.j.x * 1000.0) + (float)(camera_to_world.i.x * 0.0))
     + (float)(camera_to_world.k.x * 0.0);
  v28 = camera_to_world.k.x * 0.0;
  v6 = (float)((float)(camera_to_world.i.y * 0.0) + (float)(camera_to_world.j.y * 1000.0))
     + (float)(camera_to_world.k.y * 0.0);
  v23 = camera_to_world.k.y * 0.0;
  v7 = (float)((float)(camera_to_world.j.z * 1000.0) + (float)(camera_to_world.i.z * 0.0))
     + (float)(camera_to_world.k.z * 0.0);
  v27 = camera_to_world.k.z * 0.0;
  v24 = 1.0 / sqrtf((float)((float)(v6 * v6) + (float)(v5 * v5)) + (float)(v7 * v7));
  v41 = v24 * v5;
  v42 = v6 * v24;
  v43 = v7 * v24;
  v38 = (float)((float)(camera_to_world.j.x * 0.0) + (float)(camera_to_world.i.x * 1000.0)) + v28;
  v39 = (float)((float)(camera_to_world.i.y * 1000.0) + (float)(camera_to_world.j.y * 0.0)) + v23;
  v40 = (float)((float)(camera_to_world.j.z * 0.0) + (float)(camera_to_world.i.z * 1000.0)) + v27;
  v25 = 1.0 / sqrtf((float)((float)(v38 * v38) + (float)(v40 * v40)) + (float)(v39 * v39));
  v8 = v25 * v38;
  v9 = v39 * v25;
  v10 = v40 * v25;
  v38 = v25 * v38;
  v39 = v39 * v25;
  v40 = v40 * v25;
  if ( debug_mode == dots_particle_render_mode )
  {
    for ( P = *(vostok::particle::base_particle **)(*(_DWORD *)(a2 + 1100) + 36); P; P = v18->next )
    {
      v35 = -72;
      v34 = 62;
      v28 = 0.0;
      v29 = 0;
      v27 = NAN;
      v33 = 255;
      width = -16711681;
      v18 = P;
      vostok::render::system_renderer::draw_3D_point(
        (vostok::render::system_renderer *)&P->position,
        (const vostok::math::float3 *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_mouse_pos.x,
        COERCE_FLOAT((vostok::particle::base_particle *)&P->position),
        (const vostok::math::color *)&width,
        v19);
    }
  }
  else if ( debug_mode == size_particle_render_mode )
  {
    v11 = *(_DWORD *)(*(_DWORD *)(a2 + 1100) + 36);
    if ( v11 )
    {
      while ( 1 )
      {
        v12 = *(float *)(v11 + 104);
        v51 = (float)(v12 * v10) * 0.5;
        *(float *)&v44 = *(float *)(v11 + 44) - (float)((float)(v12 * v8) * 0.5);
        *((float *)&v44 + 1) = *(float *)(v11 + 48) - (float)((float)(v12 * v9) * 0.5);
        v45 = *(float *)(v11 + 52) - v51;
        *(_QWORD *)&points[0].x = v44;
        v13 = *(float *)(v11 + 104);
        points[0].z = v45;
        v27 = 255.0;
        v47.y = *(float *)(v11 + 48) + (float)((float)(v13 * v9) * 0.5);
        v14 = (float)((float)(v13 * v8) * 0.5) + *(float *)(v11 + 44);
        v47.z = *(float *)(v11 + 52) + (float)((float)(v13 * v10) * 0.5);
        v47.x = v14;
        v35 = 255;
        points[1] = v47;
        v34 = -72;
        v27 = 0.0;
        v33 = 62;
        P = 0;
        v30 = -72;
        v37 = 255;
        v36 = 0;
        v32 = 0;
        width = -16711681;
        vostok::render::system_renderer::draw_screen_lines(
          (vostok::render::system_renderer *)points,
          (const vostok::math::float3 *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_mouse_pos.x,
          (unsigned int)points,
          (const vostok::math::color *)2,
          COERCE_FLOAT(&width),
          0,
          v19,
          v21);
        v15 = *(float *)(v11 + 108);
        v16 = *(float *)(v11 + 48);
        v48.x = *(float *)(v11 + 44) - (float)((float)(v41 * v15) * 0.5);
        v17 = *(float *)(v11 + 108);
        v48.y = v16 - (float)((float)(v42 * v15) * 0.5);
        v48.z = *(float *)(v11 + 52) - (float)((float)(v43 * v15) * 0.5);
        points[0] = v48;
        v46.x = *(float *)(v11 + 44) + (float)((float)(v41 * v17) * 0.5);
        v46.y = *(float *)(v11 + 48) + (float)((float)(v42 * v17) * 0.5);
        v46.z = *(float *)(v11 + 52) + (float)((float)(v43 * v17) * 0.5);
        points[1] = v46;
        v33 = -72;
        v35 = 255;
        v34 = 62;
        v28 = 0.0;
        v29 = 0;
        v30 = -72;
        v37 = 255;
        width = -16711681;
        vostok::render::system_renderer::draw_screen_lines(
          (vostok::render::system_renderer *)points,
          (const vostok::math::float3 *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_mouse_pos.x,
          (unsigned int)points,
          (const vostok::math::color *)2,
          COERCE_FLOAT(&width),
          0,
          v20,
          v22);
        v11 = *(_DWORD *)(v11 + 128);
        if ( !v11 )
          break;
        v10 = v40;
        v8 = v38;
        v9 = v39;
      }
    }
  }
}
