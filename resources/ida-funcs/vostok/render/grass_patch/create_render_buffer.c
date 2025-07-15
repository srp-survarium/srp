void __userpurge vostok::render::grass_patch::create_render_buffer(
        vostok::render::grass_patch *this@<ecx>,
        vostok::math::float3 *__formal,
        const bool __formala)
{
  vostok::math::float3 *v3; // esi
  float x; // eax
  vostok::render::grass_instance_data *v5; // eax
  float z; // ebx
  vostok::math::half *v7; // ecx
  float y; // xmm0_4
  vostok::math::half *v9; // ecx
  vostok::render::byte4 *v10; // edx
  _WORD *v11; // eax
  int v12; // ecx
  int v13; // eax
  int v14; // edx
  int v15; // ecx
  int v16; // eax
  int *v17; // edx
  int v18; // ecx
  int v19; // eax
  int v20; // edx
  float v21; // xmm3_4
  float v22; // xmm1_4
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm1_4
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v26; // eax
  vostok::command_line::key *v27; // ecx
  vostok::math::float3 v28; // [esp+10h] [ebp-34h] BYREF
  vostok::render::byte4 v29; // [esp+1Eh] [ebp-26h]
  vostok::render::byte4 v30; // [esp+22h] [ebp-22h]
  vostok::math::half3 v31; // [esp+26h] [ebp-1Eh] BYREF
  float v32; // [esp+2Ch] [ebp-18h]
  _WORD *v33; // [esp+30h] [ebp-14h]
  void *data; // [esp+34h] [ebp-10h]
  vostok::render::byte4 *p_world_transform1; // [esp+38h] [ebp-Ch]
  float v36; // [esp+3Ch] [ebp-8h]
  __int16 v37; // [esp+42h] [ebp-2h] BYREF

  v3 = __formal;
  x = __formal[1].x;
  v32 = x;
  if ( x != 0.0 )
  {
    v5 = vostok::memory::new_array_helper<vostok::render::grass_instance_data>::call<vostok::memory::pthreads3_allocator>(
           LODWORD(x),
           &vostok::memory::g_mt_allocator);
    z = v3[1].z;
    data = v5;
    if ( z != 0.0 )
    {
      p_world_transform1 = &v5->world_transform1;
      do
      {
        vostok::math::float4x4::get_scale((vostok::math::float4x4 *)(LODWORD(z) + 12), &v28);
        y = v28.z;
        if ( v28.z > v28.y )
          y = v28.y;
        if ( y <= v28.x )
          v36 = y;
        else
          v36 = v28.x;
        v33 = vostok::math::half::half(v7, &v37, 0);
        vostok::math::half3::half3(&v31, (const vostok::math::float3 *)(LODWORD(z) + 60), v9);
        v10 = p_world_transform1;
        *(_WORD *)&v29.x = *v11;
        LOWORD(v12) = v11[1];
        *(_WORD *)&v30.x = v11[2];
        *(_WORD *)&v30.z = *v33;
        *(_WORD *)&v29.z = v12;
        p_world_transform1[-3] = v29;
        v10[-2] = v30;
        v13 = vostok::render::pack_direction((const vostok::math::float3 *)(LODWORD(z) + 12), v12);
        *(_DWORD *)(v14 - 4) = v13;
        v16 = vostok::render::pack_direction((const vostok::math::float3 *)(LODWORD(z) + 28), v15);
        *v17 = v16;
        v19 = vostok::render::pack_direction((const vostok::math::float3 *)(LODWORD(z) + 44), v18);
        v21 = s_bm_current_air_resistance;
        v22 = v36 * 0.1;
        v23 = 0.0;
        *(_DWORD *)(v20 + 4) = v19;
        *(_DWORD *)(v20 + 8) = *(_DWORD *)(LODWORD(z) + 80);
        if ( v22 > 0.0 )
        {
          if ( v21 < v22 )
            v22 = v21;
        }
        else
        {
          v22 = 0.0;
        }
        v24 = v22 * 255.0;
        if ( v24 > 0.0 )
        {
          if ( v24 > 255.0 )
            v24 = FLOAT_255_0;
        }
        else
        {
          v24 = 0.0;
        }
        *(_BYTE *)(v20 + 11) = (int)v24;
        v25 = *(float *)(LODWORD(z) + 76);
        if ( v25 > 0.0 )
        {
          if ( v21 < v25 )
            v23 = v21;
          else
            v23 = *(float *)(LODWORD(z) + 76);
        }
        *(_BYTE *)(v20 - 1) = (int)(float)(v23 * 255.0);
        z = *(float *)(LODWORD(z) + 8);
        p_world_transform1 = (vostok::render::byte4 *)(v20 + 24);
      }
      while ( z != 0.0 );
      v3 = __formal;
    }
    vostok::render::resource_manager::create_buffer(
      24 * LODWORD(v32),
      vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
      (void *)0x18,
      (vostok::render::enum_buffer_type)data,
      0,
      0,
      0);
    vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
      v26,
      (vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)&v3->z,
      (vostok::render::hw_buffer_pool *)v3);
    if ( data )
    {
      __formal = (vostok::math::float3 *)((char *)data - 8);
      if ( vostok::memory::g_mt_allocator.m_use_memory_monitor )
        vostok::memory::monitor::on_free((void **)&__formal, v27);
      pt3free((int)v27, (char *)__formal);
    }
  }
}
