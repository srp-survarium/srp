void __thiscall Scaleform::GFx::MovieImpl::SetControllerCount(Scaleform::GFx::MovieImpl *this, unsigned int n)
{
  unsigned int v2; // eax

  v2 = n;
  if ( n > 6 )
    v2 = 6;
  this->ControllerCount = v2;
}
