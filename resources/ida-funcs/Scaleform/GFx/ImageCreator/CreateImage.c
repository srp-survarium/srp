Scaleform::Render::Image *__thiscall Scaleform::GFx::ImageCreator::CreateImage(
        Scaleform::GFx::ImageCreator *this,
        const Scaleform::GFx::ImageCreateInfo *info,
        Scaleform::Render::ImageSource *source)
{
  Scaleform::Render::TextureManager *pObject; // ecx
  bool v4; // zf
  Scaleform::Render::ImageCreateArgs args; // [esp+0h] [ebp-14h] BYREF

  pObject = this->pTextureManager.pObject;
  args.pUpdateSync = 0;
  args.Format = Image_None;
  v4 = info->RUse == Use_FontTexture;
  args.pHeap = info->pHeap;
  args.Use = info->Use;
  args.pManager = pObject;
  if ( v4 )
    args.Format = Image_A8;
  return source->CreateCompatibleImage(source, &args);
}
