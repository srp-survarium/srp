void __thiscall Scaleform::Render::D3D1x::HAL::setBatchUnitSquareVertexStream(Scaleform::Render::D3D1x::HAL *this)
{
  ID3D11Buffer *pObject; // eax
  ID3D11DeviceContext *pDeviceContext; // ecx
  Scaleform::Render::D3D1x::HAL *v3; // [esp+0h] [ebp-4h] BYREF

  v3 = this;
  pObject = this->Cache.pMaskEraseBatchVertexBuffer.pObject;
  pDeviceContext = this->pDeviceContext;
  v3 = (Scaleform::Render::D3D1x::HAL *)pObject;
  pDeviceContext->IASetVertexBuffers(
    pDeviceContext,
    0,
    1u,
    (ID3D11Buffer *const *)&v3,
    &stride,
    (const unsigned int *)&FLOAT_0_0);
}
