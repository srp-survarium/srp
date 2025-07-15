void __thiscall Scaleform::Render::MeshKeySet::GetFillData(
        Scaleform::Render::MeshKeySet *this,
        Scaleform::Render::FillData *data,
        unsigned int layer,
        unsigned int fillIndex,
        unsigned int meshGenFlags)
{
  this->pDelegate->GetFillData(&this->pDelegate->Scaleform::Render::MeshProvider, data, layer, fillIndex, meshGenFlags);
}
