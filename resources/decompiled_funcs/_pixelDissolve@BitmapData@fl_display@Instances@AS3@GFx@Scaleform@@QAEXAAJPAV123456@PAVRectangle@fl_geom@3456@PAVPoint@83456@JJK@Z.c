void __thiscall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::pixelDissolve(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        int *result,
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *sourceBitmapData,
        Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *sourceRect,
        Scaleform::GFx::AS3::Instances::fl_geom::Point *destPoint,
        unsigned int randomSeed,
        int numPixels,
        unsigned int fillColor)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v10; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v12; // ecx
  Scaleform::GFx::AS3::VM *v13; // esi
  const Scaleform::GFx::AS3::VM::Error *v14; // eax
  Scaleform::GFx::ASStringNode *v15; // eax
  Scaleform::Render::DrawableImage *DrawableImageFromBitmapData; // edi
  Scaleform::Render::DrawableImage *v17; // ebx
  const Scaleform::Render::Rect<long> *v18; // eax
  const Scaleform::Render::Point<long> *v19; // [esp-10h] [ebp-38h]
  Scaleform::GFx::AS3::VM::Error v20; // [esp+10h] [ebp-18h] BYREF
  Scaleform::Render::Rect<long> v21; // [esp+18h] [ebp-10h] BYREF

  if ( !this->pImage.pObject )
  {
    pVM = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v20, eArgumentError, pVM);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(pVM, v10);
    pNode = v20.Message.pNode;
    --v20.Message.pNode->RefCount;
    v12 = pNode;
    if ( pNode->RefCount )
      return;
    goto LABEL_3;
  }
  if ( !sourceBitmapData )
  {
    v13 = this->pTraits.pObject->pVM;
LABEL_6:
    Scaleform::GFx::AS3::VM::Error::Error(&v20, eNullPointerError, v13);
    goto LABEL_7;
  }
  if ( !sourceRect )
  {
    v13 = this->pTraits.pObject->pVM;
    goto LABEL_6;
  }
  if ( !destPoint )
  {
    v13 = this->pTraits.pObject->pVM;
    goto LABEL_6;
  }
  if ( numPixels >= 0 )
  {
    DrawableImageFromBitmapData = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                    this,
                                    this);
    v17 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(this, sourceBitmapData);
    v19 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::PointToPoint(
            this,
            (Scaleform::Render::Point<long> *)&v20,
            destPoint);
    v18 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::RectangleToRect(this, &v21, sourceRect);
    *result = Scaleform::Render::DrawableImage::PixelDissolve(
                DrawableImageFromBitmapData,
                v17,
                v18,
                v19,
                randomSeed,
                numPixels,
                (Scaleform::Render::Color)fillColor);
    return;
  }
  v13 = this->pTraits.pObject->pVM;
  Scaleform::GFx::AS3::VM::Error::Error(&v20, eMustBeNonNegative, v13);
LABEL_7:
  Scaleform::GFx::AS3::VM::ThrowArgumentError(v13, v14);
  v15 = v20.Message.pNode;
  --v20.Message.pNode->RefCount;
  v12 = v15;
  if ( !v15->RefCount )
LABEL_3:
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
}
