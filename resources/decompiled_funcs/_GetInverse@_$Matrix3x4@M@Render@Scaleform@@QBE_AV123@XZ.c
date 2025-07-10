Scaleform::Render::Matrix3x4<float> *__thiscall Scaleform::Render::Matrix3x4<float>::GetInverse(
        Scaleform::Render::Matrix3x4<float> *this,
        Scaleform::Render::Matrix3x4<float> *result)
{
  double v3; // st6
  double v4; // st3
  double v5; // st1
  double v6; // st4
  double v7; // st5
  double v8; // st6
  double v9; // st4
  Scaleform::Render::Matrix3x4<float> *v10; // eax
  double v11; // st3
  double v12; // st2
  double v13; // st7
  float v14; // [esp+CD4h] [ebp-98h]
  float v15; // [esp+CD4h] [ebp-98h]
  float v16; // [esp+CD4h] [ebp-98h]
  float v17; // [esp+CD4h] [ebp-98h]
  float v18; // [esp+CD4h] [ebp-98h]
  float v19; // [esp+CD4h] [ebp-98h]
  float v20; // [esp+CD4h] [ebp-98h]
  float v21; // [esp+CD8h] [ebp-94h]
  float v22; // [esp+CD8h] [ebp-94h]
  float v23; // [esp+CD8h] [ebp-94h]
  float v24; // [esp+CDCh] [ebp-90h]
  float v25; // [esp+CDCh] [ebp-90h]
  float v26; // [esp+CDCh] [ebp-90h]
  float v27; // [esp+CE0h] [ebp-8Ch]
  float v28; // [esp+CE0h] [ebp-8Ch]
  float v29; // [esp+CE0h] [ebp-8Ch]
  float v30; // [esp+CE4h] [ebp-88h]
  float v31; // [esp+CE8h] [ebp-84h]
  float v32; // [esp+CECh] [ebp-80h]
  float v33; // [esp+CF0h] [ebp-7Ch]
  float v34; // [esp+CF4h] [ebp-78h]
  float v35; // [esp+CF8h] [ebp-74h]
  float v36; // [esp+CF8h] [ebp-74h]
  float v37; // [esp+CFCh] [ebp-70h]
  float v38; // [esp+CFCh] [ebp-70h]
  float v39; // [esp+D00h] [ebp-6Ch]
  float v40; // [esp+D04h] [ebp-68h]
  float v41; // [esp+D08h] [ebp-64h]
  float v42; // [esp+D08h] [ebp-64h]
  float v43; // [esp+D0Ch] [ebp-60h]
  float v44; // [esp+D10h] [ebp-5Ch]
  float v45; // [esp+D14h] [ebp-58h]
  float v46; // [esp+D14h] [ebp-58h]
  float v47; // [esp+D18h] [ebp-54h]
  double v48; // [esp+D1Ch] [ebp-50h]
  float v49; // [esp+D28h] [ebp-44h]
  float v50; // [esp+D2Ch] [ebp-40h]
  float v51; // [esp+D30h] [ebp-3Ch]
  double v52; // [esp+D34h] [ebp-38h]
  unsigned __int8 dst[48]; // [esp+D3Ch] [ebp-30h] BYREF

  v31 = this->M[0][0];
  v32 = this->M[0][1];
  v30 = this->M[0][2];
  v33 = this->M[1][0];
  v34 = this->M[1][3];
  v47 = this->M[2][0];
  v39 = this->M[2][1];
  v44 = this->M[2][2];
  v50 = this->M[2][3];
  v3 = v47 * 0.0;
  v4 = v39 * 0.0;
  v41 = v3 - v4;
  v37 = v3 - v44 * 0.0;
  v5 = v50 * 0.0;
  v21 = v47 - v5;
  v35 = v4 - v44 * 0.0;
  v24 = v39 - v5;
  v27 = v44 - v5;
  v6 = this->M[1][1];
  v7 = this->M[1][2];
  v49 = v35 * v34 + v27 * v6 - v24 * v7;
  v40 = -(v27 * v33 - v21 * v7 + v37 * v34);
  v43 = v34 * v41 + v24 * v33 - v21 * v6;
  v8 = v6;
  v45 = -(v33 * v35 - v37 * v6 + v41 * v7);
  v9 = this->M[0][3];
  v14 = v45 * v9 + v40 * v32 + v49 * v31 + v43 * v30;
  if ( v14 == 0.0 )
  {
    memset((int)dst, 0, sizeof(dst));
    *(float *)dst = 1.0;
    *(float *)&dst[20] = 1.0;
    *(float *)&dst[40] = 1.0;
    *(float *)&dst[12] = -this->M[0][3];
    *(float *)&dst[28] = -this->M[1][3];
    *(float *)&dst[44] = -this->M[2][3];
    memcpy((unsigned __int8 *)result, dst, sizeof(Scaleform::Render::Matrix3x4<float>));
    return result;
  }
  else
  {
    v15 = 1.0 / v14;
    v46 = -((v27 * v32 - v24 * v30 + v35 * v9) * v15);
    v11 = v15;
    v38 = (v27 * v31 - v21 * v30 + v37 * v9) * v15;
    v51 = -((v24 * v31 - v21 * v32 + v41 * v9) * v15);
    v12 = v34 * 0.0;
    v22 = v33 - v12;
    v25 = v8 - v12;
    v28 = v7 - v12;
    v52 = v8 * 0.0;
    v48 = v7 * 0.0;
    v16 = v52 - v48;
    v42 = (v28 * v32 - v25 * v30 + v16 * v9) * v11;
    v13 = 0.0 * v33;
    v17 = v13 - v48;
    v10 = result;
    v36 = -((v28 * v31 - v22 * v30 + v17 * v9) * v11);
    v18 = v13 - v52;
    *(float *)&v48 = (v25 * v31 - v22 * v32 + v18 * v9) * v11;
    v23 = v50 * v33 - v47 * v34;
    v26 = v50 * v8 - v39 * v34;
    v29 = v50 * v7 - v44 * v34;
    result->M[0][0] = v11 * v49;
    result->M[0][1] = v46;
    result->M[0][2] = v42;
    v19 = v44 * v8 - v39 * v7;
    result->M[0][3] = -((v19 * v9 + v29 * v32 - v26 * v30) * v11);
    result->M[1][0] = v11 * v40;
    result->M[1][1] = v38;
    result->M[1][2] = v36;
    v20 = v44 * v33 - v7 * v47;
    result->M[1][3] = (v20 * v9 + v29 * v31 - v23 * v30) * v11;
    result->M[2][0] = v11 * v43;
    result->M[2][1] = v51;
    result->M[2][2] = *(float *)&v48;
    *(float *)&v48 = v39 * v33 - v8 * v47;
    result->M[2][3] = -(v11 * (v9 * *(float *)&v48 + v26 * v31 - v23 * v32));
  }
  return v10;
}
