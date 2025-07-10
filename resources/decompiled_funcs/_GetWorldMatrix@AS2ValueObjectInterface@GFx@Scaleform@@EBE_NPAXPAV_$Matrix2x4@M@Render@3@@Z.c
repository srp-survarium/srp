char __thiscall Scaleform::GFx::AS2ValueObjectInterface::GetWorldMatrix(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::CharacterHandle *pdata,
        Scaleform::Render::Matrix2x4<float> *pmat)
{
  Scaleform::GFx::InteractiveObject *v3; // eax
  Scaleform::Render::Matrix2x4<float> v5; // [esp+20h] [ebp-20h] BYREF

  v3 = Scaleform::GFx::CharacterHandle::ResolveCharacter(pdata, this->pMovieRoot);
  if ( !v3 )
    return 0;
  v5.M[0][0] = 1.0;
  v5.M[0][1] = 0.0;
  v5.M[0][2] = 0.0;
  v5.M[0][3] = 0.0;
  v5.M[1][0] = 0.0;
  v5.M[1][2] = 0.0;
  v5.M[1][3] = 0.0;
  v5.M[1][1] = 1.0;
  Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(v3, &v5);
  v5.M[0][3] = v5.M[0][3] * 0.05000000074505806;
  v5.M[1][3] = 0.05000000074505806 * v5.M[1][3];
  *pmat = v5;
  return 1;
}
