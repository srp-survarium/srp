char __thiscall Scaleform::Render::TextMeshProvider::generateUnderlines(
        Scaleform::Render::TextMeshProvider *this,
        Scaleform::Render::Renderer2DImpl *ren,
        Scaleform::Render::VertexOutput *verOut,
        const Scaleform::Render::TextMeshLayer *layer,
        const Scaleform::Render::Matrix2x4<float> *mtx,
        char meshGenFlags)
{
  double v6; // st7
  Scaleform::Render::StrokerAA *p_mStrokerAA; // edi
  double v8; // st5
  double v9; // st6
  double v10; // st4
  const Scaleform::Render::Matrix2x4<float> *v11; // ebx
  int VStart; // ecx
  double v13; // st3
  double v14; // st2
  Scaleform::Render::TextMeshEntry *v15; // esi
  Scaleform::Render::Font *pFont; // eax
  double v17; // st4
  double v18; // st6
  double v19; // rt0
  double v20; // st5
  double v21; // st6
  Scaleform::Render::StrokerAA_vtbl *v22; // ebx
  Scaleform::Render::StrokerAA_vtbl *v23; // ebx
  Scaleform::Render::Font *v24; // eax
  double v25; // st7
  Scaleform::Render::Font *v26; // esi
  double v27; // st7
  double v28; // st7
  int v29; // eax
  bool (__thiscall *BeginOutput)(Scaleform::Render::VertexOutput *, const Scaleform::Render::VertexOutput::Fill *, unsigned int, const Scaleform::Render::Matrix2x4<float> *); // edx
  float X; // [esp+992h] [ebp-108h]
  float Xa; // [esp+992h] [ebp-108h]
  float v34; // [esp+9AAh] [ebp-F0h]
  float v35; // [esp+9AAh] [ebp-F0h]
  float v36; // [esp+9AAh] [ebp-F0h]
  float v37; // [esp+9AAh] [ebp-F0h]
  float v38; // [esp+9AAh] [ebp-F0h]
  float v39; // [esp+9AAh] [ebp-F0h]
  float v40; // [esp+9AAh] [ebp-F0h]
  float v41; // [esp+9AAh] [ebp-F0h]
  float v42; // [esp+9AAh] [ebp-F0h]
  float v43; // [esp+9AAh] [ebp-F0h]
  float v44; // [esp+9AAh] [ebp-F0h]
  float v45; // [esp+9AAh] [ebp-F0h]
  float v46; // [esp+9AAh] [ebp-F0h]
  float v47; // [esp+9AAh] [ebp-F0h]
  float v48; // [esp+9AEh] [ebp-ECh]
  float v49; // [esp+9AEh] [ebp-ECh]
  float v50; // [esp+9AEh] [ebp-ECh]
  float v51; // [esp+9AEh] [ebp-ECh]
  float v52; // [esp+9AEh] [ebp-ECh]
  float v53; // [esp+9AEh] [ebp-ECh]
  float v54; // [esp+9AEh] [ebp-ECh]
  char v55; // [esp+9B5h] [ebp-E5h]
  float v56; // [esp+9B6h] [ebp-E4h]
  float v57; // [esp+9B6h] [ebp-E4h]
  float v58; // [esp+9B6h] [ebp-E4h]
  float v59; // [esp+9B6h] [ebp-E4h]
  float v60; // [esp+9B6h] [ebp-E4h]
  float v61; // [esp+9B6h] [ebp-E4h]
  float v62; // [esp+9B6h] [ebp-E4h]
  float v63; // [esp+9B6h] [ebp-E4h]
  float v64; // [esp+9BAh] [ebp-E0h]
  float v65; // [esp+9BAh] [ebp-E0h]
  float v66; // [esp+9BEh] [ebp-DCh]
  float v67; // [esp+9BEh] [ebp-DCh]
  float v68; // [esp+9BEh] [ebp-DCh]
  float v69; // [esp+9C2h] [ebp-D8h]
  float v70; // [esp+9C2h] [ebp-D8h]
  float v71; // [esp+9C6h] [ebp-D4h]
  float v72; // [esp+9C6h] [ebp-D4h]
  float v73; // [esp+9C6h] [ebp-D4h]
  float v74; // [esp+9CAh] [ebp-D0h]
  float v75; // [esp+9CAh] [ebp-D0h]
  double v76; // [esp+9CAh] [ebp-D0h]
  Scaleform::Render::TextMeshProvider::VertexCountType v78; // [esp+9DAh] [ebp-C0h] BYREF
  double v79; // [esp+9E2h] [ebp-B8h]
  Scaleform::Render::Matrix2x4<float> v80; // [esp+9EAh] [ebp-B0h] BYREF
  _DWORD v81[7]; // [esp+A0Eh] [ebp-8Ch] BYREF
  Scaleform::ArrayStaticBuffPOD<unsigned long,16,2> v82; // [esp+A2Ah] [ebp-70h] BYREF
  Scaleform::Render::Matrix2x4<float> v83; // [esp+A7Ah] [ebp-20h] BYREF

  v82.Data = v82.Static;
  v82.pHeap = Scaleform::Memory::pGlobalHeap;
  v82.Size = 0;
  v82.Reserved = 16;
  Scaleform::Render::MeshGenerator::Clear(&ren->MeshGen);
  if ( (meshGenFlags & 1) == 0 || (v55 = 1, (meshGenFlags & 2) != 0) )
    v55 = 0;
  v6 = 0.5;
  p_mStrokerAA = &ren->MeshGen.mStrokerAA;
  ren->MeshGen.mStrokerAA.EndLineCap = ButtCap;
  ren->MeshGen.mStrokerAA.StartLineCap = ButtCap;
  ren->MeshGen.mStrokerAA.LineJoin = MiterJoin;
  if ( v55 )
  {
    v48 = 0.5 * 0.0;
    ren->MeshGen.mStrokerAA.WidthRight = v48;
    ren->MeshGen.mStrokerAA.WidthLeft = v48;
    v8 = 0.95999998;
    v9 = 0.0;
    ren->MeshGen.mStrokerAA.AaWidthRight = 0.95999998;
    ren->MeshGen.mStrokerAA.AaWidthLeft = 0.95999998;
  }
  else
  {
    ren->MeshGen.mStrokerAA.WidthRight = 0.5;
    ren->MeshGen.mStrokerAA.WidthLeft = 0.5;
    v49 = 0.0 + 0.0;
    ren->MeshGen.mStrokerAA.AaWidthRight = v49;
    ren->MeshGen.mStrokerAA.AaWidthLeft = v49;
    v9 = 0.0;
    v8 = 0.95999998;
  }
  v10 = 1.0;
  v11 = mtx;
  VStart = 0;
  if ( layer->Count )
  {
    v13 = 0.25;
    v14 = 0.75;
    while ( 1 )
    {
      v15 = &this->Entries.Data.Data[VStart + layer->Start];
      pFont = v15->EntryData.VectorData.pFont;
      if ( v55 )
      {
        if ( pFont == (Scaleform::Render::Font *)1 || pFont == (Scaleform::Render::Font *)3 )
        {
          v18 = v13;
        }
        else
        {
          v17 = v9;
          v18 = v13;
          v50 = v17 * 0.5;
          v10 = v50;
        }
        ren->MeshGen.mStrokerAA.WidthRight = v10;
        ren->MeshGen.mStrokerAA.WidthLeft = v10;
        if ( v15->EntryData.UnderlineData.Style == 5 )
        {
          v19 = v8;
          v20 = v18;
          v21 = v19;
          ren->MeshGen.mStrokerAA.WidthRight = v20;
          ren->MeshGen.mStrokerAA.WidthLeft = v20;
        }
        else
        {
          v21 = v8;
        }
        if ( v15->EntryData.UnderlineData.Style != 4 )
          v6 = v21;
      }
      else
      {
        if ( pFont == (Scaleform::Render::Font *)1 || pFont == (Scaleform::Render::Font *)3 )
          v6 = v10;
        ren->MeshGen.mStrokerAA.WidthRight = v6;
        ren->MeshGen.mStrokerAA.WidthLeft = v6;
        if ( v15->EntryData.UnderlineData.Style == 5 )
        {
          ren->MeshGen.mStrokerAA.WidthRight = v14;
          ren->MeshGen.mStrokerAA.WidthLeft = v14;
        }
        v51 = v9 + v9;
        v6 = v51;
      }
      ren->MeshGen.mStrokerAA.AaWidthRight = v6;
      ren->MeshGen.mStrokerAA.AaWidthLeft = v6;
      ren->MeshGen.mStrokerAA.StyleLeft = VStart + 1;
      ren->MeshGen.mStrokerAA.StyleRight = VStart + 1;
      v78.VStart = VStart + 1;
      Scaleform::ArrayStaticBuffPOD<unsigned int,16,2>::PushBack(&v82, &v15->mColor);
      v66 = v15->EntryData.RasterData.Coord[2];
      v34 = v15->EntryData.RasterData.Coord[1];
      v74 = v11->M[0][0] * v34 + v11->M[0][1] * v66 + v11->M[0][3];
      v69 = v66 * v11->M[1][1] + v34 * v11->M[1][0] + v11->M[1][3];
      v35 = v15->EntryData.RasterData.Coord[3] + v34;
      v52 = v11->M[0][1] * v66 + v11->M[0][0] * v35 + v11->M[0][3];
      v67 = v66 * v11->M[1][1] + v35 * v11->M[1][0] + v11->M[1][3];
      if ( v15->EntryData.UnderlineData.Style <= 1 )
      {
        v22 = p_mStrokerAA->__vftable;
        v36 = floor(v69);
        v37 = v36 + 0.5;
        ((void (__thiscall *)(Scaleform::Render::StrokerAA *, float, _DWORD))v22->AddVertex)(
          p_mStrokerAA,
          COERCE_FLOAT(LODWORD(v74)),
          LODWORD(v37));
        v23 = p_mStrokerAA->__vftable;
        v38 = floor(v67);
        v39 = v38 + 0.5;
        ((void (__thiscall *)(Scaleform::Render::StrokerAA *, float, _DWORD))v23->AddVertex)(
          p_mStrokerAA,
          COERCE_FLOAT(LODWORD(v52)),
          LODWORD(v39));
        p_mStrokerAA->FinalizePath(p_mStrokerAA, 0, 0, 0, 0);
        v11 = mtx;
      }
      v24 = v15->EntryData.VectorData.pFont;
      if ( v24 == (Scaleform::Render::Font *)2 || v24 == (Scaleform::Render::Font *)3 )
      {
        v40 = floor(v74);
        v74 = v40 - 0.5;
        v41 = floor(v52);
        v52 = v41 + 0.5;
        v42 = floor(v69);
        v69 = v42 + 0.5;
        v43 = floor(v67);
        v67 = v43 + 0.5;
        v64 = v74;
        v79 = v52;
        if ( v52 >= (double)v74 )
        {
          v44 = floor(v69);
          v71 = v44 + 0.5;
          v45 = floor(v67);
          v46 = v45 + 0.5;
          v25 = v74;
          do
          {
            X = v25;
            ((void (__thiscall *)(Scaleform::Render::StrokerAA *, _DWORD, float))p_mStrokerAA->AddVertex)(
              p_mStrokerAA,
              LODWORD(X),
              COERCE_FLOAT(LODWORD(v71)));
            v56 = v64 + 2.0;
            ((void (__thiscall *)(Scaleform::Render::StrokerAA *, _DWORD, float))p_mStrokerAA->AddVertex)(
              p_mStrokerAA,
              LODWORD(v56),
              COERCE_FLOAT(LODWORD(v46)));
            p_mStrokerAA->FinalizePath(p_mStrokerAA, 0, 0, 0, 0);
            v64 = v64 + 5.0;
            v25 = v64;
          }
          while ( v64 <= v79 );
        }
      }
      v26 = v15->EntryData.VectorData.pFont;
      if ( v26 == (Scaleform::Render::Font *)4 || v26 == (Scaleform::Render::Font *)5 )
      {
        v57 = floor(v74);
        v75 = v57;
        v58 = floor(v52);
        v53 = v58 + 1.0;
        v59 = floor(v69);
        v70 = v59 + 0.5;
        v60 = floor(v67);
        v68 = v60 + 0.5;
        v47 = 4.0;
        v72 = 0.75;
        if ( v26 == (Scaleform::Render::Font *)5 )
        {
          v47 = 6.0;
          v72 = 1.25;
        }
        v27 = v75;
        v65 = v75;
        v76 = v53;
        if ( v53 >= v27 )
        {
          v61 = floor(v70);
          v54 = v61 + v72;
          v62 = floor(v68);
          v63 = v62 - v72;
          v79 = v47 * 0.5;
          v28 = v65;
          do
          {
            Xa = v28;
            ((void (__thiscall *)(Scaleform::Render::StrokerAA *, _DWORD, float))p_mStrokerAA->AddVertex)(
              p_mStrokerAA,
              LODWORD(Xa),
              COERCE_FLOAT(LODWORD(v54)));
            v73 = v65 + v79;
            ((void (__thiscall *)(Scaleform::Render::StrokerAA *, _DWORD, float))p_mStrokerAA->AddVertex)(
              p_mStrokerAA,
              LODWORD(v73),
              COERCE_FLOAT(LODWORD(v63)));
            v65 = v47 + v65;
            v28 = v65;
          }
          while ( v65 <= v76 );
        }
        p_mStrokerAA->FinalizePath(p_mStrokerAA, 0, 0, 0, 0);
      }
      VStart = v78.VStart;
      if ( v78.VStart >= layer->Count )
        break;
      v6 = 0.5;
      v9 = 0.0;
      v13 = 0.25;
      v8 = 0.95999998;
      v14 = 0.75;
      v10 = 1.0;
    }
  }
  if ( p_mStrokerAA->GetVertexCount(p_mStrokerAA) )
  {
    v80.M[0][0] = 1.0;
    v80.M[0][1] = 0.0;
    v80.M[0][2] = 0.0;
    v80.M[0][3] = 0.0;
    v80.M[1][0] = 0.0;
    v80.M[1][2] = 0.0;
    v80.M[1][3] = 0.0;
    v80.M[1][1] = 1.0;
    Scaleform::Render::Matrix2x4<float>::SetInverse(&v80, v11);
    p_mStrokerAA->Transform(p_mStrokerAA, &v80);
    ((void (__thiscall *)(Scaleform::Render::StrokerAA *, Scaleform::Render::Matrix2x4<float> *, _DWORD, _DWORD, _DWORD, _DWORD))p_mStrokerAA->StretchTo)(
      p_mStrokerAA,
      &v83,
      -32764.0,
      -32764.0,
      32764.0,
      32764.0);
    v81[0] = p_mStrokerAA->GetMeshVertexCount(p_mStrokerAA, 0);
    v29 = p_mStrokerAA->GetMeshTriangleCount(p_mStrokerAA, 0);
    BeginOutput = verOut->BeginOutput;
    v81[1] = 3 * v29;
    v81[2] = &Scaleform::Render::VertexXY16iCF32::Format;
    memset(&v81[3], 0, 16);
    if ( BeginOutput(verOut, (const Scaleform::Render::VertexOutput::Fill *)v81, 1u, &v83) )
    {
      v78.VStart = 0;
      v78.IStart = 0;
      Scaleform::Render::TextMeshProvider::setMeshData(this, p_mStrokerAA, verOut, v82.Data, &v78);
      verOut->EndOutput(verOut);
    }
  }
  else
  {
    Scaleform::Render::TextMeshProvider::generateNullVectorMesh(this, verOut);
  }
  ren->MeshGen.mStrokerAA.StyleLeft = 1;
  ren->MeshGen.mStrokerAA.StyleRight = 1;
  Scaleform::Render::MeshGenerator::Clear(&ren->MeshGen);
  if ( v82.Data != v82.Static )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v82.Data);
  return 1;
}
