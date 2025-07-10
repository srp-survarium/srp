void __thiscall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::noise(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        const Scaleform::GFx::AS3::Value *result,
        unsigned int randomSeed,
        unsigned int low,
        unsigned int high,
        unsigned int channelOptions,
        bool grayScale)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v8; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::Render::DrawableImage *DrawableImageFromBitmapData; // eax
  Scaleform::GFx::AS3::VM::Error v11; // [esp+0h] [ebp-8h] BYREF

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
    pVM = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v11, eArgumentError, pVM);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(pVM, v8);
    pNode = v11.Message.pNode;
    --v11.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}
