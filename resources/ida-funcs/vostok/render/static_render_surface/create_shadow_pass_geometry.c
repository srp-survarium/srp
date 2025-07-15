void __thiscall vostok::render::static_render_surface::create_shadow_pass_geometry(
        vostok::render::static_render_surface *this,
        const unsigned __int8 *data,
        unsigned __int8 *num_vertices,
        unsigned int stride,
        int a5)
{
  int v5; // eax
  unsigned int v6; // esi
  unsigned int v7[28]; // [esp+Ch] [ebp-5Ch] BYREF
  unsigned int stridea[21]; // [esp+7Ch] [ebp+14h] BYREF

  stridea[16] = 28;
  v7[16] = 28;
  v7[23] = 28;
  stridea[1] = 0;
  memset(&stridea[3], 0, 16);
  stridea[8] = 0;
  stridea[10] = 0;
  stridea[12] = 0;
  stridea[13] = 0;
  stridea[15] = 0;
  stridea[17] = 0;
  stridea[19] = 0;
  stridea[20] = 0;
  v7[1] = 0;
  memset(&v7[3], 0, 16);
  v7[8] = 0;
  v7[10] = 0;
  v7[12] = 0;
  v7[13] = 0;
  v7[15] = 0;
  v7[17] = 0;
  v7[19] = 0;
  v7[20] = 0;
  v7[22] = 0;
  v7[24] = 0;
  v7[26] = 0;
  v7[27] = 0;
  v5 = *((_DWORD *)data + 37);
  stridea[0] = (unsigned int)"POSITION";
  stridea[2] = 10;
  stridea[7] = (unsigned int)"TEXCOORD";
  stridea[9] = 34;
  stridea[11] = 8;
  stridea[14] = (unsigned int)"NORMAL";
  stridea[18] = 12;
  v7[0] = (unsigned int)"POSITION";
  v7[2] = 10;
  v7[7] = (unsigned int)"TEXCOORD";
  v7[9] = 34;
  v7[11] = 8;
  v7[14] = (unsigned int)"NORMAL";
  v7[18] = 12;
  v7[21] = (unsigned int)"COLOR";
  v7[25] = 16;
  if ( v5 == 2 )
  {
    v6 = stride;
    vostok::render::create_shadow_pass_geometry_type_vostok::render::static_vertex_type__vostok::render::static_render_surface::create_shadow_pass_geometry_::_2_::opt_static_vertex_(
      (vostok::render::render_geometry *)(data + 4),
      (const vostok::render::static_vertex_type *)num_vertices,
      stride,
      (unsigned int)stridea,
      (const D3D11_INPUT_ELEMENT_DESC *)3);
  }
  else
  {
    if ( v5 == 4 )
      vostok::render::create_shadow_pass_geometry_type_vostok::render::colored_static_vertex_type__vostok::render::static_render_surface::create_shadow_pass_geometry_::_3_::colored_opt_static_vertex_(
        (vostok::render::render_geometry *)(data + 4),
        (const vostok::render::static_vertex_type *)num_vertices,
        stride,
        (unsigned int)v7,
        (const D3D11_INPUT_ELEMENT_DESC *)4);
    v6 = stride;
  }
  shadow_geom_size += a5 * v6;
}
