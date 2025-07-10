Scaleform::Render::Texture *__thiscall Scaleform::Render::RawImage::GetTexture(
        Scaleform::Render::RawImage *this,
        Scaleform::Render::TextureManager *pmanager)
{
  Scaleform::AtomicPtr<Scaleform::Render::Texture> *p_pTexture; // edi
  Scaleform::Render::TextureManagerLocks *pObject; // eax
  Scaleform::Render::TextureManager *v5; // eax
  Scaleform::Render::ImagePlane *pPlanes; // eax
  unsigned int Height; // ecx
  Scaleform::Render::Texture *(__thiscall *CreateTexture)(Scaleform::Render::TextureManager *, Scaleform::Render::ImageFormat, unsigned int, const Scaleform::Render::Size<unsigned long> *, unsigned int, Scaleform::Render::ImageBase *, struct Scaleform::Render::MemoryManager *); // edx
  unsigned int LevelCount; // eax
  LONG v11; // esi
  unsigned int v12; // [esp-10h] [ebp-24h]
  _DWORD v13[2]; // [esp+Ch] [ebp-8h] BYREF

  p_pTexture = &this->pTexture;
  if ( this->pTexture.Value )
  {
    pObject = p_pTexture->Value->pManagerLocks.pObject;
    v5 = pObject ? pObject->pManager : 0;
    if ( v5 == pmanager )
      return p_pTexture->Value;
  }
  if ( !pmanager )
    return 0;
  InterlockedExchange((volatile LONG *)&this->pTexture, 0);
  pPlanes = this->Data.pPlanes;
  Height = pPlanes->Height;
  CreateTexture = pmanager->CreateTexture;
  v13[0] = pPlanes->Width;
  v12 = this->Data.Use & 0xFFFFFF3F;
  LevelCount = this->Data.LevelCount;
  v13[1] = Height;
  v11 = (int)CreateTexture(
               pmanager,
               this->Data.Format,
               LevelCount,
               (const Scaleform::Render::Size<unsigned long> *)v13,
               v12,
               this,
               0);
  InterlockedExchange((volatile LONG *)p_pTexture, v11);
  return (Scaleform::Render::Texture *)v11;
}
