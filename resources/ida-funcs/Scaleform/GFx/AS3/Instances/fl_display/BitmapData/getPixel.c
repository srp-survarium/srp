void __thiscall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getPixel(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        unsigned int *result,
        int x,
        int y)
{
  const Scaleform::GFx::AS3::VM::Error *v5; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::Render::DrawableImage *DrawableImageFromBitmapData; // eax
  Scaleform::StringDataPtr v8; // [esp-8h] [ebp-14h]
  Scaleform::GFx::AS3::VM::Error v9; // [esp+4h] [ebp-8h] BYREF

  if ( this->pImage.pObject )
  {
    DrawableImageFromBitmapData = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                    this,
                                    this);
    *result = Scaleform::Render::DrawableImage::GetPixel(
                DrawableImageFromBitmapData,
                (Scaleform::Render::Color *)&y,
                x,
                y)->Raw;
  }
  else
  {
    v8.pStr = "Invalid BitmapData";
    v8.Size = 18;
    Scaleform::GFx::AS3::VM::Error::Error(&v9, eArgumentError, this->pTraits.pObject->pVM, v8);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(this->pTraits.pObject->pVM, v5);
    pNode = v9.Message.pNode;
    --v9.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}
