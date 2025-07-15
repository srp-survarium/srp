void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Graphics::drawRoundRectComplex(
        Scaleform::GFx::AS3::Instances::fl_display::Graphics *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v6; // eax
  Scaleform::GFx::ASStringNode *v7; // eax
  Scaleform::GFx::AS3::VM *v8; // esi
  const Scaleform::GFx::AS3::VM::Error *v9; // eax
  Scaleform::GFx::ASStringNode *v10; // eax
  long double v11; // st5
  long double v12; // st5
  Scaleform::GFx::DrawingContext *pObject; // ecx
  Scaleform::GFx::DrawingContext *v14; // ecx
  Scaleform::GFx::DrawingContext *v15; // ecx
  Scaleform::GFx::DrawingContext *v16; // ecx
  Scaleform::GFx::DrawingContext *v17; // ecx
  Scaleform::GFx::DrawingContext *v18; // ecx
  long double v19; // st7
  Scaleform::GFx::DrawingContext *v20; // ecx
  long double v21; // st6
  Scaleform::GFx::DrawingContext *v22; // ecx
  double v23; // st7
  Scaleform::GFx::DrawingContext *v24; // ecx
  Scaleform::GFx::DrawingContext *v25; // ecx
  Scaleform::GFx::DrawingContext *v26; // ecx
  float cy; // [esp+4h] [ebp-8Ch]
  float cya; // [esp+4h] [ebp-8Ch]
  float cyb; // [esp+4h] [ebp-8Ch]
  float v; // [esp+8h] [ebp-88h]
  float va; // [esp+8h] [ebp-88h]
  float vb; // [esp+8h] [ebp-88h]
  float vc; // [esp+8h] [ebp-88h]
  float vd; // [esp+8h] [ebp-88h]
  float ve; // [esp+8h] [ebp-88h]
  float v_4; // [esp+Ch] [ebp-84h]
  float v_4a; // [esp+Ch] [ebp-84h]
  float v_4b; // [esp+Ch] [ebp-84h]
  float v_4c; // [esp+Ch] [ebp-84h]
  float v_4d; // [esp+Ch] [ebp-84h]
  float v_4e; // [esp+Ch] [ebp-84h]
  float v_4f; // [esp+Ch] [ebp-84h]
  float v_4g; // [esp+Ch] [ebp-84h]
  float v_4h; // [esp+Ch] [ebp-84h]
  Scaleform::GFx::AS3::CheckResult v45; // [esp+23h] [ebp-6Dh] BYREF
  float xwft; // [esp+24h] [ebp-6Ch]
  float v47; // [esp+28h] [ebp-68h]
  float v48; // [esp+2Ch] [ebp-64h]
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
    pVM = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&xw, eWrongArgumentCountError, pVM);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(pVM, v6);
    v7 = (Scaleform::GFx::ASStringNode *)HIDWORD(xw);
    --*(_DWORD *)(HIDWORD(xw) + 12);
    if ( !v7->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v7);
    return;
  }
  Scaleform::GFx::AS3::Value::Convert2Number(argv, &v45, &x);
  Scaleform::GFx::AS3::Value::Convert2Number(argv + 1, &v45, &y);
  Scaleform::GFx::AS3::Value::Convert2Number(argv + 2, &v45, &width);
  Scaleform::GFx::AS3::Value::Convert2Number(argv + 3, &v45, &height);
  Scaleform::GFx::AS3::Value::Convert2Number(argv + 4, &v45, &topLeftRadius);
  Scaleform::GFx::AS3::Value::Convert2Number(argv + 5, &v45, &topRightRadius);
  Scaleform::GFx::AS3::Value::Convert2Number(argv + 6, &v45, &bottomLeftRadius);
  Scaleform::GFx::AS3::Value::Convert2Number(argv + 7, &v45, &bottomRightRadius);
  xw = width;
  if ( (HIDWORD(xw) & 0x7FF00000) == 0x7FF00000 && (unsigned int)&loc_FFFFF & HIDWORD(xw) | LODWORD(xw) )
    goto LABEL_6;
  if ( Scaleform::GFx::NumberUtil::IsNaN(height) )
  {
    v8 = this->pTraits.pObject->pVM;
    goto LABEL_7;
  }
  if ( Scaleform::GFx::NumberUtil::IsNaN(topLeftRadius) )
  {
    v8 = this->pTraits.pObject->pVM;
    goto LABEL_7;
  }
  if ( Scaleform::GFx::NumberUtil::IsNaN(topRightRadius) )
  {
LABEL_6:
    v8 = this->pTraits.pObject->pVM;
    goto LABEL_7;
  }
  if ( Scaleform::GFx::NumberUtil::IsNaN(bottomLeftRadius) )
  {
    v8 = this->pTraits.pObject->pVM;
    goto LABEL_7;
  }
  if ( Scaleform::GFx::NumberUtil::IsNaN(bottomRightRadius) )
  {
    v8 = this->pTraits.pObject->pVM;
LABEL_7:
    Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&xw, eInvalidArgumentError, v8);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(v8, v9);
    v10 = (Scaleform::GFx::ASStringNode *)HIDWORD(xw);
    --*(_DWORD *)(HIDWORD(xw) + 12);
    if ( !v10->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v10);
    return;
  }
  xw = x + width;
  v11 = height;
  yh = y + height;
  if ( width < height )
    v11 = width;
  v12 = v11 + v11;
  if ( v12 <= topLeftRadius )
    topLeftRadius = v12;
  if ( v12 <= topRightRadius )
    topRightRadius = v12;
  if ( v12 <= bottomLeftRadius )
    bottomLeftRadius = v12;
  if ( bottomRightRadius < v12 )
    v12 = bottomRightRadius;
  else
    bottomRightRadius = v12;
  pObject = this->pDrawing.pObject;
  a = 0.2928932188134524 * v12;
  s = 0.585786437626905 * v12;
  v47 = (x + width) * 20.0;
  xwft = v47;
  v48 = (y + height - v12) * 20.0;
  Scaleform::GFx::DrawingContext::MoveTo(pObject, v47, v48);
  v14 = this->pDrawing.pObject;
  v48 = (yh - a) * 20.0;
  v_4 = v48;
  v48 = (xw - a) * 20.0;
  v = v48;
  v48 = 20.0 * (yh - s);
  Scaleform::GFx::DrawingContext::CurveTo(v14, xwft, v48, v, v_4);
  v15 = this->pDrawing.pObject;
  xwft = yh * 20.0;
  v48 = (xw - bottomRightRadius) * 20.0;
  va = v48;
  v48 = 20.0 * (xw - s);
  Scaleform::GFx::DrawingContext::CurveTo(v15, v48, xwft, va, xwft);
  a = 0.2928932188134524 * bottomLeftRadius;
  s = 0.585786437626905 * bottomLeftRadius;
  v16 = this->pDrawing.pObject;
  v48 = bottomLeftRadius * 20.0 + 20.0 * x;
  Scaleform::GFx::DrawingContext::LineTo(v16, v48, xwft);
  v17 = this->pDrawing.pObject;
  v48 = (yh - a) * 20.0;
  v_4a = v48;
  v48 = a * 20.0 + x * 20.0;
  vb = v48;
  v48 = x * 20.0 + 20.0 * s;
  Scaleform::GFx::DrawingContext::CurveTo(v17, v48, xwft, vb, v_4a);
  v18 = this->pDrawing.pObject;
  xwft = x * 20.0;
  v48 = (yh - bottomLeftRadius) * 20.0;
  v_4b = v48;
  v48 = 20.0 * (yh - s);
  Scaleform::GFx::DrawingContext::CurveTo(v18, xwft, v48, xwft, v_4b);
  a = 0.2928932188134524 * topLeftRadius;
  s = 0.585786437626905 * topLeftRadius;
  v48 = topLeftRadius * 20.0 + y * 20.0;
  v_4c = v48;
  v48 = 20.0 * x;
  Scaleform::GFx::DrawingContext::LineTo(this->pDrawing.pObject, v48, v_4c);
  v19 = a * 20.0;
  v20 = this->pDrawing.pObject;
  v21 = x * 20.0;
  a = 20.0 * s;
  v48 = y * 20.0 + v19;
  v_4d = v48;
  v48 = v19 + v21;
  vc = v48;
  v48 = a + y * 20.0;
  cy = v48;
  v48 = v21;
  Scaleform::GFx::DrawingContext::CurveTo(v20, v48, cy, vc, v_4d);
  v22 = this->pDrawing.pObject;
  v48 = y * 20.0;
  v_4e = v48;
  v23 = v48;
  v48 = 20.0 * topLeftRadius + x * 20.0;
  vd = v48;
  cya = v23;
  v48 = x * 20.0 + a;
  Scaleform::GFx::DrawingContext::CurveTo(v22, v48, cya, vd, v_4e);
  a = 0.2928932188134524 * topRightRadius;
  s = 0.585786437626905 * topRightRadius;
  v48 = y * 20.0;
  v_4f = v48;
  v48 = (xw - topRightRadius) * 20.0;
  Scaleform::GFx::DrawingContext::LineTo(this->pDrawing.pObject, v48, v_4f);
  v24 = this->pDrawing.pObject;
  v48 = a * 20.0 + y * 20.0;
  v_4g = v48;
  v48 = (xw - a) * 20.0;
  ve = v48;
  v48 = y * 20.0;
  cyb = v48;
  v48 = 20.0 * (xw - s);
  Scaleform::GFx::DrawingContext::CurveTo(v24, v48, cyb, ve, v_4g);
  v25 = this->pDrawing.pObject;
  v48 = topRightRadius * 20.0 + y * 20.0;
  v_4h = v48;
  v48 = y * 20.0 + 20.0 * s;
  Scaleform::GFx::DrawingContext::CurveTo(v25, v47, v48, v47, v_4h);
  v26 = this->pDrawing.pObject;
  v48 = (yh - bottomRightRadius) * 20.0;
  Scaleform::GFx::DrawingContext::LineTo(v26, v47, v48);
  Scaleform::GFx::DisplayObjectBase::InvalidateHitResult(this->pDispObj);
}
