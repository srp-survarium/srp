void __userpurge vostok::render::renderer::sort_models(
        vostok::render::vector<vostok::render::render_surface_instance *> *instances@<edi>,
        vostok::render::renderer *this,
        unsigned int stage_type,
        const unsigned int tech_index)
{
  if ( s_sorting_value )
    stlp_std::sort<vostok::render::render_surface_instance * *,vostok::render::sort_by_vs_predicate>(
      (vostok::render::render_surface_instance **)instances->_M_impl._M_start,
      (vostok::render::render_surface_instance **)instances->_M_impl._M_finish,
      (vostok::render::sort_by_ps_predicate)__PAIR64__(stage_type, (unsigned int)this));
  if ( s_sorting3_value )
    stlp_std::sort<vostok::render::render_surface_instance * *,vostok::render::sort_by_texture_predicate>(
      (vostok::render::render_surface_instance **)instances->_M_impl._M_start,
      (vostok::render::render_surface_instance **)instances->_M_impl._M_finish,
      (vostok::render::sort_by_texture_predicate)__PAIR64__(stage_type, (unsigned int)this));
}
