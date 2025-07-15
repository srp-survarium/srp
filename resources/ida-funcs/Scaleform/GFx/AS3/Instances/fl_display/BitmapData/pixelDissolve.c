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
  unsigned int v9; // eax
  Scaleform::GFx::AS3::VM *pVM; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  unsigned int v12; // eax
  Scaleform::GFx::AS3::VM *v13; // esi
  Scaleform::GFx::AS3::VM *v14; // esi
  Scaleform::Render::DrawableImage *DrawableImageFromBitmapData; // edi
  Scaleform::Render::DrawableImage *v16; // ebx
  const Scaleform::Render::Rect<long> *v17; // eax
  const Scaleform::Render::Point<long> *v18; // [esp-10h] [ebp-38h]
  Scaleform::StringDataPtr v19[3]; // [esp-8h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::VM::Error v20; // [esp+10h] [ebp-18h] BYREF
  Scaleform::Render::Rect<long> v21; // [esp+18h] [ebp-10h] BYREF

  if ( !this->pImage.pObject )
  {
    v19[0].pStr = "Invalid BitmapData";
    v19[0].Size = 18;
    Scaleform::GFx::AS3::VM::Error::Error(&v20, eArgumentError, this->pTraits.pObject->pVM, v19[0]);
    pVM = this->pTraits.pObject->pVM;
LABEL_3:
    v19[0].Size = v9;
    goto LABEL_4;
  }
  if ( sourceBitmapData )
  {
    if ( sourceRect )
    {
      if ( destPoint )
      {
        if ( numPixels >= 0 )
        {
          DrawableImageFromBitmapData = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                          this,
                                          this);
          v16 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                  this,
                  sourceBitmapData);
          v18 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::PointToPoint(
                  this,
                  (Scaleform::Render::Point<long> *)&v20,
                  destPoint);
          v17 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::RectangleToRect(this, &v21, sourceRect);
          *result = Scaleform::Render::DrawableImage::PixelDissolve(
                      DrawableImageFromBitmapData,
                      v16,
                      v17,
                      v18,
                      randomSeed,
                      numPixels,
                      (Scaleform::Render::Color)fillColor);
          return;
        }
        v14 = this->pTraits.pObject->pVM;
        Scaleform::StringDataPtr::StringDataPtr(v19, "numPixels");
        Scaleform::GFx::AS3::VM::Error::Error(&v20, eMustBeNonNegative, v14, v19[0]);
        pVM = v14;
      }
      else
      {
        v13 = this->pTraits.pObject->pVM;
        Scaleform::StringDataPtr::StringDataPtr(v19, "destPoint");
        Scaleform::GFx::AS3::VM::Error::Error(&v20, eNullPointerError, v13, v19[0]);
        pVM = v13;
      }
    }
    else
    {
      v19[0].pStr = "sourceRect";
      v19[0].Size = 10;
      Scaleform::GFx::AS3::VM::Error::Error(&v20, eNullPointerError, this->pTraits.pObject->pVM, v19[0]);
      pVM = this->pTraits.pObject->pVM;
    }
    goto LABEL_3;
  }
  v19[0].pStr = "sourceBitmapData";
  v19[0].Size = 16;
  Scaleform::GFx::AS3::VM::Error::Error(&v20, eNullPointerError, this->pTraits.pObject->pVM, v19[0]);
  v19[0].Size = v12;
  pVM = this->pTraits.pObject->pVM;
LABEL_4:
  Scaleform::GFx::AS3::VM::ThrowArgumentError(pVM, (const Scaleform::GFx::AS3::VM::Error *)v19[0].Size);
  pNode = v20.Message.pNode;
  --v20.Message.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}
