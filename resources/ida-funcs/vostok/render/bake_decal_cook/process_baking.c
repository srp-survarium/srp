char __thiscall vostok::render::bake_decal_cook::process_baking(
        vostok::render::bake_decal_cook *this,
        vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> out_result,
        vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *data,
        int surface,
        vostok::render::render_target *parameters)
{
  ID3D11DeviceContext *m_context; // eax
  ID3D11DeviceContext_vtbl *v6; // ecx
  int v7; // ebx
  vostok::render::bake_decal_cook *v8; // ecx
  LARGE_INTEGER QPC; // rax
  vostok::render::render_surface *v10; // ecx
  vostok::render::material_effects *material_effects; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v12; // ecx
  bool has_passed_filters; // al
  bool v14; // zf
  vostok::render::bake_decal_cook *v15; // ecx
  vostok::particle::particle_system_instance_impl *m_object; // eax
  vostok::render::res_effect *v17; // ecx
  vostok::render::result_struct *v18; // ecx
  vostok::render::resource_manager *v19; // ecx
  vostok::shared_string *p_m_name; // eax
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *diffuse_texture; // eax
  vostok::render::backend *v22; // ecx
  unsigned int *p_type; // eax
  vostok::render::resource_manager *v24; // ecx
  vostok::shared_string *v25; // eax
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *normal_texture; // eax
  vostok::render::backend *v27; // ecx
  unsigned int *v28; // eax
  vostok::render::resource_manager *v29; // ecx
  vostok::shared_string *v30; // eax
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *fresnel_texture; // eax
  vostok::render::backend *v32; // ecx
  unsigned int *v33; // eax
  vostok::render::resource_manager *v34; // ecx
  vostok::shared_string *v35; // eax
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *smoothness_texture; // eax
  vostok::render::backend *v37; // ecx
  vostok::render::resource_manager *v38; // ecx
  unsigned int *v39; // eax
  vostok::render::render_target *v40; // esi
  vostok::render::render_target *v41; // ecx
  vostok::render::render_target *v42; // ecx
  vostok::timing::timer *v43; // ecx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v44; // ecx
  bool v45; // al
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v46; // esi
  vostok::render::result_struct *v47; // ecx
  vostok::render::result_struct *v48; // ecx
  bool v50; // al
  vostok::render::system_renderer *v51; // [esp-Ch] [ebp-9Ch]
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v52; // [esp-8h] [ebp-98h] BYREF
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v53; // [esp-4h] [ebp-94h] BYREF
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v54; // [esp+0h] [ebp-90h] BYREF
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v55; // [esp+4h] [ebp-8Ch] BYREF
  __int64 v56; // [esp+8h] [ebp-88h]
  const D3D11_VIEWPORT *v57; // [esp+10h] [ebp-80h]
  float v58; // [esp+14h] [ebp-7Ch]
  float v59; // [esp+18h] [ebp-78h]
  float v60; // [esp+1Ch] [ebp-74h]
  D3D11_VIEWPORT v61; // [esp+20h] [ebp-70h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v62; // [esp+38h] [ebp-58h] BYREF
  vostok::render::result_struct v63; // [esp+58h] [ebp-38h] BYREF
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> object; // [esp+68h] [ebp-28h] BYREF
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v65; // [esp+6Ch] [ebp-24h] BYREF
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v66; // [esp+70h] [ebp-20h] BYREF
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v67; // [esp+74h] [ebp-1Ch] BYREF
  __int64 v68; // [esp+78h] [ebp-18h] BYREF
  vostok::render::render_target *v69; // [esp+80h] [ebp-10h]
  vostok::render::render_target *v70; // [esp+84h] [ebp-Ch]
  vostok::render::render_target *v71; // [esp+88h] [ebp-8h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v72; // [esp+8Ch] [ebp-4h] BYREF

  m_context = vostok::quasi_singleton<vostok::render::device>::pinst->m_context;
  v6 = m_context->lpVtbl;
  v7 = surface;
  surface = 0;
  v6->Flush(m_context);
  vostok::render::bake_decal_cook::register_constants(v8, (int)out_result.m_object);
  qmemcpy(
    (void *)&v61,
    (const void *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 120),
    sizeof(v61));
  vostok::timing::timer::timer(0, (LARGE_INTEGER *)&v62.functor);
  QPC = vostok::timing::get_QPC();
  *(_QWORD *)&v62.functor.obj_ptr = 0;
  *((LARGE_INTEGER *)&v62.functor.data + 1) = QPC;
  material_effects = vostok::render::render_surface::get_material_effects(v10, *(_DWORD *)(v7 + 16));
  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v72,
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&material_effects->m_effects[1]);
  if ( !v72.m_object )
  {
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(
                                 (vostok::logging::filter_tree *)"render_pc_dx11",
                                 (const char *)2),
          v12 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)HIDWORD(v56),
          has_passed_filters) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        v12,
        &v62);
      surface = 1;
      vostok::logging::append(
        &v62,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\bake_decal_cook.cpp",
        0x2CAu,
        "bool __thiscall vostok::render::bake_decal_cook::process_baking(struct vostok::render::result_struct &,class vos"
        "tok::resources::queries_result &,struct vostok::render::render_surface_instance *,const struct vostok::render::b"
        "ake_decal_parameters &)",
        "render_pc_dx11",
        error,
        "the baking model material must have gbuffer stage");
    }
    v14 = (surface & 1) == 0;
LABEL_58:
    if ( !v14 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v12,
        (int *)&v62);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v72);
    return 0;
  }
  vostok::render::res_effect::get_texture_resolution((vostok::render::res_effect *)&v68, (int)v72.m_object);
  if ( !(_DWORD)v68 || !HIDWORD(v68) )
  {
    if ( !vostok::core::g_log_filter_tree
      || (v50 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"render_pc_dx11", (const char *)2),
          v12 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)HIDWORD(v56),
          v50) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        v12,
        &v62);
      surface = 2;
      vostok::logging::append(
        &v62,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\bake_decal_cook.cpp",
        0x2D3u,
        "bool __thiscall vostok::render::bake_decal_cook::process_baking(struct vostok::render::result_struct &,class vos"
        "tok::resources::queries_result &,struct vostok::render::render_surface_instance *,const struct vostok::render::b"
        "ake_decal_parameters &)",
        "render_pc_dx11",
        error,
        "the model material must have a diffuse texture");
    }
    v14 = (surface & 2) == 0;
    goto LABEL_58;
  }
  vostok::render::bake_decal_cook::accumulate_decals(
    (vostok::render::bake_decal_cook *)v12,
    (vostok::math::float4x4 *)out_result.m_object,
    &object,
    (vostok::render::render_surface_instance *)v7,
    (unsigned int)parameters,
    v68,
    HIDWORD(v68),
    (DXGI_FORMAT)v57,
    SLODWORD(v58));
  vostok::render::bake_decal_cook::composition(
    v15,
    (vostok::render::bake_decal_cook *)out_result.m_object,
    &v63,
    (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)&object,
    (vostok::render::render_surface_instance *)v7,
    parameters,
    v68);
  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &out_result,
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&vostok::quasi_singleton<vostok::render::system_renderer>::pinst->m_add_border_padding_effect);
  m_object = out_result.m_object;
  LODWORD(out_result.m_object[28].m_current_satisfaction_update_tick) = 0;
  vostok::render::res_effect::apply_pass(v17, (int)m_object);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&out_result);
  HIBYTE(out_result.m_object) = (vostok::render::result_struct::get_diffuse_texture(
                                   v18,
                                   (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)&v63,
                                   (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&parameters)->m_object != 0
                               ? (unsigned int)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
                               : 0) != 0;
  if ( parameters )
  {
    p_m_name = &parameters->m_name;
    --parameters->m_name.m_pointer.m_object;
    if ( !p_m_name->m_pointer.m_object )
      vostok::render::resource_manager::release(
        v19,
        (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
        (vostok::render::res_texture *)parameters);
  }
  if ( HIBYTE(out_result.m_object) )
  {
    diffuse_texture = vostok::render::result_struct::get_diffuse_texture(
                        (vostok::render::result_struct *)v19,
                        (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)&v63,
                        (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&out_result);
    vostok::render::backend::set_ps_texture(
      v22,
      SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      "t_source_diffuse",
      diffuse_texture->m_object);
    if ( *(float *)&out_result.m_object != 0.0 )
    {
      p_type = &out_result.m_object->type;
      --out_result.m_object->type;
      if ( !*p_type )
        vostok::render::resource_manager::release(
          v19,
          (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          (vostok::render::res_texture *)out_result.m_object);
    }
  }
  HIBYTE(out_result.m_object) = (vostok::render::result_struct::get_normal_texture(
                                   (vostok::render::result_struct *)v19,
                                   (int)&v63,
                                   (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&parameters)->m_object != 0
                               ? (unsigned int)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
                               : 0) != 0;
  if ( parameters )
  {
    v25 = &parameters->m_name;
    --parameters->m_name.m_pointer.m_object;
    if ( !v25->m_pointer.m_object )
      vostok::render::resource_manager::release(
        v24,
        (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
        (vostok::render::res_texture *)parameters);
  }
  if ( HIBYTE(out_result.m_object) )
  {
    normal_texture = vostok::render::result_struct::get_normal_texture(
                       (vostok::render::result_struct *)v24,
                       (int)&v63,
                       (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&out_result);
    vostok::render::backend::set_ps_texture(
      v27,
      SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      "t_source_normal",
      normal_texture->m_object);
    if ( *(float *)&out_result.m_object != 0.0 )
    {
      v28 = &out_result.m_object->type;
      --out_result.m_object->type;
      if ( !*v28 )
        vostok::render::resource_manager::release(
          v24,
          (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          (vostok::render::res_texture *)out_result.m_object);
    }
  }
  HIBYTE(out_result.m_object) = (vostok::render::result_struct::get_fresnel_texture(
                                   (vostok::render::result_struct *)v24,
                                   (int)&v63,
                                   (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&parameters)->m_object != 0
                               ? (unsigned int)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
                               : 0) != 0;
  if ( parameters )
  {
    v30 = &parameters->m_name;
    --parameters->m_name.m_pointer.m_object;
    if ( !v30->m_pointer.m_object )
      vostok::render::resource_manager::release(
        v29,
        (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
        (vostok::render::res_texture *)parameters);
  }
  if ( HIBYTE(out_result.m_object) )
  {
    fresnel_texture = vostok::render::result_struct::get_fresnel_texture(
                        (vostok::render::result_struct *)v29,
                        (int)&v63,
                        (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&out_result);
    vostok::render::backend::set_ps_texture(
      v32,
      SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      "t_source_fresnel",
      fresnel_texture->m_object);
    if ( *(float *)&out_result.m_object != 0.0 )
    {
      v33 = &out_result.m_object->type;
      --out_result.m_object->type;
      if ( !*v33 )
        vostok::render::resource_manager::release(
          v29,
          (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          (vostok::render::res_texture *)out_result.m_object);
    }
  }
  HIBYTE(out_result.m_object) = (vostok::render::result_struct::get_smoothness_texture(
                                   (vostok::render::result_struct *)v29,
                                   (int)&v63,
                                   (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&parameters)->m_object != 0
                               ? (unsigned int)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
                               : 0) != 0;
  if ( parameters )
  {
    v35 = &parameters->m_name;
    --parameters->m_name.m_pointer.m_object;
    if ( !v35->m_pointer.m_object )
      vostok::render::resource_manager::release(
        v34,
        (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
        (vostok::render::res_texture *)parameters);
  }
  if ( HIBYTE(out_result.m_object) )
  {
    smoothness_texture = vostok::render::result_struct::get_smoothness_texture(
                           (vostok::render::result_struct *)v34,
                           (int)&v63,
                           (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&out_result);
    vostok::render::backend::set_ps_texture(
      v37,
      SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      "t_source_smoothness",
      smoothness_texture->m_object);
    if ( *(float *)&out_result.m_object != 0.0 )
    {
      v39 = &out_result.m_object->type;
      --out_result.m_object->type;
      if ( !*v39 )
        vostok::render::resource_manager::release(
          v38,
          (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          (vostok::render::res_texture *)out_result.m_object);
    }
  }
  v40 = v67.m_object;
  v56 = 0;
  if ( !v67.m_object
    || !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    v40 = 0;
  }
  if ( !v66.m_object
    || (v71 = v66.m_object,
        !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr) )
  {
    v71 = 0;
  }
  if ( !v65.m_object
    || (v70 = v65.m_object,
        !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr) )
  {
    v70 = 0;
  }
  if ( !object.m_object
    || (v69 = object.m_object,
        !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr) )
  {
    v69 = 0;
  }
  v55.m_object = (vostok::render::render_target *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr;
  HIDWORD(v68) = vostok::quasi_singleton<vostok::render::system_renderer>::pinst;
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
    &v55,
    v40);
  v54.m_object = v41;
  v53.m_object = v41;
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
    &v54,
    v71);
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
    &v53,
    v70);
  v52.m_object = v42;
  v51 = (vostok::render::system_renderer *)v42;
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
    &v52,
    v69);
  vostok::render::system_renderer::fill_surface(
    v51,
    *(vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)((char *)&v68 + 4),
    v52.m_object,
    v53.m_object,
    v54.m_object,
    v55,
    (vostok::render::render_target *)v56,
    (D3D11_VIEWPORT *)HIDWORD(v56),
    *(float *)&v57,
    v58,
    v59,
    v60);
  vostok::quasi_singleton<vostok::render::device>::pinst->m_context->Flush(vostok::quasi_singleton<vostok::render::device>::pinst->m_context);
  *(float *)&out_result.m_object = vostok::timing::timer::get_elapsed_sec(v43, (int)&v62.functor);
  if ( !vostok::core::g_log_filter_tree
    || (v45 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"render_pc_dx11", (const char *)4),
        v44 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)HIDWORD(v56),
        v45) )
  {
    boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
      v44,
      &v62);
    surface = 4;
    vostok::logging::append(
      &v62,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\bake_decal_cook.cpp",
      0x2F9u,
      "bool __thiscall vostok::render::bake_decal_cook::process_baking(struct vostok::render::result_struct &,class vosto"
      "k::resources::queries_result &,struct vostok::render::render_surface_instance *,const struct vostok::render::bake_"
      "decal_parameters &)",
      "render_pc_dx11",
      info,
      "decal bake time: %.3f ms",
      (float)(*(float *)&out_result.m_object * 1000.0));
  }
  if ( (surface & 4) != 0 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v44,
      (int *)&v62);
  vostok::render::backend::set_viewports(
    (vostok::render::backend *)v44,
    SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    &v61,
    v57);
  v46 = data;
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    &object,
    data);
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    &v65,
    v46 + 1);
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    &v66,
    v46 + 2);
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    &v67,
    v46 + 3);
  vostok::render::result_struct::~result_struct(v47, &v63.diffuse);
  vostok::render::result_struct::~result_struct(v48, &object);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v72);
  return 1;
}
