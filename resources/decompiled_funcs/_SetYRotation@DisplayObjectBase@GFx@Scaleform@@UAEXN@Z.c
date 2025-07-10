void __thiscall Scaleform::GFx::DisplayObjectBase::SetYRotation(
        Scaleform::GFx::DisplayObjectBase *this,
        long double rotation)
{
  Scaleform::GFx::ASMovieRootBase *pASRoot; // eax
  long double v4; // st7

  if ( (HIDWORD(rotation) & 0x7FF00000) != 0x7FF00000
    || !((unsigned int)&loc_FFFFF & HIDWORD(rotation) | LODWORD(rotation)) )
  {
    pASRoot = this->pASRoot;
    if ( pASRoot && pASRoot->pMovieImpl->AcceptAnimMovesWith3D(pASRoot->pMovieImpl) )
      Scaleform::GFx::DisplayObjectBase::EnsureGeomDataCreated(this);
    else
      this->SetAcceptAnimMoves(this, 0);
    v4 = fmod(rotation, 360.0);
    if ( v4 <= 180.0 )
    {
      if ( v4 < -180.0 )
        v4 = v4 + 360.0;
    }
    else
    {
      v4 = v4 - 360.0;
    }
    this->pGeomData->YRotation = v4;
    this->UpdateTransform3D(this);
  }
}
