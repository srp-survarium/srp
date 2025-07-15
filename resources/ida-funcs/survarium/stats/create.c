void __usercall survarium::stats::create(survarium::stats *this@<ecx>, int **a2@<esi>)
{
  int *v2; // eax
  int *v3; // ecx
  int *v4; // ecx
  int *v5; // eax
  int v6; // eax
  void (__thiscall ***v7)(_DWORD, float *); // eax
  int v8; // eax
  int *v9; // ecx
  int v10; // eax
  int v11; // eax
  float v12; // xmm0_4
  int *v13; // ecx
  int v14; // eax
  int *v15; // eax
  int v16; // eax
  void (__thiscall ***v17)(_DWORD, float *); // eax
  int v18; // eax
  int *v19; // ecx
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int *v23; // eax
  int v24; // eax
  void (__thiscall ***v25)(_DWORD, float *); // eax
  int v26; // eax
  int *v27; // ecx
  int v28; // eax
  int v29; // eax
  int v30; // eax
  int *v31; // ecx
  float v32; // xmm0_4
  int v33; // eax
  int *v34; // eax
  int v35; // eax
  void (__thiscall ***v36)(_DWORD, float *); // eax
  int v37; // eax
  int *v38; // ecx
  int v39; // eax
  int v40; // eax
  int v41; // eax
  int *v42; // ecx
  float v43; // xmm0_4
  int v44; // eax
  int *v45; // eax
  int v46; // eax
  void (__thiscall ***v47)(_DWORD, float *); // eax
  int v48; // eax
  int *v49; // ecx
  int v50; // eax
  int v51; // eax
  int v52; // eax
  int *v53; // ecx
  float v54; // xmm0_4
  int v55; // eax
  int *v56; // eax
  int v57; // eax
  void (__thiscall ***v58)(_DWORD, float *); // eax
  int v59; // eax
  int *v60; // ecx
  int v61; // eax
  int v62; // eax
  int v63; // eax
  int *v64; // ecx
  float v65; // xmm0_4
  int v66; // eax
  int *v67; // eax
  int v68; // eax
  void (__thiscall ***v69)(_DWORD, float *); // eax
  int v70; // eax
  int *v71; // ecx
  int v72; // eax
  int v73; // eax
  int v74; // eax
  int *v75; // ecx
  float v76; // xmm0_4
  int v77; // eax
  int *v78; // eax
  int v79; // eax
  void (__thiscall ***v80)(_DWORD, float *); // eax
  int v81; // eax
  int *v82; // ecx
  int v83; // eax
  int v84; // eax
  int v85; // eax
  int *v86; // ecx
  float v87; // xmm0_4
  int v88; // eax
  int *v89; // eax
  int v90; // eax
  void (__thiscall ***v91)(_DWORD, float *); // eax
  int v92; // eax
  int *v93; // ecx
  int v94; // eax
  int v95; // eax
  int v96; // eax
  int *v97; // ecx
  float v98; // xmm0_4
  int v99; // eax
  int *v100; // eax
  int v101; // eax
  void (__thiscall ***v102)(_DWORD, float *); // eax
  int v103; // eax
  int *v104; // ecx
  int v105; // eax
  int v106; // eax
  int v107; // eax
  int *v108; // ecx
  float v109; // xmm0_4
  int v110; // eax
  int *v111; // eax
  int v112; // eax
  void (__thiscall ***v113)(_DWORD, float *); // eax
  int v114; // eax
  int *v115; // ecx
  int v116; // eax
  int v117; // eax
  int v118; // eax
  int v119; // eax
  float v120; // xmm0_4
  int *v121; // ecx
  int *v122; // eax
  int v123; // eax
  void (__thiscall ***v124)(_DWORD, _DWORD *); // eax
  int v125; // eax
  int *v126; // ecx
  int v127; // eax
  int v128; // eax
  int v129; // eax
  int v130; // eax
  float v131; // xmm0_4
  int *v132; // ecx
  int *v133; // eax
  int v134; // eax
  void (__thiscall ***v135)(_DWORD, _DWORD *); // eax
  int v136; // eax
  int *v137; // ecx
  int v138; // eax
  int v139; // eax
  int v140; // eax
  int v141; // eax
  float v142; // xmm0_4
  int *v143; // ecx
  int *v144; // eax
  int v145; // eax
  void (__thiscall ***v146)(_DWORD, _DWORD *); // eax
  int v147; // eax
  int v148; // ebx
  int v149; // eax
  int v150; // eax
  _DWORD v151[2]; // [esp+Ch] [ebp-24h] BYREF
  _DWORD v152[2]; // [esp+14h] [ebp-1Ch] BYREF
  _DWORD v153[2]; // [esp+1Ch] [ebp-14h] BYREF
  float v154; // [esp+24h] [ebp-Ch] BYREF
  float v155; // [esp+28h] [ebp-8h]
  float v156; // [esp+2Ch] [ebp-4h]

  v2 = (int *)(*(int (__thiscall **)(_DWORD))(**a2 + 8))(*a2);
  a2[1] = v2;
  (*(void (__thiscall **)(int *, int))(*v2 + 16))(v2, 1);
  v3 = a2[1];
  v154 = 0.0;
  v155 = 0.0;
  (*(void (__thiscall **)(int *, float *))*v3)(v3, &v154);
  v4 = a2[1];
  v154 = FLOAT_1280_0;
  v155 = FLOAT_720_0;
  (*(void (__thiscall **)(int *, float *))(*v4 + 8))(v4, &v154);
  v5 = (int *)(*(int (__thiscall **)(_DWORD))(**a2 + 16))(*a2);
  a2[2] = v5;
  v6 = (*(int (__thiscall **)(int *))(*v5 + 28))(v5);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v6 + 16))(v6, 1);
  v7 = (void (__thiscall ***)(_DWORD, float *))(*(int (__thiscall **)(int *))(*a2[2] + 28))(a2[2]);
  v154 = 0.0;
  v155 = 0.0;
  (**v7)(v7, &v154);
  v8 = (*(int (__thiscall **)(int *))(*a2[2] + 28))(a2[2]);
  v154 = FLOAT_50_0;
  v155 = FLOAT_20_0;
  (*(void (__thiscall **)(int, float *))(*(_DWORD *)v8 + 8))(v8, &v154);
  (*(void (__thiscall **)(int *, _DWORD))*a2[2])(a2[2], 0);
  (*(void (__thiscall **)(int *, _DWORD))(*a2[2] + 20))(a2[2], 0);
  (*(void (__thiscall **)(int *, int *))(*a2[2] + 4))(a2[2], a2[17]);
  v9 = a2[2];
  v156 = *(float *)a2[1];
  v10 = (*(int (__thiscall **)(int *, int))(*v9 + 28))(v9, 1);
  (*(void (__thiscall **)(int *, int))(LODWORD(v156) + 64))(a2[1], v10);
  v11 = (*(int (__thiscall **)(int *))(*a2[2] + 28))(a2[2]);
  v12 = *(float *)((*(int (__thiscall **)(int))(*(_DWORD *)v11 + 12))(v11) + 4);
  v13 = *a2;
  v14 = **a2;
  v156 = v12;
  v15 = (int *)(*(int (__thiscall **)(int *))(v14 + 16))(v13);
  a2[3] = v15;
  v16 = (*(int (__thiscall **)(int *))(*v15 + 28))(v15);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v16 + 16))(v16, 1);
  v17 = (void (__thiscall ***)(_DWORD, float *))(*(int (__thiscall **)(int *))(*a2[3] + 28))(a2[3]);
  v154 = 0.0;
  v155 = v156;
  (**v17)(v17, &v154);
  v18 = (*(int (__thiscall **)(int *))(*a2[3] + 28))(a2[3]);
  v154 = s_spot_max_distance;
  v155 = FLOAT_20_0;
  (*(void (__thiscall **)(int, float *))(*(_DWORD *)v18 + 8))(v18, &v154);
  (*(void (__thiscall **)(int *, _DWORD))*a2[3])(a2[3], 0);
  (*(void (__thiscall **)(int *, _DWORD))(*a2[3] + 20))(a2[3], 0);
  (*(void (__thiscall **)(int *, int *))(*a2[3] + 4))(a2[3], a2[18]);
  v19 = a2[3];
  v155 = *(float *)a2[1];
  v20 = (*(int (__thiscall **)(int *, int))(*v19 + 28))(v19, 1);
  (*(void (__thiscall **)(int *, int))(LODWORD(v155) + 64))(a2[1], v20);
  v21 = (*(int (__thiscall **)(int *))(*a2[2] + 28))(a2[2]);
  v22 = (*(int (__thiscall **)(int))(*(_DWORD *)v21 + 12))(v21);
  v156 = *(float *)(v22 + 4) + v156;
  v23 = (int *)(*(int (__thiscall **)(_DWORD))(**a2 + 16))(*a2);
  a2[4] = v23;
  v24 = (*(int (__thiscall **)(int *))(*v23 + 28))(v23);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v24 + 16))(v24, 1);
  v25 = (void (__thiscall ***)(_DWORD, float *))(*(int (__thiscall **)(int *))(*a2[4] + 28))(a2[4]);
  v154 = 0.0;
  v155 = v156;
  (**v25)(v25, &v154);
  v26 = (*(int (__thiscall **)(int *))(*a2[4] + 28))(a2[4]);
  v154 = FLOAT_50_0;
  v155 = FLOAT_20_0;
  (*(void (__thiscall **)(int, float *))(*(_DWORD *)v26 + 8))(v26, &v154);
  (*(void (__thiscall **)(int *, _DWORD))*a2[4])(a2[4], 0);
  (*(void (__thiscall **)(int *, _DWORD))(*a2[4] + 20))(a2[4], 0);
  (*(void (__thiscall **)(int *, int *))(*a2[4] + 4))(a2[4], a2[18]);
  v27 = a2[4];
  v155 = *(float *)a2[1];
  v28 = (*(int (__thiscall **)(int *, int))(*v27 + 28))(v27, 1);
  (*(void (__thiscall **)(int *, int))(LODWORD(v155) + 64))(a2[1], v28);
  v29 = (*(int (__thiscall **)(int *))(*a2[2] + 28))(a2[2]);
  v30 = (*(int (__thiscall **)(int))(*(_DWORD *)v29 + 12))(v29);
  v31 = *a2;
  v32 = *(float *)(v30 + 4) + v156;
  v33 = **a2;
  v156 = v32;
  v34 = (int *)(*(int (__thiscall **)(int *))(v33 + 16))(v31);
  a2[5] = v34;
  v35 = (*(int (__thiscall **)(int *))(*v34 + 28))(v34);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v35 + 16))(v35, 1);
  v36 = (void (__thiscall ***)(_DWORD, float *))(*(int (__thiscall **)(int *))(*a2[5] + 28))(a2[5]);
  v154 = 0.0;
  v155 = v156;
  (**v36)(v36, &v154);
  v37 = (*(int (__thiscall **)(int *))(*a2[5] + 28))(a2[5]);
  v154 = FLOAT_50_0;
  v155 = FLOAT_20_0;
  (*(void (__thiscall **)(int, float *))(*(_DWORD *)v37 + 8))(v37, &v154);
  (*(void (__thiscall **)(int *, _DWORD))*a2[5])(a2[5], 0);
  (*(void (__thiscall **)(int *, _DWORD))(*a2[5] + 20))(a2[5], 0);
  (*(void (__thiscall **)(int *, int *))(*a2[5] + 4))(a2[5], a2[18]);
  v38 = a2[5];
  v155 = *(float *)a2[1];
  v39 = (*(int (__thiscall **)(int *, int))(*v38 + 28))(v38, 1);
  (*(void (__thiscall **)(int *, int))(LODWORD(v155) + 64))(a2[1], v39);
  v40 = (*(int (__thiscall **)(int *))(*a2[2] + 28))(a2[2]);
  v41 = (*(int (__thiscall **)(int))(*(_DWORD *)v40 + 12))(v40);
  v42 = *a2;
  v43 = *(float *)(v41 + 4) + v156;
  v44 = **a2;
  v156 = v43;
  v45 = (int *)(*(int (__thiscall **)(int *))(v44 + 16))(v42);
  a2[6] = v45;
  v46 = (*(int (__thiscall **)(int *))(*v45 + 28))(v45);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v46 + 16))(v46, 1);
  v47 = (void (__thiscall ***)(_DWORD, float *))(*(int (__thiscall **)(int *))(*a2[6] + 28))(a2[6]);
  v154 = 0.0;
  v155 = v156;
  (**v47)(v47, &v154);
  v48 = (*(int (__thiscall **)(int *))(*a2[6] + 28))(a2[6]);
  v154 = s_spot_max_distance;
  v155 = FLOAT_20_0;
  (*(void (__thiscall **)(int, float *))(*(_DWORD *)v48 + 8))(v48, &v154);
  (*(void (__thiscall **)(int *, _DWORD))*a2[6])(a2[6], 0);
  (*(void (__thiscall **)(int *, _DWORD))(*a2[6] + 20))(a2[6], 0);
  (*(void (__thiscall **)(int *, int *))(*a2[6] + 4))(a2[6], a2[17]);
  v49 = a2[6];
  v155 = *(float *)a2[1];
  v50 = (*(int (__thiscall **)(int *, int))(*v49 + 28))(v49, 1);
  (*(void (__thiscall **)(int *, int))(LODWORD(v155) + 64))(a2[1], v50);
  v51 = (*(int (__thiscall **)(int *))(*a2[2] + 28))(a2[2]);
  v52 = (*(int (__thiscall **)(int))(*(_DWORD *)v51 + 12))(v51);
  v53 = *a2;
  v54 = *(float *)(v52 + 4) + v156;
  v55 = **a2;
  v156 = v54;
  v56 = (int *)(*(int (__thiscall **)(int *))(v55 + 16))(v53);
  a2[7] = v56;
  v57 = (*(int (__thiscall **)(int *))(*v56 + 28))(v56);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v57 + 16))(v57, 1);
  v58 = (void (__thiscall ***)(_DWORD, float *))(*(int (__thiscall **)(int *))(*a2[7] + 28))(a2[7]);
  v154 = 0.0;
  v155 = v156;
  (**v58)(v58, &v154);
  v59 = (*(int (__thiscall **)(int *))(*a2[7] + 28))(a2[7]);
  v154 = FLOAT_50_0;
  v155 = FLOAT_20_0;
  (*(void (__thiscall **)(int, float *))(*(_DWORD *)v59 + 8))(v59, &v154);
  (*(void (__thiscall **)(int *, _DWORD))*a2[7])(a2[7], 0);
  (*(void (__thiscall **)(int *, _DWORD))(*a2[7] + 20))(a2[7], 0);
  (*(void (__thiscall **)(int *, int *))(*a2[7] + 4))(a2[7], a2[17]);
  v60 = a2[7];
  v155 = *(float *)a2[1];
  v61 = (*(int (__thiscall **)(int *, int))(*v60 + 28))(v60, 1);
  (*(void (__thiscall **)(int *, int))(LODWORD(v155) + 64))(a2[1], v61);
  v62 = (*(int (__thiscall **)(int *))(*a2[2] + 28))(a2[2]);
  v63 = (*(int (__thiscall **)(int))(*(_DWORD *)v62 + 12))(v62);
  v64 = *a2;
  v65 = *(float *)(v63 + 4) + v156;
  v66 = **a2;
  v156 = v65;
  v67 = (int *)(*(int (__thiscall **)(int *))(v66 + 16))(v64);
  a2[8] = v67;
  v68 = (*(int (__thiscall **)(int *))(*v67 + 28))(v67);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v68 + 16))(v68, 1);
  v69 = (void (__thiscall ***)(_DWORD, float *))(*(int (__thiscall **)(int *))(*a2[8] + 28))(a2[8]);
  v154 = 0.0;
  v155 = v156;
  (**v69)(v69, &v154);
  v70 = (*(int (__thiscall **)(int *))(*a2[8] + 28))(a2[8]);
  v154 = FLOAT_50_0;
  v155 = FLOAT_20_0;
  (*(void (__thiscall **)(int, float *))(*(_DWORD *)v70 + 8))(v70, &v154);
  (*(void (__thiscall **)(int *, _DWORD))*a2[8])(a2[8], 0);
  (*(void (__thiscall **)(int *, _DWORD))(*a2[8] + 20))(a2[8], 0);
  (*(void (__thiscall **)(int *, int *))(*a2[8] + 4))(a2[8], a2[18]);
  v71 = a2[8];
  v155 = *(float *)a2[1];
  v72 = (*(int (__thiscall **)(int *, int))(*v71 + 28))(v71, 1);
  (*(void (__thiscall **)(int *, int))(LODWORD(v155) + 64))(a2[1], v72);
  v73 = (*(int (__thiscall **)(int *))(*a2[2] + 28))(a2[2]);
  v74 = (*(int (__thiscall **)(int))(*(_DWORD *)v73 + 12))(v73);
  v75 = *a2;
  v76 = *(float *)(v74 + 4) + v156;
  v77 = **a2;
  v156 = v76;
  v78 = (int *)(*(int (__thiscall **)(int *))(v77 + 16))(v75);
  a2[11] = v78;
  v79 = (*(int (__thiscall **)(int *))(*v78 + 28))(v78);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v79 + 16))(v79, 1);
  v80 = (void (__thiscall ***)(_DWORD, float *))(*(int (__thiscall **)(int *))(*a2[11] + 28))(a2[11]);
  v154 = 0.0;
  v155 = v156;
  (**v80)(v80, &v154);
  v81 = (*(int (__thiscall **)(int *))(*a2[11] + 28))(a2[11]);
  v154 = FLOAT_50_0;
  v155 = FLOAT_20_0;
  (*(void (__thiscall **)(int, float *))(*(_DWORD *)v81 + 8))(v81, &v154);
  (*(void (__thiscall **)(int *, _DWORD))*a2[11])(a2[11], 0);
  (*(void (__thiscall **)(int *, _DWORD))(*a2[11] + 20))(a2[11], 0);
  (*(void (__thiscall **)(int *, int *))(*a2[11] + 4))(a2[11], a2[18]);
  v82 = a2[11];
  v155 = *(float *)a2[1];
  v83 = (*(int (__thiscall **)(int *, int))(*v82 + 28))(v82, 1);
  (*(void (__thiscall **)(int *, int))(LODWORD(v155) + 64))(a2[1], v83);
  v84 = (*(int (__thiscall **)(int *))(*a2[2] + 28))(a2[2]);
  v85 = (*(int (__thiscall **)(int))(*(_DWORD *)v84 + 12))(v84);
  v86 = *a2;
  v87 = *(float *)(v85 + 4) + v156;
  v88 = **a2;
  v156 = v87;
  v89 = (int *)(*(int (__thiscall **)(int *))(v88 + 16))(v86);
  a2[12] = v89;
  v90 = (*(int (__thiscall **)(int *))(*v89 + 28))(v89);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v90 + 16))(v90, 1);
  v91 = (void (__thiscall ***)(_DWORD, float *))(*(int (__thiscall **)(int *))(*a2[12] + 28))(a2[12]);
  v154 = 0.0;
  v155 = v156;
  (**v91)(v91, &v154);
  v92 = (*(int (__thiscall **)(int *))(*a2[12] + 28))(a2[12]);
  v154 = FLOAT_50_0;
  v155 = FLOAT_20_0;
  (*(void (__thiscall **)(int, float *))(*(_DWORD *)v92 + 8))(v92, &v154);
  (*(void (__thiscall **)(int *, _DWORD))*a2[12])(a2[12], 0);
  (*(void (__thiscall **)(int *, _DWORD))(*a2[12] + 20))(a2[12], 0);
  (*(void (__thiscall **)(int *, int *))(*a2[12] + 4))(a2[12], a2[17]);
  v93 = a2[12];
  v155 = *(float *)a2[1];
  v94 = (*(int (__thiscall **)(int *, int))(*v93 + 28))(v93, 1);
  (*(void (__thiscall **)(int *, int))(LODWORD(v155) + 64))(a2[1], v94);
  v95 = (*(int (__thiscall **)(int *))(*a2[2] + 28))(a2[2]);
  v96 = (*(int (__thiscall **)(int))(*(_DWORD *)v95 + 12))(v95);
  v97 = *a2;
  v98 = *(float *)(v96 + 4) + v156;
  v99 = **a2;
  v156 = v98;
  v100 = (int *)(*(int (__thiscall **)(int *))(v99 + 16))(v97);
  a2[13] = v100;
  v101 = (*(int (__thiscall **)(int *))(*v100 + 28))(v100);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v101 + 16))(v101, 1);
  v102 = (void (__thiscall ***)(_DWORD, float *))(*(int (__thiscall **)(int *))(*a2[13] + 28))(a2[13]);
  v154 = 0.0;
  v155 = v156;
  (**v102)(v102, &v154);
  v103 = (*(int (__thiscall **)(int *))(*a2[13] + 28))(a2[13]);
  v154 = FLOAT_50_0;
  v155 = FLOAT_20_0;
  (*(void (__thiscall **)(int, float *))(*(_DWORD *)v103 + 8))(v103, &v154);
  (*(void (__thiscall **)(int *, _DWORD))*a2[13])(a2[13], 0);
  (*(void (__thiscall **)(int *, _DWORD))(*a2[13] + 20))(a2[13], 0);
  (*(void (__thiscall **)(int *, int *))(*a2[13] + 4))(a2[13], a2[18]);
  v104 = a2[13];
  v155 = *(float *)a2[1];
  v105 = (*(int (__thiscall **)(int *, int))(*v104 + 28))(v104, 1);
  (*(void (__thiscall **)(int *, int))(LODWORD(v155) + 64))(a2[1], v105);
  v106 = (*(int (__thiscall **)(int *))(*a2[2] + 28))(a2[2]);
  v107 = (*(int (__thiscall **)(int))(*(_DWORD *)v106 + 12))(v106);
  v108 = *a2;
  v109 = *(float *)(v107 + 4) + v156;
  v110 = **a2;
  v156 = v109;
  v111 = (int *)(*(int (__thiscall **)(int *))(v110 + 16))(v108);
  a2[14] = v111;
  v112 = (*(int (__thiscall **)(int *))(*v111 + 28))(v111);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v112 + 16))(v112, 1);
  v113 = (void (__thiscall ***)(_DWORD, float *))(*(int (__thiscall **)(int *))(*a2[14] + 28))(a2[14]);
  v154 = 0.0;
  v155 = v156;
  (**v113)(v113, &v154);
  v114 = (*(int (__thiscall **)(int *))(*a2[14] + 28))(a2[14]);
  v154 = FLOAT_50_0;
  v155 = FLOAT_20_0;
  (*(void (__thiscall **)(int, float *))(*(_DWORD *)v114 + 8))(v114, &v154);
  (*(void (__thiscall **)(int *, _DWORD))*a2[14])(a2[14], 0);
  (*(void (__thiscall **)(int *, _DWORD))(*a2[14] + 20))(a2[14], 0);
  (*(void (__thiscall **)(int *, int *))(*a2[14] + 4))(a2[14], a2[18]);
  v115 = a2[14];
  v155 = *(float *)a2[1];
  v116 = (*(int (__thiscall **)(int *, int))(*v115 + 28))(v115, 1);
  (*(void (__thiscall **)(int *, int))(LODWORD(v155) + 64))(a2[1], v116);
  v117 = (*(int (__thiscall **)(int *))(*a2[2] + 28))(a2[2]);
  (*(void (__thiscall **)(int))(*(_DWORD *)v117 + 12))(v117);
  v118 = (*(int (__thiscall **)(int *))(*a2[12] + 28))(a2[12]);
  v119 = (*(int (__thiscall **)(int))(*(_DWORD *)v118 + 4))(v118);
  v120 = *(float *)(v119 + 4) + 20.0;
  v121 = *a2;
  v153[0] = *(_DWORD *)v119;
  *(float *)&v153[1] = v120;
  v122 = (int *)(*(int (__thiscall **)(int *))(*v121 + 16))(v121);
  a2[9] = v122;
  v123 = (*(int (__thiscall **)(int *))(*v122 + 28))(v122);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v123 + 16))(v123, 1);
  v124 = (void (__thiscall ***)(_DWORD, _DWORD *))(*(int (__thiscall **)(int *))(*a2[9] + 28))(a2[9]);
  (**v124)(v124, v153);
  v125 = (*(int (__thiscall **)(int *))(*a2[9] + 28))(a2[9]);
  v154 = FLOAT_50_0;
  v155 = FLOAT_20_0;
  (*(void (__thiscall **)(int, float *))(*(_DWORD *)v125 + 8))(v125, &v154);
  (*(void (__thiscall **)(int *, _DWORD))*a2[9])(a2[9], 0);
  (*(void (__thiscall **)(int *, _DWORD))(*a2[9] + 20))(a2[9], 0);
  (*(void (__thiscall **)(int *, int *))(*a2[9] + 4))(a2[9], a2[18]);
  v126 = a2[9];
  v155 = *(float *)a2[1];
  v127 = (*(int (__thiscall **)(int *, int))(*v126 + 28))(v126, 1);
  (*(void (__thiscall **)(int *, int))(LODWORD(v155) + 64))(a2[1], v127);
  v128 = (*(int (__thiscall **)(int *))(*a2[2] + 28))(a2[2]);
  (*(void (__thiscall **)(int))(*(_DWORD *)v128 + 12))(v128);
  v129 = (*(int (__thiscall **)(int *))(*a2[9] + 28))(a2[9]);
  v130 = (*(int (__thiscall **)(int))(*(_DWORD *)v129 + 4))(v129);
  v131 = *(float *)(v130 + 4) + 20.0;
  v132 = *a2;
  v152[0] = *(_DWORD *)v130;
  *(float *)&v152[1] = v131;
  v133 = (int *)(*(int (__thiscall **)(int *))(*v132 + 16))(v132);
  a2[10] = v133;
  v134 = (*(int (__thiscall **)(int *))(*v133 + 28))(v133);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v134 + 16))(v134, 1);
  v135 = (void (__thiscall ***)(_DWORD, _DWORD *))(*(int (__thiscall **)(int *))(*a2[10] + 28))(a2[10]);
  (**v135)(v135, v152);
  v136 = (*(int (__thiscall **)(int *))(*a2[10] + 28))(a2[10]);
  v154 = FLOAT_50_0;
  v155 = FLOAT_20_0;
  (*(void (__thiscall **)(int, float *))(*(_DWORD *)v136 + 8))(v136, &v154);
  (*(void (__thiscall **)(int *, _DWORD))*a2[10])(a2[10], 0);
  (*(void (__thiscall **)(int *, _DWORD))(*a2[10] + 20))(a2[10], 0);
  (*(void (__thiscall **)(int *, int *))(*a2[10] + 4))(a2[10], a2[17]);
  v137 = a2[10];
  v155 = *(float *)a2[1];
  v138 = (*(int (__thiscall **)(int *, int))(*v137 + 28))(v137, 1);
  (*(void (__thiscall **)(int *, int))(LODWORD(v155) + 64))(a2[1], v138);
  v139 = (*(int (__thiscall **)(int *))(*a2[2] + 28))(a2[2]);
  (*(void (__thiscall **)(int))(*(_DWORD *)v139 + 12))(v139);
  v140 = (*(int (__thiscall **)(int *))(*a2[10] + 28))(a2[10]);
  v141 = (*(int (__thiscall **)(int))(*(_DWORD *)v140 + 4))(v140);
  v142 = *(float *)(v141 + 4) + 20.0;
  v143 = *a2;
  v151[0] = *(_DWORD *)v141;
  *(float *)&v151[1] = v142;
  v144 = (int *)(*(int (__thiscall **)(int *))(*v143 + 16))(v143);
  a2[15] = v144;
  v145 = (*(int (__thiscall **)(int *))(*v144 + 28))(v144);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v145 + 16))(v145, 1);
  v146 = (void (__thiscall ***)(_DWORD, _DWORD *))(*(int (__thiscall **)(int *))(*a2[15] + 28))(a2[15]);
  (**v146)(v146, v151);
  v147 = (*(int (__thiscall **)(int *))(*a2[15] + 28))(a2[15]);
  v154 = FLOAT_50_0;
  v155 = FLOAT_20_0;
  (*(void (__thiscall **)(int, float *))(*(_DWORD *)v147 + 8))(v147, &v154);
  (*(void (__thiscall **)(int *, _DWORD))*a2[15])(a2[15], 0);
  (*(void (__thiscall **)(int *, _DWORD))(*a2[15] + 20))(a2[15], 0);
  (*(void (__thiscall **)(int *, int *))(*a2[15] + 4))(a2[15], a2[18]);
  v148 = *a2[1];
  v149 = (*(int (__thiscall **)(int *, int))(*a2[15] + 28))(a2[15], 1);
  (*(void (__thiscall **)(int *, int))(v148 + 64))(a2[1], v149);
  v150 = (*(int (__thiscall **)(int *))(*a2[2] + 28))(a2[2]);
  (*(void (__thiscall **)(int))(*(_DWORD *)v150 + 12))(v150);
}
