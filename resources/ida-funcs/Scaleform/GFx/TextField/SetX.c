void __thiscall Scaleform::GFx::TextField::SetX(Scaleform::GFx::TextField *this, double x)
{
  float *v3; // eax
  const Scaleform::Render::Rect<float> *ViewRect; // eax
  Scaleform::GFx::DisplayObjectBase::GeomDataType *pGeomData; // esi
  Scaleform::Render::Point<float> p; // [esp+10h] [ebp-38h] BYREF
  Scaleform::Render::Point<float> result; // [esp+18h] [ebp-30h] BYREF
  double v8; // [esp+20h] [ebp-28h]
  Scaleform::Render::Matrix2x4<float> v9; // [esp+28h] [ebp-20h] BYREF

  *(double *)&p = x;
  if ( (LODWORD(p.y) & 0x7FF00000) != 0x7FF00000 || !(LODWORD(p.y) & 0xFFFFF | LODWORD(p.x)) )
  {
    *(double *)&p = x;
    if ( x == -INFINITY || (*(double *)&p = x, x == INFINITY) )
      x = 0.0;
    v3 = (float *)this->GetMatrix(this);
    v9.M[0][0] = *v3;
    v9.M[0][1] = v3[1];
    v9.M[0][2] = v3[2];
    v9.M[0][3] = v3[3];
    v9.M[1][0] = v3[4];
    v9.M[1][1] = v3[5];
    v9.M[1][2] = v3[6];
    v9.M[1][3] = v3[7];
    v8 = x * 20.0;
    p.x = v8;
    p.y = p.x;
    Scaleform::Render::Matrix2x4<float>::TransformByInverse(&v9, &result, &p);
    ViewRect = Scaleform::Render::Text::DocView::GetViewRect(this->pDocument.pObject);
    p.x = result.x - ViewRect->x1;
    p.x = result.y * v9.M[0][1] + v9.M[0][0] * p.x + v9.M[0][3];
    p.x = p.x * 0.05000000074505806;
    Scaleform::GFx::DisplayObjectBase::SetX(this, p.x);
    pGeomData = this->pGeomData;
    if ( pGeomData )
    {
      if ( v8 <= 0.0 )
        pGeomData->X = (int)(v8 - 0.5);
      else
        pGeomData->X = (int)(v8 + 0.5);
    }
  }
}
