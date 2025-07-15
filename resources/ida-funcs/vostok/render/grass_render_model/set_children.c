void __thiscall vostok::render::grass_render_model::set_children(
        vostok::render::grass_render_model *this,
        vostok::render::render_surface **children,
        unsigned __int8 count,
        vostok::render::model_lods_descriptor *lods)
{
  _DWORD *v4; // ecx
  unsigned int i; // edx
  int v6; // esi

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
      v4[78] = children[v6];
    }
    v4[79] = children[v6];
LABEL_8:
    v4[80] = children[v6];
  }
  if ( !v4[78] )
    v4[78] = *children;
}
