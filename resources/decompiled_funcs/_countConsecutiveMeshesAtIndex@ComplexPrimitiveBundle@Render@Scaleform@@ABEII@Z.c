unsigned int __thiscall Scaleform::Render::ComplexPrimitiveBundle::countConsecutiveMeshesAtIndex(
        Scaleform::Render::ComplexPrimitiveBundle *this,
        unsigned int i)
{
  Scaleform::Render::ComplexPrimitiveBundle::InstanceEntry *Data; // edx
  unsigned int v3; // ecx
  Scaleform::Render::ComplexPrimitiveBundle::InstanceEntry *v4; // edx
  Scaleform::Render::ComplexMesh *pObject; // edi
  unsigned int v6; // eax
  Scaleform::Ptr<Scaleform::Render::ComplexMesh> *p_pMesh; // edx

  Data = this->Instances.Data.Data;
  v3 = this->Instances.Data.Size - 1;
  v4 = &Data[i];
  pObject = v4->pMesh.pObject;
  v6 = i;
  if ( i < v3 )
  {
    p_pMesh = &v4[1].pMesh;
    do
    {
      if ( p_pMesh->pObject != pObject )
        break;
      ++v6;
      p_pMesh += 2;
    }
    while ( v6 < v3 );
  }
  return v6 - i + 1;
}
