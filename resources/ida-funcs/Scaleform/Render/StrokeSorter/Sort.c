void __thiscall Scaleform::Render::StrokeSorter::Sort(Scaleform::Render::StrokeSorter *this)
{
  unsigned int Size; // ebx
  unsigned int v3; // ecx
  Scaleform::Render::StrokeSorter::PathType *v4; // edx
  int v5; // eax
  unsigned int start; // ebp
  unsigned int numVer; // eax
  unsigned int v8; // ebp
  Scaleform::Render::StrokeSorter::PathType *v9; // ebp
  unsigned int v10; // eax
  unsigned __int8 *v11; // ebp
  Scaleform::Render::StrokeSorter::SortedPathType *Array; // eax
  unsigned int v13; // ecx
  unsigned int v14; // edi
  unsigned int v15; // ecx
  unsigned int v16; // edx
  int v17; // edi
  unsigned int v18; // ebx
  Scaleform::Render::StrokeSorter::VertexType *v19; // eax
  Scaleform::Render::StrokeSorter::SortedPathType *v20; // ebx
  unsigned int v21; // edx
  int v22; // edi
  unsigned int v23; // ebx
  Scaleform::Render::StrokeSorter::VertexType *v24; // eax
  Scaleform::Render::StrokeSorter::SortedPathType *v25; // ebx
  int v26; // ebx
  unsigned int v27; // edx
  int v28; // edi
  unsigned int v29; // ebx
  Scaleform::Render::StrokeSorter::VertexType *v30; // eax
  int v31; // ebp
  Scaleform::Render::StrokeSorter::SortedPathType *v32; // ebx
  Scaleform::Render::StrokeSorter::VertexType **Pages; // ebx
  unsigned int v34; // edx
  Scaleform::Render::StrokeSorter::PathType *v35; // edi
  float *p_x; // eax
  float *v37; // edi
  unsigned int v38; // ecx
  int v39; // edx
  unsigned int v40; // ebx
  Scaleform::Render::StrokeSorter::VertexType *v41; // eax
  Scaleform::Render::StrokeSorter::SortedPathType *v42; // ebx
  unsigned int Next; // eax
  int v44; // eax
  Scaleform::Render::StrokeSorter::PathType *thisPath; // ecx
  unsigned int v46; // edi
  Scaleform::Render::StrokeSorter::VertexType **v47; // edx
  unsigned int v48; // ebp
  float *v49; // ecx
  float *v50; // edx
  Scaleform::Render::StrokeSorter::VertexType **v51; // edx
  float *v52; // ecx
  float *v53; // edx
  unsigned int v54; // ecx
  Scaleform::Render::StrokeSorter::PathType *v55; // ecx
  unsigned int v56; // eax
  unsigned int i; // [esp+10h] [ebp-18h]
  unsigned int v58; // [esp+10h] [ebp-18h]
  unsigned int v59; // [esp+10h] [ebp-18h]
  int v60; // [esp+14h] [ebp-14h]
  unsigned int v61; // [esp+14h] [ebp-14h]
  int v62; // [esp+14h] [ebp-14h]
  Scaleform::Render::StrokeSorter::PathType dst; // [esp+18h] [ebp-10h] BYREF
  int v64; // [esp+20h] [ebp-8h]
  unsigned int v65; // [esp+24h] [ebp-4h]

  Size = this->SrcPaths.Size;
  v3 = 0;
  dst.start = Size;
  for ( i = 0; v3 < Size; i = v3 )
  {
    v4 = this->SrcPaths.Pages[v3 >> 4];
    v5 = v3 & 0xF;
    start = v4[v5].start;
    numVer = v4[v5].numVer;
    v64 = start;
    v8 = this->SrcPaths.Size >> 4;
    v65 = numVer;
    if ( v8 >= this->SrcPaths.NumPages )
    {
      Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16>::allocPage(
        (Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16> *)&this->SrcPaths,
        v8);
      v3 = i;
    }
    v9 = this->SrcPaths.Pages[v8];
    v10 = this->SrcPaths.Size & 0xF;
    v9[v10].start = v64;
    ++v3;
    v9[v10].numVer = v65;
    ++this->SrcPaths.Size;
  }
  if ( Size > this->SortedPaths.Size )
  {
    v11 = Scaleform::Render::LinearHeap::Alloc(this->SortedPaths.pHeap, 12 * Size);
    memset((int)v11, 0, 12 * Size);
    Array = this->SortedPaths.Array;
    if ( Array )
    {
      v13 = this->SortedPaths.Size;
      if ( v13 )
        memcpy((int)v11, (const __m128i *)Array, 12 * v13);
    }
    this->SortedPaths.Array = (Scaleform::Render::StrokeSorter::SortedPathType *)v11;
  }
  v14 = 0;
  this->SortedPaths.Size = Size;
  v58 = 0;
  if ( (int)Size >= 4 )
  {
    v15 = 2;
    v60 = 0;
    do
    {
      v16 = v14 >> 4;
      v17 = v14 & 0xF;
      v18 = this->SrcPaths.Pages[v16][v17].start;
      v19 = &this->SrcVertices.Pages[v18 >> 4][v18 & 0xF];
      v20 = &this->SortedPaths.Array[v60];
      v20->x = v19->x;
      v20->y = v19->y;
      v20->thisPath = &this->SrcPaths.Pages[v16][v17];
      v21 = (v15 - 1) >> 4;
      v22 = ((_BYTE)v15 - 1) & 0xF;
      v23 = this->SrcPaths.Pages[v21][v22].start;
      v24 = &this->SrcVertices.Pages[v23 >> 4][v23 & 0xF];
      v25 = this->SortedPaths.Array;
      v25[v60 + 1].x = v24->x;
      v26 = (int)&v25[v60 + 1];
      *(float *)(v26 + 4) = v24->y;
      *(_DWORD *)(v26 + 8) = &this->SrcPaths.Pages[v21][v22];
      v27 = v15 >> 4;
      v28 = v15 & 0xF;
      v29 = this->SrcPaths.Pages[v27][v28].start;
      v30 = &this->SrcVertices.Pages[v29 >> 4][v29 & 0xF];
      v31 = v60 * 12 + 36;
      v32 = &this->SortedPaths.Array[v60 + 2];
      v32->x = v30->x;
      v32->y = v30->y;
      v32->thisPath = &this->SrcPaths.Pages[v27][v28];
      Pages = this->SrcVertices.Pages;
      v34 = (v15 + 1) >> 4;
      v35 = this->SrcPaths.Pages[v34];
      v64 = 8 * ((v15 + 1) & 0xF);
      v60 += 4;
      p_x = &Pages[*(unsigned int *)((char *)&v35->start + v64) >> 4][*(unsigned int *)((_BYTE *)&v35->start + v64)
                                                                    & 0xF].x;
      Size = dst.start;
      v37 = (float *)((char *)&this->SortedPaths.Array->x + v31);
      *v37 = *p_x;
      v15 += 4;
      v37[1] = p_x[1];
      *((_DWORD *)v37 + 2) = (char *)this->SrcPaths.Pages[v34] + v64;
      v14 = v58 + 4;
      v58 = v14;
    }
    while ( v14 < Size - 3 );
  }
  if ( v14 < Size )
  {
    v61 = v14;
    do
    {
      v38 = v14 >> 4;
      v39 = v14 & 0xF;
      v40 = this->SrcPaths.Pages[v38][v39].start;
      v41 = &this->SrcVertices.Pages[v40 >> 4][v40 & 0xF];
      v42 = &this->SortedPaths.Array[v61];
      v42->x = v41->x;
      ++v14;
      v42->y = v41->y;
      v42->thisPath = &this->SrcPaths.Pages[v38][v39];
      ++v61;
    }
    while ( v14 < dst.start );
  }
  Scaleform::Alg::QuickSortSliced<Scaleform::Render::ArrayUnsafe<Scaleform::Render::StrokeSorter::SortedPathType>,bool (__cdecl *)(Scaleform::Render::StrokeSorter::SortedPathType const &,Scaleform::Render::StrokeSorter::SortedPathType const &)>(
    &this->SortedPaths,
    0,
    this->SortedPaths.Size,
    (bool (__cdecl *)(const Scaleform::Render::StrokeSorter::SortedPathType *, const Scaleform::Render::StrokeSorter::SortedPathType *))Scaleform::Render::StrokeSorter::cmpPaths);
  Next = 0;
  v59 = 0;
  if ( this->SortedPaths.Size )
  {
    v62 = 0;
    do
    {
      if ( (this->SortedPaths.Array[v62].thisPath->numVer & 0x40000000) == 0 )
      {
        dst.start = 0;
        dst.numVer = 0;
        do
        {
          v44 = Next & 0xFFFFFFF;
          thisPath = this->SortedPaths.Array[v44].thisPath;
          thisPath->numVer |= 0x40000000u;
          Scaleform::Render::StrokeSorter::appendPath(this, &dst, this->SortedPaths.Array[v44].thisPath);
          v46 = dst.start;
          v47 = this->OutVertices.Pages;
          v48 = dst.numVer;
          v49 = &v47[dst.start >> 4][dst.start & 0xF].x;
          v50 = &v47[((dst.numVer & 0xFFFFFFF) + dst.start - 1) >> 4][((dst.numVer & 0xFFFFFFF) + dst.start - 1) & 0xF].x;
          if ( *v50 == *v49 && v50[1] == v49[1] )
            break;
          Next = Scaleform::Render::StrokeSorter::findNext(this, &dst);
        }
        while ( Next != -1 );
        v51 = this->OutVertices.Pages;
        v52 = &v51[v46 >> 4][v46 & 0xF].x;
        v53 = &v51[((v48 & 0xFFFFFFF) + v46 - 1) >> 4][((v48 & 0xFFFFFFF) + v46 - 1) & 0xF].x;
        if ( *v53 == *v52 && v53[1] == v52[1] )
          v48 |= 0x20000000u;
        v54 = this->OutPaths.Size >> 4;
        v64 = v54;
        if ( v54 >= this->OutPaths.NumPages )
        {
          Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16> *)&this->OutPaths,
            v54);
          v54 = v64;
        }
        v55 = this->OutPaths.Pages[v54];
        v56 = this->OutPaths.Size & 0xF;
        v55[v56].start = v46;
        v55[v56].numVer = v48;
        ++this->OutPaths.Size;
        Next = v59;
      }
      ++v62;
      v59 = ++Next;
    }
    while ( Next < this->SortedPaths.Size );
  }
}
