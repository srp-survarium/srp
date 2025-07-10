void __thiscall Scaleform::Render::Tessellator::splitMesh(
        Scaleform::Render::Tessellator *this,
        Scaleform::Render::Tessellator::TriangleType *mesh)
{
  unsigned int ecx1a; // ecx
  unsigned int MeshIdx; // esi
  unsigned int v5; // edi
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *Arrays; // eax
  Scaleform::Render::Tessellator::TriangleType **v7; // edx
  unsigned int v8; // ecx
  unsigned int v9; // eax
  int v10; // ecx
  Scaleform::Render::TessMesh *v11; // esi
  unsigned int Size; // eax
  unsigned int v13; // edi
  unsigned int v14; // ecx
  unsigned int v15; // eax
  Scaleform::Render::Tessellator::TriangleType *v16; // edi
  Scaleform::Render::TessVertex **Pages; // ecx
  int v18; // esi
  int v19; // ecx
  Scaleform::Render::Tessellator::TriangleType *v20; // edx
  unsigned int v21; // ecx
  Scaleform::Render::TessVertex *v22; // ecx
  unsigned int v23; // eax
  _DWORD *p_x; // eax
  unsigned int v25; // esi
  Scaleform::Render::TessVertex *v26; // eax
  unsigned int v27; // esi
  Scaleform::Render::TessVertex *v28; // eax
  int v29; // [esp+10h] [ebp-38h]
  unsigned int v2; // [esp+14h] [ebp-34h]
  Scaleform::Render::TessVertex *v2a; // [esp+14h] [ebp-34h]
  Scaleform::Render::TessVertex *v3; // [esp+18h] [ebp-30h]
  Scaleform::Render::TessVertex *v3a; // [esp+18h] [ebp-30h]
  unsigned int newMeshes; // [esp+1Ch] [ebp-2Ch]
  unsigned int newMeshesa; // [esp+1Ch] [ebp-2Ch]
  unsigned int n; // [esp+20h] [ebp-28h]
  unsigned int na; // [esp+20h] [ebp-28h]
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayAdaptor arr; // [esp+24h] [ebp-24h] BYREF
  Scaleform::Render::TessMesh newMesh; // [esp+2Ch] [ebp-1Ch] BYREF
  Scaleform::Render::Tessellator::TriangleType *trib; // [esp+4Ch] [ebp+4h]
  unsigned int tri; // [esp+4Ch] [ebp+4h]
  Scaleform::Render::Tessellator::TriangleType *tria; // [esp+4Ch] [ebp+4h]

  ecx1a = this->VertexLimit - (this->VertexLimit >> 2);
  MeshIdx = mesh->d.t.v1;
  v5 = 16 * mesh->d.t.v1;
  v3 = (Scaleform::Render::TessVertex *)v5;
  newMeshes = (mesh[2].d.t.v1 + ecx1a - 1) / ecx1a;
  v2 = *(unsigned int *)((char *)&this->MeshTriangles.Arrays->Size + v5) / newMeshes;
  Arrays = this->MeshTriangles.Arrays;
  v7 = *(Scaleform::Render::Tessellator::TriangleType ***)((char *)&Arrays->Pages + v5);
  arr.Size = *(unsigned int *)((char *)&Arrays->Size + v5);
  arr.Pages = v7;
  Scaleform::Alg::QuickSortSliced<Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayAdaptor,Scaleform::Render::Tessellator::CmpVer1>(
    &arr,
    0,
    arr.Size,
    (Scaleform::Render::Tessellator::CmpVer1)&this->MeshVertices);
  v8 = 0;
  n = this->MeshTriangles.Arrays[mesh->d.t.v1].Size;
  if ( n )
  {
    while ( 1 )
    {
      trib = &(*(Scaleform::Render::Tessellator::TriangleType ***)((char *)&this->MeshTriangles.Arrays->Pages + v5))[v8 >> 4][v8 & 0xF];
      this->MeshVertices.Pages[trib->d.t.v1 >> 4][trib->d.t.v1 & 0xF].Mesh = -1;
      this->MeshVertices.Pages[trib->d.t.v2 >> 4][trib->d.t.v2 & 0xF].Mesh = -1;
      ++v8;
      this->MeshVertices.Pages[trib->d.t.v3 >> 4][trib->d.t.v3 & 0xF].Mesh = -1;
      if ( v8 >= n )
        break;
      v5 = (unsigned int)v3;
    }
  }
  for ( tri = 1; tri < newMeshes; ++tri )
  {
    if ( !Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::Split(
            &this->MeshTriangles,
            MeshIdx,
            v2) )
      break;
    v9 = MeshIdx >> 4;
    v10 = MeshIdx & 0xF;
    this->Meshes.Pages[v9][v10].VertexCount = -1;
    v11 = this->Meshes.Pages[v9];
    Size = this->Meshes.Size;
    qmemcpy(&newMesh, &v11[v10], sizeof(newMesh));
    v13 = this->Meshes.Size >> 4;
    newMesh.MeshIdx = Size;
    if ( v13 >= this->Meshes.NumPages )
      Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::BaseLineType,4,4>::allocPage(&this->Meshes, v13);
    qmemcpy(
      &this->Meshes.Pages[v13][this->Meshes.Size++ & 0xF],
      &newMesh,
      sizeof(this->Meshes.Pages[v13][this->Meshes.Size++ & 0xF]));
    MeshIdx = newMesh.MeshIdx;
  }
  v14 = 0;
  tria = 0;
  if ( this->Meshes.Size )
  {
    v29 = 0;
    do
    {
      if ( this->Meshes.Pages[v14 >> 4][v14 & 0xF].VertexCount == -1 )
      {
        v15 = 0;
        na = this->MeshTriangles.Arrays[v29].Size;
        newMeshesa = 0;
        if ( na )
        {
          while ( 1 )
          {
            v16 = &this->MeshTriangles.Arrays[v29].Pages[v15 >> 4][v15 & 0xF];
            Pages = this->MeshVertices.Pages;
            v18 = (int)&Pages[v16->d.t.v1 >> 4][v16->d.t.v1 & 0xF];
            v2a = &Pages[v16->d.t.v2 >> 4][v16->d.t.v2 & 0xF];
            v19 = (int)&Pages[v16->d.t.v3 >> 4][v16->d.t.v3 & 0xF];
            v3a = (Scaleform::Render::TessVertex *)v19;
            if ( *(_WORD *)(v18 + 18) == 0xFFFF )
              *(_WORD *)(v18 + 18) = (_WORD)tria;
            v20 = tria;
            if ( v2a->Mesh == 0xFFFF )
              v2a->Mesh = (unsigned __int16)tria;
            if ( *(_WORD *)(v19 + 18) == 0xFFFF )
              *(_WORD *)(v19 + 18) = (_WORD)tria;
            if ( (Scaleform::Render::Tessellator::TriangleType *)*(unsigned __int16 *)(v18 + 18) != tria )
            {
              v16->d.t.v1 = this->MeshVertices.Size;
              v21 = this->MeshVertices.Size >> 4;
              arr.Size = v21;
              if ( v21 >= this->MeshVertices.NumPages )
              {
                Scaleform::Render::ArrayPaged<Scaleform::Render::TessVertex,4,16>::allocPage(&this->MeshVertices, v21);
                v21 = arr.Size;
              }
              v22 = this->MeshVertices.Pages[v21];
              v23 = this->MeshVertices.Size & 0xF;
              v22[v23].x = *(float *)v18;
              p_x = (_DWORD *)&v22[v23].x;
              p_x[1] = *(_DWORD *)(v18 + 4);
              p_x[2] = *(_DWORD *)(v18 + 8);
              p_x[3] = *(_DWORD *)(v18 + 12);
              p_x[4] = *(_DWORD *)(v18 + 16);
              ++this->MeshVertices.Size;
              this->MeshVertices.Pages[(this->MeshVertices.Size - 1) >> 4][(this->MeshVertices.Size - 1) & 0xF].Mesh = (unsigned __int16)tria;
              v19 = (int)v3a;
              v20 = tria;
            }
            if ( (Scaleform::Render::Tessellator::TriangleType *)v2a->Mesh != v20 )
            {
              v16->d.t.v2 = this->MeshVertices.Size;
              v25 = this->MeshVertices.Size >> 4;
              if ( v25 >= this->MeshVertices.NumPages )
              {
                Scaleform::Render::ArrayPaged<Scaleform::Render::TessVertex,4,16>::allocPage(
                  &this->MeshVertices,
                  this->MeshVertices.Size >> 4);
                v19 = (int)v3a;
              }
              v26 = &this->MeshVertices.Pages[v25][this->MeshVertices.Size & 0xF];
              v26->x = v2a->x;
              v26->y = v2a->y;
              v26->Idx = v2a->Idx;
              *(_DWORD *)v26->Styles = *(_DWORD *)v2a->Styles;
              *(_DWORD *)&v26->Flags = *(_DWORD *)&v2a->Flags;
              ++this->MeshVertices.Size;
              v20 = tria;
              this->MeshVertices.Pages[(this->MeshVertices.Size - 1) >> 4][(this->MeshVertices.Size - 1) & 0xF].Mesh = (unsigned __int16)tria;
            }
            if ( (Scaleform::Render::Tessellator::TriangleType *)*(unsigned __int16 *)(v19 + 18) != v20 )
            {
              v16->d.t.v3 = this->MeshVertices.Size;
              v27 = this->MeshVertices.Size >> 4;
              if ( v27 >= this->MeshVertices.NumPages )
              {
                Scaleform::Render::ArrayPaged<Scaleform::Render::TessVertex,4,16>::allocPage(
                  &this->MeshVertices,
                  this->MeshVertices.Size >> 4);
                v19 = (int)v3a;
                LOWORD(v20) = (_WORD)tria;
              }
              v28 = &this->MeshVertices.Pages[v27][this->MeshVertices.Size & 0xF];
              v28->x = *(float *)v19;
              v28->y = *(float *)(v19 + 4);
              v28->Idx = *(_DWORD *)(v19 + 8);
              *(_DWORD *)v28->Styles = *(_DWORD *)(v19 + 12);
              *(_DWORD *)&v28->Flags = *(_DWORD *)(v19 + 16);
              ++this->MeshVertices.Size;
              this->MeshVertices.Pages[(this->MeshVertices.Size - 1) >> 4][(this->MeshVertices.Size - 1) & 0xF].Mesh = (unsigned __int16)v20;
            }
            if ( ++newMeshesa >= na )
              break;
            v15 = newMeshesa;
          }
          v14 = (unsigned int)tria;
        }
      }
      ++v29;
      tria = (Scaleform::Render::Tessellator::TriangleType *)++v14;
    }
    while ( v14 < this->Meshes.Size );
  }
}
