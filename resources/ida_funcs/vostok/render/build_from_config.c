void __usercall vostok::render::build_from_config(
        vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *cfg@<eax>,
        vostok::render::skeleton_combined_cook_data *cook_data@<edi>)
{
  const char **v2; // eax
  const char **v3; // eax
  int v4; // ecx
  int v5; // ebx
  vostok::fs_new::virtual_path_string *p_part_name; // esi
  char *pointer; // eax
  unsigned __int64 v8; // xmm0_8
  char *v9; // eax
  char *v10; // eax
  char *m_begin; // ecx
  char *m_end; // ecx
  char *v13; // eax
  char *v14; // ecx
  char *v15; // ecx
  unsigned int part_idx; // [esp+4h] [ebp-34h]
  vostok::configs::binary_config_value root; // [esp+8h] [ebp-30h] BYREF
  vostok::configs::binary_config_value current; // [esp+20h] [ebp-18h] BYREF

  root = *cfg->m_object->m_root;
  v2 = (const char **)vostok::configs::binary_config_value::operator[](&root, "skeleton");
  vostok::fs_new::path_string_impl::assignf(&cook_data->skeleton_name, "resources/animations/%s", *v2);
  v3 = (const char **)vostok::configs::binary_config_value::operator[](&root, "bind_pose");
  vostok::fs_new::path_string_impl::assignf(
    &cook_data->bind_pose_name,
    "resources/models/%s.skinned_model/render/bind_pose",
    *v3);
  v4 = 24 * vostok::configs::binary_config_value::operator[](&root, "parts")->count;
  v5 = 0;
  cook_data->models_count = v4 / 24;
  part_idx = 0;
  if ( (unsigned __int8)(v4 / 24) )
  {
    p_part_name = &cook_data->model_defs[0].part_name;
    do
    {
      pointer = (char *)vostok::configs::binary_config_value::operator[](&root, "parts")->data.pointer;
      v8 = *(_QWORD *)&pointer[v5];
      v9 = &pointer[v5];
      current.data.max_storage = v8;
      current.id.max_storage = *((_QWORD *)v9 + 1);
      *(_QWORD *)&current.id_crc = *((_QWORD *)v9 + 2);
      v10 = (char *)vostok::configs::binary_config_value::operator[](&current, "part_name")->data.pointer;
      m_begin = p_part_name->m_string.m_begin;
      if ( p_part_name->m_string.m_begin != v10 )
      {
        p_part_name->m_string.m_end = m_begin;
        *m_begin = 0;
        if ( v10 )
        {
          for ( ; *v10; ++v10 )
          {
            m_end = p_part_name->m_string.m_end;
            if ( m_end >= p_part_name->m_string.m_max_end )
              break;
            *m_end = *v10;
            ++p_part_name->m_string.m_end;
          }
          *p_part_name->m_string.m_end = 0;
        }
      }
      v13 = (char *)vostok::configs::binary_config_value::operator[](&current, "base_model")->data.pointer;
      v14 = p_part_name[-1].m_string.m_begin;
      if ( v14 != v13 )
      {
        p_part_name[-1].m_string.m_end = v14;
        *v14 = 0;
        if ( v13 )
        {
          for ( ; *v13; ++v13 )
          {
            v15 = p_part_name[-1].m_string.m_end;
            if ( v15 >= p_part_name[-1].m_string.m_max_end )
              break;
            *v15 = *v13;
            ++p_part_name[-1].m_string.m_end;
          }
          *p_part_name[-1].m_string.m_end = 0;
        }
      }
      p_part_name = (vostok::fs_new::virtual_path_string *)((char *)p_part_name + 844);
      v5 += 24;
      ++part_idx;
    }
    while ( part_idx < cook_data->models_count );
  }
}
