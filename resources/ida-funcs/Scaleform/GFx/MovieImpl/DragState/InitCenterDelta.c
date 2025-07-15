void __thiscall Scaleform::GFx::MovieImpl::DragState::InitCenterDelta(
        Scaleform::GFx::MovieImpl::DragState *this,
        bool lockCenter,
        unsigned int mouseIndex)
{
  Scaleform::GFx::InteractiveObject *pCharacter; // edi
  Scaleform::GFx::InteractiveObject *pParent; // ecx
  unsigned int v6; // eax
  int v7; // eax
  Scaleform::Render::Point<float> p; // [esp+10h] [ebp-50h] BYREF
  Scaleform::Render::Point<float> result; // [esp+18h] [ebp-48h] BYREF
  Scaleform::Render::Matrix2x4<float> pmat; // [esp+20h] [ebp-40h] BYREF
  Scaleform::Render::Matrix2x4<float> v11; // [esp+40h] [ebp-20h] BYREF

  this->LockCenter = lockCenter;
  this->MouseIndex = mouseIndex;
  if ( !lockCenter )
  {
    pCharacter = this->pCharacter;
    pParent = this->pCharacter->pParent;
    v11.M[0][0] = 1.0;
    v11.M[0][1] = 0.0;
    v11.M[0][2] = 0.0;
    v11.M[0][3] = 0.0;
    v11.M[1][0] = 0.0;
    v11.M[1][2] = 0.0;
    v11.M[1][3] = 0.0;
    v11.M[1][1] = 1.0;
    if ( pParent )
    {
      pmat.M[0][0] = 1.0;
      pmat.M[1][1] = 1.0;
      pmat.M[0][1] = 0.0;
      pmat.M[0][2] = 0.0;
      pmat.M[0][3] = 0.0;
      pmat.M[1][0] = 0.0;
      pmat.M[1][2] = 0.0;
      pmat.M[1][3] = 0.0;
      Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(pParent, &pmat);
      v11.M[0][0] = pmat.M[0][0];
      v11.M[0][1] = pmat.M[0][1];
      v11.M[0][2] = pmat.M[0][2];
      v11.M[0][3] = pmat.M[0][3];
      v11.M[1][0] = pmat.M[1][0];
      v11.M[1][1] = pmat.M[1][1];
      v11.M[1][2] = pmat.M[1][2];
      v11.M[1][3] = pmat.M[1][3];
    }
    if ( mouseIndex < 6 )
      v6 = (unsigned int)&pCharacter->pASRoot->pMovieImpl->mMouseState[mouseIndex];
    else
      v6 = 0;
    p.x = *(float *)(v6 + 32);
    p.y = *(float *)(v6 + 36);
    Scaleform::Render::Matrix2x4<float>::TransformByInverse(&v11, &result, &p);
    v7 = (int)pCharacter->GetMatrix(pCharacter);
    v11.M[0][3] = *(float *)(v7 + 12);
    v11.M[1][3] = *(float *)(v7 + 28);
    this->CenterDelta.x = v11.M[0][3] - result.x;
    this->CenterDelta.y = v11.M[1][3] - result.y;
  }
}
