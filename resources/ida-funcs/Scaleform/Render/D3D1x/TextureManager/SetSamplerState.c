void __userpurge Scaleform::Render::D3D1x::TextureManager::SetSamplerState(
        unsigned int viewCount@<esi>,
        Scaleform::Render::D3D1x::TextureManager *this,
        unsigned int stage,
        ID3D11ShaderResourceView **views,
        ID3D11SamplerState *state)
{
  unsigned __int8 *v6; // edx
  unsigned __int8 src[64]; // [esp+4h] [ebp-4Ch] BYREF
  unsigned __int8 *dst; // [esp+44h] [ebp-Ch]
  unsigned int v9; // [esp+48h] [ebp-8h]
  char v10; // [esp+4Fh] [ebp-1h]
  char v11; // [esp+5Bh] [ebp+Bh]

  v9 = 0;
  v11 = 0;
  v10 = 0;
  if ( viewCount )
  {
    dst = (unsigned __int8 *)&this->CurrentTextures[stage];
    v6 = dst;
    memset32(src, (int)state, viewCount);
    do
    {
      if ( *((ID3D11SamplerState **)v6 - 4) != state )
        v11 = 1;
      if ( *(ID3D11ShaderResourceView **)v6 != views[v9] )
        v10 = 1;
      ++v9;
      v6 += 4;
    }
    while ( v9 < viewCount );
    if ( v11 )
    {
      this->pDeviceContext->PSSetSamplers(this->pDeviceContext, stage, viewCount, (ID3D11SamplerState *const *)src);
      memcpy((unsigned __int8 *)&this->CurrentSamplers[stage], src, 4 * viewCount);
    }
    if ( v10 )
    {
      this->pDeviceContext->PSSetShaderResources(this->pDeviceContext, stage, viewCount, views);
      memcpy(dst, (unsigned __int8 *)views, 4 * viewCount);
    }
  }
}
