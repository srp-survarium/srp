void __userpurge vostok::render::batched_geometry<vostok::render::lpv_vertex>::batched_geometry<vostok::render::lpv_vertex>(
        vostok::render::batched_geometry<vostok::render::lpv_vertex> *this@<ecx>,
        vostok::intrusive_ptr<vostok::render::res_declaration,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *a2@<edi>,
        const D3D11_INPUT_ELEMENT_DESC *layout,
        const unsigned int num_elements,
        const unsigned int in_batched_geometry_max_vertices_count)
{
  vostok::intrusive_ptr<vostok::render::res_declaration,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v5; // ecx
  int v6; // esi
  vostok::intrusive_ptr<vostok::render::res_declaration,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v7; // eax
  vostok::render::resource_manager *v8; // ecx
  vostok::render::res_declaration *declaration; // eax

  a2->m_object = (vostok::render::res_declaration *)&vostok::render::batched_geometry<vostok::render::lpv_vertex>::`vftable';
  a2[1].m_object = (vostok::render::res_declaration *)&a2[4];
  a2[2].m_object = (vostok::render::res_declaration *)&a2[4];
  v5 = a2 + 292;
  a2[3].m_object = (vostok::render::res_declaration *)&a2[292];
  v6 = 7;
  v7 = a2 + 295;
  do
  {
    v5->m_object = (vostok::render::res_declaration *)v7;
    v7[-2].m_object = (vostok::render::res_declaration *)v7;
    v7[-1].m_object = (vostok::render::res_declaration *)&v7[288];
    v5 += 291;
    v7 += 291;
    --v6;
  }
  while ( v6 >= 0 );
  a2[2620].m_object = 0;
  a2[2621].m_object = (vostok::render::res_declaration *)&_sbh_sizeHeaderList;
  a2[2630].m_object = (vostok::render::res_declaration *)&a2[2633];
  a2[2631].m_object = (vostok::render::res_declaration *)&a2[2633];
  a2[2632].m_object = (vostok::render::res_declaration *)((char *)&a2[2633] + (_DWORD)&loc_13FFFE + 2);
  a2[330313].m_object = (vostok::render::res_declaration *)&a2[330316];
  a2[330314].m_object = (vostok::render::res_declaration *)&a2[330316];
  a2[330315].m_object = (vostok::render::res_declaration *)((char *)&loc_20000 + (_DWORD)(a2 + 330316));
  vostok::math::create_zero_aabb((vostok::math::aabb *)((char *)&loc_162930 + (_DWORD)a2));
  *(vostok::render::res_declaration **)((char *)&a2->m_object + (_DWORD)&loc_162945 + 3) = 0;
  declaration = vostok::render::resource_manager::create_declaration(
                  v8,
                  (const D3D11_INPUT_ELEMENT_DESC *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                  lpv_layout,
                  (unsigned int)layout);
  vostok::intrusive_ptr<vostok::render::res_declaration,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    a2 + 2620,
    declaration);
}


void __userpurge vostok::render::batched_geometry<vostok::render::shadow_vertex>::batched_geometry<vostok::render::shadow_vertex>(
        vostok::render::batched_geometry<vostok::render::shadow_vertex> *this@<ecx>,
        int a2@<edi>,
        const D3D11_INPUT_ELEMENT_DESC *layout,
        const unsigned int num_elements,
        const unsigned int in_batched_geometry_max_vertices_count)
{
  _DWORD *v5; // ecx
  int v6; // esi
  int v7; // eax
  _DWORD *v8; // eax
  char *v9; // ecx
  vostok::render::resource_manager *v10; // ecx
  vostok::render::res_declaration *declaration; // eax

  *(_DWORD *)a2 = &vostok::render::batched_geometry<vostok::render::shadow_vertex>::`vftable';
  *(_DWORD *)(a2 + 4) = a2 + 16;
  *(_DWORD *)(a2 + 8) = a2 + 16;
  v5 = (_DWORD *)(a2 + 1168);
  *(_DWORD *)(a2 + 12) = a2 + 1168;
  v6 = 7;
  v7 = a2 + 1180;
  do
  {
    *v5 = v7;
    *(_DWORD *)(v7 - 8) = v7;
    *(_DWORD *)(v7 - 4) = v7 + 1152;
    v5 += 291;
    v7 += 1164;
    --v6;
  }
  while ( v6 >= 0 );
  *(_DWORD *)(a2 + 10480) = 0;
  *(_DWORD *)(a2 + 10484) = 0x8000;
  *(_DWORD *)(a2 + 10520) = a2 + 10532;
  *(_DWORD *)(a2 + 10524) = a2 + 10532;
  *(_DWORD *)(a2 + 10528) = (char *)&loc_200000 + a2 + 10532;
  v8 = (_DWORD *)((char *)&loc_202924 + a2);
  v9 = (char *)&loc_202924 + a2 + 12;
  *v8 = v9;
  v8[1] = v9;
  v8[2] = (char *)&loc_20000 + (_DWORD)v9;
  vostok::math::create_zero_aabb((vostok::math::aabb *)(a2 + 2238768));
  *(_DWORD *)(a2 + 2238792) = 0;
  declaration = vostok::render::resource_manager::create_declaration(
                  v10,
                  (const D3D11_INPUT_ELEMENT_DESC *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                  shadow_layout,
                  (unsigned int)layout);
  vostok::intrusive_ptr<vostok::render::res_declaration,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    (vostok::intrusive_ptr<vostok::render::res_declaration,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(a2 + 10480),
    declaration);
}
