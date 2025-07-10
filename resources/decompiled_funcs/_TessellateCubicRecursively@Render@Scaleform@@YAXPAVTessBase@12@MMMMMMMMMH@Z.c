void __cdecl Scaleform::Render::TessellateCubicRecursively(
        Scaleform::Render::TessBase *con,
        float toleranceSq,
        float x1,
        float y1,
        float x2,
        float y2,
        float x3,
        float y3,
        float x4,
        float y4,
        int level)
{
  int v11; // esi
  double v12; // st4
  double v13; // st3
  double v14; // st6
  double v15; // st7
  double v16; // st2
  double v17; // st7
  double v18; // st2
  double v19; // st1
  double v20; // st2
  double v21; // st1
  double v22; // st6
  double v23; // st2
  double v24; // st1
  double v25; // st3
  double v26; // st7
  double v27; // st5
  double v28; // st6
  double v29; // st6
  double v30; // st7
  double v31; // rtt
  double v32; // st7
  double v33; // st7
  long double v34; // st7
  long double v35; // st7
  double v36; // st7
  long double v37; // st7
  long double v38; // st7
  double v39; // st7
  long double v40; // st7
  long double v41; // st7
  long double v42; // st7
  double v43; // st7
  double v44; // st6
  bool v45; // c0
  double v46; // st7
  float v47; // [esp+18h] [ebp-58h]
  float v48; // [esp+18h] [ebp-58h]
  float v49; // [esp+1Ch] [ebp-54h]
  float v50; // [esp+1Ch] [ebp-54h]
  float v51; // [esp+20h] [ebp-50h]
  float v52; // [esp+20h] [ebp-50h]
  float v53; // [esp+24h] [ebp-4Ch]
  float v54; // [esp+24h] [ebp-4Ch]
  float d3d; // [esp+34h] [ebp-3Ch]
  float d3; // [esp+34h] [ebp-3Ch]
  float d3e; // [esp+34h] [ebp-3Ch]
  float d3f; // [esp+34h] [ebp-3Ch]
  float d3g; // [esp+34h] [ebp-3Ch]
  float d3h; // [esp+34h] [ebp-3Ch]
  float d3a; // [esp+34h] [ebp-3Ch]
  float d3b; // [esp+34h] [ebp-3Ch]
  float d3i; // [esp+34h] [ebp-3Ch]
  float d3j; // [esp+34h] [ebp-3Ch]
  float d3c; // [esp+34h] [ebp-3Ch]
  float d3k; // [esp+34h] [ebp-3Ch]
  float y23a; // [esp+38h] [ebp-38h]
  float y23; // [esp+38h] [ebp-38h]
  double y23b; // [esp+38h] [ebp-38h]
  float d2c; // [esp+40h] [ebp-30h]
  float d2d; // [esp+40h] [ebp-30h]
  float d2e; // [esp+40h] [ebp-30h]
  float d2; // [esp+40h] [ebp-30h]
  float d2a; // [esp+40h] [ebp-30h]
  float d2f; // [esp+40h] [ebp-30h]
  float d2b; // [esp+40h] [ebp-30h]
  float d2g; // [esp+40h] [ebp-30h]
  float d2h; // [esp+40h] [ebp-30h]
  float d2i; // [esp+40h] [ebp-30h]
  float d2j; // [esp+40h] [ebp-30h]
  float d2k; // [esp+40h] [ebp-30h]
  float d2l; // [esp+40h] [ebp-30h]
  float dy; // [esp+44h] [ebp-2Ch]
  float dyb; // [esp+44h] [ebp-2Ch]
  float dyc; // [esp+44h] [ebp-2Ch]
  float dyd; // [esp+44h] [ebp-2Ch]
  float dye; // [esp+44h] [ebp-2Ch]
  float dyf; // [esp+44h] [ebp-2Ch]
  float dyg; // [esp+44h] [ebp-2Ch]
  float dyh; // [esp+44h] [ebp-2Ch]
  float dyi; // [esp+44h] [ebp-2Ch]
  float dyj; // [esp+44h] [ebp-2Ch]
  float dyk; // [esp+44h] [ebp-2Ch]
  float dyl; // [esp+44h] [ebp-2Ch]
  float dym; // [esp+44h] [ebp-2Ch]
  float dyn; // [esp+44h] [ebp-2Ch]
  float dyo; // [esp+44h] [ebp-2Ch]
  float dyp; // [esp+44h] [ebp-2Ch]
  float dyq; // [esp+44h] [ebp-2Ch]
  float dyr; // [esp+44h] [ebp-2Ch]
  float dys; // [esp+44h] [ebp-2Ch]
  float dyt; // [esp+44h] [ebp-2Ch]
  float dyu; // [esp+44h] [ebp-2Ch]
  float dyv; // [esp+44h] [ebp-2Ch]
  float dyw; // [esp+44h] [ebp-2Ch]
  float dyx; // [esp+44h] [ebp-2Ch]
  float dyy; // [esp+44h] [ebp-2Ch]
  float dyz; // [esp+44h] [ebp-2Ch]
  float dyba; // [esp+44h] [ebp-2Ch]
  float dybb; // [esp+44h] [ebp-2Ch]
  float dybc; // [esp+44h] [ebp-2Ch]
  float dybd; // [esp+44h] [ebp-2Ch]
  float dybe; // [esp+44h] [ebp-2Ch]
  float dya; // [esp+44h] [ebp-2Ch]
  float y123; // [esp+48h] [ebp-28h]
  float x123; // [esp+4Ch] [ebp-24h]
  float y12; // [esp+50h] [ebp-20h]
  float x12; // [esp+54h] [ebp-1Ch]
  float y34; // [esp+58h] [ebp-18h]
  float x34; // [esp+5Ch] [ebp-14h]
  float y234; // [esp+60h] [ebp-10h]
  float x234; // [esp+64h] [ebp-Ch]
  float y1234; // [esp+68h] [ebp-8h]
  float x1234; // [esp+6Ch] [ebp-4h]

  if ( level <= 12 )
  {
    v11 = level + 1;
    while ( 2 )
    {
      x12 = (x1 + x2) * 0.5;
      v12 = y2;
      y12 = (y1 + y2) * 0.5;
      v13 = x3;
      d2c = (x2 + x3) * 0.5;
      y23a = (y2 + y3) * 0.5;
      x34 = (x3 + x4) * 0.5;
      y34 = (y3 + y4) * 0.5;
      x123 = (d2c + x12) * 0.5;
      y123 = (y23a + y12) * 0.5;
      x234 = (x34 + d2c) * 0.5;
      y234 = (y34 + y23a) * 0.5;
      v14 = y3;
      y23 = x4 - x1;
      dy = y4 - y1;
      v15 = dy;
      d2d = (x2 - x4) * dy - (y2 - y4) * y23;
      d2e = fabs(d2d);
      d3d = (x3 - x4) * dy - (y3 - y4) * y23;
      d3 = fabs(d3d);
      v16 = d2e;
      switch ( (d3 > 1.000000013351432e-10) + 2 * (d2e > 1.000000013351432e-10) )
      {
        case 0:
          d2 = dy * dy + y23 * y23;
          if ( d2 == 0.0 )
          {
            d2a = Scaleform::Render::Math2D::SqDistance(x1, y1, x2, y2);
            v53 = y3;
            v51 = x3;
            v49 = y4;
            v17 = x4;
            goto LABEL_24;
          }
          d2f = 1.0 / d2;
          d3e = x2 - x1;
          v18 = d3e * y23;
          d3f = v12 - y1;
          v19 = (v18 + d3f * v15) * d2f;
          v20 = d2f;
          d2b = v19;
          d3g = v13 - x1;
          v21 = v14 - y1;
          v22 = d3g * y23;
          d3h = v21;
          d3a = (v22 + d3h * v15) * v20;
          v23 = d2b;
          v24 = d3a;
          if ( d2b > 0.0 && v23 < 1.0 && v24 > 0.0 && v24 < 1.0 )
            goto LABEL_10;
          v25 = d2b;
          if ( v23 > 0.0 )
          {
            if ( v25 >= 1.0 )
            {
              v29 = y2;
              v30 = x2;
              v54 = y4;
              v52 = x4;
LABEL_18:
              v50 = v29;
              v47 = v30;
              d2a = Scaleform::Render::Math2D::SqDistance(v47, v50, v52, v54);
              v32 = d3a;
              if ( d3a > 0.0 )
              {
                if ( v32 < 1.0 )
                {
                  dyb = v32 * dy + y1;
                  v53 = dyb;
                  dyc = v32 * y23 + x1;
                  v33 = dyc;
                }
                else
                {
                  v53 = y4;
                  v33 = x4;
                }
              }
              else
              {
                v53 = y1;
                v33 = x1;
              }
              v51 = v33;
              v49 = y3;
              v17 = x3;
LABEL_24:
              v48 = v17;
              d3b = Scaleform::Render::Math2D::SqDistance(v48, v49, v51, v53);
              if ( toleranceSq > (double)d2a || d3b < (double)toleranceSq )
                goto LABEL_10;
              goto LABEL_44;
            }
            d2g = v15 * v25 + y1;
            v54 = d2g;
            v26 = y2;
            v28 = x2;
            d2h = x1 + v25 * y23;
            v27 = d2h;
          }
          else
          {
            v26 = y2;
            v54 = y1;
            v27 = x1;
            v28 = x2;
          }
          v52 = v27;
          v31 = v28;
          v29 = v26;
          v30 = v31;
          goto LABEL_18;
        case 1:
          if ( d3 * d3 > (v15 * v15 + y23 * y23) * toleranceSq )
            goto LABEL_44;
          dyd = y4 - v14;
          v34 = dyd;
          dye = x4 - x3;
          dyf = atan2(v34, dye);
          d2i = dyf;
          dyg = y3 - y2;
          v35 = dyg;
          dyh = x3 - x2;
          dyi = atan2(v35, dyh);
          dyj = d2i - dyi;
          dyk = fabs(dyj);
          v36 = dyk;
          if ( dyk >= 3.141592741012573 )
          {
            d3i = 6.283185482025146 - v36;
            v36 = d3i;
          }
          if ( v36 >= 0.25 )
            goto LABEL_44;
          goto LABEL_10;
        case 2:
          if ( v16 * v16 > (v15 * v15 + y23 * y23) * toleranceSq )
            goto LABEL_44;
          dyl = v14 - v12;
          v37 = dyl;
          dym = v13 - x2;
          dyn = atan2(v37, dym);
          d2j = dyn;
          dyo = y2 - y1;
          v38 = dyo;
          dyp = x2 - x1;
          dyq = atan2(v38, dyp);
          dyr = d2j - dyq;
          dys = fabs(dyr);
          v39 = dys;
          if ( dys >= 3.141592741012573 )
          {
            d3j = 6.283185482025146 - v39;
            v39 = d3j;
          }
          if ( v39 >= 0.25 )
            goto LABEL_44;
          goto LABEL_10;
        case 3:
          if ( (v16 + d3) * (v16 + d3) > (v15 * v15 + y23 * y23) * toleranceSq )
            goto LABEL_44;
          dyt = v14 - v12;
          v40 = dyt;
          dyu = v13 - x2;
          dyv = atan2(v40, dyu);
          d2k = dyv;
          y23b = dyv;
          dyw = y2 - y1;
          v41 = dyw;
          dyx = x2 - x1;
          dyy = atan2(v41, dyx);
          dyz = y23b - dyy;
          dyba = fabs(dyz);
          d3c = dyba;
          dybb = y4 - y3;
          v42 = dybb;
          dybc = x4 - x3;
          dybd = atan2(v42, dybc);
          dybe = dybd - d2k;
          dya = fabs(dybe);
          if ( d3c < 3.141592741012573 )
          {
            v44 = d3c;
            v43 = 3.141592741012573;
          }
          else
          {
            v43 = 3.141592741012573;
            d3k = 6.283185482025146 - d3c;
            v44 = d3k;
          }
          v45 = dya < v43;
          v46 = dya;
          if ( !v45 )
          {
            d2l = 6.283185482025146 - v46;
            v46 = d2l;
          }
          if ( v46 + v44 >= 0.25 )
            goto LABEL_44;
LABEL_10:
          ((void (__thiscall *)(Scaleform::Render::TessBase *, _DWORD, _DWORD))con->AddVertex)(
            con,
            LODWORD(x4),
            LODWORD(y4));
          return;
        default:
LABEL_44:
          y1234 = 0.5 * (y234 + y123);
          x1234 = (x234 + x123) * 0.5;
          Scaleform::Render::TessellateCubicRecursively(
            con,
            toleranceSq,
            x1,
            y1,
            x12,
            y12,
            x123,
            y123,
            x1234,
            y1234,
            v11);
          y3 = (y3 + y4) * 0.5;
          ++v11;
          x3 = (x3 + x4) * 0.5;
          y2 = y234;
          x2 = x234;
          y1 = y1234;
          x1 = x1234;
          if ( v11 > 13 )
            return;
          continue;
      }
    }
  }
}
