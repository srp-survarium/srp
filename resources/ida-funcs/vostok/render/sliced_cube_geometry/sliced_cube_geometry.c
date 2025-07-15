void __thiscall vostok::render::sliced_cube_geometry::sliced_cube_geometry(
        vostok::render::sliced_cube_geometry *this,
        vostok::render::resource_manager *in_num_cells)
{
  vostok::render::resource_manager *v2; // esi
  void *v3; // esp
  _BYTE *v4; // ebx
  void *v5; // esp
  float v6; // xmm0_4
  _WORD *v7; // eax
  float *v8; // edx
  double v9; // st7
  int cb_created; // ecx
  double v11; // st6
  double v12; // st6
  _BYTE *v13; // ebx
  float *v14; // edx
  float v15; // xmm2_4
  float v16; // xmm3_4
  float *v17; // edi
  __int16 v18; // cx
  _WORD *v19; // eax
  vostok::render::res_declaration *declaration; // eax
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v22; // eax
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v23; // eax
  _BYTE v24[192]; // [esp-8C0h] [ebp-964h] BYREF
  _BYTE v25[16]; // [esp-800h] [ebp-8A4h] BYREF
  int v26; // [esp-7F0h] [ebp-894h] BYREF
  float v27; // [esp+Ch] [ebp-98h]
  float v28; // [esp+10h] [ebp-94h]
  int v29; // [esp+14h] [ebp-90h]
  float v30; // [esp+18h] [ebp-8Ch]
  float v31; // [esp+1Ch] [ebp-88h]
  int v32; // [esp+20h] [ebp-84h]
  float v33; // [esp+24h] [ebp-80h]
  float v34; // [esp+28h] [ebp-7Ch]
  int v35; // [esp+2Ch] [ebp-78h]
  float v36; // [esp+30h] [ebp-74h]
  float v37; // [esp+34h] [ebp-70h]
  float v38; // [esp+38h] [ebp-6Ch]
  float v39; // [esp+3Ch] [ebp-68h]
  float v40; // [esp+40h] [ebp-64h]
  int v41; // [esp+44h] [ebp-60h]
  float v42; // [esp+48h] [ebp-5Ch]
  float v43; // [esp+4Ch] [ebp-58h]
  float v44; // [esp+50h] [ebp-54h]
  int v45; // [esp+54h] [ebp-50h]
  float v46; // [esp+58h] [ebp-4Ch]
  int v47; // [esp+5Ch] [ebp-48h]
  int v48; // [esp+60h] [ebp-44h]
  float v49; // [esp+64h] [ebp-40h]
  float v50; // [esp+68h] [ebp-3Ch]
  float v51; // [esp+6Ch] [ebp-38h]
  float v52; // [esp+70h] [ebp-34h]
  float v53; // [esp+74h] [ebp-30h]
  float v54; // [esp+78h] [ebp-2Ch]
  float v55; // [esp+7Ch] [ebp-28h]
  float v56; // [esp+80h] [ebp-24h]
  int v57; // [esp+84h] [ebp-20h]
  float v58; // [esp+88h] [ebp-1Ch]
  void *v59; // [esp+8Ch] [ebp-18h]
  float v60; // [esp+90h] [ebp-14h]
  void *data; // [esp+94h] [ebp-10h]
  float v62; // [esp+98h] [ebp-Ch]
  unsigned int v63; // [esp+9Ch] [ebp-8h]

  v2 = in_num_cells;
  in_num_cells->sh_created = 0;
  in_num_cells->sh_returned = 0;
  in_num_cells->tl_created = 0;
  in_num_cells->cb_created = 16;
  in_num_cells->sl_created = 32;
  v3 = alloca(2048);
  v4 = v25;
  v5 = alloca(192);
  v6 = s_bm_current_air_resistance;
  v7 = v24;
  v47 = 0;
  v48 = 0;
  v57 = 0;
  v32 = 0;
  v41 = 0;
  v45 = 0;
  v35 = 0;
  v29 = 0;
  data = v25;
  v59 = v24;
  v63 = 0;
  v58 = s_bm_current_air_resistance;
  v31 = s_bm_current_air_resistance;
  v42 = s_bm_current_air_resistance;
  v51 = s_bm_current_air_resistance;
  v52 = s_bm_current_air_resistance;
  v46 = s_bm_current_air_resistance;
  v36 = s_bm_current_air_resistance;
  v30 = s_bm_current_air_resistance;
  v8 = (float *)&v26;
  while ( 1 )
  {
    v9 = (double)v63;
    cb_created = v2->cb_created;
    v60 = v9;
    v11 = (double)(int)v2->cb_created;
    if ( cb_created < 0 )
      v11 = v11 + 4294967300.0;
    v12 = v9 / v11;
    v62 = v12;
    v49 = v12;
    v50 = v9;
    *(_DWORD *)v4 = v47;
    v33 = v12;
    *((_DWORD *)v4 + 1) = v48;
    v34 = v9;
    *((float *)v4 + 2) = v49;
    v53 = v12;
    *((float *)v4 + 3) = v50;
    v55 = (float)(*(float *)v4 * 2.0) - v6;
    v56 = (float)((float)(v6 - *((float *)v4 + 1)) * 2.0) - v6;
    *v8 = v55;
    v8[1] = v56;
    *((_DWORD *)v8 + 2) = v57;
    v8[3] = v58;
    v13 = v4 + 32;
    *(float *)v13 = v31;
    *((_DWORD *)v13 + 1) = v32;
    *((float *)v13 + 2) = v33;
    *((float *)v13 + 3) = v34;
    v39 = (float)(*(float *)v13 * 2.0) - v6;
    v14 = v8 + 8;
    v40 = (float)((float)(v6 - *((float *)v13 + 1)) * 2.0) - v6;
    v15 = v60;
    *v14 = v39;
    v14[1] = v40;
    *((_DWORD *)v14 + 2) = v41;
    v14[3] = v42;
    v13 += 32;
    v54 = v15;
    *(float *)v13 = v51;
    *((float *)v13 + 1) = v52;
    *((float *)v13 + 2) = v53;
    *((float *)v13 + 3) = v54;
    v43 = (float)(*(float *)v13 * 2.0) - v6;
    v14 += 8;
    v44 = (float)((float)(v6 - *((float *)v13 + 1)) * 2.0) - v6;
    *v14 = v43;
    v14[1] = v44;
    *((_DWORD *)v14 + 2) = v45;
    v16 = v62;
    v14[3] = v46;
    v13 += 32;
    v38 = v15;
    v37 = v16;
    *(_DWORD *)v13 = v35;
    *((float *)v13 + 1) = v36;
    *((float *)v13 + 2) = v37;
    *((float *)v13 + 3) = v38;
    v14 += 8;
    v27 = (float)(*(float *)v13 * 2.0) - v6;
    v28 = (float)((float)(v6 - *((float *)v13 + 1)) * 2.0) - v6;
    *v14 = v27;
    v14[1] = v28;
    *((_DWORD *)v14 + 2) = v29;
    v17 = v14 + 3;
    v4 = v13 + 32;
    v8 = v14 + 8;
    v18 = v63;
    *v17 = v30;
    v18 *= 4;
    *v7 = v18;
    v19 = v7 + 1;
    *v19++ = v18 + 1;
    *v19++ = v18 + 2;
    *v19++ = v18;
    *v19++ = v18 + 2;
    *v19 = v18 + 3;
    v7 = v19 + 1;
    if ( ++v63 >= in_num_cells->cb_created )
      break;
    v2 = in_num_cells;
  }
  declaration = vostok::render::resource_manager::create_declaration(
                  in_num_cells,
                  (const D3D11_INPUT_ELEMENT_DESC *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                  sliced_cube_vertex_layout,
                  2u);
  vostok::intrusive_ptr<vostok::render::res_declaration,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    (vostok::intrusive_ptr<vostok::render::res_declaration,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)in_num_cells,
    declaration);
  vostok::render::resource_manager::create_buffer(
    in_num_cells->sl_created << 6,
    vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
    (void *)in_num_cells->sl_created,
    (vostok::render::enum_buffer_type)data,
    0,
    0,
    0);
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    v22,
    (vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)&in_num_cells->sh_returned,
    (vostok::render::hw_buffer_pool *)in_num_cells);
  vostok::render::resource_manager::create_buffer(
    0xC0u,
    vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
    (void *)2,
    (vostok::render::enum_buffer_type)v59,
    1,
    0,
    0);
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    v23,
    (vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)&in_num_cells->tl_created,
    (vostok::render::hw_buffer_pool *)in_num_cells);
}
