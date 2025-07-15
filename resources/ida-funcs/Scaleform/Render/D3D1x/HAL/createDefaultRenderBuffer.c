bool __thiscall Scaleform::Render::D3D1x::HAL::createDefaultRenderBuffer(Scaleform::Render::D3D1x::HAL *this)
{
  Scaleform::Render::RenderTarget *v2; // eax
  unsigned int v3; // edx
  ID3D11DeviceContext *pDeviceContext; // eax
  Scaleform::Render::RenderTarget *v5; // eax
  Scaleform::Render::RenderBuffer *v6; // eax
  Scaleform::Render::DepthStencilBuffer *v7; // edi
  Scaleform::Render::DepthStencilBuffer *v8; // eax
  Scaleform::Render::DepthStencilBuffer *v9; // eax
  Scaleform::Render::Size<unsigned long> v11; // [esp+Ch] [ebp-7Ch] BYREF
  Scaleform::Render::Size<unsigned long> v12; // [esp+38h] [ebp-50h] BYREF
  Scaleform::Render::Size<unsigned long> v13; // [esp+64h] [ebp-24h] BYREF
  Scaleform::Render::Size<unsigned long> bufferSize; // [esp+6Ch] [ebp-1Ch] BYREF
  int v15; // [esp+74h] [ebp-14h] BYREF
  int v16; // [esp+78h] [ebp-10h] BYREF
  ID3D11View *v17; // [esp+7Ch] [ebp-Ch] BYREF
  Scaleform::Render::RenderTarget *v18; // [esp+80h] [ebp-8h]
  ID3D11View *v19; // [esp+84h] [ebp-4h] BYREF

  if ( this->GetDefaultRenderTarget(this) )
  {
    v2 = this->GetDefaultRenderTarget(this);
    v3 = v2->ViewRect.x2 - v2->ViewRect.x1;
    bufferSize.Height = v2->ViewRect.y2 - v2->ViewRect.y1;
    bufferSize.Width = v3;
    return this->pRenderBufferManager.pObject->Initialize(
             this->pRenderBufferManager.pObject,
             this->pTextureManager.pObject,
             Image_R8G8B8A8,
             &bufferSize);
  }
  pDeviceContext = this->pDeviceContext;
  v19 = 0;
  v17 = 0;
  v15 = 0;
  v16 = 0;
  pDeviceContext->OMGetRenderTargets(
    pDeviceContext,
    1u,
    (ID3D11RenderTargetView **)&v19,
    (ID3D11DepthStencilView **)&v17);
  v19->GetResource(v19, (ID3D11Resource **)&v15);
  (*(void (__stdcall **)(int, Scaleform::Render::Size<unsigned long> *))(*(_DWORD *)v15 + 40))(v15, &v12);
  bufferSize = v12;
  v5 = (Scaleform::Render::RenderTarget *)Scaleform::NewOverrideBase<75>::operator new(
                                            0x2Cu,
                                            (Scaleform::MemAddressStub *)this);
  if ( v5 )
  {
    Scaleform::Render::RenderTarget::RenderTarget(v5, 0, RBuffer_Default, &bufferSize);
    v18 = (Scaleform::Render::RenderTarget *)v6;
  }
  else
  {
    v18 = 0;
  }
  v7 = 0;
  if ( v17 )
  {
    v19->GetResource(v19, (ID3D11Resource **)&v16);
    (*(void (__stdcall **)(int, Scaleform::Render::Size<unsigned long> *))(*(_DWORD *)v16 + 40))(v16, &v11);
    v13 = v11;
    v8 = (Scaleform::Render::DepthStencilBuffer *)Scaleform::NewOverrideBase<75>::operator new(
                                                    0x1Cu,
                                                    (Scaleform::MemAddressStub *)this);
    if ( v8 )
      Scaleform::Render::DepthStencilBuffer::DepthStencilBuffer(v8, 0, &v13);
    else
      v9 = 0;
    v7 = v9;
  }
  Scaleform::Render::D3D1x::RenderTargetData::UpdateData(v17, v18, v19, v7);
  if ( this->SetRenderTarget(this, v18, 1) )
  {
    if ( v7 )
      v7->Release(v7);
    if ( v18 )
      v18->Release(v18);
    if ( v16 )
      (*(void (__stdcall **)(int))(*(_DWORD *)v16 + 8))(v16);
    if ( v15 )
      (*(void (__stdcall **)(int))(*(_DWORD *)v15 + 8))(v15);
    if ( v17 )
      v17->Release(v17);
    if ( v19 )
      v19->Release(v19);
    return this->pRenderBufferManager.pObject->Initialize(
             this->pRenderBufferManager.pObject,
             this->pTextureManager.pObject,
             Image_R8G8B8A8,
             &bufferSize);
  }
  if ( v7 )
    v7->Release(v7);
  if ( v18 )
    v18->Release(v18);
  if ( v16 )
    (*(void (__stdcall **)(int))(*(_DWORD *)v16 + 8))(v16);
  if ( v15 )
    (*(void (__stdcall **)(int))(*(_DWORD *)v15 + 8))(v15);
  if ( v17 )
    v17->Release(v17);
  if ( v19 )
    v19->Release(v19);
  return 0;
}
