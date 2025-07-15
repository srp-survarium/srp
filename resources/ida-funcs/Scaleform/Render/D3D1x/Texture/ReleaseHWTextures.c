void __thiscall Scaleform::Render::D3D1x::Texture::ReleaseHWTextures(
        Scaleform::Render::D3D1x::Texture *this,
        bool staging)
{
  Scaleform::Render::TextureManager *pManager; // esi
  int v4; // edi
  bool v5; // zf
  char *v6; // eax
  ID3D11Resource *v7; // esi
  ID3D11Resource *v8; // ecx
  Scaleform::Render::TextureManager *v9; // esi
  ID3D11Resource *pNext; // ecx
  unsigned int TextureCount; // eax
  ID3D11Resource *v12; // [esp+Ch] [ebp-1Ch] BYREF
  ID3D11Resource *val; // [esp+10h] [ebp-18h] BYREF
  Scaleform::Render::TextureManager *v14; // [esp+14h] [ebp-14h]
  unsigned int v15; // [esp+18h] [ebp-10h]
  int v16; // [esp+1Ch] [ebp-Ch]
  ID3D11Resource *v17; // [esp+20h] [ebp-8h]
  char v18; // [esp+27h] [ebp-1h]

  Scaleform::Render::Texture::ReleaseHWTextures(this, staging);
  pManager = this->pManagerLocks.pObject->pManager;
  v4 = 0;
  v14 = pManager;
  if ( !pManager->RenderThreadId || (v18 = 0, (void *)Scaleform::GetCurrentThreadId() != pManager->RenderThreadId) )
    v18 = 1;
  v5 = this->TextureCount == 0;
  v15 = 0;
  if ( !v5 )
  {
    v16 = 0;
    do
    {
      v6 = (char *)this->pTextures + v4;
      v7 = (ID3D11Resource *)*((_DWORD *)v6 + 3);
      v8 = (ID3D11Resource *)*((_DWORD *)v6 + 2);
      v12 = v7;
      if ( staging )
        v17 = *(ID3D11Texture2D **)((char *)&this->pTextures->pStagingTexture + v4);
      else
        v17 = 0;
      if ( v8 )
      {
        if ( v18 )
        {
          v9 = v14;
          val = v8;
          Scaleform::ArrayBase<Scaleform::ArrayData<ID3D11Resource *,Scaleform::AllocatorLH<ID3D11Resource *,75>,Scaleform::ArrayConstPolicy<8,8,0>>>::PushBack(
            (Scaleform::ArrayBase<Scaleform::ArrayData<ID3D11Resource *,Scaleform::AllocatorLH<ID3D11Resource *,75>,Scaleform::ArrayConstPolicy<8,8,0> > > *)v8,
            (Scaleform::ArrayDataBase<ID3D11Resource *,Scaleform::AllocatorLH<ID3D11Resource *,75>,Scaleform::ArrayConstPolicy<8,8,0> > *)&v14[2].TextureFormats.Data.Size,
            &val);
          Scaleform::ArrayDataBase<ID3D11Resource *,Scaleform::AllocatorLH<ID3D11Resource *,75>,Scaleform::ArrayConstPolicy<8,8,0>>::ResizeNoConstruct(
            (Scaleform::ArrayDataBase<ID3D11Resource *,Scaleform::AllocatorLH<ID3D11Resource *,75>,Scaleform::ArrayConstPolicy<8,8,0> > *)&v9[2].Textures.Root.4,
            (unsigned int)&v9[2].TextureInitQueue.Root.pPrev->__vftable + 1,
            &v9[2].Textures.Root.4);
          pNext = (ID3D11Resource *)v9[2].Textures.Root.pNext;
          if ( &pNext[(int)v9[2].TextureInitQueue.Root.pPrev] != (ID3D11Resource *)4 )
          {
            pNext = v12;
            *((_DWORD *)v9[2].Textures.Root.pNext + (int)v9[2].TextureInitQueue.Root.pPrev - 1) = v12;
          }
          if ( v17 )
          {
            v12 = v17;
            Scaleform::ArrayBase<Scaleform::ArrayData<ID3D11Resource *,Scaleform::AllocatorLH<ID3D11Resource *,75>,Scaleform::ArrayConstPolicy<8,8,0>>>::PushBack(
              (Scaleform::ArrayBase<Scaleform::ArrayData<ID3D11Resource *,Scaleform::AllocatorLH<ID3D11Resource *,75>,Scaleform::ArrayConstPolicy<8,8,0> > > *)pNext,
              (Scaleform::ArrayDataBase<ID3D11Resource *,Scaleform::AllocatorLH<ID3D11Resource *,75>,Scaleform::ArrayConstPolicy<8,8,0> > *)&v14[2].TextureFormats.Data.Size,
              &v12);
          }
          v4 = v16;
        }
        else
        {
          v8->Release(v8);
          v7->Release(v7);
          if ( v17 )
            v17->Release(v17);
        }
      }
      *(ID3D11Texture2D **)((char *)&this->pTextures->pTexture + v4) = 0;
      *(ID3D11ShaderResourceView **)((char *)&this->pTextures->pView + v4) = 0;
      if ( staging )
        *(ID3D11Texture2D **)((char *)&this->pTextures->pStagingTexture + v4) = 0;
      TextureCount = this->TextureCount;
      ++v15;
      v4 += 20;
      v16 = v4;
    }
    while ( v15 < TextureCount );
  }
}
