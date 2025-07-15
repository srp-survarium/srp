void __userpurge Scaleform::Render::D3D1x::TextureManager::SetSamplerState(
        unsigned int viewCount@<esi>,
        Scaleform::Render::D3D1x::TextureManager *this,
        unsigned int stage,
        ID3D11ShaderResourceView **views,
        ID3D11SamplerState *state)
{
  unsigned int v6; // edx
  ID3D11ShaderResourceView **v7; // ebp
  bool loadTextures; // [esp+1Fh] [ebp-45h]
  ID3D11SamplerState *states[16]; // [esp+24h] [ebp-40h] BYREF
  char loadSamplers; // [esp+6Ch] [ebp+8h]

  v6 = 0;
  loadSamplers = 0;
  loadTextures = 0;
  if ( viewCount )
  {
    v7 = (ID3D11ShaderResourceView **)&this->CurrentTextures[stage];
    memset32(states, (int)state, viewCount);
    do
    {
      if ( *(v7 - 4) != (ID3D11ShaderResourceView *)state )
        loadSamplers = 1;
      if ( *v7 != views[v6] )
        loadTextures = 1;
      ++v6;
      ++v7;
    }
    while ( v6 < viewCount );
    if ( loadSamplers )
    {
      this->pDeviceContext->PSSetSamplers(this->pDeviceContext, stage, viewCount, states);
      memcpy((unsigned __int8 *)&this->CurrentSamplers[stage], (unsigned __int8 *)states, 4 * viewCount);
    }
    if ( loadTextures )
    {
      this->pDeviceContext->PSSetShaderResources(this->pDeviceContext, stage, viewCount, views);
      memcpy((unsigned __int8 *)&this->CurrentTextures[stage], (unsigned __int8 *)views, 4 * viewCount);
    }
  }
}
