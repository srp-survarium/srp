void __thiscall Scaleform::Render::D3D1x::MappedTexture::Unmap(
        Scaleform::Render::D3D1x::MappedTexture *this,
        bool applyUpdate)
{
  Scaleform::Render::Texture *pTexture; // edi
  volatile int RefCount; // eax
  char *v5; // edi
  bool v6; // cc
  Scaleform::Render::ImagePlane pplane; // [esp+Ch] [ebp-30h] BYREF
  Scaleform::Render::Texture *v8; // [esp+20h] [ebp-1Ch]
  unsigned int TextureCount; // [esp+24h] [ebp-18h]
  int v10; // [esp+28h] [ebp-14h]
  unsigned int index; // [esp+2Ch] [ebp-10h]
  unsigned int v12; // [esp+30h] [ebp-Ch]
  volatile int v13; // [esp+34h] [ebp-8h]
  int v14; // [esp+38h] [ebp-4h]

  pTexture = this->pTexture;
  RefCount = pTexture->pManagerLocks.pObject->pManager[1].RefCount;
  v8 = pTexture;
  v13 = RefCount;
  if ( RefCount )
  {
    (*(void (__stdcall **)(volatile int))(*(_DWORD *)RefCount + 4))(RefCount);
    RefCount = v13;
  }
  TextureCount = this->pTexture->TextureCount;
  v12 = 0;
  if ( TextureCount )
  {
    v10 = 0;
    while ( 1 )
    {
      v5 = (char *)pTexture[1].__vftable + v10;
      v6 = this->LevelCount <= 0;
      memset(&pplane, 0, sizeof(pplane));
      v14 = 0;
      if ( !v6 )
      {
        do
          (*(void (__stdcall **)(volatile int, _DWORD, int))(*(_DWORD *)v13 + 60))(v13, *((_DWORD *)v5 + 4), v14++);
        while ( v14 < this->LevelCount );
      }
      if ( applyUpdate )
      {
        v6 = this->LevelCount <= 0;
        v14 = 0;
        if ( !v6 )
        {
          index = v12;
          do
          {
            Scaleform::Render::ImageData::GetPlane(&this->Data, index, &pplane);
            if ( pplane.pData )
            {
              (*(void (__stdcall **)(volatile int, _DWORD, unsigned int, _DWORD, _DWORD, _DWORD, _DWORD, int, _DWORD))(*(_DWORD *)v13 + 184))(
                v13,
                *((_DWORD *)v5 + 2),
                v14 + this->StartMipLevel,
                0,
                0,
                0,
                *((_DWORD *)v5 + 4),
                v14,
                0);
              pplane.pData = 0;
            }
            ++v14;
            index += TextureCount;
          }
          while ( v14 < this->LevelCount );
        }
      }
      ++v12;
      v10 += 20;
      if ( v12 >= TextureCount )
        break;
      pTexture = v8;
    }
    RefCount = v13;
  }
  this->pTexture->pMap = 0;
  this->pTexture = 0;
  this->StartMipLevel = 0;
  this->LevelCount = 0;
  if ( RefCount )
    (*(void (__stdcall **)(volatile int))(*(_DWORD *)RefCount + 8))(RefCount);
}
