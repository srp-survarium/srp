void __thiscall Scaleform::Render::ImageDelegate::GetMatrix(
        Scaleform::Render::ImageDelegate *this,
        Scaleform::Render::Matrix2x4<float> *mat)
{
  this->pImage.pObject->GetMatrix(this->pImage.pObject, mat);
}
