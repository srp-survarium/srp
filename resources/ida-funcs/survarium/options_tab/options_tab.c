void __userpurge survarium::options_tab::options_tab(
        survarium::game *g@<ecx>,
        survarium::options_enum type@<eax>,
        survarium::options_tab *this,
        vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *movie)
{
  vostok::memory::doug_lea_allocator *v4; // eax
  survarium::options_item_base **v5; // eax
  vostok::memory::doug_lea_allocator *v6; // ecx
  survarium::options_item_base *v7; // edi
  survarium::options_item_base *v8; // edi
  vostok::memory::doug_lea_allocator *v9; // ecx
  survarium::options_item_base *v10; // edi
  vostok::memory::doug_lea_allocator *v11; // ecx
  survarium::options_item_base *v12; // edi
  survarium::options_item_base *v13; // edi
  vostok::memory::doug_lea_allocator *v14; // ecx
  survarium::options_item_base *v15; // edi
  vostok::memory::doug_lea_allocator *v16; // ecx
  survarium::options_item_int *v17; // eax
  int v18; // eax
  survarium::options_item_base *v19; // edi
  vostok::memory::doug_lea_allocator *v20; // ecx
  survarium::options_item_base *v21; // edi
  vostok::memory::doug_lea_allocator *v22; // eax
  survarium::options_item_base **v23; // eax
  vostok::memory::doug_lea_allocator *v24; // ecx
  survarium::options_monitor_index_selector *v25; // ecx
  survarium::options_item_base *v26; // eax
  vostok::memory::doug_lea_allocator *v27; // ecx
  survarium::options_resolution_selector *v28; // ecx
  int v29; // eax
  survarium::options_item_base *v30; // edi
  vostok::memory::doug_lea_allocator *v31; // ecx
  survarium::options_item_base *v32; // edi
  vostok::memory::doug_lea_allocator *v33; // ecx
  survarium::options_item_int *v34; // eax
  int v35; // eax
  survarium::options_item_int *v36; // eax
  int v37; // eax
  vostok::memory::doug_lea_allocator *v38; // ecx
  survarium::options_item_base *v39; // edi
  vostok::memory::doug_lea_allocator *v40; // ecx
  survarium::options_item_base *v41; // edi
  const vostok::math::float4x4 *v42; // xmm0_4
  survarium::options_graphics_quality_selector *v43; // ecx
  int v44; // eax
  vostok::memory::doug_lea_allocator *v45; // ecx
  survarium::options_item_int *v46; // eax
  int v47; // eax
  survarium::options_item_int *v48; // eax
  int v49; // eax
  vostok::memory::doug_lea_allocator *v50; // ecx
  survarium::options_item_int *v51; // eax
  int v52; // eax
  survarium::options_item_int *v53; // eax
  int v54; // eax
  vostok::memory::doug_lea_allocator *v55; // ecx
  survarium::options_item_int *v56; // eax
  int v57; // eax
  survarium::options_item_int *v58; // eax
  int v59; // eax
  vostok::memory::doug_lea_allocator *v60; // ecx
  survarium::options_item_int *v61; // eax
  int v62; // eax
  survarium::options_item_int *v63; // eax
  int v64; // eax
  vostok::memory::doug_lea_allocator *v65; // ecx
  survarium::options_item_int *v66; // eax
  int v67; // eax
  survarium::options_item_int *v68; // eax
  int v69; // eax
  vostok::memory::doug_lea_allocator *v70; // eax
  survarium::options_item_base **v71; // eax
  vostok::memory::doug_lea_allocator *v72; // ecx
  survarium::options_item_base *v73; // edi
  survarium::options_item_base *v74; // edi
  vostok::memory::doug_lea_allocator *v75; // eax
  survarium::options_item_base **v76; // eax
  vostok::memory::doug_lea_allocator *v77; // ecx
  survarium::options_item_base *v78; // edi
  const vostok::math::float4x4 *v79; // xmm0_4
  survarium::options_item_base *v80; // edi
  const vostok::math::float4x4 *v81; // xmm0_4
  vostok::memory::doug_lea_allocator *v82; // ecx
  survarium::options_item_base *v83; // edi
  const vostok::math::float4x4 *v84; // xmm0_4
  vostok::memory::doug_lea_allocator *v85; // ecx
  survarium::options_item_base *v86; // edi
  const vostok::math::float4x4 *v87; // xmm0_4
  survarium::options_item_base *v88; // edi
  vostok::memory::doug_lea_allocator *v89; // ecx
  survarium::options_item_base *v90; // edi
  const vostok::math::float4x4 *v91; // xmm0_4
  vostok::memory::doug_lea_allocator *v92; // ecx
  survarium::options_item_base *v93; // edi
  vostok::sound::sound_world *f; // [esp-4h] [ebp-10h]
  vostok::sound::sound_world *v95; // [esp-4h] [ebp-10h]
  vostok::sound::sound_world *v96; // [esp-4h] [ebp-10h]
  vostok::sound::sound_world *v97; // [esp-4h] [ebp-10h]

  this->m_type = type;
  this->m_game = g;
  this->m_movie = movie;
  switch ( type )
  {
    case gameplay_options_type:
      f = (vostok::sound::sound_world *)survarium::g_allocator.f_.f_;
      this->m_options_count = 9;
      v4 = (vostok::memory::doug_lea_allocator *)boost::get_pointer<vostok::sound::sound_scene>(f);
      v5 = (survarium::options_item_base **)vostok::memory::new_array_helper<survarium::options_item_base *>::call<vostok::memory::doug_lea_allocator>(
                                              v4,
                                              9u);
      v6 = (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_;
      this->m_options = v5;
      v7 = (survarium::options_item_base *)vostok::memory::doug_lea_allocator::malloc_impl(v6, 0x1Cu);
      if ( v7 )
      {
        survarium::options_item_base::options_item_base(v7, "g_invite_from_friends", this, 0, bool_selector);
        v7->__vftable = (survarium::options_item_base_vtbl *)&survarium::options_item_bool::`vftable';
      }
      else
      {
        v7 = 0;
      }
      *this->m_options = v7;
      v8 = (survarium::options_item_base *)vostok::memory::doug_lea_allocator::malloc_impl(
                                             (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
                                             0x1Cu);
      if ( v8 )
      {
        survarium::options_item_base::options_item_base(v8, "g_friends_signin_notification", this, 1u, bool_selector);
        v8->__vftable = (survarium::options_item_base_vtbl *)&survarium::options_item_bool::`vftable';
      }
      else
      {
        v8 = 0;
      }
      v9 = (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_;
      *((_DWORD *)this->m_options + 1) = v8;
      v10 = (survarium::options_item_base *)vostok::memory::doug_lea_allocator::malloc_impl(v9, 0x1Cu);
      if ( v10 )
      {
        survarium::options_item_base::options_item_base(v10, "g_messages_censor", this, 2u, bool_selector);
        v10->__vftable = (survarium::options_item_base_vtbl *)&survarium::options_item_bool::`vftable';
      }
      else
      {
        v10 = 0;
      }
      v11 = (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_;
      *((_DWORD *)this->m_options + 2) = v10;
      v12 = (survarium::options_item_base *)vostok::memory::doug_lea_allocator::malloc_impl(v11, 0x1Cu);
      if ( v12 )
      {
        survarium::options_item_base::options_item_base(v12, "g_messages_only_from_friends", this, 3u, bool_selector);
        v12->__vftable = (survarium::options_item_base_vtbl *)&survarium::options_item_bool::`vftable';
      }
      else
      {
        v12 = 0;
      }
      *((_DWORD *)this->m_options + 3) = v12;
      v13 = (survarium::options_item_base *)vostok::memory::doug_lea_allocator::malloc_impl(
                                              (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
                                              0x1Cu);
      if ( v13 )
      {
        survarium::options_item_base::options_item_base(v13, "g_private_messages_in_game", this, 4u, bool_selector);
        v13->__vftable = (survarium::options_item_base_vtbl *)&survarium::options_item_bool::`vftable';
      }
      else
      {
        v13 = 0;
      }
      v14 = (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_;
      *((_DWORD *)this->m_options + 4) = v13;
      v15 = (survarium::options_item_base *)vostok::memory::doug_lea_allocator::malloc_impl(v14, 0x1Cu);
      if ( v15 )
      {
        survarium::options_item_base::options_item_base(v15, "g_hide_spam", this, 5u, bool_selector);
        v15->__vftable = (survarium::options_item_base_vtbl *)&survarium::options_item_bool::`vftable';
      }
      else
      {
        v15 = 0;
      }
      v16 = (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_;
      *((_DWORD *)this->m_options + 5) = v15;
      v17 = (survarium::options_item_int *)vostok::memory::doug_lea_allocator::malloc_impl(v16, 0x20u);
      if ( v17 )
        survarium::options_item_int::options_item_int(this, 6u, v17, "g_crosshair_type", 0, 0);
      else
        v18 = 0;
      *((_DWORD *)this->m_options + 6) = v18;
      v19 = (survarium::options_item_base *)vostok::memory::doug_lea_allocator::malloc_impl(
                                              (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
                                              0x1Cu);
      if ( v19 )
      {
        survarium::options_item_base::options_item_base(v19, "g_crosshair_static", this, 7u, bool_selector);
        v19->__vftable = (survarium::options_item_base_vtbl *)&survarium::options_item_bool::`vftable';
      }
      else
      {
        v19 = 0;
      }
      v20 = (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_;
      *((_DWORD *)this->m_options + 7) = v19;
      v21 = (survarium::options_item_base *)vostok::memory::doug_lea_allocator::malloc_impl(v20, 0x1Cu);
      if ( v21 )
      {
        survarium::options_item_base::options_item_base(v21, "is_ui_minimap_rotable", this, 8u, bool_selector);
        v21->__vftable = (survarium::options_item_base_vtbl *)&survarium::options_item_bool::`vftable';
        *((_DWORD *)this->m_options + 8) = v21;
      }
      else
      {
        *((_DWORD *)this->m_options + 8) = 0;
      }
      break;
    case controllers_options_type:
      v96 = (vostok::sound::sound_world *)survarium::g_allocator.f_.f_;
      this->m_options_count = 2;
      v70 = (vostok::memory::doug_lea_allocator *)boost::get_pointer<vostok::sound::sound_scene>(v96);
      v71 = (survarium::options_item_base **)vostok::memory::new_array_helper<survarium::options_item_base *>::call<vostok::memory::doug_lea_allocator>(
                                               v70,
                                               2u);
      v72 = (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_;
      this->m_options = v71;
      v73 = (survarium::options_item_base *)vostok::memory::doug_lea_allocator::malloc_impl(v72, 0x1Cu);
      if ( v73 )
      {
        survarium::options_item_base::options_item_base(v73, "mouse_invertion", this, 0, bool_selector);
        v73->__vftable = (survarium::options_item_base_vtbl *)&survarium::options_item_bool::`vftable';
      }
      else
      {
        v73 = 0;
      }
      *this->m_options = v73;
      v74 = (survarium::options_item_base *)vostok::memory::doug_lea_allocator::malloc_impl(
                                              (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
                                              0x24u);
      if ( v74 )
      {
        survarium::options_item_base::options_item_base(v74, "sensitivity", this, 1u, slider_selector);
        v74->__vftable = (survarium::options_item_base_vtbl *)&survarium::options_item_float::`vftable';
        *(float *)&v74[1].__vftable = satisfaction_equality_tolerance;
        *((_DWORD *)this->m_options + 1) = v74;
      }
      else
      {
        *((_DWORD *)this->m_options + 1) = 0;
      }
      break;
    case video_options_type:
      v95 = (vostok::sound::sound_world *)survarium::g_allocator.f_.f_;
      this->m_options_count = 19;
      v22 = (vostok::memory::doug_lea_allocator *)boost::get_pointer<vostok::sound::sound_scene>(v95);
      v23 = (survarium::options_item_base **)vostok::memory::new_array_helper<survarium::options_item_base *>::call<vostok::memory::doug_lea_allocator>(
                                               v22,
                                               0x13u);
      v24 = (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_;
      this->m_options = v23;
      v25 = (survarium::options_monitor_index_selector *)vostok::memory::doug_lea_allocator::malloc_impl(v24, 0x128u);
      if ( v25 )
        survarium::options_monitor_index_selector::options_monitor_index_selector(v25, this);
      else
        v26 = 0;
      v27 = (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_;
      *this->m_options = v26;
      v28 = (survarium::options_resolution_selector *)vostok::memory::doug_lea_allocator::malloc_impl(v27, 0x5820u);
      if ( v28 )
        survarium::options_resolution_selector::options_resolution_selector(v28, this);
      else
        v29 = 0;
      *((_DWORD *)this->m_options + 1) = v29;
      v30 = (survarium::options_item_base *)vostok::memory::doug_lea_allocator::malloc_impl(
                                              (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
                                              0x1Cu);
      if ( v30 )
      {
        survarium::options_item_base::options_item_base(v30, "r_fullscreen", this, 2u, bool_selector);
        v30->__vftable = (survarium::options_item_base_vtbl *)&survarium::options_item_bool::`vftable';
      }
      else
      {
        v30 = 0;
      }
      v31 = (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_;
      *((_DWORD *)this->m_options + 2) = v30;
      v32 = (survarium::options_item_base *)vostok::memory::doug_lea_allocator::malloc_impl(v31, 0x1Cu);
      if ( v32 )
      {
        survarium::options_item_base::options_item_base(v32, "r_vsync", this, 3u, bool_selector);
        v32->__vftable = (survarium::options_item_base_vtbl *)&survarium::options_item_bool::`vftable';
      }
      else
      {
        v32 = 0;
      }
      v33 = (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_;
      *((_DWORD *)this->m_options + 3) = v32;
      v34 = (survarium::options_item_int *)vostok::memory::doug_lea_allocator::malloc_impl(v33, 0x20u);
      if ( v34 )
        survarium::options_item_int::options_item_int(this, 4u, v34, "r_antialiasing_method", antialiasing_data, 3u);
      else
        v35 = 0;
      *((_DWORD *)this->m_options + 4) = v35;
      v36 = (survarium::options_item_int *)vostok::memory::doug_lea_allocator::malloc_impl(
                                             (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
                                             0x20u);
      if ( v36 )
        survarium::options_item_int::options_item_int(
          this,
          5u,
          v36,
          "r_max_anisotropic",
          anisotrophic_filtering_data,
          5u);
      else
        v37 = 0;
      v38 = (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_;
      *((_DWORD *)this->m_options + 5) = v37;
      v39 = (survarium::options_item_base *)vostok::memory::doug_lea_allocator::malloc_impl(v38, 0x24u);
      if ( v39 )
      {
        survarium::options_item_base::options_item_base(v39, "r_gamma_correction_factor", this, 6u, slider_selector);
        v39[1].__vftable = (survarium::options_item_base_vtbl *)1008981770;
        v39->__vftable = (survarium::options_item_base_vtbl *)&survarium::options_gamma_selector::`vftable';
      }
      else
      {
        v39 = 0;
      }
      v40 = (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_;
      *((_DWORD *)this->m_options + 6) = v39;
      v41 = (survarium::options_item_base *)vostok::memory::doug_lea_allocator::malloc_impl(v40, 0x24u);
      if ( v41 )
      {
        survarium::options_item_base::options_item_base(v41, "fov", this, 7u, slider_selector);
        v42 = clear_value;
        v41->__vftable = (survarium::options_item_base_vtbl *)&survarium::options_item_float::`vftable';
        v41[1].__vftable = (survarium::options_item_base_vtbl *)v42;
      }
      else
      {
        v41 = 0;
      }
      *((_DWORD *)this->m_options + 7) = v41;
      v43 = (survarium::options_graphics_quality_selector *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                              (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
                                                              0x20u);
      if ( v43 )
        survarium::options_graphics_quality_selector::options_graphics_quality_selector(v43, this);
      else
        v44 = 0;
      v45 = (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_;
      *((_DWORD *)this->m_options + 8) = v44;
      v46 = (survarium::options_item_int *)vostok::memory::doug_lea_allocator::malloc_impl(v45, 0x20u);
      if ( v46 )
        survarium::options_item_int::options_item_int(this, 9u, v46, "r_texture_quality", texture_quality_data, 3u);
      else
        v47 = 0;
      *((_DWORD *)this->m_options + 9) = v47;
      v48 = (survarium::options_item_int *)vostok::memory::doug_lea_allocator::malloc_impl(
                                             (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
                                             0x20u);
      if ( v48 )
        survarium::options_item_int::options_item_int(this, 0xAu, v48, "r_geometry_quality", geometry_quality_data, 2u);
      else
        v49 = 0;
      v50 = (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_;
      *((_DWORD *)this->m_options + 10) = v49;
      v51 = (survarium::options_item_int *)vostok::memory::doug_lea_allocator::malloc_impl(v50, 0x20u);
      if ( v51 )
        survarium::options_item_int::options_item_int(this, 0xBu, v51, "r_shadow_quality", shadow_quality_data, 4u);
      else
        v52 = 0;
      *((_DWORD *)this->m_options + 11) = v52;
      v53 = (survarium::options_item_int *)vostok::memory::doug_lea_allocator::malloc_impl(
                                             (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
                                             0x20u);
      if ( v53 )
        survarium::options_item_int::options_item_int(this, 0xCu, v53, "r_lighting_quality", lighting_quality_data, 4u);
      else
        v54 = 0;
      v55 = (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_;
      *((_DWORD *)this->m_options + 12) = v54;
      v56 = (survarium::options_item_int *)vostok::memory::doug_lea_allocator::malloc_impl(v55, 0x20u);
      if ( v56 )
        survarium::options_item_int::options_item_int(this, 0xDu, v56, "r_shading_quality", shading_quality_data, 4u);
      else
        v57 = 0;
      *((_DWORD *)this->m_options + 13) = v57;
      v58 = (survarium::options_item_int *)vostok::memory::doug_lea_allocator::malloc_impl(
                                             (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
                                             0x20u);
      if ( v58 )
        survarium::options_item_int::options_item_int(
          this,
          0xEu,
          v58,
          "r_decorations_quality",
          decorations_quality_data,
          3u);
      else
        v59 = 0;
      v60 = (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_;
      *((_DWORD *)this->m_options + 14) = v59;
      v61 = (survarium::options_item_int *)vostok::memory::doug_lea_allocator::malloc_impl(v60, 0x20u);
      if ( v61 )
        survarium::options_item_int::options_item_int(
          this,
          0xFu,
          v61,
          "r_post_process_quality",
          post_process_quality_data,
          4u);
      else
        v62 = 0;
      *((_DWORD *)this->m_options + 15) = v62;
      v63 = (survarium::options_item_int *)vostok::memory::doug_lea_allocator::malloc_impl(
                                             (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
                                             0x20u);
      if ( v63 )
        survarium::options_item_int::options_item_int(
          this,
          0x10u,
          v63,
          "r_ambient_occlusion_quality",
          ambient_occlusion_data,
          4u);
      else
        v64 = 0;
      v65 = (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_;
      *((_DWORD *)this->m_options + 16) = v64;
      v66 = (survarium::options_item_int *)vostok::memory::doug_lea_allocator::malloc_impl(v65, 0x20u);
      if ( v66 )
        survarium::options_item_int::options_item_int(
          this,
          0x11u,
          v66,
          "r_particles_quality",
          particles_quality_data,
          3u);
      else
        v67 = 0;
      *((_DWORD *)this->m_options + 17) = v67;
      v68 = (survarium::options_item_int *)vostok::memory::doug_lea_allocator::malloc_impl(
                                             (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
                                             0x20u);
      if ( v68 )
      {
        survarium::options_item_int::options_item_int(
          this,
          0x12u,
          v68,
          "r_motion_blur_quality",
          motion_blur_quality_data,
          4u);
        *((_DWORD *)this->m_options + 18) = v69;
      }
      else
      {
        *((_DWORD *)this->m_options + 18) = 0;
      }
      break;
    case sound_options_type:
      v97 = (vostok::sound::sound_world *)survarium::g_allocator.f_.f_;
      this->m_options_count = 7;
      v75 = (vostok::memory::doug_lea_allocator *)boost::get_pointer<vostok::sound::sound_scene>(v97);
      v76 = (survarium::options_item_base **)vostok::memory::new_array_helper<survarium::options_item_base *>::call<vostok::memory::doug_lea_allocator>(
                                               v75,
                                               7u);
      v77 = (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_;
      this->m_options = v76;
      v78 = (survarium::options_item_base *)vostok::memory::doug_lea_allocator::malloc_impl(v77, 0x24u);
      if ( v78 )
      {
        survarium::options_item_base::options_item_base(v78, "s_general_volume", this, 0, slider_selector);
        v79 = clear_value;
        v78->__vftable = (survarium::options_item_base_vtbl *)&survarium::options_item_float::`vftable';
        v78[1].__vftable = (survarium::options_item_base_vtbl *)v79;
      }
      else
      {
        v78 = 0;
      }
      *this->m_options = v78;
      v80 = (survarium::options_item_base *)vostok::memory::doug_lea_allocator::malloc_impl(
                                              (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
                                              0x24u);
      if ( v80 )
      {
        survarium::options_item_base::options_item_base(v80, "s_ingame_volume", this, 1u, slider_selector);
        v81 = clear_value;
        v80->__vftable = (survarium::options_item_base_vtbl *)&survarium::options_item_float::`vftable';
        v80[1].__vftable = (survarium::options_item_base_vtbl *)v81;
      }
      else
      {
        v80 = 0;
      }
      v82 = (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_;
      *((_DWORD *)this->m_options + 1) = v80;
      v83 = (survarium::options_item_base *)vostok::memory::doug_lea_allocator::malloc_impl(v82, 0x24u);
      if ( v83 )
      {
        survarium::options_item_base::options_item_base(v83, "s_music_volume", this, 2u, slider_selector);
        v84 = clear_value;
        v83->__vftable = (survarium::options_item_base_vtbl *)&survarium::options_item_float::`vftable';
        v83[1].__vftable = (survarium::options_item_base_vtbl *)v84;
      }
      else
      {
        v83 = 0;
      }
      v85 = (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_;
      *((_DWORD *)this->m_options + 2) = v83;
      v86 = (survarium::options_item_base *)vostok::memory::doug_lea_allocator::malloc_impl(v85, 0x24u);
      if ( v86 )
      {
        survarium::options_item_base::options_item_base(v86, "s_chat_volume", this, 3u, slider_selector);
        v87 = clear_value;
        v86->__vftable = (survarium::options_item_base_vtbl *)&survarium::options_item_float::`vftable';
        v86[1].__vftable = (survarium::options_item_base_vtbl *)v87;
      }
      else
      {
        v86 = 0;
      }
      *((_DWORD *)this->m_options + 3) = v86;
      v88 = (survarium::options_item_base *)vostok::memory::doug_lea_allocator::malloc_impl(
                                              (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
                                              0x1Cu);
      if ( v88 )
      {
        survarium::options_item_base::options_item_base(v88, "s_use_microphone", this, 4u, bool_selector);
        v88->__vftable = (survarium::options_item_base_vtbl *)&survarium::options_item_bool::`vftable';
      }
      else
      {
        v88 = 0;
      }
      v89 = (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_;
      *((_DWORD *)this->m_options + 4) = v88;
      v90 = (survarium::options_item_base *)vostok::memory::doug_lea_allocator::malloc_impl(v89, 0x24u);
      if ( v90 )
      {
        survarium::options_item_base::options_item_base(v90, "s_mic_sens", this, 5u, slider_selector);
        v91 = clear_value;
        v90->__vftable = (survarium::options_item_base_vtbl *)&survarium::options_item_float::`vftable';
        v90[1].__vftable = (survarium::options_item_base_vtbl *)v91;
      }
      else
      {
        v90 = 0;
      }
      v92 = (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_;
      *((_DWORD *)this->m_options + 5) = v90;
      v93 = (survarium::options_item_base *)vostok::memory::doug_lea_allocator::malloc_impl(v92, 0x1Cu);
      if ( v93 )
      {
        survarium::options_item_base::options_item_base(v93, "s_ptt_button", this, 6u, bool_selector);
        v93->__vftable = (survarium::options_item_base_vtbl *)&survarium::options_item_bool::`vftable';
        *((_DWORD *)this->m_options + 6) = v93;
      }
      else
      {
        *((_DWORD *)this->m_options + 6) = 0;
      }
      break;
    default:
      return;
  }
}
