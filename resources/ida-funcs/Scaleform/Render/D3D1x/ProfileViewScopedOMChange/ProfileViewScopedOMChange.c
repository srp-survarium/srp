void __userpurge Scaleform::Render::D3D1x::ProfileViewScopedOMChange::ProfileViewScopedOMChange(
        Scaleform::Render::D3D1x::ProfileViewScopedOMChange *this@<esi>,
        bool *drawingMask@<ecx>,
        ID3D11DeviceContext *pcontext@<eax>,
        ID3D11BlendState *pblendOverride,
        ID3D11DepthStencilState *pdepthOverride)
{
  this->pDeviceContext = pcontext;
  this->DrawingMask = drawingMask;
  this->pBlendState = pblendOverride;
  this->pDepthStencilState = pdepthOverride;
  *drawingMask = 1;
  this->pDeviceContext->OMGetBlendState(this->pDeviceContext, &this->pBlendState, 0, 0);
  this->pDeviceContext->OMGetDepthStencilState(this->pDeviceContext, &this->pDepthStencilState, &this->StencilRef);
  this->pDeviceContext->OMSetBlendState(this->pDeviceContext, pblendOverride, 0, -1u);
  this->pDeviceContext->OMSetDepthStencilState(this->pDeviceContext, pdepthOverride, 0);
}
