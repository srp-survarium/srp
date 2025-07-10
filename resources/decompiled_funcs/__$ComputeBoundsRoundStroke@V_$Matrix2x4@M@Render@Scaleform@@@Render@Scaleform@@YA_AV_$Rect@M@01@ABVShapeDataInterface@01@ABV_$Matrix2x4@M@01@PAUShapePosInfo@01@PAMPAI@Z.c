Scaleform::Render::Rect<float> *__cdecl Scaleform::Render::ComputeBoundsRoundStroke<Scaleform::Render::Matrix2x4<float>>(
        Scaleform::Render::Rect<float> *result,
        const Scaleform::Render::ShapeDataInterface *shape,
        Scaleform::Render::Matrix2x4<float> *trans,
        Scaleform::Render::ShapePosInfo *pos,
        float *coord,
        unsigned int *styles)
{
  void (__thiscall *GetStrokeStyle)(Scaleform::Render::ShapeDataInterface *, unsigned int, Scaleform::Render::StrokeStyleType *); // edx
  double Scale; // st7
  unsigned int v9; // [esp+54h] [ebp-38h]
  float v10; // [esp+6Ch] [ebp-20h]
  float v11; // [esp+6Ch] [ebp-20h]
  float v12; // [esp+6Ch] [ebp-20h]
  float v13; // [esp+6Ch] [ebp-20h]
  float v14; // [esp+6Ch] [ebp-20h]
  float v15; // [esp+6Ch] [ebp-20h]
  float v16; // [esp+6Ch] [ebp-20h]
  float v17; // [esp+70h] [ebp-1Ch] BYREF
  int v18; // [esp+78h] [ebp-14h]
  Scaleform::RefCountVImpl *v19; // [esp+84h] [ebp-8h]
  Scaleform::RefCountVImpl *v20; // [esp+88h] [ebp-4h]

  result->x1 = 1.0e30;
  result->y1 = 1.0e30;
  result->x2 = -1.0e30;
  result->y2 = -1.0e30;
  GetStrokeStyle = shape->GetStrokeStyle;
  v9 = styles[2];
  v19 = 0;
  v20 = 0;
  GetStrokeStyle(shape, v9, (Scaleform::Render::StrokeStyleType *)&v17);
  v10 = 1.0;
  switch ( v18 & 6 )
  {
    case 0:
      Scale = Scaleform::Render::Matrix2x4<float>::GetScale(trans);
      goto LABEL_7;
    case 2:
      v13 = trans->M[1][0] * trans->M[1][0] + trans->M[0][0] * trans->M[0][0];
      v14 = sqrt(v13);
      Scale = v14;
      goto LABEL_7;
    case 4:
      v11 = trans->M[1][1] * trans->M[1][1] + trans->M[0][1] * trans->M[0][1];
      v12 = sqrt(v11);
      Scale = v12;
LABEL_7:
      v10 = Scale;
      break;
  }
  v15 = v17 * v10;
  Scaleform::Render::ExpandBoundsToPath<Scaleform::Render::Matrix2x4<float>>(
    shape,
    *(float *)&trans,
    pos,
    *(float *)&coord,
    result);
  if ( result->x1 <= (double)result->x2 && result->y1 <= (double)result->y2 )
  {
    v16 = v15 * 0.5;
    result->x1 = result->x1 - v16;
    result->y1 = result->y1 - v16;
    result->x2 = result->x2 + v16;
    result->y2 = v16 + result->y2;
  }
  if ( v20 )
    Scaleform::RefCountImpl::Release(v20);
  if ( v19 )
    Scaleform::RefCountImpl::Release(v19);
  return result;
}
