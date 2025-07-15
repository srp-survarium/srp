BOOL __cdecl Scaleform::Render::HitTestGeneralStroke(const Scaleform::Render::VertexPath *path, float x, float y)
{
  const Scaleform::Render::VertexPath *v3; // ecx
  unsigned int v4; // eax
  double v5; // st7
  double v6; // st6
  Scaleform::Render::PathBasic *v7; // edx
  int v8; // esi
  unsigned int Count; // ebp
  const Scaleform::Render::PathBasic *v10; // edx
  unsigned int v11; // esi
  Scaleform::Render::VertexBasic **Pages; // edi
  unsigned int v13; // esi
  unsigned int v14; // ebp
  Scaleform::Render::VertexBasic *v15; // eax
  int v16; // edx
  float v17; // ecx
  float *p_x; // edx
  double v19; // st4
  float *v20; // ecx
  double v21; // st3
  int v22; // ebx
  double v23; // rt0
  double v24; // st3
  double v25; // st7
  double v26; // st4
  double v27; // st4
  float *v28; // edx
  double v29; // st3
  int v30; // ebx
  double v31; // rt1
  double v32; // st3
  double v33; // st7
  double v34; // st4
  double v35; // st4
  float *v36; // ecx
  double v37; // st3
  int v38; // ebx
  double v39; // rt2
  double v40; // st3
  double v41; // st7
  double v42; // st4
  double v43; // st4
  float *v44; // edx
  double v45; // st3
  int v46; // ebx
  double v47; // rtt
  double v48; // st3
  double v49; // st7
  double v50; // st4
  Scaleform::Render::VertexBasic **v51; // ebx
  unsigned int v52; // ecx
  unsigned int v53; // ebp
  float *v54; // edx
  double v55; // st4
  float *v56; // esi
  double v57; // st3
  int v58; // edi
  double v59; // rt0
  double v60; // st3
  double v61; // st7
  double v62; // st4
  int styleCount; // [esp+0h] [ebp-30h]
  unsigned int i; // [esp+4h] [ebp-2Ch]
  float v66; // [esp+Ch] [ebp-24h]
  float v67; // [esp+Ch] [ebp-24h]
  float v68; // [esp+Ch] [ebp-24h]
  float v69; // [esp+Ch] [ebp-24h]
  unsigned int v70; // [esp+10h] [ebp-20h]
  unsigned int j; // [esp+14h] [ebp-1Ch]
  const Scaleform::Render::PathBasic *p; // [esp+18h] [ebp-18h]
  float pa; // [esp+18h] [ebp-18h]
  unsigned int Size; // [esp+1Ch] [ebp-14h]
  float p2; // [esp+20h] [ebp-10h]
  float p2a; // [esp+20h] [ebp-10h]
  float p2b; // [esp+20h] [ebp-10h]
  float p2c; // [esp+20h] [ebp-10h]
  float p2d; // [esp+20h] [ebp-10h]
  float p1; // [esp+28h] [ebp-8h]
  float p1a; // [esp+28h] [ebp-8h]
  float p1b; // [esp+28h] [ebp-8h]
  float p1c; // [esp+28h] [ebp-8h]
  float p1d; // [esp+28h] [ebp-8h]

  v3 = path;
  v4 = 0;
  styleCount = 0;
  i = 0;
  Size = path->Paths.Size;
  if ( Size )
  {
    v5 = y;
    v6 = x;
    do
    {
      v7 = path->Paths.Pages[v4 >> 2];
      v8 = v4 & 3;
      Count = v7[v8].Count;
      v10 = &v7[v8];
      v11 = 1;
      p = v10;
      v70 = Count;
      if ( Count > 1 )
      {
        if ( (int)(Count - 1) >= 4 )
        {
          Pages = v3->Vertices.Pages;
          v13 = v10->Start + 1;
          v14 = ((Count - 5) >> 2) + 1;
          j = 4 * v14 + 1;
          do
          {
            v15 = Pages[(v13 - 1) >> 4];
            v16 = ((_BYTE)v13 - 1) & 0xF;
            v17 = v15[v16].x;
            p_x = &v15[v16].x;
            p1 = v17;
            v19 = p_x[1];
            v20 = &Pages[v13 >> 4][v13 & 0xF].x;
            p2 = *v20;
            v21 = v20[1];
            if ( v21 != v19 )
            {
              v22 = 1;
              if ( v21 < v19 )
              {
                p1 = *v20;
                v19 = v20[1];
                v21 = p_x[1];
                p2 = *p_x;
                v22 = -1;
              }
              v23 = v21;
              v24 = v5;
              v25 = v23;
              if ( v24 < v19 || v24 >= v25 )
              {
                v5 = v24;
              }
              else
              {
                v26 = (v6 - p2) * (v25 - v19) - (v24 - v25) * (p2 - p1);
                v5 = v24;
                v66 = v26;
                if ( v66 > 0.0 )
                  styleCount += v22;
              }
            }
            p1a = *v20;
            v27 = v20[1];
            v28 = &Pages[(v13 + 1) >> 4][(v13 + 1) & 0xF].x;
            p2a = *v28;
            v29 = v28[1];
            if ( v29 != v27 )
            {
              v30 = 1;
              if ( v29 < v27 )
              {
                p1a = *v28;
                v27 = v28[1];
                v29 = v20[1];
                p2a = *v20;
                v30 = -1;
              }
              v31 = v29;
              v32 = v5;
              v33 = v31;
              if ( v32 < v27 || v32 >= v33 )
              {
                v5 = v32;
              }
              else
              {
                v34 = (v6 - p2a) * (v33 - v27) - (v32 - v33) * (p2a - p1a);
                v5 = v32;
                v67 = v34;
                if ( v67 > 0.0 )
                  styleCount += v30;
              }
            }
            p1b = *v28;
            v35 = v28[1];
            v36 = &Pages[(v13 + 2) >> 4][(v13 + 2) & 0xF].x;
            p2b = *v36;
            v37 = v36[1];
            if ( v37 != v35 )
            {
              v38 = 1;
              if ( v37 < v35 )
              {
                p1b = *v36;
                v35 = v36[1];
                v37 = v28[1];
                p2b = *v28;
                v38 = -1;
              }
              v39 = v37;
              v40 = v5;
              v41 = v39;
              if ( v40 < v35 || v40 >= v41 )
              {
                v5 = v40;
              }
              else
              {
                v42 = (v6 - p2b) * (v41 - v35) - (v40 - v41) * (p2b - p1b);
                v5 = v40;
                v68 = v42;
                if ( v68 > 0.0 )
                  styleCount += v38;
              }
            }
            p1c = *v36;
            v43 = v36[1];
            v44 = &Pages[(v13 + 3) >> 4][(v13 + 3) & 0xF].x;
            p2c = *v44;
            v45 = v44[1];
            if ( v45 != v43 )
            {
              v46 = 1;
              if ( v45 < v43 )
              {
                p1c = *v44;
                v43 = v44[1];
                v45 = v36[1];
                p2c = *v36;
                v46 = -1;
              }
              v47 = v45;
              v48 = v5;
              v49 = v47;
              if ( v48 < v43 || v48 >= v49 )
              {
                v5 = v48;
              }
              else
              {
                v50 = (v6 - p2c) * (v49 - v43) - (v48 - v49) * (p2c - p1c);
                v5 = v48;
                v69 = v50;
                if ( v69 > 0.0 )
                  styleCount += v46;
              }
            }
            v13 += 4;
            --v14;
          }
          while ( v14 );
          v3 = path;
          v4 = i;
          Count = v70;
          v11 = j;
          v10 = p;
        }
        if ( v11 < Count )
        {
          v51 = v3->Vertices.Pages;
          v52 = v11 + v10->Start;
          v53 = Count - v11;
          do
          {
            v54 = &v51[(v52 - 1) >> 4][((_BYTE)v52 - 1) & 0xF].x;
            p1d = *v54;
            v55 = v54[1];
            v56 = &v51[v52 >> 4][v52 & 0xF].x;
            p2d = *v56;
            v57 = v56[1];
            if ( v57 != v55 )
            {
              v58 = 1;
              if ( v57 < v55 )
              {
                p1d = *v56;
                v55 = v56[1];
                v57 = v54[1];
                p2d = *v54;
                v58 = -1;
              }
              v59 = v57;
              v60 = v5;
              v61 = v59;
              if ( v60 < v55 || v60 >= v61 )
              {
                v5 = v60;
              }
              else
              {
                v62 = (v6 - p2d) * (v61 - v55) - (v60 - v61) * (p2d - p1d);
                v5 = v60;
                pa = v62;
                if ( pa > 0.0 )
                  styleCount += v58;
              }
            }
            ++v52;
            --v53;
          }
          while ( v53 );
          v3 = path;
          v4 = i;
        }
      }
      i = ++v4;
    }
    while ( v4 < Size );
  }
  return styleCount != 0;
}
