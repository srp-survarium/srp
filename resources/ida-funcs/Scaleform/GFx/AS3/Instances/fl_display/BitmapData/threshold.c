void __thiscall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::threshold(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *const argv)
{
  unsigned int v5; // eax
  Scaleform::GFx::AS3::VM *pVM; // ecx
  Scaleform::GFx::ASStringNode *v7; // eax
  const Scaleform::GFx::AS3::Value *v8; // ebp
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *VInt; // ebx
  Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *v10; // eax
  Scaleform::GFx::AS3::Instances::fl_geom::Point *v11; // ecx
  unsigned int v12; // eax
  Scaleform::GFx::AS3::VM *v13; // esi
  Scaleform::GFx::AS3::Value *v14; // edi
  Scaleform::Render::DrawableImage *DrawableImageFromBitmapData; // ebp
  Scaleform::Render::DrawableImage *v16; // ebx
  const Scaleform::Render::Rect<long> *v17; // eax
  Scaleform::GFx::AS3::VM *v18; // esi
  const Scaleform::GFx::AS3::VM::Error *v19; // eax
  Scaleform::GFx::ASStringNode *v20; // eax
  const Scaleform::Render::Point<long> *v22; // [esp-18h] [ebp-54h]
  unsigned int v23; // [esp-10h] [ebp-4Ch]
  unsigned int v24; // [esp-Ch] [ebp-48h]
  Scaleform::StringDataPtr v25[3]; // [esp-8h] [ebp-44h] BYREF
  Scaleform::Render::DrawableImage::OperationType op; // [esp+10h] [ebp-2Ch]
  BOOL copySource; // [esp+14h] [ebp-28h]
  unsigned int mask; // [esp+18h] [ebp-24h] BYREF
  unsigned int color; // [esp+1Ch] [ebp-20h] BYREF
  unsigned int threshold; // [esp+20h] [ebp-1Ch] BYREF
  Scaleform::GFx::AS3::Instances::fl_geom::Point *destPoint; // [esp+24h] [ebp-18h] BYREF
  Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *sourceRect; // [esp+2Ch] [ebp-10h] BYREF
  Scaleform::GFx::ASStringNode *v33; // [esp+30h] [ebp-Ch]

  sourceRect = 0;
  if ( !this->pImage.pObject )
  {
    v25[0].pStr = "Invalid BitmapData";
    v25[0].Size = 18;
    Scaleform::GFx::AS3::VM::Error::Error(
      (Scaleform::GFx::AS3::VM::Error *)&sourceRect,
      eArgumentError,
      this->pTraits.pObject->pVM,
      v25[0]);
    pVM = this->pTraits.pObject->pVM;
LABEL_3:
    v25[0].Size = v5;
    goto LABEL_4;
  }
  if ( argc < 5 )
    return;
  v8 = argv;
  VInt = (Scaleform::GFx::AS3::Instances::fl_display::BitmapData *)argv->value.VS._1.VInt;
  v10 = (Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *)argv[1].value.VS._1.VInt;
  v11 = (Scaleform::GFx::AS3::Instances::fl_geom::Point *)argv[2].value.VS._1.VInt;
  sourceRect = v10;
  destPoint = v11;
  if ( !VInt )
  {
    v25[0].pStr = "sourceBitmapData";
    v25[0].Size = 16;
    Scaleform::GFx::AS3::VM::Error::Error(
      (Scaleform::GFx::AS3::VM::Error *)&sourceRect,
      eNullPointerError,
      this->pTraits.pObject->pVM,
      v25[0]);
    v25[0].Size = v12;
    pVM = this->pTraits.pObject->pVM;
LABEL_4:
    Scaleform::GFx::AS3::VM::ThrowArgumentError(pVM, (const Scaleform::GFx::AS3::VM::Error *)v25[0].Size);
    v7 = v33;
    --v33->RefCount;
    if ( !v7->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v7);
    return;
  }
  if ( !v10 )
  {
    v13 = this->pTraits.pObject->pVM;
    Scaleform::StringDataPtr::StringDataPtr(v25, "sourceRect");
LABEL_11:
    Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&sourceRect, eNullPointerError, v13, v25[0]);
    pVM = v13;
    goto LABEL_3;
  }
  if ( !v11 )
  {
    v13 = this->pTraits.pObject->pVM;
    Scaleform::StringDataPtr::StringDataPtr(v25, "destPoint");
    goto LABEL_11;
  }
  v14 = (Scaleform::GFx::AS3::Value *)argv[3].value.VS._1.VInt;
  ++v14->value.VS._2.VObj;
  argv = v14;
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
      v18 = this->pTraits.pObject->pVM;
      Scaleform::StringDataPtr::StringDataPtr(v25, "The operation string is not a valid operation.");
      Scaleform::GFx::AS3::VM::Error::Error(
        (Scaleform::GFx::AS3::VM::Error *)&sourceRect,
        eInvalidArgumentError,
        v18,
        v25[0]);
      Scaleform::GFx::AS3::VM::ThrowArgumentError(v18, v19);
      v20 = v33;
      --v33->RefCount;
      if ( !v20->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v20);
      goto LABEL_36;
    }
    op = Operator_EQ;
  }
  color = 0;
  mask = -1;
  LOBYTE(copySource) = 1;
  if ( Scaleform::GFx::AS3::Value::Convert2UInt32(
         (Scaleform::GFx::AS3::Value *)&v8[4],
         (Scaleform::GFx::AS3::CheckResult *)&argv,
         &threshold)->Result
    && (argc < 6
     || Scaleform::GFx::AS3::Value::Convert2UInt32(
          (Scaleform::GFx::AS3::Value *)&v8[5],
          (Scaleform::GFx::AS3::CheckResult *)&argv,
          &color)->Result)
    && (argc < 7
     || Scaleform::GFx::AS3::Value::Convert2UInt32(
          (Scaleform::GFx::AS3::Value *)&v8[6],
          (Scaleform::GFx::AS3::CheckResult *)&argv,
          &mask)->Result) )
  {
    if ( argc >= 8 )
      LOBYTE(copySource) = Scaleform::GFx::AS3::Value::Convert2Boolean((Scaleform::GFx::AS3::Value *)&v8[7]);
    DrawableImageFromBitmapData = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                    this,
                                    this);
    v16 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(this, VInt);
    v25[0].pStr = (const char *)mask;
    v24 = color;
    v23 = threshold;
    v22 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::PointToPoint(
            this,
            (Scaleform::Render::Point<long> *)&destPoint,
            destPoint);
    v17 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::RectangleToRect(
            this,
            (Scaleform::Render::Rect<long> *)&sourceRect,
            sourceRect);
    Scaleform::Render::DrawableImage::Threshold(
      DrawableImageFromBitmapData,
      v16,
      v17,
      v22,
      op,
      v23,
      v24,
      (unsigned int)v25[0].pStr,
      copySource);
  }
LABEL_36:
  if ( v14->value.VS._2.VObj-- == (Scaleform::GFx::AS3::Object *)1 )
    Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)v14);
}
