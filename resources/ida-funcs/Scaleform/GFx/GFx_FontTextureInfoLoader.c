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
  int v15; // ebx
  int v16; // edx
  unsigned int v17; // eax
  int v18; // edx
  int v19; // ecx
  unsigned int v20; // eax
  int v21; // edx
  int v22; // ecx
  unsigned int v23; // eax
  int v24; // edi
  unsigned int v25; // ebx
  int v26; // ecx
  unsigned int v27; // ecx
  int v28; // edx
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
  Scaleform::Render::Image *v49; // edi
  unsigned int v50; // edi
  Scaleform::Render::TextureGlyph *v51; // ebx
  int v52; // ecx
  unsigned int v53; // eax
  float v54; // edi
  int v55; // edx
  unsigned int v56; // eax
  unsigned __int16 v57; // cx
  Scaleform::Render::Font *FontData; // edi
  int v59; // eax
  Scaleform::GFx::TextureGlyphData *v60; // ebx
  Scaleform::GFx::TextureGlyphData *v61; // ebx
  unsigned int v62; // eax
  Scaleform::GFx::TextureGlyphData *v63; // eax
  int v64; // edx
  int v65; // ecx
  int v66; // edx
  int v67; // eax
  unsigned int v68; // eax
  unsigned __int16 v69; // dx
  int v70; // edx
  unsigned int v71; // eax
  unsigned __int16 v72; // cx
  int v73; // edx
  unsigned int v74; // edi
  unsigned int v75; // eax
  unsigned __int16 v76; // cx
  Scaleform::Render::TextureGlyph *Data; // ebx
  Scaleform::Render::TextureGlyph *v78; // esi
  unsigned int Size; // edi
  void *v80; // esi
  Scaleform::String pstr; // [esp+30h] [ebp-80h] BYREF
  float v82; // [esp+34h] [ebp-7Ch]
  float v83; // [esp+38h] [ebp-78h]
  float v84; // [esp+3Ch] [ebp-74h]
  float v85; // [esp+40h] [ebp-70h]
  float v86; // [esp+44h] [ebp-6Ch]
  float v87; // [esp+48h] [ebp-68h]
  unsigned int v88; // [esp+4Ch] [ebp-64h]
  unsigned int v89; // [esp+50h] [ebp-60h]
  Scaleform::MemoryHeap *pHeap; // [esp+54h] [ebp-5Ch]
  Scaleform::GFx::ResourceId v91; // [esp+58h] [ebp-58h]
  Scaleform::GFx::ResourceHandle textureId; // [esp+5Ch] [ebp-54h] BYREF
  Scaleform::ArrayDataBase<Scaleform::Render::TextureGlyph,Scaleform::AllocatorGH<Scaleform::Render::TextureGlyph,2>,Scaleform::ArrayDefaultPolicy> pheapAddr; // [esp+64h] [ebp-4Ch] BYREF
  int v94; // [esp+70h] [ebp-40h]
  int v95; // [esp+74h] [ebp-3Ch]
  int v96; // [esp+78h] [ebp-38h]
  int v97; // [esp+7Ch] [ebp-34h]
  Scaleform::Render::TextureGlyph __that; // [esp+80h] [ebp-30h] BYREF

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
  v91.Id = v5;
  pAltStream->Stream.Pos = v6;
  pAltStream->Stream.UnusedBits = 0;
  if ( v7 < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
  v8 = pAltStream->Stream.Pos;
  LODWORD(v82) = *(unsigned __int16 *)&pAltStream->Stream.pBuffer[v8];
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
  v96 = v11;
  pAltStream->Stream.UnusedBits = 0;
  if ( v12 < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
  v13 = pAltStream->Stream.Pos;
  v14 = *(_WORD *)&pAltStream->Stream.pBuffer[v13];
  v13 += 2;
  v15 = v14;
  v16 = pAltStream->Stream.DataSize - v13;
  pAltStream->Stream.Pos = v13;
  v97 = v14;
  pAltStream->Stream.UnusedBits = 0;
  if ( v16 < 1 )
    Scaleform::GFx::Stream::PopulateBuffer1(&pAltStream->Stream);
  v17 = pAltStream->Stream.Pos;
  v18 = pAltStream->Stream.pBuffer[v17++];
  v19 = pAltStream->Stream.DataSize - v17;
  pAltStream->Stream.Pos = v17;
  v95 = v18;
  pAltStream->Stream.UnusedBits = 0;
  if ( v19 < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
  v20 = pAltStream->Stream.Pos;
  v21 = *(unsigned __int16 *)&pAltStream->Stream.pBuffer[v20];
  pAltStream->Stream.Pos = v20 + 2;
  v94 = v21;
  if ( (unsigned __int8)Scaleform::GFx::Stream::IsVerboseParse(&pAltStream->Stream) )
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(
      &pAltStream->Stream,
      "  FontTextureInfo: tagInfo.TagType = %d, id = 0x%X, fmt = %d, name = '%s', w = %d, h = %d\n",
      tagInfo->TagType,
      v5,
      LOWORD(v82),
      (const char *)((pstr.HeapTypeBits & 0xFFFFFFFC) + 8),
      v96,
      v15);
  Scaleform::GFx::GFx_CreateImageFileResourceHandle(
    &textureId,
    p,
    (Scaleform::GFx::ResourceId)v5,
    (const __m128i *)((pstr.HeapTypeBits & 0xFFFFFFFC) + 8),
    (const __m128i *)uri,
    LOWORD(v82),
    v96,
    v15);
  v22 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
  memset(&pheapAddr, 0, sizeof(pheapAddr));
  pAltStream->Stream.UnusedBits = 0;
  if ( v22 < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
  v23 = pAltStream->Stream.Pos;
  v24 = *(unsigned __int16 *)&pAltStream->Stream.pBuffer[v23];
  pAltStream->Stream.Pos = v23 + 2;
  v89 = v24;
  if ( (unsigned __int8)Scaleform::GFx::Stream::IsVerboseParse(&pAltStream->Stream) )
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(
      &pAltStream->Stream,
      "  PadPixels = %d, nominal glyph size = %d, numTexGlyphs = %d\n",
      v95,
      v94,
      v24);
  v25 = 0;
  v88 = 0;
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
      v82 = *(float *)&v28;
      pAltStream->Stream.Pos = v29;
      pAltStream->Stream.UnusedBits = 0;
      if ( v30 < 4 )
        Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 4);
      v31 = pAltStream->Stream.Pos;
      v32 = pAltStream->Stream.pBuffer[v31]
          | ((pAltStream->Stream.pBuffer[v31 + 1] | (*(unsigned __int16 *)&pAltStream->Stream.pBuffer[v31 + 2] << 8)) << 8);
      v33 = v31 + 4;
      v34 = pAltStream->Stream.DataSize - (v31 + 4);
      v83 = *(float *)&v32;
      pAltStream->Stream.Pos = v33;
      pAltStream->Stream.UnusedBits = 0;
      if ( v34 < 4 )
        Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 4);
      v35 = pAltStream->Stream.Pos;
      v36 = pAltStream->Stream.pBuffer[v35]
          | ((pAltStream->Stream.pBuffer[v35 + 1] | (*(unsigned __int16 *)&pAltStream->Stream.pBuffer[v35 + 2] << 8)) << 8);
      v37 = v35 + 4;
      v38 = pAltStream->Stream.DataSize - (v35 + 4);
      v84 = *(float *)&v36;
      pAltStream->Stream.Pos = v37;
      pAltStream->Stream.UnusedBits = 0;
      if ( v38 < 4 )
        Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 4);
      v39 = pAltStream->Stream.Pos;
      v40 = pAltStream->Stream.pBuffer[v39]
          | ((pAltStream->Stream.pBuffer[v39 + 1] | (*(unsigned __int16 *)&pAltStream->Stream.pBuffer[v39 + 2] << 8)) << 8);
      v41 = v39 + 4;
      v42 = pAltStream->Stream.DataSize - (v39 + 4);
      v85 = *(float *)&v40;
      pAltStream->Stream.Pos = v41;
      pAltStream->Stream.UnusedBits = 0;
      if ( v42 < 4 )
        Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 4);
      v43 = pAltStream->Stream.Pos;
      v44 = pAltStream->Stream.pBuffer[v43]
          | ((pAltStream->Stream.pBuffer[v43 + 1] | (*(unsigned __int16 *)&pAltStream->Stream.pBuffer[v43 + 2] << 8)) << 8);
      v45 = v43 + 4;
      v46 = pAltStream->Stream.DataSize - (v43 + 4);
      v86 = *(float *)&v44;
      pAltStream->Stream.Pos = v45;
      pAltStream->Stream.UnusedBits = 0;
      if ( v46 < 4 )
        Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 4);
      v47 = pAltStream->Stream.Pos;
      v48 = pAltStream->Stream.pBuffer[v47]
          | ((pAltStream->Stream.pBuffer[v47 + 1] | (*(unsigned __int16 *)&pAltStream->Stream.pBuffer[v47 + 2] << 8)) << 8);
      pAltStream->Stream.Pos = v47 + 4;
      v87 = *(float *)&v48;
      if ( (unsigned __int8)Scaleform::GFx::Stream::IsVerboseParse(&pAltStream->Stream) )
      {
        Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(
          &pAltStream->Stream,
          "  TEXGLYPH[%d]: uvBnd.x1 = %f, uvBnd.y1 = %f, uvBnd.x2 = %f, uvBnd.y2 = %f\n",
          v25,
          v82,
          v83,
          v84,
          v85);
        Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(
          &pAltStream->Stream,
          "                uvOrigin.x = %f, uvOrigin.y = %f\n",
          v86,
          v87);
      }
      __that.UvBounds.x1 = 0.0;
      __that.UvBounds.y1 = 0.0;
      __that.RefCount = 1;
      __that.UvBounds.x2 = 0.0;
      __that.__vftable = (Scaleform::Render::TextureGlyph_vtbl *)&Scaleform::Render::TextureGlyph::`vftable';
      __that.UvBounds.y2 = 0.0;
      __that.pImage.pObject = 0;
      __that.BindIndex = -1;
      if ( textureId.HType == RH_Index )
      {
        __that.BindIndex = textureId.BindIndex;
      }
      else if ( textureId.HType == RH_Pointer
             && textureId.BindIndex
             && ((*(int (__thiscall **)(unsigned int))(*(_DWORD *)textureId.BindIndex + 8))(textureId.BindIndex) & 0xFF00) == 0x100 )
      {
        v49 = *(Scaleform::Render::Image **)(textureId.HType == RH_Pointer ? textureId.BindIndex + 0xC : 12);
        if ( v49 )
          v49->AddRef(*(struct Scaleform::Render::Image **)(textureId.HType == RH_Pointer
                                                          ? textureId.BindIndex + 0xC
                                                          : 12));
        if ( __that.pImage.pObject )
          __that.pImage.pObject->Release(__that.pImage.pObject);
        __that.pImage.pObject = v49;
      }
      __that.UvBounds.x1 = v82;
      v50 = pheapAddr.Size + 1;
      __that.UvBounds.y1 = v83;
      __that.UvBounds.x2 = v84;
      __that.UvBounds.y2 = v85;
      __that.UvOrigin.x = v86;
      __that.UvOrigin.y = v87;
      if ( pheapAddr.Size + 1 >= pheapAddr.Size )
      {
        if ( v50 >= pheapAddr.Policy.Capacity )
          Scaleform::ArrayDataBase<Scaleform::Render::TextureGlyph,Scaleform::AllocatorGH<Scaleform::Render::TextureGlyph,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            &pheapAddr,
            &pheapAddr,
            v50 + (v50 >> 2));
      }
      else
      {
        v51 = &pheapAddr.Data[pheapAddr.Size - 1];
        v87 = NAN;
        do
        {
          ((void (__thiscall *)(Scaleform::Render::TextureGlyph *, _DWORD))v51->~Scaleform::Render::TextureGlyph)(
            v51,
            0);
          --v51;
          --LODWORD(v87);
        }
        while ( v87 != 0.0 );
        if ( v50 < pheapAddr.Policy.Capacity >> 1 )
          Scaleform::ArrayDataBase<Scaleform::Render::TextureGlyph,Scaleform::AllocatorGH<Scaleform::Render::TextureGlyph,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            &pheapAddr,
            &pheapAddr,
            v50);
      }
      pheapAddr.Size = v50;
      if ( &pheapAddr.Data[v50] != (Scaleform::Render::TextureGlyph *)48 )
        Scaleform::Render::TextureGlyph::TextureGlyph(&pheapAddr.Data[v50 - 1], &__that);
      if ( __that.pImage.pObject )
        __that.pImage.pObject->Release(__that.pImage.pObject);
      Scaleform::RefCountImplCore::~RefCountImplCore(&__that.Scaleform::RefCountBase<Scaleform::Render::TextureGlyph,2>);
      v25 = v88 + 1;
      v88 = v25;
    }
    while ( v25 < v89 );
  }
  v52 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
  pAltStream->Stream.UnusedBits = 0;
  if ( v52 < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
  v53 = pAltStream->Stream.Pos;
  LODWORD(v54) = *(unsigned __int16 *)&pAltStream->Stream.pBuffer[v53];
  pAltStream->Stream.Pos = v53 + 2;
  if ( (unsigned __int8)Scaleform::GFx::Stream::IsVerboseParse(&pAltStream->Stream) )
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(&pAltStream->Stream, "  NumFonts = %d\n", v54);
  if ( v54 != 0.0 )
  {
    v87 = v54;
    do
    {
      v55 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
      pAltStream->Stream.UnusedBits = 0;
      if ( v55 < 2 )
        Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
      v56 = pAltStream->Stream.Pos;
      v57 = *(_WORD *)&pAltStream->Stream.pBuffer[v56];
      pAltStream->Stream.Pos = v56 + 2;
      FontData = Scaleform::GFx::MovieDataDef::LoadTaskData::GetFontData(
                   p->pLoadData.pObject,
                   (Scaleform::GFx::ResourceId)v57);
      if ( !FontData )
        goto LABEL_89;
      v59 = (int)FontData->GetTextureGlyphData(FontData);
      if ( v59 )
        ++*(_DWORD *)(v59 + 4);
      v60 = (Scaleform::GFx::TextureGlyphData *)v59;
      if ( !v59 )
      {
        v61 = (Scaleform::GFx::TextureGlyphData *)pHeap->Alloc(pHeap, 44u, 0);
        if ( v61 )
        {
          v62 = FontData->GetGlyphShapeCount(FontData);
          Scaleform::GFx::TextureGlyphData::TextureGlyphData(v61, v62, 1);
        }
        else
        {
          v63 = 0;
        }
        v60 = v63;
        if ( !v63 )
          goto LABEL_76;
        v64 = v95;
        v63->PackTextureConfig.NominalSize = v94;
        v65 = v96;
        v63->PackTextureConfig.PadPixels = v64;
        v66 = v97;
        v63->PackTextureConfig.TextureWidth = v65;
        v63->PackTextureConfig.TextureHeight = v66;
        FontData->SetTextureGlyphData(FontData, v63);
      }
      Scaleform::GFx::TextureGlyphData::AddTexture(v60, v91, &textureId);
LABEL_76:
      v67 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
      pAltStream->Stream.UnusedBits = 0;
      if ( v67 < 2 )
        Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
      v68 = pAltStream->Stream.Pos;
      v69 = *(_WORD *)&pAltStream->Stream.pBuffer[v68];
      pAltStream->Stream.Pos = v68 + 2;
      if ( v69 )
      {
        v88 = v69;
        do
        {
          v70 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
          pAltStream->Stream.UnusedBits = 0;
          if ( v70 < 2 )
            Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
          v71 = pAltStream->Stream.Pos;
          v72 = *(_WORD *)&pAltStream->Stream.pBuffer[v71];
          v71 += 2;
          v73 = pAltStream->Stream.DataSize - v71;
          pAltStream->Stream.Pos = v71;
          v74 = v72;
          pAltStream->Stream.UnusedBits = 0;
          if ( v73 < 2 )
            Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
          v75 = pAltStream->Stream.Pos;
          v76 = *(_WORD *)&pAltStream->Stream.pBuffer[v75];
          pAltStream->Stream.Pos = v75 + 2;
          if ( v60 )
            Scaleform::GFx::TextureGlyphData::AddTextureGlyph(v60, v74, &pheapAddr.Data[v76]);
          --v88;
        }
        while ( v88 );
      }
      if ( v60 )
        Scaleform::RefCountNTSImpl::Release(v60);
LABEL_89:
      --LODWORD(v87);
    }
    while ( v87 != 0.0 );
  }
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(&pAltStream->Stream, "\n");
  Data = pheapAddr.Data;
  v78 = &pheapAddr.Data[pheapAddr.Size - 1];
  if ( pheapAddr.Size )
  {
    Size = pheapAddr.Size;
    do
    {
      ((void (__thiscall *)(Scaleform::Render::TextureGlyph *, _DWORD))v78->~Scaleform::Render::TextureGlyph)(v78, 0);
      --v78;
      --Size;
    }
    while ( Size );
  }
  if ( Data )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)Data);
  if ( textureId.HType == RH_Pointer && textureId.BindIndex )
    Scaleform::GFx::Resource::Release(textureId.pResource);
  v80 = (void *)(pstr.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((pstr.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v80);
}
