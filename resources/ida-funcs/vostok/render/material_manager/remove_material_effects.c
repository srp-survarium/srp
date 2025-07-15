void __thiscall vostok::render::material_manager::remove_material_effects(
        vostok::render::material_manager *this,
        vostok::render::material_manager *in_material_effects_instance,
        const vostok::resources::resource_ptr<vostok::render::material_effects_instance,vostok::resources::unmanaged_intrusive_base> *in_material_effects_instancea)
{
  vostok::render::material_effects_instance *M_finish; // ebp
  vostok::render::material_effects_instance *M_start; // esi
  vostok::render::material_effects_entry *p_dof_focus_region; // edi
  vostok::render::material_effects_instance *v6; // eax

  M_finish = (vostok::render::material_effects_instance *)in_material_effects_instance->m_material_effects._M_impl._M_finish;
  M_start = (vostok::render::material_effects_instance *)in_material_effects_instance->m_material_effects._M_impl._M_start;
  if ( (vostok::render::material_effects_instance *)in_material_effects_instance->m_material_effects._M_impl._M_start != M_finish )
  {
    p_dof_focus_region = (vostok::render::material_effects_entry *)&M_start->m_material_effects.m_post_process_stage_parameters.dof_focus_region;
    do
    {
      if ( M_start->~vostok::resources::resource_base == (void (__thiscall *)(struct vostok::resources::resource_base *))in_material_effects_instancea->m_object )
      {
        v6 = (vostok::render::material_effects_instance *)in_material_effects_instance->m_material_effects._M_impl._M_finish;
        if ( p_dof_focus_region != (vostok::render::material_effects_entry *)v6 )
          stlp_std::priv::__copy<vostok::render::material_effects_entry *,vostok::render::material_effects_entry *,int>(
            p_dof_focus_region,
            (vostok::render::material_effects_entry *)v6,
            (vostok::render::material_effects_entry *)M_start);
        --in_material_effects_instance->m_material_effects._M_impl._M_finish;
      }
      M_start = (vostok::render::material_effects_instance *)((char *)M_start + 280);
      ++p_dof_focus_region;
    }
    while ( M_start != M_finish );
  }
}
