void __thiscall vostok::render::stage_visibility::frustum_culling(
        vostok::render::stage_visibility *this,
        int probes_generate_pass)
{
  int v2; // edi
  int v3; // eax
  int v4; // esi
  unsigned int v5; // ebx
  vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> > *v6; // ecx
  int v7; // eax
  int v8; // ecx
  vostok::render::ambient_light *v9; // edi
  vostok::render::ambient_light *v10; // eax
  _DWORD *m_reference_count; // edi
  int v12; // eax
  int v13; // eax
  vostok::render::light *v14; // eax
  vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> > *v15; // ecx
  vostok::render::light *v16; // eax
  char *v17; // edi
  vostok::memory::doug_lea_allocator *v19; // esi
  vostok::memory::doug_lea_allocator *v20; // ecx
  int v21; // edi
  void *v22; // esp
  int v23; // ecx
  vostok::render::light *v24; // edi
  vostok::render::ambient_light **v25; // eax
  int v26; // edi
  void *v27; // esp
  int v28; // ecx
  vostok::buffer_vector<vostok::render::environment_probe *> *v29; // ecx
  vostok::render::light *v30; // edi
  vostok::render::ambient_volume **v31; // ecx
  vostok::render::ambient_light *v32; // eax
  vostok::buffer_vector<vostok::render::ambient_volume *> *v33; // ecx
  int v34; // edi
  void *v35; // esp
  int v36; // ecx
  vostok::buffer_vector<vostok::render::ambient_light *> *v37; // ecx
  vostok::render::light *v38; // edi
  vostok::render::ambient_light *v39; // ecx
  int *v40; // esi
  vostok::render::ambient_light *v41; // ebx
  vostok::render::render_surface_instance **m_begin; // edi
  int v43; // ebx
  unsigned int *v44; // eax
  unsigned int v45; // edx
  const char *v46[4]; // [esp+0h] [ebp-20D4h] BYREF
  vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> > *v47; // [esp+10h] [ebp-20C4h] BYREF
  vostok::render::ambient_light *v48; // [esp+14h] [ebp-20C0h]
  char *v49; // [esp+18h] [ebp-20BCh]
  _BYTE v50[8192]; // [esp+1Ch] [ebp-20B8h] BYREF
  char v51; // [esp+201Ch] [ebp-B8h] BYREF
  vostok::math::frustum v52; // [esp+2020h] [ebp-B4h] BYREF
  int v53; // [esp+2098h] [ebp-3Ch]
  _BYTE v54[24]; // [esp+209Ch] [ebp-38h] BYREF
  vostok::buffer_vector<vostok::render::render_surface_instance *> *v55; // [esp+20B4h] [ebp-20h]
  int v56; // [esp+20B8h] [ebp-1Ch]
  vostok::render::ambient_light *v57; // [esp+20BCh] [ebp-18h]
  vostok::render::ambient_volume **v58; // [esp+20C0h] [ebp-14h]
  bool v59; // [esp+20C7h] [ebp-Dh] BYREF
  vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> value; // [esp+20C8h] [ebp-Ch] BYREF
  vostok::render::ambient_light *v61[2]; // [esp+20CCh] [ebp-8h] BYREF
  int v62; // [esp+20DCh] [ebp+8h]

  v2 = probes_generate_pass;
  vostok::math::frustum::frustum(&v52, (const vostok::math::float4x4 *)(*(_DWORD *)(probes_generate_pass + 4) + 20148));
  v3 = *(_DWORD *)(probes_generate_pass + 4);
  v4 = *(_DWORD *)(v3 + 16264);
  v5 = *(_DWORD *)(v3 + 16268);
  *(_DWORD *)(v5 + 48356) = *(_DWORD *)(v5 + 48352);
  *(_DWORD *)(v5 + 52464) = *(_DWORD *)(v5 + 52460);
  v6 = *(vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> > **)(v5 + 56568);
  *(_DWORD *)(v5 + 56572) = v6;
  v56 = v4;
  vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>::clear(
    v6,
    v5,
    (const char *)probes_generate_pass,
    (const char *)v4,
    (vostok::render::light *)(v5 + 44244));
  *(_DWORD *)(v5 + 9372) = *(_DWORD *)(v5 + 9368);
  v55 = (vostok::buffer_vector<vostok::render::render_surface_instance *> *)(v5 + 9368);
  *(_DWORD *)(v5 + 60680) = *(_DWORD *)(v5 + 60676);
  *(_DWORD *)(v5 + 64788) = *(_DWORD *)(v5 + 64784);
  *(_DWORD *)(v5 + 1168) = *(_DWORD *)(v5 + 1164);
  v7 = *(int *)((char *)&dword_8B9668 + v4);
  if ( v7
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    vostok::render::grass_world::process_culling(
      (vostok::render::grass_world *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr,
      v7,
      *(vostok::render::renderer_context **)(probes_generate_pass + 4),
      *(const float *)v46);
    v2 = probes_generate_pass;
  }
  v8 = *(int *)((char *)&dword_8B9664 + v4);
  if ( v8 )
    (*(void (__thiscall **)(int, int, unsigned int))(*(_DWORD *)v8 + 36))(v8, *(_DWORD *)(v2 + 4) + 20148, v5 + 56568);
  if ( ((*(_DWORD *)(v5 + 56572) - *(_DWORD *)(v5 + 56568)) & 0xFFFFFFFC) != 0 )
  {
    v9 = *(vostok::render::ambient_light **)(v5 + 56568);
    v10 = *(vostok::render::ambient_light **)(v5 + 56572);
    v58 = 0;
    v53 = 0;
    v57 = v9;
    v61[0] = v10;
    if ( v9 != v10 )
    {
      value.m_object = (vostok::render::light *)(*(int (__thiscall **)(unsigned int))(*(_DWORD *)v9->m_reference_count
                                                                                    + 24))(v9->m_reference_count);
      while ( 1 )
      {
        m_reference_count = (_DWORD *)v9->m_reference_count;
        v12 = (*(int (__thiscall **)(_DWORD *))(*m_reference_count + 28))(m_reference_count);
        if ( v53 != v12 )
        {
          v13 = (*(int (__thiscall **)(_DWORD *))(*m_reference_count + 28))(m_reference_count);
          v58 = 0;
          v53 = v13;
        }
        v14 = (vostok::render::light *)(*(int (__thiscall **)(_DWORD *))(*m_reference_count + 24))(m_reference_count);
        if ( value.m_object != v14 )
        {
          v58 = (vostok::render::ambient_volume **)((char *)v58 + 1);
          m_reference_count[95] = v58;
          value.m_object = (vostok::render::light *)(*(int (__thiscall **)(_DWORD *))(*m_reference_count + 24))(m_reference_count);
        }
        v57 = (vostok::render::ambient_light *)((char *)v57 + 4);
        if ( v57 == v61[0] )
          break;
        v9 = v57;
      }
    }
  }
  v47 = (vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> > *)v50;
  v48 = (vostok::render::ambient_light *)v50;
  v49 = &v51;
  (*(void (__thiscall **)(_DWORD, int, vostok::math::frustum *, vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> > **))(**(_DWORD **)(*(int *)((char *)&dword_8B9660 + v4) + 8204) + 28))(
    *(_DWORD *)(*(int *)((char *)&dword_8B9660 + v4) + 8204),
    -1,
    &v52,
    &v47);
  v15 = v47;
  v57 = (vostok::render::ambient_light *)v47;
  v61[0] = v48;
  if ( v47 != (vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> > *)v48 )
  {
    do
    {
      v16 = *(vostok::render::light **)(v57->m_reference_count + 36);
      v17 = 0;
      value.m_object = 0;
      if ( v16 )
      {
        ++v16->m_reference_count;
        v17 = (char *)v16;
        value.m_object = v16;
      }
      vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>::push_back(
        v15,
        v5 + 44244,
        &value);
      if ( v17 )
      {
        if ( (*(_DWORD *)v17)-- == 1 )
        {
          v19 = vostok::render::g_allocator;
          vostok::render::light::remove_collision((vostok::render::light *)v15, (int)v17);
          `vector destructor iterator'(
            v17 + 724,
            4u,
            6,
            (void (__thiscall *)(void *))vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>);
          `vector destructor iterator'(
            v17 + 700,
            4u,
            6,
            (void (__thiscall *)(void *))vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>);
          vostok::memory::doug_lea_allocator::free_impl(v20, (int)v19, v17, v46[0], v46[1], (const unsigned int)v46[2]);
        }
      }
      v57 = (vostok::render::ambient_light *)((char *)v57 + 4);
    }
    while ( v57 != v61[0] );
    v4 = v56;
  }
  v21 = *(int *)((char *)&dword_8B6544 + v4);
  v22 = alloca(v21 * 4);
  v23 = *(int *)((char *)&dword_8B9650 + v4);
  *(_DWORD *)&v54[12] = v46;
  *(_DWORD *)&v54[16] = v46;
  *(_DWORD *)&v54[20] = &v46[v21];
  (*(void (__thiscall **)(int, int, vostok::math::frustum *, _BYTE *))(*(_DWORD *)v23 + 28))(v23, -1, &v52, &v54[12]);
  v24 = *(vostok::render::light **)&v54[12];
  for ( value.m_object = *(vostok::render::light **)&v54[16];
        v24 != value.m_object;
        v24 = (vostok::render::light *)((char *)v24 + 4) )
  {
    v61[0] = *(vostok::render::ambient_light **)(v24->m_reference_count + 36);
    if ( *(_DWORD *)(v5 + 48356) >= *(_DWORD *)(v5 + 48360)
      && !HIBYTE(vostok::quasi_singleton<vostok::render::effect_constant_storage>::pinst.elements[2]) )
    {
      v59 = 0;
      vostok::debug::on_error(
        &v59,
        process_error_true,
        0,
        "assertion_failed",
        "fatal error",
        "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
        "vostok::buffer_vector<struct vostok::render::decal_instance *>::push_back",
        (const char *)0x12E,
        "buffer overflow",
        v46[0]);
      if ( vostok::debug::is_debugger_present() || v59 )
        __debugbreak();
    }
    v25 = *(vostok::render::ambient_light ***)(v5 + 48356);
    if ( v25 )
      *v25 = v61[0];
    *(_DWORD *)(v5 + 48356) += 4;
  }
  v26 = (*(_DWORD *)&aAvbtcollisionw[v4 + 8] - *(_DWORD *)&aAvbtcollisionw[v4 + 4]) >> 2;
  v27 = alloca(v26 * 4);
  v28 = *(int *)((char *)&dword_8B9658 + v4);
  *(_DWORD *)&v54[12] = v46;
  *(_DWORD *)&v54[16] = v46;
  *(_DWORD *)&v54[20] = &v46[v26];
  (*(void (__thiscall **)(int, int, vostok::math::frustum *, _BYTE *))(*(_DWORD *)v28 + 28))(v28, -1, &v52, &v54[12]);
  v30 = *(vostok::render::light **)&v54[12];
  value.m_object = *(vostok::render::light **)&v54[16];
  if ( *(_DWORD *)&v54[12] != *(_DWORD *)&v54[16] )
  {
    do
    {
      v61[0] = *(vostok::render::ambient_light **)(v30->m_reference_count + 36);
      vostok::buffer_vector<vostok::render::environment_probe *>::push_back(
        v29,
        v5 + 52460,
        (vostok::render::environment_probe **)v61);
      v30 = (vostok::render::light *)((char *)v30 + 4);
    }
    while ( v30 != value.m_object );
    v4 = v56;
  }
  v31 = *(vostok::render::ambient_volume ***)((char *)&vostok::memory::s_resources.m_buffer[9314] + v4);
  v32 = *(vostok::render::ambient_light **)((char *)&vostok::memory::s_resources.m_buffer[9315] + v4);
  v58 = v31;
  v61[0] = v32;
  if ( v31 != (vostok::render::ambient_volume **)v32 )
  {
    while ( 1 )
    {
      qmemcpy(v54, &(*v31)->m_aabb, sizeof(v54));
      if ( vostok::math::cuboid::test_inexact(0, (int)&v52, (vostok::math::aabb_plane *)v54) != 2 )
        vostok::buffer_vector<vostok::render::ambient_volume *>::push_back(v33, v5 + 60676, v58);
      if ( ++v58 == (vostok::render::ambient_volume **)v61[0] )
        break;
      v31 = v58;
    }
    v4 = v56;
  }
  v34 = (*(_DWORD *)((char *)&SNaN_33 + v4 + 4) - *(_DWORD *)((char *)&SNaN_33 + v4)) >> 2;
  v35 = alloca(v34 * 4);
  v36 = *(int *)((char *)&dword_8B965C + v4);
  *(_DWORD *)&v54[12] = v46;
  *(_DWORD *)&v54[16] = v46;
  *(_DWORD *)&v54[20] = &v46[v34];
  (*(void (__thiscall **)(int, int, vostok::math::frustum *, _BYTE *))(*(_DWORD *)v36 + 28))(v36, -1, &v52, &v54[12]);
  v38 = *(vostok::render::light **)&v54[12];
  value.m_object = *(vostok::render::light **)&v54[16];
  if ( *(_DWORD *)&v54[12] != *(_DWORD *)&v54[16] )
  {
    do
    {
      v61[0] = *(vostok::render::ambient_light **)(v38->m_reference_count + 36);
      vostok::buffer_vector<vostok::render::ambient_light *>::push_back(v37, v5 + 64784, v61);
      v38 = (vostok::render::light *)((char *)v38 + 4);
    }
    while ( v38 != value.m_object );
    v4 = v56;
  }
  vostok::render::scene::select_models(
    (vostok::render::scene *)(*(_DWORD *)(probes_generate_pass + 4) + 20148),
    v4,
    (vostok::math::float4x4 *)(*(_DWORD *)(probes_generate_pass + 4) + 20148),
    (const vostok::math::float4x4 *)(*(_DWORD *)(probes_generate_pass + 4) + 20148),
    v55,
    (vostok::math::float4x4 *)(*(_DWORD *)(probes_generate_pass + 4) + 21132),
    (const vostok::math::float3 *)1,
    0,
    (bool)v46[0]);
  vostok::render::scene::select_models(
    (vostok::render::scene *)(*(_DWORD *)(probes_generate_pass + 4) + 20148),
    v4,
    (vostok::math::float4x4 *)(*(_DWORD *)(probes_generate_pass + 4) + 20148),
    (const vostok::math::float4x4 *)(*(_DWORD *)(probes_generate_pass + 4) + 20148),
    (vostok::buffer_vector<vostok::render::render_surface_instance *> *)(v5 + 1164),
    (vostok::math::float4x4 *)(*(_DWORD *)(probes_generate_pass + 4) + 21132),
    (const vostok::math::float3 *)1,
    1u,
    (bool)v46[0]);
  if ( s_visible_surfaces_limit_value )
  {
    v40 = (int *)v55;
    v41 = *(vostok::render::ambient_light **)(v5 + 9372);
    m_begin = v55->m_begin;
    v62 = 0;
    v61[0] = v41;
    if ( m_begin != (vostok::render::render_surface_instance **)v41 )
    {
      v39 = (vostok::render::ambient_light *)(m_begin + 1);
      if ( m_begin + 1 != (vostok::render::render_surface_instance **)v41 )
      {
        v43 = 4;
        do
        {
          v62 = 134775813 * v62 + 1;
          v44 = (unsigned int *)&m_begin[((unsigned int)v62 * (unsigned __int64)(unsigned int)((v43 >> 2) + 1)) >> 32];
          v45 = v39->m_reference_count;
          v39->m_reference_count = *v44;
          v39 = (vostok::render::ambient_light *)((char *)v39 + 4);
          v43 += 4;
          *v44 = v45;
        }
        while ( v39 != v61[0] );
        v40 = (int *)v55;
      }
    }
    if ( (v40[1] - *v40) >> 2 > s_visible_surfaces_limit_value )
      vostok::buffer_vector<vostok::render::render_surface_instance *>::resize(
        (vostok::buffer_vector<vostok::render::render_surface_instance *> *)v39,
        v40);
  }
}
