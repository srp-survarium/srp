void __thiscall survarium::game_world::on_project_loaded(
        survarium::game_world *this,
        vostok::resources::queries_result *data,
        unsigned int results_offset,
        boost::function<void __cdecl(vostok::resources::queries_result &)> *callback)
{
  bool v5; // zf
  vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *p_m_render_scene; // edi
  vostok::configs::binary_config *v7; // ecx
  vostok::resources::unmanaged_resource *M_start; // eax
  vostok::resources::unmanaged_intrusive_base *v9; // ecx
  vostok::configs::binary_config *m_object; // eax
  vostok::resources::unmanaged_intrusive_base *v11; // ecx
  vostok::configs::binary_config *v12; // edi
  vostok::resources::unmanaged_resource *v13; // eax
  vostok::resources::unmanaged_intrusive_base *v14; // ecx
  vostok::resources::unmanaged_resource *v15; // edi
  vostok::resources::unmanaged_resource *v16; // eax
  vostok::resources::unmanaged_resource *v17; // edx
  vostok::resources::unmanaged_resource *v18; // eax
  vostok::resources::unmanaged_intrusive_base *v19; // ecx
  survarium::victory_item *v20; // eax
  vostok::resources::unmanaged_intrusive_base *v21; // ecx
  vostok::resources::unmanaged_resource *v22; // esi
  vostok::resources::unmanaged_resource *M_data; // edi
  vostok::resources::unmanaged_resource *v24; // eax
  survarium::game_world::bullet_tracer *M_finish; // eax
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *death_particles; // edx
  vostok::resources::query_result *v27; // ecx
  vostok::resources::unmanaged_resource *v28; // eax
  vostok::resources::unmanaged_resource *v29; // esi
  vostok::resources::unmanaged_resource *v30; // eax
  vostok::resources::unmanaged_resource *v31; // ecx
  vostok::resources::unmanaged_resource *v32; // eax
  survarium::flash_factory *m_flash_factory; // edi
  survarium::flash_text_manager *v34; // esi
  survarium::flash_text_manager *v35; // eax
  survarium::flash_text_manager *v36; // esi
  vostok::resources::resource_ptr<vostok::render::base_output_window,vostok::resources::unmanaged_intrusive_base> *p_m_render_output_window; // eax
  vostok::resources::unmanaged_resource *v38; // edi
  int type; // ecx
  int v40; // edi
  const vostok::math::float4x4 *v41; // xmm0_4
  Scaleform::GFx::DrawTextManager *text_manager_impl; // ecx
  vostok::resources::unmanaged_resource *v43; // eax
  vostok::resources::unmanaged_resource *v44; // edi
  vostok::resources::unmanaged_resource *v45; // esi
  survarium::game_material_manager *v46; // eax
  survarium::game_material_manager *v47; // ecx
  survarium::game_material_manager *v48; // eax
  survarium::bullet_manager *v49; // eax
  survarium::bullet_manager *v50; // eax
  vostok::resources::unmanaged_resource *v51; // eax
  vostok::resources::unmanaged_resource *v52; // edi
  vostok::resources::unmanaged_resource *v53; // esi
  survarium::simple_game_project *v54; // eax
  survarium::simple_game_project *v55; // ecx
  survarium::simple_game_project *v56; // eax
  survarium::game_world *v57; // ecx
  survarium::game *v58; // ecx
  survarium::lobby_menu *m_lobby_menu; // esi
  survarium::base_network_client *m_network_client; // ecx
  survarium::match_options *(__thiscall *match_options)(survarium::base_network_client *); // eax
  survarium::simple_game_project *v62; // ecx
  const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v63; // eax
  survarium::victory_item *p_m_prev_in_global_list; // esi
  vostok::configs::binary_config *v65; // eax
  vostok::resources::unmanaged_intrusive_base *v66; // ecx
  vostok::resources::resource_ptr<survarium::victory_item,vostok::resources::unmanaged_intrusive_base> *v67; // esi
  vostok::resources::resource_ptr<survarium::victory_item,vostok::resources::unmanaged_intrusive_base> *v68; // eax
  vostok::resources::unmanaged_intrusive_base *v69; // ecx
  survarium::base_network_client *v70; // ecx
  survarium::match_options *(__thiscall *v71)(survarium::base_network_client *); // eax
  int v72; // eax
  vostok::configs::binary_config_value *v73; // eax
  const vostok::configs::binary_config_value *v74; // eax
  int v75; // edx
  vostok::configs::binary_config_value *m_root; // ecx
  vostok::configs::binary_config_value *v77; // eax
  vostok::resources::request **v78; // eax
  int path; // edx
  survarium::camera_director *v80; // edi
  survarium::camera_director *v81; // ecx
  vostok::sound::world_user *v82; // eax
  vostok::variant<32> *v83; // ecx
  survarium::match_client *v84; // eax
  survarium::game_world_ui *v85; // ecx
  void (__cdecl *v86)(int *, int *, int); // eax
  survarium::game *m_game; // esi
  survarium::base_game_scene *m_active_scene; // ecx
  survarium::game_world *p_m_game_world; // edi
  int v90; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::game_world,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::game_world *>,boost::arg<1> > > v91; // [esp+28Ah] [ebp-A8h]
  survarium::free_fly_camera *m_free_fly_camera; // [esp+292h] [ebp-A0h]
  survarium::camera_director *m_camera_director; // [esp+296h] [ebp-9Ch]
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *p_m_config; // [esp+296h] [ebp-9Ch]
  const stlp_std::__false_type *v95; // [esp+29Ah] [ebp-98h]
  unsigned int v96; // [esp+29Eh] [ebp-94h]
  bool v97; // [esp+2A2h] [ebp-90h]
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v98; // [esp+2A6h] [ebp-8Ch] BYREF
  stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<survarium::victory_item,vostok::resources::unmanaged_intrusive_base>,vostok::vectora_allocator<vostok::resources::resource_ptr<survarium::victory_item,vostok::resources::unmanaged_intrusive_base> > > v99; // [esp+2AAh] [ebp-88h] BYREF
  vostok::resources::query_result *__x; // [esp+2BAh] [ebp-78h]
  survarium::game_world::bullet_tracer __x_4; // [esp+2BEh] [ebp-74h] BYREF
  Scaleform::Render::Viewport vp; // [esp+2C6h] [ebp-6Ch] BYREF
  int v103; // [esp+2F2h] [ebp-40h]
  const vostok::math::float4x4 *v104; // [esp+2F6h] [ebp-3Ch]
  const vostok::math::float4x4 *v105; // [esp+2FAh] [ebp-38h]
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v106[2]; // [esp+302h] [ebp-30h] BYREF
  char v107[32]; // [esp+30Ah] [ebp-28h] BYREF
  int v108; // [esp+32Ah] [ebp-8h]
  int v109; // [esp+32Eh] [ebp-4h]

  v5 = this->m_render_scene.m_object == 0;
  p_m_render_scene = &this->m_render_scene;
  v7 = (vostok::configs::binary_config *)results_offset;
  if ( v5 )
  {
    v98.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v98,
      (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[results_offset].m_unmanaged_resource);
    v99._M_start = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v99,
      v98.m_object);
    vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
      (vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base> *)p_m_render_scene,
      (const vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base> *)&v99);
    M_start = (vostok::resources::unmanaged_resource *)v99._M_start;
    if ( v99._M_start )
    {
      v9 = (vostok::resources::unmanaged_intrusive_base *)&v99._M_start[52];
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v99._M_start[52], 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(v9, M_start);
    }
    m_object = v98.m_object;
    if ( v98.m_object )
    {
      v11 = &v98.m_object->vostok::resources::unmanaged_intrusive_base;
      if ( !_InterlockedExchangeAdd(&v98.m_object->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(v11, m_object);
    }
    v98.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v98,
      (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[results_offset + 1].m_unmanaged_resource);
    v99._M_start = 0;
    v12 = v98.m_object;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v99,
      v98.m_object);
    vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
      (vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base> *)&this->m_render_scene_view,
      (const vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base> *)&v99);
    v13 = (vostok::resources::unmanaged_resource *)v99._M_start;
    if ( v99._M_start )
    {
      v14 = (vostok::resources::unmanaged_intrusive_base *)&v99._M_start[52];
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v99._M_start[52], 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(v14, v13);
    }
    if ( v12 && !_InterlockedExchangeAdd(&v12->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v12->vostok::resources::unmanaged_intrusive_base, v12);
    v99._M_start = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v99,
      (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[results_offset + 2].m_unmanaged_resource);
    v15 = (vostok::resources::unmanaged_resource *)v99._M_start;
    v16 = 0;
    if ( v99._M_start )
    {
      v16 = (vostok::resources::unmanaged_resource *)v99._M_start;
      _InterlockedExchangeAdd((volatile signed __int32 *)&v99._M_start[52], 1u);
    }
    v17 = this->m_sound_scene.m_object;
    this->m_sound_scene.m_object = v16;
    if ( v17 && !_InterlockedExchangeAdd(&v17->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v17->vostok::resources::unmanaged_intrusive_base, v17);
    if ( v15 && !_InterlockedExchangeAdd(&v15->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v15->vostok::resources::unmanaged_intrusive_base, v15);
    v98.m_object = (vostok::configs::binary_config *)(results_offset + 4);
    v99._M_start = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v99,
      (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[results_offset + 3].m_unmanaged_resource);
    survarium::game_world_ui::initialize_resources(
      &this->game_ui,
      (const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)&v99);
    v18 = (vostok::resources::unmanaged_resource *)v99._M_start;
    if ( v99._M_start )
    {
      v19 = (vostok::resources::unmanaged_intrusive_base *)&v99._M_start[52];
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v99._M_start[52], 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(v19, v18);
    }
    v99._M_finish = 0;
    if ( s_max_tracers_count )
    {
      v99._M_start = (vostok::resources::resource_ptr<survarium::victory_item,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[(int)v98.m_object];
      do
      {
        ++v98.m_object;
        v20 = v99._M_start[55].m_object;
        v21 = (vostok::resources::unmanaged_intrusive_base *)&v99._M_start[180];
        v22 = 0;
        M_data = 0;
        v99._M_start += 180;
        v99._M_end_of_storage._M_data = 0;
        if ( v20 )
        {
          M_data = (vostok::resources::unmanaged_resource *)v20;
          v99._M_end_of_storage._M_data = (vostok::resources::resource_ptr<survarium::victory_item,vostok::resources::unmanaged_intrusive_base> *)v20;
          v21 = (vostok::resources::unmanaged_intrusive_base *)_InterlockedExchangeAdd(
                                                                 (volatile signed __int32 *)&v20->m_name_registry_entry,
                                                                 1u);
        }
        v24 = 0;
        if ( M_data )
        {
          v24 = M_data;
          v21 = &M_data->vostok::resources::unmanaged_intrusive_base;
          _InterlockedExchangeAdd(&M_data->m_reference_count, 1u);
        }
        __x_4.bullet = 0;
        __x_4.tracer.m_object = 0;
        if ( v24 )
        {
          v22 = v24;
          v21 = &v24->vostok::resources::unmanaged_intrusive_base;
          __x_4.tracer.m_object = (vostok::render::tracer_model_instance *)v24;
          __x = (vostok::resources::query_result *)&v24->vostok::resources::unmanaged_intrusive_base;
          _InterlockedExchangeAdd(&v24->m_reference_count, 1u);
          if ( !_InterlockedExchangeAdd(&v24->m_reference_count, 0xFFFFFFFF) )
            vostok::resources::unmanaged_intrusive_base::destroy(v21, v24);
        }
        M_finish = this->m_bullet_tracers._M_impl._M_finish;
        if ( M_finish == this->m_bullet_tracers._M_impl._M_end_of_storage._M_data )
        {
          stlp_std::priv::_Impl_vector<survarium::game_world::bullet_tracer,survarium::std_allocator<survarium::game_world::bullet_tracer>>::_M_insert_overflow_aux(
            (stlp_std::priv::_Impl_vector<survarium::game_world::bullet_tracer,survarium::std_allocator<survarium::game_world::bullet_tracer> > *)v21,
            (stlp_std::reverse_iterator<survarium::game_world::bullet_tracer *> *)&this->m_bullet_tracers,
            M_finish,
            &__x_4,
            v95,
            v96,
            v97);
          v22 = __x_4.tracer.m_object;
          M_data = (vostok::resources::unmanaged_resource *)v99._M_end_of_storage._M_data;
        }
        else
        {
          if ( M_finish )
          {
            M_finish->bullet = 0;
            M_finish->tracer.m_object = 0;
            if ( v22 )
            {
              M_finish->tracer.m_object = (vostok::render::tracer_model_instance *)v22;
              _InterlockedExchangeAdd(&v22->m_reference_count, 1u);
            }
          }
          ++this->m_bullet_tracers._M_impl._M_finish;
        }
        if ( v22 && !_InterlockedExchangeAdd(&v22->m_reference_count, 0xFFFFFFFF) )
          vostok::resources::unmanaged_intrusive_base::destroy(&v22->vostok::resources::unmanaged_intrusive_base, v22);
        if ( M_data && !_InterlockedExchangeAdd(&M_data->m_reference_count, 0xFFFFFFFF) )
          vostok::resources::unmanaged_intrusive_base::destroy(
            &M_data->vostok::resources::unmanaged_intrusive_base,
            M_data);
        ++v99._M_finish;
      }
      while ( v99._M_finish < (vostok::resources::resource_ptr<survarium::victory_item,vostok::resources::unmanaged_intrusive_base> *)s_max_tracers_count );
    }
    death_particles = this->death_particles;
    v99._M_finish = (vostok::resources::resource_ptr<survarium::victory_item,vostok::resources::unmanaged_intrusive_base> *)this->death_particles;
    v27 = &data->m_queries[(int)v98.m_object];
    v99._M_end_of_storage._M_data = (vostok::resources::resource_ptr<survarium::victory_item,vostok::resources::unmanaged_intrusive_base> *)16;
    v98.m_object = (vostok::configs::binary_config *)((char *)v98.m_object + 16);
    while ( 1 )
    {
      v28 = v27->m_unmanaged_resource.m_object;
      v29 = 0;
      __x = v27 + 1;
      if ( v28 )
      {
        v29 = v28;
        _InterlockedExchangeAdd(&v28->m_reference_count, 1u);
      }
      v30 = 0;
      if ( v29 )
      {
        v30 = v29;
        _InterlockedExchangeAdd(&v29->m_reference_count, 1u);
      }
      v31 = v30;
      v32 = death_particles->m_object;
      death_particles->m_object = v31;
      if ( v32 && !_InterlockedExchangeAdd(&v32->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(&v32->vostok::resources::unmanaged_intrusive_base, v32);
      if ( v29 && !_InterlockedExchangeAdd(&v29->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(&v29->vostok::resources::unmanaged_intrusive_base, v29);
      death_particles = (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)&v99._M_finish[1];
      v5 = v99._M_end_of_storage._M_data-- == (vostok::resources::resource_ptr<survarium::victory_item,vostok::resources::unmanaged_intrusive_base> *)1;
      ++v99._M_finish;
      if ( v5 )
        break;
      v27 = __x;
    }
    m_flash_factory = this->m_game->m_flash_factory;
    v34 = (survarium::flash_text_manager *)operator new(0x10u);
    if ( v34 )
    {
      survarium::flash_text_manager::flash_text_manager(v34, m_flash_factory->m_gfx_loader);
      v36 = v35;
    }
    else
    {
      v36 = 0;
    }
    p_m_render_output_window = &this->m_game->m_render_output_window;
    this->m_text_manager = v36;
    v38 = 0;
    if ( p_m_render_output_window->m_object )
    {
      v38 = p_m_render_output_window->m_object;
      _InterlockedExchangeAdd(&p_m_render_output_window->m_object->m_reference_count, 1u);
    }
    if ( v38 && !_InterlockedExchangeAdd(&v38->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v38->vostok::resources::unmanaged_intrusive_base, v38);
    type = v38[1].type;
    v40 = (int)v38[1].__vftable;
    v41 = clear_value;
    vp.Top = 0;
    vp.Width = 0;
    v103 = 0;
    memset(&vp.ScissorTop, 0, 16);
    v36->m_output_height = type;
    vp.Left = type;
    vp.ScissorLeft = type;
    text_manager_impl = v36->text_manager_impl;
    v36->m_output_width = v40;
    vp.BufferHeight = v40;
    vp.Height = v40;
    v105 = v41;
    v104 = v41;
    Scaleform::GFx::DrawTextManager::SetViewport(
      text_manager_impl,
      (const Scaleform::Render::Viewport *)&vp.BufferHeight);
    v36->need_capture = 1;
    vostok::render::game::renderer::show_text_manager(
      (vostok::render::game::renderer *)this->m_game,
      (const vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *)this->m_game->m_renderer,
      (survarium::flash_text_manager *)&this->m_render_scene_view);
    v7 = v98.m_object;
  }
  if ( !this->m_game_material_manager.m_object )
  {
    v43 = data->m_queries[(_DWORD)v7].m_unmanaged_resource.m_object;
    v44 = 0;
    v98.m_object = (vostok::configs::binary_config *)((char *)&v7->__vftable + 1);
    if ( v43 )
    {
      v44 = v43;
      _InterlockedExchangeAdd(&v43->m_reference_count, 1u);
    }
    v45 = 0;
    if ( v44 )
    {
      v45 = v44;
      _InterlockedExchangeAdd(&v44->m_reference_count, 1u);
    }
    v46 = 0;
    if ( v45 )
    {
      v46 = (survarium::game_material_manager *)v45;
      _InterlockedExchangeAdd(&v45->m_reference_count, 1u);
    }
    v47 = v46;
    v48 = this->m_game_material_manager.m_object;
    this->m_game_material_manager.m_object = v47;
    if ( v48 && !_InterlockedExchangeAdd(&v48->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v48->vostok::resources::unmanaged_intrusive_base, v48);
    if ( v45 && !_InterlockedExchangeAdd(&v45->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v45->vostok::resources::unmanaged_intrusive_base, v45);
    if ( v44 && !_InterlockedExchangeAdd(&v44->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v44->vostok::resources::unmanaged_intrusive_base, v44);
    v49 = (survarium::bullet_manager *)vostok::memory::doug_lea_allocator::malloc_impl(
                                         (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
                                         0x80u);
    if ( v49 )
      survarium::bullet_manager::bullet_manager(
        v49,
        this->m_game_material_manager.m_object,
        this->m_physics_world,
        &this->survarium::bullet_manager_engine);
    else
      v50 = 0;
    v7 = v98.m_object;
    this->m_bullet_manager = v50;
  }
  v51 = data->m_queries[(_DWORD)v7].m_unmanaged_resource.m_object;
  v52 = 0;
  v98.m_object = (vostok::configs::binary_config *)((char *)&v7->__vftable + 1);
  if ( v51 )
  {
    v52 = v51;
    _InterlockedExchangeAdd(&v51->m_reference_count, 1u);
  }
  v53 = 0;
  if ( v52 )
  {
    v53 = v52;
    _InterlockedExchangeAdd(&v52->m_reference_count, 1u);
  }
  v54 = 0;
  if ( v53 )
  {
    v54 = (survarium::simple_game_project *)v53;
    _InterlockedExchangeAdd(&v53->m_reference_count, 1u);
  }
  v55 = v54;
  v56 = this->m_game_project.m_object;
  this->m_game_project.m_object = v55;
  if ( v56 && !_InterlockedExchangeAdd(&v56->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v56->vostok::resources::unmanaged_intrusive_base, v56);
  if ( v53 && !_InterlockedExchangeAdd(&v53->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v53->vostok::resources::unmanaged_intrusive_base, v53);
  if ( v52 && !_InterlockedExchangeAdd(&v52->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v52->vostok::resources::unmanaged_intrusive_base, v52);
  if ( !this->m_game->m_network_client->has_bandwidth(this->m_game->m_network_client)
    || this->m_game->m_network_client->lobby_client(this->m_game->m_network_client)->m_status )
  {
    this->show_ui(this, 1);
    m_network_client = this->m_game->m_network_client;
    match_options = m_network_client->match_options;
    HIBYTE(v99._M_end_of_storage.m_allocator) = 0;
    if ( match_options(m_network_client)->victory_items_count )
    {
      v99._M_finish = (vostok::resources::resource_ptr<survarium::victory_item,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[(int)v98.m_object];
      do
      {
        v63 = (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v99._M_finish[55];
        v99._M_finish += 180;
        p_m_prev_in_global_list = 0;
        v98.m_object = 0;
        vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
          &v98,
          v63);
        if ( v98.m_object )
          p_m_prev_in_global_list = (survarium::victory_item *)&v98.m_object[-1].m_prev_in_global_list;
        v99._M_start = 0;
        vostok::intrusive_ptr<survarium::victory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
          (vostok::intrusive_ptr<survarium::victory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v99,
          p_m_prev_in_global_list);
        if ( v98.m_object )
        {
          v65 = v98.m_object;
          v66 = &v98.m_object->vostok::resources::unmanaged_intrusive_base;
          if ( !_InterlockedExchangeAdd(&v98.m_object->m_reference_count, 0xFFFFFFFF) )
            vostok::resources::unmanaged_intrusive_base::destroy(v66, v65);
        }
        v67 = this->m_victory_items._M_impl._M_finish;
        if ( v67 == this->m_victory_items._M_impl._M_end_of_storage._M_data )
        {
          stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<survarium::victory_item,vostok::resources::unmanaged_intrusive_base>,vostok::vectora_allocator<vostok::resources::resource_ptr<survarium::victory_item,vostok::resources::unmanaged_intrusive_base>>>::_M_insert_overflow_aux(
            &v99,
            (int)&this->m_victory_items,
            v67,
            (const vostok::resources::resource_ptr<survarium::victory_item,vostok::resources::unmanaged_intrusive_base> *)&v99,
            (unsigned int)v95,
            v96);
        }
        else
        {
          if ( v67 )
          {
            v67->m_object = 0;
            vostok::intrusive_ptr<survarium::victory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
              v67,
              (const vostok::intrusive_ptr<survarium::victory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v99);
          }
          ++this->m_victory_items._M_impl._M_finish;
        }
        v68 = v99._M_start;
        if ( v99._M_start )
        {
          v69 = (vostok::resources::unmanaged_intrusive_base *)&v99._M_start[60];
          if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v99._M_start[60], 0xFFFFFFFF) )
            vostok::resources::unmanaged_intrusive_base::destroy(v69, (vostok::resources::unmanaged_resource *)&v68[8]);
        }
        v70 = this->m_game->m_network_client;
        v71 = v70->match_options;
        ++HIBYTE(v99._M_end_of_storage.m_allocator);
        v72 = (int)v71(v70);
        LOBYTE(v62) = HIBYTE(v99._M_end_of_storage.m_allocator);
      }
      while ( HIBYTE(v99._M_end_of_storage.m_allocator) < *(_BYTE *)(v72 + 8823) );
    }
    survarium::simple_game_project::insert(v62, (int)this->m_game_project.m_object, &this->m_game->m_scheduler);
    v73 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                    this->m_game_project.m_object->m_config.m_object->m_root,
                                                    (const char *)&stru_96A440.m_inverted_view.lines[2]);
    v74 = vostok::configs::binary_config_value::operator[](v73, "position");
    v75 = *((_DWORD *)v74->data.pointer + 2);
    m_root = this->m_game_project.m_object->m_config.m_object->m_root;
    *(_QWORD *)&vp.BufferHeight = *(_QWORD *)v74->data.pointer;
    vp.Top = v75;
    v77 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                    m_root,
                                                    (const char *)&stru_96A440.m_inverted_view.lines[2]);
    v78 = (vostok::resources::request **)vostok::configs::binary_config_value::operator[](
                                           v77,
                                           (const char *)&stru_96A440.m_inverted_view.lines[2].elements[2]);
    path = (int)(*v78)[1].path;
    m_camera_director = this->m_camera_director;
    __x_4 = (survarium::game_world::bullet_tracer)**v78;
    vp.BufferWidth = path;
    survarium::camera_director::set_position_direction(
      (const vostok::math::float3 *)&vp.BufferHeight,
      (const vostok::math::float3 *)&__x_4,
      m_camera_director);
    survarium::game_camera::set_position_direction(
      (const vostok::math::float3 *)&vp.BufferHeight,
      (const vostok::math::float3 *)&__x_4,
      this->m_free_fly_camera);
    v80 = this->m_camera_director;
    m_free_fly_camera = this->m_free_fly_camera;
    this->m_input_mode = free_fly_mode;
    survarium::camera_director::switch_to_camera(
      v81,
      v80,
      m_free_fly_camera,
      (const char *)&stru_96A440.m_inverted_view.lines[1]);
    if ( this->m_is_active )
    {
      v82 = this->m_game->m_sound_world->get_logic_world_user(this->m_game->m_sound_world);
      vostok::sound::world_user::set_active_sound_scene(v82, &this->m_sound_scene, 0x3E8u, 0);
    }
    if ( this->m_game->m_network_client->has_bandwidth(this->m_game->m_network_client) )
    {
      v84 = this->m_game->m_network_client->match_client(this->m_game->m_network_client);
      survarium::game_world_ui::initialize(&this->game_ui, &this->game_ui, &v84->m_match_options);
    }
    p_m_config = &this->m_game_project.m_object->m_config;
    v108 = 0;
    v109 = 0;
    vostok::variant<32>::set<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>(
      v83,
      v106,
      p_m_config);
    vp.BufferHeight = (int)survarium::game_world::on_portal_system_loaded;
    vp.Left = 0;
    v91.f_.f_ = (void (__thiscall *__ptr64)(survarium::game_world *, vostok::resources::queries_result *))(unsigned int)survarium::game_world::on_portal_system_loaded;
    vp.Top = (int)this;
    *(_QWORD *)&v91.l_.a1_.t_ = *(_QWORD *)&vp.Top;
    boost::function1<void,vostok::resources::queries_result &>::function1<void,vostok::resources::queries_result &>(
      0,
      (int)&vp.BufferHeight,
      (int)v106,
      v91,
      (int)v95);
    v99._M_finish = (vostok::resources::resource_ptr<survarium::victory_item,vostok::resources::unmanaged_intrusive_base> *)v106;
    __x_4.bullet = (survarium::bullet *)&stru_96A440.m_inverted_view.lines[3].elements[1];
    __x_4.tracer.m_object = (vostok::render::tracer_model_instance *)110;
    vostok::resources::query_resources(
      (const vostok::resources::request *)&__x_4,
      1u,
      (const boost::function<void __cdecl(vostok::resources::queries_result &)> *)&vp.BufferHeight,
      (vostok::memory::base_allocator *)survarium::g_allocator.f_.f_,
      (const vostok::variant<32> **)&v99._M_finish,
      0,
      assert_on_fail_true);
    if ( vp.BufferHeight )
    {
      if ( (vp.BufferHeight & 1) == 0 )
      {
        v86 = *(void (__cdecl **)(int *, int *, int))(vp.BufferHeight & 0xFFFFFFFE);
        if ( v86 )
          v86(&vp.Top, &vp.Top, 2);
      }
    }
    survarium::game_world_ui::initialize_minimap(v85, &this->game_ui);
    if ( this->m_game->m_network_client->has_bandwidth(this->m_game->m_network_client) )
      survarium::game_world_ui::show_capture_progress(&this->game_ui);
    if ( callback->vtable )
      boost::function1<void,vostok::render::ambient_volume_properties const &>::operator()(
        (boost::function1<void,char const *> *)data,
        callback,
        (const char *)data);
    m_game = this->m_game;
    m_active_scene = m_game->m_active_scene;
    p_m_game_world = &m_game->m_game_world;
    if ( m_active_scene != &m_game->m_game_world )
    {
      if ( m_active_scene )
        m_active_scene->on_deactivate(m_active_scene);
      m_game->m_active_scene = p_m_game_world;
      p_m_game_world->on_activate(&m_game->m_game_world);
    }
    v90 = v108;
    this->m_is_loading = 0;
    if ( v90 )
      (*(void (__thiscall **)(int, char *))(*(_DWORD *)v90 + 4))(v90, v107);
  }
  else
  {
    survarium::game_world::unload(
      v57,
      (vostok::resources::resource_ptr<survarium::human_npc,vostok::resources::unmanaged_intrusive_base>)this);
    v58 = this->m_game;
    m_lobby_menu = v58->m_lobby_menu;
    if ( m_lobby_menu->m_is_in_match_making )
    {
      survarium::base_game_scene::hide_movie(v58->m_lobby_menu, &m_lobby_menu->m_match_making_ui, (int)v58);
      m_lobby_menu->m_is_in_match_making = 0;
    }
    this->m_is_loading = 0;
  }
}
