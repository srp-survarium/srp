void __thiscall Scaleform::GFx::DisplayObjectBase::GetWorldMatrix3D(
        Scaleform::GFx::DisplayObjectBase *this,
        Scaleform::Render::Matrix3x4<float> *pmat)
{
  Scaleform::GFx::InteractiveObject *pParent; // ecx
  const Scaleform::Render::Matrix3x4<float> *v4; // esi
  const __m128i *v5; // eax
  Scaleform::Render::Matrix3x4<float> dst; // [esp+10h] [ebp-30h] BYREF

  pParent = this->pParent;
  if ( pParent )
  {
    Scaleform::GFx::DisplayObjectBase::GetWorldMatrix3D(pParent, pmat);
    v4 = this->GetMatrix3D(this);
    memcpy((int)&dst, (const __m128i *)pmat, sizeof(dst));
    Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(pmat, &dst, v4);
  }
  else
  {
    v5 = (const __m128i *)this->GetMatrix3D(this);
    memcpy((int)pmat, v5, sizeof(Scaleform::Render::Matrix3x4<float>));
  }
}


Scaleform::Render::Matrix3x4<float> *__thiscall Scaleform::GFx::DisplayObjectBase::GetWorldMatrix3D(
        Scaleform::GFx::DisplayObjectBase *this,
        Scaleform::Render::Matrix3x4<float> *result)
{
  memset((int)result, 0, sizeof(Scaleform::Render::Matrix3x4<float>));
  result->M[0][0] = 1.0;
  result->M[1][1] = 1.0;
  result->M[2][2] = 1.0;
  Scaleform::GFx::DisplayObjectBase::GetWorldMatrix3D(this, result);
  return result;
}
