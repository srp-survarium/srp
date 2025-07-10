bool __usercall vostok::render::state_utils::operator==@<al>(
        const D3D11_DEPTH_STENCIL_DESC *desc1@<ecx>,
        const D3D11_DEPTH_STENCIL_DESC *desc2@<eax>)
{
  return desc1->DepthEnable == desc2->DepthEnable
      && desc1->DepthWriteMask == desc2->DepthWriteMask
      && desc1->DepthFunc == desc2->DepthFunc
      && desc1->StencilEnable == desc2->StencilEnable
      && desc1->StencilReadMask == desc2->StencilReadMask
      && desc1->StencilWriteMask == desc2->StencilWriteMask
      && desc1->FrontFace.StencilFailOp == desc2->FrontFace.StencilFailOp
      && desc1->FrontFace.StencilDepthFailOp == desc2->FrontFace.StencilDepthFailOp
      && desc1->FrontFace.StencilPassOp == desc2->FrontFace.StencilPassOp
      && desc1->FrontFace.StencilFunc == desc2->FrontFace.StencilFunc
      && desc1->BackFace.StencilFailOp == desc2->BackFace.StencilFailOp
      && desc1->BackFace.StencilDepthFailOp == desc2->BackFace.StencilDepthFailOp
      && desc1->BackFace.StencilPassOp == desc2->BackFace.StencilPassOp
      && desc1->BackFace.StencilFunc == desc2->BackFace.StencilFunc;
}
