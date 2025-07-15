void __thiscall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::copyPixels(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *sourceBitmapData,
        Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *sourceRect,
        Scaleform::GFx::AS3::Instances::fl_geom::Point *destPoint,
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *alphaBitmapData,
        Scaleform::GFx::AS3::Instances::fl_geom::Point *alphaPoint,
        bool mergeAlpha)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v10; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v12; // ecx
  Scaleform::GFx::AS3::VM *v13; // esi
  const Scaleform::GFx::AS3::VM::Error *v14; // eax
  Scaleform::GFx::ASStringNode *v15; // eax
  Scaleform::Render::DrawableImage *DrawableImageFromBitmapData; // ebx
  Scaleform::Render::DrawableImage *v17; // ebp
  Scaleform::Render::DrawableImage *v18; // edi
  Scaleform::Render::Point<long> *v19; // eax
  int y; // ecx
  const Scaleform::Render::Rect<long> *v21; // eax
  const Scaleform::Render::Point<long> *v22; // [esp-1Ch] [ebp-40h]
  Scaleform::Render::Point<long> alphaPt; // [esp+4h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::VM::Error v24; // [esp+Ch] [ebp-18h] BYREF
  Scaleform::Render::Rect<long> v25; // [esp+14h] [ebp-10h] BYREF

  if ( !this->pImage.pObject )
  {
    pVM = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v24, eArgumentError, pVM);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(pVM, v10);
    pNode = v24.Message.pNode;
    --v24.Message.pNode->RefCount;
    v12 = pNode;
    if ( pNode->RefCount )
      return;
    goto LABEL_3;
  }
  if ( sourceBitmapData )
  {
    if ( sourceRect )
    {
      if ( destPoint )
      {
        DrawableImageFromBitmapData = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                        this,
                                        this);
        v17 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                this,
                alphaBitmapData);
        v18 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                this,
                sourceBitmapData);
        if ( v18 && DrawableImageFromBitmapData )
        {
          if ( alphaPoint )
          {
            v19 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::PointToPoint(
                    this,
                    (Scaleform::Render::Point<long> *)&v24,
                    alphaPoint);
            y = v19->y;
            alphaPt.x = v19->x;
            alphaPt.y = y;
          }
          v22 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::PointToPoint(
                  this,
                  (Scaleform::Render::Point<long> *)&v24,
                  destPoint);
          v21 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::RectangleToRect(this, &v25, sourceRect);
          Scaleform::Render::DrawableImage::CopyPixels(
            DrawableImageFromBitmapData,
            v18,
            v21,
            v22,
            v17,
            &alphaPt,
            mergeAlpha);
        }
        return;
      }
      v13 = this->pTraits.pObject->pVM;
    }
    else
    {
      v13 = this->pTraits.pObject->pVM;
    }
  }
  else
  {
    v13 = this->pTraits.pObject->pVM;
  }
  Scaleform::GFx::AS3::VM::Error::Error(&v24, eNullPointerError, v13);
  Scaleform::GFx::AS3::VM::ThrowArgumentError(v13, v14);
  v15 = v24.Message.pNode;
  --v24.Message.pNode->RefCount;
  v12 = v15;
  if ( !v15->RefCount )
LABEL_3:
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
}
