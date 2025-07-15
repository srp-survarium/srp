void __thiscall Scaleform::Render::Matrix4x4<float>::Matrix4x4<float>(
        Scaleform::Render::Matrix4x4<float> *this,
        const Scaleform::Render::Matrix3x4<float> *m)
{
  this->M[0][0] = m->M[0][0];
  this->M[0][1] = m->M[0][1];
  this->M[0][2] = m->M[0][2];
  this->M[0][3] = m->M[0][3];
  this->M[1][0] = m->M[1][0];
  this->M[1][1] = m->M[1][1];
  this->M[1][2] = m->M[1][2];
  this->M[1][3] = m->M[1][3];
  this->M[2][0] = m->M[2][0];
  this->M[2][1] = m->M[2][1];
  this->M[2][2] = m->M[2][2];
  this->M[2][3] = m->M[2][3];
  this->M[3][0] = 0.0;
  this->M[3][1] = 0.0;
  this->M[3][2] = 0.0;
  this->M[3][3] = 1.0;
}


void __thiscall Scaleform::Render::Matrix4x4<float>::Matrix4x4<float>(
        Scaleform::Render::Matrix4x4<float> *this,
        float v1,
        float v2,
        float v3,
        float v4,
        float v5,
        float v6,
        float v7,
        float v8,
        float v9,
        float v10,
        float v11,
        float v12,
        float v13,
        float v14,
        float v15,
        float v16)
{
  this->M[0][0] = v1;
  this->M[0][1] = v2;
  this->M[0][2] = v3;
  this->M[0][3] = v4;
  this->M[1][0] = v5;
  this->M[1][1] = v6;
  this->M[1][2] = v7;
  this->M[1][3] = v8;
  this->M[2][0] = v9;
  this->M[2][1] = v10;
  this->M[2][2] = v11;
  this->M[2][3] = v12;
  this->M[3][0] = v13;
  this->M[3][1] = v14;
  this->M[3][2] = v15;
  this->M[3][3] = v16;
}


void __thiscall Scaleform::Render::Matrix4x4<float>::Matrix4x4<float>(Scaleform::Render::Matrix4x4<float> *this)
{
  float v2; // xmm0_4

  memset((int)this, 0, sizeof(Scaleform::Render::Matrix4x4<float>));
  v2 = s_bm_current_air_resistance;
  this->M[0][0] = s_bm_current_air_resistance;
  this->M[1][1] = v2;
  this->M[2][2] = v2;
  this->M[3][3] = v2;
}


void __thiscall Scaleform::Render::Matrix4x4<double>::Matrix4x4<double>(
        Scaleform::Render::Matrix4x4<double> *this,
        long double v1,
        long double v2,
        long double v3,
        long double v4,
        long double v5,
        long double v6,
        long double v7,
        long double v8,
        long double v9,
        long double v10,
        long double v11,
        long double v12,
        long double v13,
        long double v14,
        long double v15,
        long double v16)
{
  this->M[0][0] = v1;
  this->M[0][1] = v2;
  this->M[0][2] = v3;
  this->M[0][3] = v4;
  this->M[1][0] = v5;
  this->M[1][1] = v6;
  this->M[1][2] = v7;
  this->M[1][3] = v8;
  this->M[2][0] = v9;
  this->M[2][1] = v10;
  this->M[2][2] = v11;
  this->M[2][3] = v12;
  this->M[3][0] = v13;
  this->M[3][1] = v14;
  this->M[3][2] = v15;
  this->M[3][3] = v16;
}
