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
  signed __int8 v8; // dl
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
  unsigned __int8 buff[16]; // [esp+Ch] [ebp-10h] BYREF

  result = Scaleform::Render::PathDataDecoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::ReadRawEdge(
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
      v7 = data;
      *data = 0;
      goto LABEL_5;
    case 2:
      v6 = data;
      *data = 1;
LABEL_3:
      v6[1] = (16 * (char)buff[1]) | (v4 >> 4);
      return v5;
    case 3:
      v7 = data;
      *data = 1;
LABEL_5:
      v7[1] = (v4 >> 4) | (16 * (buff[1] | (((char)buff[2] | ((char)buff[3] << 8)) << 8)));
      result = v5;
      break;
    case 4:
      v8 = buff[1];
      data[1] = ((char)(buff[1] << 6) | (buff[0] >> 2)) >> 2;
      *data = 2;
      data[2] = v8 >> 2;
      break;
    case 5:
      v9 = buff[1] >> 6;
      v10 = 4 * (char)buff[2];
      data[1] = (buff[0] >> 4) | (4 * (char)(4 * buff[1]));
      *data = 2;
      data[2] = v10 | v9;
      break;
    case 6:
      v11 = buff[2] >> 2;
      v12 = (char)buff[3] << 6;
      data[1] = (buff[0] >> 4) | (16 * (buff[1] | (4 * (char)(buff[2] << 6))));
      *data = 2;
      data[2] = v12 | v11;
      break;
    case 7:
      v13 = buff[4];
      v14 = (char)buff[7];
      data[1] = (buff[0] >> 4) | (16 * (buff[1] | ((buff[2] | ((buff[3] | (4 * (char)(buff[4] << 6))) << 8)) << 8)));
      v15 = (v13 >> 2) | ((buff[5] | ((buff[6] | (v14 << 8)) << 8)) << 6);
      *data = 2;
      data[2] = v15;
      break;
    case 8:
      v16 = buff[1];
      data[1] = ((char)(buff[1] << 7) | (buff[0] >> 1)) >> 3;
      data[2] = (char)(4 * v16) >> 3;
      v17 = ((char)(32 * buff[2]) | (v16 >> 3)) >> 3;
      data[4] = (char)buff[2] >> 3;
      result = v5;
      *data = 3;
      data[3] = v17;
      break;
    case 9:
      v18 = buff[1];
      data[1] = ((char)(32 * buff[1]) | (buff[0] >> 3)) >> 1;
      v19 = v18;
      v20 = buff[2];
      data[2] = (int)((char)(buff[2] << 6) | (v19 >> 2)) >> 1;
      v21 = ((char)(buff[3] << 7) | (v20 >> 1)) >> 1;
      data[4] = (char)buff[3] >> 1;
      result = v5;
      *data = 3;
      data[3] = v21;
      break;
    case 0xA:
      v22 = buff[1];
      v23 = buff[2];
      v24 = 2 * buff[2];
      data[1] = (buff[0] >> 4) | (2 * (char)(8 * buff[1]));
      v25 = (v22 >> 5) | (2 * (char)(2 * v24));
      v26 = buff[3];
      v27 = buff[3];
      data[2] = v25;
      v28 = (2 * (char)buff[4]) | (v26 >> 7);
      data[3] = (v23 >> 6) | (2 * (char)(2 * v27));
      data[4] = v28;
      result = v5;
      *data = 3;
      break;
    case 0xB:
      v29 = buff[1];
      v30 = buff[3];
      data[1] = (buff[0] >> 4) | (8 * (char)(2 * buff[1]));
      v31 = (v29 >> 7) | (2 * (buff[2] | (4 * (char)(v30 << 6))));
      v32 = buff[4];
      v33 = 2 * buff[4];
      data[2] = v31;
      v34 = (8 * (char)buff[5]) | (v32 >> 5);
      data[3] = (v30 >> 2) | (8 * (char)(4 * v33));
      data[4] = v34;
      result = v5;
      *data = 3;
      break;
    case 0xC:
      v35 = buff[2];
      v36 = buff[3];
      data[1] = (buff[0] >> 4) | (16 * (buff[1] | (2 * (char)(buff[2] << 7))));
      v37 = (v35 >> 1) | (32 * (char)(4 * v36));
      v38 = buff[5];
      data[2] = v37;
      v39 = (v36 >> 6) | (4 * (buff[4] | (8 * (char)(32 * v38))));
      v40 = (32 * (char)buff[6]) | (v38 >> 3);
      data[3] = v39;
      data[4] = v40;
      result = v5;
      *data = 3;
      break;
    case 0xD:
      v41 = buff[2];
      v42 = buff[4];
      data[1] = (buff[0] >> 4) | (16 * (buff[1] | (8 * (char)(32 * buff[2]))));
      v43 = (v41 >> 3) | (32 * (buff[3] | (4 * (char)(v42 << 6))));
      v44 = buff[6];
      v45 = buff[6];
      data[2] = v43;
      v46 = ((char)buff[7] << 7) | (v44 >> 1);
      data[3] = (v42 >> 2) | ((buff[5] | (2 * (char)(v45 << 7))) << 6);
      data[4] = v46;
      result = v5;
      *data = 3;
      break;
    case 0xE:
      v47 = buff[4];
      v48 = buff[8];
      data[1] = (buff[0] >> 4) | (16 * (buff[1] | ((buff[2] | ((buff[3] | (8 * (char)(32 * buff[4]))) << 8)) << 8)));
      v49 = (v47 >> 3) | (32 * (buff[5] | ((buff[6] | ((buff[7] | (4 * (char)(v48 << 6))) << 8)) << 8)));
      v50 = buff[12];
      data[2] = v49;
      v51 = (v48 >> 2) | ((buff[9] | ((buff[10] | ((buff[11] | (2 * (char)(v50 << 7))) << 8)) << 8)) << 6);
      v52 = (char)buff[15];
      data[3] = v51;
      v53 = (v50 >> 1) | ((buff[13] | ((buff[14] | (v52 << 8)) << 8)) << 7);
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
