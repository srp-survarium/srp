void __thiscall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::copyChannel(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *sourceBitmapData,
        Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *sourceRect,
        Scaleform::GFx::AS3::Instances::fl_geom::Point *destPoint,
        Scaleform::Render::DrawableImage::ChannelBits sourceChannel,
        Scaleform::Render::DrawableImage::ChannelBits destChannel)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v9; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v11; // ecx
  Scaleform::GFx::AS3::VM *v12; // esi
  const Scaleform::GFx::AS3::VM::Error *v13; // eax
  Scaleform::GFx::ASStringNode *v14; // eax
  Scaleform::GFx::AS3::VM *v15; // esi
  const Scaleform::GFx::AS3::VM::Error *v16; // eax
  Scaleform::GFx::ASStringNode *v17; // eax
  Scaleform::Render::DrawableImage *DrawableImageFromBitmapData; // ebx
  Scaleform::Render::DrawableImage *v19; // ebp
  long double y; // st7
  const Scaleform::Render::Rect<long> *v21; // eax
  Scaleform::GFx::AS3::VM::Error v22; // [esp+4h] [ebp-18h] BYREF
  Scaleform::Render::Rect<long> v23; // [esp+Ch] [ebp-10h] BYREF

  if ( !this->pImage.pObject )
  {
    pVM = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v22, eArgumentError, pVM);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(pVM, v9);
    pNode = v22.Message.pNode;
    --v22.Message.pNode->RefCount;
    v11 = pNode;
    if ( pNode->RefCount )
      return;
LABEL_12:
    Scaleform::GFx::ASStringNode::ReleaseNode(v11);
    return;
  }
  if ( !sourceBitmapData )
  {
    v12 = this->pTraits.pObject->pVM;
    goto LABEL_8;
  }
  if ( !sourceRect )
  {
    v12 = this->pTraits.pObject->pVM;
LABEL_8:
    Scaleform::GFx::AS3::VM::Error::Error(&v22, eNullPointerError, v12);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(v12, v13);
    v14 = v22.Message.pNode;
    --v22.Message.pNode->RefCount;
    v11 = v14;
    if ( v14->RefCount )
      return;
    goto LABEL_12;
  }
  if ( !destPoint )
  {
    v15 = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v22, eNullPointerError, v15);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(v15, v16);
    v17 = v22.Message.pNode;
    --v22.Message.pNode->RefCount;
    v11 = v17;
    if ( v17->RefCount )
      return;
    goto LABEL_12;
  }
  DrawableImageFromBitmapData = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                  this,
                                  this);
  v19 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(this, sourceBitmapData);
  y = destPoint->y;
  v22.ID = (int)destPoint->x;
  v22.Message.pNode = (Scaleform::GFx::ASStringNode *)(int)y;
  v21 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::RectangleToRect(this, &v23, sourceRect);
  Scaleform::Render::DrawableImage::CopyChannel(
    DrawableImageFromBitmapData,
    v19,
    v21,
    (const Scaleform::Render::Point<long> *)&v22,
    sourceChannel,
    destChannel);
}
