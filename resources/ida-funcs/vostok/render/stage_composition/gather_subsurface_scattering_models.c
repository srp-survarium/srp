void __userpurge vostok::render::stage_composition::gather_subsurface_scattering_models(
        vostok::render::stage_composition *this@<ecx>,
        int a2@<eax>,
        vostok::buffer_vector<vostok::render::render_surface_instance *> *result_models)
{
  int v3; // eax
  vostok::render::render_surface_instance **v4; // ebx
  vostok::render::render_surface_instance **i; // edi
  vostok::render::render_surface_instance *v6; // esi
  vostok::render::render_surface_instance *v7; // [esp+10h] [ebp-4h] BYREF

  v3 = *(_DWORD *)(*(_DWORD *)(a2 + 4) + 16268);
  v4 = *(vostok::render::render_surface_instance ***)(v3 + 17576);
  for ( i = *(vostok::render::render_surface_instance ***)(v3 + 17572); i != v4; ++i )
  {
    v6 = *i;
    if ( vostok::render::render_surface::get_material_effects(
           (vostok::render::render_surface *)this,
           (int)(*i)->m_render_surface)->use_subsurface_scattering )
    {
      v7 = v6;
      vostok::buffer_vector<vostok::render::render_surface_instance *>::push_back(
        (vostok::buffer_vector<vostok::render::render_surface_instance *> *)this,
        (int)result_models,
        &v7);
    }
  }
}
