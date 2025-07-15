Scaleform::Render::Rect<float> *__thiscall Scaleform::GFx::AS3::ShapeObject::GetBounds(
        Scaleform::GFx::AS3::ShapeObject *this,
        Scaleform::Render::Rect<float> *result,
        Scaleform::Render::Matrix2x4<float> *transform)
{
  Scaleform::GFx::DrawingContext *pObject; // eax
  Scaleform::GFx::ShapeBaseCharacterDef *v5; // ebx
  int (__thiscall **p_GetBoundsLocal)(Scaleform::GFx::ShapeBaseCharacterDef *, Scaleform::Render::Rect<float> *, _DWORD); // edi
  __m128 *v7; // eax
  float bottom; // [esp+1Ch] [ebp-34h]
  Scaleform::Render::Rect<float> pRect; // [esp+30h] [ebp-20h] BYREF
  __m128 left; // [esp+40h] [ebp-10h] BYREF

  pObject = this->pDrawing.pObject;
  result->x1 = 0.0;
  result->y1 = 0.0;
  result->x2 = 0.0;
  result->y2 = 0.0;
  if ( !pObject )
  {
    v5 = this->pDef.pObject;
    p_GetBoundsLocal = (int (__thiscall **)(Scaleform::GFx::ShapeBaseCharacterDef *, Scaleform::Render::Rect<float> *, _DWORD))&v5->GetBoundsLocal;
    bottom = this->GetRatio(this);
    v7 = (__m128 *)(*p_GetBoundsLocal)(v5, &pRect, LODWORD(bottom));
    Scaleform::Render::Matrix2x4<float>::EncloseTransform(transform, &left, v7);
    *(__m128 *)result = left;
    return result;
  }
  pRect.x1 = 0.0;
  pRect.y1 = 0.0;
  pRect.x2 = 0.0;
  pRect.y2 = 0.0;
  Scaleform::GFx::DrawingContext::ComputeBound(pObject, &pRect);
  if ( pRect.x2 <= (double)pRect.x1 || pRect.y2 <= (double)pRect.y1 )
    return result;
  Scaleform::Render::Matrix2x4<float>::EncloseTransform(transform, &left, (__m128 *)&pRect);
  pRect.x1 = left.m128_f32[0];
  pRect.y1 = left.m128_f32[1];
  pRect.x2 = left.m128_f32[2];
  pRect.y2 = left.m128_f32[3];
  if ( result->x2 <= (double)result->x1 || result->y2 <= (double)result->y1 )
  {
    Scaleform::Render::Rect<float>::operator=(result, &pRect);
    return result;
  }
  else
  {
    Scaleform::Render::Rect<float>::Union(
      result,
      left.m128_f32[0],
      left.m128_f32[1],
      left.m128_f32[2],
      left.m128_f32[3]);
    return result;
  }
}
