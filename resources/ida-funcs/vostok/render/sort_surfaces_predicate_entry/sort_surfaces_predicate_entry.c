void __usercall vostok::render::sort_surfaces_predicate_entry::sort_surfaces_predicate_entry(
        vostok::render::sort_surfaces_predicate_entry *this@<ecx>,
        const vostok::render::sort_surfaces_predicate_entry *__that@<eax>)
{
  vostok::intrusive_ptr<vostok::render::res_xs<vostok::render::ps_data>,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_xs<vostok::render::ps_data>,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
    &this->ps_ref,
    &__that->ps_ref);
  this->instance = __that->instance;
  this->vs = __that->vs;
  this->ps = __that->ps;
  this->distance = __that->distance;
  this->two_sided = __that->two_sided;
  this->alpha_test = __that->alpha_test;
}


void __userpurge vostok::render::sort_surfaces_predicate_entry::sort_surfaces_predicate_entry(
        vostok::render::sort_surfaces_predicate_entry *this@<esi>,
        vostok::render::render_surface_instance *in_instance@<eax>,
        vostok::render::render_surface *a3@<ecx>,
        const unsigned int stage_type,
        char in_tech_index,
        bool in_with_lods)
{
  vostok::render::render_surface_instance *v7; // ecx
  vostok::render::material_effects *material_effects; // ebx
  int shader_lod_index; // ecx
  unsigned int v10; // eax
  int v11; // ecx

  this->ps_ref.m_object = 0;
  this->instance = in_instance;
  material_effects = vostok::render::render_surface::get_material_effects(a3, (int)in_instance->m_render_surface);
  if ( in_tech_index )
    shader_lod_index = vostok::render::render_surface_instance::get_shader_lod_index(v7, (int)in_instance);
  else
    shader_lod_index = 0;
  v10 = (unsigned int)&material_effects->m_effects[stage_type];
  v11 = 4 * shader_lod_index;
  this->vs = *(const void **)(*(_DWORD *)(*(_DWORD *)(**(_DWORD **)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)v10 + 22052) + v11)
                                                                  + 8)
                                                    + 8)
                                        + 4)
                            + 8);
  this->ps = *(const void **)(*(_DWORD *)(*(_DWORD *)(**(_DWORD **)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)v10 + 22052) + v11)
                                                                  + 8)
                                                    + 16)
                                        + 4)
                            + 8);
  vostok::intrusive_ptr<vostok::render::res_xs<vostok::render::ps_data>,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    (const vostok::intrusive_ptr<vostok::render::res_xs<vostok::render::ps_data>,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(**(_DWORD **)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)v10 + 22052) + v11) + 8) + 16),
    &this->ps_ref);
  this->distance = this->instance->m_distance_to_viewer;
  this->two_sided = material_effects->two_sided;
  this->alpha_test = material_effects->is_use_alpha_test;
}
