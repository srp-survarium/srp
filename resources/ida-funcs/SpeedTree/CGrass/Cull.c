void __thiscall SpeedTree::CGrass::Cull(
        SpeedTree::CGrass *this,
        SpeedTree::Vec3 *a2,
        struct SpeedTree::SGrassCullResults *a3)
{
  SpeedTree::Vec3 *v3; // ecx
  float *v4; // eax
  SpeedTree::Vec3 *v5; // eax
  double v6; // st7
  struct SpeedTree::Vec3 *v7; // eax
  struct SpeedTree::Vec3 *v8; // eax
  float *v9; // eax
  struct SpeedTree::Vec3 *v10; // eax
  float *v11; // eax
  float *v12; // eax
  float *v13; // eax
  struct SpeedTree::Vec3 *v14; // eax
  struct SpeedTree::Vec3 *v15; // eax
  float *v16; // eax
  struct SpeedTree::Vec3 *v17; // eax
  float *v18; // eax
  float *v19; // eax
  float *v20; // eax
  float v21; // [esp+0h] [ebp-5A4h]
  float v22; // [esp+0h] [ebp-5A4h]
  float v23; // [esp+8h] [ebp-59Ch]
  float v24; // [esp+8h] [ebp-59Ch]
  float v25; // [esp+8h] [ebp-59Ch]
  float v26; // [esp+8h] [ebp-59Ch]
  float v27; // [esp+10h] [ebp-594h]
  struct SpeedTree::Vec3 *v28; // [esp+10h] [ebp-594h]
  float v29; // [esp+10h] [ebp-594h]
  struct SpeedTree::Vec3 *v30; // [esp+10h] [ebp-594h]
  float v31; // [esp+18h] [ebp-58Ch]
  float *v32; // [esp+18h] [ebp-58Ch]
  float v33; // [esp+18h] [ebp-58Ch]
  float *v34; // [esp+18h] [ebp-58Ch]
  int *v35; // [esp+1Ch] [ebp-588h]
  int *v36; // [esp+1Ch] [ebp-588h]
  int v37; // [esp+2Ch] [ebp-578h]
  float v38; // [esp+38h] [ebp-56Ch]
  float v39; // [esp+3Ch] [ebp-568h]
  float v40; // [esp+44h] [ebp-560h]
  float v41; // [esp+48h] [ebp-55Ch]
  const struct SpeedTree::Vec3 *v43; // [esp+64h] [ebp-540h]
  float v44; // [esp+68h] [ebp-53Ch]
  float v45; // [esp+6Ch] [ebp-538h]
  float v46; // [esp+70h] [ebp-534h]
  _BYTE v47[12]; // [esp+74h] [ebp-530h]
  const struct SpeedTree::Vec3 *v48; // [esp+80h] [ebp-524h]
  float v49; // [esp+84h] [ebp-520h]
  float v50; // [esp+88h] [ebp-51Ch]
  float v51; // [esp+8Ch] [ebp-518h]
  const struct SpeedTree::Vec3 *v52; // [esp+90h] [ebp-514h]
  float v53; // [esp+94h] [ebp-510h]
  float v54; // [esp+98h] [ebp-50Ch]
  float v55; // [esp+9Ch] [ebp-508h]
  SpeedTree::Vec3 v56; // [esp+A4h] [ebp-500h] BYREF
  float v57[6]; // [esp+C4h] [ebp-4E0h] BYREF
  float v58; // [esp+DCh] [ebp-4C8h]
  float v59; // [esp+E0h] [ebp-4C4h]
  float v60; // [esp+E4h] [ebp-4C0h]
  float v61; // [esp+E8h] [ebp-4BCh]
  float v62; // [esp+ECh] [ebp-4B8h]
  float v63; // [esp+F0h] [ebp-4B4h]
  float v64; // [esp+F4h] [ebp-4B0h]
  const struct SpeedTree::Vec3 *v65; // [esp+F8h] [ebp-4ACh]
  float v66; // [esp+FCh] [ebp-4A8h]
  float v67; // [esp+100h] [ebp-4A4h]
  float v68; // [esp+104h] [ebp-4A0h]
  float v69; // [esp+108h] [ebp-49Ch]
  float v70; // [esp+10Ch] [ebp-498h]
  float v71; // [esp+110h] [ebp-494h]
  float v72; // [esp+114h] [ebp-490h]
  const struct SpeedTree::Vec3 *v73; // [esp+118h] [ebp-48Ch]
  float v74; // [esp+11Ch] [ebp-488h]
  float v75; // [esp+120h] [ebp-484h]
  float v76; // [esp+124h] [ebp-480h]
  float m_fGlobalHighPoint; // [esp+128h] [ebp-47Ch]
  const struct SpeedTree::Vec3 *v78; // [esp+12Ch] [ebp-478h]
  float v79; // [esp+130h] [ebp-474h]
  float v80; // [esp+134h] [ebp-470h]
  float v81; // [esp+138h] [ebp-46Ch]
  float v82; // [esp+148h] [ebp-45Ch]
  float v83; // [esp+14Ch] [ebp-458h]
  float v84; // [esp+150h] [ebp-454h]
  float v85; // [esp+154h] [ebp-450h]
  float v86; // [esp+158h] [ebp-44Ch]
  float v87; // [esp+15Ch] [ebp-448h]
  float v88; // [esp+160h] [ebp-444h]
  const struct SpeedTree::Vec3 *v89; // [esp+164h] [ebp-440h]
  float v90; // [esp+168h] [ebp-43Ch]
  float v91; // [esp+16Ch] [ebp-438h]
  float v92; // [esp+170h] [ebp-434h]
  float v93; // [esp+174h] [ebp-430h]
  float v94; // [esp+178h] [ebp-42Ch]
  float v95; // [esp+17Ch] [ebp-428h]
  float v96; // [esp+180h] [ebp-424h]
  const struct SpeedTree::Vec3 *v97; // [esp+184h] [ebp-420h]
  float v98; // [esp+188h] [ebp-41Ch]
  float v99; // [esp+18Ch] [ebp-418h]
  float v100; // [esp+190h] [ebp-414h]
  float m_fGlobalLowPoint; // [esp+194h] [ebp-410h]
  const struct SpeedTree::Vec3 *v102; // [esp+198h] [ebp-40Ch]
  float v103; // [esp+19Ch] [ebp-408h]
  float v104; // [esp+1A0h] [ebp-404h]
  float v105; // [esp+1A4h] [ebp-400h]
  int v106; // [esp+1A8h] [ebp-3FCh]
  float v107; // [esp+1ACh] [ebp-3F8h]
  float v108; // [esp+1BCh] [ebp-3E8h]
  float m_fCellSize; // [esp+1CCh] [ebp-3D8h]
  int m; // [esp+1D0h] [ebp-3D4h]
  SpeedTree::Vec3 *v111; // [esp+1D8h] [ebp-3CCh]
  float v112; // [esp+1DCh] [ebp-3C8h]
  float v113; // [esp+1E0h] [ebp-3C4h]
  float v114; // [esp+1E4h] [ebp-3C0h]
  float v115; // [esp+1E8h] [ebp-3BCh]
  float v116; // [esp+1ECh] [ebp-3B8h]
  float v117; // [esp+1F0h] [ebp-3B4h]
  float v118; // [esp+20Ch] [ebp-398h]
  int v119; // [esp+224h] [ebp-380h]
  SpeedTree::Vec3 *j; // [esp+228h] [ebp-37Ch]
  float y; // [esp+22Ch] [ebp-378h]
  int v122; // [esp+230h] [ebp-374h]
  struct SpeedTree::Vec4 *i; // [esp+234h] [ebp-370h]
  char v124; // [esp+23Bh] [ebp-369h] BYREF
  struct SpeedTree::CExtents v125; // [esp+23Ch] [ebp-368h] BYREF
  float v126[3]; // [esp+254h] [ebp-350h] BYREF
  float v127[3]; // [esp+260h] [ebp-344h] BYREF
  float v128[3]; // [esp+26Ch] [ebp-338h] BYREF
  float v129[3]; // [esp+278h] [ebp-32Ch] BYREF
  float v130[3]; // [esp+284h] [ebp-320h] BYREF
  float v131[3]; // [esp+290h] [ebp-314h] BYREF
  float v132[3]; // [esp+29Ch] [ebp-308h] BYREF
  float v133[3]; // [esp+2A8h] [ebp-2FCh] BYREF
  float v134[3]; // [esp+2B4h] [ebp-2F0h] BYREF
  float v135[3]; // [esp+2C0h] [ebp-2E4h] BYREF
  float v136[3]; // [esp+2CCh] [ebp-2D8h] BYREF
  int v137[5]; // [esp+2D8h] [ebp-2CCh] BYREF
  struct SpeedTree::Vec3 v138; // [esp+2ECh] [ebp-2B8h]
  float v139; // [esp+2F8h] [ebp-2ACh]
  float v140; // [esp+2FCh] [ebp-2A8h]
  float v141; // [esp+300h] [ebp-2A4h]
  float v142; // [esp+304h] [ebp-2A0h]
  float v143; // [esp+308h] [ebp-29Ch]
  float v144; // [esp+30Ch] [ebp-298h]
  float v145; // [esp+310h] [ebp-294h]
  float v146; // [esp+314h] [ebp-290h]
  float v147; // [esp+318h] [ebp-28Ch]
  struct SpeedTree::Vec3 v148; // [esp+31Ch] [ebp-288h]
  float v149; // [esp+328h] [ebp-27Ch]
  float v150; // [esp+32Ch] [ebp-278h]
  float v151; // [esp+330h] [ebp-274h]
  float v152[3]; // [esp+334h] [ebp-270h] BYREF
  float v153[15]; // [esp+340h] [ebp-264h] BYREF
  float v154[3]; // [esp+37Ch] [ebp-228h] BYREF
  float v155[16]; // [esp+388h] [ebp-21Ch] BYREF
  float v156; // [esp+3C8h] [ebp-1DCh]
  float v157; // [esp+3CCh] [ebp-1D8h]
  float v158; // [esp+3D0h] [ebp-1D4h]
  float v159; // [esp+3D4h] [ebp-1D0h]
  float v160; // [esp+3D8h] [ebp-1CCh]
  struct SpeedTree::CExtents v161; // [esp+3DCh] [ebp-1C8h] BYREF
  int v162; // [esp+3F4h] [ebp-1B0h]
  int v163; // [esp+3F8h] [ebp-1ACh]
  SpeedTree::CGrassCell *v164; // [esp+3FCh] [ebp-1A8h] BYREF
  int v165; // [esp+400h] [ebp-1A4h] BYREF
  int v166; // [esp+404h] [ebp-1A0h]
  int CellPtrByRowCol_Add; // [esp+408h] [ebp-19Ch]
  int ii; // [esp+40Ch] [ebp-198h]
  int n; // [esp+410h] [ebp-194h]
  SpeedTree::Vec3 result; // [esp+414h] [ebp-190h] BYREF
  int k; // [esp+420h] [ebp-184h]
  float v172; // [esp+424h] [ebp-180h]
  float v173; // [esp+428h] [ebp-17Ch]
  float v174; // [esp+42Ch] [ebp-178h]
  SpeedTree::Vec3 v175[8]; // [esp+430h] [ebp-174h] BYREF
  int v176; // [esp+490h] [ebp-114h] BYREF
  float v177; // [esp+494h] [ebp-110h] BYREF
  int v178; // [esp+498h] [ebp-10Ch] BYREF
  float v179; // [esp+49Ch] [ebp-108h]
  float v180[3]; // [esp+4A0h] [ebp-104h] BYREF
  struct SpeedTree::Vec3 v181; // [esp+4ACh] [ebp-F8h] BYREF
  float v182; // [esp+4B8h] [ebp-ECh]
  signed int v183; // [esp+4BCh] [ebp-E8h]
  float v184[3]; // [esp+4C0h] [ebp-E4h] BYREF
  float v185[3]; // [esp+4CCh] [ebp-D8h] BYREF
  struct SpeedTree::Vec3 v186; // [esp+4D8h] [ebp-CCh] BYREF
  struct SpeedTree::Vec3 v187; // [esp+4E4h] [ebp-C0h] BYREF
  struct SpeedTree::Vec4 dst[6]; // [esp+4F0h] [ebp-B4h] BYREF
  unsigned __int8 *src; // [esp+550h] [ebp-54h]
  SpeedTree::CExtents v190; // [esp+554h] [ebp-50h] BYREF
  int v191; // [esp+56Ch] [ebp-38h]
  float v192; // [esp+570h] [ebp-34h] BYREF
  float v193[3]; // [esp+574h] [ebp-30h] BYREF
  struct SpeedTree::CExtents v194; // [esp+580h] [ebp-24h] BYREF
  int v195; // [esp+5A0h] [ebp-4h]

  v122 = 6;
  for ( i = dst; --v122 >= 0; ++i )
  {
    i->x = 0.0;
    i->y = 0.0;
    i->z = 0.0;
    i->w = 1.0;
  }
  memcpy((unsigned __int8 *)dst, (unsigned __int8 *)&a2[39].y, sizeof(dst));
  src = (unsigned __int8 *)&a2[31].y;
  y = a2[13].y;
  dst[1].w = dst[1].w - (y - this->m_fEndFade);
  v119 = 8;
  for ( j = v175; --v119 >= 0; ++j )
  {
    j->x = 0.0;
    j->y = 0.0;
    j->z = 0.0;
  }
  memcpy((unsigned __int8 *)v175, src, sizeof(v175));
  v173 = SpeedTree::Vec3::Distance(v175, &v175[4]);
  v118 = a2[13].y;
  v174 = this->m_fEndFade / v118;
  v172 = v174 * v173;
  for ( k = 0; k < 4; ++k )
  {
    SpeedTree::Vec3::operator-(&v175[k + 4], &result, &v175[k]);
    SpeedTree::Vec3::Normalize(&result);
    v115 = v172 * result.x;
    v116 = v172 * result.y;
    v117 = v172 * result.z;
    v158 = v115;
    v159 = v116;
    v160 = v117;
    v111 = &v175[k];
    v112 = v115 + v111->x;
    v113 = v116 + v111->y;
    v114 = v117 + v111->z;
    v155[15] = v112;
    v156 = v113;
    v157 = v114;
    v3 = &v175[k + 4];
    v3->x = v112;
    v3->y = v156;
    v3->z = v157;
  }
  SpeedTree::CExtents::CExtents(&v190);
  v195 = 0;
  SpeedTree::CExtents::Reset(&v190);
  for ( m = 0; m < 8; ++m )
    SpeedTree::CExtents::ExpandAround(&v190, &v175[m]);
  v192 = 0.0;
  v176 = 0;
  v177 = 0.0;
  v178 = 0;
  m_fCellSize = this->m_cGrassCellMap.m_fCellSize;
  SpeedTree::ComputeCellCoords(
    (SpeedTree *)&v190,
    (const struct SpeedTree::Vec3 *)LODWORD(m_fCellSize),
    COERCE_FLOAT(&v192),
    &v176,
    v35);
  v108 = this->m_cGrassCellMap.m_fCellSize;
  SpeedTree::ComputeCellCoords(
    (SpeedTree *)&v190.m_cMax,
    (const struct SpeedTree::Vec3 *)LODWORD(v108),
    COERCE_FLOAT(&v177),
    &v178,
    v36);
  if ( SLODWORD(v177) < SLODWORD(v192) )
  {
    v107 = v192;
    v192 = v177;
    v177 = v107;
  }
  if ( v178 < v176 )
  {
    v106 = v176;
    v176 = v178;
    v178 = v106;
  }
  v191 = v178 - v176 + 1;
  v182 = this->m_cGrassCellMap.m_fCellSize;
  v179 = (double)v191 * v182;
  m_fGlobalLowPoint = this->m_fGlobalLowPoint;
  v102 = SpeedTree::CCoordSys::UpAxis();
  v103 = m_fGlobalLowPoint * v102->x;
  v104 = m_fGlobalLowPoint * v102->y;
  v105 = m_fGlobalLowPoint * v102->z;
  v154[0] = v103;
  v154[1] = v104;
  v154[2] = v105;
  v96 = (float)SLODWORD(v192);
  v97 = SpeedTree::CCoordSys::OutAxis();
  v98 = v96 * v97->x;
  v99 = v96 * v97->y;
  v100 = v96 * v97->z;
  v155[6] = v98;
  v155[7] = v99;
  v155[8] = v100;
  v93 = v182 * v98;
  v94 = v182 * v99;
  v95 = v182 * v100;
  v155[3] = v93;
  v155[4] = v94;
  v155[5] = v95;
  v88 = (float)v176;
  v89 = SpeedTree::CCoordSys::RightAxis();
  v90 = v88 * v89->x;
  v91 = v88 * v89->y;
  v92 = v88 * v89->z;
  v155[12] = v90;
  v155[13] = v91;
  v155[14] = v92;
  v85 = v182 * v90;
  v86 = v182 * v91;
  v87 = v182 * v92;
  v155[9] = v85;
  v155[10] = v86;
  v155[11] = v87;
  v82 = v93 + v85;
  v83 = v94 + v86;
  v84 = v95 + v87;
  v155[0] = v82;
  v155[1] = v83;
  v155[2] = v84;
  SpeedTree::Vec3::operator+(v155, v180, v154);
  m_fGlobalHighPoint = this->m_fGlobalHighPoint;
  v78 = SpeedTree::CCoordSys::UpAxis();
  v79 = m_fGlobalHighPoint * v78->x;
  v80 = m_fGlobalHighPoint * v78->y;
  v81 = m_fGlobalHighPoint * v78->z;
  v152[0] = v79;
  v152[1] = v80;
  v152[2] = v81;
  v72 = (float)(LODWORD(v192) + 1);
  v73 = SpeedTree::CCoordSys::OutAxis();
  v74 = v72 * v73->x;
  v75 = v72 * v73->y;
  v76 = v72 * v73->z;
  v153[6] = v74;
  v153[7] = v75;
  v153[8] = v76;
  v69 = v182 * v74;
  v70 = v182 * v75;
  v71 = v182 * v76;
  v153[3] = v69;
  v153[4] = v70;
  v153[5] = v71;
  v64 = (float)(v176 + 1);
  v65 = SpeedTree::CCoordSys::RightAxis();
  v66 = v64 * v65->x;
  v67 = v64 * v65->y;
  v68 = v64 * v65->z;
  v153[12] = v66;
  v153[13] = v67;
  v153[14] = v68;
  v61 = v182 * v66;
  v62 = v182 * v67;
  v63 = v182 * v68;
  v153[9] = v61;
  v153[10] = v62;
  v153[11] = v63;
  v58 = v69 + v61;
  v59 = v70 + v62;
  v60 = v71 + v63;
  v153[0] = v58;
  v153[1] = v59;
  v153[2] = v60;
  SpeedTree::Vec3::operator+(v153, v193, v152);
  v184[0] = v180[0];
  v184[1] = v180[1];
  v184[2] = v180[2];
  v185[0] = v193[0];
  v185[1] = v193[1];
  v185[2] = v193[2];
  LOBYTE(v195) = 1;
  v4 = SpeedTree::Vec3::operator+(v184, v57, v185);
  SpeedTree::Vec3::operator*(v4, &v186.x, 0.5);
  v41 = this->m_fGlobalLowPoint - SpeedTree::CCoordSys::UpComponent(&v186.x);
  v40 = v182 * -0.5;
  SpeedTree::CCoordSys::ConvertFromStd(&v181, v40, v40, v41);
  v39 = this->m_fGlobalHighPoint - SpeedTree::CCoordSys::UpComponent(&v186.x);
  v38 = v182 * 0.5;
  SpeedTree::CCoordSys::ConvertFromStd(&v187, v38, v38, v39);
  v194.m_cMin = v181;
  v194.m_cMax = v187;
  LOBYTE(v195) = 2;
  v183 = 0;
  for ( n = LODWORD(v192); n <= SLODWORD(v177); ++n )
  {
    for ( ii = v176; ii <= v178; ++ii )
    {
      if ( !FrustumCullsAABB(dst, &v186, &v194) )
      {
        ++v183;
        CellPtrByRowCol_Add = SpeedTree::CCellContainer<SpeedTree::CGrassCell>::GetCellPtrByRowCol_Add(n, ii);
        if ( CellPtrByRowCol_Add )
        {
          v5 = SpeedTree::Vec3::operator-(a2, &v56, (const SpeedTree::Vec3 *)(CellPtrByRowCol_Add + 40));
          v6 = vostok::math::float3_pod::squared_length(v5);
          *(float *)(CellPtrByRowCol_Add + 64) = v6;
          *(_DWORD *)(CellPtrByRowCol_Add + 12) = this->m_nUpdateIndex;
        }
      }
      v52 = SpeedTree::CCoordSys::RightAxis();
      v53 = v182 * v52->x;
      v54 = v182 * v52->y;
      v55 = v182 * v52->z;
      v149 = v53;
      v150 = v54;
      v151 = v55;
      v186.x = v186.x + v53;
      v186.y = v186.y + v54;
      v186.z = v186.z + v55;
      v148 = v186;
    }
    v48 = SpeedTree::CCoordSys::RightAxis();
    v49 = v179 * v48->x;
    v50 = v179 * v48->y;
    v51 = v179 * v48->z;
    v145 = v49;
    v146 = v50;
    v147 = v51;
    *(float *)v47 = v186.x - v49;
    *(float *)&v47[4] = v186.y - v50;
    *(float *)&v47[8] = v186.z - v51;
    v142 = *(float *)v47;
    v143 = *(float *)&v47[4];
    v144 = *(float *)&v47[8];
    v186 = *(struct SpeedTree::Vec3 *)v47;
    v43 = SpeedTree::CCoordSys::OutAxis();
    v44 = v182 * v43->x;
    v45 = v182 * v43->y;
    v46 = v182 * v43->z;
    v139 = v44;
    v140 = v45;
    v141 = v46;
    v186.x = v186.x + v44;
    v186.y = v186.y + v45;
    v186.z = v186.z + v46;
    v138 = v186;
  }
  if ( v183 > (signed int)this->m_cGrassCellMap.m_uiSize )
    SpeedTree::CCore::SetError(
      "CGrass::Cull, tried to create [%d] grass cells with limit of [%d]; raise limit via CGrass::SetHint(HINT_MAX_NUM_VISIBLE_CELLS)",
      v183,
      this->m_nHintMaxNumVisibleCells);
  SpeedTree::CGrass::RemoveInactiveCells(&a3->m_aFreedVbos);
  SpeedTree::CArray<SpeedTree::CGrassCell *,1>::resize(0);
  SpeedTree::CArray<SpeedTree::CGrassCell *,1>::resize(0);
  SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CGrassCell,1>::begin(&v165);
  while ( 1 )
  {
    v137[3] = 0;
    v137[4] = 0;
    if ( !v165 )
      break;
    if ( v166 )
      v37 = v165 + *(_DWORD *)(v166 + 4);
    else
      v37 = 0;
    v164 = (SpeedTree::CGrassCell *)(v37 + 8);
    v162 = *(_DWORD *)(v37 + 12);
    v163 = *(_DWORD *)(v37 + 16);
    if ( !SpeedTree::CExtents::Valid((SpeedTree::CExtents *)(v37 + 24)) || !v164->m_pVbo )
    {
      v31 = this->m_fGlobalLowPoint;
      v7 = (struct SpeedTree::Vec3 *)SpeedTree::CCoordSys::UpAxis();
      v32 = SpeedTree::Vec3::operator*(&v7->x, v132, v31);
      v27 = v182;
      v23 = (float)v162;
      v8 = (struct SpeedTree::Vec3 *)SpeedTree::CCoordSys::OutAxis();
      v9 = SpeedTree::Vec3::operator*(&v8->x, v135, v23);
      v28 = (struct SpeedTree::Vec3 *)SpeedTree::Vec3::operator*(v9, v134, v27);
      v24 = v182;
      v21 = (float)v163;
      v10 = (struct SpeedTree::Vec3 *)SpeedTree::CCoordSys::RightAxis();
      v11 = SpeedTree::Vec3::operator*(&v10->x, (float *)v137, v21);
      v12 = SpeedTree::Vec3::operator*(v11, v136, v24);
      v13 = SpeedTree::Vec3::operator+(v12, v133, &v28->x);
      SpeedTree::Vec3::operator+(v13, &v161.m_cMin.x, v32);
      v33 = this->m_fGlobalHighPoint;
      v14 = (struct SpeedTree::Vec3 *)SpeedTree::CCoordSys::UpAxis();
      v34 = SpeedTree::Vec3::operator*(&v14->x, v126, v33);
      v29 = v182;
      v25 = (float)(v162 + 1);
      v15 = (struct SpeedTree::Vec3 *)SpeedTree::CCoordSys::OutAxis();
      v16 = SpeedTree::Vec3::operator*(&v15->x, v129, v25);
      v30 = (struct SpeedTree::Vec3 *)SpeedTree::Vec3::operator*(v16, v128, v29);
      v26 = v182;
      v22 = (float)(v163 + 1);
      v17 = (struct SpeedTree::Vec3 *)SpeedTree::CCoordSys::RightAxis();
      v18 = SpeedTree::Vec3::operator*(&v17->x, v131, v22);
      v19 = SpeedTree::Vec3::operator*(v18, v130, v26);
      v20 = SpeedTree::Vec3::operator+(v19, v127, &v30->x);
      SpeedTree::Vec3::operator+(v20, &v161.m_cMax.x, v34);
      v125 = v161;
      LOBYTE(v195) = 3;
      SpeedTree::CGrassCell::SetExtents(v164, &v125);
      LOBYTE(v195) = 2;
      SpeedTree::CArray<SpeedTree::CGrassCell *,1>::push_back(&v164);
    }
    SpeedTree::CArray<SpeedTree::CGrassCell *,1>::push_back(&v164);
    SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CGrassCell,1>::iterator_base::operator++(&v165);
  }
  v124 = 0;
  SpeedTree::CArray<SpeedTree::CGrassCell *,1>::sort<CGrassCellSorter>(&v124, 0);
  ++this->m_nUpdateIndex;
}
