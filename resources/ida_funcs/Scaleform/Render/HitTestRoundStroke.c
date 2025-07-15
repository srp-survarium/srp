char __cdecl Scaleform::Render::HitTestRoundStroke(
        const Scaleform::Render::VertexPath *path,
        float w,
        float x,
        float y)
{
  const Scaleform::Render::VertexPath *v4; // edx
  unsigned int Size; // esi
  double v6; // st7
  unsigned int v7; // ecx
  double v8; // st6
  double v9; // st5
  Scaleform::Render::PathBasic *v10; // eax
  int v11; // edi
  unsigned int Count; // ebp
  Scaleform::Render::PathBasic *v13; // eax
  unsigned int v14; // ebx
  Scaleform::Render::VertexBasic **v15; // edi
  unsigned int v16; // esi
  float *p_x; // ecx
  Scaleform::Render::VertexBasic *v18; // edx
  int v19; // eax
  double v20; // st4
  float *v21; // edx
  double v22; // st6
  unsigned int v23; // esi
  unsigned int v24; // ecx
  Scaleform::Render::VertexBasic **v25; // edx
  double v26; // st5
  Scaleform::Render::VertexBasic *v27; // eax
  int v28; // edi
  float v30; // [esp+10h] [ebp-3Ch]
  float v31; // [esp+14h] [ebp-38h]
  float dy; // [esp+28h] [ebp-24h]
  float dya; // [esp+28h] [ebp-24h]
  unsigned int i; // [esp+2Ch] [ebp-20h]
  Scaleform::Render::PathBasic **Pages; // [esp+30h] [ebp-1Ch]
  float v36; // [esp+34h] [ebp-18h]
  float v37; // [esp+34h] [ebp-18h]
  float v38; // [esp+34h] [ebp-18h]
  float v39; // [esp+34h] [ebp-18h]
  unsigned int v40; // [esp+38h] [ebp-14h]
  float p1; // [esp+3Ch] [ebp-10h]
  float p1_4; // [esp+40h] [ebp-Ch]
  float p2; // [esp+44h] [ebp-8h]
  float p2_4; // [esp+48h] [ebp-4h]
  float patha; // [esp+50h] [ebp+4h]
  float wa; // [esp+54h] [ebp+8h]
  float wb; // [esp+54h] [ebp+8h]
  float wc; // [esp+54h] [ebp+8h]
  float wd; // [esp+54h] [ebp+8h]

  v4 = path;
  Size = path->Paths.Size;
  wa = w * 0.5;
  v6 = y;
  v7 = 0;
  v8 = x;
  i = 0;
  v40 = Size;
  if ( Size )
  {
    v9 = 0.0;
    Pages = path->Paths.Pages;
    do
    {
      v10 = Pages[v7 >> 2];
      v11 = v7 & 3;
      Count = v10[v11].Count;
      v13 = &v10[v11];
      v14 = 1;
      if ( Count > 1 )
      {
        v15 = v4->Vertices.Pages;
        v16 = v13->Start + 1;
        do
        {
          p_x = &v15[(v16 - 1) >> 4][((_BYTE)v16 - 1) & 0xF].x;
          v18 = v15[v16 >> 4];
          v19 = v16 & 0xF;
          v20 = v18[v19].x;
          v21 = &v18[v19].x;
          v36 = v20 - *p_x;
          dy = v21[1] - p_x[1];
          p1 = *p_x - dy;
          p1_4 = p_x[1] + v36;
          p2_4 = v36 + v21[1];
          v37 = (v8 - p1) * (p1_4 - p_x[1]) - (p1 - *p_x) * (v6 - p1_4);
          if ( v37 >= v9 )
          {
            p2 = *v21 - dy;
            v38 = (v8 - p2) * (p2_4 - v21[1]) - (v6 - p2_4) * (p2 - *v21);
            if ( v38 <= v9 )
            {
              v31 = v6;
              v30 = v8;
              v39 = Scaleform::Render::Math2D::LinePointDistance(*p_x, p_x[1], *v21, v21[1], v30, v31);
              v22 = v39;
              if ( v39 < 0.0 )
                v22 = -v22;
              dya = v22;
              if ( wa >= (double)dya )
                return 1;
              v8 = x;
              v9 = 0.0;
              v6 = y;
            }
          }
          ++v14;
          ++v16;
        }
        while ( v14 < Count );
        Size = v40;
        v4 = path;
        v7 = i;
      }
      i = ++v7;
    }
    while ( v7 < Size );
  }
  v23 = v4->Vertices.Size;
  v24 = 0;
  wb = wa * wa;
  if ( !v23 )
    return 0;
  v25 = v4->Vertices.Pages;
  v26 = wb;
  while ( 1 )
  {
    v27 = v25[v24 >> 4];
    v28 = v24 & 0xF;
    patha = v8 - v27[v28].x;
    wc = v6 - v27[v28].y;
    wd = wc * wc + patha * patha;
    if ( wd <= v26 )
      break;
    if ( ++v24 >= v23 )
      return 0;
  }
  return 1;
}
