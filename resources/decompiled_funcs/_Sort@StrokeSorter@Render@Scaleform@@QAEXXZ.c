void __thiscall Scaleform::Render::StrokeSorter::Sort(Scaleform::Render::StrokeSorter *this)
{
  unsigned int Size; // ebx
  unsigned int v3; // ecx
  Scaleform::Render::StrokeSorter::PathType *v4; // edx
  int v5; // eax
  unsigned int start; // ebp
  unsigned int numVer; // eax
  unsigned int v8; // ebp
  unsigned __int8 *v9; // ebp
  unsigned __int8 *Array; // eax
  unsigned int v11; // ecx
  unsigned int v12; // edi
  unsigned int v13; // ecx
  unsigned int v14; // edx
  int v15; // edi
  unsigned int v16; // ebx
  Scaleform::Render::StrokeSorter::VertexType *v17; // eax
  Scaleform::Render::StrokeSorter::SortedPathType *v18; // ebx
  unsigned int v19; // edx
  int v20; // edi
  unsigned int v21; // ebx
  Scaleform::Render::StrokeSorter::VertexType *v22; // eax
  Scaleform::Render::StrokeSorter::SortedPathType *v23; // ebx
  int v24; // ebx
  unsigned int v25; // edx
  int v26; // edi
  unsigned int v27; // ebx
  Scaleform::Render::StrokeSorter::VertexType *v28; // eax
  int v29; // ebp
  Scaleform::Render::StrokeSorter::SortedPathType *v30; // ebx
  Scaleform::Render::StrokeSorter::VertexType **Pages; // ebx
  unsigned int v32; // edx
  Scaleform::Render::StrokeSorter::PathType *v33; // edi
  float *p_x; // eax
  float *v35; // edi
  unsigned int v36; // ecx
  int v37; // edx
  unsigned int v38; // ebx
  Scaleform::Render::StrokeSorter::VertexType *v39; // eax
  Scaleform::Render::StrokeSorter::SortedPathType *v40; // ebx
  unsigned int Next; // eax
  int v42; // eax
  Scaleform::Render::StrokeSorter::PathType *thisPath; // ecx
  unsigned int v44; // edi
  Scaleform::Render::StrokeSorter::VertexType **v45; // edx
  unsigned int v46; // ebp
  float *v47; // ecx
  float *v48; // edx
  Scaleform::Render::StrokeSorter::VertexType **v49; // edx
  float *v50; // ecx
  float *v51; // edx
  unsigned int v52; // ecx
  Scaleform::Render::StrokeSorter::PathType *v53; // ecx
  unsigned int v54; // eax
  unsigned int i; // [esp+10h] [ebp-18h]
  unsigned int ia; // [esp+10h] [ebp-18h]
  unsigned int ib; // [esp+10h] [ebp-18h]
  int v58; // [esp+14h] [ebp-14h]
  unsigned int v59; // [esp+14h] [ebp-14h]
  int v60; // [esp+14h] [ebp-14h]
  unsigned int n; // [esp+18h] [ebp-10h] BYREF
  unsigned int v62; // [esp+1Ch] [ebp-Ch]
  Scaleform::Render::StrokeSorter::PathType p; // [esp+20h] [ebp-8h]

  Size = this->SrcPaths.Size;
  v3 = 0;
  n = Size;
  for ( i = 0; v3 < Size; i = v3 )
  {
    v4 = this->SrcPaths.Pages[v3 >> 4];
    v5 = v3 & 0xF;
    start = v4[v5].start;
    numVer = v4[v5].numVer;
    p.start = start;
    v8 = this->SrcPaths.Size >> 4;
    p.numVer = numVer;
    if ( v8 >= this->SrcPaths.NumPages )
    {
      Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16>::allocPage(
        (Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16> *)&this->SrcPaths,
        v8);
      v3 = i;
    }
    this->SrcPaths.Pages[v8][this->SrcPaths.Size & 0xF] = p;
    ++v3;
    ++this->SrcPaths.Size;
  }
  if ( Size > this->SortedPaths.Size )
  {
    v9 = Scaleform::Render::LinearHeap::Alloc(this->SortedPaths.pHeap, 12 * Size);
    memset((int)v9, 0, 12 * Size);
    Array = (unsigned __int8 *)this->SortedPaths.Array;
    if ( Array )
    {
      v11 = this->SortedPaths.Size;
      if ( v11 )
        memcpy(v9, Array, 12 * v11);
    }
    this->SortedPaths.Array = (Scaleform::Render::StrokeSorter::SortedPathType *)v9;
  }
  v12 = 0;
  this->SortedPaths.Size = Size;
  ia = 0;
  if ( (int)Size >= 4 )
  {
    v13 = 2;
    v58 = 0;
    do
    {
      v14 = v12 >> 4;
      v15 = v12 & 0xF;
      v16 = this->SrcPaths.Pages[v14][v15].start;
      v17 = &this->SrcVertices.Pages[v16 >> 4][v16 & 0xF];
      v18 = &this->SortedPaths.Array[v58];
      v18->x = v17->x;
      v18->y = v17->y;
      v18->thisPath = &this->SrcPaths.Pages[v14][v15];
      v19 = (v13 - 1) >> 4;
      v20 = ((_BYTE)v13 - 1) & 0xF;
      v21 = this->SrcPaths.Pages[v19][v20].start;
      v22 = &this->SrcVertices.Pages[v21 >> 4][v21 & 0xF];
      v23 = this->SortedPaths.Array;
      v23[v58 + 1].x = v22->x;
      v24 = (int)&v23[v58 + 1];
      *(float *)(v24 + 4) = v22->y;
      *(_DWORD *)(v24 + 8) = &this->SrcPaths.Pages[v19][v20];
      v25 = v13 >> 4;
      v26 = v13 & 0xF;
      v27 = this->SrcPaths.Pages[v25][v26].start;
      v28 = &this->SrcVertices.Pages[v27 >> 4][v27 & 0xF];
      v29 = v58 * 12 + 36;
      v30 = &this->SortedPaths.Array[v58 + 2];
      v30->x = v28->x;
      v30->y = v28->y;
      v30->thisPath = &this->SrcPaths.Pages[v25][v26];
      Pages = this->SrcVertices.Pages;
      v32 = (v13 + 1) >> 4;
      v33 = this->SrcPaths.Pages[v32];
      p.start = 8 * ((v13 + 1) & 0xF);
      v58 += 4;
      p_x = &Pages[*(unsigned int *)((char *)&v33->start + p.start) >> 4][*(unsigned int *)((_BYTE *)&v33->start
                                                                                          + p.start)
                                                                        & 0xF].x;
      Size = n;
      v35 = (float *)((char *)&this->SortedPaths.Array->x + v29);
      *v35 = *p_x;
      v13 += 4;
      v35[1] = p_x[1];
      *((_DWORD *)v35 + 2) = (char *)this->SrcPaths.Pages[v32] + p.start;
      v12 = ia + 4;
      ia = v12;
    }
    while ( v12 < Size - 3 );
  }
  if ( v12 < Size )
  {
    v59 = v12;
    do
    {
      v36 = v12 >> 4;
      v37 = v12 & 0xF;
      v38 = this->SrcPaths.Pages[v36][v37].start;
      v39 = &this->SrcVertices.Pages[v38 >> 4][v38 & 0xF];
      v40 = &this->SortedPaths.Array[v59];
      v40->x = v39->x;
      ++v12;
      v40->y = v39->y;
      v40->thisPath = &this->SrcPaths.Pages[v36][v37];
      ++v59;
    }
    while ( v12 < n );
  }
  Scaleform::Alg::QuickSortSliced<Scaleform::Render::ArrayUnsafe<Scaleform::Render::StrokeSorter::SortedPathType>,bool (__cdecl *)(Scaleform::Render::StrokeSorter::SortedPathType const &,Scaleform::Render::StrokeSorter::SortedPathType const &)>(
    &this->SortedPaths,
    0,
    this->SortedPaths.Size,
    (bool (__cdecl *)(const Scaleform::Render::StrokeSorter::SortedPathType *, const Scaleform::Render::StrokeSorter::SortedPathType *))Scaleform::Render::StrokeSorter::cmpPaths);
  Next = 0;
  ib = 0;
  if ( this->SortedPaths.Size )
  {
    v60 = 0;
    do
    {
      if ( (this->SortedPaths.Array[v60].thisPath->numVer & 0x40000000) == 0 )
      {
        n = 0;
        v62 = 0;
        do
        {
          v42 = Next & 0xFFFFFFF;
          thisPath = this->SortedPaths.Array[v42].thisPath;
          thisPath->numVer |= 0x40000000u;
          Scaleform::Render::StrokeSorter::appendPath(
            this,
            (Scaleform::Render::StrokeSorter::PathType *)&n,
            this->SortedPaths.Array[v42].thisPath);
          v44 = n;
          v45 = this->OutVertices.Pages;
          v46 = v62;
          v47 = &v45[n >> 4][n & 0xF].x;
          v48 = &v45[((v62 & 0xFFFFFFF) + n - 1) >> 4][((v62 & 0xFFFFFFF) + n - 1) & 0xF].x;
          if ( *v48 == *v47 && v48[1] == v47[1] )
            break;
          Next = Scaleform::Render::StrokeSorter::findNext(this, (const Scaleform::Render::StrokeSorter::PathType *)&n);
        }
        while ( Next != -1 );
        v49 = this->OutVertices.Pages;
        v50 = &v49[v44 >> 4][v44 & 0xF].x;
        v51 = &v49[((v46 & 0xFFFFFFF) + v44 - 1) >> 4][((v46 & 0xFFFFFFF) + v44 - 1) & 0xF].x;
        if ( *v51 == *v50 && v51[1] == v50[1] )
          v46 |= 0x20000000u;
        v52 = this->OutPaths.Size >> 4;
        p.start = v52;
        if ( v52 >= this->OutPaths.NumPages )
        {
          Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16> *)&this->OutPaths,
            v52);
          v52 = p.start;
        }
        v53 = this->OutPaths.Pages[v52];
        v54 = this->OutPaths.Size & 0xF;
        v53[v54].start = v44;
        v53[v54].numVer = v46;
        ++this->OutPaths.Size;
        Next = ib;
      }
      ++v60;
      ib = ++Next;
    }
    while ( Next < this->SortedPaths.Size );
  }
}
