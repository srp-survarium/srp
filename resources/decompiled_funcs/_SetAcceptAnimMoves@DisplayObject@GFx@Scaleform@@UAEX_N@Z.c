void __thiscall Scaleform::GFx::DisplayObject::SetAcceptAnimMoves(Scaleform::GFx::DisplayObject *this, bool accept)
{
  const Scaleform::GFx::DisplayObjectBase::GeomDataType *v3; // eax
  Scaleform::GFx::ASMovieRootBase *pASRoot; // eax
  Scaleform::GFx::DisplayObjectBase::GeomDataType geomData; // [esp+70h] [ebp-60h] BYREF

  if ( !this->pGeomData )
  {
    geomData.OrigMatrix.M[0][0] = 1.0;
    geomData.Y = 0;
    geomData.OrigMatrix.M[0][1] = 0.0;
    geomData.X = 0;
    geomData.OrigMatrix.M[0][2] = 0.0;
    geomData.OrigMatrix.M[0][3] = 0.0;
    geomData.OrigMatrix.M[1][0] = 0.0;
    geomData.OrigMatrix.M[1][2] = 0.0;
    geomData.OrigMatrix.M[1][3] = 0.0;
    geomData.OrigMatrix.M[1][1] = 1.0;
    geomData.Rotation = 0.0;
    geomData.YScale = 100.0;
    geomData.XScale = 100.0;
    geomData.ZScale = 100.0;
    geomData.YRotation = 0.0;
    geomData.XRotation = 0.0;
    geomData.Z = 0.0;
    v3 = Scaleform::GFx::DisplayObjectBase::GetGeomData(this, &geomData);
    Scaleform::GFx::DisplayObjectBase::SetGeomData(this, v3);
  }
  if ( accept )
    this->Flags |= 8u;
  else
    this->Flags &= ~8u;
  pASRoot = this->pASRoot;
  if ( (pASRoot->pMovieImpl->Flags & 0x2000) != 0 )
    this->Flags |= 0x10u;
  else
    this->Flags &= ~0x10u;
  if ( (pASRoot->pMovieImpl->Flags & 0x2000) != 0 && accept )
  {
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->pGeomData);
    this->pGeomData = 0;
  }
}
