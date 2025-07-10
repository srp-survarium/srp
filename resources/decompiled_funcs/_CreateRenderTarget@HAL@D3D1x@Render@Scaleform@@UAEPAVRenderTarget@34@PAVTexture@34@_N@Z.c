Scaleform::Render::RenderTarget *__thiscall Scaleform::Render::D3D1x::HAL::CreateRenderTarget(
        Scaleform::Render::D3D1x::HAL *this,
        ID3D11View *texture,
        bool needsStencil)
{
  ID3D11View *v3; // esi
  Scaleform::Render::RenderBufferManager *pObject; // ebx
  Scaleform::Render::ImageFormat (__thiscall *GetPrivateData)(Scaleform::Render::Texture *); // eax
  int (__thiscall **p_CreateRenderTarget)(Scaleform::Render::RenderBufferManager *, unsigned int *, int, int); // edi
  int v8; // eax
  Scaleform::Render::RenderBuffer *v9; // ebx
  Scaleform::Render::DepthStencilBuffer *v10; // edi
  ID3D11Device *pDevice; // eax
  ID3D11View_vtbl *v12; // edx
  ID3D11View_vtbl *v13; // edx
  Scaleform::Render::RenderBufferManager *v14; // ebp
  int v15; // eax
  ID3D11DepthStencilView *pdsView; // [esp+24h] [ebp-14h]
  unsigned int v18; // [esp+2Ch] [ebp-Ch] BYREF
  _DWORD v19[2]; // [esp+30h] [ebp-8h] BYREF

  v3 = texture;
  if ( !texture || BYTE1(texture[9].lpVtbl) != 1 )
    return 0;
  pObject = this->pRenderBufferManager.pObject;
  GetPrivateData = (Scaleform::Render::ImageFormat (__thiscall *)(Scaleform::Render::Texture *))texture->GetPrivateData;
  v18 = (unsigned int)texture[7].lpVtbl;
  p_CreateRenderTarget = (int (__thiscall **)(Scaleform::Render::RenderBufferManager *, unsigned int *, int, int))&pObject->CreateRenderTarget;
  v8 = ((int (__thiscall *)(ID3D11View *, ID3D11View *))GetPrivateData)(texture, texture);
  v9 = (Scaleform::Render::RenderBuffer *)(*p_CreateRenderTarget)(pObject, &v18, 4, v8);
  v10 = 0;
  if ( !v9 )
    return 0;
  pDevice = this->pDevice;
  v12 = v3[13].lpVtbl;
  texture = 0;
  pdsView = 0;
  if ( pDevice->CreateRenderTargetView(pDevice, (ID3D11Resource *)v12->Release, 0, (ID3D11RenderTargetView **)&texture) < 0 )
  {
    if ( texture )
      texture->Release(texture);
    return 0;
  }
  if ( needsStencil )
  {
    v13 = v3[7].lpVtbl;
    v14 = this->pRenderBufferManager.pObject;
    v19[0] = v3[6].lpVtbl;
    v19[1] = v13;
    v10 = v14->CreateDepthStencilBuffer(v14, (const Scaleform::Render::Size<unsigned long> *)v19);
    if ( v10 )
    {
      v15 = (int)v10->GetSurface(v10);
      if ( v15 )
        pdsView = *(ID3D11DepthStencilView **)(v15 + 36);
    }
  }
  Scaleform::Render::D3D1x::RenderTargetData::UpdateData(v10, v9, texture, pdsView);
  if ( v10 )
    v10->Release(v10);
  if ( texture )
    texture->Release(texture);
  return (Scaleform::Render::RenderTarget *)v9;
}
