Scaleform::Render::Rect<float> *__thiscall Scaleform::GFx::MovieDefImpl::GetFrameRect(
        Scaleform::GFx::MovieDefImpl *this,
        Scaleform::Render::Rect<float> *result)
{
  float *pObject; // ecx
  double v3; // st7
  Scaleform::Render::Rect<float> *v4; // eax

  pObject = (float *)this->pBindData.pObject->pDataDef.pObject->pData.pObject;
  v3 = pObject[16];
  v4 = result;
  pObject += 16;
  result->x1 = v3 * 0.05000000074505806;
  result->y1 = pObject[1] * 0.05000000074505806;
  result->x2 = pObject[2] * 0.05000000074505806;
  result->y2 = 0.05000000074505806 * pObject[3];
  return v4;
}
