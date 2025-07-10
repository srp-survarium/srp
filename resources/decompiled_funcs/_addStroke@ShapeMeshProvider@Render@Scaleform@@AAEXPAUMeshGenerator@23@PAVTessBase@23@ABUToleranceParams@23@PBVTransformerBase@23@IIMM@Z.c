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
