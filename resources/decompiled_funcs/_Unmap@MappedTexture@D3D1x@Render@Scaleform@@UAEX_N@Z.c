void __thiscall Scaleform::Render::D3D1x::MappedTexture::Unmap(
        Scaleform::Render::D3D1x::MappedTexture *this,
        bool applyUpdate)
{
  Scaleform::Render::Texture *pTexture; // ebp
  volatile int RefCount; // ebx
  int v5; // edi
  char *v6; // ebp
  bool v7; // cc
  int v8; // edi
  unsigned int index; // [esp+34h] [ebp-28h]
  unsigned int itex; // [esp+38h] [ebp-24h]
  int v11; // [esp+3Ch] [ebp-20h]
  unsigned int textureCount; // [esp+40h] [ebp-1Ch]
  Scaleform::Render::D3D1x::Texture *d3dTexture; // [esp+44h] [ebp-18h]
  Scaleform::Render::ImagePlane plane; // [esp+48h] [ebp-14h] BYREF

  pTexture = this->pTexture;
  RefCount = pTexture->pManagerLocks.pObject->pManager[1].RefCount;
  v5 = 0;
  d3dTexture = (Scaleform::Render::D3D1x::Texture *)pTexture;
  if ( RefCount )
    (*(void (__stdcall **)(volatile int))(*(_DWORD *)RefCount + 4))(RefCount);
  textureCount = this->pTexture->TextureCount;
  itex = 0;
  if ( this->pTexture->TextureCount )
  {
    v11 = 0;
    while ( 1 )
    {
      v6 = (char *)pTexture[1].__vftable + v11;
      v7 = this->LevelCount <= 0;
      memset(&plane, 0, sizeof(plane));
      if ( !v7 )
      {
        do
          (*(void (__stdcall **)(volatile int, _DWORD, int))(*(_DWORD *)RefCount + 60))(
            RefCount,
            *((_DWORD *)v6 + 4),
            v5++);
        while ( v5 < this->LevelCount );
      }
      if ( applyUpdate )
      {
        v8 = 0;
        if ( this->LevelCount > 0 )
        {
          index = itex;
          do
          {
            Scaleform::Render::ImageData::GetPlane(&this->Data, index, &plane);
            if ( plane.pData )
            {
              (*(void (__stdcall **)(volatile int, _DWORD, unsigned int, _DWORD, _DWORD, _DWORD, _DWORD, int, _DWORD))(*(_DWORD *)RefCount + 184))(
                RefCount,
                *((_DWORD *)v6 + 2),
                v8 + this->StartMipLevel,
                0,
                0,
                0,
                *((_DWORD *)v6 + 4),
                v8,
                0);
              plane.pData = 0;
            }
            index += textureCount;
            ++v8;
          }
          while ( v8 < this->LevelCount );
        }
      }
      v11 += 20;
      v5 = 0;
      if ( ++itex >= textureCount )
        break;
      pTexture = d3dTexture;
    }
  }
  this->pTexture->pMap = 0;
  this->pTexture = 0;
  this->StartMipLevel = 0;
  this->LevelCount = 0;
  if ( RefCount )
    (*(void (__stdcall **)(volatile int))(*(_DWORD *)RefCount + 8))(RefCount);
}
