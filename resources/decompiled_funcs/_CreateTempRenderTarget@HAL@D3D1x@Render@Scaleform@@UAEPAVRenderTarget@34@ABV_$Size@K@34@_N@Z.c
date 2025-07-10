Scaleform::Render::RenderTarget *__thiscall Scaleform::Render::D3D1x::HAL::CreateTempRenderTarget(
        Scaleform::Render::D3D1x::HAL *this,
        Scaleform::Render::Size<unsigned long> *size,
        bool needsStencil)
{
  Scaleform::Render::RenderTarget *v4; // eax
  Scaleform::Render::RenderBuffer *v5; // ebp
  Scaleform::Render::DepthStencilBuffer *v6; // esi
  Scaleform::Render::RenderBuffer::RenderTargetData *pRenderTargetData; // eax
  _DWORD *v9; // edi
  ID3D11Device *pDevice; // eax
  int v11; // edx
  Scaleform::Render::RenderBufferManager *pObject; // ecx
  int v13; // eax
  int v14; // eax
  ID3D11DepthStencilView *pdsView; // [esp+18h] [ebp-Ch]
  _DWORD v16[2]; // [esp+1Ch] [ebp-8h] BYREF

  v4 = this->pRenderBufferManager.pObject->CreateTempRenderTarget(this->pRenderBufferManager.pObject, size);
  v5 = v4;
  v6 = 0;
  if ( !v4 )
    return 0;
  pRenderTargetData = v4->pRenderTargetData;
  if ( pRenderTargetData && (!needsStencil || pRenderTargetData->pDepthStencilBuffer.pObject) )
    return (Scaleform::Render::RenderTarget *)v5;
  v9 = (_DWORD *)((int (__thiscall *)(Scaleform::Render::RenderBuffer *))v5->__vftable[1].~Scaleform::Render::RenderBuffer)(v5);
  pDevice = this->pDevice;
  size = 0;
  pdsView = 0;
  if ( pDevice->CreateRenderTargetView(pDevice, *(ID3D11Resource **)(v9[13] + 8), 0, (ID3D11RenderTargetView **)&size) >= 0 )
  {
    if ( needsStencil )
    {
      v11 = v9[7];
      pObject = this->pRenderBufferManager.pObject;
      v16[0] = v9[6];
      v16[1] = v11;
      v13 = (int)pObject->CreateDepthStencilBuffer(pObject, (const Scaleform::Render::Size<unsigned long> *)v16);
      v6 = (Scaleform::Render::DepthStencilBuffer *)v13;
      if ( v13 )
      {
        v14 = (*(int (__thiscall **)(int))(*(_DWORD *)v13 + 12))(v13);
        if ( v14 )
          pdsView = *(ID3D11DepthStencilView **)(v14 + 36);
      }
    }
    Scaleform::Render::D3D1x::RenderTargetData::UpdateData(v6, v5, (ID3D11View *)size, pdsView);
    if ( v6 )
      v6->Release(v6);
    if ( size )
      (*(void (__stdcall **)(Scaleform::Render::Size<unsigned long> *))(size->Width + 8))(size);
    return (Scaleform::Render::RenderTarget *)v5;
  }
  else
  {
    if ( size )
      (*(void (__stdcall **)(Scaleform::Render::Size<unsigned long> *))(size->Width + 8))(size);
    return 0;
  }
}
