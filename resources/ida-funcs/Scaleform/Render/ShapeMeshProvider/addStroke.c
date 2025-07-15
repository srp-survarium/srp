void __userpurge Scaleform::Render::ShapeMeshProvider::addStroke(
        Scaleform::Render::ShapeMeshProvider *this@<ecx>,
        int a2@<ebp>,
        Scaleform::Render::TessBase *a3@<edi>,
        int a4@<esi>,
        Scaleform::Render::MeshGenerator *gen,
        const Scaleform::Render::ToleranceParams *param,
        Scaleform::Render::TransformerBase *tr,
        unsigned int startPos,
        unsigned int strokeStyleIdx,
        float snapOffset,
        float morphRatio)
{
  unsigned int v11; // ebx
  int v12; // ebp
  int v13; // edx
  unsigned int v14; // esi
  int v15; // eax
  int v16; // ecx
  _DWORD *v17; // eax
  unsigned int v18; // ecx
  unsigned int v19; // ebx
  Scaleform::Render::StrokeSorter::VertexType *v20; // ebx
  int v21; // eax
  int v22; // ecx
  _DWORD *v23; // eax
  unsigned int v24; // ecx
  unsigned int v25; // edx
  Scaleform::Render::StrokeSorter::VertexType *v26; // eax
  _DWORD *v27; // ecx
  unsigned int v28; // esi
  unsigned int v29; // edx
  unsigned int v30; // ebp
  Scaleform::Render::StrokeSorter::VertexType *v31; // ecx
  int v32; // eax
  int v33; // ecx
  _DWORD *v34; // eax
  unsigned int v35; // ecx
  unsigned int v36; // edx
  Scaleform::Render::StrokeSorter::VertexType *v37; // eax
  int snapOffseta; // [esp+18h] [ebp-10h]
  int morphRatioa; // [esp+1Ch] [ebp-Ch]
  Scaleform::Render::TessBase *v40; // [esp+20h] [ebp-8h]
  unsigned int startPosa; // [esp+38h] [ebp+10h]
  unsigned int strokeStyleIdxa; // [esp+3Ch] [ebp+14h]
  unsigned int v43; // [esp+40h] [ebp+18h]
  int v44; // [esp+44h] [ebp+1Ch]

  v40 = a3;
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
  v11 = 0;
  v43 = 0;
  if ( !gen->mStrokeSorter.OutPaths.Size )
    return;
  morphRatioa = a2;
  snapOffseta = a4;
  do
  {
    v12 = 4 * (v11 >> 4);
    v13 = 8 * (v11 & 0xF);
    strokeStyleIdxa = v12;
    v44 = v13;
    startPosa = *(unsigned int *)((_BYTE *)&(*(Scaleform::Render::StrokeSorter::PathType **)((char *)gen->mStrokeSorter.OutPaths.Pages
                                                                                           + v12))->numVer
                                + v13)
              & 0xFFFFFFF;
    v14 = 0;
    if ( !startPosa )
      goto LABEL_21;
    do
    {
      v15 = *(int *)((char *)gen->mStrokeSorter.OutPaths.Pages + v12);
      v16 = *(_DWORD *)(v15 + v13 + 4);
      v17 = (_DWORD *)(v13 + v15);
      v18 = v16 & 0xFFFFFFF;
      v19 = v14;
      if ( v14 >= v18 )
        v19 = v14 - v18;
      ++v14;
      v20 = &gen->mStrokeSorter.OutVertices.Pages[(v19 + *v17) >> 4][(v19 + *v17) & 0xF];
      switch ( v20->segType )
      {
        case 1u:
          ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))gen->mStroker.AddVertex)(&gen->mStroker, v20->x, v20->y);
          break;
        case 2u:
          v32 = *(int *)((char *)gen->mStrokeSorter.OutPaths.Pages + v12);
          v33 = *(_DWORD *)(v32 + v13 + 4);
          v34 = (_DWORD *)(v13 + v32);
          v35 = v33 & 0xFFFFFFF;
          v36 = v14;
          if ( v14 >= v35 )
            v36 = v14 - v35;
          v37 = &gen->mStrokeSorter.OutVertices.Pages[(v36 + *v34) >> 4][(v36 + *v34) & 0xF];
          ++v14;
          Scaleform::Render::TessellateQuadCurve(&gen->mStroker, param, v20->x, v20->y, v37->x, v37->y);
          break;
        case 3u:
          v21 = *(int *)((char *)gen->mStrokeSorter.OutPaths.Pages + v12);
          v22 = *(_DWORD *)(v21 + v13 + 4);
          v23 = (_DWORD *)(v13 + v21);
          v24 = v22 & 0xFFFFFFF;
          v25 = v14;
          if ( v14 >= v24 )
            v25 = v14 - v24;
          v26 = &gen->mStrokeSorter.OutVertices.Pages[(v25 + *v23) >> 4][(v25 + *v23) & 0xF];
          v27 = (unsigned int *)((char *)&(*(Scaleform::Render::StrokeSorter::PathType **)((char *)gen->mStrokeSorter.OutPaths.Pages
                                                                                         + v12))->start
                               + v44);
          v28 = v14 + 1;
          v29 = v27[1] & 0xFFFFFFF;
          v30 = v28;
          if ( v28 >= v29 )
            v30 = v28 - v29;
          v31 = &gen->mStrokeSorter.OutVertices.Pages[(v30 + *v27) >> 4][(v30 + *v27) & 0xF];
          v14 = v28 + 1;
          Scaleform::Render::TessellateCubicCurve(&gen->mStroker, param, v20->x, v20->y, v26->x, v26->y, v31->x, v31->y);
          v12 = strokeStyleIdxa;
          break;
        default:
          continue;
      }
      v13 = v44;
    }
    while ( v14 < startPosa );
    v11 = v43;
LABEL_21:
    Scaleform::Render::Stroker::GenerateStroke(
      &gen->mStroker,
      v11++,
      v12,
      *(float *)&gen,
      &gen->mTess,
      snapOffseta,
      morphRatioa,
      v40);
    v43 = v11;
  }
  while ( v11 < gen->mStrokeSorter.OutPaths.Size );
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
  unsigned int startPosa; // [esp+3Ch] [ebp+14h]
  unsigned int strokeStyleIdxa; // [esp+40h] [ebp+18h]
  unsigned int v38; // [esp+44h] [ebp+1Ch]
  int v39; // [esp+48h] [ebp+20h]

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
  v38 = 0;
  if ( !gen->mStrokeSorter.OutPaths.Size )
    return;
  do
  {
    v10 = 4 * (v9 >> 4);
    v11 = 8 * (v9 & 0xF);
    strokeStyleIdxa = v10;
    v39 = v11;
    startPosa = *(unsigned int *)((_BYTE *)&(*(Scaleform::Render::StrokeSorter::PathType **)((char *)gen->mStrokeSorter.OutPaths.Pages
                                                                                           + v10))->numVer
                                + v11)
              & 0xFFFFFFF;
    v12 = 0;
    if ( !startPosa )
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
                               + v39);
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
      v11 = v39;
    }
    while ( v12 < startPosa );
    v9 = v38;
LABEL_20:
    stroker->FinalizePath(stroker, 0, 0, 0, 0);
    v38 = ++v9;
  }
  while ( v9 < gen->mStrokeSorter.OutPaths.Size );
}
