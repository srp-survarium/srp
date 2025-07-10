void __userpurge vostok::render::state_descriptor::set_alpha_blend(
        D3D11_BLEND dest_blend@<edi>,
        D3D11_BLEND_OP blend_op@<esi>,
        D3D11_BLEND dest_alpha_blend@<edx>,
        D3D11_BLEND_OP blend_alpha_op@<ecx>,
        vostok::render::state_descriptor *this,
        int blend_enable,
        D3D11_BLEND src_blend,
        D3D11_BLEND src_alpha_blend)
{
  this->m_effect_desc.RenderTarget[0].BlendEnable = blend_enable;
  this->m_effect_desc.RenderTarget[1].BlendEnable = blend_enable;
  this->m_effect_desc.RenderTarget[2].BlendEnable = blend_enable;
  this->m_effect_desc.RenderTarget[3].BlendEnable = blend_enable;
  this->m_effect_desc.RenderTarget[4].BlendEnable = blend_enable;
  this->m_effect_desc.RenderTarget[5].BlendEnable = blend_enable;
  this->m_effect_desc.RenderTarget[6].BlendEnable = blend_enable;
  this->m_effect_desc.RenderTarget[7].BlendEnable = blend_enable;
  this->m_effect_desc.RenderTarget[0].SrcBlend = src_blend;
  this->m_effect_desc.RenderTarget[1].SrcBlend = src_blend;
  this->m_effect_desc.RenderTarget[2].SrcBlend = src_blend;
  this->m_effect_desc.RenderTarget[3].SrcBlend = src_blend;
  this->m_effect_desc.RenderTarget[4].SrcBlend = src_blend;
  this->m_effect_desc.RenderTarget[5].SrcBlend = src_blend;
  this->m_effect_desc.RenderTarget[6].SrcBlend = src_blend;
  this->m_effect_desc.RenderTarget[7].SrcBlend = src_blend;
  this->m_effect_desc.RenderTarget[0].DestBlend = dest_blend;
  this->m_effect_desc.RenderTarget[0].BlendOp = blend_op;
  this->m_effect_desc.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_ONE;
  this->m_effect_desc.RenderTarget[0].DestBlendAlpha = dest_alpha_blend;
  this->m_effect_desc.RenderTarget[0].BlendOpAlpha = blend_alpha_op;
  this->m_effect_desc.RenderTarget[1].DestBlend = dest_blend;
  this->m_effect_desc.RenderTarget[1].BlendOp = blend_op;
  this->m_effect_desc.RenderTarget[1].SrcBlendAlpha = D3D11_BLEND_ONE;
  this->m_effect_desc.RenderTarget[1].DestBlendAlpha = dest_alpha_blend;
  this->m_effect_desc.RenderTarget[1].BlendOpAlpha = blend_alpha_op;
  this->m_effect_desc.RenderTarget[2].DestBlend = dest_blend;
  this->m_effect_desc.RenderTarget[2].BlendOp = blend_op;
  this->m_effect_desc.RenderTarget[2].SrcBlendAlpha = D3D11_BLEND_ONE;
  this->m_effect_desc.RenderTarget[2].DestBlendAlpha = dest_alpha_blend;
  this->m_effect_desc.RenderTarget[2].BlendOpAlpha = blend_alpha_op;
  this->m_effect_desc.RenderTarget[3].DestBlend = dest_blend;
  this->m_effect_desc.RenderTarget[3].BlendOp = blend_op;
  this->m_effect_desc.RenderTarget[3].SrcBlendAlpha = D3D11_BLEND_ONE;
  this->m_effect_desc.RenderTarget[3].DestBlendAlpha = dest_alpha_blend;
  this->m_effect_desc.RenderTarget[3].BlendOpAlpha = blend_alpha_op;
  this->m_effect_desc.RenderTarget[4].DestBlend = dest_blend;
  this->m_effect_desc.RenderTarget[4].BlendOp = blend_op;
  this->m_effect_desc.RenderTarget[4].SrcBlendAlpha = D3D11_BLEND_ONE;
  this->m_effect_desc.RenderTarget[4].DestBlendAlpha = dest_alpha_blend;
  this->m_effect_desc.RenderTarget[4].BlendOpAlpha = blend_alpha_op;
  this->m_effect_desc.RenderTarget[5].DestBlend = dest_blend;
  this->m_effect_desc.RenderTarget[5].BlendOp = blend_op;
  this->m_effect_desc.RenderTarget[5].SrcBlendAlpha = D3D11_BLEND_ONE;
  this->m_effect_desc.RenderTarget[5].DestBlendAlpha = dest_alpha_blend;
  this->m_effect_desc.RenderTarget[5].BlendOpAlpha = blend_alpha_op;
  this->m_effect_desc.RenderTarget[6].DestBlend = dest_blend;
  this->m_effect_desc.RenderTarget[6].BlendOp = blend_op;
  this->m_effect_desc.RenderTarget[6].SrcBlendAlpha = D3D11_BLEND_ONE;
  this->m_effect_desc.RenderTarget[6].DestBlendAlpha = dest_alpha_blend;
  this->m_effect_desc.RenderTarget[6].BlendOpAlpha = blend_alpha_op;
  this->m_effect_desc.RenderTarget[7].DestBlend = dest_blend;
  this->m_effect_desc.RenderTarget[7].BlendOp = blend_op;
  this->m_effect_desc.RenderTarget[7].SrcBlendAlpha = D3D11_BLEND_ONE;
  this->m_effect_desc.RenderTarget[7].DestBlendAlpha = dest_alpha_blend;
  this->m_effect_desc.RenderTarget[7].BlendOpAlpha = blend_alpha_op;
}
