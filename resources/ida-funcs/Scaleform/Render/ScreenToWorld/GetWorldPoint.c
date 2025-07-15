void __thiscall Scaleform::Render::ScreenToWorld::GetWorldPoint(
        Scaleform::Render::ScreenToWorld *this,
        Scaleform::Render::Point3<float> *ptOut)
{
  unsigned __int8 *Inverse; // eax
  unsigned __int8 *v4; // eax
  double v5; // st6
  double v6; // st5
  double v7; // st4
  double v8; // st3
  float y; // [esp+798h] [ebp-DCh]
  float ya; // [esp+798h] [ebp-DCh]
  float z; // [esp+79Ch] [ebp-D8h]
  float za; // [esp+79Ch] [ebp-D8h]
  float v13; // [esp+7B8h] [ebp-BCh]
  float v14; // [esp+7B8h] [ebp-BCh]
  float x; // [esp+7B8h] [ebp-BCh]
  float v16; // [esp+7B8h] [ebp-BCh]
  float v17; // [esp+7B8h] [ebp-BCh]
  float v18; // [esp+7B8h] [ebp-BCh]
  float v19; // [esp+7B8h] [ebp-BCh]
  float v20; // [esp+7B8h] [ebp-BCh]
  float v21; // [esp+7BCh] [ebp-B8h]
  float v22; // [esp+7BCh] [ebp-B8h]
  float v23; // [esp+7C0h] [ebp-B4h]
  float v24; // [esp+7C0h] [ebp-B4h]
  float v; // [esp+7C4h] [ebp-B0h] BYREF
  float v26; // [esp+7C8h] [ebp-ACh]
  float v27; // [esp+7CCh] [ebp-A8h]
  float v28; // [esp+7D0h] [ebp-A4h]
  float v29; // [esp+7D4h] [ebp-A0h] BYREF
  float v30; // [esp+7D8h] [ebp-9Ch]
  float v31; // [esp+7DCh] [ebp-98h]
  float v32; // [esp+7E0h] [ebp-94h]
  float po; // [esp+7E4h] [ebp-90h] BYREF
  float v34; // [esp+7E8h] [ebp-8Ch]
  float v35; // [esp+7ECh] [ebp-88h]
  float w; // [esp+7F0h] [ebp-84h]
  Scaleform::Render::Matrix4x4<float> m; // [esp+7F4h] [ebp-80h] BYREF
  Scaleform::Render::Matrix4x4<float> result; // [esp+834h] [ebp-40h] BYREF

  if ( 3.402823466385289e38 != this->Sx && this->Sy != 3.402823466385289e38 )
  {
    Inverse = (unsigned __int8 *)Scaleform::Render::Matrix4x4<float>::GetInverse(&this->MatProj, &result);
    memcpy((unsigned __int8 *)&this->MatInvProj, Inverse, sizeof(this->MatInvProj));
    Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(
      (Scaleform::Render::Matrix3x4<float> *)&m,
      &this->MatView,
      &this->MatWorld);
    Scaleform::Render::Matrix4x4<float>::Matrix4x4<float>(&result, (const Scaleform::Render::Matrix3x4<float> *)&m);
    memcpy((unsigned __int8 *)&m, (unsigned __int8 *)&result, sizeof(m));
    v4 = (unsigned __int8 *)Scaleform::Render::Matrix4x4<float>::GetInverse(&m, &result);
    memcpy((unsigned __int8 *)&m, v4, sizeof(m));
    Scaleform::Render::ScreenToWorld::VectorMult(this, &po, (const float *)&this->MatProj, 0.0, 0.0, -0.5, 1.0);
    Scaleform::Render::ScreenToWorld::VectorMult(this, &v29, (const float *)&this->MatProj, 0.0, 0.0, -100.0, 1.0);
    v13 = v35 * w;
    z = v13;
    v14 = w * this->Sy;
    y = v14;
    x = w * this->Sx;
    Scaleform::Render::ScreenToWorld::VectorMult(this, &v, (const float *)&this->MatInvProj, x, y, z, w);
    v16 = v31 * v32;
    za = v16;
    v17 = v32 * this->Sy;
    ya = v17;
    v18 = v32 * this->Sx;
    Scaleform::Render::ScreenToWorld::VectorMult(this, &v29, (const float *)&this->MatInvProj, v18, ya, za, v32);
    v = v28 * v;
    v26 = v26 * v28;
    v27 = v28 * v27;
    v28 = 1.0;
    v29 = v32 * v29;
    v30 = v30 * v32;
    v31 = v32 * v31;
    v32 = 1.0;
    Scaleform::Render::ScreenToWorld::VectorMult(this, &po, (const float *)&m, &v);
    Scaleform::Render::ScreenToWorld::VectorMult(this, &v, (const float *)&m, &v29);
    v5 = v34;
    v23 = v26 - v34;
    v6 = v35;
    v19 = v27 - v35;
    v7 = v19;
    if ( v19 == 0.0 )
      v8 = 0.0;
    else
      v8 = -v6 / v7;
    v20 = v8;
    v21 = v - po;
    v22 = po + v20 * v21;
    ptOut->x = v22;
    this->LastX = v22;
    v24 = v5 + v20 * v23;
    ptOut->y = v24;
    this->LastY = v24;
    ptOut->z = v6 + v7 * v20;
  }
}


void __thiscall Scaleform::Render::ScreenToWorld::GetWorldPoint(
        Scaleform::Render::ScreenToWorld *this,
        Scaleform::Render::Point<float> *ptOut)
{
  Scaleform::Render::Point3<float> pt3; // [esp+0h] [ebp-Ch] BYREF

  Scaleform::Render::ScreenToWorld::GetWorldPoint(this, &pt3);
  ptOut->x = pt3.x;
  ptOut->y = pt3.y;
}
