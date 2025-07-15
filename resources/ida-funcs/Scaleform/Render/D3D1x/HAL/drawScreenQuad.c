void __thiscall Scaleform::Render::D3D1x::HAL::drawScreenQuad(Scaleform::Render::D3D1x::HAL *this)
{
  ID3D11Buffer *pObject; // [esp+4h] [ebp-4h] BYREF

  pObject = this->Cache.pMaskEraseBatchVertexBuffer.pObject;
  this->pDeviceContext->IASetVertexBuffers(
    this->pDeviceContext,
    0,
    1u,
    &pObject,
    &stride,
    (const unsigned int *)&FLOAT_0_0);
  this->drawPrimitive(this, 6u, 1u);
}
