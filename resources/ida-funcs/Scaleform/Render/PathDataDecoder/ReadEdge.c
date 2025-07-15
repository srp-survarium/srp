unsigned int __thiscall Scaleform::Render::PathDataDecoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::ReadEdge(
        Scaleform::Render::PathDataDecoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        unsigned int pos,
        int *data)
{
  unsigned int result; // eax
  unsigned int v4; // ecx
  unsigned int v5; // esi
  int *v6; // eax
  int *v7; // eax
  char v8; // dl
  int v9; // edx
  int v10; // ecx
  int v11; // edx
  int v12; // ecx
  unsigned __int8 v13; // dl
  int v14; // ecx
  int v15; // ecx
  unsigned __int8 v16; // al
  int v17; // ecx
  unsigned __int8 v18; // al
  unsigned int v19; // ecx
  unsigned __int8 v20; // al
  int v21; // ecx
  unsigned __int8 v22; // al
  unsigned __int8 v23; // cl
  char v24; // bl
  int v25; // edi
  unsigned __int8 v26; // al
  unsigned __int8 v27; // bl
  int v28; // eax
  unsigned __int8 v29; // al
  unsigned __int8 v30; // cl
  int v31; // edi
  unsigned __int8 v32; // al
  char v33; // bl
  int v34; // eax
  unsigned __int8 v35; // al
  unsigned __int8 v36; // cl
  int v37; // edi
  unsigned __int8 v38; // al
  int v39; // edi
  int v40; // eax
  unsigned __int8 v41; // al
  unsigned __int8 v42; // cl
  int v43; // edi
  unsigned __int8 v44; // al
  unsigned __int8 v45; // bl
  int v46; // eax
  unsigned __int8 v47; // al
  unsigned __int8 v48; // cl
  int v49; // edi
  unsigned __int8 v50; // al
  int v51; // edi
  int v52; // ecx
  int v53; // ecx
  unsigned __int8 dataa; // [esp+Ch] [ebp-10h] BYREF
  unsigned __int8 v55; // [esp+Dh] [ebp-Fh]
  unsigned __int8 v56; // [esp+Eh] [ebp-Eh]
  unsigned __int8 v57; // [esp+Fh] [ebp-Dh]
  unsigned __int8 v58; // [esp+10h] [ebp-Ch]
  unsigned __int8 v59; // [esp+11h] [ebp-Bh]
  unsigned __int8 v60; // [esp+12h] [ebp-Ah]
  unsigned __int8 v61; // [esp+13h] [ebp-9h]
  unsigned __int8 v62; // [esp+14h] [ebp-8h]
  unsigned __int8 v63; // [esp+15h] [ebp-7h]
  unsigned __int8 v64; // [esp+16h] [ebp-6h]
  unsigned __int8 v65; // [esp+17h] [ebp-5h]
  unsigned __int8 v66; // [esp+18h] [ebp-4h]
  unsigned __int8 v67; // [esp+19h] [ebp-3h]
  unsigned __int8 v68; // [esp+1Ah] [ebp-2h]
  char v69; // [esp+1Bh] [ebp-1h]

  result = Scaleform::Render::PathDataDecoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::ReadRawEdge(
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
      v7 = data;
      *data = 0;
      goto LABEL_5;
    case 2:
      v6 = data;
      *data = 1;
LABEL_3:
      v6[1] = (16 * (char)v55) | (v4 >> 4);
      return v5;
    case 3:
      v7 = data;
      *data = 1;
LABEL_5:
      v7[1] = (v4 >> 4) | (16 * (v55 | (((char)v56 | ((char)v57 << 8)) << 8)));
      result = v5;
      break;
    case 4:
      v8 = v55;
      data[1] = ((char)(v55 << 6) | (dataa >> 2)) >> 2;
      *data = 2;
      data[2] = v8 >> 2;
      break;
    case 5:
      v9 = v55 >> 6;
      v10 = 4 * (char)v56;
      data[1] = (dataa >> 4) | (4 * (char)(4 * v55));
      *data = 2;
      data[2] = v10 | v9;
      break;
    case 6:
      v11 = v56 >> 2;
      v12 = (char)v57 << 6;
      data[1] = (dataa >> 4) | (16 * (v55 | (4 * (char)(v56 << 6))));
      *data = 2;
      data[2] = v12 | v11;
      break;
    case 7:
      v13 = v58;
      v14 = (char)v61;
      data[1] = (dataa >> 4) | (16 * (v55 | ((v56 | ((v57 | (4 * (char)(v58 << 6))) << 8)) << 8)));
      v15 = (v13 >> 2) | ((v59 | ((v60 | (v14 << 8)) << 8)) << 6);
      *data = 2;
      data[2] = v15;
      break;
    case 8:
      v16 = v55;
      data[1] = ((char)(v55 << 7) | (dataa >> 1)) >> 3;
      data[2] = (char)(4 * v16) >> 3;
      v17 = ((char)(32 * v56) | (v16 >> 3)) >> 3;
      data[4] = (char)v56 >> 3;
      result = v5;
      *data = 3;
      data[3] = v17;
      break;
    case 9:
      v18 = v55;
      data[1] = ((char)(32 * v55) | (dataa >> 3)) >> 1;
      v19 = v18;
      v20 = v56;
      data[2] = (int)((char)(v56 << 6) | (v19 >> 2)) >> 1;
      v21 = ((char)(v57 << 7) | (v20 >> 1)) >> 1;
      data[4] = (char)v57 >> 1;
      result = v5;
      *data = 3;
      data[3] = v21;
      break;
    case 0xA:
      v22 = v55;
      v23 = v56;
      v24 = 2 * v56;
      data[1] = (dataa >> 4) | (2 * (char)(8 * v55));
      v25 = (v22 >> 5) | (2 * (char)(2 * v24));
      v26 = v57;
      v27 = v57;
      data[2] = v25;
      v28 = (2 * (char)v58) | (v26 >> 7);
      data[3] = (v23 >> 6) | (2 * (char)(2 * v27));
      data[4] = v28;
      result = v5;
      *data = 3;
      break;
    case 0xB:
      v29 = v55;
      v30 = v57;
      data[1] = (dataa >> 4) | (8 * (char)(2 * v55));
      v31 = (v29 >> 7) | (2 * (v56 | (4 * (char)(v30 << 6))));
      v32 = v58;
      v33 = 2 * v58;
      data[2] = v31;
      v34 = (8 * (char)v59) | (v32 >> 5);
      data[3] = (v30 >> 2) | (8 * (char)(4 * v33));
      data[4] = v34;
      result = v5;
      *data = 3;
      break;
    case 0xC:
      v35 = v56;
      v36 = v57;
      data[1] = (dataa >> 4) | (16 * (v55 | (2 * (char)(v56 << 7))));
      v37 = (v35 >> 1) | (32 * (char)(4 * v36));
      v38 = v59;
      data[2] = v37;
      v39 = (v36 >> 6) | (4 * (v58 | (8 * (char)(32 * v38))));
      v40 = (32 * (char)v60) | (v38 >> 3);
      data[3] = v39;
      data[4] = v40;
      result = v5;
      *data = 3;
      break;
    case 0xD:
      v41 = v56;
      v42 = v58;
      data[1] = (dataa >> 4) | (16 * (v55 | (8 * (char)(32 * v56))));
      v43 = (v41 >> 3) | (32 * (v57 | (4 * (char)(v42 << 6))));
      v44 = v60;
      v45 = v60;
      data[2] = v43;
      v46 = ((char)v61 << 7) | (v44 >> 1);
      data[3] = (v42 >> 2) | ((v59 | (2 * (char)(v45 << 7))) << 6);
      data[4] = v46;
      result = v5;
      *data = 3;
      break;
    case 0xE:
      v47 = v58;
      v48 = v62;
      data[1] = (dataa >> 4) | (16 * (v55 | ((v56 | ((v57 | (8 * (char)(32 * v58))) << 8)) << 8)));
      v49 = (v47 >> 3) | (32 * (v59 | ((v60 | ((v61 | (4 * (char)(v48 << 6))) << 8)) << 8)));
      v50 = v66;
      data[2] = v49;
      v51 = (v48 >> 2) | ((v63 | ((v64 | ((v65 | (2 * (char)(v50 << 7))) << 8)) << 8)) << 6);
      v52 = v69;
      data[3] = v51;
      v53 = (v50 >> 1) | ((v67 | ((v68 | (v52 << 8)) << 8)) << 7);
      result = v5;
      *data = 3;
      data[4] = v53;
      break;
    case 0xF:
      *data = 4;
      break;
    default:
      return result;
  }
  return result;
}
