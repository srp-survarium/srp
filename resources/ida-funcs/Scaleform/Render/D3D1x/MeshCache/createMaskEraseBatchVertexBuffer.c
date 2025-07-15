bool __userpurge Scaleform::Render::D3D1x::MeshCache::createMaskEraseBatchVertexBuffer@<al>(
        ID3D11Device *pdevice@<edi>,
        Scaleform::Render::D3D1x::MeshCache *this)
{
  ID3D11Device_vtbl *v2; // ecx
  HRESULT (__stdcall *CreateBuffer)(ID3D11Device *, const D3D11_BUFFER_DESC *, const D3D11_SUBRESOURCE_DATA *, ID3D11Buffer **); // eax
  D3D11_SUBRESOURCE_DATA initData; // [esp+4h] [ebp-6E4h] BYREF
  D3D11_BUFFER_DESC vbdesc; // [esp+10h] [ebp-6D8h] BYREF
  Scaleform::Render::VertexXY16fAlpha pbuffer[144]; // [esp+28h] [ebp-6C0h] BYREF

  vbdesc.Usage = D3D11_USAGE_IMMUTABLE;
  vbdesc.BindFlags = 1;
  vbdesc.ByteWidth = 1728;
  memset(&vbdesc.CPUAccessFlags, 0, 12);
  Scaleform::Render::MeshCache::fillMaskEraseVertexBuffer<Scaleform::Render::VertexXY16fAlpha>(pbuffer);
  v2 = pdevice->lpVtbl;
  initData.pSysMem = pbuffer;
  CreateBuffer = v2->CreateBuffer;
  initData.SysMemPitch = 0;
  initData.SysMemSlicePitch = 0;
  return CreateBuffer(pdevice, &vbdesc, &initData, &this->pMaskEraseBatchVertexBuffer.pObject) >= 0;
}
