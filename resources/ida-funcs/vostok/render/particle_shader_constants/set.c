void __thiscall vostok::render::particle_shader_constants::set(
        vostok::render::particle_shader_constants *this,
        const vostok::math::float3 up_vector,
        const vostok::math::float3 right_vector,
        const vostok::math::float3 view_location,
        vostok::particle::enum_particle_locked_axis locked_axis,
        vostok::particle::enum_particle_screen_alignment screen_alignment,
        int a7)
{
  float z; // ebx
  float x; // edi
  float v9; // esi
  vostok::particle::enum_particle_screen_alignment v10; // ecx
  bool v11; // al
  BOOL v12; // edx
  float v13; // xmm0_4
  unsigned int v14; // [esp+Ch] [ebp-24h]
  unsigned int v15; // [esp+18h] [ebp-18h] BYREF
  float v16; // [esp+1Ch] [ebp-14h]
  float v17; // [esp+20h] [ebp-10h]
  unsigned int v18; // [esp+24h] [ebp-Ch] BYREF
  unsigned int v19; // [esp+28h] [ebp-8h] BYREF
  unsigned int v20; // [esp+2Ch] [ebp-4h] BYREF

  z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
  x = up_vector.x;
  v9 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
  vostok::render::backend::set_vs_constant<vostok::math::float4x4>(
    (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    *(const vostok::render::shader_constant_host **)LODWORD(up_vector.x),
    (const unsigned int *)&right_vector.y);
  vostok::render::backend::set_vs_constant<vostok::math::float4x4>(
    (vostok::render::backend *)LODWORD(v9),
    *(const vostok::render::shader_constant_host **)(LODWORD(up_vector.x) + 4),
    (const unsigned int *)&up_vector.y);
  vostok::render::backend::set_vs_constant<vostok::math::float4x4>(
    (vostok::render::backend *)LODWORD(v9),
    *(const vostok::render::shader_constant_host **)(LODWORD(up_vector.x) + 12),
    (const unsigned int *)&view_location.y);
  v19 = 0;
  v18 = 0;
  v20 = LODWORD(FLOAT_N1_0);
  v15 = 0;
  v16 = 0.0;
  v17 = 0.0;
  if ( a7 == 3 )
  {
    v10 = screen_alignment;
    v11 = screen_alignment == 6;
    HIBYTE(a7) = screen_alignment == (particle_screen_alignment_to_axis|0x4);
    v12 = screen_alignment == (particle_screen_alignment_to_axis|0x4);
    *(float *)&v14 = (float)(screen_alignment == 6);
    HIBYTE(screen_alignment) = screen_alignment == 8;
    v15 = v14;
    v16 = (float)v12;
    v17 = (float)HIBYTE(screen_alignment);
    if ( !v11 && !HIBYTE(a7) && !HIBYTE(screen_alignment) )
    {
      x = up_vector.x;
      v13 = (float)v10;
LABEL_9:
      v20 = LODWORD(v13);
      goto LABEL_10;
    }
    x = up_vector.x;
    v18 = LODWORD(s_bm_current_air_resistance);
  }
  else if ( a7 == 2 )
  {
    v19 = LODWORD(s_bm_current_air_resistance);
    v13 = (float)screen_alignment;
    goto LABEL_9;
  }
LABEL_10:
  vostok::render::backend::set_vs_constant<vostok::math::float4x4>(
    (vostok::render::backend *)LODWORD(z),
    *(const vostok::render::shader_constant_host **)(LODWORD(x) + 36),
    &v15);
  vostok::render::backend::set_vs_constant<vostok::math::float4x4>(
    (vostok::render::backend *)LODWORD(z),
    *(const vostok::render::shader_constant_host **)(LODWORD(x) + 40),
    &v20);
  vostok::render::backend::set_vs_constant<vostok::math::float4x4>(
    (vostok::render::backend *)LODWORD(z),
    *(const vostok::render::shader_constant_host **)(LODWORD(x) + 8),
    &v19);
  vostok::render::backend::set_vs_constant<vostok::math::float4x4>(
    (vostok::render::backend *)LODWORD(z),
    *(const vostok::render::shader_constant_host **)(LODWORD(x) + 32),
    &v18);
}
