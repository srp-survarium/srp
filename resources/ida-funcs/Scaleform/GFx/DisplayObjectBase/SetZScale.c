void __thiscall Scaleform::GFx::DisplayObjectBase::SetZScale(
        Scaleform::GFx::DisplayObjectBase *this,
        long double zscale)
{
  Scaleform::GFx::ASMovieRootBase *pASRoot; // eax

  if ( ((HIDWORD(zscale) & 0x7FF00000) != 0x7FF00000 || !(HIDWORD(zscale) & 0xFFFFF | LODWORD(zscale)))
    && zscale != -INFINITY
    && zscale != INFINITY )
  {
    pASRoot = this->pASRoot;
    if ( pASRoot && pASRoot->pMovieImpl->AcceptAnimMovesWith3D(pASRoot->pMovieImpl) )
      Scaleform::GFx::DisplayObjectBase::EnsureGeomDataCreated(this);
    else
      this->SetAcceptAnimMoves(this, 0);
    this->pGeomData->ZScale = zscale;
    this->UpdateTransform3D(this);
  }
}
