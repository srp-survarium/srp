void __thiscall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::compare(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *otherBitmapData)
{
  const Scaleform::GFx::AS3::VM::Error *v4; // eax
  Scaleform::GFx::ASStringNode *v5; // eax
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v6; // edi
  const Scaleform::GFx::AS3::VM::Error *v7; // eax
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData **v8; // eax
  Scaleform::Render::Size<unsigned long> *v9; // eax
  Scaleform::Render::DrawableImage *DrawableImageFromBitmapData; // edi
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v11; // ebx
  Scaleform::Render::DrawableImage *v12; // ebp
  Scaleform::Render::DrawableImage *v13; // eax
  Scaleform::StringDataPtr v14; // [esp-8h] [ebp-28h]
  Scaleform::StringDataPtr v15; // [esp-8h] [ebp-28h]
  int h; // [esp+10h] [ebp-10h] BYREF
  Scaleform::GFx::ASStringNode *v17; // [esp+14h] [ebp-Ch]
  _BYTE v18[8]; // [esp+18h] [ebp-8h] BYREF

  if ( !this->pImage.pObject )
  {
    v14.pStr = "Invalid BitmapData";
    v14.Size = 18;
    Scaleform::GFx::AS3::VM::Error::Error(
      (Scaleform::GFx::AS3::VM::Error *)&h,
      eArgumentError,
      this->pTraits.pObject->pVM,
      v14);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(this->pTraits.pObject->pVM, v4);
    goto LABEL_3;
  }
  v6 = otherBitmapData;
  if ( !otherBitmapData )
  {
    v15.pStr = "otherBitmapData";
    v15.Size = 15;
    Scaleform::GFx::AS3::VM::Error::Error(
      (Scaleform::GFx::AS3::VM::Error *)&h,
      eNullPointerError,
      this->pTraits.pObject->pVM,
      v15);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(this->pTraits.pObject->pVM, v7);
LABEL_3:
    v5 = v17;
    --v17->RefCount;
    if ( !v5->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v5);
    return;
  }
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData::widthGet(otherBitmapData, (int *)&otherBitmapData);
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData::heightGet(v6, &h);
  v8 = (Scaleform::GFx::AS3::Instances::fl_display::BitmapData **)this->pImage.pObject->GetSize(
                                                                    this->pImage.pObject,
                                                                    v18);
  if ( *v8 == otherBitmapData )
  {
    v9 = this->pImage.pObject->GetSize(this->pImage.pObject, v18);
    if ( v9->Height == h )
    {
      DrawableImageFromBitmapData = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                      this,
                                      v6);
      otherBitmapData = 0;
      Scaleform::GFx::AS3::Instances::fl_display::BitmapData::clone(
        this,
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::BitmapData> *)&otherBitmapData);
      v11 = otherBitmapData;
      v12 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
              this,
              otherBitmapData);
      v13 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(this, this);
      Scaleform::Render::DrawableImage::Compare(v12, v13, DrawableImageFromBitmapData);
      Scaleform::GFx::AS3::Value::Assign(result, v11);
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>::~SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>((Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *)&otherBitmapData);
    }
    else
    {
      Scaleform::GFx::AS3::Value::SetSInt32(result, -4);
    }
  }
  else
  {
    Scaleform::GFx::AS3::Value::SetSInt32(result, -3);
  }
}
