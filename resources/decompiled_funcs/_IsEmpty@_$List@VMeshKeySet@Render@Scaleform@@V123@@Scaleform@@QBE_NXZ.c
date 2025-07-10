bool __thiscall Scaleform::List<Scaleform::Render::MeshKeySet,Scaleform::Render::MeshKeySet>::IsEmpty(
        Scaleform::List<Scaleform::Render::MeshKeySet,Scaleform::Render::MeshKeySet> *this)
{
  if ( this )
    return this->Root.pNext == (Scaleform::Render::MeshKeySet *)&this[-1].Root.4;
  else
    return MEMORY[4] == 0;
}
