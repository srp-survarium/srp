void __thiscall Scaleform::Render::ShapeMeshProvider::addStroke(
        Scaleform::Render::ShapeMeshProvider *this,
        Scaleform::Render::MeshGenerator *gen,
        const Scaleform::Render::ToleranceParams *param,
        Scaleform::Render::TransformerBase *tr,
        unsigned int startPos,
        unsigned int strokeStyleIdx,
        float snapOffset,
        float morphRatio)
{
  unsigned int v8; // ebx
  int v9; // ebp
  int v10; // edx
  unsigned int v11; // esi
  int v12; // eax
  int v13; // ecx
  _DWORD *v14; // eax
  unsigned int v15; // ecx
  unsigned int v16; // ebx
  Scaleform::Render::StrokeSorter::VertexType *v17; // ebx
  int v18; // eax
  int v19; // ecx
  _DWORD *v20; // eax
  unsigned int v21; // ecx
  unsigned int v22; // edx
  Scaleform::Render::StrokeSorter::VertexType *v23; // eax
  _DWORD *v24; // ecx
  unsigned int v25; // esi
  unsigned int v26; // edx
  unsigned int v27; // ebp
  Scaleform::Render::StrokeSorter::VertexType *v28; // ecx
  int v29; // eax
  int v30; // ecx
  _DWORD *v31; // eax
  unsigned int v32; // ecx
  unsigned int v33; // edx
  Scaleform::Render::StrokeSorter::VertexType *v34; // eax
  unsigned int n; // [esp+38h] [ebp+10h]
  unsigned int strokeStyleIdxa; // [esp+3Ch] [ebp+14h]
  unsigned int i; // [esp+40h] [ebp+18h]
  int morphRatioa; // [esp+44h] [ebp+1Ch]

  Scaleform::Render::ShapeMeshProvider::addToStrokeSorter(
    this,
    gen,
    param,
    tr,
    startPos,
    strokeStyleIdx,
    snapOffset,
    morphRatio);
  gen->mStroker.Clear(&gen->mStroker);
  v8 = 0;
  i = 0;
  if ( !gen->mStrokeSorter.OutPaths.Size )
    return;
  do
  {
    v9 = 4 * (v8 >> 4);
    v10 = 8 * (v8 & 0xF);
    strokeStyleIdxa = v9;
    morphRatioa = v10;
    n = *(unsigned int *)((_BYTE *)&(*(Scaleform::Render::StrokeSorter::PathType **)((char *)gen->mStrokeSorter.OutPaths.Pages
                                                                                   + v9))->numVer
                        + v10)
      & 0xFFFFFFF;
    v11 = 0;
    if ( !n )
      goto LABEL_20;
    do
    {
      v12 = *(int *)((char *)gen->mStrokeSorter.OutPaths.Pages + v9);
      v13 = *(_DWORD *)(v12 + v10 + 4);
      v14 = (_DWORD *)(v10 + v12);
      v15 = v13 & 0xFFFFFFF;
      v16 = v11;
      if ( v11 >= v15 )
        v16 = v11 - v15;
      ++v11;
      v17 = &gen->mStrokeSorter.OutVertices.Pages[(v16 + *v14) >> 4][(v16 + *v14) & 0xF];
      switch ( v17->segType )
      {
        case 1u:
          ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))gen->mStroker.AddVertex)(&gen->mStroker, v17->x, v17->y);
          break;
        case 2u:
          v29 = *(int *)((char *)gen->mStrokeSorter.OutPaths.Pages + v9);
          v30 = *(_DWORD *)(v29 + v10 + 4);
          v31 = (_DWORD *)(v10 + v29);
          v32 = v30 & 0xFFFFFFF;
          v33 = v11;
          if ( v11 >= v32 )
            v33 = v11 - v32;
          v34 = &gen->mStrokeSorter.OutVertices.Pages[(v33 + *v31) >> 4][(v33 + *v31) & 0xF];
          ++v11;
          Scaleform::Render::TessellateQuadCurve(&gen->mStroker, param, v17->x, v17->y, v34->x, v34->y);
          break;
        case 3u:
          v18 = *(int *)((char *)gen->mStrokeSorter.OutPaths.Pages + v9);
          v19 = *(_DWORD *)(v18 + v10 + 4);
          v20 = (_DWORD *)(v10 + v18);
          v21 = v19 & 0xFFFFFFF;
          v22 = v11;
          if ( v11 >= v21 )
            v22 = v11 - v21;
          v23 = &gen->mStrokeSorter.OutVertices.Pages[(v22 + *v20) >> 4][(v22 + *v20) & 0xF];
          v24 = (unsigned int *)((char *)&(*(Scaleform::Render::StrokeSorter::PathType **)((char *)gen->mStrokeSorter.OutPaths.Pages
                                                                                         + v9))->start
                               + morphRatioa);
          v25 = v11 + 1;
          v26 = v24[1] & 0xFFFFFFF;
          v27 = v25;
          if ( v25 >= v26 )
            v27 = v25 - v26;
          v28 = &gen->mStrokeSorter.OutVertices.Pages[(v27 + *v24) >> 4][(v27 + *v24) & 0xF];
          v11 = v25 + 1;
          Scaleform::Render::TessellateCubicCurve(&gen->mStroker, param, v17->x, v17->y, v23->x, v23->y, v28->x, v28->y);
          v9 = strokeStyleIdxa;
          break;
        default:
          continue;
      }
      v10 = morphRatioa;
    }
    while ( v11 < n );
    v8 = i;
LABEL_20:
    Scaleform::Render::Stroker::GenerateStroke(&gen->mStroker, &gen->mTess);
    i = ++v8;
  }
  while ( v8 < gen->mStrokeSorter.OutPaths.Size );
}


void __thiscall Scaleform::Render::ShapeMeshProvider::addStroke(
        Scaleform::Render::ShapeMeshProvider *this,
        Scaleform::Render::MeshGenerator *gen,
        Scaleform::Render::TessBase *stroker,
        const Scaleform::Render::ToleranceParams *param,
        Scaleform::Render::TransformerBase *tr,
        unsigned int startPos,
        unsigned int strokeStyleIdx,
        float snapOffset,
        float morphRatio)
{
  unsigned int v9; // ebx
  int v10; // ebp
  int v11; // edx
  unsigned int v12; // esi
  int v13; // eax
  int v14; // ecx
  _DWORD *v15; // eax
  unsigned int v16; // ecx
  unsigned int v17; // ebx
  Scaleform::Render::StrokeSorter::VertexType *v18; // ebx
  int v19; // eax
  int v20; // ecx
  _DWORD *v21; // eax
  unsigned int v22; // ecx
  unsigned int v23; // edx
  Scaleform::Render::StrokeSorter::VertexType *v24; // eax
  _DWORD *v25; // ecx
  unsigned int v26; // esi
  unsigned int v27; // edx
  unsigned int v28; // ebp
  Scaleform::Render::StrokeSorter::VertexType *v29; // ecx
  int v30; // eax
  int v31; // ecx
  _DWORD *v32; // eax
  unsigned int v33; // ecx
  unsigned int v34; // edx
  Scaleform::Render::StrokeSorter::VertexType *v35; // eax
  unsigned int n; // [esp+3Ch] [ebp+14h]
  unsigned int strokeStyleIdxa; // [esp+40h] [ebp+18h]
  unsigned int i; // [esp+44h] [ebp+1Ch]
  int morphRatioa; // [esp+48h] [ebp+20h]

  Scaleform::Render::ShapeMeshProvider::addToStrokeSorter(
    this,
    gen,
    param,
    tr,
    startPos,
    strokeStyleIdx,
    snapOffset,
    morphRatio);
  stroker->Clear(stroker);
  v9 = 0;
  i = 0;
  if ( !gen->mStrokeSorter.OutPaths.Size )
    return;
  do
  {
    v10 = 4 * (v9 >> 4);
    v11 = 8 * (v9 & 0xF);
    strokeStyleIdxa = v10;
    morphRatioa = v11;
    n = *(unsigned int *)((_BYTE *)&(*(Scaleform::Render::StrokeSorter::PathType **)((char *)gen->mStrokeSorter.OutPaths.Pages
                                                                                   + v10))->numVer
                        + v11)
      & 0xFFFFFFF;
    v12 = 0;
    if ( !n )
      goto LABEL_20;
    do
    {
      v13 = *(int *)((char *)gen->mStrokeSorter.OutPaths.Pages + v10);
      v14 = *(_DWORD *)(v13 + v11 + 4);
      v15 = (_DWORD *)(v11 + v13);
      v16 = v14 & 0xFFFFFFF;
      v17 = v12;
      if ( v12 >= v16 )
        v17 = v12 - v16;
      ++v12;
      v18 = &gen->mStrokeSorter.OutVertices.Pages[(v17 + *v15) >> 4][(v17 + *v15) & 0xF];
      switch ( v18->segType )
      {
        case 1u:
          ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))stroker->AddVertex)(stroker, v18->x, v18->y);
          break;
        case 2u:
          v30 = *(int *)((char *)gen->mStrokeSorter.OutPaths.Pages + v10);
          v31 = *(_DWORD *)(v30 + v11 + 4);
          v32 = (_DWORD *)(v11 + v30);
          v33 = v31 & 0xFFFFFFF;
          v34 = v12;
          if ( v12 >= v33 )
            v34 = v12 - v33;
          v35 = &gen->mStrokeSorter.OutVertices.Pages[(v34 + *v32) >> 4][(v34 + *v32) & 0xF];
          ++v12;
          Scaleform::Render::TessellateQuadCurve(stroker, param, v18->x, v18->y, v35->x, v35->y);
          break;
        case 3u:
          v19 = *(int *)((char *)gen->mStrokeSorter.OutPaths.Pages + v10);
          v20 = *(_DWORD *)(v19 + v11 + 4);
          v21 = (_DWORD *)(v11 + v19);
          v22 = v20 & 0xFFFFFFF;
          v23 = v12;
          if ( v12 >= v22 )
            v23 = v12 - v22;
          v24 = &gen->mStrokeSorter.OutVertices.Pages[(v23 + *v21) >> 4][(v23 + *v21) & 0xF];
          v25 = (unsigned int *)((char *)&(*(Scaleform::Render::StrokeSorter::PathType **)((char *)gen->mStrokeSorter.OutPaths.Pages
                                                                                         + v10))->start
                               + morphRatioa);
          v26 = v12 + 1;
          v27 = v25[1] & 0xFFFFFFF;
          v28 = v26;
          if ( v26 >= v27 )
            v28 = v26 - v27;
          v29 = &gen->mStrokeSorter.OutVertices.Pages[(v28 + *v25) >> 4][(v28 + *v25) & 0xF];
          v12 = v26 + 1;
          Scaleform::Render::TessellateCubicCurve(stroker, param, v18->x, v18->y, v24->x, v24->y, v29->x, v29->y);
          v10 = strokeStyleIdxa;
          break;
        default:
          continue;
      }
      v11 = morphRatioa;
    }
    while ( v12 < n );
    v9 = i;
LABEL_20:
    stroker->FinalizePath(stroker, 0, 0, 0, 0);
    i = ++v9;
  }
  while ( v9 < gen->mStrokeSorter.OutPaths.Size );
}
