void __thiscall Scaleform::Render::Text::ImageDesc::ImageDesc(Scaleform::Render::Text::ImageDesc *this)
{
  this->RefCount = 1;
  this->__vftable = (Scaleform::Render::Text::ImageDesc_vtbl *)&Scaleform::Render::Text::ImageDesc::`vftable';
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
}
