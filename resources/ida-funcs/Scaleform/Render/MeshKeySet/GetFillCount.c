unsigned int __thiscall Scaleform::Render::MeshKeySet::GetFillCount(
        Scaleform::Render::MeshKeySet *this,
        unsigned int layer,
        unsigned int meshGenFlags)
{
  return this->pDelegate->GetFillCount(&this->pDelegate->Scaleform::Render::MeshProvider, layer, meshGenFlags);
}
