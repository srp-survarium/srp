Scaleform::GFx::DisplayObjectBase::GeomDataType *__thiscall Scaleform::GFx::TextField::UpdateAndGetGeomData(
        Scaleform::GFx::TextField *this,
        Scaleform::GFx::DisplayObjectBase::GeomDataType *pgeomData,
        bool force)
{
  const Scaleform::Render::Rect<float> *ViewRect; // eax
  float *v5; // eax
  double v6; // st6
  double v7; // st7
  double v8; // st6
  double v9; // st7
  float x1; // [esp+60h] [ebp-30h]
  float y1; // [esp+64h] [ebp-2Ch]

  Scaleform::GFx::DisplayObjectBase::GetGeomData(this, pgeomData);
  if ( force || (this->Flags & 0x2000) != 0 )
  {
    ViewRect = Scaleform::Render::Text::DocView::GetViewRect(this->pDocument.pObject);
    x1 = ViewRect->x1;
    y1 = ViewRect->y1;
    v5 = (float *)this->GetMatrix(this);
    v6 = v5[1] * y1 + *v5 * x1 + v5[3];
    v7 = y1 * v5[5] + x1 * v5[4] + v5[7];
    if ( v6 <= 0.0 )
      v8 = v6 - 0.5;
    else
      v8 = v6 + 0.5;
    pgeomData->X = (int)v8;
    if ( v7 <= 0.0 )
      v9 = v7 - 0.5;
    else
      v9 = v7 + 0.5;
    pgeomData->Y = (int)v9;
    Scaleform::GFx::DisplayObjectBase::SetGeomData(this, pgeomData);
    this->Flags &= ~0x2000u;
  }
  return pgeomData;
}
