const vostok::math::float4x4 *__usercall vostok::render::renderer_context::get_view2shadow@<eax>(
        vostok::render::renderer_context *this@<ecx>,
        unsigned int index@<eax>)
{
  int v2; // eax
  int v3; // eax

  if ( index )
  {
    v2 = index - 1;
    if ( !v2 )
      return &this->m_v2shadow1;
    v3 = v2 - 1;
    if ( !v3 )
      return &this->m_v2shadow2;
    if ( v3 == 1 )
      return &this->m_v2shadow3;
  }
  return &this->m_v2shadow0;
}
