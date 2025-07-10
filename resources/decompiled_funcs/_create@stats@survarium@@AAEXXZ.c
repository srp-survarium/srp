void __usercall survarium::stats::create(survarium::stats *this@<ecx>, _DWORD *a2@<esi>)
{
  int v2; // eax
  void (__thiscall ***v3)(_DWORD, int *); // ecx
  int v4; // ecx
  int v5; // eax
  int v6; // eax
  void (__thiscall ***v7)(_DWORD, int *); // eax
  int v8; // eax
  int v9; // edi
  int v10; // eax
  int v11; // eax
  int v12; // eax
  void (__thiscall ***v13)(_DWORD, int *); // eax
  int v14; // eax
  int v15; // edi
  int v16; // eax
  int v17; // eax
  int v18; // eax
  void (__thiscall ***v19)(_DWORD, int *); // eax
  int v20; // eax
  int v21; // edi
  int v22; // eax
  int v23; // eax
  int v24; // eax
  void (__thiscall ***v25)(_DWORD, int *); // eax
  int v26; // eax
  int v27; // edi
  int v28; // eax
  int v29; // eax
  int v30; // eax
  void (__thiscall ***v31)(_DWORD, int *); // eax
  int v32; // eax
  int v33; // edi
  int v34; // eax
  int v35; // eax
  int v36; // eax
  void (__thiscall ***v37)(_DWORD, int *); // eax
  int v38; // eax
  int v39; // edi
  int v40; // eax
  int v41; // eax
  int v42; // eax
  void (__thiscall ***v43)(_DWORD, int *); // eax
  int v44; // eax
  int v45; // edi
  int v46; // eax
  int v47; // eax
  int v48; // eax
  void (__thiscall ***v49)(_DWORD, int *); // eax
  int v50; // eax
  int v51; // edi
  int v52; // eax
  int v53; // eax
  int v54; // eax
  void (__thiscall ***v55)(_DWORD, int *); // eax
  int v56; // eax
  int v57; // edi
  int v58; // eax
  int v59; // eax
  int v60; // eax
  void (__thiscall ***v61)(_DWORD, int *); // eax
  int v62; // eax
  int v63; // edi
  int v64; // eax
  int v65; // eax
  int v66; // eax
  void (__thiscall ***v67)(_DWORD, int *); // eax
  int v68; // eax
  int v69; // edi
  int v70; // eax
  int v71; // eax
  int v72; // eax
  void (__thiscall ***v73)(_DWORD, int *); // eax
  int v74; // eax
  int v75; // edi
  int v76; // eax
  int v77; // eax
  int v78; // eax
  float v79; // xmm0_4
  int v80; // ecx
  int v81; // eax
  int v82; // eax
  void (__thiscall ***v83)(_DWORD, _DWORD *); // eax
  int v84; // eax
  int v85; // edi
  int v86; // eax
  int v87; // [esp+194h] [ebp-14h] BYREF
  int v88; // [esp+198h] [ebp-10h]
  _DWORD v89[3]; // [esp+19Ch] [ebp-Ch] BYREF

  v2 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)*a2 + 8))(*a2);
  a2[1] = v2;
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v2 + 16))(v2, 1);
  v3 = (void (__thiscall ***)(_DWORD, int *))a2[1];
  v87 = 0;
  v88 = 0;
  (**v3)(v3, &v87);
  v4 = a2[1];
  v87 = 1151336448;
  v88 = 1144258560;
  (*(void (__thiscall **)(int, int *))(*(_DWORD *)v4 + 8))(v4, &v87);
  v5 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)*a2 + 16))(*a2);
  a2[2] = v5;
  v6 = (*(int (__thiscall **)(int))(*(_DWORD *)v5 + 28))(v5);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v6 + 16))(v6, 1);
  v7 = (void (__thiscall ***)(_DWORD, int *))(*(int (__thiscall **)(_DWORD))(*(_DWORD *)a2[2] + 28))(a2[2]);
  v87 = 0;
  v88 = 0;
  (**v7)(v7, &v87);
  v8 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)a2[2] + 28))(a2[2]);
  v87 = 1112014848;
  v88 = 1101004800;
  (*(void (__thiscall **)(int, int *))(*(_DWORD *)v8 + 8))(v8, &v87);
  (**(void (__thiscall ***)(_DWORD, _DWORD))a2[2])(a2[2], 0);
  (*(void (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)a2[2] + 20))(a2[2], 0);
  (*(void (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)a2[2] + 4))(a2[2], a2[16]);
  v9 = *(_DWORD *)a2[1];
  v10 = (*(int (__thiscall **)(_DWORD, int))(*(_DWORD *)a2[2] + 28))(a2[2], 1);
  (*(void (__thiscall **)(_DWORD, int))(v9 + 64))(a2[1], v10);
  v11 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)*a2 + 16))(*a2);
  a2[3] = v11;
  v12 = (*(int (__thiscall **)(int))(*(_DWORD *)v11 + 28))(v11);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v12 + 16))(v12, 1);
  v13 = (void (__thiscall ***)(_DWORD, int *))(*(int (__thiscall **)(_DWORD))(*(_DWORD *)a2[3] + 28))(a2[3]);
  v87 = 0;
  v88 = 1101004800;
  (**v13)(v13, &v87);
  v14 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)a2[3] + 28))(a2[3]);
  v87 = 1120403456;
  v88 = 1101004800;
  (*(void (__thiscall **)(int, int *))(*(_DWORD *)v14 + 8))(v14, &v87);
  (**(void (__thiscall ***)(_DWORD, _DWORD))a2[3])(a2[3], 0);
  (*(void (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)a2[3] + 20))(a2[3], 0);
  (*(void (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)a2[3] + 4))(a2[3], a2[17]);
  v15 = *(_DWORD *)a2[1];
  v16 = (*(int (__thiscall **)(_DWORD, int))(*(_DWORD *)a2[3] + 28))(a2[3], 1);
  (*(void (__thiscall **)(_DWORD, int))(v15 + 64))(a2[1], v16);
  v17 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)*a2 + 16))(*a2);
  a2[4] = v17;
  v18 = (*(int (__thiscall **)(int))(*(_DWORD *)v17 + 28))(v17);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v18 + 16))(v18, 1);
  v19 = (void (__thiscall ***)(_DWORD, int *))(*(int (__thiscall **)(_DWORD))(*(_DWORD *)a2[4] + 28))(a2[4]);
  v87 = 0;
  v88 = 1109393408;
  (**v19)(v19, &v87);
  v20 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)a2[4] + 28))(a2[4]);
  v87 = 1120403456;
  v88 = 1101004800;
  (*(void (__thiscall **)(int, int *))(*(_DWORD *)v20 + 8))(v20, &v87);
  (**(void (__thiscall ***)(_DWORD, _DWORD))a2[4])(a2[4], 0);
  (*(void (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)a2[4] + 20))(a2[4], 0);
  (*(void (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)a2[4] + 4))(a2[4], a2[16]);
  v21 = *(_DWORD *)a2[1];
  v22 = (*(int (__thiscall **)(_DWORD, int))(*(_DWORD *)a2[4] + 28))(a2[4], 1);
  (*(void (__thiscall **)(_DWORD, int))(v21 + 64))(a2[1], v22);
  v23 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)*a2 + 16))(*a2);
  a2[5] = v23;
  v24 = (*(int (__thiscall **)(int))(*(_DWORD *)v23 + 28))(v23);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v24 + 16))(v24, 1);
  v25 = (void (__thiscall ***)(_DWORD, int *))(*(int (__thiscall **)(_DWORD))(*(_DWORD *)a2[5] + 28))(a2[5]);
  v87 = 0;
  v88 = 1114636288;
  (**v25)(v25, &v87);
  v26 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)a2[5] + 28))(a2[5]);
  v87 = 1112014848;
  v88 = 1101004800;
  (*(void (__thiscall **)(int, int *))(*(_DWORD *)v26 + 8))(v26, &v87);
  (**(void (__thiscall ***)(_DWORD, _DWORD))a2[5])(a2[5], 0);
  (*(void (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)a2[5] + 20))(a2[5], 0);
  (*(void (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)a2[5] + 4))(a2[5], a2[17]);
  v27 = *(_DWORD *)a2[1];
  v28 = (*(int (__thiscall **)(_DWORD, int))(*(_DWORD *)a2[5] + 28))(a2[5], 1);
  (*(void (__thiscall **)(_DWORD, int))(v27 + 64))(a2[1], v28);
  v29 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)*a2 + 16))(*a2);
  a2[6] = v29;
  v30 = (*(int (__thiscall **)(int))(*(_DWORD *)v29 + 28))(v29);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v30 + 16))(v30, 1);
  v31 = (void (__thiscall ***)(_DWORD, int *))(*(int (__thiscall **)(_DWORD))(*(_DWORD *)a2[6] + 28))(a2[6]);
  v87 = 0;
  v88 = 1117782016;
  (**v31)(v31, &v87);
  v32 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)a2[6] + 28))(a2[6]);
  v87 = 1120403456;
  v88 = 1101004800;
  (*(void (__thiscall **)(int, int *))(*(_DWORD *)v32 + 8))(v32, &v87);
  (**(void (__thiscall ***)(_DWORD, _DWORD))a2[6])(a2[6], 0);
  (*(void (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)a2[6] + 20))(a2[6], 0);
  (*(void (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)a2[6] + 4))(a2[6], a2[16]);
  v33 = *(_DWORD *)a2[1];
  v34 = (*(int (__thiscall **)(_DWORD, int))(*(_DWORD *)a2[6] + 28))(a2[6], 1);
  (*(void (__thiscall **)(_DWORD, int))(v33 + 64))(a2[1], v34);
  v35 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)*a2 + 16))(*a2);
  a2[7] = v35;
  v36 = (*(int (__thiscall **)(int))(*(_DWORD *)v35 + 28))(v35);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v36 + 16))(v36, 1);
  v37 = (void (__thiscall ***)(_DWORD, int *))(*(int (__thiscall **)(_DWORD))(*(_DWORD *)a2[7] + 28))(a2[7]);
  v87 = 0;
  v88 = 1120403456;
  (**v37)(v37, &v87);
  v38 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)a2[7] + 28))(a2[7]);
  v87 = 1133903872;
  v88 = 1109393408;
  (*(void (__thiscall **)(int, int *))(*(_DWORD *)v38 + 8))(v38, &v87);
  (**(void (__thiscall ***)(_DWORD, _DWORD))a2[7])(a2[7], 0);
  (*(void (__thiscall **)(_DWORD, int))(*(_DWORD *)a2[7] + 20))(a2[7], 1);
  (*(void (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)a2[7] + 4))(a2[7], a2[17]);
  v39 = *(_DWORD *)a2[1];
  v40 = (*(int (__thiscall **)(_DWORD, int))(*(_DWORD *)a2[7] + 28))(a2[7], 1);
  (*(void (__thiscall **)(_DWORD, int))(v39 + 64))(a2[1], v40);
  v41 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)*a2 + 16))(*a2);
  a2[9] = v41;
  v42 = (*(int (__thiscall **)(int))(*(_DWORD *)v41 + 28))(v41);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v42 + 16))(v42, 1);
  v43 = (void (__thiscall ***)(_DWORD, int *))(*(int (__thiscall **)(_DWORD))(*(_DWORD *)a2[9] + 28))(a2[9]);
  v87 = 0;
  v88 = 1123024896;
  (**v43)(v43, &v87);
  v44 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)a2[9] + 28))(a2[9]);
  v87 = 1112014848;
  v88 = 1101004800;
  (*(void (__thiscall **)(int, int *))(*(_DWORD *)v44 + 8))(v44, &v87);
  (**(void (__thiscall ***)(_DWORD, _DWORD))a2[9])(a2[9], 0);
  (*(void (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)a2[9] + 20))(a2[9], 0);
  (*(void (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)a2[9] + 4))(a2[9], a2[16]);
  v45 = *(_DWORD *)a2[1];
  v46 = (*(int (__thiscall **)(_DWORD, int))(*(_DWORD *)a2[9] + 28))(a2[9], 1);
  (*(void (__thiscall **)(_DWORD, int))(v45 + 64))(a2[1], v46);
  v47 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)*a2 + 16))(*a2);
  a2[8] = v47;
  v48 = (*(int (__thiscall **)(int))(*(_DWORD *)v47 + 28))(v47);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v48 + 16))(v48, 1);
  v49 = (void (__thiscall ***)(_DWORD, int *))(*(int (__thiscall **)(_DWORD))(*(_DWORD *)a2[8] + 28))(a2[8]);
  v87 = 0;
  v88 = 1124859904;
  (**v49)(v49, &v87);
  v50 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)a2[8] + 28))(a2[8]);
  v87 = 1112014848;
  v88 = 1101004800;
  (*(void (__thiscall **)(int, int *))(*(_DWORD *)v50 + 8))(v50, &v87);
  (**(void (__thiscall ***)(_DWORD, _DWORD))a2[8])(a2[8], 0);
  (*(void (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)a2[8] + 20))(a2[8], 0);
  (*(void (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)a2[8] + 4))(a2[8], a2[16]);
  v51 = *(_DWORD *)a2[1];
  v52 = (*(int (__thiscall **)(_DWORD, int))(*(_DWORD *)a2[8] + 28))(a2[8], 1);
  (*(void (__thiscall **)(_DWORD, int))(v51 + 64))(a2[1], v52);
  v53 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)*a2 + 16))(*a2);
  a2[10] = v53;
  v54 = (*(int (__thiscall **)(int))(*(_DWORD *)v53 + 28))(v53);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v54 + 16))(v54, 1);
  v55 = (void (__thiscall ***)(_DWORD, int *))(*(int (__thiscall **)(_DWORD))(*(_DWORD *)a2[10] + 28))(a2[10]);
  v87 = 0;
  v88 = 1126170624;
  (**v55)(v55, &v87);
  v56 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)a2[10] + 28))(a2[10]);
  v87 = 1112014848;
  v88 = 1101004800;
  (*(void (__thiscall **)(int, int *))(*(_DWORD *)v56 + 8))(v56, &v87);
  (**(void (__thiscall ***)(_DWORD, _DWORD))a2[10])(a2[10], 0);
  (*(void (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)a2[10] + 20))(a2[10], 0);
  (*(void (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)a2[10] + 4))(a2[10], a2[17]);
  v57 = *(_DWORD *)a2[1];
  v58 = (*(int (__thiscall **)(_DWORD, int))(*(_DWORD *)a2[10] + 28))(a2[10], 1);
  (*(void (__thiscall **)(_DWORD, int))(v57 + 64))(a2[1], v58);
  v59 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)*a2 + 16))(*a2);
  a2[11] = v59;
  v60 = (*(int (__thiscall **)(int))(*(_DWORD *)v59 + 28))(v59);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v60 + 16))(v60, 1);
  v61 = (void (__thiscall ***)(_DWORD, int *))(*(int (__thiscall **)(_DWORD))(*(_DWORD *)a2[11] + 28))(a2[11]);
  v87 = 0;
  v88 = 1130102784;
  (**v61)(v61, &v87);
  v62 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)a2[11] + 28))(a2[11]);
  v87 = 1112014848;
  v88 = 1101004800;
  (*(void (__thiscall **)(int, int *))(*(_DWORD *)v62 + 8))(v62, &v87);
  (**(void (__thiscall ***)(_DWORD, _DWORD))a2[11])(a2[11], 0);
  (*(void (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)a2[11] + 20))(a2[11], 0);
  (*(void (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)a2[11] + 4))(a2[11], a2[16]);
  v63 = *(_DWORD *)a2[1];
  v64 = (*(int (__thiscall **)(_DWORD, int))(*(_DWORD *)a2[11] + 28))(a2[11], 1);
  (*(void (__thiscall **)(_DWORD, int))(v63 + 64))(a2[1], v64);
  v65 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)*a2 + 16))(*a2);
  a2[13] = v65;
  v66 = (*(int (__thiscall **)(int))(*(_DWORD *)v65 + 28))(v65);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v66 + 16))(v66, 1);
  v67 = (void (__thiscall ***)(_DWORD, int *))(*(int (__thiscall **)(_DWORD))(*(_DWORD *)a2[13] + 28))(a2[13]);
  v87 = 0;
  v88 = 1127481344;
  (**v67)(v67, &v87);
  v68 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)a2[13] + 28))(a2[13]);
  v87 = 1112014848;
  v88 = 1101004800;
  (*(void (__thiscall **)(int, int *))(*(_DWORD *)v68 + 8))(v68, &v87);
  (**(void (__thiscall ***)(_DWORD, _DWORD))a2[13])(a2[13], 0);
  (*(void (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)a2[13] + 20))(a2[13], 0);
  (*(void (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)a2[13] + 4))(a2[13], a2[17]);
  v69 = *(_DWORD *)a2[1];
  v70 = (*(int (__thiscall **)(_DWORD, int))(*(_DWORD *)a2[13] + 28))(a2[13], 1);
  (*(void (__thiscall **)(_DWORD, int))(v69 + 64))(a2[1], v70);
  v71 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)*a2 + 16))(*a2);
  a2[14] = v71;
  v72 = (*(int (__thiscall **)(int))(*(_DWORD *)v71 + 28))(v71);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v72 + 16))(v72, 1);
  v73 = (void (__thiscall ***)(_DWORD, int *))(*(int (__thiscall **)(_DWORD))(*(_DWORD *)a2[14] + 28))(a2[14]);
  v87 = 0;
  v88 = 1128792064;
  (**v73)(v73, &v87);
  v74 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)a2[14] + 28))(a2[14]);
  v87 = 1112014848;
  v88 = 1101004800;
  (*(void (__thiscall **)(int, int *))(*(_DWORD *)v74 + 8))(v74, &v87);
  (**(void (__thiscall ***)(_DWORD, _DWORD))a2[14])(a2[14], 0);
  (*(void (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)a2[14] + 20))(a2[14], 0);
  (*(void (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)a2[14] + 4))(a2[14], a2[16]);
  v75 = *(_DWORD *)a2[1];
  v76 = (*(int (__thiscall **)(_DWORD, int))(*(_DWORD *)a2[14] + 28))(a2[14], 1);
  (*(void (__thiscall **)(_DWORD, int))(v75 + 64))(a2[1], v76);
  v77 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)a2[14] + 28))(a2[14]);
  v78 = (*(int (__thiscall **)(int))(*(_DWORD *)v77 + 4))(v77);
  v79 = *(float *)(v78 + 4) + 20.0;
  v80 = *a2;
  v89[0] = *(_DWORD *)v78;
  *(float *)&v89[1] = v79;
  v81 = (*(int (__thiscall **)(int))(*(_DWORD *)v80 + 16))(v80);
  a2[12] = v81;
  v82 = (*(int (__thiscall **)(int))(*(_DWORD *)v81 + 28))(v81);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v82 + 16))(v82, 1);
  v83 = (void (__thiscall ***)(_DWORD, _DWORD *))(*(int (__thiscall **)(_DWORD))(*(_DWORD *)a2[12] + 28))(a2[12]);
  (**v83)(v83, v89);
  v84 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)a2[12] + 28))(a2[12]);
  v87 = 1112014848;
  v88 = 1101004800;
  (*(void (__thiscall **)(int, int *))(*(_DWORD *)v84 + 8))(v84, &v87);
  (**(void (__thiscall ***)(_DWORD, _DWORD))a2[12])(a2[12], 0);
  (*(void (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)a2[12] + 20))(a2[12], 0);
  (*(void (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)a2[12] + 4))(a2[12], a2[17]);
  v85 = *(_DWORD *)a2[1];
  v86 = (*(int (__thiscall **)(_DWORD, int))(*(_DWORD *)a2[12] + 28))(a2[12], 1);
  (*(void (__thiscall **)(_DWORD, int))(v85 + 64))(a2[1], v86);
}
