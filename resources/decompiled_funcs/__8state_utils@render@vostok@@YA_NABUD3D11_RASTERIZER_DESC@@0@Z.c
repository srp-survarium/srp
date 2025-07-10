bool __fastcall vostok::render::state_utils::operator==(
        const D3D11_RASTERIZER_DESC *desc2,
        const D3D11_RASTERIZER_DESC *desc1)
{
  return desc1->FillMode == desc2->FillMode
      && desc1->CullMode == desc2->CullMode
      && desc1->FrontCounterClockwise == desc2->FrontCounterClockwise
      && desc1->DepthBias == desc2->DepthBias
      && desc1->DepthBiasClamp == desc2->DepthBiasClamp
      && desc1->SlopeScaledDepthBias == desc2->SlopeScaledDepthBias
      && desc1->DepthClipEnable == desc2->DepthClipEnable
      && desc1->ScissorEnable == desc2->ScissorEnable
      && desc1->MultisampleEnable == desc2->MultisampleEnable
      && desc1->AntialiasedLineEnable == desc2->AntialiasedLineEnable;
}
