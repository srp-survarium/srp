void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Graphics::drawRoundRect(
        Scaleform::GFx::AS3::Instances::fl_display::Graphics *this,
        const Scaleform::GFx::AS3::Value *result,
        long double x,
        long double y,
        long double width,
        long double height,
        long double ellipseWidth,
        long double ellipseHeight)
{
  const Scaleform::GFx::AS3::VM::Error *v9; // eax
  Scaleform::GFx::AS3::VM *pVM; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  const Scaleform::GFx::AS3::VM::Error *v12; // eax
  long double v13; // st7
  double v14; // st6
  double v15; // st5
  double v16; // st7
  Scaleform::GFx::DrawingContext *pObject; // ecx
  Scaleform::GFx::DrawingContext *v18; // ecx
  double v19; // st7
  Scaleform::StringDataPtr arg1; // [esp+8h] [ebp-88h]
  Scaleform::StringDataPtr arg1a; // [esp+8h] [ebp-88h]
  Scaleform::StringDataPtr arg1b; // [esp+8h] [ebp-88h]
  float arg1c; // [esp+8h] [ebp-88h]
  float arg1d; // [esp+8h] [ebp-88h]
  float arg1e; // [esp+8h] [ebp-88h]
  float arg1_4; // [esp+Ch] [ebp-84h]
  float arg1_4a; // [esp+Ch] [ebp-84h]
  float arg1_4b; // [esp+Ch] [ebp-84h]
  float arg1_4c; // [esp+Ch] [ebp-84h]
  float fexcenter; // [esp+3Ch] [ebp-54h]
  float fexradius; // [esp+40h] [ebp-50h]
  float feycenter; // [esp+44h] [ebp-4Ch]
  float feycentera; // [esp+44h] [ebp-4Ch]
  float feyradius; // [esp+48h] [ebp-48h]
  float fx; // [esp+4Ch] [ebp-44h]
  float fy; // [esp+50h] [ebp-40h]
  float v37; // [esp+54h] [ebp-3Ch]
  float fy1; // [esp+58h] [ebp-38h]
  float fy1a; // [esp+58h] [ebp-38h]
  float fy1b; // [esp+58h] [ebp-38h]
  float fx1; // [esp+5Ch] [ebp-34h]
  float fx1a; // [esp+5Ch] [ebp-34h]
  float fx1b; // [esp+5Ch] [ebp-34h]
  float fx1c; // [esp+5Ch] [ebp-34h]
  float fx1d; // [esp+5Ch] [ebp-34h]
  float fx1e; // [esp+5Ch] [ebp-34h]
  float fx1f; // [esp+5Ch] [ebp-34h]
  float fhalfHeight; // [esp+60h] [ebp-30h]
  float fhalfHeighta; // [esp+60h] [ebp-30h]
  float fhalfHeightb; // [esp+60h] [ebp-30h]
  float fhalfHeightc; // [esp+60h] [ebp-30h]
  float fhalfHeightd; // [esp+60h] [ebp-30h]
  float fhalfHeighte; // [esp+60h] [ebp-30h]
  float fhalfWidth; // [esp+64h] [ebp-2Ch]
  float fhalfWidtha; // [esp+64h] [ebp-2Ch]
  float fhalfWidthb; // [esp+64h] [ebp-2Ch]
  float fhalfWidthc; // [esp+64h] [ebp-2Ch]
  float fhalfWidthd; // [esp+64h] [ebp-2Ch]
  float fhalfWidthe; // [esp+64h] [ebp-2Ch]
  float v62; // [esp+68h] [ebp-28h]
  float v63; // [esp+68h] [ebp-28h]
  float v64; // [esp+68h] [ebp-28h]
  float v65; // [esp+68h] [ebp-28h]
  float v66; // [esp+68h] [ebp-28h]
  float v67; // [esp+68h] [ebp-28h]
  float v68; // [esp+68h] [ebp-28h]
  float v69; // [esp+68h] [ebp-28h]
  float v70; // [esp+68h] [ebp-28h]
  float v71; // [esp+68h] [ebp-28h]
  float v72; // [esp+68h] [ebp-28h]
  float v73; // [esp+68h] [ebp-28h]
  float v74; // [esp+68h] [ebp-28h]
  float v75; // [esp+68h] [ebp-28h]
  float v76; // [esp+68h] [ebp-28h]
  float v77; // [esp+68h] [ebp-28h]
  float v78; // [esp+68h] [ebp-28h]
  float v79; // [esp+68h] [ebp-28h]
  float v80; // [esp+68h] [ebp-28h]
  float v81; // [esp+68h] [ebp-28h]
  float v82; // [esp+68h] [ebp-28h]
  float v83; // [esp+68h] [ebp-28h]
  float v84; // [esp+68h] [ebp-28h]
  float v85; // [esp+68h] [ebp-28h]
  float v86; // [esp+68h] [ebp-28h]
  float v87; // [esp+68h] [ebp-28h]
  float v88; // [esp+68h] [ebp-28h]
  float v89; // [esp+68h] [ebp-28h]
  float v90; // [esp+68h] [ebp-28h]
  float v91; // [esp+68h] [ebp-28h]
  float v92; // [esp+68h] [ebp-28h]
  float v93; // [esp+68h] [ebp-28h]
  double v94; // [esp+70h] [ebp-20h]
  Scaleform::GFx::AS3::VM::Error v95; // [esp+78h] [ebp-18h] BYREF
  double v96; // [esp+80h] [ebp-10h]
  double v97; // [esp+88h] [ebp-8h]

  if ( (HIDWORD(width) & 0x7FF00000) == 0x7FF00000 && HIDWORD(width) & 0xFFFFF | LODWORD(width) )
  {
    arg1.pStr = "width";
    arg1.Size = 5;
    Scaleform::GFx::AS3::VM::Error::Error(&v95, eInvalidArgumentError, this->pTraits.pObject->pVM, arg1);
    pVM = this->pTraits.pObject->pVM;
LABEL_4:
    Scaleform::GFx::AS3::VM::ThrowArgumentError(pVM, v9);
    goto LABEL_5;
  }
  if ( (HIDWORD(height) & 0x7FF00000) == 0x7FF00000 && HIDWORD(height) & 0xFFFFF | LODWORD(height) )
  {
    arg1a.pStr = "height";
    arg1a.Size = 6;
    Scaleform::GFx::AS3::VM::Error::Error(&v95, eInvalidArgumentError, this->pTraits.pObject->pVM, arg1a);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(this->pTraits.pObject->pVM, v12);
LABEL_5:
    pNode = v95.Message.pNode;
    --v95.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    return;
  }
  if ( Scaleform::GFx::NumberUtil::IsNaN(ellipseWidth) )
  {
    arg1b.pStr = "ellipseWidth";
    arg1b.Size = 12;
    Scaleform::GFx::AS3::VM::Error::Error(&v95, eInvalidArgumentError, this->pTraits.pObject->pVM, arg1b);
    pVM = this->pTraits.pObject->pVM;
    goto LABEL_4;
  }
  if ( Scaleform::GFx::NumberUtil::IsNaN(ellipseHeight) )
    v13 = ellipseWidth;
  else
    v13 = ellipseHeight;
  fx = x;
  fy = y;
  v62 = width;
  v14 = v62;
  fx1 = v62 + fx;
  v63 = height;
  fy1 = v63 + fy;
  fhalfWidth = v14 * 0.5;
  fhalfHeight = v63 * 0.5;
  v64 = ellipseWidth;
  v65 = v64 * 0.5;
  v15 = v65;
  if ( fhalfWidth <= (double)v65 )
    v15 = fhalfWidth;
  fexradius = v15;
  v66 = v13;
  v67 = 0.5 * v66;
  v16 = v67;
  if ( fhalfHeight <= (double)v67 )
    v16 = fhalfHeight;
  feyradius = v16;
  v37 = fx1 - fexradius;
  v68 = fy1 - feyradius;
  feycenter = v68;
  v69 = v68 * 20.0;
  arg1_4 = v69;
  v70 = fx1 * 20.0;
  Scaleform::GFx::DrawingContext::MoveTo(this->pDrawing.pObject, v70, arg1_4);
  pObject = this->pDrawing.pObject;
  v96 = feyradius * 0.7071067690849304;
  v71 = v96 + feycenter;
  fx1a = v71 * 20.0;
  v94 = 0.7071067690849304 * fexradius;
  v97 = feyradius * 0.4142135679721832;
  v72 = feycenter + v97;
  fhalfWidtha = v72 * 20.0;
  v73 = v94 + v37;
  v74 = v73 * 20.0;
  arg1c = v74;
  v75 = fexradius + v37;
  v76 = 20.0 * v75;
  Scaleform::GFx::DrawingContext::CurveTo(pObject, v76, fhalfWidtha, arg1c, fx1a);
  v77 = feycenter + feyradius;
  v18 = this->pDrawing.pObject;
  fhalfHeighta = v77 * 20.0;
  *(double *)&v95 = fexradius * 0.4142135679721832;
  v78 = v37 * 20.0;
  arg1d = v78;
  v79 = *(double *)&v95 + v37;
  v80 = 20.0 * v79;
  Scaleform::GFx::DrawingContext::CurveTo(v18, v80, fhalfHeighta, arg1d, fhalfHeighta);
  fexcenter = fexradius + fx;
  v81 = fy1 * 20.0;
  arg1_4a = v81;
  v82 = 20.0 * fexcenter;
  Scaleform::GFx::DrawingContext::LineTo(this->pDrawing.pObject, v82, arg1_4a);
  v83 = fexcenter - v94;
  fy1a = v83 * 20.0;
  v84 = fexcenter - *(double *)&v95;
  v85 = 20.0 * v84;
  Scaleform::GFx::DrawingContext::CurveTo(this->pDrawing.pObject, v85, fhalfHeighta, fy1a, fx1a);
  fhalfHeightb = fexcenter - fexradius;
  fhalfHeightc = fhalfHeightb * 20.0;
  fx1b = 20.0 * feycenter;
  Scaleform::GFx::DrawingContext::CurveTo(this->pDrawing.pObject, fhalfHeightc, fhalfWidtha, fhalfHeightc, fx1b);
  fhalfWidthb = feyradius + fy;
  fx1c = fhalfWidthb * 20.0;
  arg1_4b = fx1c;
  fx1d = 20.0 * fx;
  Scaleform::GFx::DrawingContext::LineTo(this->pDrawing.pObject, fx1d, arg1_4b);
  feycentera = fhalfWidthb;
  v19 = fhalfWidthb;
  fhalfWidthc = fhalfWidthb - v96;
  fhalfWidthd = fhalfWidthc * 20.0;
  fx1e = v19 - v97;
  fx1f = 20.0 * fx1e;
  Scaleform::GFx::DrawingContext::CurveTo(this->pDrawing.pObject, fhalfHeightc, fx1f, fy1a, fhalfWidthd);
  fhalfHeightd = feycentera - feyradius;
  fhalfHeighte = fhalfHeightd * 20.0;
  fy1b = 20.0 * fexcenter;
  Scaleform::GFx::DrawingContext::CurveTo(this->pDrawing.pObject, v85, fhalfHeighte, fy1b, fhalfHeighte);
  v86 = fy * 20.0;
  arg1_4c = v86;
  v87 = 20.0 * v37;
  Scaleform::GFx::DrawingContext::LineTo(this->pDrawing.pObject, v87, arg1_4c);
  v88 = v94 + v37;
  v89 = v88 * 20.0;
  arg1e = v89;
  v90 = v37 + *(double *)&v95;
  v91 = 20.0 * v90;
  Scaleform::GFx::DrawingContext::CurveTo(this->pDrawing.pObject, v91, fhalfHeighte, arg1e, fhalfWidthd);
  v92 = v37 + fexradius;
  fhalfWidthe = v92 * 20.0;
  v93 = 20.0 * feycentera;
  Scaleform::GFx::DrawingContext::CurveTo(this->pDrawing.pObject, fhalfWidthe, fx1f, fhalfWidthe, v93);
  Scaleform::GFx::DisplayObjectBase::InvalidateHitResult(this->pDispObj);
}
