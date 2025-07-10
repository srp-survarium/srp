void __thiscall Scaleform::Render::MeshKeySet::GetFillMatrix(
        Scaleform::Render::MeshKeySet *this,
        Scaleform::Render::MeshBase *mesh,
        Scaleform::Render::Matrix2x4<float> *matrix,
        unsigned int layer,
        unsigned int fillIndex,
        unsigned int meshGenFlags)
{
  this->pDelegate->GetFillMatrix(
    &this->pDelegate->Scaleform::Render::MeshProvider,
    mesh,
    matrix,
    layer,
    fillIndex,
    meshGenFlags);
}
