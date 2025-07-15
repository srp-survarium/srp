char __thiscall Scaleform::Render::D3D1x::HAL::BeginScene(Scaleform::Render::D3D1x::HAL *this)
{
  char result; // al
  Scaleform::String::DataDesc *v3; // ecx
  Scaleform::Render::RenderEvent *v4; // eax
  ID3D11DeviceContext *pDeviceContext; // eax
  ID3D11DeviceContext_vtbl *v6; // ecx
  Scaleform::Render::D3D1x::ShaderInterface *v7; // ecx
  Scaleform::String v8; // [esp-8h] [ebp-14h] BYREF
  int v9; // [esp-4h] [ebp-10h]
  Scaleform::String v10; // [esp+0h] [ebp-Ch]
  Scaleform::Ptr<ID3D11DepthStencilView> *p_pDepthStencilView; // [esp+4h] [ebp-8h]
  Scaleform::Render::ScopedRenderEvent v12; // [esp+8h] [ebp-4h] BYREF

  result = Scaleform::Render::HAL::BeginScene(this);
  if ( result )
  {
    v9 = 1;
    v8.pData = v3;
    Scaleform::String::String(&v8, "Scaleform::Render::D3D1x::HAL::BeginScene-SetState");
    v4 = (Scaleform::Render::RenderEvent *)((int (__thiscall *)(Scaleform::Render::D3D1x::HAL *, int, Scaleform::String::DataDesc *, int))this->GetEvent)(
                                             this,
                                             3,
                                             v8.pData,
                                             v9);
    Scaleform::Render::ScopedRenderEvent::ScopedRenderEvent(&v12, v4, v10, (bool)p_pDepthStencilView);
    pDeviceContext = this->pDeviceContext;
    v6 = pDeviceContext->lpVtbl;
    p_pDepthStencilView = &this->pDepthStencilView;
    v10.pData = (Scaleform::String::DataDesc *)&this->pRenderTargetView;
    ((void (__stdcall *)(ID3D11DeviceContext *, int))v6->OMGetRenderTargets)(pDeviceContext, 1);
    this->pDeviceContext->IASetPrimitiveTopology(this->pDeviceContext, D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
    this->pDeviceContext->OMSetDepthStencilState(this->pDeviceContext, this->DepthStencilStates[0], 0);
    this->CurrentConstantBuffer = 0;
    Scaleform::Render::D3D1x::ShaderInterface::BeginScene(v7, this->ShaderData.UniformData);
    v12.EventObj->End(v12.EventObj);
    return 1;
  }
  return result;
}
