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
