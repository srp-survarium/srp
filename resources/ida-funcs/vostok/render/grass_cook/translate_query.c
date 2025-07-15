void __thiscall vostok::render::grass_cook::translate_query(
        vostok::render::grass_cook *this,
        const vostok::variant<32> **parent)
{
  const vostok::variant<32> *v2; // esi
  unsigned __int8 v3; // al
  vostok::configs::binary_config_value *v4; // edi
  char *v5; // eax
  const char *v6; // ebx
  const vostok::configs::binary_config_value *v7; // eax
  vostok::configs::binary_config_value *v8; // esi
  char *v9; // edi
  vostok::configs::binary_config_value *v10; // ecx
  unsigned __int8 v11; // al
  void *v12; // esp
  const char *v13; // ebx
  char *v14; // eax
  float v15; // xmm0_4
  const vostok::configs::binary_config_value *v16; // eax
  vostok::configs::binary_config_value *v17; // ecx
  vostok::configs::binary_config_value *v18; // ebx
  char **v19; // eax
  vostok::fixed_string<260> *v20; // ecx
  int v21; // eax
  char *m_begin; // ecx
  unsigned int v23; // eax
  unsigned int v24; // kr00_4
  unsigned __int8 *v25; // esi
  const vostok::configs::binary_config_value *v26; // eax
  vostok::buffer_string *v27; // ecx
  vostok::strings::detail::tuples *v28; // ecx
  vostok::strings::detail::tuples *v29; // ecx
  void *v30; // esp
  vostok::strings::detail::tuples *v31; // ecx
  const vostok::configs::binary_config_value *v32; // eax
  float v33; // xmm0_4
  char *v34; // esi
  const vostok::configs::binary_config_value *v35; // eax
  float v36; // xmm0_4
  const vostok::configs::binary_config_value *v37; // eax
  float v38; // xmm0_4
  const vostok::configs::binary_config_value *v39; // eax
  float v40; // xmm0_4
  const vostok::configs::binary_config_value *v41; // eax
  vostok::configs::binary_config_value *v42; // ecx
  float v43; // xmm0_4
  int v44; // eax
  unsigned __int8 *v45; // edi
  vostok::resources::request *v46; // esi
  const vostok::configs::binary_config_value *v47; // eax
  char *v48; // edx
  char *v49; // edi
  vostok::buffer_string *v50; // eax
  char *v51; // ecx
  vostok::configs::binary_config_value *v52; // ecx
  int v53; // eax
  unsigned __int8 *v54; // edi
  const vostok::configs::binary_config_value *v55; // eax
  char *pointer; // edx
  vostok::buffer_string *v57; // eax
  char *v58; // ecx
  const vostok::configs::binary_config_value *v59; // eax
  const vostok::configs::binary_config_value *v60; // eax
  float v61; // xmm0_4
  const vostok::configs::binary_config_value *v62; // eax
  const vostok::configs::binary_config_value *v63; // eax
  const vostok::configs::binary_config_value *v64; // eax
  float v65; // xmm0_4
  vostok::resources::request *v66; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v67; // ecx
  const char *v68; // [esp+0h] [ebp-158h] BYREF
  const char *v69; // [esp+4h] [ebp-154h]
  unsigned int v70; // [esp+8h] [ebp-150h]
  char *p0; // [esp+Ch] [ebp-14Ch] BYREF
  vostok::buffer_string str1[22]; // [esp+10h] [ebp-148h] BYREF
  char v73; // [esp+11Ch] [ebp-3Ch] BYREF
  vostok::strings::detail::tuples v74; // [esp+120h] [ebp-38h] BYREF
  vostok::resources::request v75; // [esp+154h] [ebp-4h] BYREF
  _DWORD v76[6]; // [esp+15Ch] [ebp+4h] BYREF
  vostok::resources::request v77; // [esp+174h] [ebp+1Ch] BYREF
  vostok::render::grass_cook *v78; // [esp+17Ch] [ebp+24h]
  const char *v79; // [esp+180h] [ebp+28h]
  vostok::render::grass_loading_data *out_value; // [esp+184h] [ebp+2Ch] BYREF
  vostok::configs::binary_config_value *t_current; // [esp+188h] [ebp+30h]
  float v82; // [esp+18Ch] [ebp+34h]
  char *v83; // [esp+190h] [ebp+38h]
  vostok::buffer_vector<vostok::resources::request> v84; // [esp+194h] [ebp+3Ch] BYREF
  vostok::configs::binary_config_value *v85; // [esp+1A0h] [ebp+48h]
  const char *v86; // [esp+1A4h] [ebp+4Ch]
  char *v87; // [esp+1A8h] [ebp+50h]
  int v88; // [esp+1ACh] [ebp+54h]
  vostok::configs::binary_config_value *v89; // [esp+1B0h] [ebp+58h]
  vostok::configs::binary_config_value *v90; // [esp+1B4h] [ebp+5Ch]
  unsigned __int8 *src; // [esp+1B8h] [ebp+60h]
  char *v92; // [esp+1BCh] [ebp+64h]
  unsigned __int8 v93; // [esp+1C3h] [ebp+6Bh]
  vostok::resources::request *v94; // [esp+1C4h] [ebp+6Ch]
  vostok::configs::binary_config_value *v95; // [esp+1C8h] [ebp+70h]

  v2 = parent[66];
  v78 = this;
  vostok::variant<32>::try_get<vostok::render::grass_loading_data *>((vostok::variant<32> *)this, (int)v2, &out_value);
  t_current = out_value->t_current;
  v3 = 24 * vostok::configs::binary_config_value::operator[](t_current, "layers")->count / 24;
  v4 = (vostok::configs::binary_config_value *)v3;
  v93 = v3;
  v89 = (vostok::configs::binary_config_value *)v3;
  v5 = vostok::memory::doug_lea_allocator::malloc_impl(
         (vostok::memory::doug_lea_allocator *)0x18,
         (int)&vostok::memory::g_resources_helper_allocator,
         4548 * v3,
         "grass world query",
         v68,
         v69,
         v70);
  v6 = &v5[4512 * (_DWORD)v4];
  v83 = v5;
  v79 = v6;
  v95 = v4;
  if ( v93 )
  {
    v94 = 0;
    v90 = v4;
    do
    {
      v7 = vostok::configs::binary_config_value::operator[](t_current, "layers");
      v8 = (vostok::configs::binary_config_value *)((char *)v94 + (unsigned int)v7->data.pointer);
      v9 = "models";
      if ( !vostok::configs::binary_config_value::value_exists(v10, (int)v8, (unsigned int)"models") )
        v9 = "model_def";
      v11 = 24 * vostok::configs::binary_config_value::operator[](v8, v9)->count / 24;
      v94 += 3;
      v95 = (vostok::configs::binary_config_value *)((char *)v95 + v11);
      v90 = (vostok::configs::binary_config_value *)((char *)v90 - 1);
    }
    while ( v90 );
    v4 = v89;
  }
  v12 = alloca(8 * (_DWORD)v95);
  v84.m_max_end = (vostok::resources::request *)&(&v68)[2 * (_DWORD)v95];
  v84.m_begin = (vostok::resources::request *)&v68;
  v84.m_end = (vostok::resources::request *)&v68;
  vostok::buffer_vector<vostok::resources::request>::resize(
    (vostok::buffer_vector<vostok::resources::request> *)v4,
    v6,
    (int *)&v84);
  if ( v93 )
  {
    v13 = v6 + 8;
    v14 = v83 + 32;
    v90 = 0;
    v85 = 0;
    v88 = 0;
    v86 = v13;
    v87 = v83 + 32;
    v89 = v4;
    while ( 1 )
    {
      if ( v14 == (char *)32 )
      {
        v92 = 0;
      }
      else
      {
        *((_DWORD *)v14 - 3) = v14;
        *((_DWORD *)v14 - 2) = v14;
        *((_DWORD *)v14 - 1) = v14 + 4480;
        v92 = v14 - 32;
      }
      if ( v13 == (const char *)8 )
      {
        v95 = 0;
      }
      else
      {
        *((_DWORD *)v13 - 2) = 0;
        *((_DWORD *)v13 - 1) = 0;
        v15 = s_bm_current_air_resistance;
        *(_WORD *)v13 = 0;
        *((_WORD *)v13 + 1) = 0;
        *((float *)v13 + 1) = v15;
        *((_DWORD *)v13 + 2) = 0;
        *((_DWORD *)v13 + 3) = 0;
        *((_DWORD *)v13 + 4) = 0;
        *((_DWORD *)v13 + 5) = 0;
        *((_DWORD *)v13 + 6) = 0;
        v95 = (vostok::configs::binary_config_value *)(v13 - 8);
      }
      v16 = vostok::configs::binary_config_value::operator[](t_current, "layers");
      v17 = v85;
      v18 = (vostok::configs::binary_config_value *)((char *)v16->data.pointer + v88);
      v94 = (vostok::resources::request *)((char *)v85 + (unsigned int)v84.m_begin);
      v94->id = raw_data_class;
      if ( vostok::configs::binary_config_value::value_exists(v17, (int)v18, (unsigned int)"intermediate_filename") )
      {
        v19 = (char **)vostok::configs::binary_config_value::operator[](v18, "intermediate_filename");
        vostok::fixed_string<260>::fixed_string<260>(v20, str1, *v19);
        strstr((unsigned __int8 *)str1[0].m_begin, (unsigned __int8 *)&stru_7F94B0.m_string.m_buffer[16]);
        m_begin = str1[0].m_begin;
        v23 = v21 ? v21 - (unsigned int)str1[0].m_begin : -1;
        src = (unsigned __int8 *)&str1[0].m_begin[v23];
        v24 = strlen(&str1[0].m_begin[v23]);
        v25 = (unsigned __int8 *)vostok::memory::doug_lea_allocator::malloc_impl(
                                   (vostok::memory::doug_lea_allocator *)m_begin,
                                   (int)&vostok::memory::g_resources_helper_allocator,
                                   v24 + 1,
                                   "strings::duplicate",
                                   v68,
                                   v69,
                                   v70);
        memcpy(v25, src, v24 + 1);
        v94->path = (const char *)v25;
      }
      else
      {
        p0 = (char *)&str1[0].m_max_end;
        str1[0].m_begin = (char *)&str1[0].m_max_end;
        str1[0].m_end = &v73;
        LOBYTE(str1[0].m_max_end) = 0;
        v73 = 47;
        v26 = vostok::configs::binary_config_value::operator[](v18, "filename");
        vostok::fs_new::path_string_impl::assignf(
          &p0,
          v27,
          (vostok::buffer_string *)"%s/%s",
          out_value->project_resources_path.m_begin,
          v26->data.pointer);
        vostok::strings::detail::tuples::tuples(v28, &v74, p0);
        v30 = alloca(vostok::strings::detail::tuples::size(v29, (unsigned int *)&v74));
        vostok::strings::detail::tuples::concat(v31, (int)&v74, (char *)&v68);
        v94->path = (const char *)&v68;
      }
      v32 = vostok::configs::binary_config_value::operator[](v18, "max_slope");
      v33 = v32->type == 2 ? *(float *)&v32->data.pointer : (float)(int)v32->data.pointer;
      v34 = v92;
      *((float *)v92 + 1) = v33;
      v34[9] = vostok::configs::binary_config_value::operator[](v18, "random_dir")->data.pointer != 0;
      v35 = vostok::configs::binary_config_value::operator[](v18, "random_scale");
      v36 = v35->type == 2 ? *(float *)&v35->data.pointer : (float)(int)v35->data.pointer;
      *((float *)v34 + 3) = v36;
      v37 = vostok::configs::binary_config_value::operator[](v18, "wind_factor");
      v38 = v37->type == 2 ? *(float *)&v37->data.pointer : (float)(int)v37->data.pointer;
      *((float *)v34 + 4) = v38;
      v34[8] = vostok::configs::binary_config_value::operator[](v18, "use_face_normal")->data.pointer != 0;
      v39 = vostok::configs::binary_config_value::operator[](v18, "lt_x");
      v40 = v39->type == 2 ? *(float *)&v39->data.pointer : (float)(int)v39->data.pointer;
      *(float *)&v95->data.pointer = v40;
      v41 = vostok::configs::binary_config_value::operator[](v18, "lt_z");
      v43 = v41->type == 2 ? *(float *)&v41->data.pointer : (float)(int)v41->data.pointer;
      *((float *)&v95->data.max_storage + 1) = v43;
      if ( vostok::configs::binary_config_value::value_exists(v42, (int)v18, (unsigned int)"models") )
      {
        v44 = 24 * vostok::configs::binary_config_value::operator[](v18, "models")->count / 24;
        v92 = v34 + 20;
        v45 = (unsigned __int8 *)(unsigned __int8)v44;
        vostok::buffer_vector<vostok::render::grass_layer_desc::model_desc>::resize(
          (vostok::buffer_vector<vostok::render::grass_layer_desc::model_desc> *)0x18,
          (int *)v34 + 5,
          (vostok::render::grass_layer_desc::model_desc *)(unsigned __int8)v44);
        v46 = 0;
        if ( v45 )
        {
          v77.id = grass_render_model_class;
          v94 = 0;
          v95 = 0;
          src = v45;
          v82 = 1.0 / (double)(unsigned int)v45;
          while ( 1 )
          {
            v47 = vostok::configs::binary_config_value::operator[](v18, "models");
            v48 = *(char **)((char *)&v95->data.pointer + (unsigned int)v47->data.pointer);
            v49 = v92;
            v50 = (vostok::buffer_string *)((char *)v46 + *(_DWORD *)v92);
            v51 = v50->m_begin;
            if ( v50->m_begin != v48 )
            {
              v50->m_end = v51;
              *v51 = 0;
              vostok::buffer_string::operator+=(v50, v48);
            }
            v52 = v90;
            *(float *)((char *)&v46[34].path + *(_DWORD *)v49) = v82;
            *(float *)((char *)&v46[34].id + *(_DWORD *)v49) = s_bm_current_air_resistance;
            v77.path = *(const char **)((char *)&v52->data.pointer + *(_DWORD *)v49);
            vostok::buffer_vector<vostok::resources::request>::push_back(&v84, &v77);
            ++v95;
            v94 += 35;
            if ( !--src )
              break;
            v46 = v94;
          }
        }
      }
      else
      {
        v53 = 24 * vostok::configs::binary_config_value::operator[](v18, "model_def")->count / 24;
        v92 = v34 + 20;
        v54 = (unsigned __int8 *)(unsigned __int8)v53;
        vostok::buffer_vector<vostok::render::grass_layer_desc::model_desc>::resize(
          (vostok::buffer_vector<vostok::render::grass_layer_desc::model_desc> *)0x18,
          (int *)v34 + 5,
          (vostok::render::grass_layer_desc::model_desc *)(unsigned __int8)v53);
        if ( v54 )
        {
          v94 = 0;
          v95 = 0;
          v75.id = grass_render_model_class;
          src = v54;
          do
          {
            v55 = vostok::configs::binary_config_value::operator[](v18, "model_def");
            pointer = (char *)vostok::configs::binary_config_value::operator[](
                                (vostok::configs::binary_config_value *)((char *)v95 + (unsigned int)v55->data.pointer),
                                "name")->data.pointer;
            v57 = (vostok::buffer_string *)((char *)v94 + *(_DWORD *)v92);
            v58 = v57->m_begin;
            if ( v57->m_begin != pointer )
            {
              v57->m_end = v58;
              *v58 = 0;
              vostok::buffer_string::operator+=(v57, pointer);
            }
            v59 = vostok::configs::binary_config_value::operator[](v18, "model_def");
            v60 = vostok::configs::binary_config_value::operator[](
                    (vostok::configs::binary_config_value *)((char *)v95 + (unsigned int)v59->data.pointer),
                    "probability");
            if ( v60->type == 2 )
              v61 = *(float *)&v60->data.pointer;
            else
              v61 = (float)(int)v60->data.pointer;
            *(float *)((char *)&v94[34].path + *(_DWORD *)v92) = v61;
            v62 = vostok::configs::binary_config_value::operator[](v18, "model_def");
            if ( vostok::configs::binary_config_value::value_exists(
                   v95,
                   (int)v95 + (unsigned int)v62->data.pointer,
                   (unsigned int)"scale") )
            {
              v63 = vostok::configs::binary_config_value::operator[](v18, "model_def");
              v64 = vostok::configs::binary_config_value::operator[](
                      (vostok::configs::binary_config_value *)((char *)v95 + (unsigned int)v63->data.pointer),
                      "scale");
              if ( v64->type == 2 )
                v65 = *(float *)&v64->data.pointer;
              else
                v65 = (float)(int)v64->data.pointer;
            }
            else
            {
              v65 = s_bm_current_air_resistance;
            }
            v66 = v94;
            *(float *)((char *)&v94[34].id + *(_DWORD *)v92) = v65;
            v75.path = *(const char **)((char *)&v66->path + *(_DWORD *)v92);
            vostok::buffer_vector<vostok::resources::request>::push_back(&v84, &v75);
            ++v95;
            v94 += 35;
            --src;
          }
          while ( src );
        }
      }
      v87 += 4512;
      v86 += 36;
      v88 += 24;
      v85 = (vostok::configs::binary_config_value *)((char *)v85 + 8);
      v90 = (vostok::configs::binary_config_value *)((char *)v90 + 280);
      v89 = (vostok::configs::binary_config_value *)((char *)v89 - 1);
      if ( !v89 )
        break;
      v13 = v86;
      v14 = v87;
    }
    v6 = v79;
  }
  v76[1] = v78;
  v76[2] = parent;
  v76[3] = v83;
  LOBYTE(v76[5]) = v93;
  v76[4] = v6;
  v74.m_strings[3].second = (unsigned int)vostok::render::grass_cook::on_layers_loaded;
  qmemcpy(&v74.m_strings[4], &v76[1], 0x14u);
  qmemcpy(v76, &v74.m_strings[3].second, sizeof(v76));
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(0) )
  {
    v74.m_strings[2].second = 0;
  }
  else
  {
    qmemcpy(&v74.m_strings[3].second, v76, 0x18u);
    v74.m_strings[2].second = (unsigned int)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf5<void,vostok::render::grass_cook,vostok::resources::queries_result &,vostok::resources::query_result_for_cook *,vostok::render::grass_layer_desc *,vostok::render::grass_layer_data *,unsigned int>,boost::_bi::list6<boost::_bi::value<vostok::render::grass_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::query_result_for_cook *>,boost::_bi::value<vostok::render::grass_layer_desc *>,boost::_bi::value<vostok::render::grass_layer_data *>,boost::_bi::value<unsigned char>>>>'::`2'::stored_vtable
                            + 1;
  }
  vostok::resources::query_resources(
    v84.m_begin,
    v84.m_end - v84.m_begin,
    &vostok::memory::g_resources_helper_allocator,
    0,
    parent,
    assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v67,
    (int *)&v74.m_strings[2].second);
}
