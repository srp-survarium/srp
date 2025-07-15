void __thiscall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::setVector(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *rect,
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *inputVector)
{
  const Scaleform::GFx::AS3::VM::Error *v5; // eax
  const Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *v6; // ebp
  const Scaleform::GFx::AS3::VM::Error *v7; // eax
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *v8; // ebx
  const Scaleform::GFx::AS3::VM::Error *v9; // eax
  Scaleform::Render::DrawableImage *DrawableImageFromBitmapData; // edi
  const Scaleform::Render::Rect<long> *v11; // eax
  Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *v12; // edi
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v14; // eax
  Scaleform::GFx::ASStringNode *y1; // eax
  Scaleform::StringDataPtr v16; // [esp-8h] [ebp-34h] BYREF
  Scaleform::Render::Rect<long> v17; // [esp+10h] [ebp-1Ch] BYREF
  Scaleform::GFx::AS3::AS3Vectoruint_DIPixelProvider pixelProvider; // [esp+20h] [ebp-Ch] BYREF

  if ( !this->pImage.pObject )
  {
    v16.pStr = "Invalid BitmapData";
    v16.Size = 18;
    Scaleform::GFx::AS3::VM::Error::Error(
      (Scaleform::GFx::AS3::VM::Error *)&v17,
      eArgumentError,
      this->pTraits.pObject->pVM,
      v16);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(this->pTraits.pObject->pVM, v5);
    goto LABEL_10;
  }
  v6 = rect;
  if ( !rect )
  {
    v16.pStr = "rect";
    v16.Size = 4;
    Scaleform::GFx::AS3::VM::Error::Error(
      (Scaleform::GFx::AS3::VM::Error *)&v17,
      eNullPointerError,
      this->pTraits.pObject->pVM,
      v16);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(this->pTraits.pObject->pVM, v7);
    goto LABEL_10;
  }
  v8 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *)inputVector;
  if ( !inputVector )
  {
    v16.pStr = "inputVector";
    v16.Size = 11;
    Scaleform::GFx::AS3::VM::Error::Error(
      (Scaleform::GFx::AS3::VM::Error *)&v17,
      eNullPointerError,
      this->pTraits.pObject->pVM,
      v16);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(this->pTraits.pObject->pVM, v9);
    goto LABEL_10;
  }
  pixelProvider.__vftable = (Scaleform::GFx::AS3::AS3Vectoruint_DIPixelProvider_vtbl *)&Scaleform::GFx::AS3::AS3Vectoruint_DIPixelProvider::`vftable';
  pixelProvider.Location = 0;
  pixelProvider.PixelVector = inputVector;
  DrawableImageFromBitmapData = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                  this,
                                  this);
  v11 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::RectangleToRect(this, &v17, v6);
  if ( !Scaleform::Render::DrawableImage::SetPixels(DrawableImageFromBitmapData, v11, &pixelProvider) )
  {
    Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint::lengthGet(v8, (unsigned int *)&rect);
    v12 = rect;
    Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint::lengthGet(
      (Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *)pixelProvider.PixelVector,
      (unsigned int *)&inputVector);
    if ( v12 < (Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *)inputVector )
    {
      pVM = this->pTraits.pObject->pVM;
      Scaleform::StringDataPtr::StringDataPtr(&v16, "inputVector not large enough to read all the pixel data.");
      Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&v17, eInvalidRangeError, pVM, v16);
      Scaleform::GFx::AS3::VM::ThrowError(pVM, v14);
LABEL_10:
      y1 = (Scaleform::GFx::ASStringNode *)v17.y1;
      --*(_DWORD *)(v17.y1 + 12);
      if ( !y1->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(y1);
    }
  }
}
