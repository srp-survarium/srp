void __usercall dradfg(
        float *c1@<ecx>,
        float *ch@<eax>,
        int ido,
        int ip,
        int l1,
        int idl1,
        float *cc,
        float *c2,
        float *ch2,
        float *wa)
{
  int v11; // ebp
  int v14; // edx
  float *v15; // ecx
  float *v16; // eax
  bool v17; // zf
  float *v18; // eax
  int v19; // ecx
  double v20; // st7
  int v21; // eax
  int v22; // ecx
  int v23; // eax
  unsigned int v24; // edx
  int v25; // eax
  int v26; // eax
  int v27; // eax
  int v28; // edx
  int v29; // ecx
  float *v30; // eax
  int v31; // eax
  int v32; // edx
  float *v33; // edx
  float *v34; // eax
  float *v35; // edx
  float *v36; // ecx
  double v37; // st7
  double v38; // st6
  int v39; // edx
  float *v40; // ecx
  int v41; // eax
  unsigned int v42; // edx
  int v43; // eax
  int v44; // eax
  int v45; // eax
  float *v46; // ebp
  float *v47; // eax
  double v48; // st7
  double v49; // st6
  int v50; // edx
  int v51; // edx
  int v52; // eax
  int v53; // eax
  int v54; // ecx
  int v55; // edx
  unsigned int v56; // edx
  int v57; // eax
  int v58; // ecx
  double v59; // st7
  int v60; // eax
  int v61; // ecx
  double v62; // st7
  int v63; // eax
  int v64; // ecx
  double v65; // st7
  int v66; // edx
  float *v67; // eax
  float *v68; // ecx
  double v69; // st7
  float *v70; // ecx
  float *v71; // ecx
  float *v72; // eax
  unsigned int v73; // edx
  double v74; // st7
  int v75; // edx
  float *v76; // ecx
  float *v77; // eax
  float *v78; // eax
  int v79; // ecx
  double v80; // st7
  int v81; // ecx
  int v82; // ecx
  int v83; // eax
  int v84; // edx
  int v85; // eax
  int v86; // ecx
  unsigned int v87; // edx
  int v88; // eax
  int v89; // ecx
  double v90; // st7
  int v91; // eax
  int v92; // ecx
  double v93; // st7
  int v94; // eax
  int v95; // ecx
  double v96; // st7
  float *v97; // eax
  float *v98; // ecx
  double v99; // st7
  double v100; // st7
  int v101; // edx
  double v102; // st7
  double v103; // st6
  double v104; // st5
  int v105; // ecx
  int v106; // eax
  int v107; // edx
  double v108; // st5
  double v109; // st4
  unsigned int v110; // edi
  float *v111; // eax
  double v112; // st3
  float *v113; // ecx
  double v114; // st3
  float *v115; // ecx
  float *v116; // edi
  float *v117; // eax
  float *v118; // ecx
  double v119; // st3
  double v120; // st3
  float *v121; // edi
  int v122; // edx
  int v123; // edi
  double v124; // st6
  double v125; // st4
  int v126; // ecx
  int v127; // eax
  int v128; // edx
  double v129; // st4
  double v130; // st3
  float *v131; // ecx
  float *v132; // eax
  unsigned int v133; // edi
  float *v134; // ebp
  double v135; // st2
  float *v136; // ebp
  float *v137; // ecx
  int v138; // eax
  float *v139; // edx
  double v140; // st2
  float *v141; // edi
  int v142; // edi
  float *v143; // edx
  signed int v144; // ecx
  int v145; // eax
  float *v146; // eax
  float *v147; // edx
  unsigned int v148; // edi
  double v149; // st7
  double v150; // st7
  float *v151; // eax
  double v152; // st7
  double v153; // st7
  int v154; // ebp
  int v155; // eax
  int v156; // ecx
  unsigned int v157; // ebp
  double v158; // st7
  int v159; // eax
  int v160; // ecx
  double v161; // st7
  int v162; // eax
  int v163; // ecx
  double v164; // st7
  int v165; // eax
  int v166; // ecx
  double v167; // st7
  float *v168; // ecx
  int v169; // eax
  int v170; // eax
  int v171; // edi
  int v172; // ebp
  float *v173; // edx
  float *v174; // ecx
  unsigned int v175; // eax
  double v176; // st7
  float *v177; // edx
  float *v178; // ecx
  int v179; // eax
  double v180; // st7
  int v181; // eax
  int v182; // ecx
  int v183; // edx
  int v184; // ebp
  int v185; // eax
  int v186; // ecx
  int v187; // edx
  int v188; // ebp
  int v189; // ecx
  double v190; // st7
  int v191; // edx
  int v192; // eax
  double v193; // st7
  int v194; // ecx
  double v195; // st7
  int v196; // edx
  int v197; // eax
  double v198; // st7
  int v199; // ecx
  double v200; // st7
  int v201; // edx
  int v202; // eax
  double v203; // st7
  double v204; // st7
  float *v205; // edx
  int v206; // ecx
  float *v207; // eax
  int v208; // ecx
  int v209; // edi
  int v210; // edx
  int v211; // ebp
  int v212; // eax
  int v213; // edi
  int v214; // ecx
  int v215; // ebp
  int v216; // edx
  int v217; // edi
  int v218; // ecx
  double v219; // st7
  int v220; // ecx
  double v221; // st7
  int v222; // eax
  int v223; // edx
  int v224; // edi
  double v225; // st7
  int v226; // ecx
  double v227; // st7
  int v228; // eax
  int v229; // edx
  int v230; // edi
  double v231; // st7
  int v232; // ecx
  double v233; // st7
  int v234; // eax
  int v235; // edx
  int v236; // edi
  double v237; // st7
  double v238; // st7
  float *v239; // ebp
  float *v240; // edx
  int v241; // edi
  float *v242; // eax
  float *v243; // ecx
  int v244; // ecx
  int v245; // edx
  float *v246; // ebp
  int v247; // ecx
  float *v248; // eax
  int v249; // esi
  float *v250; // edi
  unsigned int v251; // edx
  double v252; // st7
  int t1; // [esp+0h] [ebp-5Ch]
  int t1a; // [esp+0h] [ebp-5Ch]
  int t1b; // [esp+0h] [ebp-5Ch]
  int t1c; // [esp+0h] [ebp-5Ch]
  int t1d; // [esp+0h] [ebp-5Ch]
  int t1e; // [esp+0h] [ebp-5Ch]
  int t1f; // [esp+0h] [ebp-5Ch]
  int ipph; // [esp+4h] [ebp-58h]
  int t2; // [esp+8h] [ebp-54h]
  int t2a; // [esp+8h] [ebp-54h]
  int t2b; // [esp+8h] [ebp-54h]
  int t2c; // [esp+8h] [ebp-54h]
  int t2d; // [esp+8h] [ebp-54h]
  int t0; // [esp+Ch] [ebp-50h]
  int t10; // [esp+10h] [ebp-4Ch]
  int t4; // [esp+14h] [ebp-48h]
  int t4a; // [esp+14h] [ebp-48h]
  int t4b; // [esp+14h] [ebp-48h]
  int t4c; // [esp+14h] [ebp-48h]
  int t4d; // [esp+14h] [ebp-48h]
  int t4e; // [esp+14h] [ebp-48h]
  int t4f; // [esp+14h] [ebp-48h]
  int t7; // [esp+18h] [ebp-44h]
  int t7a; // [esp+18h] [ebp-44h]
  int t7b; // [esp+18h] [ebp-44h]
  int t7c; // [esp+18h] [ebp-44h]
  float *v279; // [esp+1Ch] [ebp-40h]
  float *v280; // [esp+1Ch] [ebp-40h]
  float *v281; // [esp+1Ch] [ebp-40h]
  int v282; // [esp+20h] [ebp-3Ch]
  float *v283; // [esp+20h] [ebp-3Ch]
  float *v284; // [esp+20h] [ebp-3Ch]
  float *v285; // [esp+20h] [ebp-3Ch]
  float *v286; // [esp+20h] [ebp-3Ch]
  int t5; // [esp+24h] [ebp-38h]
  int t5a; // [esp+24h] [ebp-38h]
  int t5b; // [esp+24h] [ebp-38h]
  int t5c; // [esp+24h] [ebp-38h]
  int t5d; // [esp+24h] [ebp-38h]
  int t5e; // [esp+24h] [ebp-38h]
  int t5f; // [esp+24h] [ebp-38h]
  int v294; // [esp+28h] [ebp-34h]
  int v295; // [esp+28h] [ebp-34h]
  unsigned int v296; // [esp+28h] [ebp-34h]
  float *v297; // [esp+28h] [ebp-34h]
  float *v298; // [esp+28h] [ebp-34h]
  float *v299; // [esp+28h] [ebp-34h]
  float *v300; // [esp+28h] [ebp-34h]
  float *v301; // [esp+2Ch] [ebp-30h]
  float *v302; // [esp+2Ch] [ebp-30h]
  float *v303; // [esp+2Ch] [ebp-30h]
  unsigned int v304; // [esp+30h] [ebp-2Ch]
  float *v305; // [esp+30h] [ebp-2Ch]
  float *v306; // [esp+30h] [ebp-2Ch]
  float *v307; // [esp+30h] [ebp-2Ch]
  float *v308; // [esp+30h] [ebp-2Ch]
  float *v309; // [esp+30h] [ebp-2Ch]
  int i; // [esp+34h] [ebp-28h]
  float *ia; // [esp+34h] [ebp-28h]
  int ib; // [esp+34h] [ebp-28h]
  int ic; // [esp+34h] [ebp-28h]
  float *id; // [esp+34h] [ebp-28h]
  int ie; // [esp+34h] [ebp-28h]
  int ig; // [esp+34h] [ebp-28h]
  int ih; // [esp+34h] [ebp-28h]
  float *ii; // [esp+34h] [ebp-28h]
  int ij; // [esp+34h] [ebp-28h]
  int ik; // [esp+34h] [ebp-28h]
  int il; // [esp+34h] [ebp-28h]
  int is; // [esp+38h] [ebp-24h]
  int isa; // [esp+38h] [ebp-24h]
  int isb; // [esp+38h] [ebp-24h]
  int isc; // [esp+38h] [ebp-24h]
  int isd; // [esp+38h] [ebp-24h]
  int ise; // [esp+38h] [ebp-24h]
  int isf; // [esp+38h] [ebp-24h]
  int isg; // [esp+38h] [ebp-24h]
  int ish; // [esp+38h] [ebp-24h]
  float *isi; // [esp+38h] [ebp-24h]
  int isj; // [esp+38h] [ebp-24h]
  int nbd; // [esp+3Ch] [ebp-20h]
  int nbda; // [esp+3Ch] [ebp-20h]
  float *nbdb; // [esp+3Ch] [ebp-20h]
  float ar1; // [esp+40h] [ebp-1Ch]
  int ar1a; // [esp+40h] [ebp-1Ch]
  float dcp; // [esp+44h] [ebp-18h]
  float dcpa; // [esp+44h] [ebp-18h]
  int dcpb; // [esp+44h] [ebp-18h]
  int t9; // [esp+48h] [ebp-14h]
  int t9a; // [esp+48h] [ebp-14h]
  int t8; // [esp+4Ch] [ebp-10h]
  float t8c; // [esp+4Ch] [ebp-10h]
  int t8a; // [esp+4Ch] [ebp-10h]
  int t8b; // [esp+4Ch] [ebp-10h]
  int ar1h; // [esp+50h] [ebp-Ch]
  float ar1ha; // [esp+50h] [ebp-Ch]
  int ar1hb; // [esp+50h] [ebp-Ch]
  int ar1hc; // [esp+50h] [ebp-Ch]
  float dsp; // [esp+54h] [ebp-8h]
  int dspa; // [esp+54h] [ebp-8h]
  float *dspb; // [esp+54h] [ebp-8h]
  int dspc; // [esp+54h] [ebp-8h]
  float *v355; // [esp+58h] [ebp-4h]
  int v356; // [esp+58h] [ebp-4h]
  float *v357; // [esp+58h] [ebp-4h]
  int v358; // [esp+58h] [ebp-4h]
  int v359; // [esp+58h] [ebp-4h]
  int v360; // [esp+58h] [ebp-4h]
  int v361; // [esp+58h] [ebp-4h]
  unsigned int v362; // [esp+58h] [ebp-4h]
  int v363; // [esp+58h] [ebp-4h]
  int v364; // [esp+58h] [ebp-4h]
  float args; // [esp+60h] [ebp+4h]
  int arg; // [esp+60h] [ebp+4h]
  float *arga; // [esp+60h] [ebp+4h]
  signed int argb; // [esp+60h] [ebp+4h]
  int argc; // [esp+60h] [ebp+4h]
  signed int argd; // [esp+60h] [ebp+4h]
  int arge; // [esp+60h] [ebp+4h]
  float *argf; // [esp+60h] [ebp+4h]
  signed int argg; // [esp+60h] [ebp+4h]
  int argh; // [esp+60h] [ebp+4h]
  float argt; // [esp+60h] [ebp+4h]
  float *argi; // [esp+60h] [ebp+4h]
  float *argj; // [esp+60h] [ebp+4h]
  float argu; // [esp+60h] [ebp+4h]
  float argv; // [esp+60h] [ebp+4h]
  float *argk; // [esp+60h] [ebp+4h]
  float *argl; // [esp+60h] [ebp+4h]
  int argm; // [esp+60h] [ebp+4h]
  signed int argn; // [esp+60h] [ebp+4h]
  float *argo; // [esp+60h] [ebp+4h]
  int argp; // [esp+60h] [ebp+4h]
  int argq; // [esp+60h] [ebp+4h]
  float *argr; // [esp+60h] [ebp+4h]
  int v388; // [esp+64h] [ebp+8h]
  float *v389; // [esp+64h] [ebp+8h]
  int v390; // [esp+64h] [ebp+8h]
  float *v391; // [esp+64h] [ebp+8h]
  float *t3; // [esp+6Ch] [ebp+10h]
  float *t3a; // [esp+6Ch] [ebp+10h]
  int t3b; // [esp+6Ch] [ebp+10h]
  int t3c; // [esp+6Ch] [ebp+10h]
  int t3d; // [esp+6Ch] [ebp+10h]
  float *t3e; // [esp+6Ch] [ebp+10h]

  v11 = idl1;
  args = 6.283185482025146 / (double)ip;
  dcp = cos(args);
  dsp = sin(args);
  ipph = (ip + 1) >> 1;
  nbd = (ido - 1) >> 1;
  t0 = l1 * ido;
  t10 = ip * ido;
  if ( ido != 1 )
  {
    v14 = 0;
    if ( idl1 >= 4 )
    {
      v15 = c2 + 3;
      v16 = ch2 + 1;
      is = ((unsigned int)(idl1 - 4) >> 2) + 1;
      i = 4 * is;
      do
      {
        *(v16 - 1) = *(v15 - 3);
        v16 += 4;
        v15 += 4;
        v17 = is-- == 1;
        *(v16 - 4) = *(float *)((char *)v16 + (char *)c2 - (char *)ch2 - 16);
        *(v16 - 3) = *(v15 - 5);
        *(v16 - 2) = *(v15 - 4);
      }
      while ( !v17 );
      v14 = i;
    }
    if ( v14 < idl1 )
    {
      v18 = &ch2[v14];
      v19 = idl1 - v14;
      do
      {
        v20 = *(float *)((char *)v18++ + (char *)c2 - (char *)ch2);
        --v19;
        *(v18 - 1) = v20;
      }
      while ( v19 );
    }
    v21 = 0;
    if ( ip <= 1 )
    {
      v22 = l1;
    }
    else
    {
      isa = ip - 1;
      v22 = l1;
      while ( 1 )
      {
        v23 = t0 + v21;
        t1 = v23;
        arg = 0;
        if ( v22 >= 4 )
        {
          v24 = ((unsigned int)(v22 - 4) >> 2) + 1;
          arg = 4 * v24;
          do
          {
            ch[v23] = c1[v23];
            v25 = ido + v23;
            ch[v25] = c1[v25];
            v26 = ido + v25;
            ch[v26] = c1[v26];
            v27 = ido + v26;
            ch[v27] = c1[v27];
            v23 = ido + v27;
            --v24;
          }
          while ( v24 );
          v22 = l1;
        }
        if ( arg < v22 )
        {
          v28 = (char *)c1 - (char *)ch;
          v29 = v22 - arg;
          v30 = &ch[v23];
          while ( 1 )
          {
            *v30 = *(float *)((char *)v30 + v28);
            v30 += ido;
            if ( !--v29 )
              break;
            v28 = (char *)c1 - (char *)ch;
          }
          v22 = l1;
        }
        if ( !--isa )
          break;
        v21 = t1;
      }
    }
    v31 = -ido;
    v32 = 0;
    if ( nbd <= v22 )
    {
      if ( ip > 1 )
      {
        ib = v31 - 1;
        v305 = &wa[-ido - 1];
        v282 = ip - 1;
        while ( 1 )
        {
          ib += ido;
          isc = ido + v31;
          v305 += ido;
          t1a = t0 + v32;
          if ( ido > 2 )
          {
            v39 = l1;
            v295 = ib - isc + t1a + 1;
            v40 = v305;
            t5a = ((unsigned int)(ido - 3) >> 1) + 1;
            do
            {
              v41 = v295 + 2;
              v40 += 2;
              v295 += 2;
              argb = 0;
              if ( v39 >= 4 )
              {
                argb = 4 * (((unsigned int)(v39 - 4) >> 2) + 1);
                v42 = ((unsigned int)(v39 - 4) >> 2) + 1;
                do
                {
                  ch[v41 - 1] = *(v40 - 1) * c1[v41 - 1] + c1[v41] * *v40;
                  ch[v41] = *(v40 - 1) * c1[v41] - c1[v41 - 1] * *v40;
                  v43 = ido + v41;
                  ch[v43 - 1] = *(v40 - 1) * c1[v43 - 1] + c1[v43] * *v40;
                  ch[v43] = *(v40 - 1) * c1[v43] - c1[v43 - 1] * *v40;
                  v44 = ido + v43;
                  ch[v44 - 1] = *(v40 - 1) * c1[v44 - 1] + c1[v44] * *v40;
                  ch[v44] = *(v40 - 1) * c1[v44] - c1[v44 - 1] * *v40;
                  v45 = ido + v44;
                  ch[v45 - 1] = *(v40 - 1) * c1[v45 - 1] + c1[v45] * *v40;
                  ch[v45] = *(v40 - 1) * c1[v45] - c1[v45 - 1] * *v40;
                  v41 = ido + v45;
                  --v42;
                }
                while ( v42 );
                v39 = l1;
              }
              if ( argb < v39 )
              {
                v46 = &ch[v41];
                v47 = &c1[v41 - 1];
                argc = l1 - argb;
                do
                {
                  *(float *)((char *)v47 + (char *)ch - (char *)c1) = *v47 * *(v40 - 1) + v47[1] * *v40;
                  v48 = *(v40 - 1) * v47[1];
                  v49 = *v47;
                  v47 += ido;
                  *v46 = v48 - v49 * *v40;
                  v46 += ido;
                  --argc;
                }
                while ( argc );
                v11 = idl1;
                v39 = l1;
              }
              --t5a;
            }
            while ( t5a );
          }
          if ( !--v282 )
            break;
          v31 = isc;
          v32 = t1a;
        }
      }
    }
    else if ( ip > 1 )
    {
      arga = &wa[-ido - 1];
      v33 = &ch[-ido];
      v34 = &c1[-ido - 1];
      t5 = ip - 1;
      while ( 1 )
      {
        v35 = &v33[t0];
        v34 += t0;
        arga += ido;
        isb = (int)v35;
        t8 = (int)v34;
        if ( l1 > 0 )
        {
          v294 = l1;
          do
          {
            v35 += ido;
            v34 += ido;
            v355 = v34;
            if ( ido > 2 )
            {
              v36 = arga;
              ia = v35;
              v304 = ((unsigned int)(ido - 3) >> 1) + 1;
              do
              {
                v37 = v34[3] * v36[2];
                ia += 2;
                v34 += 2;
                v38 = v36[1] * *v34;
                v36 += 2;
                v17 = v304-- == 1;
                *(float *)((char *)v34 + (char *)ch - (char *)c1) = v37 + v38;
                *ia = v34[1] * *(v36 - 1) - *v36 * *v34;
              }
              while ( !v17 );
              v34 = v355;
            }
            --v294;
          }
          while ( v294 );
          v34 = (float *)t8;
        }
        if ( !--t5 )
          break;
        v33 = (float *)isb;
      }
    }
    v50 = ip * t0;
    t1b = 0;
    if ( nbd >= l1 )
    {
      if ( ipph > 1 )
      {
        v307 = &ch[v50 - 1];
        id = &c1[v50];
        v70 = c1;
        argf = ch - 1;
        t2a = ipph - 1;
        do
        {
          argf += t0;
          id -= t0;
          v307 -= t0;
          v70 += t0;
          v357 = v70;
          if ( l1 > 0 )
          {
            t5c = (int)v70;
            v279 = id;
            v71 = v307;
            v283 = argf;
            ise = (int)v307;
            t7 = l1;
            do
            {
              if ( ido > 2 )
              {
                v297 = v279;
                t4a = (char *)c1 - (char *)ch;
                v302 = (float *)t5c;
                v72 = v283;
                v73 = ((unsigned int)(ido - 3) >> 1) + 1;
                do
                {
                  v74 = v71[2] + v72[2];
                  v302 += 2;
                  v297 += 2;
                  v71 += 2;
                  v72 += 2;
                  --v73;
                  *(float *)((char *)v72 + t4a) = v74;
                  *(float *)((char *)v71 + t4a) = v72[1] - v71[1];
                  *v302 = v71[1] + v72[1];
                  *v297 = *v71 - *v72;
                }
                while ( v73 );
                v11 = idl1;
              }
              t5c += 4 * ido;
              v283 += ido;
              v279 += ido;
              v71 = (float *)(4 * ido + ise);
              v17 = t7-- == 1;
              ise = (int)v71;
            }
            while ( !v17 );
            v70 = v357;
          }
          --t2a;
        }
        while ( t2a );
      }
    }
    else if ( ipph > 1 )
    {
      ic = -ido;
      t5b = ipph - 1;
      do
      {
        t1b += t0;
        ic += t0;
        v50 -= t0;
        t2 = v50;
        if ( ido > 2 )
        {
          v51 = v50 - t1b;
          v52 = ic;
          v356 = v51;
          v296 = ((unsigned int)(ido - 3) >> 1) + 1;
          while ( 1 )
          {
            v53 = v52 + 2;
            v54 = v53 + v51;
            v55 = l1;
            isd = v53;
            argd = 0;
            if ( l1 >= 4 )
            {
              argd = 4 * (((unsigned int)(l1 - 4) >> 2) + 1);
              v56 = ((unsigned int)(l1 - 4) >> 2) + 1;
              do
              {
                v57 = ido + v53;
                v58 = ido + v54;
                c1[v57 - 1] = ch[v57 - 1] + ch[v58 - 1];
                c1[v58 - 1] = ch[v57] - ch[v58];
                c1[v57] = ch[v57] + ch[v58];
                v59 = ch[v58 - 1] - ch[v57 - 1];
                v60 = ido + v57;
                c1[v58] = v59;
                v61 = ido + v58;
                c1[v60 - 1] = ch[v60 - 1] + ch[v61 - 1];
                c1[v61 - 1] = ch[v60] - ch[v61];
                c1[v60] = ch[v60] + ch[v61];
                v62 = ch[v61 - 1] - ch[v60 - 1];
                v63 = ido + v60;
                c1[v61] = v62;
                v64 = ido + v61;
                c1[v63 - 1] = ch[v63 - 1] + ch[v64 - 1];
                c1[v64 - 1] = ch[v63] - ch[v64];
                c1[v63] = ch[v63] + ch[v64];
                v65 = ch[v64 - 1] - ch[v63 - 1];
                v53 = ido + v63;
                c1[v64] = v65;
                v54 = ido + v64;
                --v56;
                c1[v53 - 1] = ch[v53 - 1] + ch[v54 - 1];
                c1[v54 - 1] = ch[v53] - ch[v54];
                c1[v53] = ch[v53] + ch[v54];
                c1[v54] = ch[v54 - 1] - ch[v53 - 1];
              }
              while ( v56 );
              v55 = l1;
            }
            if ( argd < v55 )
            {
              v301 = &c1[v54];
              v306 = &c1[v53];
              t4 = (char *)c1 - (char *)ch;
              v66 = 4 * ido;
              v67 = &ch[v53 - 1];
              v68 = &ch[v54 - 1];
              arge = l1 - argd;
              do
              {
                v69 = v68[ido] + v67[ido];
                v306 = (float *)((char *)v306 + v66);
                v301 = (float *)((char *)v301 + v66);
                v68 = (float *)((char *)v68 + v66);
                v67 = (float *)((char *)v67 + v66);
                v17 = arge-- == 1;
                *(float *)((char *)v67 + t4) = v69;
                *(float *)((char *)v68 + t4) = v67[1] - v68[1];
                *v306 = v68[1] + v67[1];
                *v301 = *v68 - *v67;
              }
              while ( !v17 );
              v11 = idl1;
            }
            v17 = v296-- == 1;
            v52 = isd;
            if ( v17 )
              break;
            v51 = v356;
          }
          v50 = t2;
        }
        --t5b;
      }
      while ( t5b );
    }
  }
  v75 = 0;
  if ( v11 >= 4 )
  {
    v76 = ch2 + 3;
    v77 = c2 + 1;
    isf = ((unsigned int)(v11 - 4) >> 2) + 1;
    ie = 4 * isf;
    do
    {
      *(v77 - 1) = *(v76 - 3);
      v77 += 4;
      v76 += 4;
      v17 = isf-- == 1;
      *(v77 - 4) = *(float *)((char *)v77 + (char *)ch2 - (char *)c2 - 16);
      *(v77 - 3) = *(v76 - 5);
      *(v77 - 2) = *(v76 - 4);
    }
    while ( !v17 );
    v75 = ie;
  }
  if ( v75 < v11 )
  {
    v78 = &c2[v75];
    v79 = v11 - v75;
    do
    {
      v80 = *(float *)((char *)v78++ + (char *)ch2 - (char *)c2);
      --v79;
      *(v78 - 1) = v80;
    }
    while ( v79 );
  }
  v81 = v11 * ip;
  if ( ipph > 1 )
  {
    v82 = v81 - ido;
    v83 = -ido;
    isg = ipph - 1;
    v84 = l1;
    while ( 1 )
    {
      v85 = t0 + v83;
      v86 = v82 - t0;
      v358 = v85;
      ar1h = v86;
      argg = 0;
      if ( v84 >= 4 )
      {
        argg = 4 * (((unsigned int)(v84 - 4) >> 2) + 1);
        v87 = ((unsigned int)(v84 - 4) >> 2) + 1;
        do
        {
          v88 = ido + v85;
          v89 = ido + v86;
          c1[v88] = ch[v88] + ch[v89];
          v90 = ch[v89] - ch[v88];
          v91 = ido + v88;
          c1[v89] = v90;
          v92 = ido + v89;
          c1[v91] = ch[v91] + ch[v92];
          v93 = ch[v92] - ch[v91];
          v94 = ido + v91;
          c1[v92] = v93;
          v95 = ido + v92;
          c1[v94] = ch[v94] + ch[v95];
          v96 = ch[v95] - ch[v94];
          v85 = ido + v94;
          c1[v95] = v96;
          v86 = ido + v95;
          --v87;
          c1[v85] = ch[v85] + ch[v86];
          c1[v86] = ch[v86] - ch[v85];
        }
        while ( v87 );
        v84 = l1;
      }
      if ( argg < v84 )
      {
        t4b = (char *)c1 - (char *)ch;
        v97 = &ch[v85];
        v98 = &ch[v86];
        argh = l1 - argg;
        do
        {
          v99 = v98[ido];
          v98 += ido;
          v100 = v99 + v97[ido];
          v97 += ido;
          v17 = argh-- == 1;
          *(float *)((char *)v97 + t4b) = v100;
          *(float *)((char *)v98 + t4b) = *v98 - *v97;
        }
        while ( !v17 );
        v84 = l1;
      }
      if ( !--isg )
        break;
      v83 = v358;
      v82 = ar1h;
    }
    v81 = v11 * ip;
  }
  ar1 = 1.0;
  t1c = 0;
  v101 = v81;
  ish = v11 * (ip - 1);
  if ( ipph > 1 )
  {
    v102 = dcp;
    v103 = dsp;
    v104 = (float)0.0;
    v308 = ch2 + 2;
    v303 = &ch2[v81 + 2];
    v359 = ipph - 1;
    while ( 1 )
    {
      v308 += v11;
      v303 -= v11;
      v105 = v11 + t1c;
      t2b = v101 - v11;
      v106 = v101 - v11;
      v107 = 0;
      ar1ha = ar1 * v102 - v104 * v103;
      t1c += v11;
      ig = ish;
      t7a = v11;
      argt = v104 * v102 + ar1 * v103;
      v108 = ar1ha;
      ar1 = ar1ha;
      v109 = argt;
      if ( v11 >= 4 )
      {
        v298 = v303;
        v284 = c2 + 2;
        v110 = ((unsigned int)(v11 - 4) >> 2) + 1;
        v280 = &c2[v11 + 2];
        v107 = 4 * v110;
        t4c = 4 * v110 + v105;
        t5d = 4 * v110 + t2b;
        ig = 4 * v110 + ish;
        argi = &c2[ish + 2];
        v111 = v308;
        t7a = 4 * v110 + v11;
        do
        {
          v111 += 4;
          *(v111 - 6) = *(v280 - 2) * v108 + *(v284 - 2);
          *(v298 - 2) = *(argi - 2) * v109;
          *(v111 - 5) = *(v280 - 1) * v108 + *(v284 - 1);
          *(v298 - 1) = *(argi - 1) * v109;
          *(v111 - 4) = v108 * *v280 + *v284;
          *v298 = *argi * v109;
          v112 = v280[1];
          v113 = v284;
          v280 += 4;
          v284 += 4;
          v114 = v112 * v108 + v113[1];
          v115 = argi;
          argi += 4;
          *(v111 - 3) = v114;
          --v110;
          v298 += 4;
          *(v298 - 3) = v115[1] * v109;
        }
        while ( v110 );
        v106 = t5d;
        v105 = t4c;
      }
      if ( v107 < v11 )
      {
        v116 = c2;
        v299 = &ch2[v106];
        argj = &c2[ig];
        v117 = &ch2[v105];
        v118 = &c2[t7a];
        while ( 1 )
        {
          ++v107;
          v119 = *v118 * v108;
          ++v117;
          ++v118;
          v120 = v119 + v116[v107 - 1];
          v121 = argj++;
          *(v117 - 1) = v120;
          *v299++ = *v121 * v109;
          if ( v107 >= v11 )
            break;
          v116 = c2;
        }
      }
      v122 = ish;
      dcpa = ar1ha;
      v123 = v11;
      if ( ipph <= 2 )
      {
        v104 = v109;
      }
      else
      {
        v124 = v109;
        argu = v109;
        v125 = argu;
        v281 = &c2[v11 + 2];
        v300 = &c2[ish + 2];
        ar1hb = ipph - 2;
        while ( 1 )
        {
          v126 = t2b;
          v281 += v11;
          v300 -= v11;
          v127 = t1c;
          t5e = v122 - v11;
          t9 = v122 - v11;
          v128 = 0;
          t8c = dcpa * v108 - v125 * v124;
          t4d = v11 + v123;
          argv = v125 * v108 + dcpa * v124;
          v129 = t8c;
          t8a = v11 + v123;
          dcpa = v129;
          v130 = argv;
          if ( v11 >= 4 )
          {
            v131 = v303;
            v132 = v308;
            v285 = v300;
            v133 = ((unsigned int)(v11 - 4) >> 2) + 1;
            argk = v281;
            v128 = 4 * v133;
            ih = 4 * v133 + t1c;
            t7b = 4 * v133 + t2b;
            t8a = 4 * v133 + t4d;
            t9 = 4 * v133 + t5e;
            do
            {
              v132 += 4;
              v131 += 4;
              *(v132 - 6) = *(argk - 2) * v129 + *(v132 - 6);
              *(v131 - 6) = *(v285 - 2) * v130 + *(v131 - 6);
              *(v132 - 5) = *(argk - 1) * v129 + *(v132 - 5);
              *(v131 - 5) = *(v285 - 1) * v130 + *(v131 - 5);
              *(v132 - 4) = v129 * *argk + *(v132 - 4);
              v134 = argk;
              argk += 4;
              *(v131 - 4) = v130 * *v285 + *(v131 - 4);
              v135 = v134[1];
              v136 = v285;
              v285 += 4;
              --v133;
              *(v132 - 3) = v135 * v129 + *(v132 - 3);
              *(v131 - 3) = v136[1] * v130 + *(v131 - 3);
            }
            while ( v133 );
            v126 = t7b;
            v127 = ih;
            v11 = idl1;
          }
          if ( v128 < v11 )
          {
            v286 = &ch2[v126];
            ii = &c2[t9];
            v137 = &ch2[v127];
            argl = &c2[t8a];
            v138 = v11 - v128;
            v139 = v286;
            do
            {
              v140 = *argl;
              v141 = ii;
              ++argl;
              ++ii;
              ++v137;
              ++v139;
              --v138;
              *(v137 - 1) = v140 * v129 + *(v137 - 1);
              *(v139 - 1) = *v141 * v130 + *(v139 - 1);
            }
            while ( v138 );
          }
          v17 = ar1hb-- == 1;
          v125 = v130;
          if ( v17 )
            break;
          v122 = t5e;
          v123 = t4d;
        }
        v104 = v124;
        v103 = dsp;
      }
      if ( !--v359 )
        break;
      v101 = t2b;
    }
  }
  v142 = 0;
  if ( ipph > 1 )
  {
    v143 = ch2;
    t3 = c2 + 2;
    argm = ipph - 1;
    do
    {
      t3 += v11;
      v142 += v11;
      v144 = 0;
      t1d = v142;
      v145 = v142;
      if ( v11 >= 4 )
      {
        v144 = 4 * (((unsigned int)(v11 - 4) >> 2) + 1);
        v146 = v143 + 2;
        v147 = t3;
        t2c = v144 + v142;
        v148 = ((unsigned int)(v11 - 4) >> 2) + 1;
        do
        {
          v149 = *(v147 - 2);
          v147 += 4;
          v150 = v149 + *(v146 - 2);
          v146 += 4;
          --v148;
          *(v146 - 6) = v150;
          *(v146 - 5) = *(v147 - 5) + *(v146 - 5);
          *(v146 - 4) = *(v146 - 4) + *(v147 - 4);
          *(v146 - 3) = *(v147 - 3) + *(v146 - 3);
        }
        while ( v148 );
        v145 = t2c;
        v142 = t1d;
        v143 = ch2;
      }
      if ( v144 < v11 )
      {
        v151 = &c2[v145];
        do
        {
          v152 = v143[v144++];
          v153 = v152 + *v151++;
          v143[v144 - 1] = v153;
        }
        while ( v144 < v11 );
        v142 = t1d;
      }
      --argm;
    }
    while ( argm );
  }
  v154 = l1;
  v155 = 0;
  if ( ido >= l1 )
  {
    t1e = 0;
    t2d = 0;
    if ( l1 > 0 )
    {
      argo = ch + 2;
      isi = cc + 2;
      v360 = l1;
      do
      {
        v170 = t1e;
        v171 = t2d;
        v172 = 0;
        if ( ido >= 4 )
        {
          v173 = isi;
          v174 = argo;
          v175 = ((unsigned int)(ido - 4) >> 2) + 1;
          t3b = 4 * v175 + t1e;
          ik = 4 * v175;
          v171 = t2d + 4 * v175;
          do
          {
            v176 = *(v174 - 2);
            v174 += 4;
            *(v173 - 2) = v176;
            v173 += 4;
            --v175;
            *(v173 - 5) = *(v174 - 5);
            *(v173 - 4) = *(v174 - 4);
            *(v173 - 3) = *(v174 - 3);
          }
          while ( v175 );
          v172 = ik;
          v170 = t3b;
        }
        if ( v172 < ido )
        {
          v177 = &cc[v171];
          v178 = &ch[v170];
          v179 = ido - v172;
          do
          {
            v180 = *v178++;
            *v177++ = v180;
            --v179;
          }
          while ( v179 );
        }
        t1e += ido;
        argo += ido;
        t2d += t10;
        isi += t10;
        --v360;
      }
      while ( v360 );
    }
  }
  else
  {
    for ( ij = 0; ij < ido; ++ij )
    {
      v156 = v155;
      argn = 0;
      if ( v154 >= 4 )
      {
        argn = 4 * (((unsigned int)(v154 - 4) >> 2) + 1);
        v157 = ((unsigned int)(v154 - 4) >> 2) + 1;
        do
        {
          v158 = ch[v155];
          v159 = ido + v155;
          cc[v156] = v158;
          v160 = t10 + v156;
          v161 = ch[v159];
          v162 = ido + v159;
          cc[v160] = v161;
          v163 = t10 + v160;
          v164 = ch[v162];
          v165 = ido + v162;
          cc[v163] = v164;
          v166 = t10 + v163;
          v167 = ch[v165];
          v155 = ido + v165;
          cc[v166] = v167;
          v156 = t10 + v166;
          --v157;
        }
        while ( v157 );
        v154 = l1;
      }
      if ( argn < v154 )
      {
        t3a = &cc[v156];
        v168 = &ch[v155];
        v169 = l1 - argn;
        while ( 1 )
        {
          *t3a = *v168;
          t3a += t10;
          if ( !--v169 )
            break;
          v168 += ido;
        }
        v154 = l1;
      }
      v155 = ij + 1;
    }
  }
  v181 = ip * t0;
  v182 = 0;
  v183 = 0;
  dspa = ip * t0;
  v184 = ip * t0;
  if ( ipph > 1 )
  {
    v361 = ipph - 1;
    while ( 1 )
    {
      t1f = 2 * ido + v182;
      v185 = t1f;
      t3c = t0 + v183;
      v186 = t0 + v183;
      t4e = v184 - t0;
      v187 = v184 - t0;
      v188 = l1;
      argp = 0;
      if ( l1 >= 4 )
      {
        v388 = ((unsigned int)(l1 - 4) >> 2) + 1;
        argp = 4 * v388;
        do
        {
          cc[v185 - 1] = ch[v186];
          v189 = ido + v186;
          v190 = ch[v187];
          v191 = ido + v187;
          cc[v185] = v190;
          v192 = t10 + v185;
          v193 = ch[v189];
          v194 = ido + v189;
          cc[v192 - 1] = v193;
          v195 = ch[v191];
          v196 = ido + v191;
          cc[v192] = v195;
          v197 = t10 + v192;
          v198 = ch[v194];
          v199 = ido + v194;
          cc[v197 - 1] = v198;
          v200 = ch[v196];
          v201 = ido + v196;
          cc[v197] = v200;
          v202 = t10 + v197;
          v203 = ch[v199];
          v186 = ido + v199;
          cc[v202 - 1] = v203;
          v204 = ch[v201];
          v187 = ido + v201;
          cc[v202] = v204;
          v185 = t10 + v202;
          --v388;
        }
        while ( v388 );
        v188 = l1;
      }
      if ( argp < v188 )
      {
        v389 = &ch[v187];
        v205 = &ch[v186];
        v206 = l1 - argp;
        v207 = &cc[v185];
        while ( 1 )
        {
          *(v207 - 1) = *v205;
          *v207 = *v389;
          v207 += t10;
          v389 += ido;
          if ( !--v206 )
            break;
          v205 += ido;
        }
      }
      if ( !--v361 )
        break;
      v183 = t3c;
      v184 = t4e;
      v182 = t1f;
    }
    v181 = dspa;
  }
  if ( ido != 1 )
  {
    if ( nbd >= l1 )
    {
      if ( ipph > 1 )
      {
        nbdb = &ch[v181 + 2];
        t3e = cc - 2;
        v244 = 4 * t0;
        v245 = 8 * ido;
        argr = cc + 2;
        v391 = ch + 2;
        dspc = ipph - 1;
        while ( 1 )
        {
          t3e = (float *)((char *)t3e + v245);
          argr = (float *)((char *)argr + v245);
          v391 = (float *)((char *)v391 + v244);
          nbdb = (float *)((char *)nbdb - v244);
          if ( l1 > 0 )
          {
            v246 = argr;
            il = (int)v391;
            isj = (int)t3e;
            v309 = nbdb;
            v364 = l1;
            do
            {
              if ( ido > 2 )
              {
                v247 = il;
                v248 = v309;
                v249 = isj;
                v250 = v246;
                v251 = ((unsigned int)(ido - 3) >> 1) + 1;
                do
                {
                  v250 += 2;
                  v252 = *(v248 - 1) + *(float *)(v247 - 4);
                  v248 += 2;
                  v247 += 8;
                  v249 -= 8;
                  --v251;
                  *(v250 - 3) = v252;
                  *(float *)(v249 + 4) = *(float *)(v247 - 12) - *(v248 - 3);
                  *(v250 - 2) = *(v248 - 2) + *(float *)(v247 - 8);
                  *(float *)(v249 + 8) = *(v248 - 2) - *(float *)(v247 - 8);
                }
                while ( v251 );
              }
              isj += 4 * t10;
              v246 += t10;
              il += 4 * ido;
              v309 += ido;
              --v364;
            }
            while ( v364 );
          }
          if ( !--dspc )
            break;
          v245 = 8 * ido;
          v244 = 4 * t0;
        }
      }
    }
    else
    {
      v208 = v181;
      v209 = 0;
      v210 = 0;
      if ( ipph > 1 )
      {
        v211 = -2;
        t9a = ipph - 1;
        do
        {
          v211 += 2 * ido;
          v209 += 2 * ido;
          v210 += t0;
          v208 -= t0;
          nbda = v211;
          t3d = v209;
          t4f = v210;
          t5f = v208;
          if ( ido > 2 )
          {
            v212 = v210 + 2;
            v213 = v209 - v210;
            v214 = v208 - v210;
            ar1hc = v210 + 2;
            v390 = v211;
            ar1a = v213;
            dcpb = v214;
            t8b = ((unsigned int)(ido - 3) >> 1) + 1;
            while ( 1 )
            {
              v215 = l1;
              v216 = v390;
              v217 = v212 + v213;
              v218 = v212 + v214;
              t7c = v217;
              argq = 0;
              if ( l1 >= 4 )
              {
                v362 = ((unsigned int)(l1 - 4) >> 2) + 1;
                argq = 4 * v362;
                do
                {
                  cc[v217 - 1] = ch[v218 - 1] + ch[v212 - 1];
                  cc[v216 - 1] = ch[v212 - 1] - ch[v218 - 1];
                  cc[v217] = ch[v218] + ch[v212];
                  v219 = ch[v218];
                  v220 = ido + v218;
                  v221 = v219 - ch[v212];
                  v222 = ido + v212;
                  cc[v216] = v221;
                  v223 = t10 + v216;
                  v224 = t10 + v217;
                  cc[v224 - 1] = ch[v220 - 1] + ch[v222 - 1];
                  cc[v223 - 1] = ch[v222 - 1] - ch[v220 - 1];
                  cc[v224] = ch[v220] + ch[v222];
                  v225 = ch[v220];
                  v226 = ido + v220;
                  v227 = v225 - ch[v222];
                  v228 = ido + v222;
                  cc[v223] = v227;
                  v229 = t10 + v223;
                  v230 = t10 + v224;
                  cc[v230 - 1] = ch[v226 - 1] + ch[v228 - 1];
                  cc[v229 - 1] = ch[v228 - 1] - ch[v226 - 1];
                  cc[v230] = ch[v226] + ch[v228];
                  v231 = ch[v226];
                  v232 = ido + v226;
                  v233 = v231 - ch[v228];
                  v234 = ido + v228;
                  cc[v229] = v233;
                  v235 = t10 + v229;
                  v236 = t10 + v230;
                  cc[v236 - 1] = ch[v232 - 1] + ch[v234 - 1];
                  cc[v235 - 1] = ch[v234 - 1] - ch[v232 - 1];
                  cc[v236] = ch[v232] + ch[v234];
                  v237 = ch[v232];
                  v218 = ido + v232;
                  v238 = v237 - ch[v234];
                  v212 = ido + v234;
                  cc[v235] = v238;
                  v216 = t10 + v235;
                  v217 = t10 + v236;
                  --v362;
                }
                while ( v362 );
                v215 = l1;
                t7c = v217;
              }
              if ( argq < v215 )
              {
                v363 = 4 * t10;
                v239 = &cc[t7c];
                v240 = &cc[v216];
                v241 = l1 - argq;
                v242 = &ch[v212];
                v243 = &ch[v218];
                dspb = v239;
                while ( 1 )
                {
                  *(v239 - 1) = *(v242 - 1) + *(v243 - 1);
                  *(v240 - 1) = *(v242 - 1) - *(v243 - 1);
                  *v239 = *v242 + *v243;
                  v239 = &dspb[v363 / 4u];
                  dspb = (float *)((char *)dspb + v363);
                  *v240 = *v243 - *v242;
                  v242 += ido;
                  v243 += ido;
                  if ( !--v241 )
                    break;
                  v240 = (float *)((char *)v240 + v363);
                }
              }
              v390 -= 2;
              v212 = ar1hc + 2;
              v17 = t8b-- == 1;
              ar1hc += 2;
              if ( v17 )
                break;
              v214 = dcpb;
              v213 = ar1a;
            }
            v211 = nbda;
            v208 = t5f;
            v210 = t4f;
            v209 = t3d;
          }
          --t9a;
        }
        while ( t9a );
      }
    }
  }
}
