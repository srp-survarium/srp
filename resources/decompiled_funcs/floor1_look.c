_DWORD *__cdecl floor1_look(vorbis_dsp_state *vd, _DWORD *in)
{
  vostok::memory::doug_lea_mt_allocator *v2; // ecx
  _DWORD *v3; // edi
  _DWORD *v4; // ebp
  int v5; // ecx
  int v6; // esi
  _DWORD *v7; // eax
  signed int v8; // esi
  signed int v9; // eax
  int *v10; // ecx
  signed int v11; // eax
  int *v12; // ecx
  signed int v13; // eax
  _DWORD *v14; // ecx
  signed int i; // eax
  int v16; // esi
  int *v17; // eax
  int v18; // edx
  int v19; // esi
  int v20; // ecx
  int v21; // ebx
  int v22; // eax
  bool v23; // zf
  vostok::memory *v25; // [esp+0h] [ebp-120h]
  int *v26; // [esp+0h] [ebp-120h]
  int *v27; // [esp+4h] [ebp-11Ch]
  int hx; // [esp+8h] [ebp-118h]
  int *v29; // [esp+Ch] [ebp-114h]
  int currentx; // [esp+10h] [ebp-110h]
  int v31; // [esp+14h] [ebp-10Ch]
  int lo; // [esp+18h] [ebp-108h]
  int *sortpointer[65]; // [esp+1Ch] [ebp-104h] BYREF

  if ( !vostok::memory::g_crt_allocator.__vftable )
    vostok::memory::initialize_crt_allocator(v25);
  v3 = vostok::memory::doug_lea_mt_allocator::malloc_impl(v2, 0x520u);
  memset((int)v3, 0, 0x520u);
  v4 = in;
  v3[324] = in;
  v3[322] = in[210];
  v5 = *in;
  v6 = 0;
  if ( (int)*in > 0 )
  {
    v7 = in + 1;
    do
    {
      v6 += in[*v7++ + 32];
      --v5;
    }
    while ( v5 );
  }
  v8 = v6 + 2;
  v9 = 0;
  v3[321] = v8;
  if ( v8 > 0 )
  {
    v10 = in + 209;
    do
      sortpointer[v9++] = v10++;
    while ( v9 < v8 );
  }
  qsort((char *)sortpointer, v8, 4u, (int (__cdecl *)(const void *, const void *))icomp);
  v11 = 0;
  if ( v8 > 0 )
  {
    v12 = v3 + 65;
    do
      *v12++ = ((char *)sortpointer[v11++] - (char *)in - 836) >> 2;
    while ( v11 < v8 );
  }
  v13 = 0;
  if ( v8 > 0 )
  {
    v14 = v3 + 65;
    do
      v3[*v14++ + 130] = v13++;
    while ( v13 < v8 );
  }
  for ( i = 0; i < v8; ++i )
    v3[i] = in[v3[i + 65] + 209];
  switch ( in[208] )
  {
    case 1:
      v3[323] = 256;
      break;
    case 2:
      v3[323] = 128;
      break;
    case 3:
      v3[323] = 86;
      break;
    case 4:
      v3[323] = 64;
      break;
    default:
      break;
  }
  v16 = v8 - 2;
  if ( v16 > 0 )
  {
    v17 = v3 + 195;
    v18 = 2;
    v29 = v3 + 195;
    v27 = in + 211;
    v31 = v16;
    do
    {
      hx = v3[322];
      currentx = *v27;
      v19 = 0;
      v20 = 0;
      lo = 0;
      v21 = 1;
      if ( v18 > 0 )
      {
        v26 = v4 + 209;
        do
        {
          v22 = *v26;
          if ( *v26 > v19 && v22 < currentx )
          {
            lo = v20;
            v19 = *v26;
          }
          if ( v22 < hx && v22 > currentx )
          {
            v21 = v20;
            hx = *v26;
          }
          ++v26;
          ++v20;
        }
        while ( v20 < v18 );
        v4 = in;
        v17 = v29;
      }
      ++v27;
      v17[63] = lo;
      *v17++ = v21;
      ++v18;
      v23 = v31-- == 1;
      v29 = v17;
    }
    while ( !v23 );
  }
  return v3;
}
