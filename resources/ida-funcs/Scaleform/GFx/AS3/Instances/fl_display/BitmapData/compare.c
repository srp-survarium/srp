void __thiscall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::compare(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *otherBitmapData)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v5; // eax
  Scaleform::GFx::ASStringNode *v6; // eax
  Scaleform::GFx::ASStringNode *v7; // ecx
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v8; // edi
  Scaleform::GFx::AS3::VM *v9; // esi
  const Scaleform::GFx::AS3::VM::Error *v10; // eax
  Scaleform::GFx::ASStringNode *v11; // eax
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData **v12; // eax
  Scaleform::Render::Size<unsigned long> *v13; // eax
  Scaleform::Render::DrawableImage *DrawableImageFromBitmapData; // edi
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v15; // ebx
  Scaleform::Render::DrawableImage *v16; // ebp
  Scaleform::Render::DrawableImage *v17; // eax
  int h; // [esp+8h] [ebp-10h] BYREF
  Scaleform::GFx::ASStringNode *v19; // [esp+Ch] [ebp-Ch]
  _BYTE v20[8]; // [esp+10h] [ebp-8h] BYREF

  if ( !this->pImage.pObject )
  {
    pVM = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&h, eArgumentError, pVM);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(pVM, v5);
    v6 = v19;
    --v19->RefCount;
    v7 = v6;
    if ( v6->RefCount )
      return;
    goto LABEL_3;
  }
  v8 = otherBitmapData;
  if ( otherBitmapData )
  {
    Scaleform::GFx::AS3::Instances::fl_display::BitmapData::widthGet(otherBitmapData, (int *)&otherBitmapData);
    Scaleform::GFx::AS3::Instances::fl_display::BitmapData::heightGet(v8, &h);
    v12 = (Scaleform::GFx::AS3::Instances::fl_display::BitmapData **)this->pImage.pObject->GetSize(
                                                                       this->pImage.pObject,
                                                                       v20);
    if ( *v12 == otherBitmapData )
    {
      v13 = this->pImage.pObject->GetSize(this->pImage.pObject, v20);
      if ( v13->Height == h )
      {
        DrawableImageFromBitmapData = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                        this,
                                        v8);
        otherBitmapData = 0;
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData::clone(
          this,
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::BitmapData> *)&otherBitmapData);
        v15 = otherBitmapData;
        v16 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                this,
                otherBitmapData);
        v17 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(this, this);
        Scaleform::Render::DrawableImage::Compare(v16, v17, DrawableImageFromBitmapData);
        Scaleform::GFx::AS3::Value::Assign(result, v15);
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
  else
  {
    v9 = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&h, eNullPointerError, v9);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(v9, v10);
    v11 = v19;
    --v19->RefCount;
    v7 = v11;
    if ( !v11->RefCount )
LABEL_3:
      Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  }
}
