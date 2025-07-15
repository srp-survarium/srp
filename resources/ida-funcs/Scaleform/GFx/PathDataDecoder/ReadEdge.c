unsigned int __thiscall Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::ReadEdge(
        Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> > *this,
        unsigned int pos,
        int *data)
{
  unsigned int result; // eax
  unsigned int v4; // ecx
  unsigned int v5; // esi
  int *v6; // eax
  int v7; // edx
  int v8; // edx
  int v9; // edi
  int v10; // edx
  int v11; // ecx
  unsigned int v12; // edx
  int v13; // ecx
  int v14; // ecx
  unsigned int v15; // edx
  unsigned __int8 v16; // dl
  int v17; // ecx
  int v18; // ecx
  unsigned __int8 v19; // al
  int v20; // edi
  unsigned int v21; // ecx
  char v22; // al
  char v23; // bl
  unsigned __int8 v24; // al
  char v25; // bl
  int v26; // ecx
  int v27; // ecx
  unsigned __int8 v28; // al
  unsigned __int8 v29; // cl
  char v30; // bl
  int v31; // edi
  unsigned __int8 v32; // al
  unsigned __int8 v33; // bl
  int v34; // edi
  int v35; // ecx
  unsigned __int8 v36; // al
  unsigned __int8 v37; // cl
  int v38; // edi
  unsigned __int8 v39; // al
  char v40; // bl
  int v41; // edi
  int v42; // ecx
  unsigned __int8 v43; // al
  unsigned __int8 v44; // cl
  int v45; // edi
  unsigned __int8 v46; // al
  int v47; // edi
  int v48; // ecx
  unsigned __int8 v49; // al
  unsigned __int8 v50; // cl
  int v51; // edi
  unsigned __int8 v52; // al
  unsigned __int8 v53; // bl
  int v54; // edi
  int v55; // ecx
  unsigned __int8 v56; // al
  unsigned __int8 v57; // cl
  int v58; // edi
  unsigned __int8 v59; // al
  int v60; // edi
  int v61; // ecx
  int v62; // ecx
  unsigned __int8 v63; // al
  unsigned __int8 v64; // cl
  int v65; // edi
  unsigned __int8 v66; // al
  char v67; // bl
  int v68; // edi
  int v69; // ecx
  int v70; // ecx
  unsigned __int8 dataa; // [esp+4h] [ebp-Ch] BYREF
  unsigned __int8 v72; // [esp+5h] [ebp-Bh]
  unsigned __int8 v73; // [esp+6h] [ebp-Ah]
  unsigned __int8 v74; // [esp+7h] [ebp-9h]
  unsigned __int8 v75; // [esp+8h] [ebp-8h]
  unsigned __int8 v76; // [esp+9h] [ebp-7h]
  unsigned __int8 v77; // [esp+Ah] [ebp-6h]
  unsigned __int8 v78; // [esp+Bh] [ebp-5h]
  unsigned __int8 v79; // [esp+Ch] [ebp-4h]
  char v80; // [esp+Dh] [ebp-3h]

  result = Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::ReadRawEdge(
             this,
             pos,
             &dataa);
  v4 = dataa;
  v5 = result;
  switch ( dataa & 0xF )
  {
    case 0:
      v6 = data;
      *data = 0;
      goto LABEL_3;
    case 1:
      v8 = (dataa >> 4) | (16 * (v72 | ((char)v73 << 8)));
      *data = 0;
      data[1] = v8;
      return result;
    case 2:
      v6 = data;
      *data = 1;
LABEL_3:
      v7 = (char)v72;
      goto LABEL_4;
    case 3:
      v9 = v72;
      v6 = data;
      v10 = (char)v73 << 8;
      *data = 1;
      v7 = v9 | v10;
LABEL_4:
      v6[1] = (v4 >> 4) | (16 * v7);
      return v5;
    case 4:
      v11 = (char)v72;
      data[1] = ((dataa >> 2) | (char)(v72 << 6)) >> 2;
      *data = 2;
      data[2] = v11 >> 2;
      return result;
    case 5:
      v12 = v72;
      v13 = 2 * (char)v73;
      data[1] = (dataa >> 4) | (4 * (char)(4 * v72));
      *data = 2;
      data[2] = (2 * v13) | (v12 >> 6);
      return result;
    case 6:
      v14 = (char)v74;
      v15 = v73;
      data[1] = (dataa >> 4) | (16 * (v72 | (4 * (char)(v73 << 6))));
      *data = 2;
      data[2] = (v14 << 6) | (v15 >> 2);
      return result;
    case 7:
      v16 = v73;
      v17 = (char)v75;
      data[1] = (dataa >> 4) | (16 * (v72 | ((char)(4 * v73) << 6)));
      v18 = (v16 >> 6) | (4 * (v74 | (v17 << 8)));
      *data = 2;
      data[2] = v18;
      return result;
    case 8:
      v19 = v72;
      v20 = (dataa >> 1) | (char)(v72 << 7);
      data[2] = (char)(4 * v72) >> 3;
      v21 = v19;
      v22 = v73;
      v23 = 32 * v73;
      data[1] = v20 >> 3;
      data[4] = v22 >> 3;
      result = v5;
      *data = 3;
      data[3] = (int)(v23 | (v21 >> 3)) >> 3;
      return result;
    case 9:
      v24 = v73;
      v25 = v73 << 6;
      v26 = v72 >> 2;
      data[1] = ((dataa >> 3) | (char)(32 * v72)) >> 1;
      data[2] = (v25 | v26) >> 1;
      v27 = ((char)(v74 << 7) | (v24 >> 1)) >> 1;
      data[4] = (char)v74 >> 1;
      result = v5;
      *data = 3;
      data[3] = v27;
      return result;
    case 0xA:
      v28 = v72;
      v29 = v73;
      v30 = 2 * v73;
      data[1] = (dataa >> 4) | (2 * (char)(8 * v72));
      v31 = (v28 >> 5) | (2 * (char)(2 * v30));
      v32 = v74;
      v33 = v74;
      data[2] = v31;
      v34 = (v29 >> 6) | (2 * (char)(2 * v33));
      v35 = 2 * (char)v75;
      data[3] = v34;
      data[4] = v35 | (v32 >> 7);
      result = v5;
      *data = 3;
      return result;
    case 0xB:
      v36 = v72;
      v37 = v74;
      data[1] = (dataa >> 4) | (8 * (char)(2 * v72));
      v38 = (v36 >> 7) | (2 * (v73 | (4 * (char)(v37 << 6))));
      v39 = v75;
      v40 = 2 * v75;
      data[2] = v38;
      v41 = (v37 >> 2) | (8 * (char)(4 * v40));
      v42 = 8 * (char)v76;
      data[3] = v41;
      data[4] = v42 | (v39 >> 5);
      result = v5;
      *data = 3;
      return result;
    case 0xC:
      v43 = v73;
      v44 = v74;
      data[1] = (dataa >> 4) | (16 * (v72 | (2 * (char)(v73 << 7))));
      v45 = (v43 >> 1) | (32 * (char)(4 * v44));
      v46 = v76;
      data[2] = v45;
      v47 = (v44 >> 6) | (4 * (v75 | (8 * (char)(32 * v46))));
      v48 = 32 * (char)v77;
      data[3] = v47;
      data[4] = v48 | (v46 >> 3);
      result = v5;
      *data = 3;
      return result;
    case 0xD:
      v49 = v73;
      v50 = v75;
      data[1] = (dataa >> 4) | (16 * (v72 | (8 * (char)(32 * v73))));
      v51 = (v49 >> 3) | (32 * (v74 | (4 * (char)(v50 << 6))));
      v52 = v77;
      v53 = v77;
      data[2] = v51;
      v54 = (v50 >> 2) | ((v76 | (2 * (char)(v53 << 7))) << 6);
      v55 = (char)v78 << 7;
      data[3] = v54;
      data[4] = v55 | (v52 >> 1);
      result = v5;
      *data = 3;
      return result;
    case 0xE:
      v56 = v73;
      v57 = v75;
      data[1] = (dataa >> 4) | (16 * (v72 | (32 * (char)(8 * v73))));
      v58 = (v56 >> 5) | (8 * (v74 | ((char)(4 * v57) << 6)));
      v59 = v77;
      data[2] = v58;
      v60 = (v57 >> 6) | (4 * (v76 | ((char)(2 * v59) << 7)));
      v61 = (char)v79;
      data[3] = v60;
      v62 = (v59 >> 7) | (2 * (v78 | (v61 << 8)));
      result = v5;
      *data = 3;
      data[4] = v62;
      return result;
    case 0xF:
      v63 = v73;
      v64 = v76;
      data[1] = (dataa >> 4) | (16 * (v72 | ((char)(2 * v73) << 7)));
      v65 = (v63 >> 7) | (2 * (v74 | ((v75 | (4 * (char)(v64 << 6))) << 8)));
      v66 = v78;
      v67 = 2 * v78;
      data[2] = v65;
      v68 = (v64 >> 2) | ((v77 | (32 * (char)(4 * v67))) << 6);
      v69 = v80 << 8;
      data[3] = v68;
      v70 = (v66 >> 5) | (8 * (v79 | v69));
      *data = 3;
      data[4] = v70;
      return v5;
    default:
      return v5;
  }
}


unsigned int __thiscall Scaleform::GFx::PathDataDecoder<Scaleform::ArrayUnsafeLH_POD<unsigned char,261>>::ReadEdge(
        Scaleform::GFx::PathDataDecoder<Scaleform::ArrayUnsafeLH_POD<unsigned char,261> > *this,
        unsigned int pos,
        int *data)
{
  unsigned int result; // eax
  unsigned int v4; // ecx
  unsigned int v5; // esi
  int *v6; // eax
  int v7; // edx
  int v8; // edx
  int v9; // edi
  int v10; // edx
  int v11; // ecx
  unsigned int v12; // edx
  int v13; // ecx
  int v14; // ecx
  unsigned int v15; // edx
  unsigned __int8 v16; // dl
  int v17; // ecx
  int v18; // ecx
  unsigned __int8 v19; // al
  int v20; // edi
  unsigned int v21; // ecx
  char v22; // al
  char v23; // bl
  unsigned __int8 v24; // al
  char v25; // bl
  int v26; // ecx
  int v27; // ecx
  unsigned __int8 v28; // al
  unsigned __int8 v29; // cl
  char v30; // bl
  int v31; // edi
  unsigned __int8 v32; // al
  unsigned __int8 v33; // bl
  int v34; // edi
  int v35; // ecx
  unsigned __int8 v36; // al
  unsigned __int8 v37; // cl
  int v38; // edi
  unsigned __int8 v39; // al
  char v40; // bl
  int v41; // edi
  int v42; // ecx
  unsigned __int8 v43; // al
  unsigned __int8 v44; // cl
  int v45; // edi
  unsigned __int8 v46; // al
  int v47; // edi
  int v48; // ecx
  unsigned __int8 v49; // al
  unsigned __int8 v50; // cl
  int v51; // edi
  unsigned __int8 v52; // al
  unsigned __int8 v53; // bl
  int v54; // edi
  int v55; // ecx
  unsigned __int8 v56; // al
  unsigned __int8 v57; // cl
  int v58; // edi
  unsigned __int8 v59; // al
  int v60; // edi
  int v61; // ecx
  int v62; // ecx
  unsigned __int8 v63; // al
  unsigned __int8 v64; // cl
  int v65; // edi
  unsigned __int8 v66; // al
  char v67; // bl
  int v68; // edi
  int v69; // ecx
  int v70; // ecx
  unsigned __int8 dataa; // [esp+4h] [ebp-Ch] BYREF
  unsigned __int8 v72; // [esp+5h] [ebp-Bh]
  unsigned __int8 v73; // [esp+6h] [ebp-Ah]
  unsigned __int8 v74; // [esp+7h] [ebp-9h]
  unsigned __int8 v75; // [esp+8h] [ebp-8h]
  unsigned __int8 v76; // [esp+9h] [ebp-7h]
  unsigned __int8 v77; // [esp+Ah] [ebp-6h]
  unsigned __int8 v78; // [esp+Bh] [ebp-5h]
  unsigned __int8 v79; // [esp+Ch] [ebp-4h]
  char v80; // [esp+Dh] [ebp-3h]

  result = Scaleform::GFx::PathDataDecoder<Scaleform::ArrayUnsafeLH_POD<unsigned char,261>>::ReadRawEdge(
             this,
             pos,
             &dataa);
  v4 = dataa;
  v5 = result;
  switch ( dataa & 0xF )
  {
    case 0:
      v6 = data;
      *data = 0;
      goto LABEL_3;
    case 1:
      v8 = (dataa >> 4) | (16 * (v72 | ((char)v73 << 8)));
      *data = 0;
      data[1] = v8;
      return result;
    case 2:
      v6 = data;
      *data = 1;
LABEL_3:
      v7 = (char)v72;
      goto LABEL_4;
    case 3:
      v9 = v72;
      v6 = data;
      v10 = (char)v73 << 8;
      *data = 1;
      v7 = v9 | v10;
LABEL_4:
      v6[1] = (v4 >> 4) | (16 * v7);
      return v5;
    case 4:
      v11 = (char)v72;
      data[1] = ((dataa >> 2) | (char)(v72 << 6)) >> 2;
      *data = 2;
      data[2] = v11 >> 2;
      return result;
    case 5:
      v12 = v72;
      v13 = 2 * (char)v73;
      data[1] = (dataa >> 4) | (4 * (char)(4 * v72));
      *data = 2;
      data[2] = (2 * v13) | (v12 >> 6);
      return result;
    case 6:
      v14 = (char)v74;
      v15 = v73;
      data[1] = (dataa >> 4) | (16 * (v72 | (4 * (char)(v73 << 6))));
      *data = 2;
      data[2] = (v14 << 6) | (v15 >> 2);
      return result;
    case 7:
      v16 = v73;
      v17 = (char)v75;
      data[1] = (dataa >> 4) | (16 * (v72 | ((char)(4 * v73) << 6)));
      v18 = (v16 >> 6) | (4 * (v74 | (v17 << 8)));
      *data = 2;
      data[2] = v18;
      return result;
    case 8:
      v19 = v72;
      v20 = (dataa >> 1) | (char)(v72 << 7);
      data[2] = (char)(4 * v72) >> 3;
      v21 = v19;
      v22 = v73;
      v23 = 32 * v73;
      data[1] = v20 >> 3;
      data[4] = v22 >> 3;
      result = v5;
      *data = 3;
      data[3] = (int)(v23 | (v21 >> 3)) >> 3;
      return result;
    case 9:
      v24 = v73;
      v25 = v73 << 6;
      v26 = v72 >> 2;
      data[1] = ((dataa >> 3) | (char)(32 * v72)) >> 1;
      data[2] = (v25 | v26) >> 1;
      v27 = ((char)(v74 << 7) | (v24 >> 1)) >> 1;
      data[4] = (char)v74 >> 1;
      result = v5;
      *data = 3;
      data[3] = v27;
      return result;
    case 0xA:
      v28 = v72;
      v29 = v73;
      v30 = 2 * v73;
      data[1] = (dataa >> 4) | (2 * (char)(8 * v72));
      v31 = (v28 >> 5) | (2 * (char)(2 * v30));
      v32 = v74;
      v33 = v74;
      data[2] = v31;
      v34 = (v29 >> 6) | (2 * (char)(2 * v33));
      v35 = 2 * (char)v75;
      data[3] = v34;
      data[4] = v35 | (v32 >> 7);
      result = v5;
      *data = 3;
      return result;
    case 0xB:
      v36 = v72;
      v37 = v74;
      data[1] = (dataa >> 4) | (8 * (char)(2 * v72));
      v38 = (v36 >> 7) | (2 * (v73 | (4 * (char)(v37 << 6))));
      v39 = v75;
      v40 = 2 * v75;
      data[2] = v38;
      v41 = (v37 >> 2) | (8 * (char)(4 * v40));
      v42 = 8 * (char)v76;
      data[3] = v41;
      data[4] = v42 | (v39 >> 5);
      result = v5;
      *data = 3;
      return result;
    case 0xC:
      v43 = v73;
      v44 = v74;
      data[1] = (dataa >> 4) | (16 * (v72 | (2 * (char)(v73 << 7))));
      v45 = (v43 >> 1) | (32 * (char)(4 * v44));
      v46 = v76;
      data[2] = v45;
      v47 = (v44 >> 6) | (4 * (v75 | (8 * (char)(32 * v46))));
      v48 = 32 * (char)v77;
      data[3] = v47;
      data[4] = v48 | (v46 >> 3);
      result = v5;
      *data = 3;
      return result;
    case 0xD:
      v49 = v73;
      v50 = v75;
      data[1] = (dataa >> 4) | (16 * (v72 | (8 * (char)(32 * v73))));
      v51 = (v49 >> 3) | (32 * (v74 | (4 * (char)(v50 << 6))));
      v52 = v77;
      v53 = v77;
      data[2] = v51;
      v54 = (v50 >> 2) | ((v76 | (2 * (char)(v53 << 7))) << 6);
      v55 = (char)v78 << 7;
      data[3] = v54;
      data[4] = v55 | (v52 >> 1);
      result = v5;
      *data = 3;
      return result;
    case 0xE:
      v56 = v73;
      v57 = v75;
      data[1] = (dataa >> 4) | (16 * (v72 | (32 * (char)(8 * v73))));
      v58 = (v56 >> 5) | (8 * (v74 | ((char)(4 * v57) << 6)));
      v59 = v77;
      data[2] = v58;
      v60 = (v57 >> 6) | (4 * (v76 | ((char)(2 * v59) << 7)));
      v61 = (char)v79;
      data[3] = v60;
      v62 = (v59 >> 7) | (2 * (v78 | (v61 << 8)));
      result = v5;
      *data = 3;
      data[4] = v62;
      return result;
    case 0xF:
      v63 = v73;
      v64 = v76;
      data[1] = (dataa >> 4) | (16 * (v72 | ((char)(2 * v73) << 7)));
      v65 = (v63 >> 7) | (2 * (v74 | ((v75 | (4 * (char)(v64 << 6))) << 8)));
      v66 = v78;
      v67 = 2 * v78;
      data[2] = v65;
      v68 = (v64 >> 2) | ((v77 | (32 * (char)(4 * v67))) << 6);
      v69 = v80 << 8;
      data[3] = v68;
      v70 = (v66 >> 5) | (8 * (v79 | v69));
      *data = 3;
      data[4] = v70;
      return v5;
    default:
      return v5;
  }
}
