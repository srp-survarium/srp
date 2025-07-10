void __thiscall vostok::render::grass_cook::translate_query(
        vostok::render::grass_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  int *v2; // eax
  vostok::render::grass_world *v3; // ecx
  vostok::render::grass_world *v4; // eax
  int v5; // ebx
  vostok::render::grass_cook_data *v6; // edi
  vostok::render::grass_layer_desc **v7; // eax
  vostok::render::grass_world *v8; // ecx
  void *v9; // esp
  vostok::render::grass_layer_desc *v10; // eax
  int *v11; // eax
  const vostok::math::float4x4 *v12; // xmm0_4
  vostok::render::grass_cook_data *v13; // edx
  unsigned int v14; // ecx
  vostok::render::grass_layer_desc *v15; // ebx
  vostok::render::grass_layer_data *v16; // eax
  const vostok::configs::binary_config_value *v17; // eax
  vostok::configs::binary_config_value *v18; // edi
  char *pointer; // ecx
  char *v20; // eax
  int v21; // eax
  int v22; // eax
  unsigned int v23; // kr00_4
  vostok::memory::doug_lea_allocator *v24; // eax
  int *v25; // ebx
  const vostok::configs::binary_config_value *v26; // eax
  vostok::strings::detail::tuples *v27; // ecx
  unsigned int v28; // eax
  void *v29; // esp
  vostok::strings::detail::tuples *v30; // ecx
  const vostok::configs::binary_config_value *v31; // eax
  float v32; // xmm0_4
  const vostok::configs::binary_config_value *v33; // eax
  float v34; // xmm0_4
  const vostok::configs::binary_config_value *v35; // eax
  float v36; // xmm0_4
  const vostok::configs::binary_config_value *v37; // eax
  float v38; // xmm0_4
  const vostok::configs::binary_config_value *v39; // eax
  float v40; // xmm0_4
  unsigned int v41; // esi
  int v42; // ebx
  double v43; // st7
  unsigned __int8 *v44; // esi
  const vostok::configs::binary_config_value *v45; // eax
  _BYTE *v46; // ecx
  _BYTE *v47; // edx
  int v48; // eax
  _BYTE *v49; // esi
  int v50; // ecx
  unsigned int v51; // ebx
  int v52; // esi
  vostok::render::grass_layer_data *v53; // ebx
  const vostok::configs::binary_config_value *v54; // eax
  _BYTE *v55; // ecx
  _BYTE *v56; // edx
  char *v57; // eax
  _BYTE *v58; // edx
  const vostok::configs::binary_config_value *v59; // eax
  const vostok::configs::binary_config_value *v60; // eax
  float v61; // xmm0_4
  const vostok::configs::binary_config_value *v62; // eax
  const vostok::configs::binary_config_value *v63; // eax
  const vostok::configs::binary_config_value *v64; // eax
  float v65; // xmm0_4
  bool v66; // zf
  void (__cdecl *v67)(unsigned int *, unsigned int *, int); // eax
  char v68[12]; // [esp+0h] [ebp-128h] BYREF
  vostok::fs_new::path_string_impl v69; // [esp+Ch] [ebp-11Ch] BYREF
  vostok::strings::detail::tuples STR_JOINA_tuples_unique_identifier; // [esp+120h] [ebp-8h] BYREF
  const vostok::configs::binary_config_value *t; // [esp+154h] [ebp+2Ch]
  vostok::render::grass_cook *v72; // [esp+158h] [ebp+30h]
  vostok::buffer_vector<vostok::resources::request> requests; // [esp+15Ch] [ebp+34h] BYREF
  __int64 v74; // [esp+164h] [ebp+3Ch]
  vostok::render::grass_cook_data *v75; // [esp+16Ch] [ebp+44h]
  unsigned int request_count; // [esp+170h] [ebp+48h]
  vostok::render::grass_loading_data *loading_data; // [esp+174h] [ebp+4Ch] BYREF
  float v78; // [esp+178h] [ebp+50h]
  int v79; // [esp+17Ch] [ebp+54h]
  vostok::render::grass_cook_data *cook_data; // [esp+180h] [ebp+58h]
  unsigned int v81; // [esp+184h] [ebp+5Ch]
  vostok::resources::request *m_begin; // [esp+188h] [ebp+60h]
  vostok::render::grass_world *result; // [esp+18Ch] [ebp+64h]
  vostok::render::grass_layer_desc *layer_desc; // [esp+190h] [ebp+68h]
  unsigned __int8 *src; // [esp+194h] [ebp+6Ch]
  vostok::render::grass_layer_data *layer_data; // [esp+198h] [ebp+70h]

  v72 = this;
  vostok::variant<32>::try_get<vostok::render::grass_loading_data *>(
    (vostok::variant<32> *)parent,
    (int)parent->m_user_data->m_helper_storage,
    &loading_data);
  v2 = vostok::memory::doug_lea_allocator::malloc_impl(
         (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
         0x168u);
  if ( v2 )
  {
    vostok::render::grass_world::grass_world(v3, (int)v2);
    result = v4;
  }
  else
  {
    result = 0;
  }
  t = loading_data->t_current;
  v5 = 24
     * vostok::configs::binary_config_value::operator[]((vostok::configs::binary_config_value *)t, "layers")->count
     / 24;
  v6 = (vostok::render::grass_cook_data *)vostok::memory::doug_lea_allocator::malloc_impl(
                                            (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                            0x10u);
  cook_data = v6;
  request_count = (unsigned __int8)v5;
  v6->desc = vostok::memory::new_array_helper<survarium::options_item_base *>::call<vostok::memory::doug_lea_allocator>(
               (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
               (unsigned __int8)v5);
  v7 = vostok::memory::new_array_helper<survarium::options_item_base *>::call<vostok::memory::doug_lea_allocator>(
         (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
         (unsigned __int8)v5);
  v8 = result;
  v6->data = (vostok::render::grass_layer_data **)v7;
  v6->parent_query = parent;
  v6->result = v8;
  v9 = alloca(8 * (unsigned __int8)v5);
  requests.m_begin = (vostok::resources::request *)v68;
  requests.m_end = (vostok::resources::request *)v68;
  vostok::buffer_vector<vostok::resources::request>::resize((int)v8, (unsigned __int8)v5, &requests);
  if ( (_BYTE)v5 )
  {
    result = 0;
    v81 = 0;
    m_begin = requests.m_begin;
    v79 = (unsigned __int8)v5;
    do
    {
      v10 = (vostok::render::grass_layer_desc *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                  (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                                  0x119Cu);
      if ( v10 )
      {
        v10->models_list.m_begin = (vostok::render::grass_layer_desc::model_desc *)v10->models_list.m_buffer;
        v10->models_list.m_end = (vostok::render::grass_layer_desc::model_desc *)v10->models_list.m_buffer;
      }
      else
      {
        v10 = 0;
      }
      cook_data->desc[v81 / 4] = v10;
      v11 = vostok::memory::doug_lea_allocator::malloc_impl(
              (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
              0x28u);
      if ( v11 )
      {
        *v11 = 0;
        v11[1] = 0;
        v12 = clear_value;
        *((_WORD *)v11 + 4) = 0;
        *((_WORD *)v11 + 5) = 0;
        v11[3] = (int)v12;
        *((_BYTE *)v11 + 16) = 1;
        v11[5] = 0;
        v11[6] = 0;
        v11[7] = 0;
        v11[8] = 0;
        v11[9] = 0;
      }
      else
      {
        v11 = 0;
      }
      v13 = cook_data;
      v14 = v81;
      cook_data->data[v81 / 4] = (vostok::render::grass_layer_data *)v11;
      v15 = *(vostok::render::grass_layer_desc **)((char *)v13->desc + v14);
      v16 = *(vostok::render::grass_layer_data **)((char *)v13->data + v14);
      layer_desc = v15;
      layer_data = v16;
      v17 = vostok::configs::binary_config_value::operator[]((vostok::configs::binary_config_value *)t, "layers");
      v18 = (vostok::configs::binary_config_value *)((char *)result + (unsigned int)v17->data.pointer);
      m_begin->id = raw_data_class;
      if ( vostok::configs::binary_config_value::value_exists(v18, "intermediate_filename") )
      {
        pointer = (char *)vostok::configs::binary_config_value::operator[](v18, "intermediate_filename")->data.pointer;
        v20 = &v69.m_string.m_buffer[4];
        v69.m_string.m_end = &v69.m_string.m_buffer[4];
        v69.m_string.m_max_end = &v69.m_string.m_buffer[4];
        *(_DWORD *)v69.m_string.m_buffer = &STR_JOINA_tuples_unique_identifier;
        v69.m_string.m_buffer[4] = 0;
        if ( pointer )
        {
          for ( ; *pointer; ++v69.m_string.m_max_end )
          {
            if ( (unsigned int)v20 >= *(_DWORD *)v69.m_string.m_buffer )
              break;
            *v20 = *pointer;
            v20 = v69.m_string.m_max_end + 1;
            ++pointer;
          }
          *v20 = 0;
        }
        strstr((unsigned __int8 *)v69.m_string.m_end, (unsigned __int8 *)&stru_954D10.m_string.m_buffer[16]);
        if ( v21 )
          v22 = v21 - (unsigned int)v69.m_string.m_end;
        else
          v22 = -1;
        src = (unsigned __int8 *)&v69.m_string.m_end[v22];
        v23 = strlen(&v69.m_string.m_end[v22]);
        v24 = (vostok::memory::doug_lea_allocator *)boost::get_pointer<vostok::sound::sound_scene>((vostok::sound::sound_world *)vostok::render::g_allocator.m_object);
        v25 = vostok::memory::doug_lea_allocator::malloc_impl(v24, v23 + 1);
        memcpy((unsigned __int8 *)v25, src, v23 + 1);
        m_begin->path = (const char *)v25;
        v15 = layer_desc;
      }
      else
      {
        v69.m_string.m_begin = v69.m_string.m_buffer;
        v69.m_string.m_end = v69.m_string.m_buffer;
        v69.m_string.m_max_end = &v69.m_separator;
        v69.m_string.m_buffer[0] = 0;
        v69.m_separator = 47;
        v26 = vostok::configs::binary_config_value::operator[](v18, "filename");
        vostok::fs_new::path_string_impl::assignf(
          &v69,
          "%s/%s",
          loading_data->project_resources_path.m_begin,
          (const char *)v26->data.pointer);
        v28 = 0;
        memset(&STR_JOINA_tuples_unique_identifier.m_strings[1], 0, 40);
        STR_JOINA_tuples_unique_identifier.m_count = 1;
        if ( v69.m_string.m_begin )
          v28 = strlen(v69.m_string.m_begin);
        STR_JOINA_tuples_unique_identifier.m_strings[0].first = v69.m_string.m_begin;
        STR_JOINA_tuples_unique_identifier.m_strings[0].second = v28;
        v29 = alloca(vostok::strings::detail::tuples::size(v27, (unsigned int *)&STR_JOINA_tuples_unique_identifier));
        vostok::strings::detail::tuples::size(v30, (unsigned int *)&STR_JOINA_tuples_unique_identifier);
        m_begin->path = v68;
        vostok::strings::detail::tuples::concat(v68, &STR_JOINA_tuples_unique_identifier);
      }
      v31 = vostok::configs::binary_config_value::operator[](v18, "max_slope");
      if ( v31->type == 2 )
        v32 = *(float *)&v31->data.pointer;
      else
        v32 = (float)(int)v31->data.pointer;
      v15->max_slope_ang = v32;
      v15->random_orient = vostok::configs::binary_config_value::operator[](v18, "random_dir")->data.pointer != 0;
      v33 = vostok::configs::binary_config_value::operator[](v18, "random_scale");
      if ( v33->type == 2 )
        v34 = *(float *)&v33->data.pointer;
      else
        v34 = (float)(int)v33->data.pointer;
      v15->random_scale = v34;
      v35 = vostok::configs::binary_config_value::operator[](v18, "wind_factor");
      if ( v35->type == 2 )
        v36 = *(float *)&v35->data.pointer;
      else
        v36 = (float)(int)v35->data.pointer;
      v15->wind_factor = v36;
      v15->use_face_normal = vostok::configs::binary_config_value::operator[](v18, "use_face_normal")->data.pointer != 0;
      v37 = vostok::configs::binary_config_value::operator[](v18, "lt_x");
      if ( v37->type == 2 )
        v38 = *(float *)&v37->data.pointer;
      else
        v38 = (float)(int)v37->data.pointer;
      layer_data->lt_x_m = v38;
      v39 = vostok::configs::binary_config_value::operator[](v18, "lt_z");
      if ( v39->type == 2 )
        v40 = *(float *)&v39->data.pointer;
      else
        v40 = (float)(int)v39->data.pointer;
      layer_data->lt_z_m = v40;
      if ( vostok::configs::binary_config_value::value_exists(v18, "models") )
      {
        v41 = (unsigned __int8)((char)(24
                                     * LOBYTE(vostok::configs::binary_config_value::operator[](v18, "models")->count))
                              / 24);
        src = (unsigned __int8 *)&v15->models_list;
        vostok::buffer_vector<vostok::render::grass_layer_desc::model_desc>::resize(v41, &v15->models_list);
        if ( v41 )
        {
          v42 = 0;
          v43 = 1.0 / (double)v41;
          layer_desc = (vostok::render::grass_layer_desc *)v41;
          v44 = src;
          layer_data = 0;
          v78 = v43;
          do
          {
            v45 = vostok::configs::binary_config_value::operator[](v18, "models");
            v46 = *(_BYTE **)((char *)&layer_data->lt_x_m + (unsigned int)v45->data.pointer);
            v47 = *(_BYTE **)(*(_DWORD *)v44 + v42);
            v48 = v42 + *(_DWORD *)v44;
            if ( v47 != v46 )
            {
              *(_DWORD *)(v48 + 4) = v47;
              *v47 = 0;
              if ( v46 )
              {
                for ( ; *v46; ++v46 )
                {
                  v49 = *(_BYTE **)(v48 + 4);
                  if ( (unsigned int)v49 >= *(_DWORD *)(v48 + 8) )
                    break;
                  *v49 = *v46;
                  ++*(_DWORD *)(v48 + 4);
                }
                v44 = src;
                **(_BYTE **)(v48 + 4) = 0;
              }
            }
            v50 = *(_DWORD *)v44;
            layer_data = (vostok::render::grass_layer_data *)((char *)layer_data + 24);
            *(float *)(v50 + v42 + 272) = v78;
            *(_DWORD *)(*(_DWORD *)v44 + v42 + 276) = clear_value;
            v42 += 280;
            layer_desc = (vostok::render::grass_layer_desc *)((char *)layer_desc - 1);
          }
          while ( layer_desc );
        }
      }
      else
      {
        v51 = (unsigned __int8)((char)(24
                                     * LOBYTE(vostok::configs::binary_config_value::operator[](v18, "model_def")->count))
                              / 24);
        src = (unsigned __int8 *)&layer_desc->models_list;
        vostok::buffer_vector<vostok::render::grass_layer_desc::model_desc>::resize(v51, &layer_desc->models_list);
        if ( v51 )
        {
          v52 = 0;
          layer_desc = (vostok::render::grass_layer_desc *)v51;
          layer_data = 0;
          v53 = 0;
          do
          {
            v54 = vostok::configs::binary_config_value::operator[](v18, "model_def");
            v55 = vostok::configs::binary_config_value::operator[](
                    (vostok::configs::binary_config_value *)((char *)v54->data.pointer + v52),
                    "name")->data.pointer;
            v56 = *(_BYTE **)((char *)&v53->lt_x_m + *(_DWORD *)src);
            v57 = (char *)v53 + *(_DWORD *)src;
            if ( v56 != v55 )
            {
              *((_DWORD *)v57 + 1) = v56;
              *v56 = 0;
              if ( v55 )
              {
                for ( ; *v55; ++v55 )
                {
                  v58 = (_BYTE *)*((_DWORD *)v57 + 1);
                  if ( (unsigned int)v58 >= *((_DWORD *)v57 + 2) )
                    break;
                  *v58 = *v55;
                  ++*((_DWORD *)v57 + 1);
                }
                v53 = layer_data;
                **((_BYTE **)v57 + 1) = 0;
              }
            }
            v59 = vostok::configs::binary_config_value::operator[](v18, "model_def");
            v60 = vostok::configs::binary_config_value::operator[](
                    (vostok::configs::binary_config_value *)((char *)v59->data.pointer + v52),
                    "probability");
            if ( v60->type == 2 )
              v61 = *(float *)&v60->data.pointer;
            else
              v61 = (float)(int)v60->data.pointer;
            *(float *)((char *)&v53[6].instances_count + *(_DWORD *)src) = v61;
            v62 = vostok::configs::binary_config_value::operator[](v18, "model_def");
            if ( vostok::configs::binary_config_value::value_exists(
                   (vostok::configs::binary_config_value *)((char *)v62->data.pointer + v52),
                   "scale") )
            {
              v63 = vostok::configs::binary_config_value::operator[](v18, "model_def");
              v64 = vostok::configs::binary_config_value::operator[](
                      (vostok::configs::binary_config_value *)((char *)v63->data.pointer + v52),
                      "scale");
              if ( v64->type == 2 )
                v65 = *(float *)&v64->data.pointer;
              else
                v65 = (float)(int)v64->data.pointer;
              *(float *)((char *)&v53[6].layer_data_raw_file.m_object + *(_DWORD *)src) = v65;
            }
            else
            {
              *(vostok::resources::managed_resource **)((char *)&v53[6].layer_data_raw_file.m_object + *(_DWORD *)src) = (vostok::resources::managed_resource *)clear_value;
            }
            v53 += 7;
            v52 += 24;
            v66 = layer_desc == (vostok::render::grass_layer_desc *)1;
            layer_desc = (vostok::render::grass_layer_desc *)((char *)layer_desc - 1);
            layer_data = v53;
          }
          while ( !v66 );
        }
      }
      v81 += 4;
      result = (vostok::render::grass_world *)((char *)result + 24);
      ++m_begin;
      --v79;
    }
    while ( v79 );
  }
  LODWORD(v74) = vostok::render::grass_cook::on_layers_loaded;
  HIDWORD(v74) = v72;
  v75 = cook_data;
  if ( survarium::generate_shaders_world::is_loading() )
  {
    STR_JOINA_tuples_unique_identifier.m_strings[2].second = 0;
  }
  else
  {
    *(_QWORD *)&STR_JOINA_tuples_unique_identifier.m_strings[3].second = v74;
    STR_JOINA_tuples_unique_identifier.m_strings[4].second = (unsigned int)v75;
    STR_JOINA_tuples_unique_identifier.m_strings[2].second = (unsigned int)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::render::grass_cook,vostok::resources::queries_result &,vostok::render::grass_cook_data *>,boost::_bi::list3<boost::_bi::value<vostok::render::grass_cook *>,boost::arg<1>,boost::_bi::value<vostok::render::grass_cook_data *>>>>'::`2'::stored_vtable
                                                           + 1;
  }
  vostok::resources::query_resources(
    requests.m_begin,
    request_count,
    (boost::function4<void,unsigned int,float,float,char const *> *)&STR_JOINA_tuples_unique_identifier.m_strings[2].second,
    (vostok::memory::base_allocator *)vostok::render::g_allocator.m_object,
    0,
    parent,
    assert_on_fail_true);
  if ( STR_JOINA_tuples_unique_identifier.m_strings[2].second
    && (STR_JOINA_tuples_unique_identifier.m_strings[2].second & 1) == 0 )
  {
    v67 = *(void (__cdecl **)(unsigned int *, unsigned int *, int))(STR_JOINA_tuples_unique_identifier.m_strings[2].second
                                                                  & 0xFFFFFFFE);
    if ( v67 )
      v67(
        &STR_JOINA_tuples_unique_identifier.m_strings[3].second,
        &STR_JOINA_tuples_unique_identifier.m_strings[3].second,
        2);
  }
}
