void __thiscall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::fillRect(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *rect,
        unsigned int color)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v5; // eax
  int y1; // eax
  Scaleform::GFx::ASStringNode *v7; // ecx
  Scaleform::GFx::AS3::VM *v8; // esi
  const Scaleform::GFx::AS3::VM::Error *v9; // eax
  int v10; // eax
  Scaleform::Render::DrawableImage *DrawableImageFromBitmapData; // ebx
  long double y; // st7
  int v13; // eax
  long double v14; // st7
  int v15; // eax
  long double v16; // st7
  Scaleform::Render::Rect<long> v17; // [esp+Ch] [ebp-10h] BYREF

  if ( !this->pImage.pObject )
  {
    pVM = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&v17, eArgumentError, pVM);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(pVM, v5);
    y1 = v17.y1;
    --*(_DWORD *)(v17.y1 + 12);
    v7 = (Scaleform::GFx::ASStringNode *)y1;
    if ( *(_DWORD *)(y1 + 12) )
      return;
    goto LABEL_3;
  }
  if ( rect )
  {
    DrawableImageFromBitmapData = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                    this,
                                    this);
    y = rect->y;
    v17.x1 = (int)rect->x;
    v13 = (int)y;
    v14 = rect->width + rect->x;
    v17.y1 = v13;
    v15 = (int)v14;
    v16 = rect->height + rect->y;
    v17.x2 = v15;
    v17.y2 = (int)v16;
    Scaleform::Render::DrawableImage::FillRect(DrawableImageFromBitmapData, &v17, (Scaleform::Render::Color)color);
  }
  else
  {
    v8 = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&v17, eNullPointerError, v8);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(v8, v9);
    v10 = v17.y1;
    --*(_DWORD *)(v17.y1 + 12);
    v7 = (Scaleform::GFx::ASStringNode *)v10;
    if ( !*(_DWORD *)(v10 + 12) )
LABEL_3:
      Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  }
}
