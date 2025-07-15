void __usercall vostok::render::backend::set_render_target(
        vostok::render::backend *this@<esi>,
        vostok::render::enum_render_target_enum target@<edx>,
        const vostok::render::render_target *rt@<eax>)
{
  ID3D11RenderTargetView *m_rt; // ecx
  ID3D11RenderTargetView **v4; // eax

  if ( rt )
    m_rt = rt->m_rt;
  else
    m_rt = 0;
  v4 = &this->m_targets[target];
  if ( *v4 != m_rt )
  {
    *v4 = m_rt;
    this->m_dirty_targets.render_targets[target] = 1;
  }
}
