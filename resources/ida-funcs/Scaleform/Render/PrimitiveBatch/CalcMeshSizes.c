void __thiscall Scaleform::Render::PrimitiveBatch::CalcMeshSizes(
        Scaleform::Render::PrimitiveBatch *this,
        unsigned int *ptotalVertices,
        unsigned int *ptotalIndices)
{
  Scaleform::Render::Primitive *pPrimitive; // edx
  unsigned int Size; // ecx
  Scaleform::Render::PrimitiveBatch *i; // eax
  signed int MeshCount; // esi
  int v8; // ebx
  unsigned int VertexCount; // eax
  int v10; // ecx
  int v11; // edi
  int v12; // ebp
  unsigned int v13; // edx
  unsigned int v14; // esi
  int p_pMesh; // eax
  int v16; // edx
  Scaleform::Render::Mesh *pObject; // edx
  unsigned int IndexCount; // edx
  signed int v19; // [esp+10h] [ebp-14h]
  Scaleform::Render::PrimitiveBatch *v20; // [esp+14h] [ebp-10h]
  int v21; // [esp+1Ch] [ebp-8h]

  pPrimitive = this->pPrimitive;
  Size = pPrimitive->Meshes.Data.Size;
  v20 = this;
  if ( pPrimitive->ModifyIndex < Size )
  {
    for ( i = pPrimitive->Batches.Root.pPrev; i != (Scaleform::Render::PrimitiveBatch *)&pPrimitive->Batches; i = i->pPrev )
    {
      Size -= i->MeshCount;
      i->MeshIndex = Size;
      if ( Size < pPrimitive->ModifyIndex )
        break;
    }
    pPrimitive->ModifyIndex = pPrimitive->Meshes.Data.Size;
  }
  MeshCount = 1;
  if ( this->Type != DP_Instanced )
    MeshCount = this->MeshCount;
  v8 = 0;
  VertexCount = 0;
  v10 = 0;
  v11 = 0;
  v12 = 0;
  v13 = 0;
  v19 = MeshCount;
  if ( MeshCount >= 2 )
  {
    v14 = ((unsigned int)(MeshCount - 2) >> 1) + 1;
    p_pMesh = (int)&v20->pPrimitive->Meshes.Data.Data[v20->MeshIndex + 1].pMesh;
    v21 = 2 * v14;
    do
    {
      v16 = *(_DWORD *)(p_pMesh - 8);
      v11 += *(_DWORD *)(v16 + 36);
      v8 += *(_DWORD *)(v16 + 40);
      v12 += *(_DWORD *)(*(_DWORD *)p_pMesh + 36);
      v10 += *(_DWORD *)(*(_DWORD *)p_pMesh + 40);
      p_pMesh += 16;
      --v14;
    }
    while ( v14 );
    VertexCount = 0;
    MeshCount = v19;
    v13 = v21;
  }
  if ( v13 >= MeshCount )
  {
    IndexCount = 0;
  }
  else
  {
    pObject = v20->pPrimitive->Meshes.Data.Data[v13 + v20->MeshIndex].pMesh.pObject;
    VertexCount = pObject->VertexCount;
    IndexCount = pObject->IndexCount;
  }
  *ptotalVertices = VertexCount + v12 + v11;
  *ptotalIndices = IndexCount + v10 + v8;
}
