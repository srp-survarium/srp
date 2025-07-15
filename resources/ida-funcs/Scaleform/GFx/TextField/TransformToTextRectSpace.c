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
  Scaleform::Render::Point<float> r; // [esp+Ch] [ebp-8h] BYREF
  float infoa; // [esp+1Ch] [ebp+8h]
  float infob; // [esp+1Ch] [ebp+8h]
  float infoc; // [esp+1Ch] [ebp+8h]

  v4 = (Scaleform::Render::Matrix2x4<float> *)this->GetMatrix(this);
  if ( (info->VarsSet & 2) != 0 )
    Y = info->Y * 20.0;
  else
    Y = (double)this->pGeomData->Y;
  v6 = (info->VarsSet & 1) == 0;
  r.x = Y;
  if ( v6 )
    X = (double)this->pGeomData->X;
  else
    X = 20.0 * info->X;
  infoa = X;
  result->x = infoa;
  result->y = r.x;
  Scaleform::Render::Matrix2x4<float>::TransformByInverse(v4, &r, result);
  *result = r;
  ViewRect = Scaleform::Render::Text::DocView::GetViewRect(this->pDocument.pObject);
  r.x = ViewRect->x1;
  y1 = ViewRect->y1;
  v10 = result;
  r.y = y1;
  infob = result->x - r.x;
  v11 = infob;
  result->x = infob;
  infoc = result->y - r.y;
  result->y = infoc;
  r.x = v11 * v4->M[0][0] + v4->M[0][1] * infoc + v4->M[0][3];
  r.y = infoc * v4->M[1][1] + v4->M[1][0] * result->x + v4->M[1][3];
  result->x = r.x * 0.05000000074505806;
  result->y = 0.05000000074505806 * r.y;
  return v10;
}
