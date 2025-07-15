void __thiscall Scaleform::Render::ImageDelegate::GetUVGenMatrix(
        Scaleform::Render::ImageDelegate *this,
        Scaleform::Render::Matrix2x4<float> *mat,
        Scaleform::Render::TextureManager *manager)
{
  this->pImage.pObject->GetUVGenMatrix(this->pImage.pObject, mat, manager);
}
