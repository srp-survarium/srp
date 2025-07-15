unsigned int __thiscall Scaleform::Render::MeshKeySet::GetLayerCount(Scaleform::Render::MeshKeySet *this)
{
  return this->pDelegate->GetLayerCount(&this->pDelegate->Scaleform::Render::MeshProvider);
}
