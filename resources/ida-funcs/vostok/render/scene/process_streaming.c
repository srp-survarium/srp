void __thiscall vostok::render::scene::process_streaming(
        vostok::render::scene *this,
        boost::_bi::bind_t<void,boost::_mfi::mf4<void,vostok::render::scene,vostok::resources::queries_result &,vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,unsigned int,float>,boost::_bi::list5<boost::_bi::value<vostok::render::scene *>,boost::arg<1>,boost::_bi::value<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> >,boost::_bi::value<unsigned int>,boost::_bi::value<float> > > __formal,
        unsigned int screen_size_y)
{
  int f; // esi
  vostok::render::texture_streaming_async_worker *v4; // ecx
  vostok::render::requested_streamable_texture *v5; // edx
  int v6; // eax
  int v7; // edi
  vostok::render::scene *v8; // ecx
  vostok::render::requested_streamable_texture *v9; // ebx
  _DWORD *v10; // edi
  vostok::render::requested_streamable_texture *v11; // eax
  vostok::render::requested_streamable_texture *if_PAUrequested_streamable_texture_render_vostok__Uremove_requested_texture_predicate__5__process_streaming_scene_23_QAEXPAVrenderer_context_23_ABVfloat4x4_math_3_Vfloat3_93_II_Z__priv_stlp_std__YAPAUrequested_streamable_texture_render_vostok__PAU234_0Uremove_requested_texture_predicate__5__process_streaming_scene_34_QAEXPAVrenderer_context_34_ABVfloat4x4_math_4_Vfloat3_math_4_II_Z_ABUrandom_access_iterator_tag_1__Z; // eax
  vostok::buffer_vector<vostok::render::requested_streamable_texture> *v13; // ecx
  int v14; // eax
  char *v15; // ebx
  int v16; // esi
  int v17; // ecx
  stlp_std::priv::_Rb_tree_node_base *v18; // eax
  stlp_std::priv::_Rb_tree_node_base *v19; // edi
  stlp_std::priv::_Rb_tree_node_base *M_left; // edx
  stlp_std::priv::_Rb_tree_node_base *M_parent; // ecx
  stlp_std::priv::_Rb_tree_node_base *v22; // edx
  stlp_std::priv::_Rb_tree_node_base *v23; // ecx
  unsigned int v24; // edx
  stlp_std::priv::_Rb_tree_node_base *v25; // eax
  int v26; // edx
  int v27; // eax
  stlp_std::priv::_Rb_tree_node_base *v28; // eax
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v29; // eax
  vostok::render::potential_request *v30; // ecx
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v31; // edi
  int v32; // edx
  int v33; // eax
  vostok::render::potential_request *v34; // esi
  vostok::render::potential_request *if_PAUpotential_request_render_vostok__Uremove_request_predicate__CG___process_streaming_scene_23_QAEXPAVrenderer_context_23_ABVfloat4x4_math_3_Vfloat3_93_II_Z__priv_stlp_std__YAPAUpotential_request_render_vostok__PAU234_0Uremove_request_predicate__CG___process_streaming_scene_34_QAEXPAVrenderer_context_34_ABVfloat4x4_math_4_Vfloat3_math_4_II_Z_ABUrandom_access_iterator_tag_1__Z; // eax
  float t; // ecx
  vostok::render::potential_request *v37; // edx
  int v38; // eax
  unsigned int v39; // esi
  vostok::render::texture_query_struct *v40; // edi
  void *v41; // esp
  vostok::render::potential_request *v42; // ebx
  unsigned int wanted_mips; // ecx
  int v44; // esi
  int v45; // esi
  char *v46; // esi
  vostok::buffer_string *v47; // ecx
  vostok::fs_new::virtual_path_string *v48; // ecx
  vostok::buffer_string *v49; // eax
  vostok::buffer_string *v50; // esi
  vostok::render::requested_streamable_texture *v51; // esi
  unsigned int v52; // eax
  void *v53; // esp
  vostok::memory::single_size_fixed_allocator<36,16384,vostok::threading::single_threading_policy> *allocator; // edx
  vostok::render::scene *v55; // ecx
  unsigned int v56; // eax
  const char *vtable; // edi
  int v58; // ebx
  boost::function1<void,vostok::resources::queries_result &> *v59; // ecx
  vostok::render::requested_streamable_texture *v60; // edi
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v61; // ecx
  char *v62; // ebx
  int v63; // esi
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v64; // edi
  int v65; // ebx
  vostok::render::streamable_texture_info *v66; // edi
  vostok::render::streamable_texture_info *v67; // eax
  vostok::memory::single_size_fixed_allocator<36,16384,vostok::threading::single_threading_policy> *v68; // esi
  vostok::render::streamable_texture_info *if_PAUstreamable_texture_info_render_vostok__Uremove_texture_predicate__DD___process_streaming_scene_23_QAEXPAVrenderer_context_23_ABVfloat4x4_math_3_Vfloat3_93_II_Z__priv_stlp_std__YAPAUstreamable_texture_info_render_vostok__PAU234_0Uremove_texture_predicate__DD___process_streaming_scene_34_QAEXPAVrenderer_context_34_ABVfloat4x4_math_4_Vfloat3_math_4_II_Z_ABUrandom_access_iterator_tag_1__Z; // eax
  vostok::render::streamable_texture_info *v70; // ecx
  int v71; // esi
  vostok::render::scene *v72; // ecx
  vostok::command_line::key *v73; // ecx
  bool is_set; // al
  vostok::render::scene *v75; // ecx
  vostok::command_line::key *v76; // ecx
  vostok::render::texture_streaming_async_worker *v77; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf4<void,vostok::render::scene,vostok::resources::queries_result &,vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,unsigned int,float>,boost::_bi::list5<boost::_bi::value<vostok::render::scene *>,boost::arg<1>,boost::_bi::value<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> >,boost::_bi::value<unsigned int>,boost::_bi::value<float> > > v78; // [esp-18h] [ebp-3E4h] BYREF
  const char *v79[4]; // [esp+0h] [ebp-3CCh] BYREF
  vostok::buffer_string v80[22]; // [esp+10h] [ebp-3BCh] BYREF
  char v81; // [esp+120h] [ebp-2ACh]
  vostok::buffer_string v82; // [esp+128h] [ebp-2A4h] BYREF
  _BYTE v83[260]; // [esp+134h] [ebp-298h] BYREF
  char v84; // [esp+238h] [ebp-194h] BYREF
  vostok::render::requested_streamable_texture value; // [esp+240h] [ebp-18Ch] BYREF
  int v86[8]; // [esp+358h] [ebp-74h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf4<void,vostok::render::scene,vostok::resources::queries_result &,vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,unsigned int,float>,boost::_bi::list5<boost::_bi::value<vostok::render::scene *>,boost::arg<1>,boost::_bi::value<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> >,boost::_bi::value<unsigned int>,boost::_bi::value<float> > > __that; // [esp+378h] [ebp-54h] BYREF
  vostok::render::texture_storage key; // [esp+390h] [ebp-3Ch] BYREF
  vostok::render::potential_request *v89; // [esp+3B0h] [ebp-1Ch] BYREF
  vostok::render::scene::process_streaming::__l51::remove_texture_predicate v90; // [esp+3B4h] [ebp-18h] BYREF
  vostok::render::scene::process_streaming::__l6::remove_requested_texture_predicate __pred[4]; // [esp+3B8h] [ebp-14h] BYREF
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *i; // [esp+3BCh] [ebp-10h]
  bool v93; // [esp+3C0h] [ebp-Ch] BYREF
  vostok::render::requested_streamable_texture *end[2]; // [esp+3C4h] [ebp-8h] BYREF

  f = (int)__formal.f_.f_;
  if ( !vostok::command_line::key::is_set((vostok::command_line::key *)this, (int)&s_sync_streaming) )
    vostok::render::texture_streaming_async_worker::ensure_completion(v4, (int)&unk_8B9588 + f);
  v5 = *(vostok::render::requested_streamable_texture **)((char *)&dword_1CA194 + f);
  for ( end[0] = *(vostok::render::requested_streamable_texture **)&byte_1CA198[f];
        v5 != end[0];
        v5 = (vostok::render::requested_streamable_texture *)((char *)v5 + 4) )
  {
    v6 = *(_DWORD *)((char *)&loc_1BE17C + f);
    v7 = *(_DWORD *)((char *)&loc_1BE17F + f + 1);
    while ( v6 != v7 )
    {
      if ( *(char **)(*(_DWORD *)v6 + 8) == v5->path.m_begin )
        *(_BYTE *)(*(_DWORD *)v6 + 4) = 1;
      v6 += 4;
    }
  }
  *(_DWORD *)&byte_1CA198[f] = *(int *)((char *)&dword_1CA194 + f);
  v8 = *(vostok::render::scene **)((char *)&dword_96154 + f);
  if ( v8 != *(vostok::render::scene **)((char *)&dword_96154 + f + 4) )
  {
    vostok::render::scene::update_streaming_data(v8, f);
    v9 = *(vostok::render::requested_streamable_texture **)((char *)&dword_E8164 + f);
    __pred[0] = 0;
    v78.l_.a5_.t_ = *(float *)__pred;
    v10 = (int *)((char *)&dword_E8160 + f);
    v11 = *(vostok::render::requested_streamable_texture **)((char *)&dword_E8160 + f);
    end[0] = v9;
    if_PAUrequested_streamable_texture_render_vostok__Uremove_requested_texture_predicate__5__process_streaming_scene_23_QAEXPAVrenderer_context_23_ABVfloat4x4_math_3_Vfloat3_93_II_Z__priv_stlp_std__YAPAUrequested_streamable_texture_render_vostok__PAU234_0Uremove_requested_texture_predicate__5__process_streaming_scene_34_QAEXPAVrenderer_context_34_ABVfloat4x4_math_4_Vfloat3_math_4_II_Z_ABUrandom_access_iterator_tag_1__Z = _____find_if_PAUrequested_streamable_texture_render_vostok__Uremove_requested_texture_predicate__5__process_streaming_scene_23_QAEXPAVrenderer_context_23_ABVfloat4x4_math_3_Vfloat3_93_II_Z__priv_stlp_std__YAPAUrequested_streamable_texture_render_vostok__PAU234_0Uremove_requested_texture_predicate__5__process_streaming_scene_34_QAEXPAVrenderer_context_34_ABVfloat4x4_math_4_Vfloat3_math_4_II_Z_ABUrandom_access_iterator_tag_1__Z(v11, v9);
    v13 = *(vostok::buffer_vector<vostok::render::requested_streamable_texture> **)__pred;
    if ( if_PAUrequested_streamable_texture_render_vostok__Uremove_requested_texture_predicate__5__process_streaming_scene_23_QAEXPAVrenderer_context_23_ABVfloat4x4_math_3_Vfloat3_93_II_Z__priv_stlp_std__YAPAUrequested_streamable_texture_render_vostok__PAU234_0Uremove_requested_texture_predicate__5__process_streaming_scene_34_QAEXPAVrenderer_context_34_ABVfloat4x4_math_4_Vfloat3_math_4_II_Z_ABUrandom_access_iterator_tag_1__Z != v9 )
    {
      v78.l_.a5_.t_ = *(float *)__pred;
      if_PAUrequested_streamable_texture_render_vostok__Uremove_requested_texture_predicate__5__process_streaming_scene_23_QAEXPAVrenderer_context_23_ABVfloat4x4_math_3_Vfloat3_93_II_Z__priv_stlp_std__YAPAUrequested_streamable_texture_render_vostok__PAU234_0Uremove_requested_texture_predicate__5__process_streaming_scene_34_QAEXPAVrenderer_context_34_ABVfloat4x4_math_4_Vfloat3_math_4_II_Z_ABUrandom_access_iterator_tag_1__Z = ___remove_copy_if_PAUrequested_streamable_texture_render_vostok__PAU123_Uremove_requested_texture_predicate__5__process_streaming_scene_23_QAEXPAVrenderer_context_23_ABVfloat4x4_math_3_Vfloat3_93_II_Z__stlp_std__YAPAUrequested_streamable_texture_render_vostok__PAU123_00Uremove_requested_texture_predicate__5__process_streaming_scene_23_QAEXPAVrenderer_context_23_ABVfloat4x4_math_3_Vfloat3_93_II_Z__Z(if_PAUrequested_streamable_texture_render_vostok__Uremove_requested_texture_predicate__5__process_streaming_scene_23_QAEXPAVrenderer_context_23_ABVfloat4x4_math_3_Vfloat3_93_II_Z__priv_stlp_std__YAPAUrequested_streamable_texture_render_vostok__PAU234_0Uremove_requested_texture_predicate__5__process_streaming_scene_34_QAEXPAVrenderer_context_34_ABVfloat4x4_math_4_Vfloat3_math_4_II_Z_ABUrandom_access_iterator_tag_1__Z + 1, v9, if_PAUrequested_streamable_texture_render_vostok__Uremove_requested_texture_predicate__5__process_streaming_scene_23_QAEXPAVrenderer_context_23_ABVfloat4x4_math_3_Vfloat3_93_II_Z__priv_stlp_std__YAPAUrequested_streamable_texture_render_vostok__PAU234_0Uremove_requested_texture_predicate__5__process_streaming_scene_34_QAEXPAVrenderer_context_34_ABVfloat4x4_math_4_Vfloat3_math_4_II_Z_ABUrandom_access_iterator_tag_1__Z);
    }
    *(_DWORD *)__pred = if_PAUrequested_streamable_texture_render_vostok__Uremove_requested_texture_predicate__5__process_streaming_scene_23_QAEXPAVrenderer_context_23_ABVfloat4x4_math_3_Vfloat3_93_II_Z__priv_stlp_std__YAPAUrequested_streamable_texture_render_vostok__PAU234_0Uremove_requested_texture_predicate__5__process_streaming_scene_34_QAEXPAVrenderer_context_34_ABVfloat4x4_math_4_Vfloat3_math_4_II_Z_ABUrandom_access_iterator_tag_1__Z;
    vostok::buffer_vector<vostok::render::requested_streamable_texture>::erase(
      v13,
      v10,
      (vostok::render::requested_streamable_texture **)__pred,
      (const vostok::render::requested_streamable_texture **)end);
    if ( (v10[1] - *v10) / 280 )
    {
      vostok::render::scene::process_ready_streaming_textures((vostok::render::scene *)0x118, f);
    }
    else
    {
      v14 = *(_DWORD *)&s_game.m_static_memory[f + 980];
      v15 = &s_game.m_static_memory[f + 976];
      v16 = *(_DWORD *)&s_game.m_static_memory[f + 976];
      *(_DWORD *)__pred = v14;
      v17 = *(unsigned int *)((char *)&vostok::quasi_singleton<vostok::render::resource_manager>::pinst->sh_created
                            + (_DWORD)&loc_948DA
                            + 2);
      if ( v17 )
      {
        v18 = *(stlp_std::priv::_Rb_tree_node_base **)(v17 + 12);
        v19 = (stlp_std::priv::_Rb_tree_node_base *)(v17 + 4);
        while ( v18 != v19 )
        {
          M_left = v18[2]._M_left;
          M_parent = M_left[6]._M_parent;
          v22 = M_left[6]._M_left;
          while ( M_parent != v22 )
          {
            BYTE1(M_parent->_M_left) = 0;
            BYTE2(M_parent->_M_left) = 0;
            M_parent = (stlp_std::priv::_Rb_tree_node_base *)((char *)M_parent + 12);
          }
          v18 = stlp_std::priv::_Rb_global<bool>::_M_increment(v18);
        }
        while ( v16 != *(_DWORD *)__pred )
        {
          v23 = *(stlp_std::priv::_Rb_tree_node_base **)(v16 + 12);
          if ( v23 != *(stlp_std::priv::_Rb_tree_node_base **)(v16 + 8) || *(_BYTE *)(v16 + 104) )
          {
            v24 = *(_DWORD *)(v16 + 36);
            v25 = *(stlp_std::priv::_Rb_tree_node_base **)(*(_DWORD *)(*(int *)((char *)&dword_96154
                                                                              + LODWORD(__formal.f_.f_))
                                                                     + 328 * *(_DWORD *)(v16 + 4)
                                                                     + 276)
                                                         + 80);
            key.m_pools._M_t._M_node_count = 0;
            key.mem_not_on_pool = v24;
            v26 = *(_DWORD *)(v16 + 40);
            key.m_pools._M_t._M_header._M_data._M_left = v25;
            v27 = *(unsigned int *)((char *)&vostok::quasi_singleton<vostok::render::resource_manager>::pinst->sh_created
                                  + (_DWORD)&loc_948DA
                                  + 2);
            key.m_pools._M_t._M_header._M_data._M_right = v23;
            *(_DWORD *)&key.m_pools._M_t._M_header._M_data._M_color = v26;
            key.m_pools._M_t._M_header._M_data._M_parent = *(stlp_std::priv::_Rb_tree_node_base **)(v16 + 20);
            v28 = vostok::render::texture_storage::has_free_space(
                    &key,
                    v27,
                    (const vostok::render::texture_pool_key *)&key);
            if ( v28 )
            {
              BYTE2(v28->_M_left) = 0;
              BYTE1(v28->_M_left) = 1;
            }
            else
            {
              v29 = (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)*((_DWORD *)v15 + 1);
              v30 = *(vostok::render::potential_request **)v15;
              i = v29;
              end[0] = (vostok::render::requested_streamable_texture *)v30;
              if ( v29 != (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v30 )
              {
                v31 = v29 - 25;
                do
                {
                  if ( v31[16].m_object == *(vostok::render::res_texture **)(v16 + 76) )
                    break;
                  if ( !LOBYTE(v31[24].m_object)
                    && v31->m_object > v31[-1].m_object
                    && v31->m_object == *(vostok::render::res_texture **)(v16 + 12)
                    && v31[6].m_object == *(vostok::render::res_texture **)(v16 + 36)
                    && v31[7].m_object == *(vostok::render::res_texture **)(v16 + 40)
                    && v31[2].m_object == *(vostok::render::res_texture **)(v16 + 20)
                    && v31[4].m_object == *(vostok::render::res_texture **)(v16 + 28) )
                  {
                    vostok::render::potential_request::cancel_request(v30, (int)&v31[-3]);
                  }
                  i -= 28;
                  v31 -= 28;
                }
                while ( i != (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)end[0] );
              }
              v32 = *((_DWORD *)v15 + 1);
              if ( v32 != *(_DWORD *)v15 )
              {
                v33 = v32 - 104;
                do
                {
                  if ( *(_DWORD *)(v33 + 68) == *(_DWORD *)(v16 + 76) )
                    break;
                  if ( !*(_BYTE *)(v33 + 100) )
                  {
                    v30 = *(vostok::render::potential_request **)v33;
                    if ( *(_DWORD *)v33 == *(_DWORD *)(v16 + 12)
                      && v30 != *(vostok::render::potential_request **)(v33 + 4) )
                    {
                      v30 = *(vostok::render::potential_request **)(v33 + 36);
                      if ( v30 == *(vostok::render::potential_request **)(v16 + 36) )
                      {
                        v30 = *(vostok::render::potential_request **)(v33 + 40);
                        if ( v30 == *(vostok::render::potential_request **)(v16 + 40) )
                        {
                          v30 = *(vostok::render::potential_request **)(v33 + 12);
                          if ( v30 == *(vostok::render::potential_request **)(v16 + 20) )
                          {
                            v30 = *(vostok::render::potential_request **)(v33 + 20);
                            if ( v30 == *(vostok::render::potential_request **)(v16 + 28) )
                              break;
                          }
                        }
                      }
                    }
                  }
                  v32 -= 112;
                  v33 -= 112;
                }
                while ( v32 != *(_DWORD *)v15 );
              }
              vostok::render::potential_request::cancel_request(v30, v16);
            }
          }
          v16 += 112;
        }
      }
      v34 = *(vostok::render::potential_request **)&s_game.m_static_memory[LODWORD(__formal.f_.f_) + 980];
      LOBYTE(end[0]) = 0;
      *(vostok::render::requested_streamable_texture **)&v78.l_.a5_.t_ = end[0];
      *(_DWORD *)__pred = v34;
      v89 = v34;
      if_PAUpotential_request_render_vostok__Uremove_request_predicate__CG___process_streaming_scene_23_QAEXPAVrenderer_context_23_ABVfloat4x4_math_3_Vfloat3_93_II_Z__priv_stlp_std__YAPAUpotential_request_render_vostok__PAU234_0Uremove_request_predicate__CG___process_streaming_scene_34_QAEXPAVrenderer_context_34_ABVfloat4x4_math_4_Vfloat3_math_4_II_Z_ABUrandom_access_iterator_tag_1__Z = _____find_if_PAUpotential_request_render_vostok__Uremove_request_predicate__CG___process_streaming_scene_23_QAEXPAVrenderer_context_23_ABVfloat4x4_math_3_Vfloat3_93_II_Z__priv_stlp_std__YAPAUpotential_request_render_vostok__PAU234_0Uremove_request_predicate__CG___process_streaming_scene_34_QAEXPAVrenderer_context_34_ABVfloat4x4_math_4_Vfloat3_math_4_II_Z_ABUrandom_access_iterator_tag_1__Z(v34);
      t = v78.l_.a5_.t_;
      if ( if_PAUpotential_request_render_vostok__Uremove_request_predicate__CG___process_streaming_scene_23_QAEXPAVrenderer_context_23_ABVfloat4x4_math_3_Vfloat3_93_II_Z__priv_stlp_std__YAPAUpotential_request_render_vostok__PAU234_0Uremove_request_predicate__CG___process_streaming_scene_34_QAEXPAVrenderer_context_34_ABVfloat4x4_math_4_Vfloat3_math_4_II_Z_ABUrandom_access_iterator_tag_1__Z != v34 )
      {
        v37 = if_PAUpotential_request_render_vostok__Uremove_request_predicate__CG___process_streaming_scene_23_QAEXPAVrenderer_context_23_ABVfloat4x4_math_3_Vfloat3_93_II_Z__priv_stlp_std__YAPAUpotential_request_render_vostok__PAU234_0Uremove_request_predicate__CG___process_streaming_scene_34_QAEXPAVrenderer_context_34_ABVfloat4x4_math_4_Vfloat3_math_4_II_Z_ABUrandom_access_iterator_tag_1__Z;
        while ( ++if_PAUpotential_request_render_vostok__Uremove_request_predicate__CG___process_streaming_scene_23_QAEXPAVrenderer_context_23_ABVfloat4x4_math_3_Vfloat3_93_II_Z__priv_stlp_std__YAPAUpotential_request_render_vostok__PAU234_0Uremove_request_predicate__CG___process_streaming_scene_34_QAEXPAVrenderer_context_34_ABVfloat4x4_math_4_Vfloat3_math_4_II_Z_ABUrandom_access_iterator_tag_1__Z != v34 )
        {
          t = *(float *)&if_PAUpotential_request_render_vostok__Uremove_request_predicate__CG___process_streaming_scene_23_QAEXPAVrenderer_context_23_ABVfloat4x4_math_3_Vfloat3_93_II_Z__priv_stlp_std__YAPAUpotential_request_render_vostok__PAU234_0Uremove_request_predicate__CG___process_streaming_scene_34_QAEXPAVrenderer_context_34_ABVfloat4x4_math_4_Vfloat3_math_4_II_Z_ABUrandom_access_iterator_tag_1__Z->wanted_mips;
          if ( LODWORD(t) != if_PAUpotential_request_render_vostok__Uremove_request_predicate__CG___process_streaming_scene_23_QAEXPAVrenderer_context_23_ABVfloat4x4_math_3_Vfloat3_93_II_Z__priv_stlp_std__YAPAUpotential_request_render_vostok__PAU234_0Uremove_request_predicate__CG___process_streaming_scene_34_QAEXPAVrenderer_context_34_ABVfloat4x4_math_4_Vfloat3_math_4_II_Z_ABUrandom_access_iterator_tag_1__Z->resident_mips
            || if_PAUpotential_request_render_vostok__Uremove_request_predicate__CG___process_streaming_scene_23_QAEXPAVrenderer_context_23_ABVfloat4x4_math_3_Vfloat3_93_II_Z__priv_stlp_std__YAPAUpotential_request_render_vostok__PAU234_0Uremove_request_predicate__CG___process_streaming_scene_34_QAEXPAVrenderer_context_34_ABVfloat4x4_math_4_Vfloat3_math_4_II_Z_ABUrandom_access_iterator_tag_1__Z->need_refresh )
          {
            qmemcpy(
              v37,
              if_PAUpotential_request_render_vostok__Uremove_request_predicate__CG___process_streaming_scene_23_QAEXPAVrenderer_context_23_ABVfloat4x4_math_3_Vfloat3_93_II_Z__priv_stlp_std__YAPAUpotential_request_render_vostok__PAU234_0Uremove_request_predicate__CG___process_streaming_scene_34_QAEXPAVrenderer_context_34_ABVfloat4x4_math_4_Vfloat3_math_4_II_Z_ABUrandom_access_iterator_tag_1__Z,
              sizeof(vostok::render::potential_request));
            t = 0.0;
            v34 = *(vostok::render::potential_request **)__pred;
            ++v37;
          }
        }
        if_PAUpotential_request_render_vostok__Uremove_request_predicate__CG___process_streaming_scene_23_QAEXPAVrenderer_context_23_ABVfloat4x4_math_3_Vfloat3_93_II_Z__priv_stlp_std__YAPAUpotential_request_render_vostok__PAU234_0Uremove_request_predicate__CG___process_streaming_scene_34_QAEXPAVrenderer_context_34_ABVfloat4x4_math_4_Vfloat3_math_4_II_Z_ABUrandom_access_iterator_tag_1__Z = v37;
      }
      end[0] = (vostok::render::requested_streamable_texture *)if_PAUpotential_request_render_vostok__Uremove_request_predicate__CG___process_streaming_scene_23_QAEXPAVrenderer_context_23_ABVfloat4x4_math_3_Vfloat3_93_II_Z__priv_stlp_std__YAPAUpotential_request_render_vostok__PAU234_0Uremove_request_predicate__CG___process_streaming_scene_34_QAEXPAVrenderer_context_34_ABVfloat4x4_math_4_Vfloat3_math_4_II_Z_ABUrandom_access_iterator_tag_1__Z;
      vostok::buffer_vector<vostok::render::potential_request>::erase(
        (vostok::buffer_vector<vostok::render::potential_request> *)LODWORD(t),
        (vostok::render::potential_request *const *)v15,
        (vostok::render::potential_request **)end,
        &v89);
      v38 = (*((_DWORD *)v15 + 1) - *(_DWORD *)v15) / 112;
      v89 = (vostok::render::potential_request *)v38;
      if ( v38 )
      {
        v39 = v38;
        v40 = vostok::memory::new_array_helper<vostok::render::texture_query_struct>::call<vostok::memory::doug_lea_allocator>(
                vostok::render::g_allocator,
                v38);
        *(_DWORD *)__pred = v40;
        v41 = alloca(276 * v39);
        v42 = *(vostok::render::potential_request **)v15;
        v90.allocator = (vostok::memory::single_size_fixed_allocator<36,16384,vostok::threading::single_threading_policy> *)v79;
        i = (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v79;
        *(_DWORD *)&key.m_calculate_memory_only = *(_DWORD *)&s_game.m_static_memory[LODWORD(__formal.f_.f_) + 980];
        if ( v42 != *(vostok::render::potential_request **)&key.m_calculate_memory_only )
        {
          end[0] = (vostok::render::requested_streamable_texture *)&v40->distance;
          do
          {
            wanted_mips = v42->wanted_mips;
            if ( wanted_mips != v42->resident_mips || v42->need_refresh )
            {
              v44 = 328 * v42->texture_index;
              value.texture.m_object = 0;
              v45 = *(int *)((char *)&dword_96154 + LODWORD(__formal.f_.f_)) + v44;
              value.path.m_begin = value.path.m_buffer;
              value.path.m_end = value.path.m_buffer;
              value.path.m_max_end = (char *)&value.texture;
              value.path.m_buffer[0] = 0;
              value.num_mips = wanted_mips;
              vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
                (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(v45 + 276),
                (vostok::render::res_texture *)&value.texture);
              if ( &value != (vostok::render::requested_streamable_texture *)v45 )
                vostok::buffer_string::operator=((vostok::buffer_string *)v45, &value.path);
              if ( *(int *)((char *)&dword_E8164 + LODWORD(__formal.f_.f_)) >= *(unsigned int *)((char *)&dword_E8160
                                                                                               + LODWORD(__formal.f_.f_)
                                                                                               + 8)
                && !`vostok::buffer_vector<vostok::render::requested_streamable_texture>::push_back'::`11'::debug_macro_helper_ignore_always )
              {
                v93 = 0;
                vostok::debug::on_error(
                  &v93,
                  process_error_true,
                  0,
                  "assertion_failed",
                  "fatal error",
                  "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
                  "vostok::buffer_vector<struct vostok::render::requested_streamable_texture>::push_back",
                  (const char *)0x12E,
                  "buffer overflow",
                  v79[0]);
                if ( vostok::debug::is_debugger_present() || v93 )
                  __debugbreak();
              }
              v46 = (char *)&dword_E8160 + LODWORD(__formal.f_.f_);
              vostok::buffer_vector<vostok::render::requested_streamable_texture>::construct(
                *(vostok::render::requested_streamable_texture **)((char *)&dword_E8164 + LODWORD(__formal.f_.f_)),
                &value);
              *((_DWORD *)v46 + 1) += 280;
              v82.m_begin = v83;
              v82.m_end = v83;
              v82.m_max_end = &v84;
              v83[0] = 0;
              v84 = 47;
              vostok::fixed_string<260>::fixed_string<260>(
                (vostok::fixed_string<260> *)LODWORD(v78.l_.a5_.t_),
                v80,
                value.path.m_begin);
              v81 = 47;
              vostok::fs_new::path_string_impl::assignf(
                &v82,
                v47,
                (vostok::buffer_string *)"%s/%s.dds",
                "resources/textures",
                v80[0].m_begin);
              if ( i )
              {
                vostok::fs_new::virtual_path_string::virtual_path_string(v48, (int)i);
                v50 = v49;
              }
              else
              {
                v50 = 0;
              }
              if ( v50 != &v82 )
                vostok::buffer_string::operator=(&v82, v50);
              value.texture.m_object->m_loaded = 0;
              v51 = end[0];
              value.texture.m_object->num_mips = v42->wanted_mips
                                               + (v42->num_max_mips < v42->wanted_mips
                                                ? v42->num_max_mips - v42->wanted_mips
                                                : 0);
              value.texture.m_object->loaded_num_mips = v42->wanted_mips
                                                      + (v42->num_max_mips < v42->wanted_mips
                                                       ? v42->num_max_mips - v42->wanted_mips
                                                       : 0);
              vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
                &value.texture,
                (vostok::render::res_texture *)&v51[-1].texture);
              v52 = v42->wanted_mips;
              i += 69;
              v51[-1].num_mips = v52;
              *(float *)&v51->path.m_begin = v42->distance;
              end[0] = (vostok::render::requested_streamable_texture *)v51->path.m_buffer;
              vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec(&value.texture);
              v39 = (unsigned int)v89;
            }
            ++v42;
          }
          while ( v42 != *(vostok::render::potential_request **)&key.m_calculate_memory_only );
        }
        v53 = alloca(8 * v39);
        allocator = v90.allocator;
        v55 = (vostok::render::scene *)v79;
        v56 = 0;
        for ( *(_DWORD *)&key.m_calculate_memory_only = v79; v56 < v39; ++v56 )
        {
          vtable = (const char *)allocator->m_on_out_of_memory.vtable;
          allocator = (vostok::memory::single_size_fixed_allocator<36,16384,vostok::threading::single_threading_policy> *)((char *)allocator + 276);
          v79[2 * v56] = vtable;
          v79[2 * v56 + 1] = (const char *)7;
        }
        end[0] = 0;
        if ( v39 )
        {
          v58 = *(_DWORD *)__pred + 4;
          do
          {
            *(_QWORD *)&v78.l_.a4_.t_ = (unsigned int)vostok::render::scene::on_textures_loaded;
            v78.l_.a3_.t_.m_object = *(vostok::render::res_texture **)v58;
            v78.l_.a1_.t_ = v55;
            HIDWORD(v78.f_.f_) = v55;
            vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
              (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v78.l_,
              (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(v58 - 4));
            boost::bind<void,vostok::render::scene,vostok::resources::queries_result &,vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,unsigned int,float,vostok::render::scene *,boost::arg<1>,vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,unsigned int,float>(
              *(void **)(v58 + 4),
              &__that,
              (vostok::render::scene *)__formal.f_.f_,
              (boost::_bi::value<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> >)*(unsigned __int8 *)&1_72,
              (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)v78.l_.a1_.t_,
              (boost::_bi::value<float>)v78.l_.a3_.t_.m_object,
              *(void (__thiscall *__ptr64 *)(vostok::render::scene *, vostok::resources::queries_result *, vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>, unsigned int, float))&v78.l_.a4_.t_);
            boost::_bi::bind_t<void,boost::_mfi::mf4<void,vostok::render::scene,vostok::resources::queries_result &,vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,unsigned int,float>,boost::_bi::list5<boost::_bi::value<vostok::render::scene *>,boost::arg<1>,boost::_bi::value<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>,boost::_bi::value<unsigned int>,boost::_bi::value<float>>>::bind_t<void,boost::_mfi::mf4<void,vostok::render::scene,vostok::resources::queries_result &,vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,unsigned int,float>,boost::_bi::list5<boost::_bi::value<vostok::render::scene *>,boost::arg<1>,boost::_bi::value<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>,boost::_bi::value<unsigned int>,boost::_bi::value<float>>>(
              (boost::_bi::bind_t<void,boost::_mfi::mf4<void,vostok::render::scene,vostok::resources::queries_result &,vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,unsigned int,float>,boost::_bi::list5<boost::_bi::value<vostok::render::scene *>,boost::arg<1>,boost::_bi::value<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> >,boost::_bi::value<unsigned int>,boost::_bi::value<float> > > *)&key,
              &__that);
            v86[0] = 0;
            boost::_bi::bind_t<void,boost::_mfi::mf4<void,vostok::render::scene,vostok::resources::queries_result &,vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,unsigned int,float>,boost::_bi::list5<boost::_bi::value<vostok::render::scene *>,boost::arg<1>,boost::_bi::value<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>,boost::_bi::value<unsigned int>,boost::_bi::value<float>>>::bind_t<void,boost::_mfi::mf4<void,vostok::render::scene,vostok::resources::queries_result &,vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,unsigned int,float>,boost::_bi::list5<boost::_bi::value<vostok::render::scene *>,boost::arg<1>,boost::_bi::value<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>,boost::_bi::value<unsigned int>,boost::_bi::value<float>>>(
              &v78,
              (const boost::_bi::bind_t<void,boost::_mfi::mf4<void,vostok::render::scene,vostok::resources::queries_result &,vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,unsigned int,float>,boost::_bi::list5<boost::_bi::value<vostok::render::scene *>,boost::arg<1>,boost::_bi::value<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> >,boost::_bi::value<unsigned int>,boost::_bi::value<float> > > *)&key);
            boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf4<void,vostok::render::scene,vostok::resources::queries_result &,vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,unsigned int,float>,boost::_bi::list5<boost::_bi::value<vostok::render::scene *>,boost::arg<1>,boost::_bi::value<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>,boost::_bi::value<unsigned int>,boost::_bi::value<float>>>>(
              v59,
              (int)v86,
              v78);
            vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec((vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&key.m_pools._M_t._M_header._M_data._M_left);
            vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec(&__that.l_.a3_.t_);
            v60 = end[0];
            vostok::resources::query_resource(
              *(const char **)(*(_DWORD *)&key.m_calculate_memory_only + 8 * (int)end[0]),
              *(vostok::variant<32> **)(*(_DWORD *)&key.m_calculate_memory_only + 8 * (int)end[0] + 4),
              vostok::render::g_allocator,
              0,
              0,
              assert_on_fail_true);
            boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
              v61,
              v86);
            v58 += 12;
            end[0] = (vostok::render::requested_streamable_texture *)((char *)&v60->path.m_begin + 1);
          }
          while ( (char *)&v60->path.m_begin + 1 < (char *)v89 );
        }
        v90.allocator = (vostok::memory::single_size_fixed_allocator<36,16384,vostok::threading::single_threading_policy> *)vostok::render::g_allocator;
        if ( *(_DWORD *)__pred )
        {
          v62 = (char *)(*(_DWORD *)__pred - 8);
          v63 = *(_DWORD *)(*(_DWORD *)__pred - 8 + 4);
          v64 = (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(*(_DWORD *)__pred + v63 * *(_DWORD *)(*(_DWORD *)__pred - 8));
          for ( i = *(vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)__pred;
                i != v64;
                i = (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)((char *)i + v63) )
          {
            vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec(i);
          }
          vostok::memory::doug_lea_allocator::free_impl(
            (vostok::memory::doug_lea_allocator *)v55,
            (int)v90.allocator,
            v62,
            v79[0],
            v79[1],
            (const unsigned int)v79[2]);
        }
      }
      v65 = (int)__formal.f_.f_;
      v66 = *(vostok::render::streamable_texture_info **)((char *)&dword_96158 + LODWORD(__formal.f_.f_));
      v67 = *(vostok::render::streamable_texture_info **)((char *)&dword_96154 + LODWORD(__formal.f_.f_));
      v68 = (vostok::memory::single_size_fixed_allocator<36,16384,vostok::threading::single_threading_policy> *)(LODWORD(__formal.f_.f_) + 280);
      *(_DWORD *)&key.m_calculate_memory_only = v66;
      if_PAUstreamable_texture_info_render_vostok__Uremove_texture_predicate__DD___process_streaming_scene_23_QAEXPAVrenderer_context_23_ABVfloat4x4_math_3_Vfloat3_93_II_Z__priv_stlp_std__YAPAUstreamable_texture_info_render_vostok__PAU234_0Uremove_texture_predicate__DD___process_streaming_scene_34_QAEXPAVrenderer_context_34_ABVfloat4x4_math_4_Vfloat3_math_4_II_Z_ABUrandom_access_iterator_tag_1__Z = _____find_if_PAUstreamable_texture_info_render_vostok__Uremove_texture_predicate__DD___process_streaming_scene_23_QAEXPAVrenderer_context_23_ABVfloat4x4_math_3_Vfloat3_93_II_Z__priv_stlp_std__YAPAUstreamable_texture_info_render_vostok__PAU234_0Uremove_texture_predicate__DD___process_streaming_scene_34_QAEXPAVrenderer_context_34_ABVfloat4x4_math_4_Vfloat3_math_4_II_Z_ABUrandom_access_iterator_tag_1__Z(v67, v66, (vostok::render::scene::process_streaming::__l51::remove_texture_predicate)(LODWORD(__formal.f_.f_) + 280));
      if ( if_PAUstreamable_texture_info_render_vostok__Uremove_texture_predicate__DD___process_streaming_scene_23_QAEXPAVrenderer_context_23_ABVfloat4x4_math_3_Vfloat3_93_II_Z__priv_stlp_std__YAPAUstreamable_texture_info_render_vostok__PAU234_0Uremove_texture_predicate__DD___process_streaming_scene_34_QAEXPAVrenderer_context_34_ABVfloat4x4_math_4_Vfloat3_math_4_II_Z_ABUrandom_access_iterator_tag_1__Z != v66 )
      {
        v90.allocator = v68;
        v71 = (int)if_PAUstreamable_texture_info_render_vostok__Uremove_texture_predicate__DD___process_streaming_scene_23_QAEXPAVrenderer_context_23_ABVfloat4x4_math_3_Vfloat3_93_II_Z__priv_stlp_std__YAPAUstreamable_texture_info_render_vostok__PAU234_0Uremove_texture_predicate__DD___process_streaming_scene_34_QAEXPAVrenderer_context_34_ABVfloat4x4_math_4_Vfloat3_math_4_II_Z_ABUrandom_access_iterator_tag_1__Z;
        LODWORD(__formal.f_.f_) = if_PAUstreamable_texture_info_render_vostok__Uremove_texture_predicate__DD___process_streaming_scene_23_QAEXPAVrenderer_context_23_ABVfloat4x4_math_3_Vfloat3_93_II_Z__priv_stlp_std__YAPAUstreamable_texture_info_render_vostok__PAU234_0Uremove_texture_predicate__DD___process_streaming_scene_34_QAEXPAVrenderer_context_34_ABVfloat4x4_math_4_Vfloat3_math_4_II_Z_ABUrandom_access_iterator_tag_1__Z
                                + 1;
        if ( &if_PAUstreamable_texture_info_render_vostok__Uremove_texture_predicate__DD___process_streaming_scene_23_QAEXPAVrenderer_context_23_ABVfloat4x4_math_3_Vfloat3_93_II_Z__priv_stlp_std__YAPAUstreamable_texture_info_render_vostok__PAU234_0Uremove_texture_predicate__DD___process_streaming_scene_34_QAEXPAVrenderer_context_34_ABVfloat4x4_math_4_Vfloat3_math_4_II_Z_ABUrandom_access_iterator_tag_1__Z[1] != v66 )
        {
          do
          {
            if ( !vostok::render::scene::process_streaming_::_51_::remove_texture_predicate::operator()(
                    &v90,
                    (const vostok::render::streamable_texture_info *)__formal.f_.f_) )
            {
              vostok::render::streamable_texture_info::operator=(
                v70,
                v71,
                (const vostok::render::streamable_texture_info *)__formal.f_.f_);
              v71 += 328;
            }
            LODWORD(__formal.f_.f_) += 328;
          }
          while ( (vostok::render::streamable_texture_info *)LODWORD(__formal.f_.f_) != v66 );
        }
        if_PAUstreamable_texture_info_render_vostok__Uremove_texture_predicate__DD___process_streaming_scene_23_QAEXPAVrenderer_context_23_ABVfloat4x4_math_3_Vfloat3_93_II_Z__priv_stlp_std__YAPAUstreamable_texture_info_render_vostok__PAU234_0Uremove_texture_predicate__DD___process_streaming_scene_34_QAEXPAVrenderer_context_34_ABVfloat4x4_math_4_Vfloat3_math_4_II_Z_ABUrandom_access_iterator_tag_1__Z = (vostok::render::streamable_texture_info *)v71;
      }
      LODWORD(__formal.f_.f_) = if_PAUstreamable_texture_info_render_vostok__Uremove_texture_predicate__DD___process_streaming_scene_23_QAEXPAVrenderer_context_23_ABVfloat4x4_math_3_Vfloat3_93_II_Z__priv_stlp_std__YAPAUstreamable_texture_info_render_vostok__PAU234_0Uremove_texture_predicate__DD___process_streaming_scene_34_QAEXPAVrenderer_context_34_ABVfloat4x4_math_4_Vfloat3_math_4_II_Z_ABUrandom_access_iterator_tag_1__Z;
      vostok::buffer_vector<vostok::render::streamable_texture_info>::erase(
        (vostok::buffer_vector<vostok::render::streamable_texture_info> *)v70,
        (int *)((char *)&dword_96154 + v65),
        (vostok::render::streamable_texture_info **)&__formal,
        (vostok::render::streamable_texture_info **)&key.m_calculate_memory_only);
      vostok::render::scene::update_streaming_texture_parameters(v72, v65);
      is_set = vostok::command_line::key::is_set(v73, (int)&s_sync_streaming);
      vostok::render::texture_streaming_async_worker::start(
        (const vostok::fixed_vector<vostok::render::streamable_texture_info,1024> *)((char *)&dword_96154 + v65),
        (const vostok::math::float4x4 *)HIDWORD(__formal.f_.f_),
        (vostok::render::texture_streaming_async_worker *)((char *)&unk_8B9588 + v65),
        (const vostok::math::float3 *)&__formal.l_,
        LODWORD(__formal.l_.a5_.t_),
        screen_size_y,
        !is_set);
      vostok::render::scene::process_ready_streaming_textures(v75, v65);
      if ( vostok::command_line::key::is_set(v76, (int)&s_sync_streaming) )
        vostok::render::texture_streaming_async_worker::ensure_completion(v77, (int)&unk_8B9588 + v65);
    }
  }
}
