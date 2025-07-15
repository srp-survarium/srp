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
  float v32; // [esp+28h] [ebp-24h]
  float v33; // [esp+28h] [ebp-24h]
  unsigned int v34; // [esp+2Ch] [ebp-20h]
  Scaleform::Render::PathBasic **Pages; // [esp+30h] [ebp-1Ch]
  float v36; // [esp+34h] [ebp-18h]
  float v37; // [esp+34h] [ebp-18h]
  float v38; // [esp+34h] [ebp-18h]
  float v39; // [esp+34h] [ebp-18h]
  unsigned int v40; // [esp+38h] [ebp-14h]
  float v41; // [esp+3Ch] [ebp-10h]
  float v42; // [esp+40h] [ebp-Ch]
  float v43; // [esp+44h] [ebp-8h]
  float v44; // [esp+48h] [ebp-4h]
  float v45; // [esp+50h] [ebp+4h]
  float v46; // [esp+54h] [ebp+8h]
  float v47; // [esp+54h] [ebp+8h]
  float v48; // [esp+54h] [ebp+8h]
  float v49; // [esp+54h] [ebp+8h]

  v4 = path;
  Size = path->Paths.Size;
  v46 = w * 0.5;
  v6 = y;
  v7 = 0;
  v8 = x;
  v34 = 0;
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
          v32 = v21[1] - p_x[1];
          v41 = *p_x - v32;
          v42 = p_x[1] + v36;
          v44 = v36 + v21[1];
          v37 = (v8 - v41) * (v42 - p_x[1]) - (v41 - *p_x) * (v6 - v42);
          if ( v37 >= v9 )
          {
            v43 = *v21 - v32;
            v38 = (v8 - v43) * (v44 - v21[1]) - (v6 - v44) * (v43 - *v21);
            if ( v38 <= v9 )
            {
              v31 = v6;
              v30 = v8;
              v39 = Scaleform::Render::Math2D::LinePointDistance(*p_x, p_x[1], *v21, v21[1], v30, v31);
              v22 = v39;
              if ( v39 < 0.0 )
                v22 = -v22;
              v33 = v22;
              if ( v46 >= (double)v33 )
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
        v7 = v34;
      }
      v34 = ++v7;
    }
    while ( v7 < Size );
  }
  v23 = v4->Vertices.Size;
  v24 = 0;
  v47 = v46 * v46;
  if ( !v23 )
    return 0;
  v25 = v4->Vertices.Pages;
  v26 = v47;
  while ( 1 )
  {
    v27 = v25[v24 >> 4];
    v28 = v24 & 0xF;
    v45 = v8 - v27[v28].x;
    v48 = v6 - v27[v28].y;
    v49 = v48 * v48 + v45 * v45;
    if ( v49 <= v26 )
      break;
    if ( ++v24 >= v23 )
      return 0;
  }
  return 1;
}
