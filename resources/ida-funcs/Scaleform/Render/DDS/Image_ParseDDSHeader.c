bool __usercall Scaleform::Render::DDS::Image_ParseDDSHeader@<al>(
        Scaleform::Render::DDS::DDSHeaderInfo *pinfo@<esi>,
        const unsigned __int8 *buf@<ecx>,
        const unsigned __int8 **pdata)
{
  unsigned int v3; // eax
  int v4; // ebx
  unsigned int *v5; // ecx
  unsigned int v6; // eax
  unsigned int *v7; // ecx
  unsigned int v8; // eax
  unsigned int *v9; // ecx
  int v10; // edi
  unsigned int v11; // eax
  unsigned int *v12; // ecx
  _DWORD *v13; // ecx
  bool result; // al
  int v15; // edx
  _DWORD *v16; // ecx
  int v17; // ebx
  int v18; // edx
  unsigned int *v19; // ecx
  unsigned int v20; // edx
  unsigned int *v21; // ecx
  unsigned int v22; // edx
  unsigned int *v23; // ecx
  unsigned int v24; // edx
  unsigned int v25; // edx
  unsigned int v26; // edx

  v3 = *((_DWORD *)buf + 1);
  v4 = *(_DWORD *)buf;
  v5 = (unsigned int *)(buf + 8);
  if ( (v4 & 2) != 0 )
    pinfo->Height = v3;
  v6 = *v5;
  v7 = v5 + 1;
  if ( (v4 & 4) != 0 )
    pinfo->Width = v6;
  v8 = *v7;
  v9 = v7 + 1;
  v10 = v4 & 8;
  if ( (v4 & 8) == 0 )
  {
    if ( (v4 & 0x80000) == 0 )
      goto LABEL_9;
    v8 = 4 * (v8 / pinfo->Height);
  }
  pinfo->Pitch = v8;
LABEL_9:
  v11 = v9[1];
  v12 = v9 + 2;
  if ( ((unsigned int)&loc_20000 & v4) != 0 )
    pinfo->MipmapCount = v11;
  v13 = v12 + 11;
  result = 1;
  if ( (v4 & 0x1000) == 0 )
  {
    v19 = v13 + 8;
    goto LABEL_35;
  }
  v15 = *v13;
  v16 = v13 + 1;
  if ( v15 != 32 )
    return 0;
  v17 = *v16;
  v18 = v16[1];
  v19 = v16 + 2;
  if ( (v17 & 4) != 0 )
  {
    switch ( v18 )
    {
      case 894720068:
        pinfo->Format = Image_DXT5;
        v19 += 5;
        goto LABEL_32;
      case 861165636:
        pinfo->Format = Image_DXT3;
        v19 += 5;
        goto LABEL_32;
      case 827611204:
        pinfo->Format = Image_DXT1;
        v19 += 5;
        goto LABEL_32;
    }
    return 0;
  }
  if ( (v17 & 0x42) != 0 )
  {
    v20 = *v19;
    v21 = v19 + 1;
    pinfo->DDSFmt.RGBBitCount = v20;
    switch ( v20 )
    {
      case 8u:
        if ( (v17 & 2) == 0 )
          return 0;
        pinfo->Format = Image_A8;
        break;
      case 0x18u:
        pinfo->Format = Image_R8G8B8;
        break;
      case 0x20u:
        pinfo->Format = Image_R8G8B8A8;
        break;
      default:
        return 0;
    }
    if ( !v10 )
      pinfo->Pitch = pinfo->Width * (v20 >> 3);
    v22 = *v21;
    v23 = v21 + 1;
    pinfo->DDSFmt.RBitMask = v22;
    v24 = *v23++;
    pinfo->DDSFmt.GBitMask = v24;
    v25 = *v23++;
    pinfo->DDSFmt.BBitMask = v25;
    v26 = *v23;
    v19 = v23 + 1;
    if ( (v17 & 1) != 0 )
    {
      pinfo->DDSFmt.ABitMask = v26;
      pinfo->DDSFmt.HasAlpha = 1;
    }
  }
LABEL_32:
  if ( pinfo->Format == Image_None )
    return 0;
LABEL_35:
  if ( pdata )
    *pdata = (const unsigned __int8 *)(v19 + 5);
  return result;
}
