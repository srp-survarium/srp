void __thiscall Scaleform::Render::DICommand_CreateTexture::ExecuteHW(
        Scaleform::Render::DICommand_CreateTexture *this,
        Scaleform::Render::DICommandContext *context)
{
  Scaleform::Render::TextureManager *v3; // eax

  v3 = context->pHAL->GetTextureManager(context->pHAL);
  Scaleform::Render::DrawableImage::createTextureFromManager(this->pImage.pObject, context->pHAL, v3);
}
