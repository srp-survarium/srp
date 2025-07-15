void __stdcall Scaleform::GFx::GFx_FontTextureInfoLoader(
        Scaleform::GFx::LoadProcess *p,
        const Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // esi
  int v3; // ecx
  unsigned int Pos; // ecx
  unsigned int v5; // edi
  unsigned int v6; // eax
  int v7; // ecx
  unsigned int v8; // eax
  int v9; // ecx
  unsigned int v10; // eax
  int v11; // edx
  int v12; // ecx
  unsigned int v13; // eax
  unsigned __int16 v14; // cx
  unsigned __int16 v15; // bx
  int v16; // edx
  unsigned int v17; // eax
  int v18; // edx
  int v19; // ecx
  unsigned int v20; // eax
  int v21; // edx
  int v22; // ecx
  unsigned int v23; // eax
  unsigned int v24; // edi
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v25; // ecx
  int v26; // ecx
  unsigned int v27; // ecx
  unsigned int v28; // edx
  unsigned int v29; // eax
  int v30; // ecx
  unsigned int v31; // ecx
  int v32; // edx
  unsigned int v33; // eax
  int v34; // ecx
  unsigned int v35; // ecx
  int v36; // edx
  unsigned int v37; // eax
  int v38; // ecx
  unsigned int v39; // ecx
  int v40; // edx
  unsigned int v41; // eax
  int v42; // ecx
  unsigned int v43; // ecx
  int v44; // edx
  unsigned int v45; // eax
  int v46; // ecx
  unsigned int v47; // ecx
  int v48; // edx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v49; // ecx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v50; // ecx
  Scaleform::Render::Image *v51; // edi
  unsigned int v52; // edi
  Scaleform::Render::TextureGlyph *v53; // ebx
  int v54; // ecx
  unsigned int v55; // eax
  float v56; // edi
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v57; // ecx
  int v58; // edx
  unsigned int v59; // eax
  unsigned __int16 v60; // cx
  Scaleform::Render::Font *FontData; // edi
  int v62; // eax
  Scaleform::GFx::TextureGlyphData *v63; // ebx
  Scaleform::GFx::TextureGlyphData *v64; // ebx
  unsigned int v65; // eax
  Scaleform::GFx::TextureGlyphData *v66; // eax
  int v67; // edx
  int v68; // ecx
  int v69; // edx
  int v70; // eax
  unsigned int v71; // eax
  unsigned __int16 v72; // dx
  int v73; // edx
  unsigned int v74; // eax
  unsigned __int16 v75; // cx
  int v76; // edx
  unsigned int v77; // edi
  unsigned int v78; // eax
  Scaleform::Render::TextureGlyph *Data; // ebx
  Scaleform::Render::TextureGlyph *v80; // esi
  unsigned int Size; // edi
  void *v82; // esi
  Scaleform::String pstr; // [esp+2C0h] [ebp-80h] BYREF
  Scaleform::GFx::ResourceId rid; // [esp+2C4h] [ebp-7Ch]
  float v85; // [esp+2C8h] [ebp-78h]
  float v86; // [esp+2CCh] [ebp-74h]
  float v87; // [esp+2D0h] [ebp-70h]
  float v88; // [esp+2D4h] [ebp-6Ch]
  float v89; // [esp+2D8h] [ebp-68h]
  unsigned int v90; // [esp+2DCh] [ebp-64h]
  unsigned int v91; // [esp+2E0h] [ebp-60h]
  Scaleform::MemoryHeap *pHeap; // [esp+2E4h] [ebp-5Ch]
  Scaleform::GFx::ResourceId v93; // [esp+2E8h] [ebp-58h]
  Scaleform::GFx::ResourceHandle result; // [esp+2ECh] [ebp-54h] BYREF
  Scaleform::ArrayDataBase<Scaleform::Render::TextureGlyph,Scaleform::AllocatorGH<Scaleform::Render::TextureGlyph,2>,Scaleform::ArrayDefaultPolicy> pheapAddr; // [esp+2F4h] [ebp-4Ch] BYREF
  int v96; // [esp+300h] [ebp-40h]
  int v97; // [esp+304h] [ebp-3Ch]
  unsigned __int16 targetWidth[2]; // [esp+308h] [ebp-38h]
  int v99; // [esp+30Ch] [ebp-34h]
  Scaleform::Render::TextureGlyph __that; // [esp+310h] [ebp-30h] BYREF

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  v3 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
  pHeap = p->pLoadData.pObject->pHeap;
  pAltStream->Stream.UnusedBits = 0;
  if ( v3 < 4 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 4);
  Pos = pAltStream->Stream.Pos;
  v5 = pAltStream->Stream.pBuffer[Pos]
     | ((pAltStream->Stream.pBuffer[Pos + 1] | (*(unsigned __int16 *)&pAltStream->Stream.pBuffer[Pos + 2] << 8)) << 8);
  v6 = Pos + 4;
  v7 = pAltStream->Stream.DataSize - (Pos + 4);
  v93.Id = v5;
  pAltStream->Stream.Pos = v6;
  pAltStream->Stream.UnusedBits = 0;
  if ( v7 < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
  v8 = pAltStream->Stream.Pos;
  rid.Id = *(unsigned __int16 *)&pAltStream->Stream.pBuffer[v8];
  pAltStream->Stream.Pos = v8 + 2;
  Scaleform::String::String(&pstr);
  Scaleform::GFx::Stream::ReadStringWithLength(&pAltStream->Stream, &pstr);
  v9 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
  pAltStream->Stream.UnusedBits = 0;
  if ( v9 < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
  v10 = pAltStream->Stream.Pos;
  v11 = *(unsigned __int16 *)&pAltStream->Stream.pBuffer[v10];
  v10 += 2;
  v12 = pAltStream->Stream.DataSize - v10;
  pAltStream->Stream.Pos = v10;
  *(_DWORD *)targetWidth = v11;
  pAltStream->Stream.UnusedBits = 0;
  if ( v12 < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
  v13 = pAltStream->Stream.Pos;
  v14 = *(_WORD *)&pAltStream->Stream.pBuffer[v13];
  v13 += 2;
  v15 = v14;
  v16 = pAltStream->Stream.DataSize - v13;
  pAltStream->Stream.Pos = v13;
  v99 = v14;
  pAltStream->Stream.UnusedBits = 0;
  if ( v16 < 1 )
    Scaleform::GFx::Stream::PopulateBuffer1(&pAltStream->Stream);
  v17 = pAltStream->Stream.Pos;
  v18 = pAltStream->Stream.pBuffer[v17++];
  v19 = pAltStream->Stream.DataSize - v17;
  pAltStream->Stream.Pos = v17;
  v97 = v18;
  pAltStream->Stream.UnusedBits = 0;
  if ( v19 < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
  v20 = pAltStream->Stream.Pos;
  v21 = *(unsigned __int16 *)&pAltStream->Stream.pBuffer[v20];
  pAltStream->Stream.Pos = v20 + 2;
  v96 = v21;
  if ( Scaleform::GFx::Stream::IsVerboseParse(&pAltStream->Stream) )
    Scaleform::Render::JPEG::JPEGRwSource::TermSource((Scaleform::GFx::AS3::RefCountBaseGC<328> *)tagInfo->TagType);
  Scaleform::GFx::GFx_CreateImageFileResourceHandle(
    &result,
    p,
    (Scaleform::GFx::ResourceId)v5,
    (char *)((pstr.HeapTypeBits & 0xFFFFFFFC) + 8),
    (char *)&buf,
    rid.Id,
    targetWidth[0],
    v15);
  v22 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
  memset(&pheapAddr, 0, sizeof(pheapAddr));
  pAltStream->Stream.UnusedBits = 0;
  if ( v22 < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
  v23 = pAltStream->Stream.Pos;
  v24 = *(unsigned __int16 *)&pAltStream->Stream.pBuffer[v23];
  pAltStream->Stream.Pos = v23 + 2;
  v91 = v24;
  if ( Scaleform::GFx::Stream::IsVerboseParse(&pAltStream->Stream) )
    Scaleform::Render::JPEG::JPEGRwSource::TermSource(v25);
  v90 = 0;
  if ( v24 )
  {
    do
    {
      v26 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
      pAltStream->Stream.UnusedBits = 0;
      if ( v26 < 4 )
        Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 4);
      v27 = pAltStream->Stream.Pos;
      v28 = pAltStream->Stream.pBuffer[v27]
          | ((pAltStream->Stream.pBuffer[v27 + 1] | (*(unsigned __int16 *)&pAltStream->Stream.pBuffer[v27 + 2] << 8)) << 8);
      v29 = v27 + 4;
      v30 = pAltStream->Stream.DataSize - (v27 + 4);
      rid.Id = v28;
      pAltStream->Stream.Pos = v29;
      pAltStream->Stream.UnusedBits = 0;
      if ( v30 < 4 )
        Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 4);
      v31 = pAltStream->Stream.Pos;
      v32 = pAltStream->Stream.pBuffer[v31]
          | ((pAltStream->Stream.pBuffer[v31 + 1] | (*(unsigned __int16 *)&pAltStream->Stream.pBuffer[v31 + 2] << 8)) << 8);
      v33 = v31 + 4;
      v34 = pAltStream->Stream.DataSize - (v31 + 4);
      v85 = *(float *)&v32;
      pAltStream->Stream.Pos = v33;
      pAltStream->Stream.UnusedBits = 0;
      if ( v34 < 4 )
        Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 4);
      v35 = pAltStream->Stream.Pos;
      v36 = pAltStream->Stream.pBuffer[v35]
          | ((pAltStream->Stream.pBuffer[v35 + 1] | (*(unsigned __int16 *)&pAltStream->Stream.pBuffer[v35 + 2] << 8)) << 8);
      v37 = v35 + 4;
      v38 = pAltStream->Stream.DataSize - (v35 + 4);
      v86 = *(float *)&v36;
      pAltStream->Stream.Pos = v37;
      pAltStream->Stream.UnusedBits = 0;
      if ( v38 < 4 )
        Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 4);
      v39 = pAltStream->Stream.Pos;
      v40 = pAltStream->Stream.pBuffer[v39]
          | ((pAltStream->Stream.pBuffer[v39 + 1] | (*(unsigned __int16 *)&pAltStream->Stream.pBuffer[v39 + 2] << 8)) << 8);
      v41 = v39 + 4;
      v42 = pAltStream->Stream.DataSize - (v39 + 4);
      v87 = *(float *)&v40;
      pAltStream->Stream.Pos = v41;
      pAltStream->Stream.UnusedBits = 0;
      if ( v42 < 4 )
        Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 4);
      v43 = pAltStream->Stream.Pos;
      v44 = pAltStream->Stream.pBuffer[v43]
          | ((pAltStream->Stream.pBuffer[v43 + 1] | (*(unsigned __int16 *)&pAltStream->Stream.pBuffer[v43 + 2] << 8)) << 8);
      v45 = v43 + 4;
      v46 = pAltStream->Stream.DataSize - (v43 + 4);
      v88 = *(float *)&v44;
      pAltStream->Stream.Pos = v45;
      pAltStream->Stream.UnusedBits = 0;
      if ( v46 < 4 )
        Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 4);
      v47 = pAltStream->Stream.Pos;
      v48 = pAltStream->Stream.pBuffer[v47]
          | ((pAltStream->Stream.pBuffer[v47 + 1] | (*(unsigned __int16 *)&pAltStream->Stream.pBuffer[v47 + 2] << 8)) << 8);
      pAltStream->Stream.Pos = v47 + 4;
      v89 = *(float *)&v48;
      if ( Scaleform::GFx::Stream::IsVerboseParse(&pAltStream->Stream) )
      {
        Scaleform::Render::JPEG::JPEGRwSource::TermSource(v49);
        Scaleform::Render::JPEG::JPEGRwSource::TermSource(v50);
      }
      __that.UvBounds.x1 = 0.0;
      __that.UvBounds.y1 = 0.0;
      __that.RefCount = 1;
      __that.UvBounds.x2 = 0.0;
      __that.__vftable = (Scaleform::Render::TextureGlyph_vtbl *)&Scaleform::Render::TextureGlyph::`vftable';
      __that.UvBounds.y2 = 0.0;
      __that.pImage.pObject = 0;
      __that.BindIndex = -1;
      if ( result.HType == RH_Index )
      {
        __that.BindIndex = result.BindIndex;
      }
      else if ( result.HType == RH_Pointer
             && result.BindIndex
             && ((*(int (__thiscall **)(unsigned int))(*(_DWORD *)result.BindIndex + 8))(result.BindIndex) & 0xFF00) == 0x100 )
      {
        v51 = *(Scaleform::Render::Image **)(result.HType == RH_Pointer ? result.BindIndex + 0xC : 12);
        if ( v51 )
          v51->AddRef(*(struct Scaleform::Render::Image **)(result.HType == RH_Pointer ? result.BindIndex + 0xC : 12));
        if ( __that.pImage.pObject )
          __that.pImage.pObject->Release(__that.pImage.pObject);
        __that.pImage.pObject = v51;
      }
      __that.UvBounds.x1 = *(float *)&rid.Id;
      v52 = pheapAddr.Size + 1;
      __that.UvBounds.y1 = v85;
      __that.UvBounds.x2 = v86;
      __that.UvBounds.y2 = v87;
      __that.UvOrigin.x = v88;
      __that.UvOrigin.y = v89;
      if ( pheapAddr.Size + 1 >= pheapAddr.Size )
      {
        if ( v52 >= pheapAddr.Policy.Capacity )
          Scaleform::ArrayDataBase<Scaleform::Render::TextureGlyph,Scaleform::AllocatorGH<Scaleform::Render::TextureGlyph,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            &pheapAddr,
            &pheapAddr,
            v52 + (v52 >> 2));
      }
      else
      {
        v53 = &pheapAddr.Data[pheapAddr.Size - 1];
        v89 = NAN;
        do
        {
          ((void (__thiscall *)(Scaleform::Render::TextureGlyph *, _DWORD))v53->~Scaleform::Render::TextureGlyph)(
            v53,
            0);
          --v53;
          --LODWORD(v89);
        }
        while ( v89 != 0.0 );
        if ( v52 < pheapAddr.Policy.Capacity >> 1 )
          Scaleform::ArrayDataBase<Scaleform::Render::TextureGlyph,Scaleform::AllocatorGH<Scaleform::Render::TextureGlyph,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            &pheapAddr,
            &pheapAddr,
            v52);
      }
      pheapAddr.Size = v52;
      if ( &pheapAddr.Data[v52] != (Scaleform::Render::TextureGlyph *)48 )
        Scaleform::Render::TextureGlyph::TextureGlyph(&pheapAddr.Data[v52 - 1], &__that);
      if ( __that.pImage.pObject )
        __that.pImage.pObject->Release(__that.pImage.pObject);
      Scaleform::RefCountImplCore::~RefCountImplCore(&__that.Scaleform::RefCountBase<Scaleform::Render::TextureGlyph,2>);
      ++v90;
    }
    while ( v90 < v91 );
  }
  v54 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
  pAltStream->Stream.UnusedBits = 0;
  if ( v54 < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
  v55 = pAltStream->Stream.Pos;
  LODWORD(v56) = *(unsigned __int16 *)&pAltStream->Stream.pBuffer[v55];
  pAltStream->Stream.Pos = v55 + 2;
  if ( Scaleform::GFx::Stream::IsVerboseParse(&pAltStream->Stream) )
    Scaleform::Render::JPEG::JPEGRwSource::TermSource(v57);
  if ( v56 != 0.0 )
  {
    v89 = v56;
    do
    {
      v58 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
      pAltStream->Stream.UnusedBits = 0;
      if ( v58 < 2 )
        Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
      v59 = pAltStream->Stream.Pos;
      v60 = *(_WORD *)&pAltStream->Stream.pBuffer[v59];
      pAltStream->Stream.Pos = v59 + 2;
      FontData = Scaleform::GFx::MovieDataDef::LoadTaskData::GetFontData(
                   p->pLoadData.pObject,
                   (Scaleform::GFx::ResourceId)v60);
      if ( !FontData )
        goto LABEL_89;
      v62 = (int)FontData->GetTextureGlyphData(FontData);
      if ( v62 )
        ++*(_DWORD *)(v62 + 4);
      v63 = (Scaleform::GFx::TextureGlyphData *)v62;
      if ( !v62 )
      {
        v64 = (Scaleform::GFx::TextureGlyphData *)pHeap->Alloc(pHeap, 44u, 0);
        if ( v64 )
        {
          v65 = FontData->GetGlyphShapeCount(FontData);
          Scaleform::GFx::TextureGlyphData::TextureGlyphData(v64, v65, 1);
        }
        else
        {
          v66 = 0;
        }
        v63 = v66;
        if ( !v66 )
          goto LABEL_76;
        v67 = v97;
        v66->PackTextureConfig.NominalSize = v96;
        v68 = *(_DWORD *)targetWidth;
        v66->PackTextureConfig.PadPixels = v67;
        v69 = v99;
        v66->PackTextureConfig.TextureWidth = v68;
        v66->PackTextureConfig.TextureHeight = v69;
        FontData->SetTextureGlyphData(FontData, v66);
      }
      Scaleform::GFx::TextureGlyphData::AddTexture(v63, v93, &result);
LABEL_76:
      v70 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
      pAltStream->Stream.UnusedBits = 0;
      if ( v70 < 2 )
        Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
      v71 = pAltStream->Stream.Pos;
      v72 = *(_WORD *)&pAltStream->Stream.pBuffer[v71];
      v57 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v72;
      pAltStream->Stream.Pos = v71 + 2;
      if ( v72 )
      {
        v90 = v72;
        do
        {
          v73 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
          pAltStream->Stream.UnusedBits = 0;
          if ( v73 < 2 )
            Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
          v74 = pAltStream->Stream.Pos;
          v75 = *(_WORD *)&pAltStream->Stream.pBuffer[v74];
          v74 += 2;
          v76 = pAltStream->Stream.DataSize - v74;
          pAltStream->Stream.Pos = v74;
          v77 = v75;
          pAltStream->Stream.UnusedBits = 0;
          if ( v76 < 2 )
            Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
          v78 = pAltStream->Stream.Pos;
          v57 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)*(unsigned __int16 *)&pAltStream->Stream.pBuffer[v78];
          pAltStream->Stream.Pos = v78 + 2;
          if ( v63 )
            Scaleform::GFx::TextureGlyphData::AddTextureGlyph(v63, v77, &pheapAddr.Data[(unsigned __int16)v57]);
          --v90;
        }
        while ( v90 );
      }
      if ( v63 )
        Scaleform::RefCountNTSImpl::Release(v63);
LABEL_89:
      --LODWORD(v89);
    }
    while ( v89 != 0.0 );
  }
  Scaleform::Render::JPEG::JPEGRwSource::TermSource(v57);
  Data = pheapAddr.Data;
  v80 = &pheapAddr.Data[pheapAddr.Size - 1];
  if ( pheapAddr.Size )
  {
    Size = pheapAddr.Size;
    do
    {
      ((void (__thiscall *)(Scaleform::Render::TextureGlyph *, _DWORD))v80->~Scaleform::Render::TextureGlyph)(v80, 0);
      --v80;
      --Size;
    }
    while ( Size );
  }
  if ( Data )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)Data);
  if ( result.HType == RH_Pointer && result.BindIndex )
    Scaleform::GFx::Resource::Release(result.pResource);
  v82 = (void *)(pstr.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((pstr.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v82);
}
