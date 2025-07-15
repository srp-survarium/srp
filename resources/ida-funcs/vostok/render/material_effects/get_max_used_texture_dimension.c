void __userpurge vostok::render::material_effects::get_max_used_texture_dimension(
        unsigned int *out_size_x@<edi>,
        unsigned int *out_size_y@<esi>,
        vostok::render::material_effects *this)
{
  unsigned int v3; // ecx
  unsigned int out_height; // [esp+4h] [ebp-Ch] BYREF
  unsigned int out_width; // [esp+8h] [ebp-8h] BYREF
  int v6; // [esp+Ch] [ebp-4h]
  int *m_effects; // [esp+18h] [ebp+8h]

  *out_size_y = 1;
  *out_size_x = 1;
  m_effects = (int *)this->m_effects;
  v6 = 28;
  do
  {
    if ( *m_effects )
    {
      if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      {
        vostok::render::res_effect::get_max_used_texture_dimension(
          (vostok::render::res_effect *)&out_width,
          *m_effects,
          &out_width,
          &out_height);
        v3 = *out_size_y;
        *out_size_x = out_width - (out_width < *out_size_x ? out_width - *out_size_x : 0);
        *out_size_y = out_height - (out_height < v3 ? out_height - v3 : 0);
      }
    }
    ++m_effects;
    --v6;
  }
  while ( v6 );
}
