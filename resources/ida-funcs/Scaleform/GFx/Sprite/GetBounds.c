Scaleform::Render::Rect<float> *__thiscall Scaleform::GFx::Sprite::GetBounds(
        Scaleform::GFx::Sprite *this,
        Scaleform::Render::Rect<float> *result,
        Scaleform::Render::Matrix2x4<float> *transform)
{
  Scaleform::GFx::DrawingContext *pObject; // ecx
  Scaleform::Render::Rect<float> pRect; // [esp+30h] [ebp-20h] BYREF
  Scaleform::Render::Rect<float> pr; // [esp+40h] [ebp-10h] BYREF

  Scaleform::GFx::DisplayList::GetBounds(&this->mDisplayList, result, transform);
  pObject = this->pDrawingAPI.pObject;
  if ( pObject )
  {
    pRect.x1 = 0.0;
    pRect.y1 = 0.0;
    pRect.x2 = 0.0;
    pRect.y2 = 0.0;
    Scaleform::GFx::DrawingContext::ComputeBound(pObject, &pRect);
    if ( pRect.x2 > (double)pRect.x1 && pRect.y2 > (double)pRect.y1 )
    {
      Scaleform::Render::Matrix2x4<float>::EncloseTransform(transform, &pr, (__m128 *)&pRect);
      pRect.x1 = pr.x1;
      pRect.y1 = pr.y1;
      pRect.x2 = pr.x2;
      pRect.y2 = pr.y2;
      if ( result->x2 > (double)result->x1 && result->y2 > (double)result->y1 )
      {
        Scaleform::Render::Rect<float>::Union(result, pr.x1, pr.y1, pr.x2, pr.y2);
        return result;
      }
      Scaleform::Render::Rect<float>::operator=(result, &pRect);
    }
  }
  return result;
}
