void __thiscall Scaleform::GFx::AS2::GASTextSnapshotGlyphVisitor::GASTextSnapshotGlyphVisitor(
        Scaleform::GFx::AS2::GASTextSnapshotGlyphVisitor *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::ArrayObject *parr)
{
  this->Matrix.M[0][0] = 1.0;
  this->Matrix.M[0][1] = 0.0;
  this->__vftable = (Scaleform::GFx::AS2::GASTextSnapshotGlyphVisitor_vtbl *)&Scaleform::GFx::AS2::GASTextSnapshotGlyphVisitor::`vftable';
  this->Matrix.M[0][2] = 0.0;
  this->pEnv = penv;
  this->Matrix.M[0][3] = 0.0;
  this->pArrayObj = parr;
  this->Matrix.M[1][0] = 0.0;
  this->Matrix.M[1][2] = 0.0;
  this->Matrix.M[1][3] = 0.0;
  this->Matrix.M[1][1] = 1.0;
  this->Corners.x1 = 0.0;
  this->Corners.y1 = 0.0;
  this->Corners.x2 = 0.0;
  this->Corners.y2 = 0.0;
}
