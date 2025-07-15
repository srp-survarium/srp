void __thiscall Scaleform::Render::Text::HTMLImageTagDesc::HTMLImageTagDesc(
        Scaleform::Render::Text::HTMLImageTagDesc *this)
{
  this->RefCount = 1;
  this->pImage.pObject = 0;
  this->BaseLineX = 0.0;
  this->BaseLineY = 0.0;
  this->ScreenWidth = 0.0;
  this->ScreenHeight = 0.0;
  this->Matrix.M[0][0] = 1.0;
  this->Matrix.M[1][1] = 1.0;
  this->Matrix.M[0][1] = 0.0;
  this->Matrix.M[0][2] = 0.0;
  this->Matrix.M[0][3] = 0.0;
  this->Matrix.M[1][0] = 0.0;
  this->Matrix.M[1][2] = 0.0;
  this->Matrix.M[1][3] = 0.0;
  this->__vftable = (Scaleform::Render::Text::HTMLImageTagDesc_vtbl *)&Scaleform::Render::Text::HTMLImageTagDesc::`vftable';
  Scaleform::StringLH::StringLH(&this->Url);
  Scaleform::StringLH::StringLH(&this->Id);
  this->VSpace = 0;
  this->HSpace = 0;
  this->Alignment = 0;
  this->ParaId = -1;
}
