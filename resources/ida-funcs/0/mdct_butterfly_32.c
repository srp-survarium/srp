void __usercall mdct_butterfly_32(float *x@<eax>)
{
  float v1; // xmm0_4
  float v2; // xmm1_4
  float v3; // xmm7_4
  float v4; // xmm6_4
  float v5; // xmm2_4
  float v6; // xmm0_4
  float v7; // xmm4_4
  float v8; // xmm3_4
  float v9; // xmm1_4
  float v10; // xmm5_4
  float v11; // xmm0_4
  float v12; // xmm3_4
  float v13; // xmm1_4
  float v14; // xmm4_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  float v17; // xmm5_4
  float v18; // xmm2_4
  float v19; // xmm4_4
  float v20; // xmm7_4
  float v21; // xmm3_4
  float v22; // xmm6_4
  float v23; // xmm4_4
  float v24; // xmm2_4
  float v25; // xmm5_4
  float v26; // xmm3_4
  float v27; // xmm4_4
  float v28; // xmm5_4
  float v29; // xmm7_4
  float v30; // xmm2_4
  float v31; // xmm2_4
  float v32; // xmm4_4
  float v33; // xmm6_4
  float v34; // xmm5_4
  float v35; // xmm2_4
  float v36; // xmm7_4
  float v37; // xmm2_4
  float v38; // xmm5_4
  float v39; // xmm6_4
  float v40; // xmm4_4
  float v41; // xmm5_4
  float v42; // xmm7_4
  float v43; // xmm5_4
  float v44; // xmm6_4
  float v45; // xmm2_4
  float v46; // xmm4_4
  float v47; // xmm2_4
  float v48; // xmm5_4
  float v49; // xmm2_4
  float v50; // xmm6_4
  float v51; // xmm4_4
  float v52; // xmm7_4
  float v53; // xmm5_4
  float v54; // xmm4_4
  float v55; // xmm2_4
  float v56; // xmm6_4
  float v57; // xmm5_4
  float v58; // xmm4_4
  float *v59; // edx

  v1 = x[14];
  v2 = x[15];
  v3 = x[27];
  v4 = x[26];
  v5 = x[30] - v1;
  v6 = v1 + x[30];
  v7 = x[28];
  v8 = x[31] - v2;
  v9 = v2 + x[31];
  v10 = x[29];
  x[14] = v5;
  x[15] = v8;
  x[30] = v6;
  v11 = x[12];
  v12 = v7 - v11;
  x[31] = v9;
  v13 = x[13];
  x[28] = v11 + v7;
  x[29] = v13 + v10;
  x[12] = (float)((float)(v7 - v11) * 0.9238795) - (float)((float)(v10 - v13) * 0.38268343);
  v14 = x[11];
  v15 = (float)((float)(v10 - v13) * 0.9238795) + (float)(v12 * 0.38268343);
  v16 = x[10];
  x[13] = v15;
  v17 = v4 - v16;
  v18 = v3 - v14;
  v19 = v14 + v3;
  v20 = x[24];
  v21 = v16 + v4;
  v22 = x[9];
  x[27] = v19;
  v23 = v17 - v18;
  v24 = v18 + v17;
  v25 = x[8];
  x[26] = v21;
  v26 = hsqt2;
  x[10] = v23 * hsqt2;
  x[11] = v24 * v26;
  v27 = v20 - v25;
  v28 = v25 + v20;
  v29 = x[22];
  v30 = x[25] - v22;
  x[24] = v28;
  x[25] = v22 + x[25];
  x[8] = (float)(v27 * 0.38268343) - (float)(v30 * 0.9238795);
  x[9] = (float)(v30 * 0.38268343) + (float)(v27 * 0.9238795);
  v31 = x[6];
  v32 = x[23];
  v33 = x[7] - v32;
  v34 = v29 - v31;
  v35 = v31 + v29;
  v36 = x[4];
  x[22] = v35;
  v37 = x[5];
  x[23] = v32 + x[7];
  x[7] = v34;
  v38 = x[20];
  x[6] = v33;
  v39 = x[21];
  v40 = v36 - v38;
  v41 = v38 + v36;
  v42 = x[2];
  x[20] = v41;
  v43 = v37 - v39;
  x[21] = v39 + x[5];
  v44 = v40;
  v45 = (float)(v43 * 0.38268343) - (float)(v40 * 0.9238795);
  v46 = x[18];
  x[5] = v45;
  v47 = x[3];
  x[4] = (float)(v43 * 0.9238795) + (float)(v44 * 0.38268343);
  v48 = x[19];
  v49 = v47 - v48;
  v50 = v42 - v46;
  v51 = v46 + v42;
  v52 = x[1];
  x[18] = v51;
  v53 = v48 + x[3];
  v54 = (float)(v49 + v50) * v26;
  v55 = v49 - v50;
  v56 = *x;
  x[2] = v54;
  x[19] = v53;
  v57 = x[17];
  x[3] = v55 * v26;
  v58 = x[16];
  x[16] = v58 + v56;
  x[17] = v57 + v52;
  *x = (float)((float)(v52 - v57) * 0.38268343) + (float)((float)(v56 - v58) * 0.9238795);
  x[1] = (float)((float)(v52 - v57) * 0.9238795) - (float)((float)(v56 - v58) * 0.38268343);
  mdct_butterfly_16(x);
  mdct_butterfly_16(v59);
}
