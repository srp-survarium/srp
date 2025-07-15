long double __thiscall Scaleform::Render::Matrix4x4<double>::GetMinor(
        Scaleform::Render::Matrix4x4<double> *this,
        const Scaleform::Render::Matrix4x4<double> *m,
        unsigned int r0,
        unsigned int r1,
        unsigned int r2,
        unsigned int c0,
        unsigned int c1,
        unsigned int c2)
{
  unsigned int v11; // esi
  double *r1a; // [esp+1Ch] [ebp+Ch]
  double *r2a; // [esp+20h] [ebp+10h]
  double *c1a; // [esp+28h] [ebp+18h]

  r1a = &m->M[r2][c2];
  r2a = &m->M[r2][c1];
  v11 = c1 + 4 * r1;
  c1a = &m->M[r1][c2];
  return (m->M[0][v11] * *r1a - *r2a * *c1a) * m->M[r0][c0]
       - (m->M[r1][c0] * *r1a - *c1a * m->M[r2][c0]) * m->M[r0][c1]
       + (m->M[r1][c0] * *r2a - m->M[0][v11] * m->M[r2][c0]) * m->M[r0][c2];
}
