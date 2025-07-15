void __cdecl vostok::render::modify_shader_configuration(
        vostok::render::shader_configuration *out_shader_config,
        char *shader_name,
        char *shader_type_str)
{
  vostok::configs::binary_config_value *v3; // ecx
  vostok::render::options *v4; // esi
  char m_post_process_quality; // dl
  vostok::configs::binary_config_value *m_root; // esi
  const vostok::configs::binary_config_value *v7; // eax
  vostok::configs::binary_config_value *v8; // ecx
  vostok::configs::binary_config_value *v9; // eax
  const vostok::configs::binary_config_value *v10; // eax
  const char **pointer; // ecx
  int v12; // esi
  vostok::render::shader_configuration v13; // [esp+98h] [ebp+58h]
  const char **v14; // [esp+B8h] [ebp+78h]

  if ( shader_name )
  {
    if ( shader_type_str )
    {
      v4 = vostok::quasi_singleton<vostok::render::options>::pinst;
      m_post_process_quality = vostok::quasi_singleton<vostok::render::options>::pinst->current.m_post_process_quality;
      *(_BYTE *)&out_shader_config->0 = *(_BYTE *)&out_shader_config->0 & 0xC0
                                      | vostok::quasi_singleton<vostok::render::options>::pinst->current.m_shadow_quality
                                      & 7
                                      | (8
                                       * (vostok::quasi_singleton<vostok::render::options>::pinst->current.m_lighting_quality
                                        & 7));
      *((_BYTE *)&out_shader_config->0 + 1) = *((_BYTE *)&out_shader_config->0 + 1) & 0xC0
                                            | m_post_process_quality & 7
                                            | (8 * (v4->current.m_shading_quality & 7));
      LOBYTE(v3) = (*((_BYTE *)&out_shader_config->0 + 2) ^ LOBYTE(v4->current.m_particles_quality)) & 7;
      *((_BYTE *)&out_shader_config->0 + 2) ^= (unsigned __int8)v3;
      v13 = *out_shader_config;
      m_root = vostok::quasi_singleton<vostok::render::resource_manager>::pinst->shader_name_to_mask_config.m_object->m_root;
      if ( vostok::configs::binary_config_value::value_exists(v3, (int)m_root, (unsigned int)shader_name) )
      {
        v7 = vostok::configs::binary_config_value::operator[](m_root, shader_name);
        if ( vostok::configs::binary_config_value::value_exists(v8, (int)v7, (unsigned int)shader_type_str) )
        {
          v9 = vostok::configs::binary_config_value::operator[](m_root, shader_name);
          v10 = vostok::configs::binary_config_value::operator[](v9, shader_type_str);
          pointer = (const char **)v10->data.pointer;
          v12 = (int)v10->data.pointer + 24 * v10->count;
          v14 = (const char **)v10->data.pointer;
          if ( 24 * v10->count / 24 )
          {
            LODWORD(out_shader_config->configuration[1]) = 0;
            out_shader_config->configuration[0] = 0;
            HIDWORD(out_shader_config->configuration[1]) = 0;
            *((_BYTE *)&out_shader_config->0 + 10) = *((_BYTE *)&out_shader_config->0 + 10) & 0xF1 | 8;
            if ( pointer != (const char **)v12 )
            {
              while ( 1 )
              {
                vostok::render::shader_configuration::merge_with(out_shader_config, *pointer, v13);
                v14 += 6;
                if ( v14 == (const char **)v12 )
                  break;
                pointer = v14;
              }
            }
          }
        }
      }
    }
  }
}
