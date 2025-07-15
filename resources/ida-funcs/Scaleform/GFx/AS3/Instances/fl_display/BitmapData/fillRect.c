void __thiscall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::fillRect(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *rect,
        unsigned int color)
{
  const Scaleform::GFx::AS3::VM::Error *v5; // eax
  Scaleform::GFx::ASStringNode *y1; // eax
  const Scaleform::GFx::AS3::VM::Error *v7; // eax
  Scaleform::Render::DrawableImage *DrawableImageFromBitmapData; // ebx
  long double y; // st7
  int v10; // eax
  long double v11; // st7
  int v12; // eax
  long double v13; // st7
  Scaleform::StringDataPtr v14; // [esp-8h] [ebp-24h]
  Scaleform::StringDataPtr v15; // [esp-8h] [ebp-24h]
  Scaleform::Render::Rect<long> v16; // [esp+Ch] [ebp-10h] BYREF

  if ( this->pImage.pObject )
  {
    if ( rect )
    {
      DrawableImageFromBitmapData = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                      this,
                                      this);
      y = rect->y;
      v16.x1 = (int)rect->x;
      v10 = (int)y;
      v11 = rect->width + rect->x;
      v16.y1 = v10;
      v12 = (int)v11;
      v13 = rect->height + rect->y;
      v16.x2 = v12;
      v16.y2 = (int)v13;
      Scaleform::Render::DrawableImage::FillRect(DrawableImageFromBitmapData, &v16, (Scaleform::Render::Color)color);
      return;
    }
    v15.pStr = "rect";
    v15.Size = 4;
    Scaleform::GFx::AS3::VM::Error::Error(
      (Scaleform::GFx::AS3::VM::Error *)&v16,
      eNullPointerError,
      this->pTraits.pObject->pVM,
      v15);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(this->pTraits.pObject->pVM, v7);
  }
  else
  {
    v14.pStr = "Invalid BitmapData";
    v14.Size = 18;
    Scaleform::GFx::AS3::VM::Error::Error(
      (Scaleform::GFx::AS3::VM::Error *)&v16,
      eArgumentError,
      this->pTraits.pObject->pVM,
      v14);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(this->pTraits.pObject->pVM, v5);
  }
  y1 = (Scaleform::GFx::ASStringNode *)v16.y1;
  --*(_DWORD *)(v16.y1 + 12);
  if ( !y1->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(y1);
}
