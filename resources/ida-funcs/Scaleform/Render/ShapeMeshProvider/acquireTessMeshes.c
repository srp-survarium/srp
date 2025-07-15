bool __thiscall Scaleform::Render::ShapeMeshProvider::acquireTessMeshes(
        Scaleform::Render::ShapeMeshProvider *this,
        Scaleform::Render::TessBase *tess,
        const Scaleform::Render::Matrix2x4<float> *mtx,
        Scaleform::Render::VertexOutput *pout,
        unsigned int drawLayerIdx,
        unsigned int strokeStyleIdx,
        unsigned int meshGenFlags,
        float morphRatio)
{
  Scaleform::Render::TessBase_vtbl *v9; // edx
  unsigned int (__thiscall *GetMeshCount)(Scaleform::Render::TessBase *); // eax
  unsigned int v11; // eax
  unsigned int v12; // edi
  unsigned int v13; // eax
  unsigned int v14; // ecx
  unsigned int v15; // edx
  unsigned int v16; // edi
  unsigned int v17; // ebx
  unsigned int (__thiscall *GetMeshTriangleCount)(Scaleform::Render::TessBase *, unsigned int); // edx
  int v19; // eax
  bool v20; // bl
  unsigned int *Data; // eax
  bool v22; // zf
  Scaleform::Log *GlobalLog; // eax
  bool NullMesh; // al
  Scaleform::Render::VertexOutput *v25; // esi
  void (__thiscall *GetMesh)(Scaleform::Render::TessBase *, unsigned int, Scaleform::Render::TessMesh *); // edx
  unsigned int (__thiscall *GetVertices)(Scaleform::Render::TessBase *, Scaleform::Render::TessMesh *, Scaleform::Render::TessVertex *, unsigned int); // eax
  unsigned int v29; // ebx
  char *v30; // edi
  float *v31; // esi
  double v32; // st7
  double v33; // st7
  int v34; // eax
  bool v35; // c0
  bool v36; // c3
  double v37; // st7
  double v38; // st7
  unsigned int v39; // eax
  unsigned int v40; // eax
  unsigned int v41; // eax
  unsigned int Color; // ecx
  unsigned int v43; // eax
  unsigned __int8 v44; // dl
  unsigned int v45; // esi
  unsigned int (__thiscall *v46)(Scaleform::Render::TessBase *, Scaleform::Render::TessMesh *, Scaleform::Render::TessVertex *, unsigned int); // edx
  unsigned int v47; // esi
  unsigned int v48; // ebx
  unsigned int v49; // edi
  unsigned int j; // [esp+88h] [ebp-28DCh]
  unsigned int v51; // [esp+88h] [ebp-28DCh]
  unsigned int i; // [esp+8Ch] [ebp-28D8h] BYREF
  Scaleform::Render::ShapeMeshProvider *v53; // [esp+90h] [ebp-28D4h]
  unsigned int v54; // [esp+94h] [ebp-28D0h]
  unsigned int v55; // [esp+98h] [ebp-28CCh]
  unsigned int v56; // [esp+9Ch] [ebp-28C8h]
  unsigned int v57; // [esp+A0h] [ebp-28C4h]
  float v58; // [esp+A4h] [ebp-28C0h]
  Scaleform::Render::FillStyleType f1; // [esp+A8h] [ebp-28BCh] BYREF
  int v60; // [esp+B0h] [ebp-28B4h]
  Scaleform::Render::Matrix2x4<float> v61; // [esp+B4h] [ebp-28B0h] BYREF
  Scaleform::Render::StrokeStyleType s1; // [esp+E0h] [ebp-2884h] BYREF
  Scaleform::Render::FillStyleType v63; // [esp+FCh] [ebp-2868h] BYREF
  Scaleform::ArrayStaticBuffPOD<unsigned long,16,2> v64; // [esp+104h] [ebp-2860h] BYREF
  char v65; // [esp+158h] [ebp-280Ch] BYREF
  int v66; // [esp+15Ch] [ebp-2808h]
  int v67; // [esp+160h] [ebp-2804h]
  int v68; // [esp+164h] [ebp-2800h]
  int v69; // [esp+170h] [ebp-27F4h]
  Scaleform::ArrayStaticBuffPOD<Scaleform::Render::VertexOutput::Fill,16,2> v70; // [esp+174h] [ebp-27F0h] BYREF
  _BYTE v71[32]; // [esp+344h] [ebp-2620h] BYREF
  char v72[1536]; // [esp+364h] [ebp-2600h] BYREF
  char v73[4]; // [esp+964h] [ebp-2000h] BYREF
  char v74; // [esp+968h] [ebp-1FFCh] BYREF
  _BYTE v75[12]; // [esp+1564h] [ebp-1400h] BYREF
  char v76; // [esp+1570h] [ebp-13F4h] BYREF

  v70.pHeap = Scaleform::Memory::pGlobalHeap;
  v64.pHeap = Scaleform::Memory::pGlobalHeap;
  v70.Data = v70.Static;
  v9 = tess->__vftable;
  v70.Reserved = 16;
  v64.Reserved = 16;
  v64.Data = v64.Static;
  GetMeshCount = v9->GetMeshCount;
  v53 = this;
  s1.pFill.pObject = 0;
  s1.pDashes.pObject = 0;
  v70.Size = 0;
  v64.Size = 0;
  if ( !GetMeshCount(tess) || !tess->GetVertexCount(tess) )
  {
    NullMesh = Scaleform::Render::ShapeMeshProvider::createNullMesh(this, pout, drawLayerIdx, meshGenFlags);
LABEL_86:
    v20 = NullMesh;
    Data = v64.Data;
    v22 = v64.Data == v64.Static;
    goto LABEL_87;
  }
  if ( strokeStyleIdx )
  {
    Scaleform::Render::ShapeMeshProvider::GetStrokeStyle(this, strokeStyleIdx, &s1, morphRatio);
  }
  else
  {
    v11 = this->pShapeData.pObject->GetFillStyleCount(this->pShapeData.pObject) + 1;
    if ( v11 )
    {
      i = 0;
      v12 = v11;
      do
      {
        Scaleform::ArrayStaticBuffPOD<unsigned int,16,2>::PushBack(&v64, &i);
        --v12;
      }
      while ( v12 );
    }
    v13 = this->GetFillCount(&this->Scaleform::Render::MeshProvider, drawLayerIdx, meshGenFlags);
    v14 = 0;
    if ( v13 )
    {
      v15 = 20 * drawLayerIdx;
      for ( i = 20 * drawLayerIdx; ; v15 = i )
      {
        v64.Data[this->FillToStyleTable.Data.Data[v14
                                                + *(unsigned int *)((char *)&this->DrawLayers.Data.Data->StartFill + v15)]] = v14;
        if ( ++v14 >= v13 )
          break;
      }
    }
  }
  v61.M[0][0] = 1.0;
  v61.M[0][1] = 0.0;
  v61.M[0][2] = 0.0;
  v61.M[0][3] = 0.0;
  v61.M[1][0] = 0.0;
  v61.M[1][2] = 0.0;
  v61.M[1][3] = 0.0;
  v61.M[1][1] = 1.0;
  Scaleform::Render::Matrix2x4<float>::SetInverse(&v61, mtx);
  tess->Transform(tess, &v61);
  ((void (__thiscall *)(Scaleform::Render::TessBase *, _BYTE *, _DWORD, _DWORD, _DWORD, _DWORD))tess->StretchTo)(
    tess,
    v71,
    -32764.0,
    -32764.0,
    32764.0,
    32764.0);
  v16 = 0;
  for ( j = 0; v16 < tess->GetMeshCount(tess); ++v16 )
  {
    tess->GetMesh(tess, v16, (Scaleform::Render::TessMesh *)&v65);
    v17 = tess->GetMeshVertexCount(tess, v16);
    GetMeshTriangleCount = tess->GetMeshTriangleCount;
    LODWORD(v61.M[0][0]) = v17;
    v19 = 3 * GetMeshTriangleCount(tess, v16);
    LODWORD(v61.M[0][1]) = v19;
    if ( v17 && v19 )
    {
      LODWORD(v61.M[0][2]) = &Scaleform::Render::VertexXY16iCF32::Format;
      v61.M[0][3] = 0.0;
      v61.M[1][0] = 0.0;
      if ( !strokeStyleIdx )
      {
        LODWORD(v61.M[0][3]) = v64.Data[v66];
        LODWORD(v61.M[1][0]) = v64.Data[v67];
      }
      LODWORD(v61.M[1][1]) = 1;
      if ( (v68 & 0x8000) != 0 )
        LODWORD(v61.M[1][1]) = 3;
      LODWORD(v61.M[1][2]) = v16;
      Scaleform::ArrayStaticBuffPOD<Scaleform::Render::VertexOutput::Fill,16,2>::PushBack(
        &v70,
        (const Scaleform::Render::VertexOutput::Fill *)&v61);
      j += v69;
    }
  }
  if ( !v70.Size )
  {
    v20 = Scaleform::Render::ShapeMeshProvider::createNullMesh(v53, pout, drawLayerIdx, meshGenFlags);
    Data = v64.Data;
    v22 = v64.Data == v64.Static;
LABEL_87:
    if ( !v22 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, Data);
    v64.Data = v64.Static;
    v64.Size = 0;
    if ( v70.Data != v70.Static )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v70.Data);
    v70.Data = v70.Static;
    v70.Size = 0;
    if ( s1.pDashes.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)s1.pDashes.pObject);
    if ( s1.pFill.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)s1.pFill.pObject);
    return v20;
  }
  if ( j > 0xFFFF )
  {
    GlobalLog = Scaleform::Log::GetGlobalLog();
    if ( GlobalLog || (GlobalLog = Scaleform::Log::GetDefaultLog()) != 0 )
      Scaleform::Log::LogWarning(
        GlobalLog,
        "Render_ShapeMeshProvider: More than 65535 vertices, the shape cannot be displayed");
    NullMesh = Scaleform::Render::ShapeMeshProvider::createNullMesh(v53, pout, drawLayerIdx, meshGenFlags);
    goto LABEL_86;
  }
  v25 = pout;
  if ( pout->BeginOutput(pout, v70.Data, v70.Size, (const Scaleform::Render::Matrix2x4<float> *)v71) )
  {
    v54 = 0;
    v60 = 0;
    f1.pFill.pObject = 0;
    v63.pFill.pObject = 0;
    v51 = 0;
    if ( v70.Size )
    {
      v56 = 0;
      do
      {
        GetMesh = tess->GetMesh;
        i = (unsigned int)&v70.Data[v56 / 0x1C].MeshIndex;
        GetMesh(tess, *(_DWORD *)i, (Scaleform::Render::TessMesh *)&v65);
        GetVertices = tess->GetVertices;
        v57 = 0;
        v55 = GetVertices(tess, (Scaleform::Render::TessMesh *)&v65, (Scaleform::Render::TessVertex *)v75, 256u);
        if ( v55 )
        {
          v29 = v54;
          do
          {
            v30 = &v74;
            v31 = (float *)&v76;
            v54 = v55;
            do
            {
              v32 = *(v31 - 3);
              if ( v32 >= 0.0 )
                v33 = v32 + 0.5;
              else
                v33 = v32 - 0.5;
              v58 = v33;
              v34 = (int)floor(v58);
              v35 = *(v31 - 2) > 0.0;
              v36 = 0.0 == *(v31 - 2);
              *((_WORD *)v30 - 2) = v34;
              v37 = *(v31 - 2);
              if ( v35 || v36 )
                v38 = v37 + 0.5;
              else
                v38 = v37 - 0.5;
              v58 = v38;
              *((_WORD *)v30 - 1) = (int)floor(v58);
              if ( strokeStyleIdx )
              {
                *(_DWORD *)v30 = s1.Color;
              }
              else
              {
                v39 = *((unsigned __int16 *)v31 + 2);
                *(_DWORD *)v30 = 0;
                if ( (v39 & 0x8000) == 0 )
                {
                  if ( (v39 & 0x10) != 0 )
                  {
                    v40 = *(unsigned __int16 *)v31;
                    if ( v29 != v40 )
                    {
                      Scaleform::Render::ShapeMeshProvider::GetFillStyle(v53, v40, &f1, morphRatio);
                      v29 = *(unsigned __int16 *)v31;
                    }
                    v41 = *((unsigned __int16 *)v31 + 1);
                    if ( v60 != v41 )
                    {
                      Scaleform::Render::ShapeMeshProvider::GetFillStyle(v53, v41, &v63, morphRatio);
                      v60 = *((unsigned __int16 *)v31 + 1);
                    }
                    Color = ((f1.Color | v63.Color) >> 1) & 0x7F7F7F7F;
                  }
                  else
                  {
                    v43 = *((unsigned __int16 *)v31 + ((v39 >> 5) & 1));
                    if ( v29 != v43 )
                    {
                      Scaleform::Render::ShapeMeshProvider::GetFillStyle(v53, v43, &f1, morphRatio);
                      v29 = *((unsigned __int16 *)v31 + ((*((unsigned __int16 *)v31 + 2) >> 5) & 1));
                    }
                    Color = f1.Color;
                  }
                  *(_DWORD *)v30 = Color;
                }
              }
              v44 = Scaleform::Render::Factors[(*((unsigned __int16 *)v31 + 2) >> 2) & 3];
              v30[4] = Scaleform::Render::Factors[(_WORD)v31[1] & 3];
              v30[5] = v44;
              v31 += 5;
              v30 += 12;
              --v54;
            }
            while ( v54 );
            v45 = v55;
            pout->SetVertices(pout, v51, v57, v73, v55);
            v46 = tess->GetVertices;
            v57 += v45;
            v55 = v46(tess, (Scaleform::Render::TessMesh *)&v65, (Scaleform::Render::TessVertex *)v75, 256u);
          }
          while ( v55 );
          v54 = v29;
        }
        v47 = 0;
        v48 = tess->GetMeshTriangleCount(tess, *(_DWORD *)i);
        if ( v48 )
        {
          do
          {
            v49 = 256;
            if ( v47 + 256 > v48 )
            {
              v49 = v48 - v47;
              if ( v48 == v47 )
                break;
            }
            tess->GetTrianglesI16(tess, *(_DWORD *)i, (unsigned __int16 *)v72, v47, v49);
            pout->SetIndices(pout, v51, 3 * v47, (unsigned __int16 *)v72, 3 * v49);
            v47 += v49;
          }
          while ( v47 < v48 );
        }
        v56 += 28;
        ++v51;
      }
      while ( v51 < v70.Size );
      v25 = pout;
    }
    v25->EndOutput(v25);
    if ( v63.pFill.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v63.pFill.pObject);
    if ( f1.pFill.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)f1.pFill.pObject);
    if ( v64.Data != v64.Static )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v64.Data);
    v64.Data = v64.Static;
    v64.Size = 0;
    if ( v70.Data != v70.Static )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v70.Data);
    v70.Data = v70.Static;
    v70.Size = 0;
    if ( s1.pDashes.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)s1.pDashes.pObject);
    if ( s1.pFill.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)s1.pFill.pObject);
    return 1;
  }
  else
  {
    if ( v64.Data != v64.Static )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v64.Data);
    v64.Data = v64.Static;
    v64.Size = 0;
    if ( v70.Data != v70.Static )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v70.Data);
    v70.Data = v70.Static;
    v70.Size = 0;
    if ( s1.pDashes.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)s1.pDashes.pObject);
    if ( s1.pFill.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)s1.pFill.pObject);
    return 0;
  }
}
