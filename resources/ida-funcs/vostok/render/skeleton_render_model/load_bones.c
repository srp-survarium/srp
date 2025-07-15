void __thiscall vostok::render::skeleton_render_model::load_bones(
        vostok::render::skeleton_render_model *this,
        vostok::memory::reader *bones_chunk,
        _DWORD *a3)
{
  unsigned __int16 *v4; // eax
  int v5; // edi
  vostok::memory::reader *v6; // ecx
  __int64 *v7; // eax
  vostok::math::float4x4 v8; // [esp+10h] [ebp-98h] BYREF
  vostok::math::float3 v9; // [esp+50h] [ebp-58h] BYREF
  vostok::animation::frame v10; // [esp+5Ch] [ebp-4Ch] BYREF
  vostok::math::float3_pod v11; // [esp+80h] [ebp-28h]
  __int64 v12; // [esp+8Ch] [ebp-1Ch]
  float v13; // [esp+94h] [ebp-14h]
  float v14; // [esp+98h] [ebp-10h]
  __int64 v15; // [esp+9Ch] [ebp-Ch]
  unsigned int *p_m_size; // [esp+A4h] [ebp-4h]
  int v17; // [esp+B0h] [ebp+8h]
  unsigned __int16 v18; // [esp+B4h] [ebp+Ch]
  int v19; // [esp+B4h] [ebp+Ch]

  v4 = (unsigned __int16 *)a3[1];
  v18 = *v4;
  v5 = v18;
  a3[1] = v4 + 1;
  p_m_size = &bones_chunk[26].m_size;
  vostok::buffer_vector<vostok::math::float4x4>::resize(
    (vostok::buffer_vector<vostok::math::float4x4> *)&bones_chunk[26].m_size,
    v18);
  if ( v18 )
  {
    v19 = 0;
    v17 = v5;
    do
    {
      vostok::memory::reader::r_string(v6, a3);
      v7 = (__int64 *)a3[1];
      v12 = *v7;
      v13 = *((float *)v7 + 2);
      *(_QWORD *)&v10.translation.x = v12;
      v10.translation.z = v13;
      v7 = (__int64 *)((char *)v7 + 12);
      a3[1] = v7;
      v11 = *(vostok::math::float3_pod *)v7;
      v10.rotation = v11;
      v7 = (__int64 *)((char *)v7 + 12);
      a3[1] = v7;
      v14 = *(float *)v7;
      v15 = *(__int64 *)((char *)v7 + 4);
      v10.scale.x = v14;
      a3[1] = (char *)v7 + 12;
      *(_QWORD *)&v10.channels[7] = v15;
      vostok::animation::frame_matrix(&v10, &v9, &v8);
      vostok::math::float4x4::try_invert(&v8, (vostok::math::float4x4 *)(v19 + *p_m_size));
      v19 += 64;
      --v17;
    }
    while ( v17 );
  }
}
