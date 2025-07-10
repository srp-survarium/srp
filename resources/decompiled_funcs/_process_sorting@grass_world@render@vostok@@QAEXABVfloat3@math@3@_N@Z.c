void __userpurge vostok::render::grass_world::process_sorting(
        vostok::render::grass_world *this@<ecx>,
        int a2@<eax>,
        vostok::render::sort_grass_patch_predicate *viewer_position,
        bool sort_instances)
{
  vostok::render::grass_patch **v5; // esi
  vostok::render::grass_patch **v6; // ebx
  unsigned int i; // edi

  if ( s_use_grass_patches_sorting_value )
    stlp_std::sort<vostok::render::grass_patch * *,vostok::render::sort_grass_patch_predicate>(
      *(vostok::render::grass_patch ***)(a2 + 300),
      *(vostok::render::grass_patch ***)(a2 + 304),
      *viewer_position);
  if ( s_use_grass_instances_sorting_value && sort_instances )
  {
    v5 = *(vostok::render::grass_patch ***)(a2 + 300);
    v6 = *(vostok::render::grass_patch ***)(a2 + 304);
    for ( i = 0; v5 != v6; ++i )
    {
      if ( i > 5 )
        break;
      vostok::render::grass_patch::sort_instances(*v5++, &viewer_position->m_view_pos);
    }
  }
}
