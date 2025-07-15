void __thiscall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::threshold(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *const argv)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v6; // eax
  Scaleform::GFx::ASStringNode *v7; // eax
  Scaleform::GFx::ASStringNode *v8; // ecx
  const Scaleform::GFx::AS3::Value *v9; // ebp
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *VInt; // ebx
  Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *v11; // eax
  Scaleform::GFx::AS3::Instances::fl_geom::Point *v12; // ecx
  Scaleform::GFx::AS3::VM *v13; // esi
  const Scaleform::GFx::AS3::VM::Error *v14; // eax
  Scaleform::GFx::ASStringNode *v15; // eax
  Scaleform::GFx::AS3::Value *v16; // edi
  Scaleform::Render::DrawableImage *DrawableImageFromBitmapData; // ebp
  Scaleform::Render::DrawableImage *v18; // eax
  Scaleform::Render::DrawableImage *v19; // ebx
  const Scaleform::Render::Rect<long> *v20; // eax
  Scaleform::GFx::AS3::VM *v21; // esi
  const Scaleform::GFx::AS3::VM::Error *v22; // eax
  Scaleform::GFx::ASStringNode *v23; // eax
  const Scaleform::Render::Point<long> *v25; // [esp-24h] [ebp-54h]
  unsigned int v26; // [esp-1Ch] [ebp-4Ch]
  unsigned int v27; // [esp-18h] [ebp-48h]
  unsigned int v28; // [esp-14h] [ebp-44h]
  Scaleform::Render::DrawableImage::OperationType op; // [esp+4h] [ebp-2Ch]
  bool copySource; // [esp+8h] [ebp-28h]
  unsigned int mask; // [esp+Ch] [ebp-24h] BYREF
  unsigned int color; // [esp+10h] [ebp-20h] BYREF
  unsigned int threshold; // [esp+14h] [ebp-1Ch] BYREF
  Scaleform::GFx::AS3::Instances::fl_geom::Point *destPoint; // [esp+18h] [ebp-18h] BYREF
  Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *sourceRect; // [esp+20h] [ebp-10h] BYREF
  Scaleform::GFx::ASStringNode *v36; // [esp+24h] [ebp-Ch]

  sourceRect = 0;
  if ( !this->pImage.pObject )
  {
    pVM = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&sourceRect, eArgumentError, pVM);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(pVM, v6);
    v7 = v36;
    --v36->RefCount;
    v8 = v7;
    if ( v7->RefCount )
      return;
    goto LABEL_3;
  }
  if ( argc >= 5 )
  {
    v9 = argv;
    VInt = (Scaleform::GFx::AS3::Instances::fl_display::BitmapData *)argv->value.VS._1.VInt;
    v11 = (Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *)argv[1].value.VS._1.VInt;
    v12 = (Scaleform::GFx::AS3::Instances::fl_geom::Point *)argv[2].value.VS._1.VInt;
    sourceRect = v11;
    destPoint = v12;
    if ( !VInt )
    {
      v13 = this->pTraits.pObject->pVM;
      goto LABEL_11;
    }
    if ( !v11 )
    {
      v13 = this->pTraits.pObject->pVM;
      goto LABEL_11;
    }
    if ( !v12 )
    {
      v13 = this->pTraits.pObject->pVM;
LABEL_11:
      Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&sourceRect, eNullPointerError, v13);
      Scaleform::GFx::AS3::VM::ThrowArgumentError(v13, v14);
      v15 = v36;
      --v36->RefCount;
      v8 = v15;
      if ( !v15->RefCount )
      {
LABEL_3:
        Scaleform::GFx::ASStringNode::ReleaseNode(v8);
        return;
      }
      return;
    }
    v16 = (Scaleform::GFx::AS3::Value *)argv[3].value.VS._1.VInt;
    ++v16->value.VS._2.VObj;
    argv = v16;
    if ( Scaleform::GFx::ASString::operator==((Scaleform::GFx::ASString *)&argv, "<=") )
    {
      op = Operator_LE;
    }
    else if ( Scaleform::GFx::ASString::operator==((Scaleform::GFx::ASString *)&argv, "<") )
    {
      op = Operator_LT;
    }
    else if ( Scaleform::GFx::ASString::operator==((Scaleform::GFx::ASString *)&argv, ">") )
    {
      op = Operator_GT;
    }
    else if ( Scaleform::GFx::ASString::operator==((Scaleform::GFx::ASString *)&argv, ">=") )
    {
      op = Operator_GE;
    }
    else if ( Scaleform::GFx::ASString::operator==((Scaleform::GFx::ASString *)&argv, "!=") )
    {
      op = Operator_NE;
    }
    else
    {
      if ( !Scaleform::GFx::ASString::operator==((Scaleform::GFx::ASString *)&argv, "==") )
      {
        v21 = this->pTraits.pObject->pVM;
        Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&sourceRect, eInvalidArgumentError, v21);
        Scaleform::GFx::AS3::VM::ThrowArgumentError(v21, v22);
        v23 = v36;
        --v36->RefCount;
        if ( !v23->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v23);
        goto LABEL_35;
      }
      op = Operator_EQ;
    }
    color = 0;
    mask = -1;
    copySource = 1;
    if ( Scaleform::GFx::AS3::Value::Convert2UInt32(
           (Scaleform::GFx::AS3::Value *)&v9[4],
           (Scaleform::GFx::AS3::CheckResult *)&argv,
           &threshold)->Result
      && (argc < 6
       || Scaleform::GFx::AS3::Value::Convert2UInt32(
            (Scaleform::GFx::AS3::Value *)&v9[5],
            (Scaleform::GFx::AS3::CheckResult *)&argv,
            &color)->Result)
      && (argc < 7
       || Scaleform::GFx::AS3::Value::Convert2UInt32(
            (Scaleform::GFx::AS3::Value *)&v9[6],
            (Scaleform::GFx::AS3::CheckResult *)&argv,
            &mask)->Result) )
    {
      if ( argc >= 8 )
        copySource = Scaleform::GFx::AS3::Value::Convert2Boolean((Scaleform::GFx::AS3::Value *)&v9[7]);
      DrawableImageFromBitmapData = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                      this,
                                      this);
      v18 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(this, VInt);
      v28 = mask;
      v19 = v18;
      v27 = color;
      v26 = threshold;
      v25 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::PointToPoint(
              this,
              (Scaleform::Render::Point<long> *)&destPoint,
              destPoint);
      v20 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::RectangleToRect(
              this,
              (Scaleform::Render::Rect<long> *)&sourceRect,
              sourceRect);
      Scaleform::Render::DrawableImage::Threshold(
        DrawableImageFromBitmapData,
        v19,
        v20,
        v25,
        op,
        v26,
        v27,
        v28,
        copySource);
    }
LABEL_35:
    if ( v16->value.VS._2.VObj-- == (Scaleform::GFx::AS3::Object *)1 )
      Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)v16);
  }
}
