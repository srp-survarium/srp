Scaleform::Render::Matrix4x4<float> *__thiscall Scaleform::Render::Matrix4x4<float>::GetInverse(
        Scaleform::Render::Matrix4x4<float> *this,
        Scaleform::Render::Matrix4x4<float> *result)
{
  double st5_1; // st5
  double st6_1; // st6
  double st4_1; // st4
  double st3_1; // st3
  double st7_4; // st7
  float v2; // [esp+4h] [ebp-FCh]
  float v5; // [esp+10h] [ebp-F0h]
  float v6; // [esp+14h] [ebp-ECh]
  float v9; // [esp+20h] [ebp-E0h]
  float v10; // [esp+24h] [ebp-DCh]
  float v13; // [esp+30h] [ebp-D0h]
  float v16; // [esp+3Ch] [ebp-C4h]
  float varB4; // [esp+4Ch] [ebp-B4h]
  float v17; // [esp+4Ch] [ebp-B4h]
  float v18; // [esp+4Ch] [ebp-B4h]
  float v19; // [esp+4Ch] [ebp-B4h]
  float v12; // [esp+4Ch] [ebp-B4h]
  float v21; // [esp+50h] [ebp-B0h]
  float v22; // [esp+50h] [ebp-B0h]
  float v23; // [esp+50h] [ebp-B0h]
  float v24; // [esp+54h] [ebp-ACh]
  float v25; // [esp+54h] [ebp-ACh]
  float v26; // [esp+54h] [ebp-ACh]
  float v27; // [esp+58h] [ebp-A8h]
  float v28; // [esp+58h] [ebp-A8h]
  float v29; // [esp+58h] [ebp-A8h]
  float v30; // [esp+5Ch] [ebp-A4h]
  float v31; // [esp+5Ch] [ebp-A4h]
  float v32; // [esp+5Ch] [ebp-A4h]
  float v33; // [esp+60h] [ebp-A0h]
  float v34; // [esp+60h] [ebp-A0h]
  float v35; // [esp+60h] [ebp-A0h]
  float v36; // [esp+64h] [ebp-9Ch]
  float v37; // [esp+68h] [ebp-98h]
  float v38; // [esp+6Ch] [ebp-94h]
  float v39; // [esp+6Ch] [ebp-94h]
  float v40; // [esp+6Ch] [ebp-94h]
  float v41; // [esp+70h] [ebp-90h]
  float v42; // [esp+74h] [ebp-8Ch]
  float v43; // [esp+78h] [ebp-88h]
  float v7; // [esp+78h] [ebp-88h]
  float v45; // [esp+7Ch] [ebp-84h]
  float v3; // [esp+7Ch] [ebp-84h]
  float v47; // [esp+80h] [ebp-80h]
  float v48; // [esp+84h] [ebp-7Ch]
  float v49; // [esp+84h] [ebp-7Ch]
  float v4; // [esp+84h] [ebp-7Ch]
  float v51; // [esp+88h] [ebp-78h]
  float v52; // [esp+88h] [ebp-78h]
  float v8; // [esp+88h] [ebp-78h]
  float v54; // [esp+8Ch] [ebp-74h]
  float v55; // [esp+90h] [ebp-70h]
  float v56; // [esp+94h] [ebp-6Ch]
  float v57; // [esp+98h] [ebp-68h]
  float v58; // [esp+9Ch] [ebp-64h]
  float v14; // [esp+A0h] [ebp-60h]
  float v60; // [esp+A4h] [ebp-5Ch]
  float v1; // [esp+A4h] [ebp-5Ch]
  float v11; // [esp+A8h] [ebp-58h]
  float v15; // [esp+ACh] [ebp-54h]
  float v64; // [esp+B0h] [ebp-50h]
  float v65; // [esp+B4h] [ebp-4Ch]
  float v66; // [esp+B8h] [ebp-48h]
  float v67; // [esp+BCh] [ebp-44h]
  unsigned __int8 src[64]; // [esp+C0h] [ebp-40h] BYREF

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
  st5_1 = this->M[0][1];
  st6_1 = this->M[0][0];
  st4_1 = this->M[0][2];
  st3_1 = this->M[0][3];
  varB4 = v67 * st3_1 + v66 * st4_1 + v65 * st6_1 + v64 * st5_1;
  if ( varB4 == 0.0 )
  {
    memset((int)src, 0, sizeof(src));
    *(float *)src = 1.0;
    *(float *)&src[20] = 1.0;
    *(float *)&src[40] = 1.0;
    *(float *)&src[60] = 1.0;
    *(float *)&src[12] = -this->M[0][3];
    *(float *)&src[28] = -this->M[1][3];
    *(float *)&src[44] = -this->M[2][3];
    memcpy((int)result, (const __m128i *)src, sizeof(Scaleform::Render::Matrix4x4<float>));
  }
  else
  {
    v17 = 1.0 / varB4;
    st7_4 = v17;
    v60 = -((v38 * st5_1 - v33 * st4_1 + v21 * st3_1) * v17);
    v48 = (v38 * st6_1 - v27 * st4_1 + v24 * st3_1) * v17;
    v51 = -((v33 * st6_1 - v27 * st5_1 + v30 * st3_1) * v17);
    v14 = (v21 * st6_1 - v24 * st5_1 + v30 * st4_1) * v17;
    v31 = v54 * v36 - v56 * v42;
    v25 = v43 * v36 - v56 * v41;
    v28 = v45 * v36 - v56 * v37;
    v22 = v43 * v42 - v54 * v41;
    v34 = v45 * v42 - v54 * v37;
    v39 = v45 * v41 - v43 * v37;
    v3 = (v39 * st5_1 - v34 * st4_1 + v22 * st3_1) * v17;
    v7 = -((v39 * st6_1 - v28 * st4_1 + v25 * st3_1) * v17);
    v11 = (v34 * st6_1 - v28 * st5_1 + v31 * st3_1) * v17;
    v15 = -((v22 * st6_1 - v25 * st5_1 + v31 * st4_1) * v17);
    v32 = v57 * v36 - v58 * v42;
    v26 = v47 * v36 - v58 * v41;
    v29 = v55 * v36 - v58 * v37;
    v23 = v47 * v42 - v57 * v41;
    v35 = v55 * v42 - v57 * v37;
    v40 = v55 * v41 - v47 * v37;
    v18 = (v23 * st6_1 - v26 * st5_1 + v32 * st4_1) * v17;
    v16 = v18;
    v19 = st7_4 * v67;
    v13 = v19;
    v12 = -((v35 * st6_1 - v29 * st5_1 + v32 * st3_1) * st7_4);
    v10 = v51;
    v52 = st7_4 * v66;
    v9 = v52;
    v8 = (st6_1 * v40 - v29 * st4_1 + v26 * st3_1) * st7_4;
    v6 = v48;
    v49 = st7_4 * v64;
    v5 = v49;
    v4 = -((st3_1 * v23 + st5_1 * v40 - st4_1 * v35) * st7_4);
    v2 = v60;
    v1 = st7_4 * v65;
    Scaleform::Render::Matrix4x4<float>::Matrix4x4<float>(
      result,
      v1,
      v2,
      v3,
      v4,
      v5,
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


Scaleform::Render::Matrix4x4<double> *__thiscall Scaleform::Render::Matrix4x4<double>::GetInverse(
        Scaleform::Render::Matrix4x4<double> *this,
        Scaleform::Render::Matrix4x4<double> *result)
{
  long double st7_1; // st7
  long double st6_1; // st6
  long double st5_1; // st5
  long double v6; // st4
  long double v7; // st3
  long double v8; // st2
  long double v10; // st2
  long double v11; // rt2
  double v12; // st2
  double v3; // [esp+B0h] [ebp-150h]
  double v3a; // [esp+B0h] [ebp-150h]
  double v4; // [esp+B8h] [ebp-148h]
  double v4a; // [esp+B8h] [ebp-148h]
  double v1; // [esp+C0h] [ebp-140h]
  long double v1a; // [esp+C0h] [ebp-140h]
  double m11; // [esp+C8h] [ebp-138h]
  double m12; // [esp+D0h] [ebp-130h]
  double v2; // [esp+D8h] [ebp-128h]
  long double v2a; // [esp+D8h] [ebp-128h]
  double v0; // [esp+E0h] [ebp-120h]
  long double v0a; // [esp+E0h] [ebp-120h]
  long double v0b; // [esp+E0h] [ebp-120h]
  double m31; // [esp+E8h] [ebp-118h]
  double m33; // [esp+F0h] [ebp-110h]
  long double m33a; // [esp+F0h] [ebp-110h]
  double d02; // [esp+F8h] [ebp-108h]
  double m32; // [esp+100h] [ebp-100h]
  long double m32a; // [esp+100h] [ebp-100h]
  double m13; // [esp+108h] [ebp-F8h]
  double m22; // [esp+110h] [ebp-F0h]
  double m21; // [esp+120h] [ebp-E0h]
  double m23; // [esp+128h] [ebp-D8h]
  double m20; // [esp+130h] [ebp-D0h]
  double v5; // [esp+138h] [ebp-C8h]
  double t00; // [esp+140h] [ebp-C0h]
  double t10; // [esp+148h] [ebp-B8h]
  double t20; // [esp+150h] [ebp-B0h]
  double t30; // [esp+158h] [ebp-A8h]
  long double d11; // [esp+160h] [ebp-A0h]
  long double d31; // [esp+168h] [ebp-98h]
  long double d01; // [esp+170h] [ebp-90h]
  long double d21; // [esp+178h] [ebp-88h]
  Scaleform::Render::Matrix4x4<double> tmp; // [esp+180h] [ebp-80h] BYREF

  st7_1 = this->M[0][0];
  st6_1 = this->M[0][1];
  st5_1 = this->M[0][2];
  v6 = this->M[0][3];
  v7 = this->M[1][0];
  m11 = this->M[1][1];
  m12 = this->M[1][2];
  m13 = this->M[1][3];
  m20 = this->M[2][0];
  m21 = this->M[2][1];
  m22 = this->M[2][2];
  m23 = this->M[2][3];
  d02 = this->M[3][0];
  m31 = this->M[3][1];
  m32 = this->M[3][2];
  m33 = this->M[3][3];
  v0 = m20 * m31 - m21 * d02;
  v1 = m32 * m20 - d02 * m22;
  v2 = m33 * m20 - d02 * m23;
  v3 = m32 * m21 - m31 * m22;
  v4 = m33 * m21 - m31 * m23;
  v5 = m33 * m22 - m23 * m32;
  t00 = v5 * m11 - v4 * m12 + v3 * m13;
  t10 = -(v5 * v7 - v2 * m12 + v1 * m13);
  t20 = v4 * v7 - v2 * m11 + v0 * m13;
  t30 = -(v3 * v7 - v1 * m11 + v0 * m12);
  v8 = t10 * st6_1 + t00 * st7_1 + t20 * st5_1 + t30 * v6;
  if ( 0.0 == v8 )
  {
    memset((int)&tmp, 0, sizeof(tmp));
    tmp.M[0][0] = 1.0;
    tmp.M[1][1] = 1.0;
    tmp.M[2][2] = 1.0;
    tmp.M[3][3] = 1.0;
    tmp.M[0][3] = -this->M[0][3];
    tmp.M[1][3] = -this->M[1][3];
    tmp.M[2][3] = -this->M[2][3];
    memcpy((int)result, (const __m128i *)&tmp, sizeof(Scaleform::Render::Matrix4x4<double>));
  }
  else
  {
    v10 = 1.0 / v8;
    d01 = -((v5 * st6_1 - v4 * st5_1 + v3 * v6) * v10);
    d11 = (v5 * st7_1 - v2 * st5_1 + v1 * v6) * v10;
    d21 = -((v4 * st7_1 - v2 * st6_1 + v0 * v6) * v10);
    d31 = (v3 * st7_1 - v1 * st6_1 + v0 * st5_1) * v10;
    v11 = v10;
    v0a = v7 * m31 - d02 * m11;
    v1a = m32 * v7 - d02 * m12;
    v2a = m33 * v7 - d02 * m13;
    v3a = m32 * m11 - m31 * m12;
    v4a = m33 * m11 - m31 * m13;
    v12 = m33 * m12 - m13 * m32;
    m33a = (v4a * st7_1 - v2a * st6_1 + v0a * v6) * v11;
    m32a = -((v3a * st7_1 - v1a * st6_1 + v0a * st5_1) * v11);
    v0b = m21 * v7 - m20 * m11;
    Scaleform::Render::Matrix4x4<double>::Matrix4x4<double>(
      result,
      v11 * t00,
      d01,
      (v12 * st6_1 - v4a * st5_1 + v3a * v6) * v11,
      -((v6 * (m22 * m11 - m21 * m12) + st6_1 * (m23 * m12 - m13 * m22) - st5_1 * (m23 * m11 - m21 * m13)) * v11),
      t10 * v11,
      d11,
      -((v12 * st7_1 - v2a * st5_1 + v1a * v6) * v11),
      (st7_1 * (m23 * m12 - m13 * m22) - (m23 * v7 - m20 * m13) * st5_1 + (m22 * v7 - m20 * m12) * v6) * v11,
      t20 * v11,
      d21,
      m33a,
      -(((m23 * m11 - m21 * m13) * st7_1 - (m23 * v7 - m20 * m13) * st6_1 + v0b * v6) * v11),
      v11 * t30,
      d31,
      m32a,
      ((m22 * m11 - m21 * m12) * st7_1 - (m22 * v7 - m20 * m12) * st6_1 + v0b * st5_1) * v11);
  }
  return result;
}
