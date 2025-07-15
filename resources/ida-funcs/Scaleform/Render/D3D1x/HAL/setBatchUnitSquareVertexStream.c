void __thiscall Scaleform::Render::D3D1x::HAL::setBatchUnitSquareVertexStream(Scaleform::Render::D3D1x::HAL *this)
{
  ID3D11Buffer *pObject; // eax
  ID3D11DeviceContext *pDeviceContext; // ecx
  ID3D11Buffer *pb; // [esp+0h] [ebp-4h] BYREF

  pb = (ID3D11Buffer *)this;
  pObject = this->Cache.pMaskEraseBatchVertexBuffer.pObject;
  pDeviceContext = this->pDeviceContext;
  pb = pObject;
  pDeviceContext->IASetVertexBuffers(pDeviceContext, 0, 1u, &pb, &stride, (const unsigned int *)&FLOAT_0_0);
}
