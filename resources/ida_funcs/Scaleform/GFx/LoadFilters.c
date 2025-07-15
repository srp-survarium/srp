unsigned int __cdecl Scaleform::GFx::LoadFilters<Scaleform::GFx::StreamContext>(
        Scaleform::GFx::StreamContext *ps,
        Scaleform::Render::FilterSet *filters)
{
  unsigned int CurByteIndex; // eax
  const unsigned __int8 *pData; // ecx
  unsigned __int8 v5; // dl
  unsigned int v6; // eax
  const unsigned __int8 *v7; // edi
  unsigned __int8 v8; // cl
  unsigned int v9; // eax
  unsigned int v10; // ebp
  Scaleform::Render::ShadowFilter *v11; // eax
  Scaleform::GFx::Resource *v12; // eax
  Scaleform::Render::BlurFilter *v13; // eax
  Scaleform::GFx::Resource *v14; // eax
  Scaleform::Render::GlowFilter *v15; // eax
  Scaleform::GFx::Resource *v16; // eax
  Scaleform::Render::BevelFilter *v17; // eax
  Scaleform::GFx::Resource *v18; // eax
  unsigned __int8 v19; // cl
  unsigned int v20; // eax
  int v21; // edx
  Scaleform::Render::ColorMatrixFilter *v22; // eax
  Scaleform::GFx::Resource *v23; // eax
  Scaleform::GFx::Resource *v24; // edi
  unsigned int i; // eax
  const unsigned __int8 *v26; // ecx
  float v27; // edx
  const unsigned __int8 *v28; // ecx
  float v29; // edx
  const unsigned __int8 *v30; // ecx
  float v31; // edx
  const unsigned __int8 *v32; // ecx
  float v33; // edx
  const unsigned __int8 *v34; // ecx
  float v35; // edx
  const unsigned __int8 *v36; // ecx
  float v37; // edx
  const unsigned __int8 *v38; // ecx
  float v39; // edx
  const unsigned __int8 *v40; // ecx
  float v41; // edx
  const unsigned __int8 *v42; // ecx
  float v43; // edx
  const unsigned __int8 *v44; // ecx
  int v45; // edx
  unsigned __int8 v46; // cl
  unsigned int CurBitIndex; // eax
  unsigned int v48; // ecx
  float v50; // [esp+20h] [ebp-40h]
  Scaleform::GFx::Resource *filter; // [esp+24h] [ebp-3Ch]
  Scaleform::MemoryHeap *filtersHeap; // [esp+28h] [ebp-38h]
  unsigned int numFilters; // [esp+2Ch] [ebp-34h]
  float distance; // [esp+30h] [ebp-30h] BYREF
  float angle; // [esp+34h] [ebp-2Ch] BYREF
  unsigned int numBytes; // [esp+38h] [ebp-28h]
  Scaleform::Render::BlurFilterParams params; // [esp+3Ch] [ebp-24h] BYREF
  unsigned __int8 filterCount; // [esp+64h] [ebp+4h]

  if ( ps->CurBitIndex )
    ++ps->CurByteIndex;
  CurByteIndex = ps->CurByteIndex;
  pData = ps->pData;
  angle = 0.0;
  ps->CurBitIndex = 0;
  distance = 0.0;
  v5 = pData[CurByteIndex];
  ps->CurByteIndex = CurByteIndex + 1;
  filterCount = v5;
  numFilters = 0;
  if ( filters )
    filtersHeap = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, filters);
  else
    filtersHeap = Scaleform::Memory::pGlobalHeap;
  if ( !filterCount )
    return 0;
  do
  {
    --filterCount;
    if ( ps->CurBitIndex )
      ++ps->CurByteIndex;
    v6 = ps->CurByteIndex;
    v7 = ps->pData;
    ps->CurBitIndex = 0;
    v8 = v7[v6];
    params.BlurX = 100.0;
    params.BlurY = 100.0;
    v9 = v6 + 1;
    params.Offset.x = 0.0;
    v10 = 0;
    params.Offset.y = 0.0;
    ps->CurByteIndex = v9;
    numBytes = 0;
    params.Strength = 1.0;
    filter = 0;
    params.Mode = 0;
    params.Passes = 1;
    *(_WORD *)&params.Colors[0].Channels.Green = 0;
    params.Colors[0].Channels.Blue = 0;
    params.Colors[0].Channels.Alpha = -1;
    *(_WORD *)&params.Colors[1].Channels.Green = 0;
    params.Colors[1].Channels.Blue = 0;
    params.Colors[1].Channels.Alpha = 0;
    switch ( v8 )
    {
      case 0u:
        Scaleform::GFx::ReadBlurFilter<Scaleform::GFx::StreamContext>(
          ps,
          &params,
          &angle,
          &distance,
          13,
          Filter_Shadow,
          0x1Fu);
        v11 = (Scaleform::Render::ShadowFilter *)filtersHeap->Alloc(filtersHeap, 60u, 0);
        if ( !v11 )
          goto LABEL_12;
        Scaleform::Render::ShadowFilter::ShadowFilter(v11, &params, angle, distance);
        filter = v12;
        break;
      case 1u:
        Scaleform::GFx::ReadBlurFilter<Scaleform::GFx::StreamContext>(ps, &params, 0, 0, 0, Filter_Blur, 0xF8u);
        v13 = (Scaleform::Render::BlurFilter *)filtersHeap->Alloc(filtersHeap, 60u, 0);
        if ( !v13 )
          goto LABEL_12;
        Scaleform::Render::BlurFilter::BlurFilter(v13, &params);
        filter = v14;
        break;
      case 2u:
        Scaleform::GFx::ReadBlurFilter<Scaleform::GFx::StreamContext>(ps, &params, 0, 0, 9, Filter_Glow, 0x1Fu);
        v15 = (Scaleform::Render::GlowFilter *)filtersHeap->Alloc(filtersHeap, 60u, 0);
        if ( !v15 )
          goto LABEL_12;
        Scaleform::Render::GlowFilter::GlowFilter(v15, &params);
        filter = v16;
        break;
      case 3u:
        Scaleform::GFx::ReadBlurFilter<Scaleform::GFx::StreamContext>(
          ps,
          &params,
          &angle,
          &distance,
          15,
          Filter_Bevel,
          0xFu);
        v17 = (Scaleform::Render::BevelFilter *)filtersHeap->Alloc(filtersHeap, 60u, 0);
        if ( v17 )
        {
          Scaleform::Render::BevelFilter::BevelFilter(v17, &params, angle, distance);
          filter = v18;
        }
        else
        {
LABEL_12:
          filter = 0;
        }
        break;
      case 4u:
      case 7u:
        ps->CurBitIndex = 0;
        v46 = v7[v9];
        ps->CurByteIndex = v9 + 1;
        v10 = 5 * v46 + 19;
        break;
      case 5u:
        ps->CurBitIndex = 0;
        v19 = v7[v9];
        v20 = v9 + 1;
        ps->CurByteIndex = v20;
        ps->CurBitIndex = 0;
        v21 = v19 * v7[v20];
        ps->CurByteIndex = v20 + 1;
        v10 = 4 * v21 + 13;
        break;
      case 6u:
        v22 = (Scaleform::Render::ColorMatrixFilter *)filtersHeap->Alloc(filtersHeap, 96u, 0);
        if ( v22 )
        {
          Scaleform::Render::ColorMatrixFilter::ColorMatrixFilter(v22);
          v24 = v23;
          if ( v23 )
            Scaleform::RefCountImpl::AddRef(v23);
        }
        else
        {
          v24 = 0;
        }
        filter = v24;
        for ( i = 0; i < 0x14; i += 10 )
        {
          if ( ps->CurBitIndex )
            ++ps->CurByteIndex;
          v26 = &ps->pData[ps->CurByteIndex];
          ps->CurBitIndex = 0;
          LODWORD(v27) = *v26 | ((v26[1] | (*((unsigned __int16 *)v26 + 1) << 8)) << 8);
          ps->CurByteIndex += 4;
          *((float *)&v24[1].RefCount.Value + `Scaleform::GFx::LoadFilters<Scaleform::GFx::StreamContext>'::`9'::Index[i]) = v27;
          if ( ps->CurBitIndex )
            ++ps->CurByteIndex;
          v28 = &ps->pData[ps->CurByteIndex];
          ps->CurBitIndex = 0;
          LODWORD(v29) = *v28 | ((v28[1] | (*((unsigned __int16 *)v28 + 1) << 8)) << 8);
          ps->CurByteIndex += 4;
          *((float *)&v24[1].RefCount.Value + (unsigned __int8)byte_85E439[i]) = v29;
          if ( ps->CurBitIndex )
            ++ps->CurByteIndex;
          v30 = &ps->pData[ps->CurByteIndex];
          ps->CurBitIndex = 0;
          LODWORD(v31) = *v30 | ((v30[1] | (*((unsigned __int16 *)v30 + 1) << 8)) << 8);
          ps->CurByteIndex += 4;
          *((float *)&v24[1].RefCount.Value + (unsigned __int8)byte_85E43A[i]) = v31;
          if ( ps->CurBitIndex )
            ++ps->CurByteIndex;
          v32 = &ps->pData[ps->CurByteIndex];
          ps->CurBitIndex = 0;
          LODWORD(v33) = *v32 | ((v32[1] | (*((unsigned __int16 *)v32 + 1) << 8)) << 8);
          ps->CurByteIndex += 4;
          *((float *)&v24[1].RefCount.Value + (unsigned __int8)byte_85E43B[i]) = v33;
          if ( ps->CurBitIndex )
            ++ps->CurByteIndex;
          v34 = &ps->pData[ps->CurByteIndex];
          ps->CurBitIndex = 0;
          LODWORD(v35) = *v34 | ((v34[1] | (*((unsigned __int16 *)v34 + 1) << 8)) << 8);
          ps->CurByteIndex += 4;
          *((float *)&v24[1].RefCount.Value + (unsigned __int8)byte_85E43C[i]) = v35;
          if ( ps->CurBitIndex )
            ++ps->CurByteIndex;
          v36 = &ps->pData[ps->CurByteIndex];
          ps->CurBitIndex = 0;
          LODWORD(v37) = *v36 | ((v36[1] | (*((unsigned __int16 *)v36 + 1) << 8)) << 8);
          ps->CurByteIndex += 4;
          *((float *)&v24[1].RefCount.Value + (unsigned __int8)byte_85E43D[i]) = v37;
          if ( ps->CurBitIndex )
            ++ps->CurByteIndex;
          v38 = &ps->pData[ps->CurByteIndex];
          ps->CurBitIndex = 0;
          LODWORD(v39) = *v38 | ((v38[1] | (*((unsigned __int16 *)v38 + 1) << 8)) << 8);
          ps->CurByteIndex += 4;
          *((float *)&v24[1].RefCount.Value + (unsigned __int8)byte_85E43E[i]) = v39;
          if ( ps->CurBitIndex )
            ++ps->CurByteIndex;
          v40 = &ps->pData[ps->CurByteIndex];
          ps->CurBitIndex = 0;
          LODWORD(v41) = *v40 | ((v40[1] | (*((unsigned __int16 *)v40 + 1) << 8)) << 8);
          ps->CurByteIndex += 4;
          *((float *)&v24[1].RefCount.Value + (unsigned __int8)byte_85E43F[i]) = v41;
          if ( ps->CurBitIndex )
            ++ps->CurByteIndex;
          v42 = &ps->pData[ps->CurByteIndex];
          ps->CurBitIndex = 0;
          LODWORD(v43) = *v42 | ((v42[1] | (*((unsigned __int16 *)v42 + 1) << 8)) << 8);
          ps->CurByteIndex += 4;
          *((float *)&v24[1].RefCount.Value + (unsigned __int8)byte_85E440[i]) = v43;
          if ( ps->CurBitIndex )
            ++ps->CurByteIndex;
          v44 = &ps->pData[ps->CurByteIndex];
          ps->CurBitIndex = 0;
          LODWORD(v50) = *v44 | ((v44[1] | (*((unsigned __int16 *)v44 + 1) << 8)) << 8);
          ps->CurByteIndex += 4;
          v45 = (unsigned __int8)byte_85E441[i];
          *((float *)&v24[1].RefCount.Value + v45) = v50;
        }
        ++numFilters;
        *(float *)&v24[6].pLib = *(float *)&v24[6].pLib * 0.003921568859368563;
        *(float *)&v24[7].__vftable = *(float *)&v24[7].__vftable * 0.003921568859368563;
        *(float *)&v24[7].RefCount.Value = *(float *)&v24[7].RefCount.Value * 0.003921568859368563;
        *(float *)&v24[7].pLib = 0.003921568859368563 * *(float *)&v24[7].pLib;
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v24);
        v10 = numBytes;
        break;
      default:
        break;
    }
    if ( filters && filter )
    {
      Scaleform::Render::FilterSet::AddFilter(filters, filter);
      ++numFilters;
    }
    if ( v10 )
    {
      CurBitIndex = ps->CurBitIndex;
      v48 = ps->CurByteIndex;
      do
      {
        --v10;
        if ( CurBitIndex )
          ++v48;
        CurBitIndex = 0;
        ++v48;
      }
      while ( v10 );
      ps->CurBitIndex = 0;
      ps->CurByteIndex = v48;
    }
    if ( filter )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)filter);
  }
  while ( filterCount );
  return numFilters;
}


unsigned int __cdecl Scaleform::GFx::LoadFilters<Scaleform::GFx::Stream>(
        Scaleform::GFx::Stream *ps,
        Scaleform::Render::FilterSet *filters)
{
  signed int v3; // eax
  unsigned int Pos; // eax
  unsigned __int8 *pBuffer; // ecx
  unsigned __int8 v6; // dl
  Scaleform::MemoryHeap *v7; // ebp
  signed int v8; // ecx
  unsigned int v9; // eax
  unsigned __int8 v10; // cl
  unsigned int v11; // eax
  unsigned int v12; // edi
  Scaleform::Render::ShadowFilter *v13; // eax
  Scaleform::GFx::Resource *v14; // eax
  Scaleform::Render::BlurFilter *v15; // eax
  Scaleform::GFx::Resource *v16; // eax
  Scaleform::Render::GlowFilter *v17; // eax
  Scaleform::GFx::Resource *v18; // eax
  Scaleform::Render::BevelFilter *v19; // eax
  Scaleform::GFx::Resource *v20; // eax
  int v21; // edx
  unsigned int v22; // eax
  unsigned __int8 v23; // cl
  int v24; // edx
  int v25; // edi
  unsigned int v26; // eax
  int v27; // edx
  Scaleform::Render::ColorMatrixFilter *v28; // eax
  Scaleform::GFx::Resource *v29; // eax
  Scaleform::GFx::Resource *v30; // edi
  unsigned int v31; // ebp
  signed int v32; // eax
  unsigned int v33; // ecx
  float v34; // edx
  int v35; // ecx
  int v36; // edx
  unsigned int v37; // eax
  unsigned __int8 v38; // cl
  signed int v39; // edx
  Scaleform::GFx::Resource *filter; // [esp+20h] [ebp-40h]
  unsigned int numFilters; // [esp+24h] [ebp-3Ch]
  float distance; // [esp+28h] [ebp-38h] BYREF
  float angle; // [esp+2Ch] [ebp-34h] BYREF
  Scaleform::MemoryHeap *filtersHeap; // [esp+30h] [ebp-30h]
  float v46; // [esp+34h] [ebp-2Ch]
  unsigned int numBytes; // [esp+38h] [ebp-28h]
  Scaleform::Render::BlurFilterParams params; // [esp+3Ch] [ebp-24h] BYREF
  unsigned __int8 filterCount; // [esp+64h] [ebp+4h]

  v3 = ps->DataSize - ps->Pos;
  ps->UnusedBits = 0;
  if ( v3 < 1 )
    Scaleform::GFx::Stream::PopulateBuffer1(ps);
  Pos = ps->Pos;
  pBuffer = ps->pBuffer;
  angle = 0.0;
  v6 = pBuffer[Pos];
  distance = 0.0;
  ps->Pos = Pos + 1;
  filterCount = v6;
  numFilters = 0;
  if ( filters )
  {
    v7 = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, filters);
    filtersHeap = v7;
  }
  else
  {
    v7 = Scaleform::Memory::pGlobalHeap;
    filtersHeap = Scaleform::Memory::pGlobalHeap;
  }
  if ( !filterCount )
    return 0;
  do
  {
    v8 = ps->DataSize - ps->Pos;
    --filterCount;
    ps->UnusedBits = 0;
    if ( v8 < 1 )
      Scaleform::GFx::Stream::PopulateBuffer1(ps);
    v9 = ps->Pos;
    v10 = ps->pBuffer[v9];
    params.BlurX = 100.0;
    params.BlurY = 100.0;
    v11 = v9 + 1;
    params.Offset.x = 0.0;
    v12 = 0;
    params.Offset.y = 0.0;
    ps->Pos = v11;
    numBytes = 0;
    params.Strength = 1.0;
    filter = 0;
    params.Mode = 0;
    params.Passes = 1;
    *(_WORD *)&params.Colors[0].Channels.Green = 0;
    params.Colors[0].Channels.Blue = 0;
    params.Colors[0].Channels.Alpha = -1;
    *(_WORD *)&params.Colors[1].Channels.Green = 0;
    params.Colors[1].Channels.Blue = 0;
    params.Colors[1].Channels.Alpha = 0;
    switch ( v10 )
    {
      case 0u:
        Scaleform::GFx::ReadBlurFilter<Scaleform::GFx::Stream>(ps, &params, &angle, &distance, 13, Filter_Shadow, 0x1Fu);
        v13 = (Scaleform::Render::ShadowFilter *)v7->Alloc(v7, 60u, 0);
        if ( !v13 )
          goto LABEL_12;
        Scaleform::Render::ShadowFilter::ShadowFilter(v13, &params, angle, distance);
        filter = v14;
        break;
      case 1u:
        Scaleform::GFx::ReadBlurFilter<Scaleform::GFx::Stream>(ps, &params, 0, 0, 0, Filter_Blur, 0xF8u);
        v15 = (Scaleform::Render::BlurFilter *)v7->Alloc(v7, 60u, 0);
        if ( !v15 )
          goto LABEL_12;
        Scaleform::Render::BlurFilter::BlurFilter(v15, &params);
        filter = v16;
        break;
      case 2u:
        Scaleform::GFx::ReadBlurFilter<Scaleform::GFx::Stream>(ps, &params, 0, 0, 9, Filter_Glow, 0x1Fu);
        v17 = (Scaleform::Render::GlowFilter *)v7->Alloc(v7, 60u, 0);
        if ( !v17 )
          goto LABEL_12;
        Scaleform::Render::GlowFilter::GlowFilter(v17, &params);
        filter = v18;
        break;
      case 3u:
        Scaleform::GFx::ReadBlurFilter<Scaleform::GFx::Stream>(ps, &params, &angle, &distance, 15, Filter_Bevel, 0xFu);
        v19 = (Scaleform::Render::BevelFilter *)v7->Alloc(v7, 60u, 0);
        if ( v19 )
        {
          Scaleform::Render::BevelFilter::BevelFilter(v19, &params, angle, distance);
          filter = v20;
        }
        else
        {
LABEL_12:
          filter = 0;
        }
        break;
      case 4u:
      case 7u:
        v36 = ps->DataSize - v11;
        ps->UnusedBits = 0;
        if ( v36 < 1 )
          Scaleform::GFx::Stream::PopulateBuffer1(ps);
        v37 = ps->Pos;
        v38 = ps->pBuffer[v37];
        ps->Pos = v37 + 1;
        v12 = 5 * v38 + 19;
        break;
      case 5u:
        v21 = ps->DataSize - v11;
        ps->UnusedBits = 0;
        if ( v21 < 1 )
          Scaleform::GFx::Stream::PopulateBuffer1(ps);
        v22 = ps->Pos;
        v23 = ps->pBuffer[v22++];
        v24 = ps->DataSize - v22;
        ps->Pos = v22;
        v25 = v23;
        ps->UnusedBits = 0;
        if ( v24 < 1 )
          Scaleform::GFx::Stream::PopulateBuffer1(ps);
        v26 = ps->Pos;
        v27 = v25 * ps->pBuffer[v26];
        ps->Pos = v26 + 1;
        v12 = 4 * v27 + 13;
        break;
      case 6u:
        v28 = (Scaleform::Render::ColorMatrixFilter *)v7->Alloc(v7, 96u, 0);
        if ( v28 )
        {
          Scaleform::Render::ColorMatrixFilter::ColorMatrixFilter(v28);
          v30 = v29;
          if ( v29 )
            Scaleform::RefCountImpl::AddRef(v29);
          filter = v30;
          v31 = 0;
        }
        else
        {
          v30 = 0;
          filter = 0;
          v31 = 0;
        }
        do
        {
          v32 = ps->DataSize - ps->Pos;
          ps->UnusedBits = 0;
          if ( v32 < 4 )
            Scaleform::GFx::Stream::PopulateBuffer(ps, 4);
          v33 = ps->Pos;
          LODWORD(v34) = ps->pBuffer[v33]
                       | ((ps->pBuffer[v33 + 1] | (*(unsigned __int16 *)&ps->pBuffer[v33 + 2] << 8)) << 8);
          ps->Pos = v33 + 4;
          v35 = `Scaleform::GFx::LoadFilters<Scaleform::GFx::StreamContext>'::`9'::Index[v31];
          v46 = v34;
          ++v31;
          *((float *)&v30[1].RefCount.Value + v35) = v34;
        }
        while ( v31 < 0x14 );
        ++numFilters;
        *(float *)&v30[6].pLib = *(float *)&v30[6].pLib * 0.003921568859368563;
        *(float *)&v30[7].__vftable = *(float *)&v30[7].__vftable * 0.003921568859368563;
        *(float *)&v30[7].RefCount.Value = *(float *)&v30[7].RefCount.Value * 0.003921568859368563;
        *(float *)&v30[7].pLib = 0.003921568859368563 * *(float *)&v30[7].pLib;
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v30);
        v12 = numBytes;
        v7 = filtersHeap;
        break;
      default:
        break;
    }
    if ( filters && filter )
    {
      Scaleform::Render::FilterSet::AddFilter(filters, filter);
      ++numFilters;
    }
    for ( ; v12; ++ps->Pos )
    {
      v39 = ps->DataSize - ps->Pos;
      --v12;
      ps->UnusedBits = 0;
      if ( v39 < 1 )
        Scaleform::GFx::Stream::PopulateBuffer1(ps);
    }
    if ( filter )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)filter);
  }
  while ( filterCount );
  return numFilters;
}
