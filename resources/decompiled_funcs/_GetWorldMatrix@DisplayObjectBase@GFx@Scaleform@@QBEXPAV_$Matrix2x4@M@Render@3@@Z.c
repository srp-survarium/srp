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
