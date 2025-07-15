bool __thiscall Scaleform::Render::D3D1x::IndexBuffer::allocBuffer(
        Scaleform::Render::D3D1x::IndexBuffer *this,
        ID3D11Device *pdevice)
{
  ID3D11Device_vtbl *v2; // esi
  HRESULT (__stdcall *CreateBuffer)(ID3D11Device *, const D3D11_BUFFER_DESC *, const D3D11_SUBRESOURCE_DATA *, ID3D11Buffer **); // edx
  D3D11_BUFFER_DESC ibdesc; // [esp+4h] [ebp-18h] BYREF

  ibdesc.ByteWidth = this->Size;
  ibdesc.Usage = D3D11_USAGE_DYNAMIC;
  ibdesc.BindFlags = 2;
  v2 = pdevice->lpVtbl;
  ibdesc.MiscFlags = 0;
  ibdesc.StructureByteStride = 0;
  CreateBuffer = v2->CreateBuffer;
  ibdesc.CPUAccessFlags = (unsigned int)&_sbh_sizeHeaderList;
  return CreateBuffer(pdevice, &ibdesc, 0, &this->pBuffer.pObject) >= 0;
}
