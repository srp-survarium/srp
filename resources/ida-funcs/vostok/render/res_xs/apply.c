void __thiscall vostok::render::res_xs<vostok::render::gs_data>::apply(
        vostok::render::res_xs<vostok::render::gs_data> *this,
        int a2)
{
  int v2; // edi
  float z; // esi
  bool v4; // zf
  float v5; // edi
  vostok::render::res_texture_list *v6; // eax
  float v7; // esi
  float v8; // edi
  const vostok::render::res_buffer_list *v9; // esi
  vostok::render::buffers_handler<0> *v10; // ecx
  float v11; // esi
  bool v12; // cl
  float v13; // edi
  float v14; // esi

  v2 = *(_DWORD *)(a2 + 4);
  if ( v2
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
    v4 = *(_DWORD *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 420) == v2;
    *(_DWORD *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 420) = v2;
    *(_BYTE *)(LODWORD(z) + 102) |= !v4;
    vostok::render::backend::set_gs_constants(
      (vostok::render::backend *)LODWORD(z),
      *(vostok::render::shader_constant_table **)(a2 + 8));
    v5 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
    v6 = *(vostok::render::res_texture_list **)(a2 + 12);
    v7 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
    if ( *(vostok::render::res_texture_list **)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z)
                                              + 2116) != v6 )
    {
      vostok::render::textures_handler<0>::assign(
        (vostok::render::textures_handler<0> *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z)
                                              + 2116),
        v6);
      v5 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
      *(_BYTE *)(LODWORD(v7) + 104) = 1;
    }
    vostok::render::backend::set_gs_samplers(
      (vostok::render::backend *)LODWORD(v5),
      *(vostok::render::res_sampler_list **)(a2 + 16));
    v8 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
    v9 = *(const vostok::render::res_buffer_list **)(a2 + 20);
    v10 = (vostok::render::buffers_handler<0> *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z)
                                               + 3000);
    if ( *(const vostok::render::res_buffer_list **)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z)
                                                   + 3000) != v9 )
      goto LABEL_11;
  }
  else
  {
    v11 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
    v12 = *(_DWORD *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 420) != 0;
    *(_DWORD *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 420) = 0;
    *(_BYTE *)(LODWORD(v11) + 102) |= v12;
    vostok::render::backend::set_gs_constants((vostok::render::backend *)LODWORD(v11), 0);
    v13 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
    v14 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
    if ( *(_DWORD *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 2116) )
    {
      vostok::render::textures_handler<0>::assign(
        (vostok::render::textures_handler<0> *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z)
                                              + 2116),
        0);
      v13 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
      *(_BYTE *)(LODWORD(v14) + 104) = 1;
    }
    vostok::render::backend::set_gs_samplers((vostok::render::backend *)LODWORD(v13), 0);
    v8 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
    v10 = (vostok::render::buffers_handler<0> *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z)
                                               + 3000);
    if ( *(_DWORD *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 3000) )
    {
      v9 = 0;
LABEL_11:
      vostok::render::buffers_handler<2>::assign(v10, v9);
      *(_BYTE *)(LODWORD(v8) + 106) = 1;
    }
  }
}


void __thiscall vostok::render::res_xs<vostok::render::ps_data>::apply(
        vostok::render::res_xs<vostok::render::ps_data> *this,
        int a2)
{
  int v2; // eax
  float z; // esi
  _DWORD *v4; // edi
  bool v5; // cl
  bool v6; // zf
  float v7; // edi
  vostok::render::res_texture_list *v8; // eax
  vostok::render::textures_handler<0> *v9; // ecx
  float v10; // esi
  float v11; // edi
  const vostok::render::res_buffer_list *v12; // esi

  v2 = *(_DWORD *)(a2 + 4);
  z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
  v4 = (_DWORD *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 416);
  v5 = *(_DWORD *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 416) != v2;
  v6 = (v5 | *(_BYTE *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 107)) == 0;
  *(_BYTE *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 107) |= v5;
  if ( !v6 )
    ++*(_DWORD *)(LODWORD(z) + 7556);
  *v4 = v2;
  vostok::render::backend::set_ps_constants(
    (vostok::render::backend *)LODWORD(z),
    *(vostok::render::shader_constant_table **)(a2 + 8));
  v7 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
  v8 = *(vostok::render::res_texture_list **)(a2 + 12);
  v9 = (vostok::render::textures_handler<0> *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z)
                                             + 3740);
  v10 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
  if ( *(vostok::render::res_texture_list **)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z)
                                            + 3740) != v8 )
  {
    ++*(_DWORD *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 7580);
    vostok::render::textures_handler<0>::assign(v9, v8);
    v7 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
    *(_BYTE *)(LODWORD(v10) + 109) = 1;
  }
  vostok::render::backend::set_ps_samplers(
    (vostok::render::backend *)LODWORD(v7),
    *(vostok::render::res_sampler_list **)(a2 + 16));
  v11 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
  v12 = *(const vostok::render::res_buffer_list **)(a2 + 20);
  if ( *(const vostok::render::res_buffer_list **)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z)
                                                 + 4624) != v12 )
  {
    vostok::render::buffers_handler<2>::assign(
      (vostok::render::buffers_handler<0> *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z)
                                           + 4624),
      v12);
    *(_BYTE *)(LODWORD(v11) + 111) = 1;
  }
}


void __thiscall vostok::render::res_xs<vostok::render::vs_data>::apply(
        vostok::render::res_xs<vostok::render::vs_data> *this,
        int a2)
{
  float z; // edi
  float v3; // edi
  vostok::render::res_texture_list *v4; // eax
  vostok::render::textures_handler<0> *v5; // ecx
  float v6; // esi
  float v7; // edi
  const vostok::render::res_buffer_list *v8; // esi

  z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
  vostok::render::backend::set_vs(
    (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    *(vostok::render::res_xs_hw<vostok::render::vs_data> **)(a2 + 4));
  vostok::render::backend::set_vs_constants(
    (vostok::render::backend *)LODWORD(z),
    *(vostok::render::shader_constant_table **)(a2 + 8));
  v3 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
  v4 = *(vostok::render::res_texture_list **)(a2 + 12);
  v5 = (vostok::render::textures_handler<0> *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z)
                                             + 492);
  v6 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
  if ( *(vostok::render::res_texture_list **)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z)
                                            + 492) != v4 )
  {
    ++*(_DWORD *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 7568);
    vostok::render::textures_handler<0>::assign(v5, v4);
    v3 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
    *(_BYTE *)(LODWORD(v6) + 99) = 1;
  }
  vostok::render::backend::set_vs_samplers(
    (vostok::render::backend *)LODWORD(v3),
    *(vostok::render::res_sampler_list **)(a2 + 16));
  v7 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
  v8 = *(const vostok::render::res_buffer_list **)(a2 + 20);
  if ( *(const vostok::render::res_buffer_list **)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z)
                                                 + 1376) != v8 )
  {
    vostok::render::buffers_handler<2>::assign(
      (vostok::render::buffers_handler<0> *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z)
                                           + 1376),
      v8);
    *(_BYTE *)(LODWORD(v7) + 101) = 1;
  }
}
