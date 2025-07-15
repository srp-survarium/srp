void __thiscall Scaleform::Render::Tessellator::Tessellate(Scaleform::Render::Tessellator *this, bool autoSplitMeshes)
{
  Scaleform::AmpServer *Instance; // eax
  Scaleform::AmpStats *v4; // eax
  unsigned int v5; // esi
  Scaleform::Render::LinearHeap *pHeap; // ecx
  unsigned int v7; // esi
  int v8; // esi
  unsigned __int8 *v9; // eax
  unsigned int i; // esi
  Scaleform::Render::Tessellator::PathType *v11; // eax
  unsigned int leftStyle; // ecx
  unsigned int rightStyle; // eax
  unsigned int j; // edi
  Scaleform::Render::Tessellator::PathType *v15; // esi
  unsigned int v16; // esi
  unsigned int k; // edi
  unsigned int NumArrays; // ecx
  unsigned int MaxArrays; // eax
  bool v20; // zf
  Scaleform::Render::LinearHeap *v21; // ecx
  unsigned __int8 *v22; // esi
  unsigned int v23; // ecx
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *v24; // eax
  unsigned int v25; // esi
  unsigned int m; // esi
  unsigned int n; // edx
  Scaleform::Render::TessVertex *v28; // ecx
  unsigned __int16 Mesh; // ax
  int v30; // ebx
  Scaleform::Render::TessMesh *v31; // eax
  unsigned int VertexLimit; // eax
  Scaleform::AmpStats *Stats; // edi
  void (__thiscall **p_NativePopCallstack)(Scaleform::AmpStats *, unsigned __int64); // esi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::AmpFunctionTimer v36; // [esp+10h] [ebp-2Ch] BYREF
  _DWORD v37[7]; // [esp+20h] [ebp-1Ch] BYREF

  Instance = Scaleform::AmpServer::GetInstance();
  v4 = Instance->GetDisplayStats(Instance);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &v36,
    v4,
    "Tessellator::Tessellate",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_Tessellate);
  this->MinX = 1.0e30;
  this->MinY = 1.0e30;
  this->MaxX = -1.0e30;
  this->MaxY = -1.0e30;
  Scaleform::Render::Tessellator::monotonize(this);
  memset(v37, 0, sizeof(v37));
  v5 = this->Meshes.Size >> 4;
  if ( v5 >= this->Meshes.NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::BaseLineType,4,4>::allocPage(
      &this->Meshes,
      this->Meshes.Size >> 4);
  qmemcpy(
    &this->Meshes.Pages[v5][this->Meshes.Size++ & 0xF],
    v37,
    sizeof(this->Meshes.Pages[v5][this->Meshes.Size++ & 0xF]));
  if ( this->HasComplexFill )
  {
    pHeap = this->StyleMatrix.pHeap;
    v7 = this->MaxStyle + 1;
    this->StyleMatrix.Size = v7;
    v8 = 2 * v7 * v7;
    v9 = Scaleform::Render::LinearHeap::Alloc(pHeap, v8);
    this->StyleMatrix.Array = (unsigned __int16 *)v9;
    memset((int)v9, 255, v8);
    for ( i = 0; i < this->Paths.Size; ++i )
    {
      v11 = &this->Paths.Pages[i >> 4][i & 0xF];
      leftStyle = v11->leftStyle;
      if ( leftStyle )
      {
        rightStyle = v11->rightStyle;
        if ( rightStyle )
          Scaleform::Render::Tessellator::setMesh(this, leftStyle, rightStyle);
      }
    }
    for ( j = 0; j < this->Paths.Size; ++j )
    {
      v15 = &this->Paths.Pages[j >> 4][j & 0xF];
      if ( v15->leftStyle )
        Scaleform::Render::Tessellator::setMesh(this, v15->leftStyle);
      v16 = v15->rightStyle;
      if ( v16 )
        Scaleform::Render::Tessellator::setMesh(this, v16);
    }
  }
  Scaleform::Render::Tessellator::clearHeap1(this);
  for ( k = 0; k < this->Meshes.Size; ++this->MeshTriangles.NumArrays )
  {
    NumArrays = this->MeshTriangles.NumArrays;
    MaxArrays = this->MeshTriangles.MaxArrays;
    if ( NumArrays >= MaxArrays )
    {
      v20 = NumArrays == 0;
      v21 = this->MeshTriangles.pHeap;
      if ( v20 )
      {
        this->MeshTriangles.MaxArrays = 16;
        this->MeshTriangles.Arrays = (Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *)Scaleform::Render::LinearHeap::Alloc(v21, 0x100u);
      }
      else
      {
        v22 = Scaleform::Render::LinearHeap::Alloc(v21, 32 * MaxArrays);
        memcpy((int)v22, (const __m128i *)this->MeshTriangles.Arrays, 16 * this->MeshTriangles.NumArrays);
        v23 = this->MeshTriangles.MaxArrays;
        this->MeshTriangles.Arrays = (Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *)v22;
        this->MeshTriangles.MaxArrays = 2 * v23;
      }
    }
    v24 = &this->MeshTriangles.Arrays[this->MeshTriangles.NumArrays];
    ++k;
    v24->Size = 0;
    v24->NumPages = 0;
    v24->MaxPages = 0;
    v24->Pages = 0;
  }
  if ( this->EdgeAAFlag )
  {
    if ( this->StrokerMode )
    {
      Scaleform::Render::Tessellator::setMesh(this, 1u);
      v25 = 0;
      for ( this->EdgeAAFlag = 0; v25 < this->Monotones.Size; ++v25 )
        Scaleform::Render::Tessellator::triangulateMonotoneAA(
          this,
          (Scaleform::Render::Tessellator::MonoVertexType *)&this->Monotones.Pages[v25 >> 4][v25 & 0xF]);
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
    v28 = &this->MeshVertices.Pages[n >> 4][n & 0xF];
    Mesh = v28->Mesh;
    if ( Mesh != 0xFFFF )
    {
      v30 = Mesh & 0xF;
      v31 = this->Meshes.Pages[Mesh >> 4];
      v28->Idx = v31[v30].VertexCount++;
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
  Stats = v36.Stats;
  if ( v36.Stats )
  {
    p_NativePopCallstack = &v36.Stats->NativePopCallstack;
    ProfileTicks = Scaleform::Timer::GetProfileTicks();
    ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))*p_NativePopCallstack)(
      Stats,
      ProfileTicks - LODWORD(v36.StartTicks),
      (ProfileTicks - v36.StartTicks) >> 32);
  }
}
