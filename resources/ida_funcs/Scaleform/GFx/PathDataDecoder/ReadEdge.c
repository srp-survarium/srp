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
  signed __int8 v22; // al
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
  unsigned __int8 buff[12]; // [esp+4h] [ebp-Ch] BYREF

  result = Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::ReadRawEdge(
             this,
             pos,
             buff);
  v4 = buff[0];
  v5 = result;
  switch ( buff[0] & 0xF )
  {
    case 0:
      v6 = data;
      *data = 0;
      goto LABEL_3;
    case 1:
      v8 = (buff[0] >> 4) | (16 * (buff[1] | ((char)buff[2] << 8)));
      *data = 0;
      data[1] = v8;
      return result;
    case 2:
      v6 = data;
      *data = 1;
LABEL_3:
      v7 = (char)buff[1];
      goto LABEL_4;
    case 3:
      v9 = buff[1];
      v6 = data;
      v10 = (char)buff[2] << 8;
      *data = 1;
      v7 = v9 | v10;
LABEL_4:
      v6[1] = (v4 >> 4) | (16 * v7);
      return v5;
    case 4:
      v11 = (char)buff[1];
      data[1] = ((buff[0] >> 2) | (char)(buff[1] << 6)) >> 2;
      *data = 2;
      data[2] = v11 >> 2;
      return result;
    case 5:
      v12 = buff[1];
      v13 = 2 * (char)buff[2];
      data[1] = (buff[0] >> 4) | (4 * (char)(4 * buff[1]));
      *data = 2;
      data[2] = (2 * v13) | (v12 >> 6);
      return result;
    case 6:
      v14 = (char)buff[3];
      v15 = buff[2];
      data[1] = (buff[0] >> 4) | (16 * (buff[1] | (4 * (char)(buff[2] << 6))));
      *data = 2;
      data[2] = (v14 << 6) | (v15 >> 2);
      return result;
    case 7:
      v16 = buff[2];
      v17 = (char)buff[4];
      data[1] = (buff[0] >> 4) | (16 * (buff[1] | ((char)(4 * buff[2]) << 6)));
      v18 = (v16 >> 6) | (4 * (buff[3] | (v17 << 8)));
      *data = 2;
      data[2] = v18;
      return result;
    case 8:
      v19 = buff[1];
      v20 = (buff[0] >> 1) | (char)(buff[1] << 7);
      data[2] = (char)(4 * buff[1]) >> 3;
      v21 = v19;
      v22 = buff[2];
      v23 = 32 * buff[2];
      data[1] = v20 >> 3;
      data[4] = v22 >> 3;
      result = v5;
      *data = 3;
      data[3] = (int)(v23 | (v21 >> 3)) >> 3;
      return result;
    case 9:
      v24 = buff[2];
      v25 = buff[2] << 6;
      v26 = buff[1] >> 2;
      data[1] = ((buff[0] >> 3) | (char)(32 * buff[1])) >> 1;
      data[2] = (v25 | v26) >> 1;
      v27 = ((char)(buff[3] << 7) | (v24 >> 1)) >> 1;
      data[4] = (char)buff[3] >> 1;
      result = v5;
      *data = 3;
      data[3] = v27;
      return result;
    case 0xA:
      v28 = buff[1];
      v29 = buff[2];
      v30 = 2 * buff[2];
      data[1] = (buff[0] >> 4) | (2 * (char)(8 * buff[1]));
      v31 = (v28 >> 5) | (2 * (char)(2 * v30));
      v32 = buff[3];
      v33 = buff[3];
      data[2] = v31;
      v34 = (v29 >> 6) | (2 * (char)(2 * v33));
      v35 = 2 * (char)buff[4];
      data[3] = v34;
      data[4] = v35 | (v32 >> 7);
      result = v5;
      *data = 3;
      return result;
    case 0xB:
      v36 = buff[1];
      v37 = buff[3];
      data[1] = (buff[0] >> 4) | (8 * (char)(2 * buff[1]));
      v38 = (v36 >> 7) | (2 * (buff[2] | (4 * (char)(v37 << 6))));
      v39 = buff[4];
      v40 = 2 * buff[4];
      data[2] = v38;
      v41 = (v37 >> 2) | (8 * (char)(4 * v40));
      v42 = 8 * (char)buff[5];
      data[3] = v41;
      data[4] = v42 | (v39 >> 5);
      result = v5;
      *data = 3;
      return result;
    case 0xC:
      v43 = buff[2];
      v44 = buff[3];
      data[1] = (buff[0] >> 4) | (16 * (buff[1] | (2 * (char)(buff[2] << 7))));
      v45 = (v43 >> 1) | (32 * (char)(4 * v44));
      v46 = buff[5];
      data[2] = v45;
      v47 = (v44 >> 6) | (4 * (buff[4] | (8 * (char)(32 * v46))));
      v48 = 32 * (char)buff[6];
      data[3] = v47;
      data[4] = v48 | (v46 >> 3);
      result = v5;
      *data = 3;
      return result;
    case 0xD:
      v49 = buff[2];
      v50 = buff[4];
      data[1] = (buff[0] >> 4) | (16 * (buff[1] | (8 * (char)(32 * buff[2]))));
      v51 = (v49 >> 3) | (32 * (buff[3] | (4 * (char)(v50 << 6))));
      v52 = buff[6];
      v53 = buff[6];
      data[2] = v51;
      v54 = (v50 >> 2) | ((buff[5] | (2 * (char)(v53 << 7))) << 6);
      v55 = (char)buff[7] << 7;
      data[3] = v54;
      data[4] = v55 | (v52 >> 1);
      result = v5;
      *data = 3;
      return result;
    case 0xE:
      v56 = buff[2];
      v57 = buff[4];
      data[1] = (buff[0] >> 4) | (16 * (buff[1] | (32 * (char)(8 * buff[2]))));
      v58 = (v56 >> 5) | (8 * (buff[3] | ((char)(4 * v57) << 6)));
      v59 = buff[6];
      data[2] = v58;
      v60 = (v57 >> 6) | (4 * (buff[5] | ((char)(2 * v59) << 7)));
      v61 = (char)buff[8];
      data[3] = v60;
      v62 = (v59 >> 7) | (2 * (buff[7] | (v61 << 8)));
      result = v5;
      *data = 3;
      data[4] = v62;
      return result;
    case 0xF:
      v63 = buff[2];
      v64 = buff[5];
      data[1] = (buff[0] >> 4) | (16 * (buff[1] | ((char)(2 * buff[2]) << 7)));
      v65 = (v63 >> 7) | (2 * (buff[3] | ((buff[4] | (4 * (char)(v64 << 6))) << 8)));
      v66 = buff[7];
      v67 = 2 * buff[7];
      data[2] = v65;
      v68 = (v64 >> 2) | ((buff[6] | (32 * (char)(4 * v67))) << 6);
      v69 = (char)buff[9] << 8;
      data[3] = v68;
      v70 = (v66 >> 5) | (8 * (buff[8] | v69));
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
  signed __int8 v22; // al
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
  unsigned __int8 buff[12]; // [esp+4h] [ebp-Ch] BYREF

  result = Scaleform::GFx::PathDataDecoder<Scaleform::ArrayUnsafeLH_POD<unsigned char,261>>::ReadRawEdge(
             this,
             pos,
             buff);
  v4 = buff[0];
  v5 = result;
  switch ( buff[0] & 0xF )
  {
    case 0:
      v6 = data;
      *data = 0;
      goto LABEL_3;
    case 1:
      v8 = (buff[0] >> 4) | (16 * (buff[1] | ((char)buff[2] << 8)));
      *data = 0;
      data[1] = v8;
      return result;
    case 2:
      v6 = data;
      *data = 1;
LABEL_3:
      v7 = (char)buff[1];
      goto LABEL_4;
    case 3:
      v9 = buff[1];
      v6 = data;
      v10 = (char)buff[2] << 8;
      *data = 1;
      v7 = v9 | v10;
LABEL_4:
      v6[1] = (v4 >> 4) | (16 * v7);
      return v5;
    case 4:
      v11 = (char)buff[1];
      data[1] = ((buff[0] >> 2) | (char)(buff[1] << 6)) >> 2;
      *data = 2;
      data[2] = v11 >> 2;
      return result;
    case 5:
      v12 = buff[1];
      v13 = 2 * (char)buff[2];
      data[1] = (buff[0] >> 4) | (4 * (char)(4 * buff[1]));
      *data = 2;
      data[2] = (2 * v13) | (v12 >> 6);
      return result;
    case 6:
      v14 = (char)buff[3];
      v15 = buff[2];
      data[1] = (buff[0] >> 4) | (16 * (buff[1] | (4 * (char)(buff[2] << 6))));
      *data = 2;
      data[2] = (v14 << 6) | (v15 >> 2);
      return result;
    case 7:
      v16 = buff[2];
      v17 = (char)buff[4];
      data[1] = (buff[0] >> 4) | (16 * (buff[1] | ((char)(4 * buff[2]) << 6)));
      v18 = (v16 >> 6) | (4 * (buff[3] | (v17 << 8)));
      *data = 2;
      data[2] = v18;
      return result;
    case 8:
      v19 = buff[1];
      v20 = (buff[0] >> 1) | (char)(buff[1] << 7);
      data[2] = (char)(4 * buff[1]) >> 3;
      v21 = v19;
      v22 = buff[2];
      v23 = 32 * buff[2];
      data[1] = v20 >> 3;
      data[4] = v22 >> 3;
      result = v5;
      *data = 3;
      data[3] = (int)(v23 | (v21 >> 3)) >> 3;
      return result;
    case 9:
      v24 = buff[2];
      v25 = buff[2] << 6;
      v26 = buff[1] >> 2;
      data[1] = ((buff[0] >> 3) | (char)(32 * buff[1])) >> 1;
      data[2] = (v25 | v26) >> 1;
      v27 = ((char)(buff[3] << 7) | (v24 >> 1)) >> 1;
      data[4] = (char)buff[3] >> 1;
      result = v5;
      *data = 3;
      data[3] = v27;
      return result;
    case 0xA:
      v28 = buff[1];
      v29 = buff[2];
      v30 = 2 * buff[2];
      data[1] = (buff[0] >> 4) | (2 * (char)(8 * buff[1]));
      v31 = (v28 >> 5) | (2 * (char)(2 * v30));
      v32 = buff[3];
      v33 = buff[3];
      data[2] = v31;
      v34 = (v29 >> 6) | (2 * (char)(2 * v33));
      v35 = 2 * (char)buff[4];
      data[3] = v34;
      data[4] = v35 | (v32 >> 7);
      result = v5;
      *data = 3;
      return result;
    case 0xB:
      v36 = buff[1];
      v37 = buff[3];
      data[1] = (buff[0] >> 4) | (8 * (char)(2 * buff[1]));
      v38 = (v36 >> 7) | (2 * (buff[2] | (4 * (char)(v37 << 6))));
      v39 = buff[4];
      v40 = 2 * buff[4];
      data[2] = v38;
      v41 = (v37 >> 2) | (8 * (char)(4 * v40));
      v42 = 8 * (char)buff[5];
      data[3] = v41;
      data[4] = v42 | (v39 >> 5);
      result = v5;
      *data = 3;
      return result;
    case 0xC:
      v43 = buff[2];
      v44 = buff[3];
      data[1] = (buff[0] >> 4) | (16 * (buff[1] | (2 * (char)(buff[2] << 7))));
      v45 = (v43 >> 1) | (32 * (char)(4 * v44));
      v46 = buff[5];
      data[2] = v45;
      v47 = (v44 >> 6) | (4 * (buff[4] | (8 * (char)(32 * v46))));
      v48 = 32 * (char)buff[6];
      data[3] = v47;
      data[4] = v48 | (v46 >> 3);
      result = v5;
      *data = 3;
      return result;
    case 0xD:
      v49 = buff[2];
      v50 = buff[4];
      data[1] = (buff[0] >> 4) | (16 * (buff[1] | (8 * (char)(32 * buff[2]))));
      v51 = (v49 >> 3) | (32 * (buff[3] | (4 * (char)(v50 << 6))));
      v52 = buff[6];
      v53 = buff[6];
      data[2] = v51;
      v54 = (v50 >> 2) | ((buff[5] | (2 * (char)(v53 << 7))) << 6);
      v55 = (char)buff[7] << 7;
      data[3] = v54;
      data[4] = v55 | (v52 >> 1);
      result = v5;
      *data = 3;
      return result;
    case 0xE:
      v56 = buff[2];
      v57 = buff[4];
      data[1] = (buff[0] >> 4) | (16 * (buff[1] | (32 * (char)(8 * buff[2]))));
      v58 = (v56 >> 5) | (8 * (buff[3] | ((char)(4 * v57) << 6)));
      v59 = buff[6];
      data[2] = v58;
      v60 = (v57 >> 6) | (4 * (buff[5] | ((char)(2 * v59) << 7)));
      v61 = (char)buff[8];
      data[3] = v60;
      v62 = (v59 >> 7) | (2 * (buff[7] | (v61 << 8)));
      result = v5;
      *data = 3;
      data[4] = v62;
      return result;
    case 0xF:
      v63 = buff[2];
      v64 = buff[5];
      data[1] = (buff[0] >> 4) | (16 * (buff[1] | ((char)(2 * buff[2]) << 7)));
      v65 = (v63 >> 7) | (2 * (buff[3] | ((buff[4] | (4 * (char)(v64 << 6))) << 8)));
      v66 = buff[7];
      v67 = 2 * buff[7];
      data[2] = v65;
      v68 = (v64 >> 2) | ((buff[6] | (32 * (char)(4 * v67))) << 6);
      v69 = (char)buff[9] << 8;
      data[3] = v68;
      v70 = (v66 >> 5) | (8 * (buff[8] | v69));
      *data = 3;
      data[4] = v70;
      return v5;
    default:
      return v5;
  }
}
