char __thiscall Scaleform::GFx::MovieImpl::TranslateLocalToScreen(
        Scaleform::GFx::MovieImpl *this,
        char *pathToMovieClip,
        const Scaleform::Render::Point<float> *pt,
        Scaleform::Render::Point<float> *presPt,
        Scaleform::Render::Matrix2x4<float> *userMatrix)
{
  unsigned int v7; // ecx
  Scaleform::Render::Point<float> v8; // [esp+10h] [ebp-60h]
  Scaleform::GFx::Value pval; // [esp+18h] [ebp-58h] BYREF
  Scaleform::Render::Matrix2x4<float> v10; // [esp+30h] [ebp-40h] BYREF
  Scaleform::Render::Matrix2x4<float> v11; // [esp+50h] [ebp-20h] BYREF

  pval.pObjectInterface = 0;
  pval.Type = VT_Undefined;
  if ( Scaleform::GFx::Movie::GetVariable(this, &pval, pathToMovieClip) )
  {
    v11.M[0][0] = 1.0;
    v11.M[0][1] = 0.0;
    v11.M[0][2] = 0.0;
    v11.M[0][3] = 0.0;
    v11.M[1][0] = 0.0;
    v11.M[1][2] = 0.0;
    v11.M[1][3] = 0.0;
    v11.M[1][1] = 1.0;
    if ( pval.pObjectInterface->GetWorldMatrix(pval.pObjectInterface, (void *)pval.mValue.IValue, &v11) )
    {
      v10.M[0][0] = this->ViewportMatrix.M[0][0];
      v10.M[0][1] = this->ViewportMatrix.M[0][1];
      v10.M[0][2] = this->ViewportMatrix.M[0][2];
      v10.M[0][3] = this->ViewportMatrix.M[0][3];
      v10.M[1][0] = this->ViewportMatrix.M[1][0];
      v10.M[1][1] = this->ViewportMatrix.M[1][1];
      v10.M[1][2] = this->ViewportMatrix.M[1][2];
      v10.M[1][3] = this->ViewportMatrix.M[1][3];
      v10.M[0][0] = v10.M[0][0] * 20.0;
      v10.M[0][1] = v10.M[0][1] * 20.0;
      v10.M[0][2] = v10.M[0][2] * 20.0;
      v10.M[0][3] = v10.M[0][3] * 20.0;
      v10.M[1][0] = v10.M[1][0] * 20.0;
      v10.M[1][1] = v10.M[1][1] * 20.0;
      v10.M[1][2] = v10.M[1][2] * 20.0;
      v10.M[1][3] = 20.0 * v10.M[1][3];
      if ( userMatrix )
        Scaleform::Render::Matrix2x4<float>::Prepend(&v10, userMatrix);
      Scaleform::Render::Matrix2x4<float>::Prepend(&v10, &v11);
      v7 = (unsigned int)pval.Type >> 6;
      v8.x = pt->y * v10.M[0][1] + pt->x * v10.M[0][0] + v10.M[0][3];
      v8.y = pt->y * v10.M[1][1] + pt->x * v10.M[1][0] + v10.M[1][3];
      *presPt = v8;
      if ( (v7 & 1) != 0 )
        pval.pObjectInterface->ObjectRelease(pval.pObjectInterface, &pval, (void *)pval.mValue.IValue);
      return 1;
    }
    else
    {
      if ( (pval.Type & 0x40) != 0 )
        pval.pObjectInterface->ObjectRelease(pval.pObjectInterface, &pval, (void *)pval.mValue.IValue);
      return 0;
    }
  }
  else
  {
    if ( (pval.Type & 0x40) != 0 )
      pval.pObjectInterface->ObjectRelease(pval.pObjectInterface, &pval, (void *)pval.mValue.IValue);
    return 0;
  }
}
