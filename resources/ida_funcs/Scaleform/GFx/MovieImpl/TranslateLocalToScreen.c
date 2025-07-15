char __thiscall Scaleform::GFx::MovieImpl::TranslateLocalToScreen(
        Scaleform::GFx::MovieImpl *this,
        const char *pathToMovieClip,
        const Scaleform::Render::Point<float> *pt,
        Scaleform::Render::Point<float> *presPt,
        Scaleform::Render::Matrix2x4<float> *userMatrix)
{
  Scaleform::GFx::ASMovieRootBase *pObject; // ecx
  unsigned int v8; // ecx
  Scaleform::Render::Point<float> v9; // [esp+C8h] [ebp-60h]
  int v10; // [esp+D0h] [ebp-58h] BYREF
  unsigned int v11; // [esp+D4h] [ebp-54h]
  int v12; // [esp+D8h] [ebp-50h]
  Scaleform::Render::Matrix2x4<float> v13; // [esp+E8h] [ebp-40h] BYREF
  Scaleform::Render::Matrix2x4<float> m; // [esp+108h] [ebp-20h] BYREF

  pObject = this->pASMovieRoot.pObject;
  v10 = 0;
  v11 = 0;
  if ( !pObject->GetVariable(pObject, (Scaleform::GFx::Value *)&v10, pathToMovieClip) )
    goto LABEL_2;
  m.M[0][0] = 1.0;
  m.M[0][1] = 0.0;
  m.M[0][2] = 0.0;
  m.M[0][3] = 0.0;
  m.M[1][0] = 0.0;
  m.M[1][2] = 0.0;
  m.M[1][3] = 0.0;
  m.M[1][1] = 1.0;
  if ( (*(unsigned __int8 (__thiscall **)(int, int, Scaleform::Render::Matrix2x4<float> *))(*(_DWORD *)v10 + 100))(
         v10,
         v12,
         &m) )
  {
    v13.M[0][0] = this->ViewportMatrix.M[0][0];
    v13.M[0][1] = this->ViewportMatrix.M[0][1];
    v13.M[0][2] = this->ViewportMatrix.M[0][2];
    v13.M[0][3] = this->ViewportMatrix.M[0][3];
    v13.M[1][0] = this->ViewportMatrix.M[1][0];
    v13.M[1][1] = this->ViewportMatrix.M[1][1];
    v13.M[1][2] = this->ViewportMatrix.M[1][2];
    v13.M[1][3] = this->ViewportMatrix.M[1][3];
    v13.M[0][0] = v13.M[0][0] * 20.0;
    v13.M[0][1] = v13.M[0][1] * 20.0;
    v13.M[0][2] = v13.M[0][2] * 20.0;
    v13.M[0][3] = v13.M[0][3] * 20.0;
    v13.M[1][0] = v13.M[1][0] * 20.0;
    v13.M[1][1] = v13.M[1][1] * 20.0;
    v13.M[1][2] = v13.M[1][2] * 20.0;
    v13.M[1][3] = 20.0 * v13.M[1][3];
    if ( userMatrix )
      Scaleform::Render::Matrix2x4<float>::Prepend(&v13, userMatrix);
    Scaleform::Render::Matrix2x4<float>::Prepend(&v13, &m);
    v8 = v11 >> 6;
    v9.x = pt->y * v13.M[0][1] + pt->x * v13.M[0][0] + v13.M[0][3];
    v9.y = pt->y * v13.M[1][1] + pt->x * v13.M[1][0] + v13.M[1][3];
    *presPt = v9;
    if ( (v8 & 1) != 0 )
      (*(void (__thiscall **)(int, int *, int))(*(_DWORD *)v10 + 8))(v10, &v10, v12);
    return 1;
  }
  else
  {
LABEL_2:
    if ( (v11 & 0x40) != 0 )
      (*(void (__thiscall **)(int, int *, int))(*(_DWORD *)v10 + 8))(v10, &v10, v12);
    return 0;
  }
}
