char __thiscall Scaleform::GFx::AS2ValueObjectInterface::GetMatrix3D(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::CharacterHandle *pdata,
        Scaleform::Render::Matrix3x4<float> *pmat)
{
  Scaleform::GFx::InteractiveObject *v3; // eax
  unsigned __int8 *v5; // eax
  unsigned __int8 dst[48]; // [esp+30h] [ebp-30h] BYREF

  v3 = Scaleform::GFx::CharacterHandle::ResolveCharacter(pdata, this->pMovieRoot);
  if ( !v3 )
    return 0;
  v5 = (unsigned __int8 *)v3->GetMatrix3D(v3);
  memcpy(dst, v5, sizeof(dst));
  *(float *)&dst[12] = *(float *)&dst[12] * 0.05000000074505806;
  *(float *)&dst[28] = 0.05000000074505806 * *(float *)&dst[28];
  memcpy((unsigned __int8 *)pmat, dst, sizeof(Scaleform::Render::Matrix3x4<float>));
  return 1;
}
