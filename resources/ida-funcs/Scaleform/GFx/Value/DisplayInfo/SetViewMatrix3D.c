void __thiscall Scaleform::GFx::Value::DisplayInfo::SetViewMatrix3D(
        Scaleform::GFx::Value::DisplayInfo *this,
        const __m128i *pmat)
{
  if ( pmat )
  {
    this->VarsSet |= 0x2000u;
    memcpy((int)&this->ViewMatrix3D, pmat, sizeof(this->ViewMatrix3D));
  }
  else
  {
    this->VarsSet &= ~0x2000u;
  }
}
