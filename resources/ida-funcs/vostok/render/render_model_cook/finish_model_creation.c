void __thiscall vostok::render::render_model_cook::finish_model_creation(
        vostok::render::render_model_cook *this,
        vostok::resources::queries_result *data_material_effects,
        vostok::render::cook_intermediate_data *cook_data)
{
  vostok::render::cook_intermediate_data *v3; // ebx
  bool v4; // zf
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *parent_query; // edi
  vostok::memory::doug_lea_allocator *v6; // ecx
  vostok::render::model_asset **p_assets; // eax
  vostok::memory::doug_lea_allocator *v8; // esi
  char *v9; // eax
  char *v10; // eax
  const void *pointer; // eax
  vostok::resources::managed_resource *v12; // ecx
  const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *p_converted_model_buffer; // edi
  vostok::resources::pinned_ptr_mutable<unsigned char> *v14; // ecx
  vostok::render::render_surface *render_surface; // edi
  char *m_begin; // esi
  vostok::buffer_string *p_shading_group_name; // eax
  char *v18; // ecx
  vostok::render::cook_intermediate_data *v19; // ecx
  unsigned int material_index; // eax
  vostok::particle::particle_system_instance_impl *v21; // esi
  vostok::resources::query_result_for_user *v22; // ecx
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *v23; // edi
  vostok::resources::unmanaged_resource *v24; // eax
  vostok::particle::particle_system_instance_impl *v25; // ecx
  vostok::render::render_surface *v26; // ecx
  bool has_passed_filters; // al
  vostok::resources::query_result_for_user *v28; // ecx
  const char *requested_path; // eax
  vostok::resources::pinned_ptr_const<unsigned char> *v30; // ecx
  unsigned int m_num_render_models; // eax
  survarium::pure_game_effect_emitter_base *v32; // esi
  survarium::pure_game_effect_emitter_base *v33; // ecx
  vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *v34; // edi
  vostok::resources::query_result_for_cook *v35; // ecx
  vostok::resources::query_result_for_cook *v36; // ecx
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v37; // [esp-Ch] [ebp-ACh] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v38; // [esp-8h] [ebp-A8h] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v39; // [esp-4h] [ebp-A4h] BYREF
  const char *v40; // [esp+0h] [ebp-A0h]
  const char *v41; // [esp+4h] [ebp-9Ch]
  unsigned int v42; // [esp+8h] [ebp-98h]
  int v43; // [esp+Ch] [ebp-94h]
  unsigned __int16 type[2]; // [esp+10h] [ebp-90h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v45; // [esp+14h] [ebp-8Ch] BYREF
  int v46; // [esp+18h] [ebp-88h]
  unsigned int v47; // [esp+1Ch] [ebp-84h]
  vostok::resources::pinned_ptr_const<unsigned char> *v48; // [esp+20h] [ebp-80h]
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *other; // [esp+24h] [ebp-7Ch]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v50; // [esp+28h] [ebp-78h] BYREF
  char *v51; // [esp+2Ch] [ebp-74h]
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v52; // [esp+30h] [ebp-70h] BYREF
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v53; // [esp+34h] [ebp-6Ch] BYREF
  vostok::render::render_model_cook *v54; // [esp+38h] [ebp-68h]
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *v55; // [esp+3Ch] [ebp-64h]
  vostok::resources::managed_resource *v56; // [esp+40h] [ebp-60h]
  vostok::resources::unmanaged_resource *m_object; // [esp+44h] [ebp-5Ch]
  vostok::resources::managed_resource *v58; // [esp+48h] [ebp-58h]
  int v59; // [esp+4Ch] [ebp-54h]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> ptr; // [esp+54h] [ebp-4Ch] BYREF
  const unsigned __int8 *v61; // [esp+58h] [ebp-48h]
  unsigned int v62; // [esp+5Ch] [ebp-44h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v63; // [esp+60h] [ebp-40h] BYREF
  vostok::memory::chunk_reader v64; // [esp+80h] [ebp-20h] BYREF

  v46 = 0;
  v3 = cook_data;
  v4 = !cook_data->status_failed;
  parent_query = (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)cook_data->parent_query;
  v54 = this;
  v55 = parent_query;
  if ( v4 )
  {
    v8 = vostok::render::g_allocator;
    v9 = type_info::raw_name(&vostok::render::render_surface * `RTTI Type Descriptor');
    v10 = vostok::memory::doug_lea_allocator::malloc_impl(
            (vostok::memory::doug_lea_allocator *)(4 * v3->m_num_render_models),
            (int)v8,
            4 * v3->m_num_render_models,
            v9,
            v40,
            v41,
            v42);
    v48 = 0;
    v4 = v3->m_num_render_models == 0;
    v51 = v10;
    if ( !v4 )
    {
      v47 = 0;
      other = (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data_material_effects->m_queries[0].m_unmanaged_resource;
      do
      {
        vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
          &v45,
          (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v3->assets[v47 / 0x120].export_properties_config);
        m_object = v45.m_object->m_lods[0].m_template.m_object;
        pointer = vostok::configs::binary_config_value::operator[](
                    (vostok::configs::binary_config_value *)m_object,
                    "type")->data.pointer;
        v59 = 0;
        *(_DWORD *)type = (unsigned __int16)pointer;
        if ( v54->m_class_id == grass_render_model_class )
          *(_DWORD *)type = 200;
        p_converted_model_buffer = &v3->assets[v47 / 0x120].converted_model_buffer;
        v39.m_object = v12;
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
          &v39,
          p_converted_model_buffer);
        vostok::resources::pinned_ptr_const<unsigned char>::pinned_ptr_const<unsigned char>(
          v14,
          (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>)&ptr,
          v39);
        render_surface = vostok::render::model_factory::create_render_surface(type[0]);
        m_begin = v3->assets[v47 / 0x120].m_surface_name.m_string.m_begin;
        p_shading_group_name = &render_surface->m_render_geometry.shading_group_name;
        v18 = render_surface->m_render_geometry.shading_group_name.m_begin;
        *(_DWORD *)type = render_surface;
        v58 = (vostok::resources::managed_resource *)m_begin;
        if ( v18 != "---" )
        {
          render_surface->m_render_geometry.shading_group_name.m_end = v18;
          *v18 = 0;
          p_shading_group_name = vostok::buffer_string::operator+=(p_shading_group_name, "---");
        }
        v19 = (vostok::render::cook_intermediate_data *)p_shading_group_name->m_begin;
        if ( p_shading_group_name->m_begin != m_begin )
        {
          p_shading_group_name->m_end = (char *)v19;
          LOBYTE(v19->root_model_path.m_string.m_begin) = 0;
          vostok::buffer_string::operator+=(p_shading_group_name, m_begin);
        }
        v4 = !v3->material_settings_valid;
        HIBYTE(v43) = 0;
        if ( v4 )
          goto LABEL_19;
        material_index = vostok::render::cook_intermediate_data::find_material_index(v19, (int)v3, m_begin);
        if ( material_index == -1 )
          goto LABEL_19;
        vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
          &v53,
          (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v3->assets[material_index].material);
        v21 = (vostok::particle::particle_system_instance_impl *)v53.m_object;
        if ( v53.m_object )
        {
          v50.m_object = 0;
          vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v50);
          v50.m_object = v21;
          v22 = (vostok::resources::query_result_for_user *)_InterlockedExchangeAdd(&v21->m_reference_count, 1u);
          v23 = other;
          if ( vostok::resources::query_result_for_user::is_successful(v22, (int)&other[-55]) )
          {
            v24 = v21->m_lods[0].m_template.m_object;
            HIBYTE(v43) = 1;
            v56 = (vostok::resources::managed_resource *)v24;
            vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
              &v52,
              v23);
            v39.m_object = v56;
            v38.m_object = v25;
            vostok::resources::resource_ptr<survarium::game_effect_emitter,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::game_effect_emitter,vostok::resources::unmanaged_intrusive_base>(
              &v38,
              (vostok::particle::particle_system_instance_impl *)v52.m_object);
            vostok::render::render_surface::set_material_effects(
              v26,
              *(vostok::resources::resource_ptr<vostok::render::material_effects_instance,vostok::resources::unmanaged_intrusive_base> *)type,
              (const char *)v38.m_object,
              (const char *)v39.m_object);
            vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v52);
          }
          vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v50);
        }
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v53);
        render_surface = *(vostok::render::render_surface **)type;
        if ( !HIBYTE(v43) )
        {
LABEL_19:
          vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>::operator=(
            (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)v19,
            (vostok::particle::particle_system_instance_impl **)&render_surface->m_materail_effects_instance);
          if ( !vostok::core::g_log_filter_tree
            || (has_passed_filters = vostok::logging::has_passed_filters(
                                       (vostok::logging::filter_tree *)"render_pc_dx11",
                                       (const char *)2),
                v19 = (vostok::render::cook_intermediate_data *)v39.m_object,
                has_passed_filters) )
          {
            boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
              (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v19,
              &v63);
            v39.m_object = v58;
            v28 = v3->parent_query;
            v46 |= 1u;
            requested_path = vostok::resources::query_result_for_user::get_requested_path(v28);
            vostok::logging::append(
              &v63,
              (void *const)vostok::core::g_log_flags,
              &vostok::core::g_log_format,
              ".\\render_model_cooker.cpp",
              0x34Cu,
              "void __thiscall vostok::render::render_model_cook::finish_model_creation(class vostok::resources::queries_"
              "result &,struct vostok::render::cook_intermediate_data *)",
              "render_pc_dx11",
              error,
              "material not loaded for %s : %s",
              requested_path,
              (const char *)v39.m_object);
          }
          if ( (v46 & 1) != 0 )
          {
            v46 &= ~1u;
            boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
              (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v19,
              (int *)&v63);
          }
        }
        vostok::memory::chunk_reader::chunk_reader(
          &v64,
          v61,
          (vostok::memory::chunk_reader *)v19,
          v62,
          (vostok::memory::chunk_reader::chunk_type)v40);
        render_surface->load(render_surface, (const vostok::configs::binary_config_value *)m_object, &v64);
        v30 = v48;
        *(_DWORD *)&v51[4 * (_DWORD)v48] = render_surface;
        vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>::~pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>(v30);
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v45);
        m_num_render_models = v3->m_num_render_models;
        v48 = (vostok::resources::pinned_ptr_const<unsigned char> *)((char *)v48 + 1);
        v47 += 288;
        other += 184;
      }
      while ( (unsigned int)v48 < m_num_render_models );
    }
    v45.m_object = 0;
    vostok::render::arrange_surfaces_by_lod(v3, (vostok::render::model_lods_descriptor **)&v45);
    v3->result_model.m_object->set_children(
      v3->result_model.m_object,
      (vostok::render::render_surface **)v51,
      v3->m_num_render_models,
      (vostok::render::model_lods_descriptor *)v45.m_object);
    v32 = (survarium::pure_game_effect_emitter_base *)v3->result_model.m_object;
    v39.m_object = (vostok::resources::managed_resource *)312;
    v38.m_object = (vostok::particle::particle_system_instance_impl *)&vostok::resources::nocache_memory;
    v37.m_object = v33;
    vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
      &v37,
      v32);
    v34 = (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)v55;
    vostok::resources::query_result_for_cook::set_unmanaged_resource(
      v35,
      v55,
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)v37.m_object,
      (const vostok::resources::memory_type *)v38.m_object,
      (unsigned int)v39.m_object);
    vostok::resources::query_result_for_cook::finish_query_impl(
      v36,
      v34,
      result_out_of_memory,
      assert_on_fail_true,
      result_fail);
    p_assets = &v3->assets;
    goto LABEL_26;
  }
  vostok::resources::query_result_for_cook::finish_query_impl(
    (vostok::resources::query_result_for_cook *)this,
    (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)parent_query,
    result_success,
    assert_on_fail_true,
    result_out_of_memory|0x8);
  p_assets = &v3->assets;
  if ( v3->assets )
LABEL_26:
    vostok::memory::delete_array_helper<vostok::memory::doug_lea_allocator,vostok::render::model_asset>(
      p_assets,
      v6,
      vostok::render::g_allocator);
  vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::cook_intermediate_data>(
    vostok::render::g_allocator,
    &cook_data,
    v40,
    v41,
    v42);
}
