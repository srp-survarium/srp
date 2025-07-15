void __userpurge vostok::render::shader_configuration::merge_with(
        vostok::render::shader_configuration *this@<esi>,
        const char *macros_name@<edi>,
        vostok::render::shader_configuration other_config)
{
  char v3; // al
  char v4; // al
  char v5; // al
  char v6; // al
  char v7; // al
  char v8; // al
  char v9; // al
  char v10; // al
  char v11; // al
  char v12; // al
  char v13; // al
  char v14; // al
  char v15; // al

  if ( !vostok::strings::compare(macros_name, "GLOBAL_SHADOWMAP_QUALITY") )
  {
    v3 = (*(_BYTE *)&other_config.0 ^ *(_BYTE *)&this->0) & 7;
LABEL_5:
    *(_BYTE *)&this->0 ^= v3;
    return;
  }
  if ( !vostok::strings::compare(macros_name, "GLOBAL_LIGHTING_QUALITY") )
  {
    v3 = (*(_BYTE *)&other_config.0 ^ *(_BYTE *)&this->0) & 0x38;
    goto LABEL_5;
  }
  if ( !vostok::strings::compare(macros_name, "GLOBAL_POST_PROCESS_QUALITY") )
  {
    v4 = (*((_BYTE *)&other_config.0 + 1) ^ *((_BYTE *)&this->0 + 1)) & 7;
LABEL_10:
    *((_BYTE *)&this->0 + 1) ^= v4;
    return;
  }
  if ( !vostok::strings::compare(macros_name, "GLOBAL_SHADING_QUALITY") )
  {
    v4 = (*((_BYTE *)&other_config.0 + 1) ^ *((_BYTE *)&this->0 + 1)) & 0x38;
    goto LABEL_10;
  }
  if ( !vostok::strings::compare(macros_name, "GLOBAL_PARTICLE_QUALITY") )
  {
    v5 = (*((_BYTE *)&other_config.0 + 2) ^ *((_BYTE *)&this->0 + 2)) & 7;
LABEL_21:
    *((_BYTE *)&this->0 + 2) ^= v5;
    return;
  }
  if ( !vostok::strings::compare(macros_name, "CONFIG_TDIFFUSE") )
  {
    v5 = (*((_BYTE *)&other_config.0 + 2) ^ *((_BYTE *)&this->0 + 2)) & 8;
    goto LABEL_21;
  }
  if ( !vostok::strings::compare(macros_name, "CONFIG_ALPHA_TEST") )
  {
    v5 = (*((_BYTE *)&other_config.0 + 2) ^ *((_BYTE *)&this->0 + 2)) & 0x10;
    goto LABEL_21;
  }
  if ( !vostok::strings::compare(macros_name, "CONFIG_VERTEX_ALPHA_TEST") )
  {
    v5 = (*((_BYTE *)&other_config.0 + 2) ^ *((_BYTE *)&this->0 + 2)) & 0x20;
    goto LABEL_21;
  }
  if ( !vostok::strings::compare(macros_name, "CONFIG_PARALLAX") )
  {
    v5 = (*((_BYTE *)&other_config.0 + 2) ^ *((_BYTE *)&this->0 + 2)) & 0x40;
    goto LABEL_21;
  }
  if ( !vostok::strings::compare(macros_name, "CONFIG_TNORMAL") )
  {
    *((_BYTE *)&this->0 + 2) = *((_BYTE *)&other_config.0 + 2)
                             ^ (*((_BYTE *)&other_config.0 + 2)
                              ^ *((_BYTE *)&this->0 + 2))
                             & 0x7F;
    return;
  }
  if ( !vostok::strings::compare(macros_name, "CONFIG_TDETAIL_NORMAL") )
  {
    v6 = (*((_BYTE *)&other_config.0 + 3) ^ *((_BYTE *)&this->0 + 3)) & 1;
LABEL_38:
    *((_BYTE *)&this->0 + 3) ^= v6;
    return;
  }
  if ( !vostok::strings::compare(macros_name, "CONFIG_TDETAIL") )
  {
    v6 = (*((_BYTE *)&other_config.0 + 3) ^ *((_BYTE *)&this->0 + 3)) & 2;
    goto LABEL_38;
  }
  if ( !vostok::strings::compare(macros_name, "CONFIG_TRANSLUCENCY") )
  {
    v6 = (*((_BYTE *)&other_config.0 + 3) ^ *((_BYTE *)&this->0 + 3)) & 4;
    goto LABEL_38;
  }
  if ( !vostok::strings::compare(macros_name, "CONFIG_TSPECULAR_COLOR") )
  {
    v6 = (*((_BYTE *)&other_config.0 + 3) ^ *((_BYTE *)&this->0 + 3)) & 8;
    goto LABEL_38;
  }
  if ( !vostok::strings::compare(macros_name, "CONFIG_TFRESNEL") )
  {
    v6 = (*((_BYTE *)&other_config.0 + 3) ^ *((_BYTE *)&this->0 + 3)) & 0x10;
    goto LABEL_38;
  }
  if ( !vostok::strings::compare(macros_name, "CONFIG_TROUGHNESS") )
  {
    v6 = (*((_BYTE *)&other_config.0 + 3) ^ *((_BYTE *)&this->0 + 3)) & 0x20;
    goto LABEL_38;
  }
  if ( !vostok::strings::compare(macros_name, "CONFIG_TDIFFUSE_POWER") )
  {
    v6 = (*((_BYTE *)&other_config.0 + 3) ^ *((_BYTE *)&this->0 + 3)) & 0x40;
    goto LABEL_38;
  }
  if ( !vostok::strings::compare(macros_name, "CONFIG_USE_SUBUV") )
  {
    *((_BYTE *)&this->0 + 3) = *((_BYTE *)&other_config.0 + 3)
                             ^ (*((_BYTE *)&other_config.0 + 3)
                              ^ *((_BYTE *)&this->0 + 3))
                             & 0x7F;
    return;
  }
  if ( !vostok::strings::compare(macros_name, "CONFIG_TTRANSPARENCY") )
  {
    v7 = (*((_BYTE *)&other_config.0 + 4) ^ *((_BYTE *)&this->0 + 4)) & 1;
LABEL_55:
    *((_BYTE *)&this->0 + 4) ^= v7;
    return;
  }
  if ( !vostok::strings::compare(macros_name, "CONFIG_VARIATION_MASK") )
  {
    v7 = (*((_BYTE *)&other_config.0 + 4) ^ *((_BYTE *)&this->0 + 4)) & 2;
    goto LABEL_55;
  }
  if ( !vostok::strings::compare(macros_name, "CONFIG_SHADOWED_LIGHT") )
  {
    v7 = (*((_BYTE *)&other_config.0 + 4) ^ *((_BYTE *)&this->0 + 4)) & 4;
    goto LABEL_55;
  }
  if ( !vostok::strings::compare(macros_name, "CONFIG_TALPHABLENDED_DIFFUSE") )
  {
    v7 = (*((_BYTE *)&other_config.0 + 4) ^ *((_BYTE *)&this->0 + 4)) & 8;
    goto LABEL_55;
  }
  if ( !vostok::strings::compare(macros_name, "CONFIG_TALPHABLENDED_NORMAL") )
  {
    v7 = (*((_BYTE *)&other_config.0 + 4) ^ *((_BYTE *)&this->0 + 4)) & 0x10;
    goto LABEL_55;
  }
  if ( !vostok::strings::compare(macros_name, "CONFIG_SEQUENCE") )
  {
    v7 = (*((_BYTE *)&other_config.0 + 4) ^ *((_BYTE *)&this->0 + 4)) & 0x20;
    goto LABEL_55;
  }
  if ( !vostok::strings::compare(macros_name, "CONFIG_REFLECTION_MASK") )
  {
    v7 = (*((_BYTE *)&other_config.0 + 4) ^ *((_BYTE *)&this->0 + 4)) & 0x40;
    goto LABEL_55;
  }
  if ( !vostok::strings::compare(macros_name, "CONFIG_USE_GRASS_FRESNEL_EFFECT") )
  {
    *((_BYTE *)&this->0 + 4) = *((_BYTE *)&other_config.0 + 4)
                             ^ (*((_BYTE *)&other_config.0 + 4)
                              ^ *((_BYTE *)&this->0 + 4))
                             & 0x7F;
    return;
  }
  if ( !vostok::strings::compare(macros_name, "CONFIG_LIGHT_TYPE") )
  {
    v8 = (*((_BYTE *)&other_config.0 + 5) ^ *((_BYTE *)&this->0 + 5)) & 0xF;
LABEL_64:
    *((_BYTE *)&this->0 + 5) ^= v8;
    return;
  }
  if ( !vostok::strings::compare(macros_name, "CONFIG_USE_BOKEH_DOF") )
  {
    v8 = (*((_BYTE *)&other_config.0 + 5) ^ *((_BYTE *)&this->0 + 5)) & 0x10;
    goto LABEL_64;
  }
  if ( !vostok::strings::compare(macros_name, "CONFIG_USE_BOKEH_IMAGE") )
  {
    v8 = (*((_BYTE *)&other_config.0 + 5) ^ *((_BYTE *)&this->0 + 5)) & 0x20;
    goto LABEL_64;
  }
  if ( !vostok::strings::compare(macros_name, "CONFIG_VERTEX_INPUT_TYPE") )
  {
    *((_BYTE *)&this->0 + 6) ^= (*((_BYTE *)&other_config.0 + 6) ^ *((_BYTE *)&this->0 + 6)) & 0x3F;
    return;
  }
  if ( !vostok::strings::compare(macros_name, "CONFIG_REFLECTION") )
  {
    *((_BYTE *)&this->0 + 6) = *((_BYTE *)&other_config.0 + 6)
                             ^ (*((_BYTE *)&other_config.0 + 6)
                              ^ *((_BYTE *)&this->0 + 6))
                             & 0x3F;
    return;
  }
  if ( !vostok::strings::compare(macros_name, "CONFIG_EMISSIVE") )
  {
    v9 = (*((_BYTE *)&other_config.0 + 7) ^ *((_BYTE *)&this->0 + 7)) & 3;
LABEL_75:
    *((_BYTE *)&this->0 + 7) ^= v9;
    return;
  }
  if ( !vostok::strings::compare(macros_name, "CONFIG_WIND_MOTION") )
  {
    v9 = (*((_BYTE *)&other_config.0 + 7) ^ *((_BYTE *)&this->0 + 7)) & 0x1C;
    goto LABEL_75;
  }
  if ( !vostok::strings::compare(macros_name, "CONFIG_DECAL_MATERIAL") )
  {
    v9 = (*((_BYTE *)&other_config.0 + 7) ^ *((_BYTE *)&this->0 + 7)) & 0x20;
    goto LABEL_75;
  }
  if ( !vostok::strings::compare(macros_name, "CONFIG_DECAL_TYPE") )
  {
    *((_BYTE *)&this->0 + 7) = *((_BYTE *)&other_config.0 + 7)
                             ^ (*((_BYTE *)&other_config.0 + 7)
                              ^ *((_BYTE *)&this->0 + 7))
                             & 0x3F;
    return;
  }
  if ( !vostok::strings::compare(macros_name, "CONFIG_POST_PROCESS_BLUR_KERNEL") )
  {
    v10 = (*((_BYTE *)&other_config.0 + 8) ^ *((_BYTE *)&this->0 + 8)) & 0x1F;
LABEL_84:
    *((_BYTE *)&this->0 + 8) ^= v10;
    return;
  }
  if ( !vostok::strings::compare(macros_name, "CONFIG_TANISOTROPIC_DIRECTION") )
  {
    v10 = (*((_BYTE *)&other_config.0 + 8) ^ *((_BYTE *)&this->0 + 8)) & 0x20;
    goto LABEL_84;
  }
  if ( !vostok::strings::compare(macros_name, "CONFIG_ANISOTROPIC_MATERIAL") )
  {
    v10 = (*((_BYTE *)&other_config.0 + 8) ^ *((_BYTE *)&this->0 + 8)) & 0x40;
    goto LABEL_84;
  }
  if ( !vostok::strings::compare(macros_name, "CONFIG_USE_AO_TEXTURE") )
  {
    *((_BYTE *)&this->0 + 8) = *((_BYTE *)&other_config.0 + 8)
                             ^ (*((_BYTE *)&other_config.0 + 8)
                              ^ *((_BYTE *)&this->0 + 8))
                             & 0x7F;
    return;
  }
  if ( !vostok::strings::compare(macros_name, "CONFIG_USE_ORGANIC_SCATTERING_AMOUNT_MASK") )
  {
    v11 = (*((_BYTE *)&other_config.0 + 9) ^ *((_BYTE *)&this->0 + 9)) & 1;
LABEL_101:
    *((_BYTE *)&this->0 + 9) ^= v11;
    return;
  }
  if ( !vostok::strings::compare(macros_name, "CONFIG_USE_ORGANIC_SCATTERING_DEPTH_TEXTURE") )
  {
    v11 = (*((_BYTE *)&other_config.0 + 9) ^ *((_BYTE *)&this->0 + 9)) & 2;
    goto LABEL_101;
  }
  if ( !vostok::strings::compare(macros_name, "CONFIG_USE_ORGANIC_BACK_ILLUMINATION_TEXTURE") )
  {
    v11 = (*((_BYTE *)&other_config.0 + 9) ^ *((_BYTE *)&this->0 + 9)) & 4;
    goto LABEL_101;
  }
  if ( !vostok::strings::compare(macros_name, "CONFIG_USE_ORGANIC_SUBDERMAL_TEXTURE") )
  {
    v11 = (*((_BYTE *)&other_config.0 + 9) ^ *((_BYTE *)&this->0 + 9)) & 8;
    goto LABEL_101;
  }
  if ( !vostok::strings::compare(macros_name, "CONFIG_LOCAL_REFLECTIONS") )
  {
    v11 = (*((_BYTE *)&other_config.0 + 9) ^ *((_BYTE *)&this->0 + 9)) & 0x10;
    goto LABEL_101;
  }
  if ( !vostok::strings::compare(macros_name, "CONFIG_VERTEX_BLENDED_DIFFUSE") )
  {
    v11 = (*((_BYTE *)&other_config.0 + 9) ^ *((_BYTE *)&this->0 + 9)) & 0x20;
    goto LABEL_101;
  }
  if ( !vostok::strings::compare(macros_name, "CONFIG_VERTEX_BLENDED_MASK") )
  {
    v11 = (*((_BYTE *)&other_config.0 + 9) ^ *((_BYTE *)&this->0 + 9)) & 0x40;
    goto LABEL_101;
  }
  if ( !vostok::strings::compare(macros_name, "CONFIG_VERTEX_BLENDED_NORMAL") )
  {
    *((_BYTE *)&this->0 + 9) = *((_BYTE *)&other_config.0 + 9)
                             ^ (*((_BYTE *)&other_config.0 + 9)
                              ^ *((_BYTE *)&this->0 + 9))
                             & 0x7F;
    return;
  }
  if ( !vostok::strings::compare(macros_name, "CONFIG_VERTEX_BLENDED_SPECULAR") )
  {
    v12 = (*((_BYTE *)&other_config.0 + 10) ^ *((_BYTE *)&this->0 + 10)) & 1;
LABEL_110:
    *((_BYTE *)&this->0 + 10) ^= v12;
    return;
  }
  if ( !vostok::strings::compare(macros_name, "CONFIG_NUM_USED_TERRAIN_LAYERS") )
  {
    v12 = (*((_BYTE *)&other_config.0 + 10) ^ *((_BYTE *)&this->0 + 10)) & 0xE;
    goto LABEL_110;
  }
  if ( !vostok::strings::compare(macros_name, "CONFIG_USED_TERRAIN_HEIGHT_MASK") )
  {
    v12 = (*((_BYTE *)&other_config.0 + 10) ^ *((_BYTE *)&this->0 + 10)) & 0x70;
    goto LABEL_110;
  }
  if ( !vostok::strings::compare(macros_name, "CONFIG_USE_INDIRECT_SPECULAR") )
  {
    *((_BYTE *)&this->0 + 10) = *((_BYTE *)&other_config.0 + 10)
                              ^ (*((_BYTE *)&other_config.0 + 10)
                               ^ *((_BYTE *)&this->0 + 10))
                              & 0x7F;
    return;
  }
  if ( !vostok::strings::compare(macros_name, "CONFIG_LOD_INDEX") )
  {
    v13 = (*((_BYTE *)&other_config.0 + 11) ^ *((_BYTE *)&this->0 + 11)) & 7;
LABEL_121:
    *((_BYTE *)&this->0 + 11) ^= v13;
    return;
  }
  if ( !vostok::strings::compare(macros_name, "CONFIG_USE_SPECULAR_LIGHTING") )
  {
    v13 = (*((_BYTE *)&other_config.0 + 11) ^ *((_BYTE *)&this->0 + 11)) & 8;
    goto LABEL_121;
  }
  if ( !vostok::strings::compare(macros_name, "CONFIG_USE_INSTANCING") )
  {
    v13 = (*((_BYTE *)&other_config.0 + 11) ^ *((_BYTE *)&this->0 + 11)) & 0x10;
    goto LABEL_121;
  }
  if ( !vostok::strings::compare(macros_name, "CONFIG_USE_IMAGE_GRAIN") )
  {
    v13 = (*((_BYTE *)&other_config.0 + 11) ^ *((_BYTE *)&this->0 + 11)) & 0x20;
    goto LABEL_121;
  }
  if ( !vostok::strings::compare(macros_name, "CONFIG_ENV_PROBE_GEOMETRY_TYPE") )
  {
    *((_BYTE *)&this->0 + 11) = *((_BYTE *)&other_config.0 + 11)
                              ^ (*((_BYTE *)&other_config.0 + 11)
                               ^ *((_BYTE *)&this->0 + 11))
                              & 0x3F;
    return;
  }
  if ( !vostok::strings::compare(macros_name, "CONFIG_USE_DIFFUSE_MASKED_COLOR") )
  {
    v14 = (*((_BYTE *)&other_config.0 + 12) ^ *((_BYTE *)&this->0 + 12)) & 1;
LABEL_136:
    *((_BYTE *)&this->0 + 12) ^= v14;
    return;
  }
  if ( !vostok::strings::compare(macros_name, "CONFIG_USE_DIFFUSE_MASKED_COLOR_BY_HUE") )
  {
    v14 = (*((_BYTE *)&other_config.0 + 12) ^ *((_BYTE *)&this->0 + 12)) & 2;
    goto LABEL_136;
  }
  if ( !vostok::strings::compare(macros_name, "CONFIG_USE_UV_SCROLLING") )
  {
    v14 = (*((_BYTE *)&other_config.0 + 12) ^ *((_BYTE *)&this->0 + 12)) & 4;
    goto LABEL_136;
  }
  if ( !vostok::strings::compare(macros_name, "CONFIG_USE_NORMAL_WAVES") )
  {
    v14 = (*((_BYTE *)&other_config.0 + 12) ^ *((_BYTE *)&this->0 + 12)) & 8;
    goto LABEL_136;
  }
  if ( !vostok::strings::compare(macros_name, "CONFIG_USE_FUZZINESS") )
  {
    v14 = (*((_BYTE *)&other_config.0 + 12) ^ *((_BYTE *)&this->0 + 12)) & 0x10;
    goto LABEL_136;
  }
  if ( !vostok::strings::compare(macros_name, "CONFIG_TERRAIN_BLEND_MODE") )
  {
    v14 = (*((_BYTE *)&other_config.0 + 12) ^ *((_BYTE *)&this->0 + 12)) & 0x60;
    goto LABEL_136;
  }
  if ( !vostok::strings::compare(macros_name, "CONFIG_USE_SOFT_EDGES") )
  {
    *((_BYTE *)&this->0 + 12) = *((_BYTE *)&other_config.0 + 12)
                              ^ (*((_BYTE *)&other_config.0 + 12)
                               ^ *((_BYTE *)&this->0 + 12))
                              & 0x7F;
    return;
  }
  if ( vostok::strings::compare(macros_name, "CONFIG_USE_THICKNESS_MAP") )
  {
    if ( vostok::strings::compare(macros_name, "CONFIG_USE_SUBSURFACE_SCATTERING_MASK_MAP") )
    {
      if ( vostok::strings::compare(macros_name, "CONFIG_USE_OLTA") )
      {
        if ( vostok::strings::compare(macros_name, "CONFIG_USE_DISPLACEMENT") )
          return;
        v15 = (*((_BYTE *)&other_config.0 + 13) ^ *((_BYTE *)&this->0 + 13)) & 8;
      }
      else
      {
        v15 = (*((_BYTE *)&other_config.0 + 13) ^ *((_BYTE *)&this->0 + 13)) & 4;
      }
    }
    else
    {
      v15 = (*((_BYTE *)&other_config.0 + 13) ^ *((_BYTE *)&this->0 + 13)) & 2;
    }
  }
  else
  {
    v15 = (*((_BYTE *)&other_config.0 + 13) ^ *((_BYTE *)&this->0 + 13)) & 1;
  }
  *((_BYTE *)&this->0 + 13) ^= v15;
}
