void __fastcall vostok::render::state_descriptor::color_write_enable(
        vostok::render::state_descriptor *this,
        D3D11_COLOR_WRITE_ENABLE mode)
{
  unsigned __int8 *p_RenderTargetWriteMask; // eax
  int v3; // ecx

  p_RenderTargetWriteMask = &this->m_effect_desc.RenderTarget[0].RenderTargetWriteMask;
  this->m_effect_desc_updated |= this->m_effect_desc.RenderTarget[0].RenderTargetWriteMask != mode;
  v3 = 8;
  do
  {
    *p_RenderTargetWriteMask = mode;
    p_RenderTargetWriteMask += 32;
    --v3;
  }
  while ( v3 );
}
