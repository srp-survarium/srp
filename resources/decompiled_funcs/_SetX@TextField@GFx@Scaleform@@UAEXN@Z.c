void __thiscall Scaleform::GFx::TextField::SetX(Scaleform::GFx::TextField *this, double x)
{
  float *v3; // eax
  const Scaleform::Render::Rect<float> *ViewRect; // eax
  Scaleform::GFx::DisplayObjectBase::GeomDataType *pGeomData; // esi
  Scaleform::Render::Point<float> v6; // [esp+84h] [ebp-38h] BYREF
  Scaleform::Render::Point<float> result; // [esp+8Ch] [ebp-30h] BYREF
  long double v8; // [esp+94h] [ebp-28h]
  Scaleform::Render::Matrix2x4<float> v9; // [esp+9Ch] [ebp-20h] BYREF

  *(double *)&v6 = x;
  if ( (LODWORD(v6.y) & 0x7FF00000) != 0x7FF00000 || !((unsigned int)&loc_FFFFF & LODWORD(v6.y) | LODWORD(v6.x)) )
  {
    *(double *)&v6 = x;
    if ( x == -INFINITY || (*(double *)&v6 = x, x == INFINITY) )
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
    v6.x = v8;
    v6.y = v6.x;
    Scaleform::Render::Matrix2x4<float>::TransformByInverse(&v9, &result, &v6);
    ViewRect = Scaleform::Render::Text::DocView::GetViewRect(this->pDocument.pObject);
    v6.x = result.x - ViewRect->x1;
    v6.x = result.y * v9.M[0][1] + v9.M[0][0] * v6.x + v9.M[0][3];
    v6.x = v6.x * 0.05000000074505806;
    Scaleform::GFx::DisplayObjectBase::SetX(this, v6.x);
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
