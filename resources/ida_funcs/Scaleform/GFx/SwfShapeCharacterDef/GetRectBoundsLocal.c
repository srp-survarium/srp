Scaleform::Render::Rect<float> *__thiscall Scaleform::GFx::SwfShapeCharacterDef::GetRectBoundsLocal(
        Scaleform::GFx::SwfShapeCharacterDef *this,
        Scaleform::Render::Rect<float> *result,
        float mr)
{
  float *v4; // eax
  double v5; // st7
  Scaleform::Render::Rect<float> *v6; // eax
  float v7[4]; // [esp+30h] [ebp-20h] BYREF
  _BYTE v8[16]; // [esp+40h] [ebp-10h] BYREF

  this->pShape.pObject->GetRectBoundsLocal(this->pShape.pObject, (Scaleform::Render::Rect<float> *)v7);
  if ( v7[2] > (double)v7[0] && v7[3] > (double)v7[1] )
    v4 = v7;
  else
    v4 = (float *)((int (__thiscall *)(Scaleform::GFx::SwfShapeCharacterDef *, _BYTE *, _DWORD))this->GetBoundsLocal)(
                    this,
                    v8,
                    LODWORD(mr));
  result->x1 = *v4;
  result->y1 = v4[1];
  result->x2 = v4[2];
  v5 = v4[3];
  v6 = result;
  result->y2 = v5;
  return v6;
}
