char __thiscall Scaleform::Render::D3D1x::HAL::EndScene(Scaleform::Render::D3D1x::HAL *this)
{
  char v2; // bl
  Scaleform::Ptr<ID3D11RenderTargetView> *p_pRenderTargetView; // edi
  ID3D11RenderTargetView *pObject; // eax
  Scaleform::Ptr<ID3D11DepthStencilView> *p_pDepthStencilView; // esi
  Scaleform::Render::RenderEvent *v7; // [esp+8h] [ebp-8h]
  Scaleform::String v8; // [esp+Ch] [ebp-4h] BYREF

  v2 = 0;
  Scaleform::String::String(&v8, 0);
  v7 = this->GetEvent(this, 2);
  Scaleform::String::DataDesc::Release((Scaleform::String::DataDesc *)(v8.HeapTypeBits & 0xFFFFFFFC));
  if ( Scaleform::Render::HAL::EndScene(this) )
  {
    p_pRenderTargetView = &this->pRenderTargetView;
    pObject = this->pRenderTargetView.pObject;
    if ( pObject )
      pObject->Release(this->pRenderTargetView.pObject);
    p_pDepthStencilView = &this->pDepthStencilView;
    p_pRenderTargetView->pObject = 0;
    if ( p_pDepthStencilView->pObject )
      p_pDepthStencilView->pObject->Release(p_pDepthStencilView->pObject);
    p_pDepthStencilView->pObject = 0;
    v2 = 1;
  }
  v7->End(v7);
  return v2;
}
