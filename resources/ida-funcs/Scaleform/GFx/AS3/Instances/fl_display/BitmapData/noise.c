void __thiscall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::noise(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        const Scaleform::GFx::AS3::Value *result,
        unsigned int randomSeed,
        unsigned int low,
        unsigned int high,
        unsigned int channelOptions,
        bool grayScale)
{
  const Scaleform::GFx::AS3::VM::Error *v8; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::Render::DrawableImage *DrawableImageFromBitmapData; // eax
  Scaleform::StringDataPtr v11; // [esp-8h] [ebp-14h]
  Scaleform::GFx::AS3::VM::Error v12; // [esp+4h] [ebp-8h] BYREF

  if ( this->pImage.pObject )
  {
    DrawableImageFromBitmapData = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                    this,
                                    this);
    Scaleform::Render::DrawableImage::Noise(
      DrawableImageFromBitmapData,
      randomSeed,
      low,
      high,
      channelOptions,
      grayScale);
  }
  else
  {
    v11.pStr = "Invalid BitmapData";
    v11.Size = 18;
    Scaleform::GFx::AS3::VM::Error::Error(&v12, eArgumentError, this->pTraits.pObject->pVM, v11);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(this->pTraits.pObject->pVM, v8);
    pNode = v12.Message.pNode;
    --v12.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}
