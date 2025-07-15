void __usercall vostok::render::renderer::fill_opaque_models(vostok::render::renderer *this@<ecx>, int a2@<eax>)
{
  _DWORD *v2; // eax
  vostok::buffer_vector<vostok::render::render_surface_instance *> *v3; // ecx
  int v4; // esi
  vostok::render::render_surface_instance **v5; // ebx
  vostok::render::render_surface_instance **i; // edi

  v2 = *(_DWORD **)(*(_DWORD *)(a2 + 480) + 16268);
  v3 = (vostok::buffer_vector<vostok::render::render_surface_instance *> *)(v2 + 2342);
  v4 = (int)(v2 + 4393);
  v2[4394] = v2[4393];
  v5 = (vostok::render::render_surface_instance **)v2[2343];
  for ( i = (vostok::render::render_surface_instance **)v2[2342]; i != v5; ++i )
  {
    if ( vostok::render::render_surface::get_material_effects(
           (vostok::render::render_surface *)v3,
           (int)(*i)->m_render_surface)->m_effects[1].m_object )
      vostok::buffer_vector<vostok::render::render_surface_instance *>::push_back(v3, v4, i);
  }
}
