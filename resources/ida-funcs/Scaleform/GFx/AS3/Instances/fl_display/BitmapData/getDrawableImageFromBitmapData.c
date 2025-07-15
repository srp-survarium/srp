Scaleform::Render::DrawableImage *__thiscall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *sourceBitmapData)
{
  Scaleform::GFx::Resource *DrawableImageContext; // ebx
  Scaleform::Render::DrawableImage *v5; // eax
  Scaleform::Render::ImageBase *v6; // eax
  Scaleform::Render::ImageBase *v7; // esi
  Scaleform::Render::ImageBase *pObject; // ecx

  if ( !sourceBitmapData )
    return 0;
  if ( sourceBitmapData->pImage.pObject->GetImageType(sourceBitmapData->pImage.pObject) != Type_DrawableImage )
  {
    DrawableImageContext = (Scaleform::GFx::Resource *)Scaleform::GFx::MovieImpl::GetDrawableImageContext((Scaleform::GFx::MovieImpl *)this->pTraits.pObject->pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM);
    v5 = (Scaleform::Render::DrawableImage *)Scaleform::Memory::pGlobalHeap->Alloc(
                                               Scaleform::Memory::pGlobalHeap,
                                               120,
                                               0);
    if ( v5 )
    {
      Scaleform::Render::DrawableImage::DrawableImage(
        v5,
        this->Transparent,
        sourceBitmapData->pImage.pObject,
        DrawableImageContext);
      v7 = v6;
    }
    else
    {
      v7 = 0;
    }
    pObject = sourceBitmapData->pImage.pObject;
    if ( pObject )
      pObject->Release(pObject);
    sourceBitmapData->pImage.pObject = v7;
  }
  return (Scaleform::Render::DrawableImage *)sourceBitmapData->pImage.pObject;
}
