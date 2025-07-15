void __userpurge vostok::render::stage_forward::render_forward_models(
        vostok::buffer_vector<vostok::render::render_surface_instance *> *dynamic_visuals@<eax>,
        vostok::render::res_input_layout *m_object@<ecx>,
        float z@<esi>,
        vostok::render::stage_forward *this,
        const unsigned int pass_index,
        bool foreground)
{
  int *m_begin; // ebx
  vostok::render::render_surface_instance **m_end; // eax
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v8; // eax
  vostok::render::render_target *v9; // eax
  int v10; // edi
  vostok::render::material_effects *material_effects; // eax
  bool i; // zf
  int *m_reference_count; // eax
  vostok::render::material_effects_instance *v14; // ecx
  vostok::render::res_effect *v15; // eax
  vostok::render::res_pass *v16; // ecx
  vostok::render::res_pass *v17; // eax
  _DWORD *v18; // eax
  vostok::render::res_pass *v19; // ebx
  vostok::render::effect_manager *v20; // ecx
  vostok::render::enum_vertex_input_type v21; // [esp-4h] [ebp-24h]
  vostok::render::effect_manager *v22; // [esp-4h] [ebp-24h]
  vostok::render::render_target *rt; // [esp+Ch] [ebp-14h] BYREF
  int *v24; // [esp+10h] [ebp-10h]
  int *v25; // [esp+14h] [ebp-Ch]
  int *v26; // [esp+18h] [ebp-8h]
  vostok::render::render_surface_instance *v27; // [esp+1Ch] [ebp-4h]

  m_begin = (int *)dynamic_visuals->m_begin;
  m_end = dynamic_visuals->m_end;
  v24 = m_begin;
  v25 = (int *)m_end;
  if ( m_begin != (int *)m_end )
  {
    v8 = vostok::render::renderer_context::get_rt(
           this->m_context,
           rt_generic_0,
           (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&rt);
    z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
    vostok::render::backend::set_render_targets(
      (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      v8->m_object,
      0,
      0,
      0);
    v9 = rt;
    if ( rt )
    {
      --rt->m_reference_count;
      if ( !v9->m_reference_count )
      {
        vostok::render::resource_manager::release(rt, vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
        z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
      }
    }
    m_object = *(vostok::render::res_input_layout **)(LODWORD(z) + 7440);
    i = *(_DWORD *)(LODWORD(z) + 7384) == (_DWORD)m_object;
    *(_DWORD *)(LODWORD(z) + 7384) = m_object;
    *(_BYTE *)(LODWORD(z) + 117) |= !i;
  }
  while ( m_begin != v25 )
  {
    v10 = *m_begin;
    if ( vostok::render::render_surface_instance::is_foreground(
           (vostok::render::render_surface_instance *)m_object,
           *m_begin) != foreground )
      goto LABEL_28;
    material_effects = vostok::render::render_surface::get_material_effects(
                         (vostok::render::render_surface *)m_object,
                         *(_DWORD *)(v10 + 16));
    m_object = (vostok::render::res_input_layout *)material_effects->m_effects[16].m_object;
    if ( m_object
      && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      if ( !pass_index && material_effects->is_forward_after_fog
        || pass_index == 1 && !material_effects->is_forward_after_fog )
      {
        goto LABEL_28;
      }
      m_object[1102].m_declaration = 0;
      vostok::render::res_effect::apply_pass((vostok::render::res_effect *)m_object, (int)m_object);
      vostok::render::stage_forward::render_forward_model(
        (vostok::render::render_surface_instance *)v10,
        (int)m_begin,
        v10,
        SLODWORD(z),
        this);
    }
    m_object = *(vostok::render::res_input_layout **)(*(_DWORD *)(v10 + 20) + 460);
    v27 = *(vostok::render::render_surface_instance **)(*(_DWORD *)(v10 + 20) + 464);
    for ( i = m_object == (vostok::render::res_input_layout *)v27; ; i = &rt->m_name == (vostok::shared_string *)v27 )
    {
      rt = (vostok::render::render_target *)m_object;
      if ( i )
        break;
      m_reference_count = (int *)m_object->m_reference_count;
      v21 = *(_DWORD *)(*(_DWORD *)(v10 + 16) + 148);
      v14 = *(vostok::render::material_effects_instance **)(m_object->m_reference_count + 2316);
      v26 = m_reference_count;
      v15 = vostok::render::material_effects_instance::get_material_effects(v14, v21)->m_effects[16].m_object;
      z = 0.0;
      if ( v15 )
      {
        v15->m_cur_technique = 0;
        v17 = (vostok::render::res_pass *)v15->m_techniques.m_begin->m_object;
        if ( *(float *)&v17 != 0.0 )
        {
          z = *(float *)&v17;
          ++v17->m_reference_count;
        }
        v18 = **(_DWORD ***)(LODWORD(z) + 8);
        v19 = 0;
        if ( v18 )
        {
          v19 = **(vostok::render::res_pass ***)(LODWORD(z) + 8);
          ++*v18;
        }
        vostok::render::res_pass::apply(v16, (int)v19);
        if ( v19 )
        {
          i = v19->m_reference_count-- == 1;
          if ( i )
            vostok::render::effect_manager::delete_pass(
              v20,
              (int)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
              v19);
        }
        i = (*(_DWORD *)LODWORD(z))-- == 1;
        if ( i )
        {
          vostok::render::resource_intrusive_base::destroy<vostok::render::res_shader_technique>((vostok::render::res_pass *)LODWORD(z));
          v20 = v22;
        }
        vostok::render::additional_material::set_parameters((vostok::render::additional_material *)v20, v26);
        vostok::render::stage_forward::render_forward_model(
          (vostok::render::render_surface_instance *)v10,
          (int)v19,
          v10,
          SLODWORD(z),
          this);
        m_begin = v24;
      }
      m_object = (vostok::render::res_input_layout *)&rt->m_name;
    }
LABEL_28:
    v24 = ++m_begin;
  }
}
