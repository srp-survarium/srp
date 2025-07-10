void __userpurge vostok::render::backend::set_render_target(
        vostok::render::enum_render_target_enum target@<ecx>,
        ID3D11RenderTargetView *rt@<eax>,
        vostok::render::backend *this)
{
  if ( rt )
    rt = (ID3D11RenderTargetView *)rt[4].lpVtbl;
  if ( this->m_targets[target] != rt )
  {
    this->m_targets[target] = rt;
    this->m_dirty_targets.render_targets[target] = 1;
  }
}
