void __thiscall Scaleform::Render::Tessellator::Tessellate(Scaleform::Render::Tessellator *this, bool autoSplitMeshes)
{
  unsigned int v3; // esi
  Scaleform::Render::LinearHeap *pHeap; // ecx
  unsigned int v5; // esi
  unsigned int v6; // esi
  unsigned __int8 *v7; // eax
  unsigned int i; // esi
  Scaleform::Render::Tessellator::PathType *v9; // eax
  unsigned int leftStyle; // ecx
  unsigned int rightStyle; // eax
  unsigned int j; // edi
  Scaleform::Render::Tessellator::PathType *v13; // esi
  unsigned int v14; // esi
  unsigned int k; // edi
  unsigned int NumArrays; // ecx
  unsigned int MaxArrays; // eax
  bool v18; // zf
  Scaleform::Render::LinearHeap *v19; // ecx
  unsigned __int8 *v20; // esi
  unsigned int v21; // ecx
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *v22; // eax
  unsigned int v23; // esi
  unsigned int m; // esi
  unsigned int n; // edx
  Scaleform::Render::TessVertex *v26; // ecx
  unsigned __int16 Mesh; // ax
  int v28; // ebx
  Scaleform::Render::TessMesh *v29; // eax
  unsigned int VertexLimit; // eax
  Scaleform::Render::TessMesh solidMesh; // [esp+8h] [ebp-1Ch] BYREF

  this->MinX = 1.0e30;
  this->MinY = 1.0e30;
  this->MaxX = -1.0e30;
  this->MaxY = -1.0e30;
  Scaleform::Render::Tessellator::monotonize(this);
  v3 = this->Meshes.Size >> 4;
  memset(&solidMesh, 0, sizeof(solidMesh));
  if ( v3 >= this->Meshes.NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::BaseLineType,4,4>::allocPage(&this->Meshes, v3);
  qmemcpy(
    &this->Meshes.Pages[v3][this->Meshes.Size++ & 0xF],
    &solidMesh,
    sizeof(this->Meshes.Pages[v3][this->Meshes.Size++ & 0xF]));
  if ( this->HasComplexFill )
  {
    pHeap = this->StyleMatrix.pHeap;
    v5 = this->MaxStyle + 1;
    this->StyleMatrix.Size = v5;
    v6 = 2 * v5 * v5;
    v7 = Scaleform::Render::LinearHeap::Alloc(pHeap, v6);
    this->StyleMatrix.Array = (unsigned __int16 *)v7;
    memset((int)v7, (unsigned __int8 *)0xFF, v6);
    for ( i = 0; i < this->Paths.Size; ++i )
    {
      v9 = &this->Paths.Pages[i >> 4][i & 0xF];
      leftStyle = v9->leftStyle;
      if ( leftStyle )
      {
        rightStyle = v9->rightStyle;
        if ( rightStyle )
          Scaleform::Render::Tessellator::setMesh(this, leftStyle, rightStyle);
      }
    }
    for ( j = 0; j < this->Paths.Size; ++j )
    {
      v13 = &this->Paths.Pages[j >> 4][j & 0xF];
      if ( v13->leftStyle )
        Scaleform::Render::Tessellator::setMesh(this, v13->leftStyle);
      v14 = v13->rightStyle;
      if ( v14 )
        Scaleform::Render::Tessellator::setMesh(this, v14);
    }
  }
  Scaleform::Render::Tessellator::clearHeap1(this);
  for ( k = 0; k < this->Meshes.Size; ++this->MeshTriangles.NumArrays )
  {
    NumArrays = this->MeshTriangles.NumArrays;
    MaxArrays = this->MeshTriangles.MaxArrays;
    if ( NumArrays >= MaxArrays )
    {
      v18 = NumArrays == 0;
      v19 = this->MeshTriangles.pHeap;
      if ( v18 )
      {
        this->MeshTriangles.MaxArrays = 16;
        this->MeshTriangles.Arrays = (Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *)Scaleform::Render::LinearHeap::Alloc(v19, 0x100u);
      }
      else
      {
        v20 = Scaleform::Render::LinearHeap::Alloc(v19, 32 * MaxArrays);
        memcpy(v20, (unsigned __int8 *)this->MeshTriangles.Arrays, 16 * this->MeshTriangles.NumArrays);
        v21 = this->MeshTriangles.MaxArrays;
        this->MeshTriangles.Arrays = (Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *)v20;
        this->MeshTriangles.MaxArrays = 2 * v21;
      }
    }
    v22 = &this->MeshTriangles.Arrays[this->MeshTriangles.NumArrays];
    ++k;
    v22->Size = 0;
    v22->NumPages = 0;
    v22->MaxPages = 0;
    v22->Pages = 0;
  }
  if ( this->EdgeAAFlag )
  {
    if ( this->StrokerMode )
    {
      Scaleform::Render::Tessellator::setMesh(this, 1u);
      v23 = 0;
      for ( this->EdgeAAFlag = 0; v23 < this->Monotones.Size; ++v23 )
        Scaleform::Render::Tessellator::triangulateMonotoneAA(
          this,
          (Scaleform::Render::Tessellator::MonoVertexType *)&this->Monotones.Pages[v23 >> 4][v23 & 0xF]);
      this->EdgeAAFlag = 1;
      Scaleform::Render::Tessellator::processStrokerEdges(this);
    }
    else
    {
      Scaleform::Render::Tessellator::processEdgeAA(this);
    }
  }
  else
  {
    for ( m = 0; m < this->Monotones.Size; ++m )
      Scaleform::Render::Tessellator::triangulateMonotoneAA(
        this,
        (Scaleform::Render::Tessellator::MonoVertexType *)&this->Monotones.Pages[m >> 4][m & 0xF]);
  }
  for ( n = 0; n < this->MeshVertices.Size; ++n )
  {
    v26 = &this->MeshVertices.Pages[n >> 4][n & 0xF];
    Mesh = v26->Mesh;
    if ( Mesh != 0xFFFF )
    {
      v28 = Mesh & 0xF;
      v29 = this->Meshes.Pages[Mesh >> 4];
      v26->Idx = v29[v28].VertexCount++;
    }
  }
  if ( autoSplitMeshes )
  {
    VertexLimit = this->VertexLimit;
    if ( VertexLimit )
    {
      if ( this->MeshVertices.Size > VertexLimit )
        Scaleform::Render::Tessellator::SplitMeshes(this);
    }
  }
}
