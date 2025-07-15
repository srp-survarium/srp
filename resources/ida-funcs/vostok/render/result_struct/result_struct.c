void __userpurge vostok::render::result_struct::result_struct(
        vostok::render::result_struct *this@<ecx>,
        vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *a2@<edi>,
        unsigned int width,
        DXGI_FORMAT height,
        DXGI_FORMAT format,
        const bool use_diffuse,
        const bool use_normal,
        const bool use_fresnel,
        const bool use_smoothness)
{
  stlp_std::priv::_Rb_tree_node_base *render_target; // eax
  stlp_std::priv::_Rb_tree_node_base *v10; // eax
  stlp_std::priv::_Rb_tree_node_base *v11; // eax
  stlp_std::priv::_Rb_tree_node_base *v12; // eax
  unsigned int v13; // [esp+0h] [ebp-8h]

  a2->m_object = 0;
  a2[1].m_object = 0;
  a2[2].m_object = 0;
  a2[3].m_object = 0;
  if ( (_BYTE)format )
  {
    render_target = vostok::render::resource_manager::create_render_target(
                      (vostok::render::resource_manager *)this,
                      (const char **)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                      0,
                      width,
                      height,
                      (char *)0x1C,
                      DXGI_FORMAT_R32G32B32A32_TYPELESS,
                      0,
                      0,
                      0,
                      v13);
    vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
      a2,
      (vostok::render::render_target *)render_target);
  }
  if ( use_diffuse )
  {
    v10 = vostok::render::resource_manager::create_render_target(
            (vostok::render::resource_manager *)this,
            (const char **)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
            0,
            width,
            height,
            (char *)0x1C,
            DXGI_FORMAT_R32G32B32A32_TYPELESS,
            0,
            0,
            0,
            v13);
    vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
      a2 + 1,
      (vostok::render::render_target *)v10);
  }
  if ( use_normal )
  {
    v11 = vostok::render::resource_manager::create_render_target(
            (vostok::render::resource_manager *)this,
            (const char **)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
            0,
            width,
            height,
            (char *)0x1C,
            DXGI_FORMAT_R32G32B32A32_TYPELESS,
            0,
            0,
            0,
            v13);
    vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
      a2 + 2,
      (vostok::render::render_target *)v11);
  }
  if ( use_fresnel )
  {
    v12 = vostok::render::resource_manager::create_render_target(
            (vostok::render::resource_manager *)this,
            (const char **)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
            0,
            width,
            height,
            (char *)0x1C,
            DXGI_FORMAT_R32G32B32A32_TYPELESS,
            0,
            0,
            0,
            v13);
    vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
      a2 + 3,
      (vostok::render::render_target *)v12);
  }
}
