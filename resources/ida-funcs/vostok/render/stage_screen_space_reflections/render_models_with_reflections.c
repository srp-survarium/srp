void __userpurge vostok::render::stage_screen_space_reflections::render_models_with_reflections(
        const vostok::buffer_vector<vostok::render::render_surface_instance *> *reflection_models@<eax>,
        vostok::render::stage_screen_space_reflections *this,
        bool foreground)
{
  vostok::render::render_surface_instance *m_begin; // ecx
  bool i; // zf
  vostok::render::res_texture *m_object; // ebx
  vostok::render::render_surface *v6; // ecx
  vostok::render::res_effect *v7; // eax
  vostok::render::res_pass *v8; // ecx
  vostok::render::res_pass *v9; // edi
  vostok::render::res_pass *v10; // eax
  vostok::render::res_pass *v11; // esi
  _DWORD *m_reference_count; // eax
  vostok::render::effect_manager *v13; // ecx
  vostok::math::float3 v14; // [esp-8h] [ebp-20h]
  vostok::render::effect_manager *v15; // [esp-4h] [ebp-1Ch]
  vostok::render::render_surface_instance *v16; // [esp+10h] [ebp-8h]
  vostok::render::render_surface_instance **m_end; // [esp+14h] [ebp-4h]

  m_begin = (vostok::render::render_surface_instance *)reflection_models->m_begin;
  m_end = reflection_models->m_end;
  for ( i = reflection_models->m_begin == m_end;
        ;
        i = &v16->m_override_normal_texture == (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)m_end )
  {
    v16 = m_begin;
    if ( i )
      break;
    m_object = m_begin->m_override_diffuse_texture.m_object;
    if ( vostok::render::render_surface_instance::is_foreground(
           m_begin,
           (int)m_begin->m_override_diffuse_texture.m_object) == foreground )
    {
      v7 = vostok::render::render_surface::get_material_effects(v6, m_object->loaded_num_mips)->m_effects[16].m_object;
      v9 = 0;
      v7->m_cur_technique = 0;
      v10 = (vostok::render::res_pass *)v7->m_techniques.m_begin->m_object;
      v11 = 0;
      if ( v10 )
      {
        v11 = v10;
        ++v10->m_reference_count;
      }
      m_reference_count = (_DWORD *)v11->m_vs.m_object->m_reference_count;
      if ( m_reference_count )
      {
        v9 = (vostok::render::res_pass *)v11->m_vs.m_object->m_reference_count;
        ++*m_reference_count;
      }
      vostok::render::res_pass::apply(v8, (int)v9);
      if ( v9 )
      {
        i = v9->m_reference_count-- == 1;
        if ( i )
          vostok::render::effect_manager::delete_pass(
            v13,
            (int)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
            v9);
      }
      i = v11->m_reference_count-- == 1;
      if ( i )
      {
        vostok::render::resource_intrusive_base::destroy<vostok::render::res_shader_technique>(v11);
        v13 = v15;
      }
      LODWORD(v14.y) = m_object;
      LODWORD(v14.x) = this;
      vostok::render::stage_screen_space_reflections::render_forward_model(
        (vostok::render::stage_screen_space_reflections *)v13,
        v14);
    }
    m_begin = (vostok::render::render_surface_instance *)&v16->m_override_normal_texture;
  }
}
