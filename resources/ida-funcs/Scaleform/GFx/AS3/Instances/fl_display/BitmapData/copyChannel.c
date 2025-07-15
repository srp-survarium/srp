void __thiscall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::copyChannel(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *sourceBitmapData,
        Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *sourceRect,
        Scaleform::GFx::AS3::Instances::fl_geom::Point *destPoint,
        Scaleform::Render::DrawableImage::ChannelBits sourceChannel,
        Scaleform::Render::DrawableImage::ChannelBits destChannel)
{
  unsigned int v8; // eax
  Scaleform::GFx::AS3::VM *pVM; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  unsigned int v11; // eax
  Scaleform::GFx::AS3::VM *v12; // esi
  Scaleform::Render::DrawableImage *DrawableImageFromBitmapData; // ebx
  Scaleform::Render::DrawableImage *v14; // ebp
  long double y; // st7
  const Scaleform::Render::Rect<long> *v16; // eax
  Scaleform::StringDataPtr v17; // [esp-8h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::VM::Error v18; // [esp+10h] [ebp-18h] BYREF
  Scaleform::Render::Rect<long> v19; // [esp+18h] [ebp-10h] BYREF

  if ( !this->pImage.pObject )
  {
    v17.pStr = "Invalid BitmapData";
    v17.Size = 18;
    Scaleform::GFx::AS3::VM::Error::Error(&v18, eArgumentError, this->pTraits.pObject->pVM, v17);
    pVM = this->pTraits.pObject->pVM;
LABEL_3:
    v17.Size = v8;
    goto LABEL_4;
  }
  if ( sourceBitmapData )
  {
    if ( sourceRect )
    {
      if ( destPoint )
      {
        DrawableImageFromBitmapData = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                        this,
                                        this);
        v14 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                this,
                sourceBitmapData);
        y = destPoint->y;
        v18.ID = (int)destPoint->x;
        v18.Message.pNode = (Scaleform::GFx::ASStringNode *)(int)y;
        v16 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::RectangleToRect(this, &v19, sourceRect);
        Scaleform::Render::DrawableImage::CopyChannel(
          DrawableImageFromBitmapData,
          v14,
          v16,
          (const Scaleform::Render::Point<long> *)&v18,
          sourceChannel,
          destChannel);
        return;
      }
      v12 = this->pTraits.pObject->pVM;
      Scaleform::StringDataPtr::StringDataPtr(&v17, "destPoint");
      Scaleform::GFx::AS3::VM::Error::Error(&v18, eNullPointerError, v12, v17);
      pVM = v12;
    }
    else
    {
      v17.pStr = "sourceRect";
      v17.Size = 10;
      Scaleform::GFx::AS3::VM::Error::Error(&v18, eNullPointerError, this->pTraits.pObject->pVM, v17);
      pVM = this->pTraits.pObject->pVM;
    }
    goto LABEL_3;
  }
  v17.pStr = "sourceBitmapData";
  v17.Size = 16;
  Scaleform::GFx::AS3::VM::Error::Error(&v18, eNullPointerError, this->pTraits.pObject->pVM, v17);
  v17.Size = v11;
  pVM = this->pTraits.pObject->pVM;
LABEL_4:
  Scaleform::GFx::AS3::VM::ThrowArgumentError(pVM, (const Scaleform::GFx::AS3::VM::Error *)v17.Size);
  pNode = v18.Message.pNode;
  --v18.Message.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}
