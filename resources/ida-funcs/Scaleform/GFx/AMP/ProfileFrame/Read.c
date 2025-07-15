void __thiscall Scaleform::GFx::AMP::ProfileFrame::Read(
        Scaleform::GFx::AMP::ProfileFrame *this,
        Scaleform::File *str,
        unsigned int version)
{
  int (__thiscall *Read)(Scaleform::File *, unsigned __int8 *, int); // edx
  int v5; // ecx
  int (__thiscall *v6)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v7)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v8)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v9)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v10)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v11)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v12)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v13)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v14)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v15)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v16)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v17)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v18)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v19)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v20)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v21)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v22)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v23)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v24)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v25)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v26)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v27)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v28)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v29)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v30)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v31)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v32)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v33)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v34)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v35)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v36)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v37)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v38)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v39)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v40)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v41)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v42)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v43)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v44)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v45)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v46)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v47)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v48)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v49)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v50)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v51)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v52)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v53)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v54)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v55)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v56)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v57)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v58)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v59)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v60)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v61)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v62)(Scaleform::File *, unsigned __int8 *, int); // edx
  int v63; // ecx
  Scaleform::Ptr<Scaleform::GFx::AMP::MovieProfile> *v64; // eax
  Scaleform::GFx::AMP::MovieProfile *v65; // eax
  unsigned int v66; // eax
  Scaleform::Ptr<Scaleform::GFx::AMP::MovieProfile> *Data; // ebp
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::Ptr<Scaleform::GFx::AMP::MovieProfile> *v69; // ebp
  int (__thiscall *v70)(Scaleform::File *, unsigned __int8 *, int); // edx
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *p_SwdHandles; // ecx
  unsigned int v72; // ebp
  unsigned int j; // ebp
  int (__thiscall *v74)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v75)(Scaleform::File *, unsigned __int8 *, int); // edx
  Scaleform::ArrayLH<unsigned __int64,2,Scaleform::ArrayDefaultPolicy> *p_FileHandles; // ecx
  unsigned int v77; // ebp
  unsigned int k; // ebp
  int (__thiscall *v79)(Scaleform::File *, unsigned __int8 *, int); // edx
  unsigned __int64 *v80; // eax
  unsigned int v81; // ebp
  Scaleform::StringLH *v82; // eax
  Scaleform::MemItem *v83; // ebp
  int (__thiscall *v84)(Scaleform::File *, unsigned __int8 *, int); // edx
  unsigned int v85; // ecx
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *p_ImageList; // ebp
  unsigned int v87; // ecx
  Scaleform::RefCountVImpl **v88; // ebp
  unsigned int v89; // ecx
  unsigned int v90; // edx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *v91; // eax
  Scaleform::StringLH *v92; // eax
  Scaleform::StringLH *v93; // ebp
  Scaleform::Ptr<Scaleform::GFx::AMP::ImageInfo> *v94; // ebp
  Scaleform::RefCountVImpl *v95; // ecx
  _DWORD *p_pObject; // ebp
  int (__thiscall *v97)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v98)(Scaleform::File *, unsigned __int8 *, int); // edx
  unsigned int Size; // [esp+21Ch] [ebp-120h]
  unsigned int i; // [esp+21Ch] [ebp-120h]
  unsigned int v101; // [esp+21Ch] [ebp-120h]
  unsigned int m; // [esp+21Ch] [ebp-120h]
  int v103; // [esp+220h] [ebp-11Ch] BYREF
  unsigned int v104; // [esp+224h] [ebp-118h] BYREF
  int v105; // [esp+228h] [ebp-114h] BYREF
  unsigned int v106; // [esp+22Ch] [ebp-110h] BYREF
  unsigned int v107; // [esp+230h] [ebp-10Ch] BYREF
  unsigned int v108; // [esp+234h] [ebp-108h] BYREF
  unsigned int v109; // [esp+238h] [ebp-104h] BYREF
  unsigned int v110; // [esp+23Ch] [ebp-100h] BYREF
  unsigned int v111; // [esp+240h] [ebp-FCh] BYREF
  unsigned int v112; // [esp+244h] [ebp-F8h] BYREF
  unsigned int v113; // [esp+248h] [ebp-F4h] BYREF
  unsigned int v114; // [esp+24Ch] [ebp-F0h] BYREF
  unsigned int v115; // [esp+250h] [ebp-ECh] BYREF
  unsigned int v116; // [esp+254h] [ebp-E8h] BYREF
  unsigned int v117; // [esp+258h] [ebp-E4h] BYREF
  unsigned int v118; // [esp+25Ch] [ebp-E0h] BYREF
  unsigned int v119; // [esp+260h] [ebp-DCh] BYREF
  unsigned int v120; // [esp+264h] [ebp-D8h] BYREF
  unsigned int v121; // [esp+268h] [ebp-D4h] BYREF
  unsigned int v122; // [esp+26Ch] [ebp-D0h] BYREF
  unsigned int v123; // [esp+270h] [ebp-CCh] BYREF
  unsigned int v124; // [esp+274h] [ebp-C8h] BYREF
  unsigned int v125; // [esp+278h] [ebp-C4h] BYREF
  unsigned int v126; // [esp+27Ch] [ebp-C0h] BYREF
  unsigned int v127; // [esp+280h] [ebp-BCh] BYREF
  unsigned int v128; // [esp+284h] [ebp-B8h] BYREF
  unsigned int v129; // [esp+288h] [ebp-B4h] BYREF
  unsigned int v130; // [esp+28Ch] [ebp-B0h] BYREF
  unsigned int v131; // [esp+290h] [ebp-ACh] BYREF
  unsigned int v132; // [esp+294h] [ebp-A8h] BYREF
  unsigned int v133; // [esp+298h] [ebp-A4h] BYREF
  unsigned int v134; // [esp+29Ch] [ebp-A0h] BYREF
  unsigned int v135; // [esp+2A0h] [ebp-9Ch] BYREF
  unsigned int v136; // [esp+2A4h] [ebp-98h] BYREF
  unsigned int v137; // [esp+2A8h] [ebp-94h] BYREF
  unsigned int v138; // [esp+2ACh] [ebp-90h] BYREF
  unsigned int v139; // [esp+2B0h] [ebp-8Ch] BYREF
  unsigned int v140; // [esp+2B4h] [ebp-88h] BYREF
  unsigned int v141; // [esp+2B8h] [ebp-84h] BYREF
  unsigned int v142; // [esp+2BCh] [ebp-80h] BYREF
  unsigned int v143; // [esp+2C0h] [ebp-7Ch] BYREF
  unsigned int v144; // [esp+2C4h] [ebp-78h] BYREF
  unsigned int v145; // [esp+2C8h] [ebp-74h] BYREF
  unsigned int v146; // [esp+2CCh] [ebp-70h] BYREF
  unsigned int v147; // [esp+2D0h] [ebp-6Ch] BYREF
  unsigned int v148; // [esp+2D4h] [ebp-68h] BYREF
  unsigned int v149; // [esp+2D8h] [ebp-64h] BYREF
  unsigned int v150; // [esp+2DCh] [ebp-60h] BYREF
  unsigned int v151; // [esp+2E0h] [ebp-5Ch] BYREF
  unsigned int v152; // [esp+2E4h] [ebp-58h] BYREF
  unsigned int v153; // [esp+2E8h] [ebp-54h] BYREF
  unsigned int v154; // [esp+2ECh] [ebp-50h] BYREF
  unsigned int v155; // [esp+2F0h] [ebp-4Ch]
  unsigned int v156; // [esp+2F4h] [ebp-48h] BYREF
  unsigned int v157; // [esp+2F8h] [ebp-44h] BYREF
  unsigned int v158; // [esp+2FCh] [ebp-40h] BYREF
  unsigned int v159; // [esp+300h] [ebp-3Ch] BYREF
  unsigned int v160; // [esp+304h] [ebp-38h] BYREF
  unsigned int v161; // [esp+308h] [ebp-34h] BYREF
  unsigned int v162; // [esp+30Ch] [ebp-30h] BYREF
  unsigned int v163; // [esp+310h] [ebp-2Ch] BYREF
  unsigned int v164; // [esp+314h] [ebp-28h] BYREF
  int v165; // [esp+318h] [ebp-24h] BYREF
  int v166; // [esp+31Ch] [ebp-20h]
  int v167; // [esp+320h] [ebp-1Ch] BYREF
  int v168; // [esp+324h] [ebp-18h]
  int v169; // [esp+328h] [ebp-14h] BYREF
  int v170; // [esp+32Ch] [ebp-10h] BYREF
  int v171; // [esp+330h] [ebp-Ch] BYREF
  int v172; // [esp+334h] [ebp-8h] BYREF
  int v173; // [esp+338h] [ebp-4h] BYREF

  Read = str->Read;
  v167 = 0;
  v168 = 0;
  Read(str, (unsigned __int8 *)&v167, 8);
  v5 = v168;
  LODWORD(this->TimeStamp) = v167;
  HIDWORD(this->TimeStamp) = v5;
  v6 = str->Read;
  v154 = 0;
  v6(str, (unsigned __int8 *)&v154, 4);
  this->FramesPerSecond = v154;
  if ( version >= 0x21 )
  {
    v7 = str->Read;
    v147 = 0;
    v7(str, (unsigned __int8 *)&v147, 4);
    this->ProfilingLevel = v147;
    v8 = str->Read;
    HIBYTE(v103) = 0;
    v8(str, (unsigned __int8 *)&v103 + 3, 1);
    this->DetailedMemReport = HIBYTE(v103) != 0;
  }
  v9 = str->Read;
  v157 = 0;
  v9(str, (unsigned __int8 *)&v157, 4);
  this->AdvanceTime = v157;
  v10 = str->Read;
  v108 = 0;
  v10(str, (unsigned __int8 *)&v108, 4);
  this->TimelineTime = v108;
  v11 = str->Read;
  v140 = 0;
  v11(str, (unsigned __int8 *)&v140, 4);
  this->ActionTime = v140;
  if ( version < 0x15 )
  {
    v12 = str->Read;
    v169 = 0;
    v12(str, (unsigned __int8 *)&v169, 4);
  }
  v13 = str->Read;
  v110 = 0;
  v13(str, (unsigned __int8 *)&v110, 4);
  this->InputTime = v110;
  v14 = str->Read;
  v156 = 0;
  v14(str, (unsigned __int8 *)&v156, 4);
  this->MouseTime = v156;
  if ( version >= 0x20 )
  {
    v15 = str->Read;
    v112 = 0;
    v15(str, (unsigned __int8 *)&v112, 4);
    this->GcCollectTime = v112;
    v16 = str->Read;
    v142 = 0;
    v16(str, (unsigned __int8 *)&v142, 4);
    this->GcMarkInCycleTime = v142;
    v17 = str->Read;
    v114 = 0;
    v17(str, (unsigned __int8 *)&v114, 4);
    this->GcScanInUseTime = v114;
    v18 = str->Read;
    v160 = 0;
    v18(str, (unsigned __int8 *)&v160, 4);
    this->GcFreeGarbageTime = v160;
    v19 = str->Read;
    v116 = 0;
    v19(str, (unsigned __int8 *)&v116, 4);
    this->GcFinalizeTime = v116;
    v20 = str->Read;
    v144 = 0;
    v20(str, (unsigned __int8 *)&v144, 4);
    this->GcDelayedCleanupTime = v144;
  }
  v21 = str->Read;
  v118 = 0;
  v21(str, (unsigned __int8 *)&v118, 4);
  this->GetVariableTime = v118;
  v22 = str->Read;
  v158 = 0;
  v22(str, (unsigned __int8 *)&v158, 4);
  this->SetVariableTime = v158;
  v23 = str->Read;
  v120 = 0;
  v23(str, (unsigned __int8 *)&v120, 4);
  this->InvokeTime = v120;
  v24 = str->Read;
  v146 = 0;
  v24(str, (unsigned __int8 *)&v146, 4);
  this->DisplayTime = v146;
  if ( version >= 0x1E )
  {
    v25 = str->Read;
    v122 = 0;
    v25(str, (unsigned __int8 *)&v122, 4);
    this->PresentTime = v122;
  }
  v26 = str->Read;
  v162 = 0;
  v26(str, (unsigned __int8 *)&v162, 4);
  this->TesselationTime = v162;
  v27 = str->Read;
  v124 = 0;
  v27(str, (unsigned __int8 *)&v124, 4);
  this->GradientGenTime = v124;
  v28 = str->Read;
  v148 = 0;
  v28(str, (unsigned __int8 *)&v148, 4);
  this->UserTime = v148;
  v29 = str->Read;
  v126 = 0;
  v29(str, (unsigned __int8 *)&v126, 4);
  this->LineCount = v126;
  v30 = str->Read;
  v163 = 0;
  v30(str, (unsigned __int8 *)&v163, 4);
  this->MaskCount = v163;
  v31 = str->Read;
  v128 = 0;
  v31(str, (unsigned __int8 *)&v128, 4);
  this->FilterCount = v128;
  if ( version >= 0x10 )
  {
    v32 = str->Read;
    v150 = 0;
    v32(str, (unsigned __int8 *)&v150, 4);
    this->MeshCount = v150;
  }
  v33 = str->Read;
  v130 = 0;
  v33(str, (unsigned __int8 *)&v130, 4);
  this->TriangleCount = v130;
  v34 = str->Read;
  v161 = 0;
  v34(str, (unsigned __int8 *)&v161, 4);
  this->DrawPrimitiveCount = v161;
  v35 = str->Read;
  v132 = 0;
  v35(str, (unsigned __int8 *)&v132, 4);
  this->StrokeCount = v132;
  v36 = str->Read;
  v152 = 0;
  v36(str, (unsigned __int8 *)&v152, 4);
  this->GradientFillCount = v152;
  v37 = str->Read;
  v134 = 0;
  v37(str, (unsigned __int8 *)&v134, 4);
  this->MeshThrashing = v134;
  v38 = str->Read;
  v164 = 0;
  v38(str, (unsigned __int8 *)&v164, 4);
  this->RasterizedGlyphCount = v164;
  v39 = str->Read;
  v136 = 0;
  v39(str, (unsigned __int8 *)&v136, 4);
  this->FontTextureCount = v136;
  v40 = str->Read;
  v106 = 0;
  v40(str, (unsigned __int8 *)&v106, 4);
  this->NumFontCacheTextureUpdates = v106;
  if ( version >= 0xE )
  {
    v41 = str->Read;
    v138 = 0;
    v41(str, (unsigned __int8 *)&v138, 4);
    this->FontThrashing = v138;
    v42 = str->Read;
    v159 = 0;
    v42(str, (unsigned __int8 *)&v159, 4);
    this->FontFill = v159;
    v43 = str->Read;
    v107 = 0;
    v43(str, (unsigned __int8 *)&v107, 4);
    this->FontFail = v107;
    if ( version >= 0x18 )
    {
      v44 = str->Read;
      v109 = 0;
      v44(str, (unsigned __int8 *)&v109, 4);
      this->FontMisses = v109;
    }
    if ( version >= 0x1B )
    {
      v45 = str->Read;
      v111 = 0;
      v45(str, (unsigned __int8 *)&v111, 4);
      this->FontTotalArea = v111;
      v46 = str->Read;
      v113 = 0;
      v46(str, (unsigned __int8 *)&v113, 4);
      this->FontUsedArea = v113;
    }
  }
  v47 = str->Read;
  v115 = 0;
  v47(str, (unsigned __int8 *)&v115, 4);
  this->TotalMemory = v115;
  v48 = str->Read;
  v117 = 0;
  v48(str, (unsigned __int8 *)&v117, 4);
  this->ImageMemory = v117;
  if ( version >= 0x1D )
  {
    v49 = str->Read;
    v119 = 0;
    v49(str, (unsigned __int8 *)&v119, 4);
    this->ImageGraphicsMemory = v119;
  }
  v50 = str->Read;
  v121 = 0;
  v50(str, (unsigned __int8 *)&v121, 4);
  this->MovieDataMemory = v121;
  v51 = str->Read;
  v123 = 0;
  v51(str, (unsigned __int8 *)&v123, 4);
  this->MovieViewMemory = v123;
  v52 = str->Read;
  v125 = 0;
  v52(str, (unsigned __int8 *)&v125, 4);
  this->MeshCacheMemory = v125;
  if ( version >= 0x1C )
  {
    v53 = str->Read;
    v127 = 0;
    v53(str, (unsigned __int8 *)&v127, 4);
    this->MeshCacheGraphicsMemory = v127;
    v54 = str->Read;
    v129 = 0;
    v54(str, (unsigned __int8 *)&v129, 4);
    this->MeshCacheUnusedMemory = v129;
    v55 = str->Read;
    v131 = 0;
    v55(str, (unsigned __int8 *)&v131, 4);
    this->MeshCacheGraphicsUnusedMemory = v131;
  }
  v56 = str->Read;
  v133 = 0;
  v56(str, (unsigned __int8 *)&v133, 4);
  this->FontCacheMemory = v133;
  v57 = str->Read;
  v135 = 0;
  v57(str, (unsigned __int8 *)&v135, 4);
  this->VideoMemory = v135;
  v58 = str->Read;
  v137 = 0;
  v58(str, (unsigned __int8 *)&v137, 4);
  this->SoundMemory = v137;
  v59 = str->Read;
  v139 = 0;
  v59(str, (unsigned __int8 *)&v139, 4);
  this->OtherMemory = v139;
  if ( version >= 0x20 )
  {
    v60 = str->Read;
    v141 = 0;
    v60(str, (unsigned __int8 *)&v141, 4);
    this->GcRootsNumber = v141;
    v61 = str->Read;
    v143 = 0;
    v61(str, (unsigned __int8 *)&v143, 4);
    this->GcFreedRootsNumber = v143;
  }
  v62 = str->Read;
  v145 = 0;
  v62(str, (unsigned __int8 *)&v145, 4);
  Size = this->MovieStats.Data.Size;
  v104 = v145;
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AMP::Server::RenderProfile>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AMP::Server::RenderProfile>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS3::SocketThreadMgr>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS3::SocketThreadMgr>,2>,Scaleform::ArrayDefaultPolicy> *)&this->MovieStats,
    &this->MovieStats,
    v145);
  if ( v104 > Size )
  {
    v63 = v104 - Size;
    v64 = &this->MovieStats.Data.Data[Size];
    if ( v104 != Size )
    {
      do
      {
        if ( v64 )
          v64->pObject = 0;
        ++v64;
        --v63;
      }
      while ( v63 );
    }
  }
  for ( i = 0; i < this->MovieStats.Data.Size; ++i )
  {
    v171 = 578;
    v65 = (Scaleform::GFx::AMP::MovieProfile *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                 Scaleform::Memory::pGlobalHeap,
                                                 this,
                                                 72,
                                                 &v171);
    if ( v65 )
    {
      Scaleform::GFx::AMP::MovieProfile::MovieProfile(v65);
      v104 = v66;
    }
    else
    {
      v104 = 0;
    }
    Data = this->MovieStats.Data.Data;
    pObject = (Scaleform::RefCountVImpl *)Data[i].pObject;
    v69 = &Data[i];
    if ( pObject )
      Scaleform::RefCountImpl::Release(pObject);
    v69->pObject = (Scaleform::GFx::AMP::MovieProfile *)v104;
    Scaleform::GFx::AMP::MovieProfile::Read(this->MovieStats.Data.Data[i].pObject, str, version);
  }
  if ( version >= 0xF )
    Scaleform::GFx::AMP::MovieFunctionStats::Read(this->DisplayStats.pObject, str, version);
  if ( version >= 0x19 )
    Scaleform::GFx::AMP::MovieFunctionTreeStats::Read(this->DisplayFunctionStats.pObject, str, version);
  v70 = str->Read;
  v104 = 0;
  v70(str, (unsigned __int8 *)&v104, 4);
  p_SwdHandles = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&this->SwdHandles;
  v72 = v104;
  if ( v104 >= this->SwdHandles.Data.Size )
  {
    if ( v104 >= this->SwdHandles.Data.Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        p_SwdHandles,
        &this->SwdHandles,
        v104 + (v104 >> 2));
  }
  else if ( v104 < this->SwdHandles.Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      p_SwdHandles,
      &this->SwdHandles,
      v104);
  }
  this->SwdHandles.Data.Size = v72;
  for ( j = 0; j < this->SwdHandles.Data.Size; ++j )
  {
    v74 = str->Read;
    v149 = 0;
    v74(str, (unsigned __int8 *)&v149, 4);
    this->SwdHandles.Data.Data[j] = v149;
  }
  if ( version >= 9 )
  {
    v75 = str->Read;
    v151 = 0;
    v75(str, (unsigned __int8 *)&v151, 4);
    p_FileHandles = &this->FileHandles;
    v77 = v151;
    if ( v151 >= this->FileHandles.Data.Size )
    {
      if ( v151 >= this->FileHandles.Data.Policy.Capacity )
        Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          (Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy> *)p_FileHandles,
          &this->FileHandles,
          v151 + (v151 >> 2));
    }
    else if ( v151 < this->FileHandles.Data.Policy.Capacity >> 1 )
    {
      Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy> *)p_FileHandles,
        &this->FileHandles,
        v151);
    }
    this->FileHandles.Data.Size = v77;
    for ( k = 0; k < this->FileHandles.Data.Size; ++k )
    {
      v79 = str->Read;
      v165 = 0;
      v166 = 0;
      v79(str, (unsigned __int8 *)&v165, 8);
      v80 = this->FileHandles.Data.Data;
      LODWORD(v80[k]) = v165;
      HIDWORD(v80[k]) = v166;
    }
  }
  v81 = version;
  Scaleform::MemItem::Read(this->MemoryByStatId.pObject, str, version);
  if ( version <= 0x12 )
  {
    v173 = 2;
    v82 = (Scaleform::StringLH *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                   Scaleform::Memory::pGlobalHeap,
                                   this,
                                   40,
                                   &v173);
    v83 = (Scaleform::MemItem *)v82;
    if ( v82 )
    {
      v82->HeapTypeBits = (unsigned int)&Scaleform::RefCountImplCore::`vftable';
      v82[1].HeapTypeBits = 1;
      v82->HeapTypeBits = (unsigned int)&Scaleform::MemItem::`vftable';
      Scaleform::StringLH::StringLH(v82 + 2);
      v83->Value = 0;
      v83->HasValue = 0;
      v83->StartExpanded = 0;
      v83->ID = 0;
      v83->ImageExtraData.pObject = 0;
      v83->Children.Data.Data = 0;
      v83->Children.Data.Size = 0;
      v83->Children.Data.Policy.Capacity = 0;
    }
    else
    {
      v83 = 0;
    }
    Scaleform::MemItem::Read(v83, str, version);
    if ( v83 )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v83);
    v81 = version;
  }
  if ( v81 >= 3 )
    Scaleform::MemItem::Read(this->Images.pObject, str, v81);
  if ( v81 >= 7 )
    Scaleform::MemItem::Read(this->Fonts.pObject, str, v81);
  if ( v81 >= 0x11 )
  {
    v84 = str->Read;
    v153 = 0;
    v84(str, (unsigned __int8 *)&v153, 4);
    v85 = this->ImageList.Data.Size;
    p_ImageList = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&this->ImageList;
    v101 = v153;
    v105 = v85;
    if ( v153 >= v85 )
    {
      if ( v153 >= this->ImageList.Data.Policy.Capacity )
        Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          p_ImageList,
          p_ImageList,
          v153 + (v153 >> 2));
    }
    else
    {
      v87 = v85 - v153;
      v88 = (Scaleform::RefCountVImpl **)&p_ImageList->Data[v87 - 1 + v153];
      if ( v87 )
      {
        v155 = v87;
        do
        {
          if ( *v88 )
            Scaleform::RefCountImpl::Release(*v88);
          --v88;
          --v155;
        }
        while ( v155 );
      }
      p_ImageList = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&this->ImageList;
      if ( v101 < this->ImageList.Data.Policy.Capacity >> 1 )
        Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          p_ImageList,
          p_ImageList,
          v101);
    }
    v89 = v105;
    p_ImageList->Size = v101;
    if ( v101 > v89 )
    {
      v90 = v101 - v89;
      v91 = &p_ImageList->Data[v89];
      if ( v101 != v89 )
      {
        do
        {
          if ( v91 )
            v91->pObject = 0;
          ++v91;
          --v90;
        }
        while ( v90 );
      }
    }
    for ( m = 0; m < this->ImageList.Data.Size; ++m )
    {
      v105 = 578;
      v92 = (Scaleform::StringLH *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                     Scaleform::Memory::pGlobalHeap,
                                     this,
                                     44,
                                     &v105);
      v93 = v92;
      if ( v92 )
      {
        v92->HeapTypeBits = (unsigned int)&Scaleform::RefCountImplCore::`vftable';
        v92[1].HeapTypeBits = 1;
        v92->HeapTypeBits = (unsigned int)&Scaleform::GFx::AMP::ImageInfo::`vftable';
        v92[2].HeapTypeBits = 0;
        Scaleform::StringLH::StringLH(v92 + 3);
        v93[4].HeapTypeBits = 0;
        LOBYTE(v93[5].pData) = 0;
        v93[6].HeapTypeBits = 0;
        v93[7].HeapTypeBits = 0;
        v93[8].HeapTypeBits = 0;
        v93[9].HeapTypeBits = 0;
        v93[10].HeapTypeBits = 0;
        v105 = (int)v93;
      }
      else
      {
        v105 = 0;
      }
      v94 = this->ImageList.Data.Data;
      v95 = (Scaleform::RefCountVImpl *)v94[m].pObject;
      p_pObject = &v94[m].pObject;
      if ( v95 )
        Scaleform::RefCountImpl::Release(v95);
      *p_pObject = v105;
      Scaleform::GFx::AMP::ImageInfo::Read(this->ImageList.Data.Data[m].pObject, (unsigned int)str, version);
    }
  }
  if ( version < 8 )
  {
    v97 = str->Read;
    v172 = 0;
    v97(str, (unsigned __int8 *)&v172, 4);
    v98 = str->Read;
    v170 = 0;
    v98(str, (unsigned __int8 *)&v170, 4);
  }
}
