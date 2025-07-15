void __thiscall Scaleform::GFx::AMP::ProfileFrame::Write(
        Scaleform::GFx::AMP::ProfileFrame *this,
        Scaleform::File *str,
        unsigned int version)
{
  int (__thiscall *Write)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int TimeStamp; // eax
  int TimeStamp_high; // ecx
  int (__thiscall *v7)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v8)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v9)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v10)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v11)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v12)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v13)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v14)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v15)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v16)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v17)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v18)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v19)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v20)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v21)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v22)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v23)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v24)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v25)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v26)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v27)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v28)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v29)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v30)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v31)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v32)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v33)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v34)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v35)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v36)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v37)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v38)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v39)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v40)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v41)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v42)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v43)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v44)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v45)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v46)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v47)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v48)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v49)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v50)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v51)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v52)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v53)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v54)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v55)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v56)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v57)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v58)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v59)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v60)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v61)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v62)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v63)(Scaleform::File *, const unsigned __int8 *, int); // edx
  unsigned int i; // ebp
  int (__thiscall *v65)(Scaleform::File *, const unsigned __int8 *, int); // edx
  unsigned int j; // ebp
  int (__thiscall *v67)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v68)(Scaleform::File *, const unsigned __int8 *, int); // edx
  unsigned int k; // ebp
  unsigned __int64 *Data; // eax
  int v71; // ecx
  int v72; // edx
  Scaleform::File_vtbl *v73; // eax
  Scaleform::StringLH *v74; // eax
  Scaleform::MemItem *v75; // ebp
  int (__thiscall *v76)(Scaleform::File *, const unsigned __int8 *, int); // edx
  unsigned int m; // ebp
  int (__thiscall *v78)(Scaleform::File *, const unsigned __int8 *, int); // edx
  int (__thiscall *v79)(Scaleform::File *, const unsigned __int8 *, int); // edx
  unsigned __int8 v80[4]; // [esp+118h] [ebp-110h] BYREF
  unsigned int RasterizedGlyphCount; // [esp+11Ch] [ebp-10Ch] BYREF
  unsigned int FontTextureCount; // [esp+120h] [ebp-108h] BYREF
  unsigned int NumFontCacheTextureUpdates; // [esp+124h] [ebp-104h] BYREF
  unsigned int AdvanceTime; // [esp+128h] [ebp-100h] BYREF
  unsigned int FontThrashing; // [esp+12Ch] [ebp-FCh] BYREF
  unsigned int ActionTime; // [esp+130h] [ebp-F8h] BYREF
  unsigned int FontFill; // [esp+134h] [ebp-F4h] BYREF
  unsigned int InputTime; // [esp+138h] [ebp-F0h] BYREF
  unsigned int FontFail; // [esp+13Ch] [ebp-ECh] BYREF
  unsigned int GcCollectTime; // [esp+140h] [ebp-E8h] BYREF
  unsigned int FontMisses; // [esp+144h] [ebp-E4h] BYREF
  unsigned int GcScanInUseTime; // [esp+148h] [ebp-E0h] BYREF
  unsigned int FontTotalArea; // [esp+14Ch] [ebp-DCh] BYREF
  unsigned int GcFinalizeTime; // [esp+150h] [ebp-D8h] BYREF
  unsigned int FontUsedArea; // [esp+154h] [ebp-D4h] BYREF
  unsigned int GetVariableTime; // [esp+158h] [ebp-D0h] BYREF
  unsigned int TotalMemory; // [esp+15Ch] [ebp-CCh] BYREF
  unsigned int InvokeTime; // [esp+160h] [ebp-C8h] BYREF
  unsigned int ImageMemory; // [esp+164h] [ebp-C4h] BYREF
  unsigned int PresentTime; // [esp+168h] [ebp-C0h] BYREF
  unsigned int ImageGraphicsMemory; // [esp+16Ch] [ebp-BCh] BYREF
  unsigned int GradientGenTime; // [esp+170h] [ebp-B8h] BYREF
  unsigned int MovieDataMemory; // [esp+174h] [ebp-B4h] BYREF
  unsigned int LineCount; // [esp+178h] [ebp-B0h] BYREF
  unsigned int MovieViewMemory; // [esp+17Ch] [ebp-ACh] BYREF
  unsigned int FilterCount; // [esp+180h] [ebp-A8h] BYREF
  unsigned int MeshCacheMemory; // [esp+184h] [ebp-A4h] BYREF
  unsigned int TriangleCount; // [esp+188h] [ebp-A0h] BYREF
  unsigned int MeshCacheGraphicsMemory; // [esp+18Ch] [ebp-9Ch] BYREF
  unsigned int StrokeCount; // [esp+190h] [ebp-98h] BYREF
  unsigned int MeshCacheUnusedMemory; // [esp+194h] [ebp-94h] BYREF
  unsigned int MeshThrashing; // [esp+198h] [ebp-90h] BYREF
  unsigned int MeshCacheGraphicsUnusedMemory; // [esp+19Ch] [ebp-8Ch] BYREF
  unsigned int ProfilingLevel; // [esp+1A0h] [ebp-88h] BYREF
  unsigned int FontCacheMemory; // [esp+1A4h] [ebp-84h] BYREF
  int v116; // [esp+1A8h] [ebp-80h] BYREF
  unsigned int VideoMemory; // [esp+1ACh] [ebp-7Ch] BYREF
  unsigned int GcMarkInCycleTime; // [esp+1B0h] [ebp-78h] BYREF
  unsigned int SoundMemory; // [esp+1B4h] [ebp-74h] BYREF
  unsigned int GcDelayedCleanupTime; // [esp+1B8h] [ebp-70h] BYREF
  unsigned int OtherMemory; // [esp+1BCh] [ebp-6Ch] BYREF
  unsigned int DisplayTime; // [esp+1C0h] [ebp-68h] BYREF
  unsigned int GcRootsNumber; // [esp+1C4h] [ebp-64h] BYREF
  unsigned int UserTime; // [esp+1C8h] [ebp-60h] BYREF
  unsigned int GcFreedRootsNumber; // [esp+1CCh] [ebp-5Ch] BYREF
  unsigned int MeshCount; // [esp+1D0h] [ebp-58h] BYREF
  unsigned int Size; // [esp+1D4h] [ebp-54h] BYREF
  unsigned int GradientFillCount; // [esp+1D8h] [ebp-50h] BYREF
  unsigned int v129; // [esp+1DCh] [ebp-4Ch] BYREF
  unsigned int TimelineTime; // [esp+1E0h] [ebp-48h] BYREF
  unsigned int v131; // [esp+1E4h] [ebp-44h] BYREF
  unsigned int GcFreeGarbageTime; // [esp+1E8h] [ebp-40h] BYREF
  unsigned int v133; // [esp+1ECh] [ebp-3Ch] BYREF
  unsigned int TesselationTime; // [esp+1F0h] [ebp-38h] BYREF
  int v135; // [esp+1F4h] [ebp-34h] BYREF
  unsigned int DrawPrimitiveCount; // [esp+1F8h] [ebp-30h] BYREF
  unsigned int v137; // [esp+1FCh] [ebp-2Ch] BYREF
  unsigned int MouseTime; // [esp+200h] [ebp-28h] BYREF
  int v139; // [esp+204h] [ebp-24h] BYREF
  unsigned int MaskCount; // [esp+208h] [ebp-20h] BYREF
  int v141; // [esp+20Ch] [ebp-1Ch] BYREF
  unsigned int SetVariableTime; // [esp+210h] [ebp-18h] BYREF
  unsigned int FramesPerSecond; // [esp+214h] [ebp-14h] BYREF
  _DWORD v144[2]; // [esp+218h] [ebp-10h] BYREF
  _DWORD v145[2]; // [esp+220h] [ebp-8h] BYREF

  Write = str->Write;
  TimeStamp = this->TimeStamp;
  TimeStamp_high = HIDWORD(this->TimeStamp);
  v144[0] = TimeStamp;
  v144[1] = TimeStamp_high;
  Write(str, (const unsigned __int8 *)v144, 8);
  v7 = str->Write;
  FramesPerSecond = this->FramesPerSecond;
  v7(str, (const unsigned __int8 *)&FramesPerSecond, 4);
  if ( version >= 0x21 )
  {
    v8 = str->Write;
    ProfilingLevel = this->ProfilingLevel;
    v8(str, (const unsigned __int8 *)&ProfilingLevel, 4);
    v9 = str->Write;
    v80[0] = this->DetailedMemReport;
    v9(str, v80, 1);
  }
  v10 = str->Write;
  AdvanceTime = this->AdvanceTime;
  v10(str, (const unsigned __int8 *)&AdvanceTime, 4);
  v11 = str->Write;
  TimelineTime = this->TimelineTime;
  v11(str, (const unsigned __int8 *)&TimelineTime, 4);
  v12 = str->Write;
  ActionTime = this->ActionTime;
  v12(str, (const unsigned __int8 *)&ActionTime, 4);
  if ( version < 0x15 )
  {
    v13 = str->Write;
    v116 = 0;
    v13(str, (const unsigned __int8 *)&v116, 4);
  }
  v14 = str->Write;
  InputTime = this->InputTime;
  v14(str, (const unsigned __int8 *)&InputTime, 4);
  v15 = str->Write;
  MouseTime = this->MouseTime;
  v15(str, (const unsigned __int8 *)&MouseTime, 4);
  if ( version >= 0x20 )
  {
    v16 = str->Write;
    GcCollectTime = this->GcCollectTime;
    v16(str, (const unsigned __int8 *)&GcCollectTime, 4);
    v17 = str->Write;
    GcMarkInCycleTime = this->GcMarkInCycleTime;
    v17(str, (const unsigned __int8 *)&GcMarkInCycleTime, 4);
    v18 = str->Write;
    GcScanInUseTime = this->GcScanInUseTime;
    v18(str, (const unsigned __int8 *)&GcScanInUseTime, 4);
    v19 = str->Write;
    GcFreeGarbageTime = this->GcFreeGarbageTime;
    v19(str, (const unsigned __int8 *)&GcFreeGarbageTime, 4);
    v20 = str->Write;
    GcFinalizeTime = this->GcFinalizeTime;
    v20(str, (const unsigned __int8 *)&GcFinalizeTime, 4);
    v21 = str->Write;
    GcDelayedCleanupTime = this->GcDelayedCleanupTime;
    v21(str, (const unsigned __int8 *)&GcDelayedCleanupTime, 4);
  }
  v22 = str->Write;
  GetVariableTime = this->GetVariableTime;
  v22(str, (const unsigned __int8 *)&GetVariableTime, 4);
  v23 = str->Write;
  SetVariableTime = this->SetVariableTime;
  v23(str, (const unsigned __int8 *)&SetVariableTime, 4);
  v24 = str->Write;
  InvokeTime = this->InvokeTime;
  v24(str, (const unsigned __int8 *)&InvokeTime, 4);
  v25 = str->Write;
  DisplayTime = this->DisplayTime;
  v25(str, (const unsigned __int8 *)&DisplayTime, 4);
  if ( version >= 0x1E )
  {
    v26 = str->Write;
    PresentTime = this->PresentTime;
    v26(str, (const unsigned __int8 *)&PresentTime, 4);
  }
  v27 = str->Write;
  TesselationTime = this->TesselationTime;
  v27(str, (const unsigned __int8 *)&TesselationTime, 4);
  v28 = str->Write;
  GradientGenTime = this->GradientGenTime;
  v28(str, (const unsigned __int8 *)&GradientGenTime, 4);
  v29 = str->Write;
  UserTime = this->UserTime;
  v29(str, (const unsigned __int8 *)&UserTime, 4);
  v30 = str->Write;
  LineCount = this->LineCount;
  v30(str, (const unsigned __int8 *)&LineCount, 4);
  v31 = str->Write;
  MaskCount = this->MaskCount;
  v31(str, (const unsigned __int8 *)&MaskCount, 4);
  v32 = str->Write;
  FilterCount = this->FilterCount;
  v32(str, (const unsigned __int8 *)&FilterCount, 4);
  if ( version >= 0x10 )
  {
    v33 = str->Write;
    MeshCount = this->MeshCount;
    v33(str, (const unsigned __int8 *)&MeshCount, 4);
  }
  v34 = str->Write;
  TriangleCount = this->TriangleCount;
  v34(str, (const unsigned __int8 *)&TriangleCount, 4);
  v35 = str->Write;
  DrawPrimitiveCount = this->DrawPrimitiveCount;
  v35(str, (const unsigned __int8 *)&DrawPrimitiveCount, 4);
  v36 = str->Write;
  StrokeCount = this->StrokeCount;
  v36(str, (const unsigned __int8 *)&StrokeCount, 4);
  v37 = str->Write;
  GradientFillCount = this->GradientFillCount;
  v37(str, (const unsigned __int8 *)&GradientFillCount, 4);
  v38 = str->Write;
  MeshThrashing = this->MeshThrashing;
  v38(str, (const unsigned __int8 *)&MeshThrashing, 4);
  v39 = str->Write;
  RasterizedGlyphCount = this->RasterizedGlyphCount;
  v39(str, (const unsigned __int8 *)&RasterizedGlyphCount, 4);
  v40 = str->Write;
  FontTextureCount = this->FontTextureCount;
  v40(str, (const unsigned __int8 *)&FontTextureCount, 4);
  v41 = str->Write;
  NumFontCacheTextureUpdates = this->NumFontCacheTextureUpdates;
  v41(str, (const unsigned __int8 *)&NumFontCacheTextureUpdates, 4);
  if ( version >= 0xE )
  {
    v42 = str->Write;
    FontThrashing = this->FontThrashing;
    v42(str, (const unsigned __int8 *)&FontThrashing, 4);
    v43 = str->Write;
    FontFill = this->FontFill;
    v43(str, (const unsigned __int8 *)&FontFill, 4);
    v44 = str->Write;
    FontFail = this->FontFail;
    v44(str, (const unsigned __int8 *)&FontFail, 4);
    if ( version >= 0x18 )
    {
      v45 = str->Write;
      FontMisses = this->FontMisses;
      v45(str, (const unsigned __int8 *)&FontMisses, 4);
    }
    if ( version >= 0x1B )
    {
      v46 = str->Write;
      FontTotalArea = this->FontTotalArea;
      v46(str, (const unsigned __int8 *)&FontTotalArea, 4);
      v47 = str->Write;
      FontUsedArea = this->FontUsedArea;
      v47(str, (const unsigned __int8 *)&FontUsedArea, 4);
    }
  }
  v48 = str->Write;
  TotalMemory = this->TotalMemory;
  v48(str, (const unsigned __int8 *)&TotalMemory, 4);
  v49 = str->Write;
  ImageMemory = this->ImageMemory;
  v49(str, (const unsigned __int8 *)&ImageMemory, 4);
  if ( version >= 0x1D )
  {
    v50 = str->Write;
    ImageGraphicsMemory = this->ImageGraphicsMemory;
    v50(str, (const unsigned __int8 *)&ImageGraphicsMemory, 4);
  }
  v51 = str->Write;
  MovieDataMemory = this->MovieDataMemory;
  v51(str, (const unsigned __int8 *)&MovieDataMemory, 4);
  v52 = str->Write;
  MovieViewMemory = this->MovieViewMemory;
  v52(str, (const unsigned __int8 *)&MovieViewMemory, 4);
  v53 = str->Write;
  MeshCacheMemory = this->MeshCacheMemory;
  v53(str, (const unsigned __int8 *)&MeshCacheMemory, 4);
  if ( version >= 0x1C )
  {
    v54 = str->Write;
    MeshCacheGraphicsMemory = this->MeshCacheGraphicsMemory;
    v54(str, (const unsigned __int8 *)&MeshCacheGraphicsMemory, 4);
    v55 = str->Write;
    MeshCacheUnusedMemory = this->MeshCacheUnusedMemory;
    v55(str, (const unsigned __int8 *)&MeshCacheUnusedMemory, 4);
    v56 = str->Write;
    MeshCacheGraphicsUnusedMemory = this->MeshCacheGraphicsUnusedMemory;
    v56(str, (const unsigned __int8 *)&MeshCacheGraphicsUnusedMemory, 4);
  }
  v57 = str->Write;
  FontCacheMemory = this->FontCacheMemory;
  v57(str, (const unsigned __int8 *)&FontCacheMemory, 4);
  v58 = str->Write;
  VideoMemory = this->VideoMemory;
  v58(str, (const unsigned __int8 *)&VideoMemory, 4);
  v59 = str->Write;
  SoundMemory = this->SoundMemory;
  v59(str, (const unsigned __int8 *)&SoundMemory, 4);
  v60 = str->Write;
  OtherMemory = this->OtherMemory;
  v60(str, (const unsigned __int8 *)&OtherMemory, 4);
  if ( version >= 0x20 )
  {
    v61 = str->Write;
    GcRootsNumber = this->GcRootsNumber;
    v61(str, (const unsigned __int8 *)&GcRootsNumber, 4);
    v62 = str->Write;
    GcFreedRootsNumber = this->GcFreedRootsNumber;
    v62(str, (const unsigned __int8 *)&GcFreedRootsNumber, 4);
  }
  v63 = str->Write;
  Size = this->MovieStats.Data.Size;
  v63(str, (const unsigned __int8 *)&Size, 4);
  for ( i = 0; i < this->MovieStats.Data.Size; ++i )
    Scaleform::GFx::AMP::MovieProfile::Write(this->MovieStats.Data.Data[i].pObject, str, version);
  if ( version >= 0xF )
    Scaleform::GFx::AMP::MovieFunctionStats::Write(this->DisplayStats.pObject, str, version);
  if ( version >= 0x19 )
    Scaleform::GFx::AMP::MovieFunctionTreeStats::Write(this->DisplayFunctionStats.pObject, str, version);
  v65 = str->Write;
  v129 = this->SwdHandles.Data.Size;
  v65(str, (const unsigned __int8 *)&v129, 4);
  for ( j = 0; j < this->SwdHandles.Data.Size; ++j )
  {
    v67 = str->Write;
    v131 = this->SwdHandles.Data.Data[j];
    v67(str, (const unsigned __int8 *)&v131, 4);
  }
  if ( version >= 9 )
  {
    v68 = str->Write;
    v133 = this->FileHandles.Data.Size;
    v68(str, (const unsigned __int8 *)&v133, 4);
    for ( k = 0; k < this->FileHandles.Data.Size; ++k )
    {
      Data = this->FileHandles.Data.Data;
      v71 = Data[k];
      v72 = HIDWORD(Data[k]);
      v73 = str->__vftable;
      v145[0] = v71;
      v145[1] = v72;
      v73->Write(str, (const unsigned __int8 *)v145, 8);
    }
  }
  Scaleform::MemItem::Write(this->MemoryByStatId.pObject, str, version);
  if ( version <= 0x12 )
  {
    v135 = 2;
    v74 = (Scaleform::StringLH *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                   Scaleform::Memory::pGlobalHeap,
                                   this,
                                   40,
                                   &v135);
    v75 = (Scaleform::MemItem *)v74;
    if ( v74 )
    {
      v74->HeapTypeBits = (unsigned int)&Scaleform::RefCountImplCore::`vftable';
      v74[1].HeapTypeBits = 1;
      v74->HeapTypeBits = (unsigned int)&Scaleform::MemItem::`vftable';
      Scaleform::StringLH::StringLH(v74 + 2);
      v75->Value = 0;
      v75->HasValue = 0;
      v75->StartExpanded = 0;
      v75->ID = 0;
      v75->ImageExtraData.pObject = 0;
      v75->Children.Data.Data = 0;
      v75->Children.Data.Size = 0;
      v75->Children.Data.Policy.Capacity = 0;
    }
    else
    {
      v75 = 0;
    }
    Scaleform::MemItem::Write(v75, str, version);
    if ( v75 )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v75);
  }
  if ( version >= 3 )
    Scaleform::MemItem::Write(this->Images.pObject, str, version);
  if ( version >= 7 )
    Scaleform::MemItem::Write(this->Fonts.pObject, str, version);
  if ( version >= 0x11 )
  {
    v76 = str->Write;
    v137 = this->ImageList.Data.Size;
    v76(str, (const unsigned __int8 *)&v137, 4);
    for ( m = 0; m < this->ImageList.Data.Size; ++m )
      Scaleform::GFx::AMP::ImageInfo::Write(this->ImageList.Data.Data[m].pObject, (unsigned int)str, version);
  }
  if ( version < 8 )
  {
    v78 = str->Write;
    v139 = 0;
    v78(str, (const unsigned __int8 *)&v139, 4);
    v79 = str->Write;
    v141 = 0;
    v79(str, (const unsigned __int8 *)&v141, 4);
  }
}
