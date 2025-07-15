void __thiscall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::colorTransform(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *rect,
        Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *cTransform)
{
  const Scaleform::GFx::AS3::VM::Error *v5; // eax
  Scaleform::GFx::AS3::VM *pVM; // ecx
  Scaleform::GFx::ASStringNode *y1; // eax
  const Scaleform::GFx::AS3::VM::Error *v8; // eax
  Scaleform::Render::DrawableImage *DrawableImageFromBitmapData; // edi
  const Scaleform::Render::Rect<long> *v10; // eax
  Scaleform::StringDataPtr cxform_24; // [esp+18h] [ebp-48h]
  Scaleform::StringDataPtr cxform_24a; // [esp+18h] [ebp-48h]
  Scaleform::StringDataPtr cxform_24b; // [esp+18h] [ebp-48h]
  Scaleform::Render::Rect<long> v14; // [esp+30h] [ebp-30h] BYREF
  Scaleform::Render::Cxform cxform; // [esp+40h] [ebp-20h] BYREF

  if ( !this->pImage.pObject )
  {
    cxform_24.pStr = "Invalid BitmapData";
    cxform_24.Size = 18;
    Scaleform::GFx::AS3::VM::Error::Error(
      (Scaleform::GFx::AS3::VM::Error *)&v14,
      eArgumentError,
      this->pTraits.pObject->pVM,
      cxform_24);
    pVM = this->pTraits.pObject->pVM;
LABEL_3:
    Scaleform::GFx::AS3::VM::ThrowArgumentError(pVM, v5);
    goto LABEL_4;
  }
  if ( rect )
  {
    if ( cTransform )
    {
      DrawableImageFromBitmapData = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                      this,
                                      this);
      Scaleform::GFx::AS3::ClassTraits::fl_geom::ColorTransform::GetCxformFromColorTransform(&cxform, cTransform);
      v10 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::RectangleToRect(this, &v14, rect);
      Scaleform::Render::DrawableImage::ColorTransform(DrawableImageFromBitmapData, v10, &cxform);
      return;
    }
    cxform_24b.pStr = "colorTransform";
    cxform_24b.Size = 14;
    Scaleform::GFx::AS3::VM::Error::Error(
      (Scaleform::GFx::AS3::VM::Error *)&v14,
      eIllegalOperationError,
      this->pTraits.pObject->pVM,
      cxform_24b);
    pVM = this->pTraits.pObject->pVM;
    goto LABEL_3;
  }
  cxform_24a.pStr = "rect";
  cxform_24a.Size = 4;
  Scaleform::GFx::AS3::VM::Error::Error(
    (Scaleform::GFx::AS3::VM::Error *)&v14,
    eIllegalOperationError,
    this->pTraits.pObject->pVM,
    cxform_24a);
  Scaleform::GFx::AS3::VM::ThrowArgumentError(this->pTraits.pObject->pVM, v8);
LABEL_4:
  y1 = (Scaleform::GFx::ASStringNode *)v14.y1;
  --*(_DWORD *)(v14.y1 + 12);
  if ( !y1->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(y1);
}
