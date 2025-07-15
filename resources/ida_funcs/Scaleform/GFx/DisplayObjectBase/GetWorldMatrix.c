void __thiscall Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(
        Scaleform::GFx::DisplayObjectBase *this,
        Scaleform::Render::Matrix2x4<float> *pmat)
{
  Scaleform::GFx::InteractiveObject *pParent; // ecx
  const Scaleform::Render::Matrix2x4<float> *v4; // eax

  pParent = this->pParent;
  if ( pParent )
  {
    Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(pParent, pmat);
    v4 = this->GetMatrix(this);
    Scaleform::Render::Matrix2x4<float>::Prepend(pmat, v4);
  }
  else
  {
    *pmat = *this->GetMatrix(this);
  }
}


Scaleform::Render::Matrix2x4<float> *__thiscall Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(
        Scaleform::GFx::DisplayObjectBase *this,
        Scaleform::Render::Matrix2x4<float> *result)
{
  result->M[0][0] = 1.0;
  result->M[0][1] = 0.0;
  result->M[0][2] = 0.0;
  result->M[0][3] = 0.0;
  result->M[1][0] = 0.0;
  result->M[1][2] = 0.0;
  result->M[1][3] = 0.0;
  result->M[1][1] = 1.0;
  Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(this, result);
  return result;
}
