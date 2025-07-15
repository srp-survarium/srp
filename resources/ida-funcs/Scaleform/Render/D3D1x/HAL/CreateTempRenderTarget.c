Scaleform::Render::RenderTarget *__thiscall Scaleform::Render::D3D1x::HAL::CreateTempRenderTarget(
        Scaleform::Render::D3D1x::HAL *this,
        Scaleform::Render::Size<unsigned long> *size,
        bool needsStencil)
{
  Scaleform::Render::RenderTarget *result; // eax
  Scaleform::Render::DepthStencilBuffer *v5; // ebx
  Scaleform::Render::RenderBuffer::RenderTargetData *pRenderTargetData; // ecx
  Scaleform::Render::Texture *v7; // esi
  ID3D11Device *pDevice; // eax
  ID3D11Device_vtbl *v9; // ecx
  Scaleform::Render::RenderBufferManager *pObject; // ecx
  int v11; // eax
  bool (__thiscall *IsValid)(Scaleform::Render::Texture *); // [esp-10h] [ebp-28h]
  _DWORD v13[2]; // [esp+8h] [ebp-10h] BYREF
  Scaleform::Render::RenderBuffer *v14; // [esp+10h] [ebp-8h]
  ID3D11View *v15; // [esp+14h] [ebp-4h]

  result = this->pRenderBufferManager.pObject->CreateTempRenderTarget(this->pRenderBufferManager.pObject, size);
  v5 = 0;
  v14 = result;
  if ( !result )
    return 0;
  pRenderTargetData = result->pRenderTargetData;
  if ( !pRenderTargetData || needsStencil && !pRenderTargetData->pDepthStencilBuffer.pObject )
  {
    v7 = result->GetTexture(result);
    pDevice = this->pDevice;
    size = 0;
    v9 = pDevice->lpVtbl;
    IsValid = v7[1].IsValid;
    v15 = 0;
    if ( v9->CreateRenderTargetView(pDevice, (ID3D11Resource *)IsValid, 0, (ID3D11RenderTargetView **)&size) >= 0 )
    {
      if ( needsStencil )
      {
        pObject = this->pRenderBufferManager.pObject;
        v13[0] = v7->ImgSize.Width;
        v13[1] = v7->ImgSize.Height;
        v5 = pObject->CreateDepthStencilBuffer(pObject, (const Scaleform::Render::Size<unsigned long> *)v13);
        if ( v5 )
        {
          v11 = (int)v5->GetSurface(v5);
          if ( v11 )
            v15 = *(ID3D11View **)(v11 + 36);
        }
      }
      Scaleform::Render::D3D1x::RenderTargetData::UpdateData(v15, v14, (ID3D11View *)size, v5);
      if ( v5 )
        v5->Release(v5);
      if ( size )
        (*(void (__stdcall **)(Scaleform::Render::Size<unsigned long> *))(size->Width + 8))(size);
      return (Scaleform::Render::RenderTarget *)v14;
    }
    else
    {
      if ( size )
        (*(void (__stdcall **)(Scaleform::Render::Size<unsigned long> *))(size->Width + 8))(size);
      return 0;
    }
  }
  return result;
}
