void __thiscall Scaleform::Render::D3D1x::TextureManager::BeginScene(Scaleform::Render::D3D1x::TextureManager *this)
{
  ID3D11DeviceContext *pDeviceContext; // eax
  ID3D11SamplerState *states[4]; // [esp+4h] [ebp-20h] BYREF
  ID3D11ShaderResourceView *views[4]; // [esp+14h] [ebp-10h] BYREF

  *(_QWORD *)this->CurrentSamplers = 0;
  *(_QWORD *)&this->CurrentSamplers[2] = 0;
  *(_QWORD *)this->CurrentTextures = 0;
  *(_QWORD *)&this->CurrentTextures[2] = 0;
  pDeviceContext = this->pDeviceContext;
  memset(views, 0, sizeof(views));
  memset(states, 0, sizeof(states));
  pDeviceContext->PSSetSamplers(pDeviceContext, 0, 4u, states);
  this->pDeviceContext->PSSetShaderResources(this->pDeviceContext, 0, 4u, views);
}
