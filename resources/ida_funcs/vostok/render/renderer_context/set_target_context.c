void __userpurge vostok::render::renderer_context::set_target_context(
        vostok::render::renderer_context *this@<esi>,
        const vostok::render::renderer_context_targets *targets_context@<eax>,
        bool force_set)
{
  unsigned int y; // edx
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v4; // ebx
  int v5; // ebp
  double x; // st7
  double v7; // st6
  unsigned int v8; // ebx
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *p_texture; // ebp
  vostok::math::float4 v10; // [esp+10h] [ebp-10h]

  if ( force_set
    || this->m_targets != targets_context
    || this->m_current_size.x != targets_context->m_size.x
    || this->m_current_size.y != targets_context->m_size.y )
  {
    this->m_targets = targets_context;
    y = targets_context->m_size.y;
    this->m_current_size.x = targets_context->m_size.x;
    this->m_current_size.y = y;
    if ( targets_context )
    {
      x = (double)targets_context->m_size.x;
      v7 = (double)targets_context->m_size.y;
      v10.y = v7;
      v10.x = x;
      v8 = 0;
      p_texture = &this->m_family[0].texture;
      v10.z = 1.0 / x;
      v10.w = 1.0 / v7;
      this->m_screen_resolution = v10;
      do
      {
        if ( this->m_targets->m_family[v8].texture.m_object
          && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
        {
          vostok::render::res_texture::clone(p_texture->m_object, this->m_targets->m_family[v8].texture.m_object);
        }
        ++v8;
        p_texture += 40;
      }
      while ( v8 < 70 );
    }
    else
    {
      v4 = &this->m_family[0].texture;
      v5 = 70;
      do
      {
        vostok::render::res_texture::clone(v4->m_object, this->m_t_null.m_object);
        v4 += 40;
        --v5;
      }
      while ( v5 );
    }
  }
}
