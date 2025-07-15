void __thiscall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::colorTransform(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *rect,
        Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *cTransform)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v6; // eax
  int y1; // eax
  Scaleform::GFx::ASStringNode *v8; // ecx
  Scaleform::GFx::AS3::VM *v9; // esi
  const Scaleform::GFx::AS3::VM::Error *v10; // eax
  int v11; // eax
  Scaleform::Render::DrawableImage *DrawableImageFromBitmapData; // edi
  const Scaleform::Render::Rect<long> *v13; // eax
  Scaleform::Render::Rect<long> v14; // [esp+30h] [ebp-30h] BYREF
  Scaleform::Render::Cxform cxform; // [esp+40h] [ebp-20h] BYREF

  if ( !this->pImage.pObject )
  {
    pVM = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&v14, eArgumentError, pVM);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(pVM, v6);
    y1 = v14.y1;
    --*(_DWORD *)(v14.y1 + 12);
    v8 = (Scaleform::GFx::ASStringNode *)y1;
    if ( *(_DWORD *)(y1 + 12) )
      return;
    goto LABEL_3;
  }
  if ( rect )
  {
    if ( cTransform )
    {
      DrawableImageFromBitmapData = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                      this,
                                      this);
      Scaleform::GFx::AS3::ClassTraits::fl_geom::ColorTransform::GetCxformFromColorTransform(&cxform, cTransform);
      v13 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::RectangleToRect(this, &v14, rect);
      Scaleform::Render::DrawableImage::ColorTransform(DrawableImageFromBitmapData, v13, &cxform);
      return;
    }
    v9 = this->pTraits.pObject->pVM;
  }
  else
  {
    v9 = this->pTraits.pObject->pVM;
  }
  Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&v14, eIllegalOperationError, v9);
  Scaleform::GFx::AS3::VM::ThrowArgumentError(v9, v10);
  v11 = v14.y1;
  --*(_DWORD *)(v14.y1 + 12);
  v8 = (Scaleform::GFx::ASStringNode *)v11;
  if ( !*(_DWORD *)(v11 + 12) )
LABEL_3:
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
}
