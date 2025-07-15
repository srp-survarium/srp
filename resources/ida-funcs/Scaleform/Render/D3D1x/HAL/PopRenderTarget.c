void __thiscall Scaleform::Render::D3D1x::HAL::PopRenderTarget(
        Scaleform::Render::D3D1x::HAL *this,
        unsigned int __formal)
{
  Scaleform::Render::HAL::RenderTargetEntry *v3; // esi
  Scaleform::Render::RenderBuffer::RenderTargetData *pRenderTargetData; // edi
  Scaleform::Render::RenderBuffer *pBuffer; // eax
  Scaleform::Render::DepthStencilBuffer *pObject; // ecx
  unsigned int Size; // eax
  Scaleform::Render::D3D1x::HAL_vtbl *v8; // eax
  ID3D11ShaderResourceView *views[2]; // [esp+Ch] [ebp-18h] BYREF
  Scaleform::Render::RenderEvent *v10; // [esp+14h] [ebp-10h]
  Scaleform::String v11; // [esp+18h] [ebp-Ch] BYREF
  Scaleform::Render::RenderBuffer::RenderTargetData *v12; // [esp+1Ch] [ebp-8h]
  ID3D11DepthStencilView *v13; // [esp+20h] [ebp-4h]

  Scaleform::String::String(&v11, 0);
  v10 = this->GetEvent(this, 11);
  Scaleform::String::DataDesc::Release((Scaleform::String::DataDesc *)(v11.HeapTypeBits & 0xFFFFFFFC));
  v3 = &this->RenderTargetStack.Data.Data[this->RenderTargetStack.Data.Size - 1];
  if ( v3->pRenderTarget.pObject->Type == RBuffer_Temporary )
  {
    pRenderTargetData = v3->pRenderTarget.pObject->pRenderTargetData;
    pBuffer = pRenderTargetData[1].pBuffer;
    if ( pBuffer )
    {
      ((void (__stdcall *)(Scaleform::Render::RenderBuffer *))pBuffer->Release)(pRenderTargetData[1].pBuffer);
      pRenderTargetData[1].pBuffer = 0;
    }
    pObject = pRenderTargetData->pDepthStencilBuffer.pObject;
    if ( pObject )
      pObject->Release(pObject);
    pRenderTargetData->pDepthStencilBuffer.pObject = 0;
  }
  this->Matrices.pObject->CopyFrom(this->Matrices.pObject, &v3->OldMatrixState);
  Scaleform::Render::Rect<int>::SetRect(&this->ViewRect, &v3->OldViewRect);
  qmemcpy(&this->VP, &v3->OldViewport, sizeof(this->VP));
  Scaleform::ArrayData<Scaleform::Render::HAL::RenderTargetEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::RenderTargetEntry,2>,Scaleform::ArrayConstPolicy<0,8,1>>::Resize(
    &this->RenderTargetStack.Data,
    this->RenderTargetStack.Data.Size - 1);
  Size = this->RenderTargetStack.Data.Size;
  v13 = 0;
  v12 = 0;
  if ( Size )
  {
    v12 = this->RenderTargetStack.Data.Data[this->RenderTargetStack.Data.Size - 1].pRenderTarget.pObject->pRenderTargetData;
    v13 = (ID3D11DepthStencilView *)v12[1].pBuffer;
  }
  if ( Size == 1 )
    this->HALState &= ~0x10u;
  views[0] = 0;
  views[1] = 0;
  Scaleform::Render::D3D1x::TextureManager::SetSamplerState(2u, this->pTextureManager.pObject, 0, views, 0);
  this->pDeviceContext->OMSetRenderTargets(this->pDeviceContext, 1u, (ID3D11RenderTargetView *const *)&v12[1], v13);
  v8 = this->__vftable;
  ++this->AccumulatedStats.RTChanges;
  this->HALState |= 0x20u;
  v8->updateViewport(this);
  v10->End(v10);
}
