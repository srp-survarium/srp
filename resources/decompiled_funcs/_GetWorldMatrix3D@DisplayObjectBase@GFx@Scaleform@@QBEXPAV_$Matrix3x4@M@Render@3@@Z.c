void __thiscall Scaleform::GFx::DisplayObjectBase::GetWorldMatrix3D(
        Scaleform::GFx::DisplayObjectBase *this,
        Scaleform::Render::Matrix3x4<float> *pmat)
{
  Scaleform::GFx::InteractiveObject *pParent; // ecx
  const Scaleform::Render::Matrix3x4<float> *v4; // esi
  unsigned __int8 *v5; // eax
  Scaleform::Render::Matrix3x4<float> dst; // [esp+10h] [ebp-30h] BYREF

  pParent = this->pParent;
  if ( pParent )
  {
    Scaleform::GFx::DisplayObjectBase::GetWorldMatrix3D(pParent, pmat);
    v4 = this->GetMatrix3D(this);
    memcpy((unsigned __int8 *)&dst, (unsigned __int8 *)pmat, sizeof(dst));
    Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(pmat, &dst, v4);
  }
  else
  {
    v5 = (unsigned __int8 *)this->GetMatrix3D(this);
    memcpy((unsigned __int8 *)pmat, v5, sizeof(Scaleform::Render::Matrix3x4<float>));
  }
}
