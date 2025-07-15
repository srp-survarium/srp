int __thiscall Scaleform::Render::MeshKeySet::GetData(
        Scaleform::Render::MeshKeySet *this,
        Scaleform::Render::MeshBase *mesh,
        Scaleform::Render::VertexOutput *out,
        unsigned int meshGenFlags)
{
  return ((int (__thiscall *)(Scaleform::Render::MeshProvider *, Scaleform::Render::MeshBase *, Scaleform::Render::VertexOutput *, unsigned int))this->pDelegate->GetData)(
           &this->pDelegate->Scaleform::Render::MeshProvider,
           mesh,
           out,
           meshGenFlags);
}
