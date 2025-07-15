bool __thiscall Scaleform::Render::D3D1x::HAL::BeginScene(Scaleform::Render::D3D1x::HAL *this)
{
  bool result; // al
  Scaleform::Render::RenderEvent *v3; // ebx
  Scaleform::Render::RenderEvent_vtbl *v4; // edi
  Scaleform::String::DataDesc *v5; // ecx
  void *v6; // edi
  Scaleform::Render::D3D1x::ShaderInterface *v7; // ecx
  Scaleform::String v8; // [esp-4h] [ebp-14h] BYREF
  Scaleform::String src; // [esp+Ch] [ebp-4h] BYREF

  result = Scaleform::Render::HAL::BeginScene(this);
  if ( result )
  {
    Scaleform::String::String(&src, "Scaleform::Render::D3D1x::HAL::BeginScene-SetState");
    v3 = this->GetEvent(this, 3);
    v4 = v3->__vftable;
    v8.pData = v5;
    Scaleform::String::String(&v8, &src);
    ((void (__thiscall *)(Scaleform::Render::RenderEvent *, Scaleform::String::DataDesc *))v4->Begin)(v3, v8.pData);
    v6 = (void *)(src.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)((src.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v6);
    this->pDeviceContext->OMGetRenderTargets(
      this->pDeviceContext,
      1u,
      (ID3D11RenderTargetView **)&this->pRenderTargetView,
      (ID3D11DepthStencilView **)&this->pDepthStencilView);
    this->pDeviceContext->IASetPrimitiveTopology(this->pDeviceContext, D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
    this->pDeviceContext->OMSetDepthStencilState(this->pDeviceContext, this->DepthStencilStates[0], 0);
    this->CurrentConstantBuffer = 0;
    Scaleform::Render::D3D1x::ShaderInterface::BeginScene(v7, this->ShaderData.UniformData);
    v3->End(v3);
    return 1;
  }
  return result;
}
