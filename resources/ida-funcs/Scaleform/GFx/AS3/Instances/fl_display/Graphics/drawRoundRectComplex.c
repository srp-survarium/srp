void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Graphics::drawRoundRectComplex(
        Scaleform::GFx::AS3::Instances::fl_display::Graphics *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  unsigned int v5; // eax
  Scaleform::GFx::AS3::VM *pVM; // ecx
  Scaleform::GFx::ASStringNode *v7; // eax
  unsigned int v8; // eax
  Scaleform::GFx::AS3::VM *v9; // esi
  long double v10; // st5
  long double v11; // st5
  Scaleform::GFx::DrawingContext *pObject; // ecx
  Scaleform::GFx::DrawingContext *v13; // ecx
  Scaleform::GFx::DrawingContext *v14; // ecx
  Scaleform::GFx::DrawingContext *v15; // ecx
  Scaleform::GFx::DrawingContext *v16; // ecx
  Scaleform::GFx::DrawingContext *v17; // ecx
  long double v18; // st7
  Scaleform::GFx::DrawingContext *v19; // ecx
  long double v20; // st6
  Scaleform::GFx::DrawingContext *v21; // ecx
  double v22; // st7
  Scaleform::GFx::DrawingContext *v23; // ecx
  Scaleform::GFx::DrawingContext *v24; // ecx
  Scaleform::GFx::DrawingContext *v25; // ecx
  Scaleform::StringDataPtr v26; // [esp-4h] [ebp-94h]
  float cy; // [esp+4h] [ebp-8Ch]
  float cya; // [esp+4h] [ebp-8Ch]
  float cyb; // [esp+4h] [ebp-8Ch]
  Scaleform::StringDataPtr arg1; // [esp+8h] [ebp-88h] BYREF
  Scaleform::GFx::AS3::CheckResult v31; // [esp+23h] [ebp-6Dh] BYREF
  float xwft; // [esp+24h] [ebp-6Ch]
  float v33; // [esp+28h] [ebp-68h]
  float v34; // [esp+2Ch] [ebp-64h]
  long double s; // [esp+30h] [ebp-60h]
  long double x; // [esp+38h] [ebp-58h] BYREF
  long double a; // [esp+40h] [ebp-50h]
  long double y; // [esp+48h] [ebp-48h] BYREF
  long double bottomLeftRadius; // [esp+50h] [ebp-40h] BYREF
  long double topLeftRadius; // [esp+58h] [ebp-38h] BYREF
  long double topRightRadius; // [esp+60h] [ebp-30h] BYREF
  long double yh; // [esp+68h] [ebp-28h]
  long double bottomRightRadius; // [esp+70h] [ebp-20h] BYREF
  double xw; // [esp+78h] [ebp-18h] BYREF
  double width; // [esp+80h] [ebp-10h] BYREF
  double height; // [esp+88h] [ebp-8h] BYREF

  if ( argc < 8 )
  {
    v26.pStr = "drawRoundRectComplex";
    v26.Size = 20;
    Scaleform::GFx::AS3::VM::Error::Error(
      (Scaleform::GFx::AS3::VM::Error *)&xw,
      eWrongArgumentCountError,
      this->pTraits.pObject->pVM,
      v26,
      8,
      8,
      argc);
LABEL_3:
    pVM = this->pTraits.pObject->pVM;
LABEL_4:
    arg1.Size = v5;
    goto LABEL_5;
  }
  Scaleform::GFx::AS3::Value::Convert2Number(argv, &v31, &x);
  Scaleform::GFx::AS3::Value::Convert2Number(argv + 1, &v31, &y);
  Scaleform::GFx::AS3::Value::Convert2Number(argv + 2, &v31, &width);
  Scaleform::GFx::AS3::Value::Convert2Number(argv + 3, &v31, &height);
  Scaleform::GFx::AS3::Value::Convert2Number(argv + 4, &v31, &topLeftRadius);
  Scaleform::GFx::AS3::Value::Convert2Number(argv + 5, &v31, &topRightRadius);
  Scaleform::GFx::AS3::Value::Convert2Number(argv + 6, &v31, &bottomLeftRadius);
  Scaleform::GFx::AS3::Value::Convert2Number(argv + 7, &v31, &bottomRightRadius);
  xw = width;
  if ( (HIDWORD(xw) & 0x7FF00000) == 0x7FF00000 && HIDWORD(xw) & 0xFFFFF | LODWORD(xw) )
  {
    arg1.pStr = "width";
    arg1.Size = 5;
    Scaleform::GFx::AS3::VM::Error::Error(
      (Scaleform::GFx::AS3::VM::Error *)&xw,
      eInvalidArgumentError,
      this->pTraits.pObject->pVM,
      arg1);
    goto LABEL_3;
  }
  if ( Scaleform::GFx::NumberUtil::IsNaN(height) )
  {
    arg1.pStr = "height";
    arg1.Size = 6;
    Scaleform::GFx::AS3::VM::Error::Error(
      (Scaleform::GFx::AS3::VM::Error *)&xw,
      eInvalidArgumentError,
      this->pTraits.pObject->pVM,
      arg1);
    arg1.Size = v8;
    pVM = this->pTraits.pObject->pVM;
LABEL_5:
    Scaleform::GFx::AS3::VM::ThrowArgumentError(pVM, (const Scaleform::GFx::AS3::VM::Error *)arg1.Size);
    v7 = (Scaleform::GFx::ASStringNode *)HIDWORD(xw);
    --*(_DWORD *)(HIDWORD(xw) + 12);
    if ( !v7->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v7);
    return;
  }
  if ( Scaleform::GFx::NumberUtil::IsNaN(topLeftRadius) )
  {
    v9 = this->pTraits.pObject->pVM;
    Scaleform::StringDataPtr::StringDataPtr(&arg1, "topLeftRadius");
LABEL_14:
    Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&xw, eInvalidArgumentError, v9, arg1);
    pVM = v9;
    goto LABEL_4;
  }
  if ( Scaleform::GFx::NumberUtil::IsNaN(topRightRadius) )
  {
    v9 = this->pTraits.pObject->pVM;
    Scaleform::StringDataPtr::StringDataPtr(&arg1, "topRightRadius");
    goto LABEL_14;
  }
  if ( Scaleform::GFx::NumberUtil::IsNaN(bottomLeftRadius) )
  {
    v9 = this->pTraits.pObject->pVM;
    Scaleform::StringDataPtr::StringDataPtr(&arg1, "bottomLeftRadius");
    goto LABEL_14;
  }
  if ( Scaleform::GFx::NumberUtil::IsNaN(bottomRightRadius) )
  {
    v9 = this->pTraits.pObject->pVM;
    Scaleform::StringDataPtr::StringDataPtr(&arg1, "bottomRightRadius");
    goto LABEL_14;
  }
  xw = x + width;
  v10 = height;
  yh = y + height;
  if ( width < height )
    v10 = width;
  v11 = v10 + v10;
  if ( v11 <= topLeftRadius )
    topLeftRadius = v11;
  if ( v11 <= topRightRadius )
    topRightRadius = v11;
  if ( v11 <= bottomLeftRadius )
    bottomLeftRadius = v11;
  if ( bottomRightRadius < v11 )
    v11 = bottomRightRadius;
  else
    bottomRightRadius = v11;
  pObject = this->pDrawing.pObject;
  a = 0.2928932188134524 * v11;
  s = 0.585786437626905 * v11;
  v33 = (x + width) * 20.0;
  xwft = v33;
  v34 = (y + height - v11) * 20.0;
  Scaleform::GFx::DrawingContext::MoveTo(pObject, v33, v34);
  v13 = this->pDrawing.pObject;
  v34 = (yh - a) * 20.0;
  *(float *)&arg1.Size = v34;
  v34 = (xw - a) * 20.0;
  *(float *)&arg1.pStr = v34;
  v34 = 20.0 * (yh - s);
  Scaleform::GFx::DrawingContext::CurveTo(v13, xwft, v34, *(float *)&arg1.pStr, *(float *)&arg1.Size);
  v14 = this->pDrawing.pObject;
  xwft = yh * 20.0;
  v34 = (xw - bottomRightRadius) * 20.0;
  *(float *)&arg1.pStr = v34;
  v34 = 20.0 * (xw - s);
  Scaleform::GFx::DrawingContext::CurveTo(v14, v34, xwft, *(float *)&arg1.pStr, xwft);
  a = 0.2928932188134524 * bottomLeftRadius;
  s = 0.585786437626905 * bottomLeftRadius;
  v15 = this->pDrawing.pObject;
  v34 = bottomLeftRadius * 20.0 + 20.0 * x;
  Scaleform::GFx::DrawingContext::LineTo(v15, v34, xwft);
  v16 = this->pDrawing.pObject;
  v34 = (yh - a) * 20.0;
  *(float *)&arg1.Size = v34;
  v34 = a * 20.0 + x * 20.0;
  *(float *)&arg1.pStr = v34;
  v34 = x * 20.0 + 20.0 * s;
  Scaleform::GFx::DrawingContext::CurveTo(v16, v34, xwft, *(float *)&arg1.pStr, *(float *)&arg1.Size);
  v17 = this->pDrawing.pObject;
  xwft = x * 20.0;
  v34 = (yh - bottomLeftRadius) * 20.0;
  *(float *)&arg1.Size = v34;
  v34 = 20.0 * (yh - s);
  Scaleform::GFx::DrawingContext::CurveTo(v17, xwft, v34, xwft, *(float *)&arg1.Size);
  a = 0.2928932188134524 * topLeftRadius;
  s = 0.585786437626905 * topLeftRadius;
  v34 = topLeftRadius * 20.0 + y * 20.0;
  *(float *)&arg1.Size = v34;
  v34 = 20.0 * x;
  Scaleform::GFx::DrawingContext::LineTo(this->pDrawing.pObject, v34, *(float *)&arg1.Size);
  v18 = a * 20.0;
  v19 = this->pDrawing.pObject;
  v20 = x * 20.0;
  a = 20.0 * s;
  v34 = y * 20.0 + v18;
  *(float *)&arg1.Size = v34;
  v34 = v18 + v20;
  *(float *)&arg1.pStr = v34;
  v34 = a + y * 20.0;
  cy = v34;
  v34 = v20;
  Scaleform::GFx::DrawingContext::CurveTo(v19, v34, cy, *(float *)&arg1.pStr, *(float *)&arg1.Size);
  v21 = this->pDrawing.pObject;
  v34 = y * 20.0;
  *(float *)&arg1.Size = v34;
  v22 = v34;
  v34 = 20.0 * topLeftRadius + x * 20.0;
  *(float *)&arg1.pStr = v34;
  cya = v22;
  v34 = x * 20.0 + a;
  Scaleform::GFx::DrawingContext::CurveTo(v21, v34, cya, *(float *)&arg1.pStr, *(float *)&arg1.Size);
  a = 0.2928932188134524 * topRightRadius;
  s = 0.585786437626905 * topRightRadius;
  v34 = y * 20.0;
  *(float *)&arg1.Size = v34;
  v34 = (xw - topRightRadius) * 20.0;
  Scaleform::GFx::DrawingContext::LineTo(this->pDrawing.pObject, v34, *(float *)&arg1.Size);
  v23 = this->pDrawing.pObject;
  v34 = a * 20.0 + y * 20.0;
  *(float *)&arg1.Size = v34;
  v34 = (xw - a) * 20.0;
  *(float *)&arg1.pStr = v34;
  v34 = y * 20.0;
  cyb = v34;
  v34 = 20.0 * (xw - s);
  Scaleform::GFx::DrawingContext::CurveTo(v23, v34, cyb, *(float *)&arg1.pStr, *(float *)&arg1.Size);
  v24 = this->pDrawing.pObject;
  v34 = topRightRadius * 20.0 + y * 20.0;
  *(float *)&arg1.Size = v34;
  v34 = y * 20.0 + 20.0 * s;
  Scaleform::GFx::DrawingContext::CurveTo(v24, v33, v34, v33, *(float *)&arg1.Size);
  v25 = this->pDrawing.pObject;
  v34 = (yh - bottomRightRadius) * 20.0;
  Scaleform::GFx::DrawingContext::LineTo(v25, v33, v34);
  Scaleform::GFx::DisplayObjectBase::InvalidateHitResult(this->pDispObj);
}
