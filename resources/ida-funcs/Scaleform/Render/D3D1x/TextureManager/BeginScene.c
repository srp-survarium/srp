void __thiscall Scaleform::Render::D3D1x::TextureManager::BeginScene(Scaleform::Render::D3D1x::TextureManager *this)
{
  _BYTE v2[16]; // [esp+8h] [ebp-20h] BYREF
  _BYTE v3[16]; // [esp+18h] [ebp-10h] BYREF

  this->CurrentSamplers[0] = 0;
  this->CurrentSamplers[1] = 0;
  this->CurrentSamplers[2] = 0;
  this->CurrentSamplers[3] = 0;
  this->CurrentTextures[0] = 0;
  this->CurrentTextures[1] = 0;
  this->CurrentTextures[2] = 0;
  this->CurrentTextures[3] = 0;
  memset(v2, 0, sizeof(v2));
  memset(v3, 0, sizeof(v3));
  this->pDeviceContext->PSSetSamplers(this->pDeviceContext, 0, 4u, (ID3D11SamplerState *const *)v3);
  this->pDeviceContext->PSSetShaderResources(this->pDeviceContext, 0, 4u, (ID3D11ShaderResourceView *const *)v2);
}
