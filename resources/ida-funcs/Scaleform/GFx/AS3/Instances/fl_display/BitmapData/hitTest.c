void __thiscall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::hitTest(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        bool *result,
        Scaleform::GFx::AS3::Instances::fl_geom::Point *firstPoint,
        unsigned int firstAlphaThreshold,
        const Scaleform::GFx::AS3::Value *secondObject,
        Scaleform::GFx::AS3::Instances::fl_geom::Point *secondBitmapDataPoint,
        unsigned int secondAlphaThreshold)
{
  const Scaleform::GFx::AS3::VM::Error *v8; // eax
  Scaleform::GFx::AS3::VM *pVM; // ecx
  Scaleform::Render::DrawableImage *DrawableImageFromBitmapData; // eax
  long double x; // st7
  int v12; // eax
  long double y; // st7
  Scaleform::GFx::AS3::Traits *pObject; // edx
  double *VInt; // edi
  double v16; // st7
  double v17; // st6
  double v18; // st5
  double v19; // st4
  Scaleform::GFx::AS3::Value::V1U v20; // edi
  int v21; // esi
  unsigned int v22; // eax
  Scaleform::GFx::AS3::Traits *v23; // eax
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v24; // ecx
  Scaleform::GFx::ImageResource *ImageResource; // eax
  Scaleform::Render::DrawableImage *pImage; // eax
  Scaleform::Render::Point<long> *v27; // eax
  int v28; // ecx
  Scaleform::GFx::AS3::VM *v29; // esi
  Scaleform::GFx::ASStringNode *v30; // eax
  Scaleform::StringDataPtr v31; // [esp-8h] [ebp-38h] BYREF
  Scaleform::Render::DrawableImage *image; // [esp+8h] [ebp-28h] BYREF
  Scaleform::GFx::ASStringNode *v33; // [esp+Ch] [ebp-24h]
  Scaleform::Render::Point<long> v34; // [esp+10h] [ebp-20h] BYREF
  Scaleform::Render::Point<long> fp; // [esp+18h] [ebp-18h] BYREF
  Scaleform::Render::Rect<long> rect; // [esp+20h] [ebp-10h] BYREF

  if ( !this->pImage.pObject )
  {
    v31.pStr = "Invalid BitmapData";
    v31.Size = 18;
    Scaleform::GFx::AS3::VM::Error::Error(
      (Scaleform::GFx::AS3::VM::Error *)&image,
      eArgumentError,
      this->pTraits.pObject->pVM,
      v31);
    pVM = this->pTraits.pObject->pVM;
    goto LABEL_20;
  }
  DrawableImageFromBitmapData = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                  this,
                                  this);
  x = firstPoint->x;
  image = DrawableImageFromBitmapData;
  v12 = (int)x;
  y = firstPoint->y;
  fp.x = v12;
  pObject = this->pTraits.pObject;
  fp.y = (int)y;
  if ( Scaleform::GFx::AS3::VM::IsOfType(
         pObject->pVM,
         secondObject,
         "flash.geom.Rectangle",
         pObject->pVM->CurrentDomain) )
  {
    VInt = (double *)secondObject->value.VS._1.VInt;
    v16 = VInt[7];
    v17 = VInt[4];
    v18 = VInt[6];
    v19 = VInt[5];
    rect.x1 = (int)v18;
    rect.y1 = (int)v16;
    rect.x2 = (int)(v18 + v19);
    rect.y2 = (int)(v16 + v17);
    *result = Scaleform::Render::DrawableImage::HitTest(image, &fp, &rect, firstAlphaThreshold);
    return;
  }
  if ( !Scaleform::GFx::AS3::VM::IsOfType(
          this->pTraits.pObject->pVM,
          secondObject,
          "flash.geom.Point",
          this->pTraits.pObject->pVM->CurrentDomain) )
  {
    v23 = this->pTraits.pObject;
    v34.x = 0;
    v34.y = 0;
    if ( Scaleform::GFx::AS3::VM::IsOfType(v23->pVM, secondObject, "flash.display.Bitmap", v23->pVM->CurrentDomain) )
    {
      v24 = *(Scaleform::GFx::AS3::Instances::fl_display::BitmapData **)(secondObject->value.VS._1.VInt + 56);
      if ( !v24 )
        return;
      ImageResource = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::GetImageResource(v24);
      if ( !ImageResource )
        return;
      pImage = (Scaleform::Render::DrawableImage *)ImageResource->pImage;
      if ( !pImage )
        return;
    }
    else
    {
      if ( !Scaleform::GFx::AS3::VM::IsOfType(
              this->pTraits.pObject->pVM,
              secondObject,
              "flash.display.BitmapData",
              this->pTraits.pObject->pVM->CurrentDomain) )
      {
        v29 = this->pTraits.pObject->pVM;
        Scaleform::StringDataPtr::StringDataPtr(&v31, "secondObject");
        Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&image, eInvalidArgumentError, v29, v31);
        pVM = v29;
LABEL_20:
        Scaleform::GFx::AS3::VM::ThrowArgumentError(pVM, v8);
        v30 = v33;
        --v33->RefCount;
        if ( !v30->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v30);
        return;
      }
      if ( secondBitmapDataPoint )
      {
        v27 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::PointToPoint(
                this,
                (Scaleform::Render::Point<long> *)&rect,
                secondBitmapDataPoint);
        v28 = v27->y;
        v34.x = v27->x;
        v34.y = v28;
      }
      pImage = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                 this,
                 (Scaleform::GFx::AS3::Instances::fl_display::BitmapData *)secondObject->value.VS._1.VInt);
    }
    *result = Scaleform::Render::DrawableImage::HitTest(
                image,
                pImage,
                &fp,
                &v34,
                firstAlphaThreshold,
                secondAlphaThreshold);
    return;
  }
  v20 = secondObject->value.VS._1;
  v21 = (int)*(double *)(v20.VInt + 40);
  rect.x1 = (int)*(double *)(v20.VInt + 32);
  rect.x2 = rect.x1 + 1;
  v22 = firstAlphaThreshold;
  rect.y1 = v21;
  rect.y2 = v21 + 1;
  if ( !firstAlphaThreshold )
    v22 = 1;
  *result = Scaleform::Render::DrawableImage::HitTest(image, &fp, &rect, v22);
}
