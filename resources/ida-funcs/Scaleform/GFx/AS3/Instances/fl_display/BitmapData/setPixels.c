void __thiscall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::setPixels(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *rect,
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *inputByteArray)
{
  const Scaleform::GFx::AS3::VM::Error *v5; // eax
  const Scaleform::GFx::AS3::VM::Error *v6; // eax
  const Scaleform::GFx::AS3::VM::Error *v7; // eax
  Scaleform::Render::DrawableImage *DrawableImageFromBitmapData; // edi
  const Scaleform::Render::Rect<long> *v9; // eax
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v11; // eax
  Scaleform::GFx::ASStringNode *y1; // eax
  Scaleform::StringDataPtr v13; // [esp-8h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::AS3ByteArray_DIPixelProvider pixelProvider; // [esp+10h] [ebp-18h] BYREF
  Scaleform::Render::Rect<long> v15; // [esp+18h] [ebp-10h] BYREF

  if ( !this->pImage.pObject )
  {
    v13.pStr = "Invalid BitmapData";
    v13.Size = 18;
    Scaleform::GFx::AS3::VM::Error::Error(
      (Scaleform::GFx::AS3::VM::Error *)&v15,
      eArgumentError,
      this->pTraits.pObject->pVM,
      v13);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(this->pTraits.pObject->pVM, v5);
    goto LABEL_10;
  }
  if ( !rect )
  {
    v13.pStr = "rect";
    v13.Size = 4;
    Scaleform::GFx::AS3::VM::Error::Error(
      (Scaleform::GFx::AS3::VM::Error *)&v15,
      eNullPointerError,
      this->pTraits.pObject->pVM,
      v13);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(this->pTraits.pObject->pVM, v6);
    goto LABEL_10;
  }
  if ( !inputByteArray )
  {
    v13.pStr = "inputByteArray";
    v13.Size = 14;
    Scaleform::GFx::AS3::VM::Error::Error(
      (Scaleform::GFx::AS3::VM::Error *)&v15,
      eNullPointerError,
      this->pTraits.pObject->pVM,
      v13);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(this->pTraits.pObject->pVM, v7);
    goto LABEL_10;
  }
  pixelProvider.__vftable = (Scaleform::GFx::AS3::AS3ByteArray_DIPixelProvider_vtbl *)&Scaleform::GFx::AS3::AS3ByteArray_DIPixelProvider::`vftable';
  pixelProvider.PixelArray = inputByteArray;
  DrawableImageFromBitmapData = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                  this,
                                  this);
  v9 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::RectangleToRect(this, &v15, rect);
  if ( !Scaleform::Render::DrawableImage::SetPixels(DrawableImageFromBitmapData, v9, &pixelProvider)
    && inputByteArray->Length < pixelProvider.PixelArray->Length )
  {
    pVM = this->pTraits.pObject->pVM;
    Scaleform::StringDataPtr::StringDataPtr(&v13, "EOF");
    Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&v15, eEOFError, pVM, v13);
    Scaleform::GFx::AS3::VM::ThrowError(pVM, v11);
LABEL_10:
    y1 = (Scaleform::GFx::ASStringNode *)v15.y1;
    --*(_DWORD *)(v15.y1 + 12);
    if ( !y1->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(y1);
  }
}
