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
  unsigned int v9; // eax
  Scaleform::GFx::AS3::VM *pVM; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  unsigned int v12; // eax
  Scaleform::GFx::AS3::VM *v13; // esi
  Scaleform::Render::DrawableImage *DrawableImageFromBitmapData; // ebx
  Scaleform::Render::DrawableImage *v15; // ebp
  Scaleform::Render::DrawableImage *v16; // edi
  Scaleform::Render::Point<long> *v17; // eax
  int y; // ecx
  const Scaleform::Render::Rect<long> *v19; // eax
  const Scaleform::Render::Point<long> *v20; // [esp-10h] [ebp-40h]
  Scaleform::StringDataPtr v21; // [esp-8h] [ebp-38h] BYREF
  Scaleform::Render::Point<long> alphaPt; // [esp+10h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::VM::Error v23; // [esp+18h] [ebp-18h] BYREF
  Scaleform::Render::Rect<long> v24; // [esp+20h] [ebp-10h] BYREF

  if ( !this->pImage.pObject )
  {
    v21.pStr = "Invalid BitmapData";
    v21.Size = 18;
    Scaleform::GFx::AS3::VM::Error::Error(&v23, eArgumentError, this->pTraits.pObject->pVM, v21);
    pVM = this->pTraits.pObject->pVM;
LABEL_3:
    v21.Size = v9;
    goto LABEL_4;
  }
  if ( !sourceBitmapData )
  {
    v21.pStr = "sourceBitmapData";
    v21.Size = 16;
    Scaleform::GFx::AS3::VM::Error::Error(&v23, eNullPointerError, this->pTraits.pObject->pVM, v21);
    v21.Size = v12;
    pVM = this->pTraits.pObject->pVM;
LABEL_4:
    Scaleform::GFx::AS3::VM::ThrowArgumentError(pVM, (const Scaleform::GFx::AS3::VM::Error *)v21.Size);
    pNode = v23.Message.pNode;
    --v23.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    return;
  }
  if ( !sourceRect )
  {
    v21.pStr = "sourceRect";
    v21.Size = 10;
    Scaleform::GFx::AS3::VM::Error::Error(&v23, eNullPointerError, this->pTraits.pObject->pVM, v21);
    pVM = this->pTraits.pObject->pVM;
    goto LABEL_3;
  }
  if ( !destPoint )
  {
    v13 = this->pTraits.pObject->pVM;
    Scaleform::StringDataPtr::StringDataPtr(&v21, "destPoint");
    Scaleform::GFx::AS3::VM::Error::Error(&v23, eNullPointerError, v13, v21);
    pVM = v13;
    goto LABEL_3;
  }
  DrawableImageFromBitmapData = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                  this,
                                  this);
  v15 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(this, alphaBitmapData);
  v16 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(this, sourceBitmapData);
  if ( v16 && DrawableImageFromBitmapData )
  {
    if ( alphaPoint )
    {
      v17 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::PointToPoint(
              this,
              (Scaleform::Render::Point<long> *)&v23,
              alphaPoint);
      y = v17->y;
      alphaPt.x = v17->x;
      alphaPt.y = y;
    }
    v20 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::PointToPoint(
            this,
            (Scaleform::Render::Point<long> *)&v23,
            destPoint);
    v19 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::RectangleToRect(this, &v24, sourceRect);
    Scaleform::Render::DrawableImage::CopyPixels(DrawableImageFromBitmapData, v16, v19, v20, v15, &alphaPt, mergeAlpha);
  }
}
