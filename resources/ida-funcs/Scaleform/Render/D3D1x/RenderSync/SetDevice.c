bool __userpurge Scaleform::Render::D3D1x::RenderSync::SetDevice@<al>(
        Scaleform::Render::D3D1x::RenderSync *this@<edi>,
        ID3D11Device *pdevice@<esi>,
        ID3D11Query *pdeviceCtx)
{
  ID3D11DeviceContext *v3; // ebx
  HRESULT (__stdcall *CreateQuery)(ID3D11Device *, const D3D11_QUERY_DESC *, ID3D11Query **); // eax
  ID3D11Device *pObject; // eax
  ID3D11DeviceContext *v6; // eax
  ID3D11Device *v8; // eax
  ID3D11DeviceContext *v9; // eax
  HRESULT hr; // [esp+20h] [ebp-Ch]
  D3D11_QUERY_DESC desc; // [esp+24h] [ebp-8h] BYREF

  v3 = (ID3D11DeviceContext *)pdeviceCtx;
  if ( pdevice && pdeviceCtx )
  {
    CreateQuery = pdevice->CreateQuery;
    desc.MiscFlags = 0;
    desc.Query = D3D11_QUERY_EVENT;
    pdeviceCtx = 0;
    hr = CreateQuery(pdevice, &desc, &pdeviceCtx);
    if ( pdeviceCtx )
    {
      pdeviceCtx->Release(pdeviceCtx);
      pdevice->AddRef(pdevice);
      pObject = this->pDevice.pObject;
      if ( pObject )
        pObject->Release(this->pDevice.pObject);
      this->pDevice.pObject = pdevice;
      v3->AddRef(v3);
      v6 = this->pDeviceContext.pObject;
      if ( v6 )
        v6->Release(this->pDeviceContext.pObject);
      this->pDeviceContext.pObject = v3;
    }
    return hr >= 0;
  }
  else
  {
    v8 = this->pDevice.pObject;
    if ( v8 )
      v8->Release(this->pDevice.pObject);
    this->pDevice.pObject = 0;
    v9 = this->pDeviceContext.pObject;
    if ( v9 )
      v9->Release(this->pDeviceContext.pObject);
    this->pDeviceContext.pObject = 0;
    Scaleform::Render::RenderSync::ReleaseOutstandingFrames(this);
    return 1;
  }
}
