Scaleform::Render::Rect<float> *__thiscall Scaleform::GFx::AS2::GenericDisplayObj::GetRectBounds(
        Scaleform::GFx::AS2::GenericDisplayObj *this,
        Scaleform::Render::Rect<float> *result,
        Scaleform::Render::Matrix2x4<float> *transform)
{
  Scaleform::GFx::ShapeBaseCharacterDef *pObject; // edi
  int (__thiscall **p_GetRectBoundsLocal)(_DWORD, _DWORD, _DWORD); // esi
  __m128 *v5; // eax
  float v7; // [esp+0h] [ebp-24h]
  _BYTE v8[16]; // [esp+14h] [ebp-10h] BYREF

  pObject = this->pDef.pObject;
  p_GetRectBoundsLocal = (int (__thiscall **)(_DWORD, _DWORD, _DWORD))&pObject->GetRectBoundsLocal;
  v7 = ((double (*)(void))this->GetRatio)();
  v5 = (__m128 *)(*p_GetRectBoundsLocal)(pObject, v8, LODWORD(v7));
  Scaleform::Render::Matrix2x4<float>::EncloseTransform(transform, result, v5);
  return result;
}
