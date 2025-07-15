char __thiscall Scaleform::Render::RawImage::Decode(
        Scaleform::Render::RawImage *this,
        Scaleform::Render::ImageData *pdest,
        void (__stdcall *copyScanline)(unsigned __int8 *, const unsigned __int8 *, unsigned int, Scaleform::Render::Palette *, void *),
        void *arg)
{
  Scaleform::Render::ImageFormat Format; // edx
  unsigned int v5; // esi
  Scaleform::Render::ImageData *p_Data; // edi
  int LevelCount; // ecx
  Scaleform::Render::ImageData *v8; // ebx
  unsigned int v9; // eax
  int v10; // ebp
  int v11; // ebp
  Scaleform::Render::ImagePlane *pPlanes; // eax
  unsigned int Width; // ecx
  unsigned int Height; // edx
  Scaleform::Render::ImagePlane *v15; // eax
  unsigned int Pitch; // ecx
  unsigned int DataSize; // edx
  unsigned __int8 *v18; // eax
  Scaleform::Render::ImagePlane *v19; // eax
  unsigned int v20; // ecx
  unsigned int v21; // edx
  Scaleform::Render::ImagePlane *v22; // eax
  unsigned int v23; // ecx
  unsigned int v24; // edx
  unsigned __int8 *v25; // eax
  int v27; // edx
  unsigned int v28; // ebp
  unsigned __int8 v29; // al
  unsigned int RawPlaneCount; // ecx
  unsigned int *v31; // eax
  unsigned int v32; // ecx
  unsigned int v33; // edx
  unsigned int v34; // ecx
  unsigned __int8 *v35; // edx
  unsigned int *v36; // eax
  unsigned int v37; // ecx
  unsigned int v38; // edx
  unsigned int v39; // ecx
  unsigned __int8 *v40; // edx
  unsigned int *v41; // eax
  unsigned int v42; // edx
  unsigned int v43; // ecx
  unsigned int v44; // edx
  unsigned __int8 *v45; // eax
  unsigned int *v46; // eax
  unsigned int v47; // ecx
  unsigned int v48; // edx
  unsigned int v49; // ecx
  unsigned __int8 *v50; // edx
  unsigned int v51; // eax
  int v52; // ecx
  unsigned int v53; // esi
  int v54; // ebp
  unsigned __int8 *pData; // esi
  unsigned __int8 *v56; // ebp
  unsigned int FormatBitsPerPixel; // eax
  int v58; // ecx
  unsigned int v59; // ebx
  unsigned __int8 *v60; // [esp+14h] [ebp-64h]
  unsigned __int8 *v61; // [esp+18h] [ebp-60h]
  unsigned int v62; // [esp+1Ch] [ebp-5Ch]
  int v64; // [esp+24h] [ebp-54h]
  int v65; // [esp+28h] [ebp-50h]
  unsigned int v66; // [esp+2Ch] [ebp-4Ch]
  unsigned int v67; // [esp+30h] [ebp-48h]
  unsigned int v68; // [esp+34h] [ebp-44h]
  int v69; // [esp+38h] [ebp-40h]
  unsigned int v70; // [esp+3Ch] [ebp-3Ch]
  unsigned int v71; // [esp+40h] [ebp-38h]
  int v72; // [esp+40h] [ebp-38h]
  int v73; // [esp+44h] [ebp-34h]
  int v74; // [esp+48h] [ebp-30h]
  int v75; // [esp+4Ch] [ebp-2Ch]
  Scaleform::Render::ImagePlane p; // [esp+50h] [ebp-28h] BYREF
  Scaleform::Render::ImagePlane pplane; // [esp+64h] [ebp-14h] BYREF

  Format = this->Data.Format;
  v5 = 0;
  p_Data = &this->Data;
  v73 = Format & 0xFFF;
  memset(&p, 0, sizeof(p));
  memset(&pplane, 0, sizeof(pplane));
  if ( (Format & 0xFFF) != 0 )
  {
    if ( v73 == 200 )
    {
      v62 = 3;
    }
    else if ( v73 == 201 )
    {
      v62 = 4;
    }
    else
    {
      v62 = 1;
    }
  }
  else
  {
    v62 = 0;
  }
  if ( (this->Data.Flags & 1) != 0 )
    LevelCount = this->Data.LevelCount;
  else
    LevelCount = 1;
  v8 = pdest;
  v9 = LevelCount * p_Data->RawPlaneCount;
  v67 = v9;
  if ( (pdest->Flags & 1) != 0 )
    v10 = pdest->LevelCount;
  else
    v10 = 1;
  if ( (int)(Format & 0xFFEFFFFF) < 4096 )
  {
    if ( v9 >= v10 * (unsigned int)pdest->RawPlaneCount )
    {
      v67 = v10 * pdest->RawPlaneCount;
      v9 = v67;
    }
    v66 = 0;
    if ( !v9 )
      return 1;
    v27 = v9 % v62;
    v69 = 0;
    v74 = v9 % v62;
    while ( ((this->Data.Flags & 1) != 0 || this->Data.LevelCount == 1) && ((v8->Flags & 1) != 0 || v8->LevelCount == 1) )
    {
      Scaleform::Render::ImageData::GetPlane(p_Data, v5, &p);
      Scaleform::Render::ImageData::GetPlane(v8, v5, &pplane);
      pData = p.pData;
      v56 = pplane.pData;
      FormatBitsPerPixel = Scaleform::Render::ImageData::GetFormatBitsPerPixel(p_Data->Format, 0);
      v59 = (p.Width * FormatBitsPerPixel) >> 3;
      if ( v58 )
      {
        v72 = v58;
        do
        {
          copyScanline(v56, pData, v59, this->Data.pPalette.pObject, arg);
          pData += p.Pitch;
          v56 += pplane.Pitch;
          --v72;
        }
        while ( v72 );
      }
      v5 = v66;
      v8 = pdest;
LABEL_67:
      v69 += 20;
      v66 = ++v5;
      if ( v5 >= v67 )
        return 1;
      v27 = v74;
    }
    v75 = 20 * v62;
    v65 = v69;
    v60 = 0;
    v61 = 0;
    v68 = 0;
    v28 = v5;
    v71 = v5;
    v64 = 20 * v27;
    v70 = v27 - v5;
    while ( 1 )
    {
      v29 = v8->LevelCount;
      if ( this->Data.LevelCount < v29 )
        v29 = this->Data.LevelCount;
      if ( v68 >= v29 )
        goto LABEL_67;
      RawPlaneCount = p_Data->RawPlaneCount;
      if ( (this->Data.Flags & 1) == 0 )
        break;
      if ( v70 + v28 >= RawPlaneCount )
      {
        Scaleform::Render::ImagePlane::GetMipLevel(
          &p_Data->pPlanes[(v70 + v28) % p_Data->RawPlaneCount],
          p_Data->Format,
          (v70 + v28) / p_Data->RawPlaneCount,
          &p,
          (v70 + v28) % p_Data->RawPlaneCount);
      }
      else
      {
        v31 = (unsigned int *)((char *)&p_Data->pPlanes->Width + v64);
        v32 = v31[1];
        p.Width = *v31;
        v33 = v31[2];
        p.Height = v32;
        v34 = v31[3];
        p.Pitch = v33;
        v35 = (unsigned __int8 *)v31[4];
        p.DataSize = v34;
        p.pData = v35;
      }
      if ( !v60 )
        goto LABEL_47;
LABEL_48:
      if ( (v8->Flags & 1) == 0 )
      {
        if ( v28 >= v8->RawPlaneCount )
        {
          Scaleform::Render::ImagePlane::GetMipLevel(
            &v8->pPlanes[v28 % v8->RawPlaneCount],
            v8->Format,
            v28 / v8->RawPlaneCount,
            &pplane,
            v28 % v8->RawPlaneCount);
        }
        else
        {
          v46 = (unsigned int *)((char *)&v8->pPlanes->Width + v65);
          v47 = v46[1];
          pplane.Width = *v46;
          v48 = v46[2];
          pplane.Height = v47;
          v49 = v46[3];
          pplane.Pitch = v48;
          v50 = (unsigned __int8 *)v46[4];
          pplane.DataSize = v49;
          pplane.pData = v50;
        }
LABEL_57:
        v61 = pplane.pData;
        goto LABEL_58;
      }
      if ( v70 + v28 >= v8->RawPlaneCount )
      {
        Scaleform::Render::ImagePlane::GetMipLevel(
          &v8->pPlanes[(v70 + v28) % v8->RawPlaneCount],
          v8->Format,
          (v70 + v28) / v8->RawPlaneCount,
          &pplane,
          (v70 + v28) % v8->RawPlaneCount);
      }
      else
      {
        v41 = (unsigned int *)((char *)&v8->pPlanes->Width + v64);
        v42 = v41[1];
        pplane.Width = *v41;
        v43 = v41[2];
        pplane.Height = v42;
        v44 = v41[3];
        v45 = (unsigned __int8 *)v41[4];
        pplane.Pitch = v43;
        pplane.DataSize = v44;
        pplane.pData = v45;
      }
      if ( !v61 )
        goto LABEL_57;
LABEL_58:
      v51 = Scaleform::Render::ImageData::GetFormatBitsPerPixel(p_Data->Format, 0);
      v53 = (p.Width * v51) >> 3;
      if ( v52 )
      {
        v54 = v52;
        do
        {
          copyScanline(v61, v60, v53, this->Data.pPalette.pObject, arg);
          v60 += p.Pitch;
          v61 += pplane.Pitch;
          --v54;
        }
        while ( v54 );
        v28 = v71;
      }
      ++v68;
      v64 += v75;
      v65 += v75;
      v28 += v62;
      v5 = v66;
      v71 = v28;
    }
    if ( v28 >= RawPlaneCount )
    {
      Scaleform::Render::ImagePlane::GetMipLevel(
        &p_Data->pPlanes[v28 % p_Data->RawPlaneCount],
        p_Data->Format,
        v28 / p_Data->RawPlaneCount,
        &p,
        v28 % p_Data->RawPlaneCount);
    }
    else
    {
      v36 = (unsigned int *)((char *)&p_Data->pPlanes->Width + v65);
      v37 = v36[1];
      p.Width = *v36;
      v38 = v36[2];
      p.Height = v37;
      v39 = v36[3];
      p.Pitch = v38;
      v40 = (unsigned __int8 *)v36[4];
      p.DataSize = v39;
      p.pData = v40;
    }
LABEL_47:
    v60 = p.pData;
    goto LABEL_48;
  }
  if ( !v9 )
    return 1;
  v11 = 0;
  do
  {
    if ( v5 >= p_Data->RawPlaneCount )
    {
      Scaleform::Render::ImagePlane::GetMipLevel(
        &p_Data->pPlanes[v5 % p_Data->RawPlaneCount],
        p_Data->Format,
        v5 / p_Data->RawPlaneCount,
        &p,
        v5 % p_Data->RawPlaneCount);
    }
    else
    {
      pPlanes = p_Data->pPlanes;
      Width = pPlanes[v11].Width;
      Height = pPlanes[v11].Height;
      v15 = &pPlanes[v11];
      p.Width = Width;
      Pitch = v15->Pitch;
      p.Height = Height;
      DataSize = v15->DataSize;
      v18 = v15->pData;
      p.Pitch = Pitch;
      p.DataSize = DataSize;
      p.pData = v18;
    }
    if ( v5 >= pdest->RawPlaneCount )
    {
      Scaleform::Render::ImagePlane::GetMipLevel(
        &pdest->pPlanes[v5 % pdest->RawPlaneCount],
        pdest->Format,
        v5 / pdest->RawPlaneCount,
        &pplane,
        v5 % pdest->RawPlaneCount);
    }
    else
    {
      v19 = pdest->pPlanes;
      v20 = v19[v11].Width;
      v21 = v19[v11].Height;
      v22 = &v19[v11];
      pplane.Width = v20;
      v23 = v22->Pitch;
      pplane.Height = v21;
      v24 = v22->DataSize;
      v25 = v22->pData;
      pplane.Pitch = v23;
      pplane.DataSize = v24;
      pplane.pData = v25;
    }
    memcpy((int)pplane.pData, (const __m128i *)p.pData, p.DataSize);
    ++v5;
    ++v11;
  }
  while ( v5 < v67 );
  return 1;
}
