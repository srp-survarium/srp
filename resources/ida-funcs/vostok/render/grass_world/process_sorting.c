void __thiscall vostok::render::grass_world::process_sorting(
        vostok::render::grass_world *this,
        const vostok::math::float3 *viewer_position,
        vostok::render::grass_patch *sort_instances,
        char a4)
{
  float y; // esi
  float z; // ebx
  unsigned int i; // edi
  vostok::render::sort_grass_patch_predicate v7; // [esp-Ch] [ebp-1Ch]

  if ( s_use_grass_patches_sorting_value )
  {
    LODWORD(v7.m_view_pos.x) = sort_instances->m_movement_rt.m_object;
    *(_QWORD *)&v7.m_view_pos.elements[1] = *(_QWORD *)&sort_instances->m_movement_texture.m_object;
    stlp_std::sort<vostok::render::grass_patch * *,vostok::render::sort_grass_patch_predicate>(
      (vostok::render::grass_patch **)LODWORD(viewer_position[28].y),
      (vostok::render::grass_patch **)LODWORD(viewer_position[28].z),
      v7);
  }
  if ( s_use_grass_instances_sorting_value && a4 )
  {
    y = viewer_position[28].y;
    z = viewer_position[28].z;
    for ( i = 0; LODWORD(y) != LODWORD(z) && i <= 5; ++i )
    {
      vostok::render::grass_patch::sort_instances(
        sort_instances,
        *(vostok::render::grass_patch::sort_info **)LODWORD(y));
      LODWORD(y) += 4;
    }
  }
}
