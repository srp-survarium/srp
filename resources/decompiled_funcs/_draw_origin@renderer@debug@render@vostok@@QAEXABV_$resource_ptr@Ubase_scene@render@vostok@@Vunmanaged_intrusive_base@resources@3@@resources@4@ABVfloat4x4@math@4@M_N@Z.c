void __userpurge vostok::render::debug::renderer::draw_origin(
        float *a1@<eax>,
        int a2@<ecx>,
        float a3@<xmm0>,
        const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *scene,
        bool use_depth)
{
  float v6; // xmm3_4
  float v7; // xmm7_4
  float v8; // xmm1_4
  float v9; // xmm4_4
  float v10; // xmm5_4
  float v11; // xmm4_4
  float v12; // xmm6_4
  float v13; // xmm7_4
  float v14; // xmm6_4
  float v15; // xmm6_4
  float v16; // xmm6_4
  float v17; // edx
  float v18; // xmm7_4
  float v19; // xmm7_4
  float v20; // xmm6_4
  __int64 v21; // xmm3_8
  __int64 v22; // xmm0_8
  int v23; // ecx
  vostok::render::debug::draw_lines_command *v24; // esi
  __int32 v25; // eax
  int v26; // ecx
  bool v27; // zf
  unsigned __int16 indices[6]; // [esp+Ch] [ebp-B8h] BYREF
  float v29; // [esp+18h] [ebp-ACh]
  float v30; // [esp+1Ch] [ebp-A8h]
  float v31; // [esp+20h] [ebp-A4h]
  float v32; // [esp+24h] [ebp-A0h]
  float v33; // [esp+28h] [ebp-9Ch]
  float v34; // [esp+2Ch] [ebp-98h]
  float v35; // [esp+30h] [ebp-94h]
  float v36; // [esp+34h] [ebp-90h]
  float v37; // [esp+38h] [ebp-8Ch]
  float v38; // [esp+3Ch] [ebp-88h]
  float v39; // [esp+40h] [ebp-84h]
  float v40; // [esp+44h] [ebp-80h]
  float v41; // [esp+48h] [ebp-7Ch]
  float v42; // [esp+4Ch] [ebp-78h]
  float v43; // [esp+50h] [ebp-74h]
  float v44; // [esp+54h] [ebp-70h]
  float v45; // [esp+5Ch] [ebp-68h]
  vostok::render::vertex_colored vertices[6]; // [esp+60h] [ebp-64h] BYREF

  v6 = a1[4];
  v7 = a1[12];
  v43 = -a3;
  v35 = -a3;
  v8 = a1[8];
  v36 = v6 * 0.0;
  v38 = v8 * 0.0;
  v9 = *a1;
  *(float *)indices = (float)((float)((float)-a3 * *a1) + (float)((float)(v6 * 0.0) + (float)(v8 * 0.0))) + v7;
  v32 = (float)(v6 * 0.0) + (float)(v8 * 0.0);
  v10 = a1[5];
  v31 = v9;
  v11 = a1[9];
  v40 = v11 * 0.0;
  v34 = v10 * 0.0;
  v12 = a1[1];
  v30 = (float)(v10 * 0.0) + (float)(v11 * 0.0);
  v37 = v12;
  v13 = (float)((float)((float)-a3 * v12) + v30) + a1[13];
  v14 = a1[10];
  *(float *)&indices[2] = v13;
  v41 = a1[6];
  v45 = v41 * 0.0;
  v42 = v14;
  v15 = v14 * 0.0;
  v29 = (float)(v41 * 0.0) + v15;
  v39 = a1[2];
  v33 = v15;
  *(float *)&indices[4] = (float)((float)((float)-a3 * v39) + v29) + a1[14];
  *(_QWORD *)&vertices[0].position.x = *(_QWORD *)indices;
  v16 = a1[13];
  *(float *)indices = (float)((float)(v31 * a3) + v32) + a1[12];
  vertices[0].position.z = *(float *)&indices[4];
  *(float *)&indices[2] = (float)((float)(v37 * a3) + v30) + v16;
  vertices[0].color.m_value = -1;
  *(float *)&indices[4] = (float)((float)(v39 * a3) + v29) + a1[14];
  v17 = *(float *)&indices[4];
  *(_QWORD *)&vertices[1].position.x = *(_QWORD *)indices;
  v32 = v31 * 0.0;
  v44 = -a3;
  *(float *)indices = (float)((float)((float)((float)-a3 * v6) + (float)(v31 * 0.0)) + (float)(v8 * 0.0)) + a1[12];
  v31 = v37 * 0.0;
  v18 = (float)((float)((float)((float)-a3 * v10) + (float)(v37 * 0.0)) + (float)(v11 * 0.0)) + a1[13];
  v29 = a1[13];
  *(float *)&indices[2] = v18;
  v30 = v39 * 0.0;
  v19 = a1[14];
  *(float *)&indices[4] = (float)((float)((float)((float)-a3 * v41) + (float)(v39 * 0.0)) + v33) + v19;
  *(_QWORD *)&vertices[2].position.x = *(_QWORD *)indices;
  v20 = a1[12];
  vertices[1].position.z = v17;
  *(float *)indices = (float)((float)((float)(v6 * a3) + v32) + (float)(v8 * 0.0)) + v20;
  *(float *)&indices[2] = (float)((float)((float)(v10 * a3) + (float)(v37 * 0.0)) + (float)(v11 * 0.0)) + v29;
  *(_QWORD *)&vertices[3].position.x = *(_QWORD *)indices;
  *(float *)indices = (float)((float)((float)((float)-a3 * v8) + v32) + (float)(v6 * 0.0)) + v20;
  vertices[1].color.m_value = -16776961;
  vertices[2].position.z = *(float *)&indices[4];
  vertices[2].color.m_value = -1;
  vertices[3].position.z = (float)((float)((float)(v41 * a3) + (float)(v39 * 0.0)) + v33) + v19;
  vertices[3].color.m_value = -16711936;
  *(float *)&indices[2] = (float)((float)((float)((float)-a3 * v11) + (float)(v37 * 0.0)) + (float)(v10 * 0.0)) + v29;
  v21 = *(_QWORD *)indices;
  vertices[4].color.m_value = -1;
  *(float *)&indices[2] = (float)((float)((float)(v11 * a3) + (float)(v37 * 0.0)) + (float)(v10 * 0.0)) + v29;
  *(float *)&indices[4] = (float)((float)((float)(v42 * a3) + (float)(v39 * 0.0)) + (float)(v41 * 0.0)) + v19;
  vertices[5].position.z = *(float *)&indices[4];
  vertices[4].position.z = (float)((float)((float)((float)-a3 * v42) + (float)(v39 * 0.0)) + (float)(v41 * 0.0)) + v19;
  *(float *)indices = (float)((float)((float)(v8 * a3) + v32) + v36) + v20;
  v22 = *(_QWORD *)indices;
  indices[0] = 0;
  indices[2] = 2;
  indices[1] = 1;
  indices[3] = 3;
  v23 = *(_DWORD *)(a2 + 128);
  indices[5] = 5;
  *(_QWORD *)&vertices[4].position.x = v21;
  *(_QWORD *)&vertices[5].position.x = v22;
  vertices[5].color.m_value = -65536;
  indices[4] = 4;
  v24 = (vostok::render::debug::draw_lines_command *)(*(int (__thiscall **)(int, int))(*(_DWORD *)v23 + 16))(v23, 124);
  if ( v24 )
    vostok::render::debug::draw_lines_command::draw_lines_command(
      v24,
      (const vostok::render::vertex_colored (*)[6])vertices,
      use_depth,
      scene,
      *(vostok::render::engine::world **)(a2 + 120),
      *(vostok::memory::base_allocator **)(a2 + 128),
      (const unsigned __int16 (*)[6])indices);
  else
    v25 = 0;
  v26 = *(_DWORD *)(a2 + 124);
  v27 = *(_DWORD *)(*(_DWORD *)(v26 + 64) + 4) == 0;
  *(_DWORD *)(v25 + 4) = 0;
  _InterlockedExchange((volatile __int32 *)(*(_DWORD *)v26 + 4), v25);
  *(_DWORD *)v26 = v25;
  if ( v27 )
    SetEvent(*(HANDLE *)(v26 + 144));
}
