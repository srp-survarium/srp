bool __usercall vostok::render::remove_inappropriate_models_predicate::operator()@<al>(
        vostok::render::render_surface_instance *in_model@<esi>,
        vostok::render::render_surface *a2@<ecx>)
{
  vostok::render::material_effects *material_effects; // eax
  vostok::render::render_surface_instance *v3; // ecx
  bool result; // al

  material_effects = vostok::render::render_surface::get_material_effects(a2, (int)in_model->m_render_surface);
  if ( !material_effects->has_local_reflections )
    return 1;
  if ( !material_effects->m_effects[16].m_object )
    return 1;
  result = vostok::render::render_surface_instance::is_occluded(v3, (int)in_model);
  if ( result )
    return 1;
  return result;
}
