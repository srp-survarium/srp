Scaleform::Render::Matrix4x4<float> *__thiscall Scaleform::Render::Matrix4x4<float>::GetInverse(
        Scaleform::Render::Matrix4x4<float> *this,
        Scaleform::Render::Matrix4x4<float> *result)
{
  double v3; // st5
  double v4; // st6
  double v5; // st4
  double st3_1; // st3
  double st7_4; // st7
  float varFC; // [esp+1190h] [ebp-FCh]
  float varF0; // [esp+119Ch] [ebp-F0h]
  float v6; // [esp+11A0h] [ebp-ECh]
  float v9; // [esp+11ACh] [ebp-E0h]
  float v10; // [esp+11B0h] [ebp-DCh]
  float v13; // [esp+11BCh] [ebp-D0h]
  float v16; // [esp+11C8h] [ebp-C4h]
  float varB4; // [esp+11D8h] [ebp-B4h]
  float v17; // [esp+11D8h] [ebp-B4h]
  float v18; // [esp+11D8h] [ebp-B4h]
  float v19; // [esp+11D8h] [ebp-B4h]
  float v12; // [esp+11D8h] [ebp-B4h]
  float v21; // [esp+11DCh] [ebp-B0h]
  float v22; // [esp+11DCh] [ebp-B0h]
  float v23; // [esp+11DCh] [ebp-B0h]
  float v24; // [esp+11E0h] [ebp-ACh]
  float v25; // [esp+11E0h] [ebp-ACh]
  float v26; // [esp+11E0h] [ebp-ACh]
  float v27; // [esp+11E4h] [ebp-A8h]
  float v28; // [esp+11E4h] [ebp-A8h]
  float v29; // [esp+11E4h] [ebp-A8h]
  float v30; // [esp+11E8h] [ebp-A4h]
  float v31; // [esp+11E8h] [ebp-A4h]
  float v32; // [esp+11E8h] [ebp-A4h]
  float v33; // [esp+11ECh] [ebp-A0h]
  float v34; // [esp+11ECh] [ebp-A0h]
  float v35; // [esp+11ECh] [ebp-A0h]
  float v36; // [esp+11F0h] [ebp-9Ch]
  float v37; // [esp+11F4h] [ebp-98h]
  float v38; // [esp+11F8h] [ebp-94h]
  float v39; // [esp+11F8h] [ebp-94h]
  float v40; // [esp+11F8h] [ebp-94h]
  float v41; // [esp+11FCh] [ebp-90h]
  float v42; // [esp+1200h] [ebp-8Ch]
  float v43; // [esp+1204h] [ebp-88h]
  float v7; // [esp+1204h] [ebp-88h]
  float v45; // [esp+1208h] [ebp-84h]
  float v46; // [esp+1208h] [ebp-84h]
  float v47; // [esp+120Ch] [ebp-80h]
  float v48; // [esp+1210h] [ebp-7Ch]
  float v49; // [esp+1210h] [ebp-7Ch]
  float v50; // [esp+1210h] [ebp-7Ch]
  float v51; // [esp+1214h] [ebp-78h]
  float v52; // [esp+1214h] [ebp-78h]
  float v8; // [esp+1214h] [ebp-78h]
  float v54; // [esp+1218h] [ebp-74h]
  float v55; // [esp+121Ch] [ebp-70h]
  float v56; // [esp+1220h] [ebp-6Ch]
  float v57; // [esp+1224h] [ebp-68h]
  float v58; // [esp+1228h] [ebp-64h]
  float v14; // [esp+122Ch] [ebp-60h]
  float v60; // [esp+1230h] [ebp-5Ch]
  float v61; // [esp+1230h] [ebp-5Ch]
  float v11; // [esp+1234h] [ebp-58h]
  float v15; // [esp+1238h] [ebp-54h]
  float v64; // [esp+123Ch] [ebp-50h]
  float v65; // [esp+1240h] [ebp-4Ch]
  float v66; // [esp+1244h] [ebp-48h]
  float v67; // [esp+1248h] [ebp-44h]
  unsigned __int8 dst[64]; // [esp+124Ch] [ebp-40h] BYREF

  v36 = this->M[1][0];
  v42 = this->M[1][1];
  v41 = this->M[1][2];
  v37 = this->M[1][3];
  v58 = this->M[2][0];
  v57 = this->M[2][1];
  v47 = this->M[2][2];
  v55 = this->M[2][3];
  v56 = this->M[3][0];
  v54 = this->M[3][1];
  v43 = this->M[3][2];
  v45 = this->M[3][3];
  v30 = v54 * v58 - v56 * v57;
  v24 = v43 * v58 - v56 * v47;
  v27 = v58 * v45 - v56 * v55;
  v21 = v43 * v57 - v54 * v47;
  v33 = v57 * v45 - v54 * v55;
  v38 = v45 * v47 - v43 * v55;
  v65 = v21 * v37 + v38 * v42 - v33 * v41;
  v64 = -(v38 * v36 - v27 * v41 + v24 * v37);
  v66 = v37 * v30 + v33 * v36 - v27 * v42;
  v67 = -(v41 * v30 + v36 * v21 - v42 * v24);
  v3 = this->M[0][1];
  v4 = this->M[0][0];
  v5 = this->M[0][2];
  st3_1 = this->M[0][3];
  varB4 = v67 * st3_1 + v66 * v5 + v65 * v4 + v64 * v3;
  if ( varB4 == 0.0 )
  {
    memset((int)dst, 0, sizeof(dst));
    *(float *)dst = 1.0;
    *(float *)&dst[20] = 1.0;
    *(float *)&dst[40] = 1.0;
    *(float *)&dst[60] = 1.0;
    *(float *)&dst[12] = -this->M[0][3];
    *(float *)&dst[28] = -this->M[1][3];
    *(float *)&dst[44] = -this->M[2][3];
    memcpy((unsigned __int8 *)result, dst, sizeof(Scaleform::Render::Matrix4x4<float>));
  }
  else
  {
    v17 = 1.0 / varB4;
    st7_4 = v17;
    v60 = -((v38 * v3 - v33 * v5 + v21 * st3_1) * v17);
    v48 = (v38 * v4 - v27 * v5 + v24 * st3_1) * v17;
    v51 = -((v33 * v4 - v27 * v3 + v30 * st3_1) * v17);
    v14 = (v21 * v4 - v24 * v3 + v30 * v5) * v17;
    v31 = v54 * v36 - v56 * v42;
    v25 = v43 * v36 - v56 * v41;
    v28 = v45 * v36 - v56 * v37;
    v22 = v43 * v42 - v54 * v41;
    v34 = v45 * v42 - v54 * v37;
    v39 = v45 * v41 - v43 * v37;
    v46 = (v39 * v3 - v34 * v5 + v22 * st3_1) * v17;
    v7 = -((v39 * v4 - v28 * v5 + v25 * st3_1) * v17);
    v11 = (v34 * v4 - v28 * v3 + v31 * st3_1) * v17;
    v15 = -((v22 * v4 - v25 * v3 + v31 * v5) * v17);
    v32 = v57 * v36 - v58 * v42;
    v26 = v47 * v36 - v58 * v41;
    v29 = v55 * v36 - v58 * v37;
    v23 = v47 * v42 - v57 * v41;
    v35 = v55 * v42 - v57 * v37;
    v40 = v55 * v41 - v47 * v37;
    v18 = (v23 * v4 - v26 * v3 + v32 * v5) * v17;
    v16 = v18;
    v19 = st7_4 * v67;
    v13 = v19;
    v12 = -((v35 * v4 - v29 * v3 + v32 * st3_1) * st7_4);
    v10 = v51;
    v52 = st7_4 * v66;
    v9 = v52;
    v8 = (v4 * v40 - v29 * v5 + v26 * st3_1) * st7_4;
    v6 = v48;
    v49 = st7_4 * v64;
    varF0 = v49;
    v50 = -((st3_1 * v23 + v3 * v40 - v5 * v35) * st7_4);
    varFC = v60;
    v61 = st7_4 * v65;
    Scaleform::Render::Matrix4x4<float>::Matrix4x4<float>(
      result,
      v61,
      varFC,
      v46,
      v50,
      varF0,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16);
  }
  return result;
}
