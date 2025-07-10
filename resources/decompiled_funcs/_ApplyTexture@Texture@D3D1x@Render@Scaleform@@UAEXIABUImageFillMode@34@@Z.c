void __thiscall Scaleform::Render::D3D1x::Texture::ApplyTexture(
        Scaleform::Render::D3D1x::Texture *this,
        unsigned int stageIndex,
        const Scaleform::Render::ImageFillMode *fm)
{
  unsigned int TextureCount; // esi
  Scaleform::Render::D3D1x::TextureManager *pManager; // ecx
  ID3D11SamplerState *v6; // edx
  unsigned int v7; // eax
  ID3D11ShaderResourceView **p_pView; // edi
  ID3D11ShaderResourceView *views[4]; // [esp+Ch] [ebp-10h] BYREF

  Scaleform::Render::Texture::ApplyTexture(this, stageIndex, fm);
  TextureCount = this->TextureCount;
  pManager = (Scaleform::Render::D3D1x::TextureManager *)this->pManagerLocks.pObject->pManager;
  v6 = pManager->SamplerStates[fm->Fill];
  v7 = 0;
  if ( this->TextureCount )
  {
    p_pView = &this->pTextures->pView;
    do
    {
      views[v7++] = *p_pView;
      p_pView += 5;
    }
    while ( v7 < TextureCount );
  }
  Scaleform::Render::D3D1x::TextureManager::SetSamplerState(TextureCount, pManager, stageIndex, views, v6);
}
