void __thiscall vostok::render::stage_lights::execute(vostok::render::stage_lights *this)
{
  ID3D11RenderTargetView *v2; // ebp
  bool v3; // zf
  vostok::render::renderer_context *m_context; // esi
  const vostok::math::float4x4 *v5; // eax
  vostok::render::render_target *m_object; // eax
  vostok::render::render_target *v7; // eax
  const char *m_conflicted_key_name; // ebx
  vostok::render::resource_manager *v9; // ecx
  const char *v10; // eax
  int v11; // eax
  vostok::render::base_scene_view *v12; // edi
  vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *m_next_delay_delete; // esi
  vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **i; // edi
  const vostok::math::float4x4 *v15; // eax
  vostok::render::render_target *v16; // eax
  vostok::render::resource_manager *v17; // ecx
  ID3D11RenderTargetView *m_rt; // edx
  const char *v19; // eax
  vostok::render::base_scene_view *v20; // eax
  vostok::render::environment_probe **m_flags; // esi
  vostok::render::environment_probe **v22; // eax
  vostok::render::renderer_context *v23; // eax
  const vostok::math::float4x4 *p_m_vp; // edx
  vostok::render::scene *m_scene; // eax
  vostok::render::render_surface_instance *v26; // edi
  vostok::render::render_surface *m_render_surface; // esi
  vostok::render::material_effects_instance *v28; // eax
  vostok::render::material_effects *p_m_material_effects; // eax
  vostok::render::environment_probe *v30; // ebp
  vostok::render::speedtree_forest::tree_render_info *z_low; // eax
  float v32; // xmm5_4
  vostok::math::float4x4 *v33; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v34; // ecx
  void (__cdecl *v35)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  vostok::render::lights_db *v36; // eax
  vostok::render::vector<vostok::render::light_data> *v37; // ecx
  const vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *p_m_sun; // eax
  vostok::render::light *v39; // edi
  vostok::render::grass_render_model *v40; // esi
  vostok::render::light_data *j; // ebp
  vostok::render::light *v42; // edi
  vostok::render::grass_render_model *v43; // esi
  vostok::render::speedtree_forest::tree_render_info *M_start; // ebp
  vostok::render::speedtree_forest::tree_render_info *M_finish; // ebx
  vostok::render::speedtree_tree_component **p_tree_component; // edi
  const vostok::math::float4x4 *v47; // eax
  vostok::render::material_effects_instance *v48; // eax
  vostok::render::material_effects *v49; // eax
  vostok::render::material_effects_instance *v50; // eax
  vostok::render::material_effects *v51; // eax
  vostok::render::light *v52; // esi
  vostok::render::light_data *k; // esi
  void *m_reconstruction_info_actuality_tick_high; // esi
  vostok::render::renderer_context *v55; // esi
  vostok::particle::world *v56; // ebx
  const vostok::math::float4x4 *v57; // eax
  void **v58; // eax
  vostok::render::grass_render_model *v59; // ecx
  int y; // eax
  vostok::render::renderer_context *v61; // ecx
  vostok::render::render_target *v62; // eax
  vostok::render::render_target *v63; // ecx
  vostok::render::render_target *v64; // eax
  vostok::render::resource_manager *v65; // ecx
  vostok::render::render_target *v66; // eax
  ID3D11RenderTargetView *v67; // ebp
  vostok::render::resource_manager *v68; // ecx
  vostok::particle::render_particle_emitter_instance *const *v69; // ecx
  vostok::particle::render_particle_emitter_instance *v70; // ebp
  void (__thiscall *set_aabb)(vostok::particle::render_particle_emitter_instance *, const vostok::math::aabb *); // eax
  float v72; // esi
  vostok::render::environment_probe **v73; // edi
  vostok::render::environment_probe **v74; // ebx
  vostok::render::environment_probe *v75; // esi
  vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v76; // ecx
  vostok::render::light *v77; // ecx
  vostok::render::light *v78; // edi
  vostok::render::stage_lights *v79; // ebx
  vostok::render::light_data *m; // esi
  void **v81; // eax
  void *v82; // esi
  const vostok::math::float4x4 *v83; // eax
  const char *v84; // esi
  vostok::render::backend *v85; // ecx
  int v86; // eax
  const vostok::math::float3 *p_m_view_pos; // [esp+14h] [ebp-15Ch]
  const vostok::math::float4x4 *v88; // [esp+20h] [ebp-150h]
  float model_probe_sqdist; // [esp+38h] [ebp-138h] BYREF
  vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> object; // [esp+3Ch] [ebp-134h] BYREF
  float max_rad; // [esp+40h] [ebp-130h]
  vostok::render::render_surface_instance *const *end_d; // [esp+44h] [ebp-12Ch] BYREF
  const vostok::render::vector<vostok::render::light_data> *e_lights; // [esp+48h] [ebp-128h]
  vostok::render::environment_probe *found_probe; // [esp+4Ch] [ebp-124h]
  vostok::render::environment_probe **probe_it; // [esp+50h] [ebp-120h]
  vostok::particle::render_particle_emitter_instance *const *it; // [esp+54h] [ebp-11Ch]
  vostok::particle::enum_particle_render_mode particle_render_mode; // [esp+58h] [ebp-118h]
  vostok::render::render_surface_instance **it_d; // [esp+5Ch] [ebp-114h]
  vostok::render::environment_probe **v100; // [esp+60h] [ebp-110h]
  vostok::render::render_surface_instance *instance; // [esp+64h] [ebp-10Ch]
  vostok::render::vector<vostok::render::speedtree_forest::tree_render_info> visible_trees; // [esp+68h] [ebp-108h] BYREF
  vostok::render::vector<vostok::render::render_surface_instance *> m_dynamic_visuals; // [esp+74h] [ebp-FCh] BYREF
  vostok::vectora<vostok::particle::render_particle_emitter_instance *> emitters; // [esp+80h] [ebp-F0h] BYREF
  vostok::math::aabb bbox; // [esp+90h] [ebp-E0h] BYREF
  D3D11_VIEWPORT tmp_viewport; // [esp+A8h] [ebp-C8h] BYREF
  _QWORD v107[3]; // [esp+C0h] [ebp-B0h] BYREF
  vostok::math::float4x4 v108; // [esp+D8h] [ebp-98h] BYREF
  D3D11_VIEWPORT orig_viewport; // [esp+118h] [ebp-58h] BYREF
  vostok::math::float4x4 v110; // [esp+130h] [ebp-40h] BYREF

  v2 = 0;
  object.m_object = 0;
  if ( !vostok::render::stage_lights::is_effects_ready(this, this) )
    return;
  if ( !((unsigned __int8 (*)(void))this->is_enabled)() )
  {
    this->execute_disabled(this);
    return;
  }
  v3 = !this->m_is_forward_lighting_pass;
  m_context = this->m_context;
  e_lights = &m_context->m_scene->m_lights.m_object->m_lights;
  if ( v3 )
  {
    v5 = vostok::math::float4x4::identity(&v108);
    vostok::render::renderer_context::set_w(m_context, v5);
    m_object = this->m_context->m_targets->m_family[28].target.m_object;
    max_rad = 0.0;
    if ( *(float *)&m_object != 0.0 )
    {
      ++m_object->m_reference_count;
      max_rad = *(float *)&m_object;
    }
    v7 = this->m_context->m_targets->m_family[26].target.m_object;
    if ( v7 )
    {
      v2 = (ID3D11RenderTargetView *)this->m_context->m_targets->m_family[26].target.m_object;
      ++v7->m_reference_count;
    }
    m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    vostok::render::backend::set_render_targets(
      v2,
      (const vostok::render::render_target *)LODWORD(max_rad),
      0,
      0,
      (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
    if ( v2 )
    {
      v3 = v2->lpVtbl-- == (ID3D11RenderTargetView_vtbl *)1;
      if ( v3 )
      {
        vostok::render::resource_manager::release(
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          (const char *)v2);
        m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      }
    }
    v10 = (const char *)LODWORD(max_rad);
    if ( max_rad != 0.0 )
    {
      v3 = (*(_DWORD *)LODWORD(max_rad))-- == 1;
      if ( v3 )
      {
        vostok::render::resource_manager::release(
          v9,
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          v10);
        m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      }
    }
    v11 = *((_DWORD *)m_conflicted_key_name + 547);
    v3 = *((_DWORD *)m_conflicted_key_name + 539) == v11;
    *((_DWORD *)m_conflicted_key_name + 539) = v11;
    LOBYTE(v9) = !v3;
    *((_BYTE *)m_conflicted_key_name + 167) |= !v3;
    v12 = this->m_context->m_scene_view.m_object;
    m_next_delay_delete = (vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v12[4].m_next_delay_delete;
    for ( i = (vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)&v12[4].232;
          m_next_delay_delete != i[1];
          ++m_next_delay_delete )
    {
      if ( *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
           + 288) )
      {
        v9 = (vostok::render::resource_manager *)m_next_delay_delete->m_object;
        if ( m_next_delay_delete->m_object[9].m_is_registered )
          continue;
      }
      if ( *(&m_next_delay_delete->m_object[9].m_is_registered + 3) )
        vostok::render::stage_lights::render_light(
          (vostok::render::stage_lights *)v9,
          m_next_delay_delete,
          this,
          (vostok::render::light *)m_next_delay_delete->m_object);
    }
    v15 = vostok::math::float4x4::identity(&v108);
    vostok::render::renderer_context::set_w(this->m_context, v15);
    return;
  }
  v16 = m_context->m_targets->m_family[47].target.m_object;
  v17 = 0;
  if ( v16 )
  {
    v17 = (vostok::render::resource_manager *)m_context->m_targets->m_family[47].target.m_object;
    ++v16->m_reference_count;
    m_rt = v16->m_rt;
  }
  else
  {
    m_rt = 0;
  }
  v19 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  if ( *((ID3D11RenderTargetView **)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
       + 535) != m_rt )
  {
    *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 535) = m_rt;
    *((_BYTE *)v19 + 163) = 1;
  }
  if ( *((_DWORD *)v19 + 536) )
  {
    *((_DWORD *)v19 + 536) = 0;
    *((_BYTE *)v19 + 164) = 1;
  }
  if ( *((_DWORD *)v19 + 537) )
  {
    *((_DWORD *)v19 + 537) = 0;
    *((_BYTE *)v19 + 165) = 1;
  }
  if ( *((_DWORD *)v19 + 538) )
  {
    *((_DWORD *)v19 + 538) = 0;
    *((_BYTE *)v19 + 166) = 1;
  }
  if ( v17 )
  {
    v3 = v17->sh_created-- == 1;
    if ( v3 )
      vostok::render::resource_manager::release(
        v17,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (const char *)v17);
  }
  v20 = this->m_context->m_scene_view.m_object;
  m_flags = (vostok::render::environment_probe **)v20[4].vostok::resources::unmanaged_resource::m_flags.vostok::resources::unmanaged_resource::m_flags;
  v22 = *(vostok::render::environment_probe ***)&v20[4].m_inlined_in_fat;
  LOBYTE(model_probe_sqdist) = 0;
  probe_it = m_flags;
  v100 = v22;
  ___sort_PAPAUenvironment_probe_render_vostok__Usort_by_size_predicate__P___execute_stage_lights_23_UAEXXZ__stlp_std__YAXPAPAUenvironment_probe_render_vostok__0Usort_by_size_predicate__P___execute_stage_lights_23_UAEXXZ__Z(
    m_flags,
    v22,
    0);
  v23 = this->m_context;
  p_m_vp = &v23->m_vp;
  p_m_view_pos = (const vostok::math::float3 *)&v23->m_view_pos;
  memset(&m_dynamic_visuals, 0, sizeof(m_dynamic_visuals));
  m_scene = v23->m_scene;
  *(float *)&it = float_max_10;
  found_probe = 0;
  max_rad = 0.0;
  vostok::render::scene::select_models(m_scene, p_m_vp, &m_dynamic_visuals, p_m_view_pos, 1u, 0);
  it_d = (vostok::render::render_surface_instance **)m_dynamic_visuals._M_impl._M_start;
  for ( end_d = (vostok::render::render_surface_instance *const *)m_dynamic_visuals._M_impl._M_finish; it_d != end_d; ++it_d )
  {
    v26 = *it_d;
    m_render_surface = (*it_d)->m_render_surface;
    v28 = m_render_surface->m_materail_effects_instance.m_object;
    instance = *it_d;
    if ( !v28 || s_use_one_material_value )
      p_m_material_effects = s_nomaterial_material_effects[m_render_surface->m_vertex_input_type];
    else
      p_m_material_effects = &v28->m_material_effects;
    if ( p_m_material_effects->stage_enable[22] )
    {
      vostok::render::renderer_context::set_w(this->m_context, v26->m_transform);
      vostok::render::res_geometry::apply(m_render_surface->m_render_geometry.geom.m_object);
      if ( probe_it != v100 )
      {
        while ( 1 )
        {
          v30 = *probe_it;
          if ( *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
               + 288)
            && v30->m_occluded
            || !v30->m_texture.m_object
            || !v30->m_properties.enabled )
          {
            goto LABEL_73;
          }
          v26->m_parent->get_aabb(v26->m_parent, &bbox);
          vostok::math::aabb::modify((vostok::math::aabb *)v26->m_transform, v88);
          z_low = (vostok::render::speedtree_forest::tree_render_info *)LODWORD(v26->m_transform->c.z);
          *(_QWORD *)&visible_trees._M_impl._M_start = *(_QWORD *)&v26->m_transform->lines[3].x;
          v32 = (float)(bbox.max.y - bbox.min.y) * 0.5;
          visible_trees._M_impl._M_end_of_storage._M_data = z_low;
          if ( v32 <= (float)((float)(bbox.max.z - bbox.min.z) * 0.5) )
            v32 = (float)(bbox.max.z - bbox.min.z) * 0.5;
          *(float *)&particle_render_mode = (float)((float)(bbox.max.x - bbox.min.x) * 0.5) <= v32
                                          ? v32
                                          : (float)(bbox.max.x - bbox.min.x) * 0.5;
          if ( (float)((float)((float)((float)((float)(bbox.max.z - bbox.min.z) * 0.5)
                                     * (float)((float)(bbox.max.z - bbox.min.z) * 0.5))
                             + (float)((float)((float)(bbox.max.y - bbox.min.y) * 0.5)
                                     * (float)((float)(bbox.max.y - bbox.min.y) * 0.5)))
                     + (float)((float)((float)(bbox.max.x - bbox.min.x) * 0.5)
                             * (float)((float)(bbox.max.x - bbox.min.x) * 0.5))) <= 2.0 )
            break;
          if ( v30->m_properties.radius > max_rad )
          {
            max_rad = v30->m_properties.radius;
LABEL_72:
            found_probe = v30;
          }
LABEL_73:
          if ( ++probe_it == v100 )
            goto LABEL_74;
        }
        model_probe_sqdist = sqrtf(
                               (float)((float)((float)(*(float *)&visible_trees._M_impl._M_start
                                                     - v30->m_properties.location.x)
                                             * (float)(*(float *)&visible_trees._M_impl._M_start
                                                     - v30->m_properties.location.x))
                                     + (float)((float)(*(float *)&visible_trees._M_impl._M_end_of_storage._M_data
                                                     - v30->m_properties.location.z)
                                             * (float)(*(float *)&visible_trees._M_impl._M_end_of_storage._M_data
                                                     - v30->m_properties.location.z)))
                             + (float)((float)(*(float *)&visible_trees._M_impl._M_finish - v30->m_properties.location.y)
                                     * (float)(*(float *)&visible_trees._M_impl._M_finish - v30->m_properties.location.y)));
        if ( (float)((float)((float)(v30->m_properties.transform.i.x * v30->m_properties.transform.i.x)
                           + (float)(v30->m_properties.transform.i.z * v30->m_properties.transform.i.z))
                   + (float)(v30->m_properties.transform.i.y * v30->m_properties.transform.i.y)) == 0.0
          || (float)((float)((float)(v30->m_properties.transform.j.y * v30->m_properties.transform.j.y)
                           + (float)(v30->m_properties.transform.j.z * v30->m_properties.transform.j.z))
                   + (float)(v30->m_properties.transform.j.x * v30->m_properties.transform.j.x)) == 0.0
          || (float)((float)((float)(v30->m_properties.transform.k.x * v30->m_properties.transform.k.x)
                           + (float)(v30->m_properties.transform.k.y * v30->m_properties.transform.k.y))
                   + (float)(v30->m_properties.transform.k.z * v30->m_properties.transform.k.z)) == 0.0 )
        {
          if ( !vostok::core::g_log_filter_tree
            || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "render_pc_dx11:", error) )
          {
            v35 = vostok::core::g_log_callback;
            v108.i.x = 0.0;
            if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
              `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
                (const boost::detail::function::function_buffer *)&v108.lines[0].elements[2],
                (boost::detail::function::function_buffer *)&v108.lines[0].elements[2],
                destroy_functor_tag);
            if ( v35 )
            {
              LODWORD(v108.i.z) = v35;
              LODWORD(v108.i.x) = (char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                + 1;
            }
            else
            {
              v108.i.x = 0.0;
            }
            object.m_object = (vostok::render::light *)((unsigned int)object.m_object | 1);
            vostok::logging::append(
              (const boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)&v108,
              (void *const)vostok::core::g_log_flags,
              &vostok::core::g_log_format,
              (const char *)&stru_9649F4.m_desc_3d.MipLevels,
              0x82Au,
              (const char *)&stru_9649F4.m_bind.m_Closure.m_pFunction,
              "render_pc_dx11:",
              error,
              (const char *)&stru_9649F4.m_rescale_min.elements[1]);
          }
          if ( ((int)object.m_object & 1) != 0 )
          {
            object.m_object = (vostok::render::light *)((unsigned int)object.m_object & 0xFFFFFFFE);
            boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
              v34,
              (int *)&v108);
          }
        }
        else
        {
          vostok::math::float4x4::get_scale(v33, (float *)v107, &v30->m_properties.transform.i.x);
          v26 = instance;
        }
        if ( (float)((float)(v30->m_properties.radius * 0.44999999) + *(float *)&particle_render_mode) < model_probe_sqdist
          || *(float *)&it <= model_probe_sqdist )
        {
          goto LABEL_73;
        }
        *(float *)&it = model_probe_sqdist;
        goto LABEL_72;
      }
LABEL_74:
      if ( found_probe )
        vostok::render::stage_lights::render_model_probe_lighting(found_probe, this, v26, *(float *)&v88);
      v36 = this->m_context->m_scene->m_lights.m_object;
      v37 = (vostok::render::vector<vostok::render::light_data> *)v36->m_sun.m_object;
      p_m_sun = &v36->m_sun;
      if ( !v37
        || !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
        || HIBYTE(v37[19]._M_impl._M_end_of_storage._M_data) )
      {
        model_probe_sqdist = 0.0;
        vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
          (vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v37,
          (const vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&model_probe_sqdist,
          p_m_sun);
        v39 = (vostok::render::light *)LODWORD(model_probe_sqdist);
        if ( model_probe_sqdist != 0.0 )
        {
          v3 = (*(_DWORD *)LODWORD(model_probe_sqdist))-- == 1;
          if ( v3 )
          {
            v40 = vostok::render::g_allocator.m_object;
            vostok::render::light::~light((vostok::render::light *)v37, (int)v39);
            BYTE2(v40->m_children_resources.m_lock) = 0;
            vostok_mspace_free((void *)HIDWORD(v40->m_reconstruction_info_actuality_tick), v39);
          }
          if ( v39->m_enabled )
            vostok::render::stage_lights::render_model_lighting(
              (vostok::render::stage_lights *)instance,
              this,
              instance,
              v39);
        }
      }
      for ( j = e_lights->_M_impl._M_start; j != e_lights->_M_impl._M_finish; ++j )
      {
        v42 = 0;
        if ( j->light.m_object )
        {
          v42 = j->light.m_object;
          ++j->light.m_object->m_reference_count;
        }
        if ( (!*((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
               + 288)
           || !v42->m_occluded)
          && v42->m_enabled )
        {
          vostok::render::stage_lights::render_model_lighting((vostok::render::stage_lights *)v37, this, instance, v42);
        }
        v3 = v42->m_reference_count-- == 1;
        if ( v3 )
        {
          v43 = vostok::render::g_allocator.m_object;
          vostok::render::light::~light((vostok::render::light *)v37, (int)v42);
          BYTE2(v43->m_children_resources.m_lock) = 0;
          vostok_mspace_free((void *)HIDWORD(v43->m_reconstruction_info_actuality_tick), v42);
        }
        v37 = (vostok::render::vector<vostok::render::light_data> *)e_lights;
      }
    }
  }
  if ( *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
       + 261)
    && this->m_context->m_scene->m_speedtree_forest )
  {
    memset(&visible_trees, 0, sizeof(visible_trees));
    vostok::render::speedtree_forest::get_visible_tree_components(
      this->m_context,
      (const vostok::math::float3 *)&this->m_context->m_v_inverted.lines[3],
      this->m_context->m_scene->m_speedtree_forest,
      &visible_trees,
      (vostok::render::vector<vostok::render::speedtree_forest::tree_render_info> *)v88);
    M_start = visible_trees._M_impl._M_start;
    M_finish = visible_trees._M_impl._M_finish;
    if ( visible_trees._M_impl._M_start != visible_trees._M_impl._M_finish )
    {
      p_tree_component = &visible_trees._M_impl._M_start->tree_component;
      do
      {
        v47 = vostok::math::float4x4::identity(&v110);
        vostok::render::renderer_context::set_w(this->m_context, v47);
        v48 = (*p_tree_component)->m_materail_effects_instance.m_object;
        if ( v48 )
          v49 = &v48->m_material_effects;
        else
          v49 = s_nomaterial_material_effects[(*p_tree_component)->get_vertex_input_type(*p_tree_component)];
        if ( v49->stage_enable[22] )
        {
          v50 = (*p_tree_component)->m_materail_effects_instance.m_object;
          v51 = v50
              ? &v50->m_material_effects
              : s_nomaterial_material_effects[(*p_tree_component)->get_vertex_input_type(*p_tree_component)];
          if ( v51->m_effects[22].m_object )
          {
            v52 = vostok::render::lights_db::get_sun(
                    (vostok::render::lights_db *)this->m_context,
                    (const vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)this->m_context->m_scene->m_lights.m_object,
                    (const vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&end_d)->m_object;
            vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>((vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&end_d);
            if ( v52 && v52->m_enabled )
              vostok::render::stage_lights::render_speedtree_lighting(
                this,
                this,
                (const vostok::render::lod_entry *)*(p_tree_component - 3),
                (vostok::render::speedtree_forest *)*(p_tree_component - 2),
                (const SpeedTree::SInstanceLod *)*(p_tree_component - 1),
                *p_tree_component,
                v52);
            for ( k = e_lights->_M_impl._M_start; k != e_lights->_M_impl._M_finish; ++k )
              vostok::render::stage_lights::render_speedtree_lighting(
                this,
                this,
                (const vostok::render::lod_entry *)*(p_tree_component - 3),
                (vostok::render::speedtree_forest *)*(p_tree_component - 2),
                (const SpeedTree::SInstanceLod *)*(p_tree_component - 1),
                *p_tree_component,
                k->light.m_object);
          }
        }
        p_tree_component += 4;
      }
      while ( p_tree_component - 3 != (vostok::render::speedtree_tree_component **)M_finish );
    }
    if ( M_start )
    {
      m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
      BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
      vostok_mspace_free(m_reconstruction_info_actuality_tick_high, M_start);
    }
  }
  if ( !*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
        + 49) )
    goto LABEL_118;
  v55 = this->m_context;
  v56 = v55->m_scene->m_particle_world.m_object;
  if ( !v56 )
  {
    v57 = vostok::math::float4x4::identity(&v110);
    vostok::render::renderer_context::set_w(v55, v57);
LABEL_118:
    v58 = m_dynamic_visuals._M_impl._M_start;
    if ( m_dynamic_visuals._M_impl._M_start )
    {
      v59 = vostok::render::g_allocator.m_object;
      BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
      vostok_mspace_free((void *)HIDWORD(v59->m_reconstruction_info_actuality_tick), v58);
    }
    return;
  }
  y = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y;
  LODWORD(model_probe_sqdist) = 1;
  (*(void (__stdcall **)(int, float *, D3D11_VIEWPORT *))(*(_DWORD *)y + 380))(y, &model_probe_sqdist, &orig_viewport);
  v61 = this->m_context;
  tmp_viewport.TopLeftX = 0.0;
  tmp_viewport.TopLeftY = 0.0;
  v62 = v61->m_targets->m_family[50].target.m_object;
  v63 = 0;
  if ( v62 )
  {
    v63 = v62;
    ++v62->m_reference_count;
  }
  tmp_viewport.Width = (float)v63->m_width;
  v3 = v63->m_reference_count-- == 1;
  if ( v3 )
    vostok::render::resource_manager::release(
      (vostok::render::resource_manager *)v63,
      (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
      (const char *)v63);
  v64 = this->m_context->m_targets->m_family[50].target.m_object;
  v65 = 0;
  if ( v64 )
  {
    v65 = (vostok::render::resource_manager *)this->m_context->m_targets->m_family[50].target.m_object;
    ++v64->m_reference_count;
  }
  tmp_viewport.Height = (float)LODWORD(v65->m_num_bytes_of_texture_video_memory);
  v3 = v65->sh_created-- == 1;
  if ( v3 )
    vostok::render::resource_manager::release(
      v65,
      (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
      (const char *)v65);
  tmp_viewport.MinDepth = 0.0;
  LODWORD(tmp_viewport.MaxDepth) = clear_value;
  (*(void (__stdcall **)(int, int, D3D11_VIEWPORT *))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                    + 176))(
    `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
    1,
    &tmp_viewport);
  v66 = this->m_context->m_targets->m_family[50].target.m_object;
  v67 = 0;
  if ( v66 )
  {
    v67 = (ID3D11RenderTargetView *)this->m_context->m_targets->m_family[50].target.m_object;
    ++v66->m_reference_count;
  }
  vostok::render::backend::set_render_targets(
    v67,
    0,
    0,
    0,
    (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
  if ( v67 )
  {
    v3 = v67->lpVtbl-- == (ID3D11RenderTargetView_vtbl *)1;
    if ( v3 )
      vostok::render::resource_manager::release(
        v68,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (const char *)v67);
  }
  emitters._M_impl._M_start = 0;
  emitters._M_impl._M_finish = 0;
  emitters._M_impl._M_end_of_storage._M_data = 0;
  emitters._M_impl._M_end_of_storage.m_allocator = (vostok::memory::base_allocator *)vostok::render::g_allocator.m_object;
  v56->get_render_emitter_instances(v56, &this->m_context->m_vp, &emitters);
  v69 = (vostok::particle::render_particle_emitter_instance *const *)emitters._M_impl._M_start;
  for ( it = (vostok::particle::render_particle_emitter_instance *const *)emitters._M_impl._M_start;
        v69 != (vostok::particle::render_particle_emitter_instance *const *)emitters._M_impl._M_finish;
        it = v69 )
  {
    v70 = *v69;
    set_aabb = (*v69)[275].__vftable[1].set_aabb;
    v72 = 0.0;
    if ( set_aabb )
    {
      do
      {
        set_aabb = (void (__thiscall *)(vostok::particle::render_particle_emitter_instance *, const vostok::math::aabb *))*((_DWORD *)set_aabb + 32);
        ++LODWORD(v72);
      }
      while ( set_aabb );
      model_probe_sqdist = v72;
      if ( v72 != 0.0 )
      {
        v73 = probe_it;
        v74 = v100;
        particle_render_mode = (vostok::particle::enum_particle_render_mode)this->m_context->m_scene_view.m_object[4].m_memory_usage_self.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::type;
        if ( probe_it != v100 )
        {
          do
          {
            v75 = *v73;
            if ( !*((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
                  + 288)
              || !v75->m_occluded )
            {
              if ( v75->m_texture.m_object )
              {
                if ( v75->m_properties.enabled )
                {
                  v107[0] = *(_QWORD *)&v70[230].__vftable;
                  v107[1] = *(_QWORD *)&v70[232].__vftable;
                  v107[2] = *(_QWORD *)&v70[234].__vftable;
                  vostok::math::aabb::modify((vostok::math::aabb *)&v70[236], v88);
                  if ( v75->m_properties.radius > max_rad )
                  {
                    max_rad = v75->m_properties.radius;
                    found_probe = v75;
                  }
                }
              }
            }
            ++v73;
          }
          while ( v73 != v74 );
          v72 = model_probe_sqdist;
          probe_it = v73;
        }
        if ( found_probe )
          vostok::render::stage_lights::render_particle_probe_lighting(
            this,
            found_probe,
            (vostok::render::render_particle_emitter_instance *)v70,
            (vostok::render::render_particle_emitter_instance *)LODWORD(v72));
        v76 = &this->m_context->m_scene->m_lights.m_object->m_sun;
        if ( v76->m_object
          && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
          && !v76->m_object->m_enabled )
        {
          object.m_object = 0;
          vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
            v76,
            &object,
            0);
        }
        else
        {
          object.m_object = 0;
          vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
            &object,
            &object,
            v76);
        }
        v78 = object.m_object;
        if ( !object.m_object )
          goto LABEL_158;
        v3 = object.m_object->m_reference_count-- == 1;
        if ( v3 )
        {
          end_d = (vostok::render::render_surface_instance *const *)v78;
          vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::light const>(
            (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
            v77,
            (const vostok::render::light **)&end_d);
        }
        if ( v78->m_enabled )
        {
          v79 = this;
          vostok::render::stage_lights::render_particle_lighting(
            (vostok::render::stage_lights *)v77,
            this,
            (vostok::render::render_particle_emitter_instance *)v70,
            v78,
            (vostok::render::render_particle_emitter_instance *)LODWORD(v72));
        }
        else
        {
LABEL_158:
          v79 = this;
        }
        if ( *(float *)&particle_render_mode == 0.0
          && vostok::render::render_particle_emitter_instance::get_material_effects((vostok::render::render_particle_emitter_instance *)v70)->stage_enable[22] )
        {
          for ( m = e_lights->_M_impl._M_start; m != e_lights->_M_impl._M_finish; ++m )
          {
            if ( m->light.m_object != v78 )
              vostok::render::stage_lights::render_particle_lighting(
                (vostok::render::stage_lights *)LODWORD(model_probe_sqdist),
                v79,
                (vostok::render::render_particle_emitter_instance *)v70,
                m->light.m_object,
                (vostok::render::render_particle_emitter_instance *)LODWORD(model_probe_sqdist));
          }
        }
      }
    }
    v69 = it + 1;
  }
  (*(void (__stdcall **)(int, int, D3D11_VIEWPORT *))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                    + 176))(
    `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
    1,
    &orig_viewport);
  if ( emitters._M_impl._M_start )
    emitters._M_impl._M_end_of_storage.m_allocator->call_free(
      emitters._M_impl._M_end_of_storage.m_allocator,
      emitters._M_impl._M_start);
  v81 = m_dynamic_visuals._M_impl._M_start;
  if ( m_dynamic_visuals._M_impl._M_start )
  {
    v82 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v82, v81);
  }
  v83 = vostok::math::float4x4::identity(&v110);
  vostok::render::renderer_context::set_w(this->m_context, v83);
  v84 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  vostok::render::backend::reset_render_targets(
    v85,
    (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
  v86 = *((_DWORD *)v84 + 547);
  v3 = *((_DWORD *)v84 + 539) == v86;
  *((_DWORD *)v84 + 539) = v86;
  *((_BYTE *)v84 + 167) |= !v3;
}
