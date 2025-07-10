void __thiscall Scaleform::Render::ImageDelegate::GetUVNormMatrix(
        Scaleform::Render::ImageDelegate *this,
        Scaleform::Render::Matrix2x4<float> *mat,
        Scaleform::Render::TextureManager *manager)
{
  this->pImage.pObject->GetUVNormMatrix(this->pImage.pObject, mat, manager);
}
