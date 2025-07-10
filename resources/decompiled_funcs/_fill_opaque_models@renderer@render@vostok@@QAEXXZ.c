void __thiscall vostok::render::renderer::fill_opaque_models(
        vostok::render::renderer *this,
        vostok::render::render_surface_instance *const *i)
{
  int v2; // ebx
  void **v3; // eax
  void **v4; // ecx
  int v5; // edi
  void **v6; // esi
  vostok::sound::sound_world *v7; // esi
  vostok::sound::sound_world *j; // ebx
  void (__thiscall *tick)(vostok::sound::world *); // eax
  stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *v10; // ecx
  vostok::render::material_effects *v11; // eax
  void **v12; // eax
  vostok::render::render_surface_instance ***v13; // edi
  int v14; // esi
  void **v15; // eax
  void **v16; // ecx
  void **v17; // ebx
  vostok::sound::sound_world *v18; // ebp
  stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *p_M_finish; // ecx
  vostok::sound::sound_world_vtbl *v20; // edi
  void (__thiscall *v21)(vostok::sound::world *); // eax
  vostok::render::material_effects *v22; // eax
  vostok::math::aabb *clear_resources; // ebx
  float *v24; // esi
  __int64 *v25; // eax
  float v26; // xmm1_4
  float v27; // xmm0_4
  float v28; // xmm4_4
  float v29; // xmm5_4
  float v30; // xmm3_4
  const vostok::math::float4x4 *v31; // xmm1_4
  float v32; // xmm0_4
  vostok::render::enum_vertex_input_type m_vertex_input_type; // eax
  bool v34; // al
  float v35; // xmm1_4
  char v36; // al
  vostok::sound::sound_world_vtbl *v37; // eax
  stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *M_finish; // ecx
  vostok::render::vector<vostok::render::render_surface_instance *> *p_opaque_models_lod1; // edi
  void **v40; // ebx
  void **M_start; // esi
  int v42; // ebp
  int v43; // edi
  vostok::render::vector<vostok::render::render_surface_instance *> *v44; // edi
  void **v45; // eax
  char *v46; // esi
  unsigned int v47; // eax
  char v48; // dl
  _DWORD *p_opaque_models; // ecx
  unsigned int v50; // ecx
  int *p_e; // eax
  int v52; // ecx
  vostok::render::grass_render_model *m_object; // eax
  unsigned int v54; // ecx
  unsigned __int8 *v55; // ebp
  unsigned int v56; // esi
  int v57; // eax
  _DWORD *v58; // eax
  void **v59; // ebx
  unsigned __int8 *v60; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  void **v62; // eax
  char *v63; // esi
  unsigned int v64; // eax
  char v65; // dl
  _DWORD *v66; // ecx
  unsigned int v67; // ecx
  int *v68; // eax
  int v69; // ecx
  vostok::render::grass_render_model *v70; // eax
  unsigned int v71; // ecx
  unsigned __int8 *v72; // ebp
  unsigned int v73; // esi
  int v74; // eax
  _DWORD *v75; // eax
  void **v76; // ebx
  unsigned __int8 *v77; // eax
  void *v78; // esi
  vostok::render::grass_render_model *v79; // ecx
  vostok::render::grass_render_model *v80; // ecx
  unsigned int v81; // [esp-4h] [ebp-6Ch]
  const vostok::math::float4x4 *v82; // [esp+0h] [ebp-68h]
  const vostok::render::material_effects *me; // [esp+14h] [ebp-54h]
  int mea; // [esp+14h] [ebp-54h]
  int meb; // [esp+14h] [ebp-54h]
  vostok::render::render_surface_instance *const *e; // [esp+18h] [ebp-50h] BYREF
  vostok::render::vector<vostok::render::render_surface_instance *> *opaque_models; // [esp+1Ch] [ebp-4Ch] BYREF
  vostok::render::vector<vostok::render::render_surface_instance *> opaque_models_lod1; // [esp+20h] [ebp-48h] BYREF
  vostok::render::vector<vostok::render::render_surface_instance *> opaque_models_lod0; // [esp+2Ch] [ebp-3Ch] BYREF
  __int64 v90; // [esp+38h] [ebp-30h]
  __int64 v91; // [esp+40h] [ebp-28h]
  __int64 v92; // [esp+48h] [ebp-20h]
  char v93[24]; // [esp+50h] [ebp-18h] BYREF
  void **ia; // [esp+6Ch] [ebp+4h]
  void **ib; // [esp+6Ch] [ebp+4h]

  if ( !*((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
        + 298) )
  {
    v2 = *(_DWORD *)(*((_DWORD *)i + 88) + 12392);
    v3 = *(void ***)(v2 + 1344);
    v4 = *(void ***)(v2 + 1340);
    v5 = v2 + 1340;
    if ( v4 != v3 )
    {
      v6 = stlp_std::priv::__copy_ptrs<void * *,void * *>(v3, v3, v4);
      stlp_std::_Destroy<vostok::fs_new::virtual_path_string>();
      *(_DWORD *)(v2 + 1344) = v6;
    }
    v7 = boost::get_pointer<vostok::sound::sound_scene>(*(vostok::sound::sound_world **)(v2 + 1328));
    for ( j = boost::get_pointer<vostok::sound::sound_scene>(*(vostok::sound::sound_world **)(v2 + 1332));
          v7 != j;
          v7 = (vostok::sound::sound_world *)((char *)v7 + 4) )
    {
      tick = v7->tick;
      v10 = (stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *)*((_DWORD *)tick + 37);
      if ( !v10 || s_use_one_material_value )
      {
        v10 = (stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *)*((_DWORD *)tick + 1);
        v11 = s_nomaterial_material_effects[(_DWORD)v10];
      }
      else
      {
        v11 = (vostok::render::material_effects *)&v10[22];
      }
      if ( v11->m_effects[0].m_object )
      {
        v12 = *(void ***)(v5 + 4);
        if ( v12 == *(void ***)(v5 + 8) )
        {
          stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *>>::_M_insert_overflow(
            v10,
            v5,
            v12,
            (void *const *)&v7->__vftable,
            (const stlp_std::__true_type *)1,
            1,
            (bool)v82);
        }
        else
        {
          *v12 = v7->__vftable;
          *(_DWORD *)(v5 + 4) += 4;
        }
      }
    }
    v13 = (vostok::render::render_surface_instance ***)(*(_DWORD *)(*((_DWORD *)i + 88) + 12392) + 1340);
    if ( s_sorting_value )
      stlp_std::sort<vostok::render::render_surface_instance * *,vostok::render::sort_by_vs_predicate>(*v13, v13[1], 0);
    if ( s_sorting3_value )
      stlp_std::sort<vostok::render::render_surface_instance * *,vostok::render::sort_by_texture_predicate>(
        *v13,
        v13[1],
        0);
    return;
  }
  v14 = *(_DWORD *)(*((_DWORD *)i + 88) + 12392);
  v15 = *(void ***)(v14 + 1344);
  v16 = *(void ***)(v14 + 1340);
  opaque_models = (vostok::render::vector<vostok::render::render_surface_instance *> *)(v14 + 1340);
  if ( v16 != v15 )
  {
    v17 = stlp_std::priv::__copy_ptrs<void * *,void * *>(v15, v15, v16);
    stlp_std::_Destroy<vostok::fs_new::virtual_path_string>();
    *(_DWORD *)(v14 + 1344) = v17;
  }
  memset(&opaque_models_lod0, 0, sizeof(opaque_models_lod0));
  memset(&opaque_models_lod1, 0, sizeof(opaque_models_lod1));
  v18 = boost::get_pointer<vostok::sound::sound_scene>(*(vostok::sound::sound_world **)(v14 + 1328));
  for ( e = (vostok::render::render_surface_instance *const *)boost::get_pointer<vostok::sound::sound_scene>(*(vostok::sound::sound_world **)(v14 + 1332));
        v18 != (vostok::sound::sound_world *)e;
        v18 = (vostok::sound::sound_world *)((char *)v18 + 4) )
  {
    v20 = v18->__vftable;
    v21 = v18->tick;
    p_M_finish = (stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *)*((_DWORD *)v21 + 37);
    if ( !p_M_finish || s_use_one_material_value )
    {
      p_M_finish = (stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *)*((_DWORD *)v21 + 1);
      v22 = s_nomaterial_material_effects[(_DWORD)p_M_finish];
    }
    else
    {
      v22 = (vostok::render::material_effects *)&p_M_finish[22];
    }
    me = v22;
    if ( !v22->m_effects[0].m_object )
      continue;
    clear_resources = (vostok::math::aabb *)v20->clear_resources;
    v24 = (float *)(*((_DWORD *)i + 88) + 16900);
    v25 = (__int64 *)(*(int (__thiscall **)(vostok::sound::world_user *(__thiscall *)(vostok::sound::world *), char *))(*(_DWORD *)v20->get_logic_world_user + 60))(
                       v20->get_logic_world_user,
                       v93);
    v90 = *v25;
    v91 = v25[1];
    v92 = v25[2];
    vostok::math::aabb::modify(clear_resources, v82);
    v26 = (float)(*(float *)&v92 - *((float *)&v90 + 1)) * 0.5;
    v27 = (float)(*((float *)&v91 + 1) - *(float *)&v90) * 0.5;
    v28 = v24[1] - (float)((float)(*(float *)&v92 + *((float *)&v90 + 1)) * 0.5);
    v29 = v24[2] - (float)((float)(*((float *)&v92 + 1) + *(float *)&v91) * 0.5);
    v30 = (float)((float)((float)(*v24 - (float)((float)(*((float *)&v91 + 1) + *(float *)&v90) * 0.5))
                        * (float)(*v24 - (float)((float)(*((float *)&v91 + 1) + *(float *)&v90) * 0.5)))
                + (float)(v29 * v29))
        + (float)(v28 * v28);
    if ( v26 <= (float)((float)(*((float *)&v92 + 1) - *(float *)&v91) * 0.5) )
      v26 = (float)(*((float *)&v92 + 1) - *(float *)&v91) * 0.5;
    if ( v27 <= v26 )
      v27 = v26;
    if ( v30 <= 0.000001 )
      v30 = Wm4::Math<float>::ZERO_TOLERANCE;
    v31 = 0;
    v32 = v27 / v30;
    if ( v32 <= 0.0 || (v31 = clear_value, *(float *)&clear_value < v32) )
      v32 = *(float *)&v31;
    p_M_finish = (stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *)me;
    m_vertex_input_type = me->m_vertex_input_type;
    v34 = m_vertex_input_type == skeletal_4_bones_mesh_vertex_input_type
       || m_vertex_input_type == skeletal_3_bones_mesh_vertex_input_type
       || m_vertex_input_type == skeletal_2_bones_mesh_vertex_input_type
       || m_vertex_input_type == skeletal_1_bones_mesh_vertex_input_type;
    if ( s_debug_use_skeletel_mesh_lods && v34 )
      v35 = 0.0099999998;
    else
      v35 = 0.0049999999;
    if ( v32 <= v35 )
    {
      if ( v32 > 0.000033299999 || !v20->tick || (v36 = 2, *((_DWORD *)v20->tick + 1) != 1) )
        v36 = 1;
    }
    else
    {
      v36 = 0;
    }
    LOBYTE(v18->get_calculation_type) = v36;
    *(float *)&v20->get_speed_of_sound = v32;
    v37 = v18->__vftable;
    LOBYTE(p_M_finish) = v18->get_calculation_type;
    if ( (_BYTE)p_M_finish )
    {
      if ( (_BYTE)p_M_finish == 1 )
      {
        M_finish = (stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *)opaque_models_lod1._M_impl._M_finish;
        if ( opaque_models_lod1._M_impl._M_finish == opaque_models_lod1._M_impl._M_end_of_storage._M_data )
        {
          p_opaque_models_lod1 = &opaque_models_lod1;
          goto LABEL_59;
        }
        *opaque_models_lod1._M_impl._M_finish = v37;
        p_M_finish = (stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *)&M_finish->_M_finish;
        opaque_models_lod1._M_impl._M_finish = (void **)&p_M_finish->_M_start;
      }
    }
    else
    {
      M_finish = (stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *)opaque_models_lod0._M_impl._M_finish;
      if ( opaque_models_lod0._M_impl._M_finish == opaque_models_lod0._M_impl._M_end_of_storage._M_data )
      {
        p_opaque_models_lod1 = &opaque_models_lod0;
LABEL_59:
        stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *>>::_M_insert_overflow(
          M_finish,
          (int)p_opaque_models_lod1,
          (void **)&M_finish->_M_start,
          (void *const *)&v18->__vftable,
          (const stlp_std::__true_type *)1,
          1,
          (bool)v82);
        continue;
      }
      *opaque_models_lod0._M_impl._M_finish = v37;
      p_M_finish = (stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *)&M_finish->_M_finish;
      opaque_models_lod0._M_impl._M_finish = (void **)&p_M_finish->_M_start;
    }
  }
  v40 = opaque_models_lod0._M_impl._M_finish;
  M_start = opaque_models_lod0._M_impl._M_start;
  v42 = opaque_models_lod0._M_impl._M_finish - opaque_models_lod0._M_impl._M_start;
  if ( v42 )
  {
    if ( s_sorting_value )
      stlp_std::sort<vostok::render::render_surface_instance * *,vostok::render::sort_by_vs_predicate>(
        (vostok::render::render_surface_instance **)opaque_models_lod0._M_impl._M_start,
        (vostok::render::render_surface_instance **)opaque_models_lod0._M_impl._M_finish,
        (vostok::render::sort_by_ps_predicate)0x100000000LL);
    if ( s_sorting3_value )
      stlp_std::sort<vostok::render::render_surface_instance * *,vostok::render::sort_by_texture_predicate>(
        (vostok::render::render_surface_instance **)M_start,
        (vostok::render::render_surface_instance **)v40,
        (vostok::render::sort_by_texture_predicate)0x100000000LL);
  }
  v43 = opaque_models_lod1._M_impl._M_finish - opaque_models_lod1._M_impl._M_start;
  if ( v43 )
  {
    if ( s_sorting_value )
      stlp_std::sort<vostok::render::render_surface_instance * *,vostok::render::sort_by_vs_predicate>(
        (vostok::render::render_surface_instance **)opaque_models_lod1._M_impl._M_start,
        (vostok::render::render_surface_instance **)opaque_models_lod1._M_impl._M_finish,
        (vostok::render::sort_by_ps_predicate)0x300000000LL);
    if ( s_sorting3_value )
      stlp_std::sort<vostok::render::render_surface_instance * *,vostok::render::sort_by_texture_predicate>(
        (vostok::render::render_surface_instance **)opaque_models_lod1._M_impl._M_start,
        (vostok::render::render_surface_instance **)opaque_models_lod1._M_impl._M_finish,
        (vostok::render::sort_by_texture_predicate)0x300000000LL);
  }
  if ( v42 || v43 )
  {
    v81 = v42 + v43;
    v44 = opaque_models;
    stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *>>::reserve(
      p_M_finish,
      (int)opaque_models,
      v81);
    v45 = opaque_models_lod0._M_impl._M_start;
    for ( ia = opaque_models_lod0._M_impl._M_start; v45 != v40; ia = v45 )
    {
      v46 = (char *)v44->_M_impl._M_finish;
      if ( v46 == (char *)v44->_M_impl._M_end_of_storage._M_data )
      {
        v47 = (v46 - (char *)v44->_M_impl._M_start) >> 2;
        v48 = 1;
        e = (vostok::render::render_surface_instance *const *)1;
        opaque_models = (vostok::render::vector<vostok::render::render_surface_instance *> *)v47;
        if ( v47 == 0x3FFFFFFF )
LABEL_100:
          stlp_std::__stl_throw_length_error("vector");
        p_opaque_models = &opaque_models;
        if ( v47 <= 1 )
          p_opaque_models = &e;
        v50 = v47 + *p_opaque_models;
        mea = v50;
        if ( v50 > 0x3FFFFFFF || v50 < v47 )
        {
          v50 = 0x3FFFFFFF;
          mea = 0x3FFFFFFF;
        }
        e = (vostok::render::render_surface_instance *const *)v50;
        opaque_models = (vostok::render::vector<vostok::render::render_surface_instance *> *)1;
        p_e = (int *)&opaque_models;
        if ( v50 )
          p_e = (int *)&e;
        v52 = *p_e;
        m_object = vostok::render::g_allocator.m_object;
        v54 = 4 * v52;
        if ( !BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) || !v54 )
          v48 = 0;
        BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = v48;
        if ( v54 )
          v55 = (unsigned __int8 *)vostok_mspace_malloc(
                                     (void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick),
                                     v54);
        else
          v55 = 0;
        v56 = v46 - (char *)v44->_M_impl._M_start;
        if ( v56 )
        {
          memmove(v55, (unsigned __int8 *)v44->_M_impl._M_start, v56);
          v58 = (_DWORD *)(v56 + v57);
        }
        else
        {
          v58 = v55;
        }
        *v58 = *ia;
        v59 = (void **)(v58 + 1);
        v60 = (unsigned __int8 *)v44->_M_impl._M_start;
        if ( v44->_M_impl._M_start )
        {
          m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
          BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
          vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v60);
        }
        v45 = ia;
        v44->_M_impl._M_finish = v59;
        v40 = opaque_models_lod0._M_impl._M_finish;
        v44->_M_impl._M_start = (void **)v55;
        v44->_M_impl._M_end_of_storage._M_data = (void **)&v55[4 * mea];
      }
      else
      {
        *(_DWORD *)v46 = *v45;
        ++v44->_M_impl._M_finish;
      }
      ++v45;
    }
    v62 = opaque_models_lod1._M_impl._M_start;
    for ( ib = opaque_models_lod1._M_impl._M_start; v62 != opaque_models_lod1._M_impl._M_finish; ib = v62 )
    {
      v63 = (char *)v44->_M_impl._M_finish;
      if ( v63 == (char *)v44->_M_impl._M_end_of_storage._M_data )
      {
        v64 = (v63 - (char *)v44->_M_impl._M_start) >> 2;
        v65 = 1;
        e = (vostok::render::render_surface_instance *const *)1;
        opaque_models = (vostok::render::vector<vostok::render::render_surface_instance *> *)v64;
        if ( v64 == 0x3FFFFFFF )
          goto LABEL_100;
        v66 = &opaque_models;
        if ( v64 <= 1 )
          v66 = &e;
        v67 = v64 + *v66;
        meb = v67;
        if ( v67 > 0x3FFFFFFF || v67 < v64 )
        {
          v67 = 0x3FFFFFFF;
          meb = 0x3FFFFFFF;
        }
        e = (vostok::render::render_surface_instance *const *)v67;
        opaque_models = (vostok::render::vector<vostok::render::render_surface_instance *> *)1;
        v68 = (int *)&opaque_models;
        if ( v67 )
          v68 = (int *)&e;
        v69 = *v68;
        v70 = vostok::render::g_allocator.m_object;
        v71 = 4 * v69;
        if ( !BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) || !v71 )
          v65 = 0;
        BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = v65;
        if ( v71 )
          v72 = (unsigned __int8 *)vostok_mspace_malloc((void *)HIDWORD(v70->m_reconstruction_info_actuality_tick), v71);
        else
          v72 = 0;
        v73 = v63 - (char *)v44->_M_impl._M_start;
        if ( v73 )
        {
          memmove(v72, (unsigned __int8 *)v44->_M_impl._M_start, v73);
          v75 = (_DWORD *)(v73 + v74);
        }
        else
        {
          v75 = v72;
        }
        *v75 = *ib;
        v76 = (void **)(v75 + 1);
        v77 = (unsigned __int8 *)v44->_M_impl._M_start;
        if ( v44->_M_impl._M_start )
        {
          v78 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
          BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
          vostok_mspace_free(v78, v77);
        }
        v62 = ib;
        v44->_M_impl._M_start = (void **)v72;
        v44->_M_impl._M_finish = v76;
        v44->_M_impl._M_end_of_storage._M_data = (void **)&v72[4 * meb];
      }
      else
      {
        *(_DWORD *)v63 = *v62;
        ++v44->_M_impl._M_finish;
      }
      ++v62;
    }
  }
  if ( opaque_models_lod1._M_impl._M_start )
  {
    v79 = vostok::render::g_allocator.m_object;
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free((void *)HIDWORD(v79->m_reconstruction_info_actuality_tick), opaque_models_lod1._M_impl._M_start);
  }
  if ( opaque_models_lod0._M_impl._M_start )
  {
    v80 = vostok::render::g_allocator.m_object;
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free((void *)HIDWORD(v80->m_reconstruction_info_actuality_tick), opaque_models_lod0._M_impl._M_start);
  }
}
