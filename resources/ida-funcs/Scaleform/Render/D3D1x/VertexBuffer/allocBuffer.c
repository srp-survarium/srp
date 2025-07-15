bool __thiscall Scaleform::Render::D3D1x::VertexBuffer::allocBuffer(
        Scaleform::Render::D3D1x::VertexBuffer *this,
        ID3D11Device *pdevice)
{
  ID3D11Device_vtbl *v2; // esi
  _DWORD v4[6]; // [esp+4h] [ebp-18h] BYREF

  v4[0] = this->Size;
  v2 = pdevice->lpVtbl;
  v4[1] = 2;
  v4[2] = 1;
  v4[3] = &_sbh_sizeHeaderList;
  v4[4] = 0;
  v4[5] = 0;
  return v2->CreateBuffer(pdevice, (const D3D11_BUFFER_DESC *)v4, 0, &this->pBuffer.pObject) >= 0;
}
