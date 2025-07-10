void __thiscall Scaleform::GFx::Value::DisplayInfo::SetViewMatrix3D(
        Scaleform::GFx::Value::DisplayInfo *this,
        Scaleform::Render::Matrix3x4<float> *pmat)
{
  if ( pmat )
  {
    this->VarsSet |= 0x2000u;
    memcpy((unsigned __int8 *)&this->ViewMatrix3D, (unsigned __int8 *)pmat, sizeof(this->ViewMatrix3D));
  }
  else
  {
    this->VarsSet &= ~0x2000u;
  }
}
