void __userpurge vostok::render::grass_world::render(
        vostok::render::grass_world *this@<ecx>,
        vostok::math::frustum *p_shadow_frustum@<esi>,
        vostok::render::grass_world *context,
        vostok::render::renderer_context *viewer_position,
        const vostok::math::float3 *stage_type,
        vostok::render::enum_render_stage_type tech_index,
        vostok::render::res_effect *draw_distance,
        float stencil_mask,
        vostok::render::res_effect *debug_effect,
        bool shadow_pass,
        unsigned int cascade_index)
{
  vostok::render::grass_world *M_start; // ecx
  vostok::render::grass_world_vtbl *v12; // eax
  void **v13; // ebx
  char *v14; // edi
  vostok::render::res_effect *v15; // [esp+4h] [ebp-90h]
  unsigned int v16; // [esp+8h] [ebp-8Ch]
  vostok::render::grass_patch *const *end_patch; // [esp+18h] [ebp-7Ch]
  vostok::math::frustum shadow_frustum; // [esp+1Ch] [ebp-78h] BYREF

  if ( *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
       + 295) )
  {
    M_start = (vostok::render::grass_world *)context->m_templates._M_impl._M_start;
    if ( M_start != (vostok::render::grass_world *)context->m_templates._M_impl._M_finish )
    {
      v12 = M_start->__vftable;
      M_start = (vostok::render::grass_world *)M_start->link_child_resource;
      if ( M_start != (vostok::render::grass_world *)v12->unlink_child_resource
        && context->m_patches._M_impl._M_start == context->m_patches._M_impl._M_finish )
      {
        context->m_need_populate = 1;
      }
    }
    if ( context->m_need_populate )
    {
      vostok::render::grass_world::populate(M_start, context);
      context->m_need_populate = 0;
    }
    v13 = context->m_visible_patches._M_impl._M_start;
    for ( end_patch = (vostok::render::grass_patch *const *)context->m_visible_patches._M_impl._M_finish;
          v13 != (void **)end_patch;
          ++v13 )
    {
      v14 = (char *)*v13;
      if ( !*((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
            + 288)
        || !v14[16557] )
      {
        if ( !(_BYTE)debug_effect
          || (p_shadow_frustum = &shadow_frustum,
              vostok::math::frustum::frustum(&shadow_frustum, &viewer_position->m_vp),
              vostok::math::cuboid::test_inexact(
                (vostok::math::cuboid *)(v14 + 16404),
                (const vostok::math::aabb *)(v14 + 16404)) != intersection_outside) )
        {
          vostok::render::grass_patch::render(
            (vostok::render::grass_patch *)v14,
            stage_type,
            (unsigned int)p_shadow_frustum,
            context,
            viewer_position,
            tech_index,
            draw_distance,
            stencil_mask,
            v15,
            v16);
        }
      }
    }
  }
}
