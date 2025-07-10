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
