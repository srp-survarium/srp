void __thiscall Scaleform::Render::ComplexPrimitiveBundle::UpdateMesh(
        Scaleform::Render::ComplexPrimitiveBundle *this,
        unsigned int entry)
{
  unsigned int v2; // edi
  int v4; // ecx
  Scaleform::Render::ComplexPrimitiveBundle::InstanceEntry *v5; // edi
  Scaleform::GFx::Resource *v6; // eax
  Scaleform::GFx::Resource *v7; // esi
  Scaleform::RefCountVImpl *pObject; // ecx

  v2 = entry;
  if ( Scaleform::Render::Bundle::findEntryIndex(this, &entry, (Scaleform::Render::BundleEntry *)entry) )
  {
    v4 = *(_DWORD *)(v2 + 28);
    v5 = &this->Instances.Data.Data[entry];
    v6 = (Scaleform::GFx::Resource *)(*(int (__thiscall **)(int))(*(_DWORD *)v4 + 56))(v4);
    v7 = v6;
    if ( v6 )
      Scaleform::RefCountImpl::AddRef(v6);
    pObject = (Scaleform::RefCountVImpl *)v5->pMesh.pObject;
    if ( pObject )
      Scaleform::RefCountImpl::Release(pObject);
    v5->pMesh.pObject = (Scaleform::Render::ComplexMesh *)v7;
  }
}
