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
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v10; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  long double v12; // st7
  double v13; // st6
  double v14; // st5
  double v15; // st7
  Scaleform::GFx::DrawingContext *pObject; // ecx
  Scaleform::GFx::DrawingContext *v17; // ecx
  double v18; // st7
  float v; // [esp+8h] [ebp-88h]
  float va; // [esp+8h] [ebp-88h]
  float vb; // [esp+8h] [ebp-88h]
  float v_4; // [esp+Ch] [ebp-84h]
  float v_4a; // [esp+Ch] [ebp-84h]
  float v_4b; // [esp+Ch] [ebp-84h]
  float v_4c; // [esp+Ch] [ebp-84h]
  float fexcenter; // [esp+3Ch] [ebp-54h]
  float fexradius; // [esp+40h] [ebp-50h]
  float feycenter; // [esp+44h] [ebp-4Ch]
  float feycentera; // [esp+44h] [ebp-4Ch]
  float feyradius; // [esp+48h] [ebp-48h]
  float fx; // [esp+4Ch] [ebp-44h]
  float fy; // [esp+50h] [ebp-40h]
  float v33; // [esp+54h] [ebp-3Ch]
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
  float v58; // [esp+68h] [ebp-28h]
  float v59; // [esp+68h] [ebp-28h]
  float v60; // [esp+68h] [ebp-28h]
  float v61; // [esp+68h] [ebp-28h]
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
  double v90; // [esp+70h] [ebp-20h]
  Scaleform::GFx::AS3::VM::Error v91; // [esp+78h] [ebp-18h] BYREF
  double v92; // [esp+80h] [ebp-10h]
  double v93; // [esp+88h] [ebp-8h]

  if ( (HIDWORD(width) & 0x7FF00000) == 0x7FF00000 && (unsigned int)&loc_FFFFF & HIDWORD(width) | LODWORD(width) )
  {
    pVM = this->pTraits.pObject->pVM;
    goto LABEL_4;
  }
  if ( (HIDWORD(height) & 0x7FF00000) == 0x7FF00000 && (unsigned int)&loc_FFFFF & HIDWORD(height) | LODWORD(height) )
  {
    pVM = this->pTraits.pObject->pVM;
    goto LABEL_4;
  }
  if ( Scaleform::GFx::NumberUtil::IsNaN(ellipseWidth) )
  {
    pVM = this->pTraits.pObject->pVM;
LABEL_4:
    Scaleform::GFx::AS3::VM::Error::Error(&v91, eInvalidArgumentError, pVM);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(pVM, v10);
    pNode = v91.Message.pNode;
    --v91.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    return;
  }
  if ( Scaleform::GFx::NumberUtil::IsNaN(ellipseHeight) )
    v12 = ellipseWidth;
  else
    v12 = ellipseHeight;
  fx = x;
  fy = y;
  v58 = width;
  v13 = v58;
  fx1 = v58 + fx;
  v59 = height;
  fy1 = v59 + fy;
  fhalfWidth = v13 * 0.5;
  fhalfHeight = v59 * 0.5;
  v60 = ellipseWidth;
  v61 = v60 * 0.5;
  v14 = v61;
  if ( fhalfWidth <= (double)v61 )
    v14 = fhalfWidth;
  fexradius = v14;
  v62 = v12;
  v63 = 0.5 * v62;
  v15 = v63;
  if ( fhalfHeight <= (double)v63 )
    v15 = fhalfHeight;
  feyradius = v15;
  v33 = fx1 - fexradius;
  v64 = fy1 - feyradius;
  feycenter = v64;
  v65 = v64 * 20.0;
  v_4 = v65;
  v66 = fx1 * 20.0;
  Scaleform::GFx::DrawingContext::MoveTo(this->pDrawing.pObject, v66, v_4);
  pObject = this->pDrawing.pObject;
  v92 = feyradius * 0.7071067690849304;
  v67 = v92 + feycenter;
  fx1a = v67 * 20.0;
  v90 = 0.7071067690849304 * fexradius;
  v93 = feyradius * 0.4142135679721832;
  v68 = feycenter + v93;
  fhalfWidtha = v68 * 20.0;
  v69 = v90 + v33;
  v70 = v69 * 20.0;
  v = v70;
  v71 = fexradius + v33;
  v72 = 20.0 * v71;
  Scaleform::GFx::DrawingContext::CurveTo(pObject, v72, fhalfWidtha, v, fx1a);
  v73 = feycenter + feyradius;
  v17 = this->pDrawing.pObject;
  fhalfHeighta = v73 * 20.0;
  *(double *)&v91 = fexradius * 0.4142135679721832;
  v74 = v33 * 20.0;
  va = v74;
  v75 = *(double *)&v91 + v33;
  v76 = 20.0 * v75;
  Scaleform::GFx::DrawingContext::CurveTo(v17, v76, fhalfHeighta, va, fhalfHeighta);
  fexcenter = fexradius + fx;
  v77 = fy1 * 20.0;
  v_4a = v77;
  v78 = 20.0 * fexcenter;
  Scaleform::GFx::DrawingContext::LineTo(this->pDrawing.pObject, v78, v_4a);
  v79 = fexcenter - v90;
  fy1a = v79 * 20.0;
  v80 = fexcenter - *(double *)&v91;
  v81 = 20.0 * v80;
  Scaleform::GFx::DrawingContext::CurveTo(this->pDrawing.pObject, v81, fhalfHeighta, fy1a, fx1a);
  fhalfHeightb = fexcenter - fexradius;
  fhalfHeightc = fhalfHeightb * 20.0;
  fx1b = 20.0 * feycenter;
  Scaleform::GFx::DrawingContext::CurveTo(this->pDrawing.pObject, fhalfHeightc, fhalfWidtha, fhalfHeightc, fx1b);
  fhalfWidthb = feyradius + fy;
  fx1c = fhalfWidthb * 20.0;
  v_4b = fx1c;
  fx1d = 20.0 * fx;
  Scaleform::GFx::DrawingContext::LineTo(this->pDrawing.pObject, fx1d, v_4b);
  feycentera = fhalfWidthb;
  v18 = fhalfWidthb;
  fhalfWidthc = fhalfWidthb - v92;
  fhalfWidthd = fhalfWidthc * 20.0;
  fx1e = v18 - v93;
  fx1f = 20.0 * fx1e;
  Scaleform::GFx::DrawingContext::CurveTo(this->pDrawing.pObject, fhalfHeightc, fx1f, fy1a, fhalfWidthd);
  fhalfHeightd = feycentera - feyradius;
  fhalfHeighte = fhalfHeightd * 20.0;
  fy1b = 20.0 * fexcenter;
  Scaleform::GFx::DrawingContext::CurveTo(this->pDrawing.pObject, v81, fhalfHeighte, fy1b, fhalfHeighte);
  v82 = fy * 20.0;
  v_4c = v82;
  v83 = 20.0 * v33;
  Scaleform::GFx::DrawingContext::LineTo(this->pDrawing.pObject, v83, v_4c);
  v84 = v90 + v33;
  v85 = v84 * 20.0;
  vb = v85;
  v86 = v33 + *(double *)&v91;
  v87 = 20.0 * v86;
  Scaleform::GFx::DrawingContext::CurveTo(this->pDrawing.pObject, v87, fhalfHeighte, vb, fhalfWidthd);
  v88 = v33 + fexradius;
  fhalfWidthe = v88 * 20.0;
  v89 = 20.0 * feycentera;
  Scaleform::GFx::DrawingContext::CurveTo(this->pDrawing.pObject, fhalfWidthe, fx1f, fhalfWidthe, v89);
  Scaleform::GFx::DisplayObjectBase::InvalidateHitResult(this->pDispObj);
}
