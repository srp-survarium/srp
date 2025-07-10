void __thiscall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getPixel(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        unsigned int *result,
        int x,
        int y)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v5; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::Render::DrawableImage *DrawableImageFromBitmapData; // eax
  Scaleform::GFx::AS3::VM::Error v8; // [esp+0h] [ebp-8h] BYREF

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
    pVM = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v8, eArgumentError, pVM);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(pVM, v5);
    pNode = v8.Message.pNode;
    --v8.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}
