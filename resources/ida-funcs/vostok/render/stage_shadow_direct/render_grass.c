void __userpurge vostok::render::stage_shadow_direct::render_grass(
        vostok::render::stage_shadow_direct *this@<edi>,
        unsigned int cascade_index@<eax>,
        vostok::render::renderer_context *a3@<ecx>,
        const vostok::math::float3 *viewer_pos)
{
  char *v4; // ebx
  vostok::render::renderer_context *v5; // ecx
  vostok::render::grass_world *m_context; // ecx
  vostok::resources::vfs_sub_fat_resource *m_object; // eax
  vostok::render::renderer_context *v8; // ecx
  unsigned int v9; // [esp+Ch] [ebp-8h]

  v4 = (char *)this + 64 * cascade_index;
  vostok::render::renderer_context::push_set_v(
    a3,
    (int)this->m_context,
    (const vostok::math::float4x4 *)&v4[(_DWORD)&loc_406F3 + 5]);
  vostok::render::renderer_context::push_set_p(
    v5,
    (int)this->m_context,
    (const vostok::math::float4x4 *)&v4[(_DWORD)&loc_407F4 + 4]);
  if ( s_draw_grass_shadows_value )
  {
    m_context = (vostok::render::grass_world *)this->m_context;
    m_object = m_context[34].m_sub_fat.m_object;
    if ( *(int *)((char *)&dword_8B9668 + (_DWORD)m_object) )
    {
      if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
        && vostok::quasi_singleton<vostok::render::options>::pinst->current.m_shadow_quality )
      {
        vostok::render::grass_world::render(
          m_context,
          *(vostok::render::scene **)((char *)&dword_8B9668 + (_DWORD)m_object),
          (vostok::math::float3 *)m_context,
          (vostok::render::enum_render_stage_type)viewer_pos,
          0x1Bu,
          0,
          COERCE_VOSTOK_RENDER_RES_EFFECT_(25.0),
          0,
          (vostok::render::grass_patch *const)1,
          v9);
      }
    }
  }
  vostok::render::renderer_context::pop_v((vostok::render::renderer_context *)m_context, (int)this->m_context);
  vostok::render::renderer_context::pop_p(v8, this->m_context);
}
