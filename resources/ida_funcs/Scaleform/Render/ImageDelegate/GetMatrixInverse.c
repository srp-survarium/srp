void __thiscall Scaleform::Render::ImageDelegate::GetMatrixInverse(
        Scaleform::Render::ImageDelegate *this,
        Scaleform::Render::Matrix2x4<float> *mat)
{
  this->pImage.pObject->GetMatrixInverse(this->pImage.pObject, mat);
}
