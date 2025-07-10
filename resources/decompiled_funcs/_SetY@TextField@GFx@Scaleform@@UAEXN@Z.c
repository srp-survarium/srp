void __thiscall Scaleform::GFx::TextField::SetY(Scaleform::GFx::TextField *this, double y)
{
  double v2; // st7
  const Scaleform::Render::Matrix2x4<float> *(__thiscall *GetMatrix)(Scaleform::GFx::DisplayObjectBase *); // edx
  float *v5; // eax
  const Scaleform::Render::Rect<float> *ViewRect; // eax
  Scaleform::GFx::DisplayObjectBase::GeomDataType *pGeomData; // esi
  Scaleform::Render::Point<float> v8; // [esp+84h] [ebp-38h] BYREF
  Scaleform::Render::Point<float> result; // [esp+8Ch] [ebp-30h] BYREF
  double v10; // [esp+94h] [ebp-28h]
  Scaleform::Render::Matrix2x4<float> v11; // [esp+9Ch] [ebp-20h] BYREF

  v2 = y;
  *(double *)&v8 = y;
  if ( (LODWORD(v8.y) & 0x7FF00000) != 0x7FF00000 || !((unsigned int)&loc_FFFFF & LODWORD(v8.y) | LODWORD(v8.x)) )
  {
    *(double *)&v8 = y;
    if ( y == -INFINITY || (*(double *)&v8 = y, y == INFINITY) )
      v2 = 0.0;
    GetMatrix = this->GetMatrix;
    v10 = v2 * 20.0;
    v5 = (float *)GetMatrix(this);
    v11.M[0][0] = *v5;
    v11.M[0][1] = v5[1];
    v11.M[0][2] = v5[2];
    v11.M[0][3] = v5[3];
    v11.M[1][0] = v5[4];
    v11.M[1][1] = v5[5];
    v11.M[1][2] = v5[6];
    v11.M[1][3] = v5[7];
    v8.x = 0.0;
    v8.y = v10;
    Scaleform::Render::Matrix2x4<float>::TransformByInverse(&v11, &result, &v8);
    ViewRect = Scaleform::Render::Text::DocView::GetViewRect(this->pDocument.pObject);
    v8.y = result.y - ViewRect->y1;
    v8.y = v11.M[1][1] * v8.y + v11.M[1][0] * result.x + v11.M[1][3];
    v8.x = v8.y * 0.05000000074505806;
    Scaleform::GFx::DisplayObjectBase::SetY(this, v8.x);
    pGeomData = this->pGeomData;
    if ( pGeomData )
    {
      if ( v10 <= 0.0 )
        pGeomData->Y = (int)(v10 - 0.5);
      else
        pGeomData->Y = (int)(v10 + 0.5);
    }
  }
}
