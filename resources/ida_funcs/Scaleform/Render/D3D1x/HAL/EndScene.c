char __thiscall Scaleform::Render::D3D1x::HAL::EndScene(Scaleform::Render::D3D1x::HAL *this)
{
  Scaleform::Render::RenderEvent *v2; // ebx
  void *v3; // edi
  ID3D11RenderTargetView *pObject; // eax
  ID3D11DepthStencilView *v6; // eax
  Scaleform::String v7; // [esp+Ch] [ebp-4h] BYREF

  Scaleform::String::String(&v7, 0);
  v2 = this->GetEvent(this, 2);
  v3 = (void *)(v7.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((v7.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v3);
  if ( Scaleform::Render::HAL::EndScene(this) )
  {
    pObject = this->pRenderTargetView.pObject;
    if ( pObject )
      pObject->Release(this->pRenderTargetView.pObject);
    this->pRenderTargetView.pObject = 0;
    v6 = this->pDepthStencilView.pObject;
    if ( v6 )
      v6->Release(this->pDepthStencilView.pObject);
    this->pDepthStencilView.pObject = 0;
    v2->End(v2);
    return 1;
  }
  else
  {
    v2->End(v2);
    return 0;
  }
}
