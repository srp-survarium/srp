Scaleform::Render::Image *__thiscall Scaleform::GFx::ImageCreator::CreateImage(
        Scaleform::GFx::ImageCreator *this,
        const Scaleform::GFx::ImageCreateInfo *info,
        Scaleform::Render::ImageSource *source)
{
  Scaleform::Render::TextureManager *pObject; // ecx
  bool v4; // zf
  _DWORD v6[4]; // [esp+0h] [ebp-14h] BYREF
  int v7; // [esp+10h] [ebp-4h]

  pObject = this->pTextureManager.pObject;
  v6[3] = 0;
  v7 = 0;
  v4 = info->RUse == Use_FontTexture;
  v6[1] = info->pHeap;
  v6[0] = info->Use;
  v6[2] = pObject;
  if ( v4 )
    v7 = 9;
  return source->CreateCompatibleImage(source, v6);
}
