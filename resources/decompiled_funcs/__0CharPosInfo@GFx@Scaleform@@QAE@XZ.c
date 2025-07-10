void __thiscall Scaleform::GFx::CharPosInfo::CharPosInfo(Scaleform::GFx::CharPosInfo *this)
{
  Scaleform::Render::Cxform::Cxform(&this->ColorTransform);
  this->Matrix_1.M[0][0] = 1.0;
  this->pFilters.pObject = 0;
  this->Matrix_1.M[0][1] = 0.0;
  this->Matrix_1.M[0][2] = 0.0;
  this->Matrix_1.M[0][3] = 0.0;
  this->Matrix_1.M[1][0] = 0.0;
  this->Matrix_1.M[1][2] = 0.0;
  this->Matrix_1.M[1][3] = 0.0;
  this->Matrix_1.M[1][1] = 1.0;
  this->CharacterId.Id = 0x40000;
  this->Flags.Flags = 0;
  this->Depth = 0;
  this->Ratio = 0.0;
  this->BlendMode = 0;
  this->ClassName = 0;
  this->ClipDepth = 0;
}
