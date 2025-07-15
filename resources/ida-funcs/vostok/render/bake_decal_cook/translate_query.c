void __thiscall vostok::render::bake_decal_cook::translate_query(
        vostok::render::bake_decal_cook *this,
        const vostok::variant<32> **parent)
{
  const vostok::variant<32> *v2; // esi
  vostok::render::render_model_instance_impl *v3; // ecx
  bool v4; // al
  vostok::render::bake_decal_cook_parameters *v5; // ebx
  vostok::particle::particle_system_instance_impl *m_object; // esi
  unsigned int *v7; // eax
  vostok::render::render_surface *v8; // ecx
  unsigned int v9; // eax
  bool has_passed_filters; // al
  vostok::render::material_effects *material_effects; // eax
  vostok::particle::particle_system_instance_impl *v12; // esi
  int v13; // eax
  const char **v14; // edi
  const char **v15; // ebx
  vostok::resources::resource_base *m_current_satisfaction_update_tick_high; // eax
  vostok::resources::resource_base *m_next_in_increase_quality_queue; // esi
  int i; // ecx
  int v19; // eax
  vostok::memory::doug_lea_allocator *v20; // esi
  char *v21; // eax
  vostok::memory::doug_lea_allocator *v22; // ecx
  char *v23; // eax
  const char **v24; // ebx
  vostok::render::stage_screen_space_reflections *v25; // ecx
  vostok::render::bake_decal_cook_parameters *v26; // edx
  _BYTE *v27; // eax
  const char *m_begin; // edi
  const char *v29; // esi
  float v30; // xmm0_4
  unsigned int v31; // ecx
  _BYTE *v32; // eax
  vostok::strings::detail::tuples *v33; // ecx
  _DWORD *v34; // ecx
  vostok::strings::detail::tuples *v35; // ecx
  void *v36; // esp
  vostok::strings::detail::tuples *v37; // ecx
  const char **v38; // ebx
  vostok::math::float4x4 *v39; // ecx
  vostok::math::float4x4 *v40; // eax
  float v41; // xmm0_4
  vostok::resources::resource_base_vtbl *v42; // eax
  void (__thiscall *link_child_resource)(struct vostok::resources::resource_base *, vostok::resources::resource_base *); // ecx
  int v44; // eax
  int v45; // ecx
  void *v46; // esp
  unsigned int v47; // edi
  int v48; // esi
  void *v49; // esp
  void *v50; // esp
  const vostok::variant<32> *v51; // eax
  const vostok::resources::request *v52; // ecx
  char *v53; // edx
  unsigned int v54; // edi
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v55; // ecx
  vostok::variant<32> *v56; // ecx
  int v57; // esi
  vostok::render::render_model_instance_impl *v58; // [esp-4h] [ebp-144h]
  vostok::render::render_surface *v59; // [esp-4h] [ebp-144h]
  unsigned int surface_index; // [esp-4h] [ebp-144h]
  const char *v61; // [esp+0h] [ebp-140h] BYREF
  const char *v62; // [esp+4h] [ebp-13Ch]
  unsigned int v63; // [esp+8h] [ebp-138h]
  unsigned int *v64; // [esp+Ch] [ebp-134h] BYREF
  unsigned int *v65; // [esp+10h] [ebp-130h]
  vostok::math::float4x4 *v66; // [esp+14h] [ebp-12Ch]
  _BYTE v67[256]; // [esp+18h] [ebp-128h] BYREF
  vostok::math::float4x4 v68; // [esp+118h] [ebp-28h] BYREF
  const vostok::resources::request *v69[3]; // [esp+158h] [ebp+18h] BYREF
  vostok::render::bake_decal_cook *v70; // [esp+164h] [ebp+24h]
  unsigned int v71; // [esp+168h] [ebp+28h]
  _DWORD v72[5]; // [esp+16Ch] [ebp+2Ch] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v73; // [esp+180h] [ebp+40h] BYREF
  const char **v74; // [esp+184h] [ebp+44h]
  vostok::fixed_string<64> *v75; // [esp+188h] [ebp+48h]
  int v76; // [esp+18Ch] [ebp+4Ch]
  vostok::render::bake_decal_cook_parameters *v77; // [esp+190h] [ebp+50h] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v78; // [esp+194h] [ebp+54h] BYREF
  const vostok::variant<32> *const *v79; // [esp+198h] [ebp+58h]
  vostok::fixed_string<64> *textures; // [esp+19Ch] [ebp+5Ch]
  char *v81; // [esp+1A0h] [ebp+60h]
  unsigned int v82; // [esp+1A4h] [ebp+64h]
  char v83; // [esp+1ABh] [ebp+6Bh]
  unsigned int v84; // [esp+1ACh] [ebp+6Ch]
  unsigned int v85; // [esp+1B0h] [ebp+70h]

  v85 = 0;
  v77 = 0;
  v2 = parent[66];
  v70 = this;
  if ( vostok::variant<32>::try_get<vostok::render::bake_decal_cook_parameters *>(
         (vostok::variant<32> *)this,
         (int)v2,
         &v77) )
  {
    v5 = v77;
    m_object = (vostok::particle::particle_system_instance_impl *)v77->model.m_object;
    v78.m_object = 0;
    if ( m_object )
    {
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v78);
      v78.m_object = m_object;
      v3 = (vostok::render::render_model_instance_impl *)_InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
    }
    v64 = (unsigned int *)v67;
    v65 = (unsigned int *)v67;
    v66 = &v68;
    vostok::render::render_model_instance_impl::get_all_surfaces(
      v3,
      (vostok::buffer_vector<vostok::render::render_surface_instance *> *)v78.m_object,
      (int)&v64);
    v7 = v64;
    v8 = 0;
    if ( v64 == v65 )
      goto LABEL_15;
    while ( v8 != (vostok::render::render_surface *)v5->surface_index )
    {
      ++v7;
      v8 = (vostok::render::render_surface *)((char *)v8 + 1);
      if ( v7 == v65 )
        goto LABEL_15;
    }
    v9 = *v7;
    v71 = v9;
    if ( v9 )
    {
      material_effects = vostok::render::render_surface::get_material_effects(v8, *(_DWORD *)(v9 + 16));
      vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
        &v73,
        (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&material_effects->m_effects[1]);
      v12 = v73.m_object;
      v13 = *(_DWORD *)(*(_DWORD *)(**(_DWORD **)(*(_DWORD *)(HIDWORD(v73.m_object[28].m_current_satisfaction_update_tick)
                                                            + 48)
                                                + 8)
                                  + 16)
                      + 4);
      v81 = 0;
      v14 = *(const char ***)(v13 + 2296);
      v15 = *(const char ***)(v13 + 2300);
      v84 = 0;
      while ( v14 != v15 )
      {
        if ( !vostok::detail::strcmp_s(*v14, "t_base") )
        {
          m_current_satisfaction_update_tick_high = (vostok::resources::resource_base *)HIDWORD(v12[28].m_current_satisfaction_update_tick);
          m_next_in_increase_quality_queue = v12[28].m_next_in_increase_quality_queue;
          for ( i = 0; ; ++i )
          {
            if ( m_current_satisfaction_update_tick_high == m_next_in_increase_quality_queue )
              goto LABEL_30;
            if ( i == 12 )
              break;
            m_current_satisfaction_update_tick_high = (vostok::resources::resource_base *)((char *)m_current_satisfaction_update_tick_high
                                                                                         + 4);
          }
          v42 = m_current_satisfaction_update_tick_high->__vftable;
          link_child_resource = (void (__thiscall *)(struct vostok::resources::resource_base *, vostok::resources::resource_base *))v42->link_child_resource;
          if ( link_child_resource == v42->unlink_child_resource )
          {
LABEL_30:
            v19 = 0;
            goto LABEL_31;
          }
          v44 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)link_child_resource + 16) + 12);
          if ( v84 < (*(_DWORD *)(v44 + 8) - *(_DWORD *)(v44 + 4)) >> 2 )
            v45 = *(_DWORD *)(*(_DWORD *)(v44 + 4) + 4 * v84);
          else
            v45 = 0;
          v19 = v45;
LABEL_31:
          if ( v19 )
            v81 = *(char **)(v19 + 164);
          break;
        }
        v14 += 21;
        ++v84;
      }
      v20 = vostok::render::g_allocator;
      v21 = type_info::raw_name(&vostok::render::decal_texture_slot `RTTI Type Descriptor');
      v23 = vostok::memory::doug_lea_allocator::malloc_impl(v22, (int)v20, 0xC80u, v21, v61, v62, v63);
      *(_DWORD *)v23 = 42;
      v23 += 4;
      v24 = (const char **)(v23 + 4);
      *(_DWORD *)v23 = 76;
      v74 = (const char **)(v23 + 4);
      vostok::memory::process_allocator::finalize_impl(v25);
      v26 = v77;
      v85 = 0;
      v79 = 0;
      v84 = 0;
      textures = v77->decals[0].textures;
      do
      {
        v82 = 0;
        v27 = (char *)&v24[19 * v85 + 18] + 1;
        v75 = textures;
        do
        {
          m_begin = v75->m_begin;
          v29 = v75->m_begin;
          v76 = (int)(v75->m_begin + 1);
          if ( &v29[strlen(v29) + 1] != (const char *)v76 )
          {
            v30 = s_bm_current_air_resistance;
            ++v85;
            *(v27 - 1) = (_BYTE)v79;
            *v27 = v82;
            v31 = v84;
            *(_DWORD *)(v27 - 9) = m_begin;
            v27[1] = 0;
            qmemcpy(v27 - 73, (char *)v26 + v31, 0x40u);
            *(float *)(v27 - 5) = v30;
            v27[2] = 0;
            v27 += 76;
          }
          ++v82;
          ++v75;
        }
        while ( v82 < 4 );
        v79 = (const vostok::variant<32> *const *)((char *)v79 + 1);
        v84 += 368;
        textures = (vostok::fixed_string<64> *)((char *)textures + 368);
      }
      while ( v84 < 0xE60 );
      v82 = 0;
      v84 = (unsigned int)v26->camouflage.textures;
      v83 = 0;
      v32 = (char *)&v24[19 * v85 + 18] + 1;
      do
      {
        v33 = (vostok::strings::detail::tuples *)v84;
        if ( strlen(*(const char **)v84) )
        {
          ++v85;
          *(v32 - 1) = (_BYTE)v33;
          *v32 = v82;
          v34 = (_DWORD *)v84;
          v32[1] = 1;
          *(_DWORD *)(v32 - 9) = *v34;
          qmemcpy(v32 - 73, &v26->camouflage, 0x40u);
          v33 = 0;
          *(float *)(v32 - 5) = v26->camouflage_tile;
          v32[2] = 0;
          v32 += 76;
          v83 = 1;
        }
        ++v82;
        v84 += 76;
      }
      while ( v82 < 4 );
      if ( v83 && v81 )
      {
        vostok::strings::detail::tuples::tuples(
          v33,
          (vostok::strings::detail::tuples *)&v68.lines[0].elements[3],
          v81,
          "_aoac");
        v36 = alloca(vostok::strings::detail::tuples::size(v35, (unsigned int *)&v68.i.w));
        vostok::strings::detail::tuples::concat(v37, (int)&v68.i.w, (char *)&v61);
        v38 = &v24[19 * v85];
        *((_BYTE *)v38 + 72) = 0;
        *((_BYTE *)v38 + 73) = 0;
        *((_BYTE *)v38 + 74) = 0;
        v38[16] = (const char *)&v61;
        v40 = vostok::math::float4x4::identity(v39, &v68);
        v41 = s_bm_current_air_resistance;
        ++v85;
        qmemcpy(v38, v40, 0x40u);
        v33 = 0;
        *((float *)v38 + 17) = v41;
        *((_BYTE *)v38 + 75) = 1;
        v24 = v74;
      }
      if ( v85 )
      {
        v46 = alloca(8 * v85);
        v47 = v85;
        v69[2] = (const vostok::resources::request *)&(&v61)[2 * v85];
        v69[0] = (const vostok::resources::request *)&v61;
        v69[1] = (const vostok::resources::request *)&v61;
        vostok::buffer_vector<vostok::resources::request>::resize(
          (vostok::buffer_vector<vostok::resources::request> *)v85,
          (const char *)v24,
          (int *)v69);
        v72[2] = -1;
        v48 = 0;
        v72[1] = 0;
        v72[3] = 65792;
        LOBYTE(v72[4]) = 0;
        v49 = alloca(4 * v47);
        v79 = (const vostok::variant<32> *const *)&v61;
        v50 = alloca(48 * v47);
        v51 = (const vostok::variant<32> *)&v61;
        v74 = &v61;
        textures = (vostok::fixed_string<64> *)&v61;
        v81 = (char *)(v24 + 16);
        while ( 1 )
        {
          v52 = v69[0];
          v53 = v81;
          v69[0][v48].id = render_texture_class;
          v52[v48].path = *(const char **)v53;
          if ( v51 )
          {
            v51->m_helper = 0;
            v51->m_type_id = 0;
          }
          else
          {
            v51 = 0;
          }
          v79[v48] = v51;
          vostok::variant<32>::set<vostok::render::render_texture_cook_parameters>(
            (vostok::variant<32> *)&v72[1],
            (const vostok::render::render_texture_cook_parameters *)v51,
            &v72[1]);
          v81 += 76;
          textures = (vostok::fixed_string<64> *)((char *)textures + 48);
          if ( ++v48 >= v47 )
            break;
          v51 = (const vostok::variant<32> *)textures;
        }
        LODWORD(v68.k.w) = vostok::render::bake_decal_cook::on_textures_loaded;
        *(_QWORD *)&v68.lines[3].x = __PAIR64__((unsigned int)v24, (unsigned int)v70);
        *(_QWORD *)&v68.lines[3].elements[2] = __PAIR64__(v71, (unsigned int)v77);
        qmemcpy(v72, &v68.lines[2].elements[3], sizeof(v72));
        if ( Scaleform::Render::RenderEvent::GetListenerStatus(0) )
        {
          v68.k.x = 0.0;
        }
        else
        {
          qmemcpy(&v68.lines[2].elements[2], v72, 0x14u);
          LODWORD(v68.k.x) = (char *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf4<void,vostok::render::bake_decal_cook,vostok::resources::queries_result &,vostok::render::decal_texture_slot *,vostok::render::bake_decal_cook_parameters *,vostok::render::render_surface_instance *>,boost::_bi::list5<boost::_bi::value<vostok::render::bake_decal_cook *>,boost::arg<1>,boost::_bi::value<vostok::render::decal_texture_slot *>,boost::_bi::value<vostok::render::bake_decal_cook_parameters *>,boost::_bi::value<vostok::render::render_surface_instance *>>>>'::`2'::stored_vtable
                           + 1;
        }
        v54 = v85;
        vostok::resources::query_resources(v69[0], v85, vostok::render::g_allocator, v79, parent, assert_on_fail_true);
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          v55,
          (int *)&v68.k.0);
        if ( v54 )
        {
          v57 = (int)v74;
          do
          {
            vostok::variant<32>::destroy_previous_variable_if_needed(v56, v57);
            v57 += 48;
            --v54;
          }
          while ( v54 );
        }
      }
      else
      {
        if ( v24 )
          vostok::memory::doug_lea_allocator::free_impl(
            (vostok::memory::doug_lea_allocator *)v33,
            (int)vostok::render::g_allocator,
            (char *)v24 - 8,
            v61,
            v62,
            v63);
        vostok::resources::query_result_for_cook::finish_query_impl(
          (vostok::resources::query_result_for_cook *)v33,
          (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)parent,
          result_success,
          assert_on_fail_true,
          result_out_of_memory|0x8);
      }
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v73);
    }
    else
    {
LABEL_15:
      if ( !vostok::core::g_log_filter_tree
        || (has_passed_filters = vostok::logging::has_passed_filters(
                                   (vostok::logging::filter_tree *)"render_pc_dx11",
                                   (const char *)2),
            v8 = v59,
            has_passed_filters) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v8,
          &v68.k.x);
        surface_index = v5->surface_index;
        v85 = 2;
        vostok::logging::append(
          (const boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)&v68.lines[2],
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\bake_decal_cook.cpp",
          0x9Fu,
          "void __thiscall vostok::render::bake_decal_cook::translate_query(class vostok::resources::query_result_for_cook &)",
          "render_pc_dx11",
          error,
          "surface with index %d not found",
          surface_index);
      }
      if ( (v85 & 2) != 0 )
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v8,
          (int *)&v68.k.0);
      vostok::resources::query_result_for_cook::finish_query_impl(
        (vostok::resources::query_result_for_cook *)v8,
        (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)parent,
        result_success,
        assert_on_fail_true,
        result_out_of_memory|0x8);
    }
    v65 = v64;
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v78);
  }
  else
  {
    if ( !vostok::core::g_log_filter_tree
      || (v4 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"render_pc_dx11", (const char *)2),
          v3 = v58,
          v4) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v3,
        &v68.k.x);
      v85 = 1;
      vostok::logging::append(
        (const boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)&v68.lines[2],
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\bake_decal_cook.cpp",
        0x86u,
        "void __thiscall vostok::render::bake_decal_cook::translate_query(class vostok::resources::query_result_for_cook &)",
        "render_pc_dx11",
        error,
        "user data bake_decal_cook_parameters* is not found");
    }
    if ( (v85 & 1) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v3,
        (int *)&v68.k.0);
    vostok::resources::query_result_for_cook::finish_query_impl(
      (vostok::resources::query_result_for_cook *)v3,
      (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)parent,
      result_success,
      assert_on_fail_true,
      result_out_of_memory|0x8);
  }
}
