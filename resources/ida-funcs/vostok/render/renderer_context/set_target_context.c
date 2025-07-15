void __userpurge vostok::render::renderer_context::set_target_context(
        const vostok::render::renderer_context_targets *targets_context@<eax>,
        vostok::render::renderer_context *this,
        bool force_set)
{
  vostok::render::res_texture *p_m_size; // ecx
  unsigned int y; // esi
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v5; // edi
  double v6; // st7
  double v7; // st6
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *p_texture; // edi
  int *v9; // eax
  vostok::math::float4 v10; // [esp+10h] [ebp-10h]
  int v11; // [esp+2Ch] [ebp+Ch]
  unsigned int v12; // [esp+2Ch] [ebp+Ch]

  if ( force_set
    || this->m_targets != targets_context
    || this->m_current_size.x != targets_context->m_size.x
    || this->m_current_size.y != targets_context->m_size.y )
  {
    p_m_size = (vostok::render::res_texture *)&targets_context->m_size;
    this->m_targets = targets_context;
    y = targets_context->m_size.y;
    this->m_current_size.x = targets_context->m_size.x;
    this->m_current_size.y = y;
    if ( targets_context )
    {
      v6 = (double)(unsigned int)p_m_size->__vftable;
      v10.x = v6;
      v7 = (double)targets_context->m_size.y;
      v10.y = v7;
      v12 = 0;
      v10.z = 1.0 / v6;
      v10.w = 1.0 / v7;
      this->m_screen_resolution = v10;
      p_texture = &this->m_family[0].texture;
      do
      {
        v9 = (int *)&this->m_targets->m_family[v12].texture;
        if ( *v9
          && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
        {
          vostok::render::res_texture::clone(
            (vostok::render::res_texture *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr,
            p_texture->m_object,
            *v9);
        }
        ++v12;
        p_texture += 40;
      }
      while ( v12 < 73 );
    }
    else
    {
      v5 = &this->m_family[0].texture;
      v11 = 73;
      do
      {
        vostok::render::res_texture::clone(p_m_size, v5->m_object, (int)this->m_t_null.m_object);
        v5 += 40;
        --v11;
      }
      while ( v11 );
    }
  }
}
