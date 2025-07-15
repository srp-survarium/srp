bool __thiscall Scaleform::Render::D3D1x::VertexBuffer::allocBuffer(
        Scaleform::Render::D3D1x::VertexBuffer *this,
        ID3D11Device *pdevice)
{
  ID3D11Device_vtbl *v2; // esi
  HRESULT (__stdcall *CreateBuffer)(ID3D11Device *, const D3D11_BUFFER_DESC *, const D3D11_SUBRESOURCE_DATA *, ID3D11Buffer **); // edx
  D3D11_BUFFER_DESC vbdesc; // [esp+4h] [ebp-18h] BYREF

  vbdesc.ByteWidth = this->Size;
  v2 = pdevice->lpVtbl;
  vbdesc.MiscFlags = 0;
  vbdesc.StructureByteStride = 0;
  CreateBuffer = v2->CreateBuffer;
  vbdesc.Usage = D3D11_USAGE_DYNAMIC;
  vbdesc.BindFlags = 1;
  vbdesc.CPUAccessFlags = (unsigned int)&_sbh_sizeHeaderList;
  return CreateBuffer(pdevice, &vbdesc, 0, &this->pBuffer.pObject) >= 0;
}
