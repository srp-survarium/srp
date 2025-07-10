void __thiscall Scaleform::Render::D3D1x::Texture::ReleaseHWTextures(
        Scaleform::Render::D3D1x::Texture *this,
        bool staging)
{
  Scaleform::Render::D3D1x::Texture *v2; // esi
  unsigned int pObject; // ecx
  Scaleform::Render::D3D1x::TextureManager *v4; // edi
  int v5; // edi
  Scaleform::Render::D3D1x::Texture::HWTextureDesc *pTextures; // edx
  ID3D11Resource *v7; // ebx
  ID3D11Texture2D *v8; // ebp
  Scaleform::ArrayDataBase<ID3D11Resource *,Scaleform::AllocatorLH<ID3D11Resource *,75>,Scaleform::ArrayConstPolicy<8,8,0> > *p_Data; // esi
  unsigned int v10; // ebp
  unsigned int v11; // eax
  ID3D11Resource **v12; // eax
  Scaleform::ArrayDataBase<ID3D11Resource *,Scaleform::AllocatorLH<ID3D11Resource *,75>,Scaleform::ArrayConstPolicy<8,8,0> > *p_D3DTexViewKillList; // edi
  unsigned int v14; // ebp
  unsigned int v15; // eax
  ID3D11ShaderResourceView **v16; // eax
  unsigned int v17; // ebp
  unsigned int v18; // eax
  ID3D11Texture2D **v19; // eax
  bool useKillList; // [esp+Bh] [ebp-19h]
  ID3D11Texture2D *pstaging; // [esp+Ch] [ebp-18h]
  int v22; // [esp+10h] [ebp-14h]
  Scaleform::Render::D3D1x::TextureManager *pmanager; // [esp+14h] [ebp-10h]
  ID3D11ShaderResourceView *pview; // [esp+18h] [ebp-Ch]
  unsigned int itex; // [esp+20h] [ebp-4h]

  v2 = this;
  Scaleform::Render::Texture::ReleaseHWTextures(this, staging);
  pObject = (unsigned int)v2->pManagerLocks.pObject;
  v4 = *(Scaleform::Render::D3D1x::TextureManager **)(pObject + 8);
  pmanager = v4;
  if ( !v4->RenderThreadId || (useKillList = 0, (void *)Scaleform::GetCurrentThreadId() != v4->RenderThreadId) )
    useKillList = 1;
  itex = 0;
  if ( v2->TextureCount )
  {
    v5 = 0;
    v22 = 0;
    do
    {
      pTextures = v2->pTextures;
      v7 = *(ID3D11Texture2D **)((char *)&pTextures->pTexture + v5);
      pview = *(ID3D11ShaderResourceView **)((char *)&pTextures->pView + v5);
      if ( staging )
      {
        pObject = (unsigned int)v2->pTextures;
        v8 = *(ID3D11Texture2D **)((char *)&pTextures->pStagingTexture + v5);
        pstaging = v8;
      }
      else
      {
        pstaging = 0;
        v8 = 0;
      }
      if ( !v7 )
        goto LABEL_37;
      if ( !useKillList )
      {
        v7->Release(v7);
        pview->Release(pview);
        if ( v8 )
          v8->Release(v8);
        goto LABEL_37;
      }
      p_Data = &pmanager->D3DTextureKillList.Data;
      v10 = pmanager->D3DTextureKillList.Data.Size + 1;
      if ( v10 >= pmanager->D3DTextureKillList.Data.Size )
      {
        if ( v10 < pmanager->D3DTextureKillList.Data.Policy.Capacity )
          goto LABEL_17;
        v11 = v10 + (v10 >> 2);
      }
      else
      {
        if ( v10 >= pmanager->D3DTextureKillList.Data.Policy.Capacity >> 1 )
          goto LABEL_17;
        v11 = pmanager->D3DTextureKillList.Data.Size + 1;
      }
      Scaleform::ArrayDataBase<ID3D11View *,Scaleform::AllocatorLH<ID3D11View *,75>,Scaleform::ArrayConstPolicy<8,8,0>>::Reserve(
        &pmanager->D3DTextureKillList.Data,
        v11,
        pObject,
        &pmanager->D3DTextureKillList);
LABEL_17:
      v12 = &p_Data->Data[v10 - 1];
      pmanager->D3DTextureKillList.Data.Size = v10;
      if ( v12 )
        *v12 = v7;
      p_D3DTexViewKillList = (Scaleform::ArrayDataBase<ID3D11Resource *,Scaleform::AllocatorLH<ID3D11Resource *,75>,Scaleform::ArrayConstPolicy<8,8,0> > *)&pmanager->D3DTexViewKillList;
      v14 = pmanager->D3DTexViewKillList.Data.Size + 1;
      if ( v14 >= pmanager->D3DTexViewKillList.Data.Size )
      {
        if ( v14 < pmanager->D3DTexViewKillList.Data.Policy.Capacity )
          goto LABEL_25;
        v15 = v14 + (v14 >> 2);
      }
      else
      {
        pObject = pmanager->D3DTexViewKillList.Data.Policy.Capacity >> 1;
        if ( v14 >= pObject )
          goto LABEL_25;
        v15 = pmanager->D3DTexViewKillList.Data.Size + 1;
      }
      Scaleform::ArrayDataBase<ID3D11View *,Scaleform::AllocatorLH<ID3D11View *,75>,Scaleform::ArrayConstPolicy<8,8,0>>::Reserve(
        p_D3DTexViewKillList,
        v15,
        pObject,
        &pmanager->D3DTexViewKillList);
LABEL_25:
      v16 = (ID3D11ShaderResourceView **)&p_D3DTexViewKillList->Data[v14 - 1];
      pmanager->D3DTexViewKillList.Data.Size = v14;
      if ( v16 )
      {
        pObject = (unsigned int)pview;
        *v16 = pview;
      }
      if ( !pstaging )
        goto LABEL_36;
      v17 = pmanager->D3DTextureKillList.Data.Size + 1;
      if ( v17 >= pmanager->D3DTextureKillList.Data.Size )
      {
        if ( v17 < pmanager->D3DTextureKillList.Data.Policy.Capacity )
          goto LABEL_34;
        v18 = v17 + (v17 >> 2);
      }
      else
      {
        if ( v17 >= pmanager->D3DTextureKillList.Data.Policy.Capacity >> 1 )
          goto LABEL_34;
        v18 = pmanager->D3DTextureKillList.Data.Size + 1;
      }
      Scaleform::ArrayDataBase<ID3D11View *,Scaleform::AllocatorLH<ID3D11View *,75>,Scaleform::ArrayConstPolicy<8,8,0>>::Reserve(
        p_Data,
        v18,
        pObject,
        p_Data);
LABEL_34:
      v19 = (ID3D11Texture2D **)&p_Data->Data[v17 - 1];
      pmanager->D3DTextureKillList.Data.Size = v17;
      if ( v19 )
        *v19 = pstaging;
LABEL_36:
      v5 = v22;
      v2 = this;
LABEL_37:
      *(ID3D11Texture2D **)((char *)&v2->pTextures->pTexture + v5) = 0;
      *(ID3D11ShaderResourceView **)((char *)&v2->pTextures->pView + v5) = 0;
      if ( staging )
        *(ID3D11Texture2D **)((char *)&v2->pTextures->pStagingTexture + v5) = 0;
      pObject = v2->TextureCount;
      v5 += 20;
      ++itex;
      v22 = v5;
    }
    while ( itex < pObject );
  }
}
