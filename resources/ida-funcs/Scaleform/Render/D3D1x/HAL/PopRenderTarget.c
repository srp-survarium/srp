void __thiscall Scaleform::Render::D3D1x::HAL::PopRenderTarget(
        Scaleform::Render::D3D1x::HAL *this,
        unsigned int __formal)
{
  void *v3; // esi
  Scaleform::Render::HAL::RenderTargetEntry *Data; // edx
  unsigned int Size; // ecx
  Scaleform::Render::RenderTarget *pObject; // eax
  int v7; // esi
  Scaleform::Render::RenderBuffer::RenderTargetData *pRenderTargetData; // ebp
  Scaleform::Render::RenderBuffer *pBuffer; // eax
  Scaleform::Render::DepthStencilBuffer *v10; // ecx
  int v11; // ecx
  int v12; // ebp
  int v13; // edx
  unsigned int v14; // esi
  unsigned int v15; // eax
  Scaleform::Render::RenderBuffer::RenderTargetData *v16; // ebp
  void (__thiscall *updateViewport)(struct Scaleform::Render::D3D1x::HAL *); // eax
  Scaleform::Render::D3D1x::TextureManager *v18; // [esp-8h] [ebp-34h]
  ID3D11DepthStencilView *pds; // [esp+18h] [ebp-14h]
  Scaleform::String v20; // [esp+1Ch] [ebp-10h] BYREF
  Scaleform::Render::ScopedRenderEvent GPUEvent; // [esp+20h] [ebp-Ch]
  ID3D11ShaderResourceView *clearViews[2]; // [esp+24h] [ebp-8h] BYREF

  Scaleform::String::String(&v20, 0);
  GPUEvent.EventObj = this->GetEvent(this, 11);
  v3 = (void *)(v20.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((v20.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v3);
  Data = this->RenderTargetStack.Data.Data;
  Size = this->RenderTargetStack.Data.Size;
  pObject = Data[Size - 1].pRenderTarget.pObject;
  v7 = (int)&Data[Size - 1];
  if ( pObject->Type == RBuffer_Temporary )
  {
    pRenderTargetData = pObject->pRenderTargetData;
    pBuffer = pRenderTargetData[1].pBuffer;
    if ( pBuffer )
    {
      ((void (__stdcall *)(Scaleform::Render::RenderBuffer *))pBuffer->Release)(pRenderTargetData[1].pBuffer);
      pRenderTargetData[1].pBuffer = 0;
    }
    v10 = pRenderTargetData->pDepthStencilBuffer.pObject;
    if ( v10 )
      v10->Release(v10);
    pRenderTargetData->pDepthStencilBuffer.pObject = 0;
  }
  this->Matrices.pObject->CopyFrom(this->Matrices.pObject, (Scaleform::Render::MatrixState *)(v7 + 16));
  v11 = *(_DWORD *)(v7 + 696);
  v12 = *(_DWORD *)(v7 + 688);
  v13 = *(_DWORD *)(v7 + 692);
  this->ViewRect.y2 = *(_DWORD *)(v7 + 700);
  this->ViewRect.x1 = v12;
  this->ViewRect.x2 = v11;
  this->ViewRect.y1 = v13;
  *(_QWORD *)&this->VP.BufferWidth = *(_QWORD *)(v7 + 704);
  *(_QWORD *)&this->VP.Left = *(_QWORD *)(v7 + 712);
  *(_QWORD *)&this->VP.Width = *(_QWORD *)(v7 + 720);
  *(_QWORD *)&this->VP.ScissorLeft = *(_QWORD *)(v7 + 728);
  *(_QWORD *)&this->VP.ScissorWidth = *(_QWORD *)(v7 + 736);
  this->VP.Flags = *(_DWORD *)(v7 + 744);
  v14 = this->RenderTargetStack.Data.Size;
  Scaleform::ArrayDataBase<Scaleform::Render::HAL::RenderTargetEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::RenderTargetEntry,2>,Scaleform::ArrayConstPolicy<0,8,1>>::ResizeNoConstruct(
    &this->RenderTargetStack.Data,
    &this->RenderTargetStack,
    v14 - 1);
  if ( v14 - 1 > v14 )
    Scaleform::ConstructorMov<Scaleform::Render::HAL::RenderTargetEntry>::ConstructArray(
      &this->RenderTargetStack.Data.Data[v14],
      0xFFFFFFFF);
  v15 = this->RenderTargetStack.Data.Size;
  v16 = 0;
  pds = 0;
  if ( v15 )
  {
    v16 = this->RenderTargetStack.Data.Data[this->RenderTargetStack.Data.Size - 1].pRenderTarget.pObject->pRenderTargetData;
    pds = (ID3D11DepthStencilView *)v16[1].pBuffer;
  }
  if ( v15 == 1 )
    this->HALState &= ~0x10u;
  v18 = this->pTextureManager.pObject;
  *(_QWORD *)clearViews = 0;
  Scaleform::Render::D3D1x::TextureManager::SetSamplerState(2u, v18, 0, clearViews, 0);
  this->pDeviceContext->OMSetRenderTargets(this->pDeviceContext, 1u, (ID3D11RenderTargetView *const *)&v16[1], pds);
  updateViewport = this->updateViewport;
  ++this->AccumulatedStats.RTChanges;
  this->HALState |= 0x20u;
  updateViewport(this);
  GPUEvent.EventObj->End(GPUEvent.EventObj);
}
