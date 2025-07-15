void __thiscall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getColorBoundsRect(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result,
        unsigned int mask,
        unsigned int color,
        bool findColor)
{
  const Scaleform::GFx::AS3::VM::Error *v6; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::Render::DrawableImage *DrawableImageFromBitmapData; // eax
  Scaleform::GFx::AS3::Traits *pObject; // eax
  Scaleform::StringDataPtr v10; // [esp-8h] [ebp-6Ch]
  Scaleform::GFx::AS3::VM::Error v11; // [esp+Ch] [ebp-58h] BYREF
  Scaleform::Render::Rect<long> rect; // [esp+14h] [ebp-50h] BYREF
  Scaleform::GFx::AS3::Value args[4]; // [esp+24h] [ebp-40h] BYREF

  if ( this->pImage.pObject )
  {
    DrawableImageFromBitmapData = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                    this,
                                    this);
    Scaleform::Render::DrawableImage::GetColorBoundsRect(DrawableImageFromBitmapData, &rect, mask, color, findColor);
    args[0].value.VS._1.VInt = rect.x1;
    args[0].Flags = 2;
    args[1].Flags = 2;
    args[2].Flags = 2;
    args[3].Flags = 2;
    pObject = this->pTraits.pObject;
    args[1].value.VS._1.VInt = rect.y1;
    args[3].value.VS._1.VInt = rect.y2 - rect.y1;
    args[0].Bonus.pWeakProxy = 0;
    args[1].Bonus.pWeakProxy = 0;
    args[2].Bonus.pWeakProxy = 0;
    args[2].value.VS._1.VInt = rect.x2 - rect.x1;
    args[3].Bonus.pWeakProxy = 0;
    Scaleform::GFx::AS3::VM::constructBuiltinObject(
      pObject->pVM,
      (Scaleform::GFx::AS3::CheckResult *)&findColor,
      result,
      "flash.geom.Rectangle",
      4u,
      args);
    `vector destructor iterator'(
      (char *)args,
      0x10u,
      4,
      (void (__thiscall *)(void *))Scaleform::GFx::AS3::Value::~Value);
  }
  else
  {
    v10.pStr = "Invalid BitmapData";
    v10.Size = 18;
    Scaleform::GFx::AS3::VM::Error::Error(&v11, eArgumentError, this->pTraits.pObject->pVM, v10);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(this->pTraits.pObject->pVM, v6);
    pNode = v11.Message.pNode;
    --v11.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}
