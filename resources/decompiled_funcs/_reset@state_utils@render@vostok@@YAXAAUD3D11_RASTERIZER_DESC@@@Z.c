void __usercall vostok::render::state_utils::reset(D3D11_RASTERIZER_DESC *desc@<eax>)
{
  *(_QWORD *)&desc->FillMode = 0;
  *(_QWORD *)&desc->FrontCounterClockwise = 0;
  *(_QWORD *)&desc->DepthBiasClamp = 0;
  *(_QWORD *)&desc->DepthClipEnable = 0;
  *(_QWORD *)&desc->MultisampleEnable = 0;
  desc->FillMode = D3D11_FILL_SOLID;
  desc->CullMode = D3D11_CULL_BACK;
  desc->FrontCounterClockwise = 0;
  desc->DepthBias = 0;
  desc->DepthBiasClamp = 0.0;
  desc->SlopeScaledDepthBias = 0.0;
  desc->DepthClipEnable = 1;
  desc->ScissorEnable = 0;
  desc->MultisampleEnable = 0;
  desc->AntialiasedLineEnable = 0;
}
