void __thiscall Scaleform::Render::D3D1x::HAL::drawScreenQuad(Scaleform::Render::D3D1x::HAL *this)
{
  ID3D11Buffer *pb; // [esp+4h] [ebp-4h] BYREF

  pb = this->Cache.pMaskEraseBatchVertexBuffer.pObject;
  this->pDeviceContext->IASetVertexBuffers(this->pDeviceContext, 0, 1u, &pb, &stride, (const unsigned int *)&FLOAT_0_0);
  this->drawPrimitive(this, 6u, 1u);
}
