Scaleform::Render::RenderTarget *__thiscall Scaleform::Render::D3D1x::HAL::CreateRenderTarget(
        Scaleform::Render::D3D1x::HAL *this,
        ID3D11View *pcolor,
        ID3D11View *pdepth)
{
  ID3D11View_vtbl *v4; // ecx
  Scaleform::Render::RenderBufferManager *pObject; // ecx
  Scaleform::Render::RenderBuffer *v6; // eax
  Scaleform::Render::DepthStencilBuffer *v7; // eax
  unsigned int v8; // eax
  Scaleform::Render::RenderBuffer *v9; // edi
  Scaleform::Render::Size<unsigned long> v11; // [esp+8h] [ebp-74h] BYREF
  _DWORD v12[11]; // [esp+34h] [ebp-48h] BYREF
  int v13; // [esp+60h] [ebp-1Ch] BYREF
  int v14; // [esp+64h] [ebp-18h]
  Scaleform::Render::RenderBuffer *v15; // [esp+68h] [ebp-14h]
  int v16; // [esp+6Ch] [ebp-10h] BYREF
  int v17; // [esp+70h] [ebp-Ch] BYREF
  Scaleform::Render::Size<unsigned long> bufferSize; // [esp+74h] [ebp-8h] BYREF

  v4 = pcolor->lpVtbl;
  v16 = 0;
  v17 = 0;
  v13 = 0;
  v14 = 0;
  v4->GetResource(pcolor, (ID3D11Resource **)&v16);
  (*(void (__stdcall **)(int, _DWORD *))(*(_DWORD *)v16 + 40))(v16, v12);
  pObject = this->pRenderBufferManager.pObject;
  v13 = v12[0];
  v14 = v12[1];
  v6 = pObject->CreateRenderTarget(
         pObject,
         (const Scaleform::Render::Size<unsigned long> *)&v13,
         RBuffer_User,
         Image_R8G8B8A8,
         0);
  v15 = v6;
  if ( v6 )
    v6->AddRef(v6);
  bufferSize.Height = 0;
  if ( pdepth )
  {
    pdepth->GetResource(pdepth, (ID3D11Resource **)&v17);
    (*(void (__stdcall **)(int, Scaleform::Render::Size<unsigned long> *))(*(_DWORD *)v17 + 40))(v17, &v11);
    bufferSize = v11;
    v7 = (Scaleform::Render::DepthStencilBuffer *)Scaleform::NewOverrideBase<75>::operator new(
                                                    0x1Cu,
                                                    (Scaleform::MemAddressStub *)this);
    if ( v7 )
      Scaleform::Render::DepthStencilBuffer::DepthStencilBuffer(v7, 0, &bufferSize);
    else
      v8 = 0;
    bufferSize.Height = v8;
  }
  v9 = v15;
  Scaleform::Render::D3D1x::RenderTargetData::UpdateData(
    pdepth,
    v15,
    pcolor,
    (Scaleform::Render::DepthStencilBuffer *)bufferSize.Height);
  if ( bufferSize.Height )
    (*(void (__thiscall **)(unsigned int))(*(_DWORD *)bufferSize.Height + 8))(bufferSize.Height);
  if ( v9 )
    v9->Release(v9);
  if ( v17 )
    (*(void (__stdcall **)(int))(*(_DWORD *)v17 + 8))(v17);
  if ( v16 )
    (*(void (__stdcall **)(int))(*(_DWORD *)v16 + 8))(v16);
  return (Scaleform::Render::RenderTarget *)v9;
}


Scaleform::Render::RenderTarget *__thiscall Scaleform::Render::D3D1x::HAL::CreateRenderTarget(
        Scaleform::Render::D3D1x::HAL *this,
        ID3D11View *texture,
        bool needsStencil)
{
  ID3D11View *v3; // esi
  Scaleform::Render::RenderBuffer *pObject; // eax
  Scaleform::Render::RenderBuffer_vtbl *v6; // edi
  int v7; // eax
  Scaleform::Render::RenderBuffer *v8; // eax
  Scaleform::Render::DepthStencilBuffer *v9; // edi
  ID3D11Device *pDevice; // eax
  ID3D11View_vtbl *v11; // edx
  ID3D11Device_vtbl *v12; // ecx
  Scaleform::Render::RenderBufferManager *v13; // ebx
  int v14; // eax
  unsigned int (__stdcall *Release)(IUnknown *); // [esp-Ch] [ebp-30h]
  _DWORD v17[2]; // [esp+Ch] [ebp-18h] BYREF
  _DWORD v18[2]; // [esp+14h] [ebp-10h] BYREF
  Scaleform::Render::RenderBuffer *v19; // [esp+1Ch] [ebp-8h]
  ID3D11View *v20; // [esp+20h] [ebp-4h]

  v3 = texture;
  if ( !texture )
    return 0;
  if ( BYTE1(texture[9].lpVtbl) != 1 )
    return 0;
  pObject = (Scaleform::Render::RenderBuffer *)this->pRenderBufferManager.pObject;
  v18[0] = texture[6].lpVtbl;
  v18[1] = texture[7].lpVtbl;
  v6 = pObject->__vftable;
  v19 = pObject;
  v7 = ((int (__thiscall *)(ID3D11View *, ID3D11View *))texture->GetPrivateData)(texture, texture);
  v8 = (Scaleform::Render::RenderBuffer *)((int (__thiscall *)(Scaleform::Render::RenderBuffer *, _DWORD *, int, int))v6[1].Release)(
                                            v19,
                                            v18,
                                            4,
                                            v7);
  v9 = 0;
  v19 = v8;
  if ( !v8 )
    return 0;
  pDevice = this->pDevice;
  v11 = v3[13].lpVtbl;
  texture = 0;
  Release = v11->Release;
  v12 = pDevice->lpVtbl;
  v20 = 0;
  if ( v12->CreateRenderTargetView(pDevice, (ID3D11Resource *)Release, 0, (ID3D11RenderTargetView **)&texture) < 0 )
  {
    if ( texture )
      texture->Release(texture);
    return 0;
  }
  if ( needsStencil )
  {
    v13 = this->pRenderBufferManager.pObject;
    v17[0] = v3[6].lpVtbl;
    v17[1] = v3[7].lpVtbl;
    v9 = v13->CreateDepthStencilBuffer(v13, (const Scaleform::Render::Size<unsigned long> *)v17);
    if ( v9 )
    {
      v14 = (int)v9->GetSurface(v9);
      if ( v14 )
        v20 = *(ID3D11View **)(v14 + 36);
    }
  }
  Scaleform::Render::D3D1x::RenderTargetData::UpdateData(v20, v19, texture, v9);
  if ( v9 )
    v9->Release(v9);
  if ( texture )
    texture->Release(texture);
  return (Scaleform::Render::RenderTarget *)v19;
}
