void __thiscall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::floodFill(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::VM::ErrorID x,
        Scaleform::GFx::ASStringNode *y,
        unsigned int color)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v6; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::Render::DrawableImage *DrawableImageFromBitmapData; // eax
  Scaleform::GFx::AS3::VM::Error v9; // [esp+4h] [ebp-8h] BYREF

  if ( this->pImage.pObject )
  {
    DrawableImageFromBitmapData = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                    this,
                                    this);
    v9.ID = x;
    v9.Message.pNode = y;
    Scaleform::Render::DrawableImage::FloodFill(
      DrawableImageFromBitmapData,
      (const Scaleform::Render::Point<long> *)&v9,
      (Scaleform::Render::Color)color);
  }
  else
  {
    pVM = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v9, eArgumentError, pVM);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(pVM, v6);
    pNode = v9.Message.pNode;
    --v9.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}
