Scaleform::Render::Point<float> *__thiscall Scaleform::GFx::TextField::TransformToTextRectSpace(
        Scaleform::GFx::TextField *this,
        Scaleform::Render::Point<float> *result,
        const Scaleform::GFx::Value::DisplayInfo *info)
{
  Scaleform::Render::Matrix2x4<float> *v4; // edi
  long double Y; // st6
  bool v6; // zf
  long double X; // st7
  const Scaleform::Render::Rect<float> *ViewRect; // eax
  double y1; // st7
  Scaleform::Render::Point<float> *v10; // eax
  double v11; // st7
  Scaleform::Render::Point<float> resulta; // [esp+Ch] [ebp-8h] BYREF
  float v13; // [esp+1Ch] [ebp+8h]
  float v14; // [esp+1Ch] [ebp+8h]
  float v15; // [esp+1Ch] [ebp+8h]

  v4 = (Scaleform::Render::Matrix2x4<float> *)this->GetMatrix(this);
  if ( (info->VarsSet & 2) != 0 )
    Y = info->Y * 20.0;
  else
    Y = (double)this->pGeomData->Y;
  v6 = (info->VarsSet & 1) == 0;
  resulta.x = Y;
  if ( v6 )
    X = (double)this->pGeomData->X;
  else
    X = 20.0 * info->X;
  v13 = X;
  result->x = v13;
  result->y = resulta.x;
  Scaleform::Render::Matrix2x4<float>::TransformByInverse(v4, &resulta, result);
  *result = resulta;
  ViewRect = Scaleform::Render::Text::DocView::GetViewRect(this->pDocument.pObject);
  resulta.x = ViewRect->x1;
  y1 = ViewRect->y1;
  v10 = result;
  resulta.y = y1;
  v14 = result->x - resulta.x;
  v11 = v14;
  result->x = v14;
  v15 = result->y - resulta.y;
  result->y = v15;
  resulta.x = v11 * v4->M[0][0] + v4->M[0][1] * v15 + v4->M[0][3];
  resulta.y = v15 * v4->M[1][1] + v4->M[1][0] * result->x + v4->M[1][3];
  result->x = resulta.x * 0.05000000074505806;
  result->y = 0.05000000074505806 * resulta.y;
  return v10;
}
