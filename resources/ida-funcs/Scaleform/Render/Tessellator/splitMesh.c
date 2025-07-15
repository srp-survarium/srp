void __thiscall Scaleform::Render::Tessellator::splitMesh(
        Scaleform::Render::Tessellator *this,
        Scaleform::Render::TessMesh *mesh)
{
  unsigned int v3; // ecx
  unsigned int MeshIdx; // esi
  unsigned int v5; // edi
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *Arrays; // eax
  Scaleform::Render::Tessellator::TriangleType **v7; // edx
  unsigned int v8; // ecx
  unsigned int v9; // eax
  int v10; // ecx
  Scaleform::Render::TessMesh *v11; // esi
  unsigned int v12; // eax
  unsigned int v13; // edi
  unsigned int v14; // ecx
  unsigned int v15; // eax
  Scaleform::Render::Tessellator::TriangleType *v16; // edi
  Scaleform::Render::TessVertex **Pages; // ecx
  int v18; // esi
  int v19; // ecx
  unsigned int v20; // edx
  unsigned int v21; // ecx
  Scaleform::Render::TessVertex *v22; // ecx
  unsigned int v23; // eax
  _DWORD *p_x; // eax
  unsigned int v25; // esi
  Scaleform::Render::TessVertex *v26; // eax
  unsigned int v27; // esi
  Scaleform::Render::TessVertex *v28; // eax
  int v29; // [esp+10h] [ebp-38h]
  unsigned int v30; // [esp+14h] [ebp-34h]
  int v31; // [esp+14h] [ebp-34h]
  unsigned int v32; // [esp+18h] [ebp-30h]
  int v33; // [esp+18h] [ebp-30h]
  unsigned int v34; // [esp+1Ch] [ebp-2Ch]
  unsigned int v35; // [esp+1Ch] [ebp-2Ch]
  unsigned int Size; // [esp+20h] [ebp-28h]
  unsigned int v37; // [esp+20h] [ebp-28h]
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayAdaptor arr; // [esp+24h] [ebp-24h] BYREF
  _DWORD v39[7]; // [esp+2Ch] [ebp-1Ch] BYREF
  Scaleform::Render::Tessellator::TriangleType *v40; // [esp+4Ch] [ebp+4h]
  unsigned int i; // [esp+4Ch] [ebp+4h]
  unsigned int v42; // [esp+4Ch] [ebp+4h]

  v3 = this->VertexLimit - (this->VertexLimit >> 2);
  MeshIdx = mesh->MeshIdx;
  v5 = 16 * mesh->MeshIdx;
  v32 = v5;
  v34 = (mesh->VertexCount + v3 - 1) / v3;
  v30 = *(unsigned int *)((char *)&this->MeshTriangles.Arrays->Size + v5) / v34;
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
  Size = this->MeshTriangles.Arrays[mesh->MeshIdx].Size;
  if ( Size )
  {
    while ( 1 )
    {
      v40 = &(*(Scaleform::Render::Tessellator::TriangleType ***)((char *)&this->MeshTriangles.Arrays->Pages + v5))[v8 >> 4][v8 & 0xF];
      this->MeshVertices.Pages[v40->d.t.v1 >> 4][v40->d.t.v1 & 0xF].Mesh = -1;
      this->MeshVertices.Pages[v40->d.t.v2 >> 4][v40->d.t.v2 & 0xF].Mesh = -1;
      ++v8;
      this->MeshVertices.Pages[v40->d.t.v3 >> 4][v40->d.t.v3 & 0xF].Mesh = -1;
      if ( v8 >= Size )
        break;
      v5 = v32;
    }
  }
  for ( i = 1; i < v34; ++i )
  {
    if ( !Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::Split(
            &this->MeshTriangles,
            MeshIdx,
            v30) )
      break;
    v9 = MeshIdx >> 4;
    v10 = MeshIdx & 0xF;
    this->Meshes.Pages[v9][v10].VertexCount = -1;
    v11 = this->Meshes.Pages[v9];
    v12 = this->Meshes.Size;
    qmemcpy(v39, &v11[v10], sizeof(v39));
    v13 = this->Meshes.Size >> 4;
    v39[0] = v12;
    if ( v13 >= this->Meshes.NumPages )
      Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::BaseLineType,4,4>::allocPage(&this->Meshes, v13);
    qmemcpy(
      &this->Meshes.Pages[v13][this->Meshes.Size++ & 0xF],
      v39,
      sizeof(this->Meshes.Pages[v13][this->Meshes.Size++ & 0xF]));
    MeshIdx = v39[0];
  }
  v14 = 0;
  v42 = 0;
  if ( this->Meshes.Size )
  {
    v29 = 0;
    do
    {
      if ( this->Meshes.Pages[v14 >> 4][v14 & 0xF].VertexCount == -1 )
      {
        v15 = 0;
        v37 = this->MeshTriangles.Arrays[v29].Size;
        v35 = 0;
        if ( v37 )
        {
          while ( 1 )
          {
            v16 = &this->MeshTriangles.Arrays[v29].Pages[v15 >> 4][v15 & 0xF];
            Pages = this->MeshVertices.Pages;
            v18 = (int)&Pages[v16->d.t.v1 >> 4][v16->d.t.v1 & 0xF];
            v31 = (int)&Pages[v16->d.t.v2 >> 4][v16->d.t.v2 & 0xF];
            v19 = (int)&Pages[v16->d.t.v3 >> 4][v16->d.t.v3 & 0xF];
            v33 = v19;
            if ( *(_WORD *)(v18 + 18) == 0xFFFF )
              *(_WORD *)(v18 + 18) = v42;
            v20 = v42;
            if ( *(_WORD *)(v31 + 18) == 0xFFFF )
              *(_WORD *)(v31 + 18) = v42;
            if ( *(_WORD *)(v19 + 18) == 0xFFFF )
              *(_WORD *)(v19 + 18) = v42;
            if ( *(unsigned __int16 *)(v18 + 18) != v42 )
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
              this->MeshVertices.Pages[(this->MeshVertices.Size - 1) >> 4][(this->MeshVertices.Size - 1) & 0xF].Mesh = v42;
              v19 = v33;
              v20 = v42;
            }
            if ( *(unsigned __int16 *)(v31 + 18) != v20 )
            {
              v16->d.t.v2 = this->MeshVertices.Size;
              v25 = this->MeshVertices.Size >> 4;
              if ( v25 >= this->MeshVertices.NumPages )
              {
                Scaleform::Render::ArrayPaged<Scaleform::Render::TessVertex,4,16>::allocPage(
                  &this->MeshVertices,
                  this->MeshVertices.Size >> 4);
                v19 = v33;
              }
              v26 = &this->MeshVertices.Pages[v25][this->MeshVertices.Size & 0xF];
              v26->x = *(float *)v31;
              v26->y = *(float *)(v31 + 4);
              v26->Idx = *(_DWORD *)(v31 + 8);
              *(_DWORD *)v26->Styles = *(_DWORD *)(v31 + 12);
              *(_DWORD *)&v26->Flags = *(_DWORD *)(v31 + 16);
              ++this->MeshVertices.Size;
              v20 = v42;
              this->MeshVertices.Pages[(this->MeshVertices.Size - 1) >> 4][(this->MeshVertices.Size - 1) & 0xF].Mesh = v42;
            }
            if ( *(unsigned __int16 *)(v19 + 18) != v20 )
            {
              v16->d.t.v3 = this->MeshVertices.Size;
              v27 = this->MeshVertices.Size >> 4;
              if ( v27 >= this->MeshVertices.NumPages )
              {
                Scaleform::Render::ArrayPaged<Scaleform::Render::TessVertex,4,16>::allocPage(
                  &this->MeshVertices,
                  this->MeshVertices.Size >> 4);
                v19 = v33;
                LOWORD(v20) = v42;
              }
              v28 = &this->MeshVertices.Pages[v27][this->MeshVertices.Size & 0xF];
              v28->x = *(float *)v19;
              v28->y = *(float *)(v19 + 4);
              v28->Idx = *(_DWORD *)(v19 + 8);
              *(_DWORD *)v28->Styles = *(_DWORD *)(v19 + 12);
              *(_DWORD *)&v28->Flags = *(_DWORD *)(v19 + 16);
              ++this->MeshVertices.Size;
              this->MeshVertices.Pages[(this->MeshVertices.Size - 1) >> 4][(this->MeshVertices.Size - 1) & 0xF].Mesh = v20;
            }
            if ( ++v35 >= v37 )
              break;
            v15 = v35;
          }
          v14 = v42;
        }
      }
      ++v29;
      v42 = ++v14;
    }
    while ( v14 < this->Meshes.Size );
  }
}
