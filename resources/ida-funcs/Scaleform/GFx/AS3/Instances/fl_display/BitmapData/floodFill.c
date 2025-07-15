void __thiscall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::floodFill(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::VM::ErrorID x,
        Scaleform::GFx::ASStringNode *y,
        unsigned int color)
{
  const Scaleform::GFx::AS3::VM::Error *v6; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::Render::DrawableImage *DrawableImageFromBitmapData; // eax
  Scaleform::StringDataPtr v9; // [esp-8h] [ebp-14h]
  Scaleform::GFx::AS3::VM::Error v10; // [esp+4h] [ebp-8h] BYREF

  if ( this->pImage.pObject )
  {
    DrawableImageFromBitmapData = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                    this,
                                    this);
    v10.ID = x;
    v10.Message.pNode = y;
    Scaleform::Render::DrawableImage::FloodFill(
      DrawableImageFromBitmapData,
      (const Scaleform::Render::Point<long> *)&v10,
      (Scaleform::Render::Color)color);
  }
  else
  {
    v9.pStr = "Invalid BitmapData";
    v9.Size = 18;
    Scaleform::GFx::AS3::VM::Error::Error(&v10, eArgumentError, this->pTraits.pObject->pVM, v9);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(this->pTraits.pObject->pVM, v6);
    pNode = v10.Message.pNode;
    --v10.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}
