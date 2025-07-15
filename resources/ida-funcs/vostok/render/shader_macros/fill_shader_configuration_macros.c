void __userpurge vostok::render::shader_macros::fill_shader_configuration_macros(
        vostok::fixed_vector<vostok::render::shader_macro,128> *macros@<eax>,
        vostok::render::shader_macro *a2@<ecx>,
        vostok::render::shader_macros *this,
        vostok::render::shader_configuration shader_config)
{
  vostok::render::shader_macro *v5; // ecx
  vostok::render::shader_macro *v6; // ecx
  vostok::render::shader_macro *v7; // ecx
  vostok::render::shader_macro *v8; // ecx
  vostok::render::shader_macro *v9; // ecx
  vostok::render::shader_macro *v10; // ecx
  vostok::render::shader_macro *v11; // ecx
  vostok::render::shader_macro *v12; // ecx
  vostok::render::shader_macro *v13; // ecx
  vostok::render::shader_macro *v14; // ecx
  vostok::render::shader_macro *v15; // ecx
  vostok::render::shader_macro *v16; // ecx
  vostok::render::shader_macro *v17; // ecx
  vostok::render::shader_macro *v18; // ecx
  vostok::render::shader_macro *v19; // ecx
  vostok::render::shader_macro *v20; // ecx
  vostok::render::shader_macro *v21; // ecx
  vostok::render::shader_macro *v22; // ecx
  vostok::buffer_string *v23; // ecx
  vostok::render::shader_macro *v24; // ecx
  vostok::render::shader_macro *v25; // ecx
  vostok::render::shader_macro *v26; // ecx
  vostok::render::shader_macro *v27; // ecx
  vostok::render::shader_macro *v28; // ecx
  vostok::render::shader_macro *v29; // ecx
  vostok::render::shader_macro *v30; // ecx
  vostok::render::shader_macro *v31; // ecx
  vostok::render::shader_macro *v32; // ecx
  vostok::render::shader_macro *v33; // ecx
  vostok::render::shader_macro *v34; // ecx
  vostok::render::shader_macro *v35; // ecx
  vostok::render::shader_macro *v36; // ecx
  vostok::render::shader_macro *v37; // ecx
  vostok::render::shader_macro *v38; // ecx
  vostok::render::shader_macro *v39; // ecx
  vostok::render::shader_macro *v40; // ecx
  vostok::render::shader_macro *v41; // ecx
  vostok::render::shader_macro *v42; // ecx
  vostok::render::shader_macro *v43; // ecx
  vostok::render::shader_macro *v44; // ecx
  vostok::render::shader_macro *v45; // ecx
  vostok::render::shader_macro *v46; // ecx
  vostok::render::shader_macro *v47; // ecx
  vostok::render::shader_macro *v48; // ecx
  vostok::render::shader_macro *v49; // ecx
  vostok::render::shader_macro *v50; // ecx
  vostok::render::shader_macro *v51; // ecx
  vostok::render::shader_macro *v52; // ecx
  vostok::render::shader_macro *v53; // ecx
  vostok::render::shader_macro *v54; // ecx
  vostok::render::shader_macro *v55; // ecx
  vostok::render::shader_macro *v56; // ecx
  vostok::render::shader_macro *v57; // ecx
  vostok::render::shader_macro *v58; // ecx
  vostok::render::shader_macro *v59; // ecx
  vostok::render::shader_macro *v60; // ecx
  vostok::render::shader_macro *v61; // ecx
  vostok::render::shader_macro *v62; // ecx
  vostok::render::shader_macro *v63; // ecx
  vostok::render::shader_macro *v64; // ecx
  vostok::render::shader_macro *v65; // ecx
  vostok::render::shader_macro *v66; // ecx
  vostok::buffer_vector<vostok::render::shader_macro> *v67; // [esp-4h] [ebp-234h]
  vostok::render::shader_macro value; // [esp+10h] [ebp-220h] BYREF

  vostok::render::`anonymous namespace'::add_bool_macro(macros, a2, "CONFIG_TDIFFUSE", (BYTE2(this) & 8) != 0);
  vostok::render::`anonymous namespace'::add_bool_macro(macros, v5, "CONFIG_TNORMAL", BYTE2(this) >> 7);
  vostok::render::`anonymous namespace'::add_bool_macro(macros, v6, "CONFIG_TDETAIL_NORMAL", HIBYTE(this) & 1);
  vostok::render::`anonymous namespace'::add_bool_macro(macros, v7, "CONFIG_ALPHA_TEST", (BYTE2(this) & 0x10) != 0);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    v8,
    "CONFIG_VERTEX_ALPHA_TEST",
    (BYTE2(this) & 0x20) != 0);
  vostok::render::`anonymous namespace'::add_bool_macro(macros, v9, "CONFIG_PARALLAX", (BYTE2(this) & 0x40) != 0);
  vostok::render::`anonymous namespace'::add_bool_macro(macros, v10, "CONFIG_TRANSLUCENCY", (HIBYTE(this) & 4) != 0);
  vostok::render::`anonymous namespace'::add_bool_macro(macros, v11, "CONFIG_TSPECULAR_COLOR", (HIBYTE(this) & 8) != 0);
  vostok::render::`anonymous namespace'::add_bool_macro(macros, v12, "CONFIG_TFRESNEL", (HIBYTE(this) & 0x10) != 0);
  vostok::render::`anonymous namespace'::add_bool_macro(macros, v13, "CONFIG_TROUGHNESS", (HIBYTE(this) & 0x20) != 0);
  vostok::render::`anonymous namespace'::add_u8_macro(
    v14,
    (int)macros,
    "CONFIG_EMISSIVE",
    *((_BYTE *)&shader_config.0 + 3) & 3);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    v15,
    "CONFIG_TDIFFUSE_POWER",
    (HIBYTE(this) & 0x40) != 0);
  vostok::render::`anonymous namespace'::add_bool_macro(macros, v16, "CONFIG_TDETAIL", (HIBYTE(this) & 2) != 0);
  vostok::render::`anonymous namespace'::add_bool_macro(macros, v17, "CONFIG_USE_SUBUV", HIBYTE(this) >> 7);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    v18,
    "CONFIG_TTRANSPARENCY",
    *(_BYTE *)&shader_config.0 & 1);
  vostok::render::`anonymous namespace'::add_u8_macro(
    v19,
    (int)macros,
    "CONFIG_REFLECTION",
    *((_BYTE *)&shader_config.0 + 2) >> 6);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    v20,
    "CONFIG_USE_GRASS_FRESNEL_EFFECT",
    *(_BYTE *)&shader_config.0 >> 7);
  vostok::render::`anonymous namespace'::add_u8_macro(
    v21,
    (int)macros,
    "CONFIG_LIGHT_TYPE",
    *((_BYTE *)&shader_config.0 + 1) & 0xF);
  vostok::render::shader_macro::shader_macro(v22, (int)&value);
  if ( value.name.m_string.m_begin != "CONFIG_VERTEX_INPUT_TYPE" )
  {
    value.name.m_string.m_end = value.name.m_string.m_begin;
    *value.name.m_string.m_begin = 0;
    vostok::buffer_string::operator+=(&value.name.m_string, "CONFIG_VERTEX_INPUT_TYPE");
  }
  vostok::fs_new::path_string_impl::assignf(
    &value.definition.m_begin,
    v23,
    (vostok::buffer_string *)"%d",
    (const char *)(*((_BYTE *)&shader_config.0 + 2) & 0x3F));
  vostok::buffer_vector<vostok::render::shader_macro>::push_back(v67, (int)macros, &value);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    v24,
    "CONFIG_USE_BOKEH_DOF",
    (*((_BYTE *)&shader_config.0 + 1) & 0x10) != 0);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    v25,
    "CONFIG_USE_BOKEH_IMAGE",
    (*((_BYTE *)&shader_config.0 + 1) & 0x20) != 0);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    v26,
    "CONFIG_VARIATION_MASK",
    (*(_BYTE *)&shader_config.0 & 2) != 0);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    v27,
    "CONFIG_SHADOWED_LIGHT",
    (*(_BYTE *)&shader_config.0 & 4) != 0);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    v28,
    "CONFIG_TALPHABLENDED_DIFFUSE",
    (*(_BYTE *)&shader_config.0 & 8) != 0);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    v29,
    "CONFIG_TALPHABLENDED_NORMAL",
    (*(_BYTE *)&shader_config.0 & 0x10) != 0);
  vostok::render::`anonymous namespace'::add_u8_macro(
    v30,
    (int)macros,
    "CONFIG_NUM_USED_TERRAIN_LAYERS",
    (*((_BYTE *)&shader_config.0 + 6) >> 1) & 7);
  vostok::render::`anonymous namespace'::add_u8_macro(
    v31,
    (int)macros,
    "CONFIG_USED_TERRAIN_HEIGHT_MASK",
    (*((_BYTE *)&shader_config.0 + 6) >> 4) & 7);
  vostok::render::`anonymous namespace'::add_u8_macro(
    v32,
    (int)macros,
    "CONFIG_LOD_INDEX",
    *((_BYTE *)&shader_config.0 + 7) & 7);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    v33,
    "CONFIG_USE_SPECULAR_LIGHTING",
    (*((_BYTE *)&shader_config.0 + 7) & 8) != 0);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    v34,
    "CONFIG_USE_INSTANCING",
    (*((_BYTE *)&shader_config.0 + 7) & 0x10) != 0);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    v35,
    "CONFIG_VERTEX_BLENDED_DIFFUSE",
    (*((_BYTE *)&shader_config.0 + 5) & 0x20) != 0);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    v36,
    "CONFIG_VERTEX_BLENDED_MASK",
    (*((_BYTE *)&shader_config.0 + 5) & 0x40) != 0);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    v37,
    "CONFIG_VERTEX_BLENDED_NORMAL",
    *((_BYTE *)&shader_config.0 + 5) >> 7);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    v38,
    "CONFIG_VERTEX_BLENDED_SPECULAR",
    *((_BYTE *)&shader_config.0 + 6) & 1);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    v39,
    "CONFIG_USE_INDIRECT_SPECULAR",
    *((_BYTE *)&shader_config.0 + 6) >> 7);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    v40,
    "CONFIG_USE_IMAGE_GRAIN",
    (*((_BYTE *)&shader_config.0 + 7) & 0x20) != 0);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    v41,
    "CONFIG_ENV_PROBE_GEOMETRY_TYPE",
    *((_BYTE *)&shader_config.0 + 7) >> 6);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    v42,
    "CONFIG_USE_DIFFUSE_MASKED_COLOR",
    *((_BYTE *)&shader_config.0 + 8) & 1);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    v43,
    "CONFIG_USE_DIFFUSE_MASKED_COLOR_BY_HUE",
    (*((_BYTE *)&shader_config.0 + 8) & 2) != 0);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    v44,
    "CONFIG_USE_UV_SCROLLING",
    (*((_BYTE *)&shader_config.0 + 8) & 4) != 0);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    v45,
    "CONFIG_USE_NORMAL_WAVES",
    (*((_BYTE *)&shader_config.0 + 8) & 8) != 0);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    v46,
    "CONFIG_USE_FUZZINESS",
    (*((_BYTE *)&shader_config.0 + 8) & 0x10) != 0);
  vostok::render::`anonymous namespace'::add_u8_macro(
    v47,
    (int)macros,
    "CONFIG_TERRAIN_BLEND_MODE",
    (*((_BYTE *)&shader_config.0 + 8) >> 5) & 3);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    v48,
    "CONFIG_USE_SOFT_EDGES",
    *((_BYTE *)&shader_config.0 + 8) >> 7);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    v49,
    "CONFIG_USE_THICKNESS_MAP",
    *((_BYTE *)&shader_config.0 + 9) & 1);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    v50,
    "CONFIG_USE_SUBSURFACE_SCATTERING_MASK_MAP",
    (*((_BYTE *)&shader_config.0 + 9) & 2) != 0);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    v51,
    "CONFIG_USE_DISPLACEMENT",
    (*((_BYTE *)&shader_config.0 + 9) & 8) != 0);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    v52,
    "CONFIG_USE_OLTA",
    (*((_BYTE *)&shader_config.0 + 9) & 4) != 0);
  vostok::render::`anonymous namespace'::add_u8_macro(
    v53,
    (int)macros,
    "CONFIG_WIND_MOTION",
    (*((_BYTE *)&shader_config.0 + 3) >> 2) & 7);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    v54,
    "CONFIG_DECAL_MATERIAL",
    (*((_BYTE *)&shader_config.0 + 3) & 0x20) != 0);
  vostok::render::`anonymous namespace'::add_u8_macro(
    v55,
    (int)macros,
    "CONFIG_DECAL_TYPE",
    *((_BYTE *)&shader_config.0 + 3) >> 6);
  vostok::render::`anonymous namespace'::add_u8_macro(
    v56,
    (int)macros,
    "CONFIG_POST_PROCESS_BLUR_KERNEL",
    *((_BYTE *)&shader_config.0 + 4) & 0x1F);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    v57,
    "CONFIG_TANISOTROPIC_DIRECTION",
    (*((_BYTE *)&shader_config.0 + 4) & 0x20) != 0);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    v58,
    "CONFIG_ANISOTROPIC_MATERIAL",
    (*((_BYTE *)&shader_config.0 + 4) & 0x40) != 0);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    v59,
    "CONFIG_USE_AO_TEXTURE",
    *((_BYTE *)&shader_config.0 + 4) >> 7);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    v60,
    "CONFIG_USE_ORGANIC_SCATTERING_AMOUNT_MASK",
    *((_BYTE *)&shader_config.0 + 5) & 1);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    v61,
    "CONFIG_USE_ORGANIC_SCATTERING_DEPTH_TEXTURE",
    (*((_BYTE *)&shader_config.0 + 5) & 2) != 0);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    v62,
    "CONFIG_USE_ORGANIC_BACK_ILLUMINATION_TEXTURE",
    (*((_BYTE *)&shader_config.0 + 5) & 4) != 0);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    v63,
    "CONFIG_USE_ORGANIC_SUBDERMAL_TEXTURE",
    (*((_BYTE *)&shader_config.0 + 5) & 8) != 0);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    v64,
    "CONFIG_SEQUENCE",
    (*(_BYTE *)&shader_config.0 & 0x20) != 0);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    v65,
    "CONFIG_REFLECTION_MASK",
    (*(_BYTE *)&shader_config.0 & 0x40) != 0);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    v66,
    "CONFIG_LOCAL_REFLECTIONS",
    (*((_BYTE *)&shader_config.0 + 5) & 0x10) != 0);
}
