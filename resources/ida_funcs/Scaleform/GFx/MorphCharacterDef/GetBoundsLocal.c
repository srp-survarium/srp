Scaleform::Render::Rect<float> *__thiscall Scaleform::GFx::MorphCharacterDef::GetBoundsLocal(
        Scaleform::GFx::MorphCharacterDef *this,
        Scaleform::Render::Rect<float> *result,
        float morphRatio)
{
  Scaleform::Render::ShapeMeshProvider *pObject; // ecx
  float v5[8]; // [esp+1Ch] [ebp-20h] BYREF

  pObject = this->pShapeMeshProvider.pObject;
  v5[0] = 1.0;
  v5[1] = 0.0;
  v5[2] = 0.0;
  v5[3] = 0.0;
  v5[4] = 0.0;
  v5[6] = 0.0;
  v5[7] = 0.0;
  v5[5] = 1.0;
  ((void (__thiscall *)(Scaleform::Render::MeshProvider *, Scaleform::Render::Rect<float> *, float *, _DWORD, _DWORD, _DWORD))pObject->GetCorrectBounds)(
    &pObject->Scaleform::Render::MeshProvider,
    result,
    v5,
    LODWORD(morphRatio),
    0,
    0);
  return result;
}
