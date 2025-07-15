void __userpurge vostok::render::shader_macros::fill_shader_configuration_macros(
        vostok::fixed_vector<vostok::render::shader_macro,128> *macros@<eax>,
        vostok::render::shader_macros *this,
        vostok::render::shader_configuration shader_config)
{
  vostok::render::`anonymous namespace'::add_bool_macro(macros, "GLOBAL_MASTER_GOLD", 1);
  vostok::render::`anonymous namespace'::add_bool_macro(macros, "CONFIG_TDIFFUSE", (unsigned __int8)this & 1);
  vostok::render::`anonymous namespace'::add_bool_macro(macros, "CONFIG_TNORMAL", ((unsigned __int8)this & 8) != 0);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    "CONFIG_TDETAIL_NORMAL",
    ((unsigned __int8)this & 0x10) != 0);
  vostok::render::`anonymous namespace'::add_bool_macro(macros, "CONFIG_ALPHA_TEST", ((unsigned __int8)this & 2) != 0);
  vostok::render::`anonymous namespace'::add_bool_macro(macros, "CONFIG_PARALLAX", ((unsigned __int8)this & 4) != 0);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    "CONFIG_TRANSLUCENCY",
    ((unsigned __int8)this & 0x40) != 0);
  vostok::render::`anonymous namespace'::add_bool_macro(macros, "CONFIG_TSPECULAR_COLOR", (unsigned __int8)this >> 7);
  vostok::render::`anonymous namespace'::add_bool_macro(macros, "CONFIG_TFRESNEL", BYTE1(this) & 1);
  vostok::render::`anonymous namespace'::add_bool_macro(macros, "CONFIG_TROUGHNESS", (BYTE1(this) & 2) != 0);
  vostok::render::`anonymous namespace'::add_u8_macro(macros, "CONFIG_EMISSIVE", (*(_BYTE *)&shader_config.0 >> 2) & 3);
  vostok::render::`anonymous namespace'::add_bool_macro(macros, "CONFIG_TDIFFUSE_POWER", (BYTE1(this) & 4) != 0);
  vostok::render::`anonymous namespace'::add_bool_macro(macros, "CONFIG_TDETAIL", ((unsigned __int8)this & 0x20) != 0);
  vostok::render::`anonymous namespace'::add_bool_macro(macros, "CONFIG_USE_SUBUV", (BYTE1(this) & 8) != 0);
  vostok::render::`anonymous namespace'::add_bool_macro(macros, "CONFIG_TTRANSPARENCY", (BYTE1(this) & 0x10) != 0);
  vostok::render::`anonymous namespace'::add_u8_macro(macros, "CONFIG_REFLECTION", *(_BYTE *)&shader_config.0 & 3);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    "CONFIG_USE_GRASS_FRESNEL_EFFECT",
    (BYTE2(this) & 8) != 0);
  vostok::render::`anonymous namespace'::add_u8_macro(macros, "CONFIG_LIGHT_TYPE", BYTE2(this) >> 4);
  vostok::render::`anonymous namespace'::add_u8_macro(macros, "CONFIG_VERTEX_INPUT_TYPE", HIBYTE(this) >> 2);
  vostok::render::`anonymous namespace'::add_bool_macro(macros, "CONFIG_USE_BOKEH_DOF", HIBYTE(this) & 1);
  vostok::render::`anonymous namespace'::add_bool_macro(macros, "CONFIG_USE_BOKEH_IMAGE", (HIBYTE(this) & 2) != 0);
  vostok::render::`anonymous namespace'::add_bool_macro(macros, "CONFIG_VARIATION_MASK", (BYTE1(this) & 0x20) != 0);
  vostok::render::`anonymous namespace'::add_bool_macro(macros, "CONFIG_SHADOWED_LIGHT", (BYTE1(this) & 0x40) != 0);
  vostok::render::`anonymous namespace'::add_bool_macro(macros, "CONFIG_TALPHABLENDED_DIFFUSE", BYTE1(this) >> 7);
  vostok::render::`anonymous namespace'::add_bool_macro(macros, "CONFIG_TALPHABLENDED_NORMAL", BYTE2(this) & 1);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    "CONFIG_USE_BOUND_NORMALS",
    (*((_BYTE *)&shader_config.0 + 2) & 0x40) != 0);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    "CONFIG_USE_UP_DIRECTIONAL_NORMALS",
    *((_BYTE *)&shader_config.0 + 2) >> 7);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    "CONFIG_USE_DIFFUSE_AS_SPECULAR",
    (*((_BYTE *)&shader_config.0 + 3) & 2) != 0);
  vostok::render::`anonymous namespace'::add_u8_macro(
    macros,
    "CONFIG_NUM_USED_TERRAIN_LAYERS",
    *((_BYTE *)&shader_config.0 + 4) & 7);
  vostok::render::`anonymous namespace'::add_u8_macro(
    macros,
    "CONFIG_USED_TERRAIN_HEIGHT_MASK",
    (*((_BYTE *)&shader_config.0 + 4) >> 3) & 7);
  vostok::render::`anonymous namespace'::add_u8_macro(macros, "CONFIG_LOD_INDEX", *((_BYTE *)&shader_config.0 + 5) & 7);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    "CONFIG_USE_SPECULAR_LIGHTING",
    (*((_BYTE *)&shader_config.0 + 5) & 8) != 0);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    "CONFIG_VERTEX_BLENDED_DIFFUSE",
    (*((_BYTE *)&shader_config.0 + 3) & 4) != 0);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    "CONFIG_VERTEX_BLENDED_MASK",
    (*((_BYTE *)&shader_config.0 + 3) & 8) != 0);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    "CONFIG_VERTEX_BLENDED_NORMAL",
    (*((_BYTE *)&shader_config.0 + 3) & 0x10) != 0);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    "CONFIG_VERTEX_BLENDED_SPECULAR",
    (*((_BYTE *)&shader_config.0 + 3) & 0x20) != 0);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    "CONFIG_USE_INDIRECT_SPECULAR",
    (*((_BYTE *)&shader_config.0 + 4) & 0x40) != 0);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    "CONFIG_USE_IMAGE_GRAIN",
    (*((_BYTE *)&shader_config.0 + 5) & 0x10) != 0);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    "CONFIG_ENV_PROBE_CLIP_BY_NORMAL",
    (*((_BYTE *)&shader_config.0 + 5) & 0x20) != 0);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    "CONFIG_ENV_PROBE_WITH_SHADOWS",
    (*((_BYTE *)&shader_config.0 + 5) & 0x40) != 0);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    "CONFIG_ENV_PROBE_GEOMETRY_TYPE",
    *((_BYTE *)&shader_config.0 + 6) & 3);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    "CONFIG_USE_DIFFUSE_MASKED_COLOR",
    (*((_BYTE *)&shader_config.0 + 6) & 4) != 0);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    "CONFIG_USE_DIFFUSE_MASKED_COLOR_BY_HUE",
    (*((_BYTE *)&shader_config.0 + 6) & 8) != 0);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    "CONFIG_USE_UV_SCROLLING",
    (*((_BYTE *)&shader_config.0 + 6) & 0x10) != 0);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    "CONFIG_USE_NORMAL_WAVES",
    (*((_BYTE *)&shader_config.0 + 6) & 0x20) != 0);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    "CONFIG_USE_FUZZINESS",
    (*((_BYTE *)&shader_config.0 + 6) & 0x40) != 0);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    "CONFIG_TERRAIN_BLEND_MODE",
    (*((_BYTE *)&shader_config.0 + 7) & 3) != 0);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    "CONFIG_USE_SOFT_EDGES",
    (*((_BYTE *)&shader_config.0 + 7) & 4) != 0);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    "CONFIG_USE_THICKNESS_MAP",
    (*((_BYTE *)&shader_config.0 + 7) & 8) != 0);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    "CONFIG_USE_SUBSURFACE_SCATTERING_MASK_MAP",
    (*((_BYTE *)&shader_config.0 + 7) & 0x10) != 0);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    "CONFIG_USE_OLTA",
    (*((_BYTE *)&shader_config.0 + 7) & 0x20) != 0);
  vostok::render::`anonymous namespace'::add_u8_macro(
    macros,
    "CONFIG_WIND_MOTION",
    (*(_BYTE *)&shader_config.0 >> 4) & 7);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    "CONFIG_DECAL_MATERIAL",
    *(_BYTE *)&shader_config.0 >> 7);
  vostok::render::`anonymous namespace'::add_u8_macro(macros, "CONFIG_DECAL_TYPE", *((_BYTE *)&shader_config.0 + 1) & 3);
  vostok::render::`anonymous namespace'::add_u8_macro(
    macros,
    "CONFIG_POST_PROCESS_BLUR_KERNEL",
    (*((_BYTE *)&shader_config.0 + 1) >> 2) & 0x1F);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    "CONFIG_TANISOTROPIC_DIRECTION",
    *((_BYTE *)&shader_config.0 + 1) >> 7);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    "CONFIG_ANISOTROPIC_MATERIAL",
    *((_BYTE *)&shader_config.0 + 2) & 1);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    "CONFIG_USE_AO_TEXTURE",
    (*((_BYTE *)&shader_config.0 + 2) & 2) != 0);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    "CONFIG_USE_ORGANIC_SCATTERING_AMOUNT_MASK",
    (*((_BYTE *)&shader_config.0 + 2) & 4) != 0);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    "CONFIG_USE_ORGANIC_SCATTERING_DEPTH_TEXTURE",
    (*((_BYTE *)&shader_config.0 + 2) & 8) != 0);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    "CONFIG_USE_ORGANIC_BACK_ILLUMINATION_TEXTURE",
    (*((_BYTE *)&shader_config.0 + 2) & 0x10) != 0);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    "CONFIG_USE_ORGANIC_SUBDERMAL_TEXTURE",
    (*((_BYTE *)&shader_config.0 + 2) & 0x20) != 0);
  vostok::render::`anonymous namespace'::add_bool_macro(macros, "CONFIG_SEQUENCE", (BYTE2(this) & 2) != 0);
  vostok::render::`anonymous namespace'::add_bool_macro(macros, "CONFIG_REFLECTION_MASK", (BYTE2(this) & 4) != 0);
  vostok::render::`anonymous namespace'::add_bool_macro(
    macros,
    "CONFIG_LOCAL_REFLECTIONS",
    *((_BYTE *)&shader_config.0 + 3) & 1);
}
