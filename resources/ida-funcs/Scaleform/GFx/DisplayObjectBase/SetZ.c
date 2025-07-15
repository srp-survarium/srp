void __thiscall Scaleform::GFx::DisplayObjectBase::SetZ(Scaleform::GFx::DisplayObjectBase *this, double z)
{
  Scaleform::GFx::ASMovieRootBase *pASRoot; // eax
  double v4; // [esp+0h] [ebp-8h]

  v4 = z;
  if ( (HIDWORD(v4) & 0x7FF00000) != 0x7FF00000 || !((unsigned int)&loc_FFFFF & HIDWORD(v4) | LODWORD(v4)) )
  {
    if ( z == -INFINITY || z == INFINITY )
      z = 0.0;
    pASRoot = this->pASRoot;
    if ( pASRoot && pASRoot->pMovieImpl->AcceptAnimMovesWith3D(pASRoot->pMovieImpl) )
      Scaleform::GFx::DisplayObjectBase::EnsureGeomDataCreated(this);
    else
      this->SetAcceptAnimMoves(this, 0);
    this->pGeomData->Z = z;
    this->UpdateTransform3D(this);
  }
}
