Scaleform::Render::Rect<float> *__thiscall Scaleform::GFx::AS3::ShapeObject::GetRectBounds(
        Scaleform::GFx::AS3::ShapeObject *this,
        Scaleform::Render::Rect<float> *result,
        Scaleform::Render::Matrix2x4<float> *transform)
{
  __m128 *v3; // eax
  _BYTE v5[16]; // [esp+14h] [ebp-10h] BYREF

  v3 = (__m128 *)((int (__stdcall *)(_BYTE *, _DWORD))this->pDef.pObject->GetRectBoundsLocal)(v5, 0.0);
  Scaleform::Render::Matrix2x4<float>::EncloseTransform(transform, result, v3);
  return result;
}
