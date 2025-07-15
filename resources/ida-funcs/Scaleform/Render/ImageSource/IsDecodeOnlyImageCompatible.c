bool __thiscall Scaleform::Render::ImageSource::IsDecodeOnlyImageCompatible(
        Scaleform::Render::ImageSource *this,
        const Scaleform::Render::ImageCreateArgs *args)
{
  Scaleform::Render::TextureManager_vtbl *v2; // edi
  Scaleform::Render::ImageFormat v3; // eax
  __int16 v4; // ax
  bool result; // al

  result = (!args->pManager
         || (v2 = args->pManager->__vftable,
             v3 = this->GetFormat(this),
             v4 = v2->GetTextureUseCaps(args->pManager, v3),
             (args->Use & (unsigned __int8)~(_BYTE)v4 & 0xC0) != 0)
         || (v4 & 0x100) == 0
         || args->pManager->pTextureCache.pObject)
        && (args->Use & 0xC0) == 0;
  return result;
}
