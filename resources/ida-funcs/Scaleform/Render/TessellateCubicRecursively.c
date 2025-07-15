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
  float y3a; // [esp+18h] [ebp-58h]
  float y3b; // [esp+18h] [ebp-58h]
  float x4a; // [esp+1Ch] [ebp-54h]
  float x4b; // [esp+1Ch] [ebp-54h]
  float y4a; // [esp+20h] [ebp-50h]
  float y4b; // [esp+20h] [ebp-50h]
  float v53; // [esp+24h] [ebp-4Ch]
  float v54; // [esp+24h] [ebp-4Ch]
  float v55; // [esp+34h] [ebp-3Ch]
  float v56; // [esp+34h] [ebp-3Ch]
  float v57; // [esp+34h] [ebp-3Ch]
  float v58; // [esp+34h] [ebp-3Ch]
  float v59; // [esp+34h] [ebp-3Ch]
  float v60; // [esp+34h] [ebp-3Ch]
  float v61; // [esp+34h] [ebp-3Ch]
  float v62; // [esp+34h] [ebp-3Ch]
  float v63; // [esp+34h] [ebp-3Ch]
  float v64; // [esp+34h] [ebp-3Ch]
  float v65; // [esp+34h] [ebp-3Ch]
  float v66; // [esp+34h] [ebp-3Ch]
  float v67; // [esp+38h] [ebp-38h]
  float v68; // [esp+38h] [ebp-38h]
  double v69; // [esp+38h] [ebp-38h]
  float v70; // [esp+40h] [ebp-30h]
  float v71; // [esp+40h] [ebp-30h]
  float v72; // [esp+40h] [ebp-30h]
  float v73; // [esp+40h] [ebp-30h]
  float v74; // [esp+40h] [ebp-30h]
  float v75; // [esp+40h] [ebp-30h]
  float v76; // [esp+40h] [ebp-30h]
  float v77; // [esp+40h] [ebp-30h]
  float v78; // [esp+40h] [ebp-30h]
  float v79; // [esp+40h] [ebp-30h]
  float v80; // [esp+40h] [ebp-30h]
  float v81; // [esp+40h] [ebp-30h]
  float v82; // [esp+40h] [ebp-30h]
  float v83; // [esp+44h] [ebp-2Ch]
  float v84; // [esp+44h] [ebp-2Ch]
  float v85; // [esp+44h] [ebp-2Ch]
  float v86; // [esp+44h] [ebp-2Ch]
  float v87; // [esp+44h] [ebp-2Ch]
  float v88; // [esp+44h] [ebp-2Ch]
  float v89; // [esp+44h] [ebp-2Ch]
  float v90; // [esp+44h] [ebp-2Ch]
  float v91; // [esp+44h] [ebp-2Ch]
  float v92; // [esp+44h] [ebp-2Ch]
  float v93; // [esp+44h] [ebp-2Ch]
  float v94; // [esp+44h] [ebp-2Ch]
  float v95; // [esp+44h] [ebp-2Ch]
  float v96; // [esp+44h] [ebp-2Ch]
  float v97; // [esp+44h] [ebp-2Ch]
  float v98; // [esp+44h] [ebp-2Ch]
  float v99; // [esp+44h] [ebp-2Ch]
  float v100; // [esp+44h] [ebp-2Ch]
  float v101; // [esp+44h] [ebp-2Ch]
  float v102; // [esp+44h] [ebp-2Ch]
  float v103; // [esp+44h] [ebp-2Ch]
  float v104; // [esp+44h] [ebp-2Ch]
  float v105; // [esp+44h] [ebp-2Ch]
  float v106; // [esp+44h] [ebp-2Ch]
  float v107; // [esp+44h] [ebp-2Ch]
  float v108; // [esp+44h] [ebp-2Ch]
  float v109; // [esp+44h] [ebp-2Ch]
  float v110; // [esp+44h] [ebp-2Ch]
  float v111; // [esp+44h] [ebp-2Ch]
  float v112; // [esp+44h] [ebp-2Ch]
  float v113; // [esp+44h] [ebp-2Ch]
  float v114; // [esp+44h] [ebp-2Ch]
  float v115; // [esp+48h] [ebp-28h]
  float v116; // [esp+4Ch] [ebp-24h]
  float v117; // [esp+50h] [ebp-20h]
  float v118; // [esp+54h] [ebp-1Ch]
  float v119; // [esp+58h] [ebp-18h]
  float v120; // [esp+5Ch] [ebp-14h]
  float v121; // [esp+60h] [ebp-10h]
  float v122; // [esp+64h] [ebp-Ch]
  float v123; // [esp+68h] [ebp-8h]
  float v124; // [esp+6Ch] [ebp-4h]

  if ( level <= 12 )
  {
    v11 = level + 1;
    while ( 2 )
    {
      v118 = (x1 + x2) * 0.5;
      v12 = y2;
      v117 = (y1 + y2) * 0.5;
      v13 = x3;
      v70 = (x2 + x3) * 0.5;
      v67 = (y2 + y3) * 0.5;
      v120 = (x3 + x4) * 0.5;
      v119 = (y3 + y4) * 0.5;
      v116 = (v70 + v118) * 0.5;
      v115 = (v67 + v117) * 0.5;
      v122 = (v120 + v70) * 0.5;
      v121 = (v119 + v67) * 0.5;
      v14 = y3;
      v68 = x4 - x1;
      v83 = y4 - y1;
      v15 = v83;
      v71 = (x2 - x4) * v83 - (y2 - y4) * v68;
      v72 = fabs(v71);
      v55 = (x3 - x4) * v83 - (y3 - y4) * v68;
      v56 = fabs(v55);
      v16 = v72;
      switch ( (v56 > 1.000000013351432e-10) + 2 * (v72 > 1.000000013351432e-10) )
      {
        case 0:
          v73 = v83 * v83 + v68 * v68;
          if ( v73 == 0.0 )
          {
            v74 = Scaleform::Render::Math2D::SqDistance(x1, y1, x2, y2);
            v53 = y3;
            y4a = x3;
            x4a = y4;
            v17 = x4;
            goto LABEL_24;
          }
          v75 = 1.0 / v73;
          v57 = x2 - x1;
          v18 = v57 * v68;
          v58 = v12 - y1;
          v19 = (v18 + v58 * v15) * v75;
          v20 = v75;
          v76 = v19;
          v59 = v13 - x1;
          v21 = v14 - y1;
          v22 = v59 * v68;
          v60 = v21;
          v61 = (v22 + v60 * v15) * v20;
          v23 = v76;
          v24 = v61;
          if ( v76 > 0.0 && v23 < 1.0 && v24 > 0.0 && v24 < 1.0 )
            goto LABEL_10;
          v25 = v76;
          if ( v23 > 0.0 )
          {
            if ( v25 >= 1.0 )
            {
              v29 = y2;
              v30 = x2;
              v54 = y4;
              y4b = x4;
LABEL_18:
              x4b = v29;
              y3a = v30;
              v74 = Scaleform::Render::Math2D::SqDistance(y3a, x4b, y4b, v54);
              v32 = v61;
              if ( v61 > 0.0 )
              {
                if ( v32 < 1.0 )
                {
                  v84 = v32 * v83 + y1;
                  v53 = v84;
                  v85 = v32 * v68 + x1;
                  v33 = v85;
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
              y4a = v33;
              x4a = y3;
              v17 = x3;
LABEL_24:
              y3b = v17;
              v62 = Scaleform::Render::Math2D::SqDistance(y3b, x4a, y4a, v53);
              if ( toleranceSq > (double)v74 || v62 < (double)toleranceSq )
                goto LABEL_10;
              goto LABEL_44;
            }
            v77 = v15 * v25 + y1;
            v54 = v77;
            v26 = y2;
            v28 = x2;
            v78 = x1 + v25 * v68;
            v27 = v78;
          }
          else
          {
            v26 = y2;
            v54 = y1;
            v27 = x1;
            v28 = x2;
          }
          y4b = v27;
          v31 = v28;
          v29 = v26;
          v30 = v31;
          goto LABEL_18;
        case 1:
          if ( v56 * v56 > (v15 * v15 + v68 * v68) * toleranceSq )
            goto LABEL_44;
          v86 = y4 - v14;
          v34 = v86;
          v87 = x4 - x3;
          v88 = atan2(v34, v87);
          v79 = v88;
          v89 = y3 - y2;
          v35 = v89;
          v90 = x3 - x2;
          v91 = atan2(v35, v90);
          v92 = v79 - v91;
          v93 = fabs(v92);
          v36 = v93;
          if ( v93 >= 3.141592741012573 )
          {
            v63 = 6.283185482025146 - v36;
            v36 = v63;
          }
          if ( v36 >= 0.25 )
            goto LABEL_44;
          goto LABEL_10;
        case 2:
          if ( v16 * v16 > (v15 * v15 + v68 * v68) * toleranceSq )
            goto LABEL_44;
          v94 = v14 - v12;
          v37 = v94;
          v95 = v13 - x2;
          v96 = atan2(v37, v95);
          v80 = v96;
          v97 = y2 - y1;
          v38 = v97;
          v98 = x2 - x1;
          v99 = atan2(v38, v98);
          v100 = v80 - v99;
          v101 = fabs(v100);
          v39 = v101;
          if ( v101 >= 3.141592741012573 )
          {
            v64 = 6.283185482025146 - v39;
            v39 = v64;
          }
          if ( v39 >= 0.25 )
            goto LABEL_44;
          goto LABEL_10;
        case 3:
          if ( (v16 + v56) * (v16 + v56) > (v15 * v15 + v68 * v68) * toleranceSq )
            goto LABEL_44;
          v102 = v14 - v12;
          v40 = v102;
          v103 = v13 - x2;
          v104 = atan2(v40, v103);
          v81 = v104;
          v69 = v104;
          v105 = y2 - y1;
          v41 = v105;
          v106 = x2 - x1;
          v107 = atan2(v41, v106);
          v108 = v69 - v107;
          v109 = fabs(v108);
          v65 = v109;
          v110 = y4 - y3;
          v42 = v110;
          v111 = x4 - x3;
          v112 = atan2(v42, v111);
          v113 = v112 - v81;
          v114 = fabs(v113);
          if ( v65 < 3.141592741012573 )
          {
            v44 = v65;
            v43 = 3.141592741012573;
          }
          else
          {
            v43 = 3.141592741012573;
            v66 = 6.283185482025146 - v65;
            v44 = v66;
          }
          v45 = v114 < v43;
          v46 = v114;
          if ( !v45 )
          {
            v82 = 6.283185482025146 - v46;
            v46 = v82;
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
          v123 = 0.5 * (v121 + v115);
          v124 = (v122 + v116) * 0.5;
          Scaleform::Render::TessellateCubicRecursively(
            con,
            toleranceSq,
            x1,
            y1,
            v118,
            v117,
            v116,
            v115,
            v124,
            v123,
            v11);
          y3 = (y3 + y4) * 0.5;
          ++v11;
          x3 = (x3 + x4) * 0.5;
          y2 = v121;
          x2 = v122;
          y1 = v123;
          x1 = v124;
          if ( v11 > 13 )
            return;
          continue;
      }
    }
  }
}
