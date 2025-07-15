void __userpurge vostok::render::backend::set_render_targets(
        ID3D11RenderTargetView *rt0@<ecx>,
        const vostok::render::render_target *rt1@<edx>,
        const vostok::render::render_target *rt2@<esi>,
        const vostok::render::render_target *rt3@<edi>,
        vostok::render::backend *this)
{
  ID3D11RenderTargetView *m_rt; // ecx
  ID3D11RenderTargetView *v6; // ecx
  ID3D11RenderTargetView *v7; // ecx

  if ( rt0 )
    rt0 = (ID3D11RenderTargetView *)rt0[4].lpVtbl;
  if ( this->m_targets[0] != rt0 )
  {
    this->m_targets[0] = rt0;
    this->m_dirty_targets.render_targets[0] = 1;
  }
  if ( rt1 )
    m_rt = rt1->m_rt;
  else
    m_rt = 0;
  if ( this->m_targets[1] != m_rt )
  {
    this->m_targets[1] = m_rt;
    this->m_dirty_targets.render_targets[1] = 1;
  }
  if ( rt2 )
    v6 = rt2->m_rt;
  else
    v6 = 0;
  if ( this->m_targets[2] != v6 )
  {
    this->m_targets[2] = v6;
    this->m_dirty_targets.render_targets[2] = 1;
  }
  if ( rt3 )
    v7 = rt3->m_rt;
  else
    v7 = 0;
  if ( this->m_targets[3] != v7 )
  {
    this->m_targets[3] = v7;
    this->m_dirty_targets.render_targets[3] = 1;
  }
}
