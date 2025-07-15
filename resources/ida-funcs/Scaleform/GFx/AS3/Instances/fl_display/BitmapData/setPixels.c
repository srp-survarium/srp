void __thiscall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::setPixels(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *rect,
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *inputByteArray)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v6; // eax
  int y1; // eax
  Scaleform::GFx::ASStringNode *v8; // ecx
  Scaleform::GFx::AS3::VM *v9; // esi
  const Scaleform::GFx::AS3::VM::Error *v10; // eax
  int v11; // eax
  Scaleform::GFx::AS3::VM *v12; // esi
  const Scaleform::GFx::AS3::VM::Error *v13; // eax
  Scaleform::Render::DrawableImage *DrawableImageFromBitmapData; // edi
  const Scaleform::Render::Rect<long> *v15; // eax
  Scaleform::GFx::AS3::VM *v16; // esi
  const Scaleform::GFx::AS3::VM::Error *v17; // eax
  Scaleform::GFx::ASStringNode *v18; // eax
  Scaleform::GFx::AS3::AS3ByteArray_DIPixelProvider pixelProvider; // [esp+4h] [ebp-18h] BYREF
  Scaleform::Render::Rect<long> v20; // [esp+Ch] [ebp-10h] BYREF

  if ( !this->pImage.pObject )
  {
    pVM = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&v20, eArgumentError, pVM);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(pVM, v6);
    y1 = v20.y1;
    --*(_DWORD *)(v20.y1 + 12);
    v8 = (Scaleform::GFx::ASStringNode *)y1;
    if ( *(_DWORD *)(y1 + 12) )
      return;
    goto LABEL_3;
  }
  if ( rect )
  {
    if ( inputByteArray )
    {
      pixelProvider.__vftable = (Scaleform::GFx::AS3::AS3ByteArray_DIPixelProvider_vtbl *)&Scaleform::GFx::AS3::AS3ByteArray_DIPixelProvider::`vftable';
      pixelProvider.PixelArray = inputByteArray;
      DrawableImageFromBitmapData = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                      this,
                                      this);
      v15 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::RectangleToRect(this, &v20, rect);
      if ( Scaleform::Render::DrawableImage::SetPixels(DrawableImageFromBitmapData, v15, &pixelProvider)
        || inputByteArray->Length >= pixelProvider.PixelArray->Length )
      {
        return;
      }
      v16 = this->pTraits.pObject->pVM;
      Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&v20, eEOFError, v16);
      Scaleform::GFx::AS3::VM::ThrowError(v16, v17);
    }
    else
    {
      v12 = this->pTraits.pObject->pVM;
      Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&v20, eNullPointerError, v12);
      Scaleform::GFx::AS3::VM::ThrowArgumentError(v12, v13);
    }
    v18 = (Scaleform::GFx::ASStringNode *)v20.y1;
    --*(_DWORD *)(v20.y1 + 12);
    if ( !v18->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v18);
    return;
  }
  v9 = this->pTraits.pObject->pVM;
  Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&v20, eNullPointerError, v9);
  Scaleform::GFx::AS3::VM::ThrowArgumentError(v9, v10);
  v11 = v20.y1;
  --*(_DWORD *)(v20.y1 + 12);
  v8 = (Scaleform::GFx::ASStringNode *)v11;
  if ( !*(_DWORD *)(v11 + 12) )
LABEL_3:
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
}
