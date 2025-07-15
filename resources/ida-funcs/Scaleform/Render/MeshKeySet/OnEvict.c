void __thiscall Scaleform::Render::MeshKeySet::OnEvict(
        Scaleform::Render::MeshKeySet *this,
        Scaleform::Render::MeshBase *pmesh)
{
  Scaleform::Render::MeshKey *pNext; // eax

  pNext = this->Meshes.Root.pNext;
  if ( pNext != (Scaleform::Render::MeshKey *)&this->Meshes )
  {
    while ( pmesh != pNext->pMesh.pObject )
    {
      pNext = pNext->pNext;
      if ( pNext == (Scaleform::Render::MeshKey *)&this->Meshes )
        return;
    }
    if ( !pNext->UseCount )
      Scaleform::Render::MeshKeySet::DestroyKey(this, pNext);
  }
}
