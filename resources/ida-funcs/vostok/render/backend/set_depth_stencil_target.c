void __usercall vostok::render::backend::set_depth_stencil_target(
        vostok::render::backend *this@<esi>,
        const vostok::render::render_target *zrt@<eax>)
{
  ID3D11DepthStencilView *m_zrt; // ecx
  bool v3; // zf

  if ( zrt )
    m_zrt = zrt->m_zrt;
  else
    m_zrt = 0;
  v3 = this->m_zb == m_zrt;
  this->m_zb = m_zrt;
  this->m_dirty_targets.depth_stencil |= !v3;
}
