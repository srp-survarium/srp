int __usercall vorbis_book_init_decode@<eax>(codebook *c@<edi>, const static_codebook *s@<eax>, __int128 a3@<xmm0>)
{
  int v3; // ebx
  int entries; // eax
  int *lengthlist; // ecx
  int v7; // edx
  void *v8; // esp
  int v10; // eax
  int *v11; // ecx
  bool v12; // zf
  void *v13; // esp
  int i; // eax
  int *v15; // edx
  int *v16; // eax
  char *v17; // ecx
  int v18; // edx
  unsigned int v19; // ecx
  unsigned int *codelist; // ebx
  int v21; // ebx
  float *v22; // eax
  int v23; // eax
  unsigned int j; // ecx
  char *v25; // eax
  int v26; // ecx
  bool v27; // cc
  int *v28; // eax
  int v29; // edx
  char *dec_codelengths; // ebx
  char v31; // al
  int v32; // eax
  unsigned __int8 *v33; // eax
  int v34; // esi
  char *v35; // eax
  int v36; // ecx
  int v37; // ebx
  int v38; // eax
  int dec_firsttablen; // ecx
  int v40; // edx
  int v41; // ebx
  unsigned int v42; // ebx
  unsigned int v43; // esi
  unsigned int *v44; // edx
  int v45; // ecx
  unsigned int *v46; // eax
  unsigned int *v47; // eax
  unsigned int v48; // eax
  __int16 v49; // cx
  unsigned int v50; // [esp-Ch] [ebp-34h]
  _BYTE v51[12]; // [esp+0h] [ebp-28h] BYREF
  int v52; // [esp+Ch] [ebp-1Ch]
  signed int v53; // [esp+10h] [ebp-18h]
  unsigned int size; // [esp+14h] [ebp-14h]
  void *base; // [esp+18h] [ebp-10h]
  void *memblock; // [esp+1Ch] [ebp-Ch]
  int *v57; // [esp+20h] [ebp-8h]
  int v58; // [esp+24h] [ebp-4h]

  v3 = 0;
  v58 = 0;
  memset((int)c, 0, sizeof(codebook));
  entries = s->entries;
  if ( entries > 0 )
  {
    lengthlist = s->lengthlist;
    v7 = s->entries;
    do
    {
      if ( *lengthlist > 0 )
        ++v3;
      ++lengthlist;
      --v7;
    }
    while ( v7 );
    v58 = v3;
  }
  c->entries = entries;
  c->used_entries = v3;
  c->dim = s->dim;
  if ( v3 > 0 )
  {
    memblock = _make_words(s->lengthlist, s->entries, v3);
    size = 4 * v3;
    v8 = alloca(4 * v3);
    base = v51;
    if ( !memblock )
    {
      vorbis_book_clear(c);
      return -1;
    }
    v57 = (int *)memblock;
    v52 = (_BYTE *)base - (_BYTE *)memblock;
    v53 = v3;
    do
    {
      v10 = bitreverse((void *)*v57);
      v11 = v57;
      *v57 = v10;
      *(int *)((char *)v11 + v52) = (int)v11;
      v12 = v53-- == 1;
      v57 = v11 + 1;
    }
    while ( !v12 );
    qsort((char *)base, v3, 4u, (int (__cdecl *)(const void *, const void *))sort32a);
    v13 = alloca(size);
    v57 = (int *)v51;
    c->codelist = (unsigned int *)ogg_malloc_impl(size);
    for ( i = 0; i < v3; ++i )
    {
      v15 = v57;
      v57[(*((_DWORD *)base + i) - (int)memblock) >> 2] = i;
    }
    v16 = v15;
    v17 = (char *)((_BYTE *)memblock - (_BYTE *)v15);
    v52 = (_BYTE *)memblock - (_BYTE *)v15;
    v53 = v3;
    while ( 1 )
    {
      v18 = *v16;
      v19 = *(int *)((char *)v16 + (_DWORD)v17);
      codelist = c->codelist;
      ++v16;
      v12 = v53-- == 1;
      codelist[v18] = v19;
      if ( v12 )
        break;
      v17 = (char *)v52;
    }
    v21 = v58;
    ogg_free_impl(memblock);
    v22 = _book_unquantize(s, (int)c, a3, v21, v57);
    v50 = size;
    c->valuelist = v22;
    c->dec_index = (int *)ogg_malloc_impl(v50);
    v23 = 0;
    for ( j = 0; v23 < s->entries; ++v23 )
    {
      if ( s->lengthlist[v23] > 0 )
        c->dec_index[v57[j++]] = v23;
    }
    v25 = (char *)ogg_malloc_impl(j);
    v26 = 0;
    c->dec_codelengths = v25;
    v27 = s->entries <= 0;
    v58 = 0;
    if ( !v27 )
    {
      do
      {
        v28 = &s->lengthlist[v26];
        if ( *v28 > 0 )
        {
          v29 = v57[v58];
          dec_codelengths = c->dec_codelengths;
          v31 = *(_BYTE *)v28;
          ++v58;
          dec_codelengths[v29] = v31;
        }
        ++v26;
      }
      while ( v26 < s->entries );
    }
    v32 = _ilog(c->used_entries) - 4;
    c->dec_firsttablen = v32;
    if ( v32 < 5 )
      c->dec_firsttablen = 5;
    if ( c->dec_firsttablen > 8 )
      c->dec_firsttablen = 8;
    v53 = 1 << c->dec_firsttablen;
    v33 = ogg_calloc_impl(v53, 4u);
    v34 = 0;
    v27 = v58 <= 0;
    c->dec_firsttable = (unsigned int *)v33;
    c->dec_maxlength = 0;
    if ( !v27 )
    {
      do
      {
        v35 = &c->dec_codelengths[v34];
        v36 = *v35;
        if ( c->dec_maxlength < v36 )
          c->dec_maxlength = v36;
        v37 = *v35;
        if ( v37 <= c->dec_firsttablen )
        {
          v38 = bitreverse((void *)c->codelist[v34]);
          dec_firsttablen = c->dec_firsttablen;
          v52 = v38;
          v40 = 0;
          if ( 1 << (dec_firsttablen - v37) > 0 )
          {
            do
            {
              v41 = v52 | (v40++ << c->dec_codelengths[v34]);
              c->dec_firsttable[v41] = v34 + 1;
            }
            while ( v40 < 1 << (LOBYTE(c->dec_firsttablen) - c->dec_codelengths[v34]) );
          }
        }
        ++v34;
      }
      while ( v34 < v58 );
    }
    v42 = 0;
    v52 = -2 << (31 - LOBYTE(c->dec_firsttablen));
    v57 = 0;
    for ( memblock = 0; (int)memblock < v53; memblock = (char *)memblock + 1 )
    {
      v43 = (_DWORD)memblock << (32 - LOBYTE(c->dec_firsttablen));
      v44 = &c->dec_firsttable[bitreverse((void *)v43)];
      v12 = *v44 == 0;
      size = (unsigned int)v44;
      if ( v12 )
      {
        if ( (int)(v42 + 1) < v58 )
        {
          v45 = v42 + 1;
          v46 = &c->codelist[v42 + 1];
          do
          {
            if ( *v46 > v43 )
              break;
            ++v42;
            ++v46;
            ++v45;
          }
          while ( v45 < v58 );
        }
        if ( (int)v57 < v58 )
        {
          v47 = &c->codelist[(_DWORD)v57];
          do
          {
            if ( v43 < (v52 & *v47) )
              break;
            v57 = (int *)((char *)v57 + 1);
            ++v47;
          }
          while ( (int)v57 < v58 );
          v44 = (unsigned int *)size;
        }
        v48 = v58 - (_DWORD)v57;
        v49 = v42;
        if ( v42 > 0x7FFF )
          v49 = 0x7FFF;
        if ( v48 > 0x7FFF )
          v48 = 0x7FFF;
        *v44 = v48 | ((*(_DWORD *)&v49 | 0xFFFF0000) << 15);
      }
    }
  }
  return 0;
}
