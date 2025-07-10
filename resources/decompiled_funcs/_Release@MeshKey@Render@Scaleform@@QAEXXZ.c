void __thiscall Scaleform::Render::MeshKey::Release(Scaleform::Render::MeshKey *this)
{
  Scaleform::Render::MeshBase *pObject; // ecx

  if ( this->UseCount-- == 1 )
  {
    pObject = this->pMesh.pObject;
    if ( !pObject || pObject->IsEvicted(pObject) || (this->Flags & 0x110) != 0 )
      Scaleform::Render::MeshKeySet::DestroyKey(this->pKeySet, this);
  }
}
