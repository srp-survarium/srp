void __thiscall vostok::render::grass_render_model::set_children(
        vostok::render::grass_render_model *this,
        vostok::render::render_surface **children,
        unsigned __int8 count,
        vostok::render::model_lods_descriptor *lods)
{
  unsigned int i; // ecx
  int v6; // eax

  vostok::render::render_model::set_children(this, children, count, lods);
  for ( i = 0; i < 3; ++i )
  {
    if ( !lods->m_lod_surfaces_count[i] )
      continue;
    v6 = *lods->m_lod_surfaces[i];
    if ( i )
    {
      if ( i != 1 )
        goto LABEL_8;
    }
    else
    {
      this->m_l0 = (vostok::render::grass_render_surface *)children[v6];
    }
    this->m_l1 = (vostok::render::grass_render_surface *)children[v6];
LABEL_8:
    this->m_l2 = (vostok::render::grass_render_surface *)children[v6];
  }
  if ( !this->m_l0 )
    this->m_l0 = (vostok::render::grass_render_surface *)*children;
}
