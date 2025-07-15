unsigned int __cdecl adler32(unsigned int adler, const unsigned __int8 *buf, unsigned int len)
{
  unsigned int v3; // ebx
  unsigned int v4; // edi
  unsigned int v5; // ecx
  unsigned int v6; // ecx
  unsigned int v7; // edi
  const unsigned __int8 *v9; // esi
  unsigned int v10; // ebp
  int v11; // eax
  unsigned int v12; // ecx
  unsigned int v13; // edi
  unsigned int v14; // ecx
  unsigned int v15; // edi
  unsigned int v16; // ecx
  unsigned int v17; // edi
  unsigned int v18; // ecx
  unsigned int v19; // edi
  unsigned int v20; // ecx
  unsigned int v21; // edi
  unsigned int v22; // ecx
  unsigned int v23; // edi
  unsigned int v24; // ecx
  unsigned int v25; // edi
  unsigned int v26; // ecx
  unsigned int v27; // edi
  unsigned int v28; // ecx
  int v29; // edi
  int v30; // ecx
  int v31; // edi
  int v32; // ecx
  int v33; // edi
  int v34; // ecx
  int v35; // edi
  int v36; // ecx
  int v37; // edi
  int v38; // ecx
  int v39; // edi
  int v40; // ecx
  int v41; // edi
  unsigned int v42; // eax
  unsigned int v43; // ecx
  unsigned int v44; // edi
  unsigned int v45; // ecx
  unsigned int v46; // edi
  unsigned int v47; // ecx
  unsigned int v48; // edi
  unsigned int v49; // ecx
  unsigned int v50; // edi
  unsigned int v51; // ecx
  unsigned int v52; // edi
  unsigned int v53; // ecx
  unsigned int v54; // edi
  unsigned int v55; // ecx
  unsigned int v56; // edi
  unsigned int v57; // ecx
  unsigned int v58; // edi
  unsigned int v59; // ecx
  int v60; // edi
  int v61; // ecx
  int v62; // edi
  int v63; // ecx
  int v64; // edi
  int v65; // ecx
  int v66; // edi
  int v67; // ecx
  int v68; // edi
  int v69; // ecx
  int v70; // edi
  int v71; // ecx
  int v72; // edi

  v3 = len;
  v4 = HIWORD(adler);
  v5 = (unsigned __int16)adler;
  if ( len == 1 )
  {
    v6 = *buf + (unsigned __int16)adler;
    if ( v6 >= 0xFFF1 )
      v6 -= 65521;
    v7 = v6 + v4;
    if ( v7 >= 0xFFF1 )
      v7 -= 65521;
    return v6 | (v7 << 16);
  }
  else
  {
    v9 = buf;
    if ( buf )
    {
      if ( len >= 0x10 )
      {
        if ( len >= 0x15B0 )
        {
          v10 = len / 0x15B0;
          do
          {
            v3 -= 5552;
            v11 = 347;
            do
            {
              v12 = *v9 + v5;
              v13 = v12 + v4;
              v14 = v9[1] + v12;
              v15 = v14 + v13;
              v16 = v9[2] + v14;
              v17 = v16 + v15;
              v18 = v9[3] + v16;
              v19 = v18 + v17;
              v20 = v9[4] + v18;
              v21 = v20 + v19;
              v22 = v9[5] + v20;
              v23 = v22 + v21;
              v24 = v9[6] + v22;
              v25 = v24 + v23;
              v26 = v9[7] + v24;
              v27 = v26 + v25;
              v28 = v9[8] + v26;
              v29 = v28 + v27;
              v30 = v9[9] + v28;
              v31 = v30 + v29;
              v32 = v9[10] + v30;
              v33 = v32 + v31;
              v34 = v9[11] + v32;
              v35 = v34 + v33;
              v36 = v9[12] + v34;
              v37 = v36 + v35;
              v38 = v9[13] + v36;
              v39 = v38 + v37;
              v40 = v9[14] + v38;
              v41 = v40 + v39;
              v5 = v9[15] + v40;
              v4 = v5 + v41;
              v9 += 16;
              --v11;
            }
            while ( v11 );
            v5 %= 0xFFF1u;
            v4 %= 0xFFF1u;
            --v10;
          }
          while ( v10 );
        }
        if ( v3 )
        {
          if ( v3 >= 0x10 )
          {
            v42 = v3 >> 4;
            do
            {
              v43 = *v9 + v5;
              v44 = v43 + v4;
              v45 = v9[1] + v43;
              v46 = v45 + v44;
              v47 = v9[2] + v45;
              v48 = v47 + v46;
              v49 = v9[3] + v47;
              v50 = v49 + v48;
              v51 = v9[4] + v49;
              v52 = v51 + v50;
              v53 = v9[5] + v51;
              v54 = v53 + v52;
              v55 = v9[6] + v53;
              v56 = v55 + v54;
              v57 = v9[7] + v55;
              v58 = v57 + v56;
              v59 = v9[8] + v57;
              v60 = v59 + v58;
              v61 = v9[9] + v59;
              v62 = v61 + v60;
              v63 = v9[10] + v61;
              v64 = v63 + v62;
              v65 = v9[11] + v63;
              v66 = v65 + v64;
              v67 = v9[12] + v65;
              v68 = v67 + v66;
              v69 = v9[13] + v67;
              v70 = v69 + v68;
              v71 = v9[14] + v69;
              v72 = v71 + v70;
              v5 = v9[15] + v71;
              v3 -= 16;
              v4 = v5 + v72;
              v9 += 16;
              --v42;
            }
            while ( v42 );
          }
          for ( ; v3; v4 += v5 )
          {
            v5 += *v9;
            --v3;
            ++v9;
          }
          v5 %= 0xFFF1u;
          v4 %= 0xFFF1u;
        }
        return v5 | (v4 << 16);
      }
      else
      {
        if ( len )
        {
          do
          {
            v5 += *v9;
            --v3;
            ++v9;
            v4 += v5;
          }
          while ( v3 );
        }
        if ( v5 >= 0xFFF1 )
          v5 -= 65521;
        return v5 | ((v4 + 15 * (v4 / 0xFFF1)) << 16);
      }
    }
    else
    {
      return 1;
    }
  }
}
