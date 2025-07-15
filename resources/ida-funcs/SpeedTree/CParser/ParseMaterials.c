char __thiscall SpeedTree::CParser::ParseMaterials(SpeedTree::CParser *this)
{
  _DWORD *v1; // ecx
  _DWORD *v2; // edx
  _DWORD *v3; // eax
  _DWORD *v4; // ecx
  unsigned __int8 *v5; // ecx
  _DWORD *v6; // edx
  const struct SpeedTree::Vec4 *v8; // [esp+0h] [ebp-75A0h]
  float v9; // [esp+4h] [ebp-759Ch]
  float v10; // [esp+8h] [ebp-7598h]
  float v11; // [esp+Ch] [ebp-7594h]
  float v12; // [esp+10h] [ebp-7590h]
  float v13; // [esp+14h] [ebp-758Ch]
  float v14; // [esp+18h] [ebp-7588h]
  unsigned __int8 *v15; // [esp+1Ch] [ebp-7584h]
  unsigned __int8 *v16; // [esp+20h] [ebp-7580h]
  unsigned __int8 *v17; // [esp+24h] [ebp-757Ch]
  unsigned __int8 *v18; // [esp+28h] [ebp-7578h]
  int v20; // [esp+138h] [ebp-7468h]
  SMaterialSerial *i; // [esp+13Ch] [ebp-7464h]
  _BYTE v22[16]; // [esp+148h] [ebp-7458h] BYREF
  unsigned __int8 *v23; // [esp+158h] [ebp-7448h]
  _BYTE v24[16]; // [esp+15Ch] [ebp-7444h] BYREF
  unsigned __int8 *v25; // [esp+16Ch] [ebp-7434h]
  _BYTE v26[16]; // [esp+170h] [ebp-7430h] BYREF
  unsigned __int8 *v27; // [esp+180h] [ebp-7420h]
  _BYTE v28[16]; // [esp+184h] [ebp-741Ch] BYREF
  unsigned __int8 *v29; // [esp+194h] [ebp-740Ch]
  int v30; // [esp+198h] [ebp-7408h]
  const struct SpeedTree::Vec4 *v31; // [esp+19Ch] [ebp-7404h]
  unsigned __int8 *buf; // [esp+1A0h] [ebp-7400h]
  int j; // [esp+1A4h] [ebp-73FCh]
  unsigned __int8 *dst[2]; // [esp+1A8h] [ebp-73F8h] BYREF
  _BYTE v35[29668]; // [esp+1B0h] [ebp-73F0h] BYREF
  int v36; // [esp+7598h] [ebp-8h]
  char v37; // [esp+759Fh] [ebp-1h]

  v37 = 0;
  if ( *((_DWORD *)this + 1) >= (unsigned int)(*((_DWORD *)this + 2) + 4) )
  {
    v36 = SpeedTree::CParser::ParseInt(this);
    if ( *((_DWORD *)this + 1) >= (unsigned int)(*((_DWORD *)this + 2) + 1648 * v36) )
    {
      dst[1] = (unsigned __int8 *)18;
      v20 = 18;
      for ( i = (SMaterialSerial *)v35; --v20 >= 0; i = (SMaterialSerial *)((char *)i + 1648) )
        SMaterialSerial::SMaterialSerial(i);
      dst[0] = v35;
      if ( v36 > 18 )
      {
        dst[0] = (unsigned __int8 *)SpeedTree::st_new_array<SMaterialSerial>(v36, "CCore::SMaterialSerial");
        printf("warning, avoidable heap allocation in CParser::ParseMaterials\n");
      }
      memcpy(dst[0], (unsigned __int8 *)(*((_DWORD *)this + 2) + *(_DWORD *)this), 1648 * v36);
      *((_DWORD *)this + 2) += 1648 * v36;
      if ( v36 > 0 )
      {
        **((_DWORD **)this + 3) = v36;
        *(_DWORD *)(*((_DWORD *)this + 3) + 4) = SpeedTree::st_new_array<SpeedTree::SMaterial>(v36, "CCore::SMaterial");
        for ( j = 0; j < v36; ++j )
        {
          v30 = *(_DWORD *)(*((_DWORD *)this + 3) + 4) + 1692 * j;
          buf = &dst[0][1648 * j];
          if ( *((_BYTE *)this + 92) )
            v18 = (unsigned __int8 *)SpeedTree::EndianSwap((SpeedTree *)v28, (struct SpeedTree::Vec4 *)buf + 81, v8);
          else
            v18 = buf + 1296;
          v29 = v18;
          v1 = (_DWORD *)v30;
          *(_DWORD *)v30 = *(_DWORD *)v18;
          v1[1] = *((_DWORD *)v18 + 1);
          v1[2] = *((_DWORD *)v18 + 2);
          v1[3] = *((_DWORD *)v18 + 3);
          if ( *((_BYTE *)this + 92) )
            v17 = (unsigned __int8 *)SpeedTree::EndianSwap((SpeedTree *)v26, (struct SpeedTree::Vec4 *)buf + 82, v8);
          else
            v17 = buf + 1312;
          v27 = v17;
          v2 = (_DWORD *)(v30 + 16);
          *(_DWORD *)(v30 + 16) = *(_DWORD *)v17;
          v2[1] = *((_DWORD *)v17 + 1);
          v2[2] = *((_DWORD *)v17 + 2);
          v2[3] = *((_DWORD *)v17 + 3);
          if ( *((_BYTE *)this + 92) )
            v16 = (unsigned __int8 *)SpeedTree::EndianSwap((SpeedTree *)v24, (struct SpeedTree::Vec4 *)buf + 83, v8);
          else
            v16 = buf + 1328;
          v25 = v16;
          v3 = (_DWORD *)(v30 + 32);
          *(_DWORD *)(v30 + 32) = *(_DWORD *)v16;
          v3[1] = *((_DWORD *)v16 + 1);
          v3[2] = *((_DWORD *)v16 + 2);
          v3[3] = *((_DWORD *)v16 + 3);
          if ( *((_BYTE *)this + 92) )
            v15 = (unsigned __int8 *)SpeedTree::EndianSwap((SpeedTree *)v22, (struct SpeedTree::Vec4 *)buf + 84, v8);
          else
            v15 = buf + 1344;
          v23 = v15;
          v4 = (_DWORD *)(v30 + 48);
          *(_DWORD *)(v30 + 48) = *(_DWORD *)v15;
          v4[1] = *((_DWORD *)v15 + 1);
          v4[2] = *((_DWORD *)v15 + 2);
          v4[3] = *((_DWORD *)v15 + 3);
          if ( *((_BYTE *)this + 92) )
            v14 = COERCE_FLOAT(SpeedTree::EndianSwap(COERCE_SPEEDTREE_(*((float *)buf + 340))));
          else
            v14 = *((float *)buf + 340);
          *(float *)(v30 + 64) = v14;
          if ( *((_BYTE *)this + 92) )
            v13 = COERCE_FLOAT(SpeedTree::EndianSwap(COERCE_SPEEDTREE_(*((float *)buf + 341))));
          else
            v13 = *((float *)buf + 341);
          *(float *)(v30 + 68) = v13;
          if ( *((_BYTE *)this + 92) )
            v12 = COERCE_FLOAT(SpeedTree::EndianSwap(COERCE_SPEEDTREE_(*((float *)buf + 342))));
          else
            v12 = *((float *)buf + 342);
          *(float *)(v30 + 72) = v12;
          if ( *((_BYTE *)this + 92) )
            v11 = COERCE_FLOAT(SpeedTree::EndianSwap(COERCE_SPEEDTREE_(*((float *)buf + 343))));
          else
            v11 = *((float *)buf + 343);
          *(float *)(v30 + 76) = v11;
          if ( *((_BYTE *)this + 92) )
            v10 = COERCE_FLOAT(SpeedTree::EndianSwap(COERCE_SPEEDTREE_(*((float *)buf + 344))));
          else
            v10 = *((float *)buf + 344);
          *(float *)(v30 + 80) = v10;
          if ( *((_BYTE *)this + 92) )
            v9 = COERCE_FLOAT(SpeedTree::EndianSwap(COERCE_SPEEDTREE_(*((float *)buf + 345))));
          else
            v9 = *((float *)buf + 345);
          *(float *)(v30 + 84) = v9;
          if ( *((_BYTE *)this + 92) )
            v8 = (const struct SpeedTree::Vec4 *)SpeedTree::EndianSwap(*((SpeedTree **)buf + 346));
          else
            v8 = (const struct SpeedTree::Vec4 *)*((_DWORD *)buf + 346);
          v31 = v8;
          *(_DWORD *)(v30 + 88) = v8;
          SpeedTree::CBasicFixedString<1024>::operator=(buf);
          SpeedTree::CBasicFixedString<1024>::operator=(buf + 256);
          SpeedTree::CBasicFixedString<1024>::operator=(buf + 512);
          SpeedTree::CBasicFixedString<1024>::operator=(buf + 768);
          SpeedTree::CBasicFixedString<1024>::operator=(buf + 1024);
          v5 = buf + 1280;
          v6 = (_DWORD *)(v30 + 1412);
          *(_DWORD *)(v30 + 1412) = *((_DWORD *)buf + 320);
          v6[1] = *((_DWORD *)v5 + 1);
          v6[2] = *((_DWORD *)v5 + 2);
          v6[3] = *((_DWORD *)v5 + 3);
          SpeedTree::CBasicFixedString<1024>::operator=(buf + 1392);
        }
      }
      if ( dst[0] != v35 )
        SpeedTree::st_delete_array<SMaterialSerial>(dst);
      return 1;
    }
  }
  return v37;
}
