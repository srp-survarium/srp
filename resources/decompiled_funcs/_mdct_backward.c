void __usercall mdct_backward(float *in@<eax>, mdct_lookup *init, float *out)
{
  int v5; // eax
  int v6; // esi
  float *v7; // edx
  int v8; // ebp
  float *trig; // eax
  float *v10; // ecx
  float *v11; // eax
  double v12; // st7
  double v13; // st7
  mdct_lookup *v14; // edx
  float *v15; // ecx
  float *v16; // eax
  double v17; // st7
  double v18; // st7
  float *p_n; // edx
  float *v20; // eax
  mdct_lookup *v21; // edi
  float *v22; // ecx
  double v23; // st7
  double v24; // st6
  float *v25; // eax
  float *v26; // ecx
  float *v27; // edx
  double v28; // st7
  mdct_lookup *v29; // ecx
  float *v30; // eax
  float *v31; // [esp+14h] [ebp-4h]
  mdct_lookup *inita; // [esp+1Ch] [ebp+4h]
  float outa; // [esp+20h] [ebp+8h]
  float outb; // [esp+20h] [ebp+8h]
  float outc; // [esp+20h] [ebp+8h]
  float outd; // [esp+20h] [ebp+8h]

  v5 = init->n >> 2;
  v6 = init->n >> 1;
  v7 = &out[v5 + v6];
  v8 = v5;
  trig = init->trig;
  v10 = &in[v6 - 7];
  inita = (mdct_lookup *)v7;
  v11 = &trig[v8];
  do
  {
    v7 -= 4;
    v12 = -v10[2];
    v10 -= 8;
    v13 = v12 * v11[3];
    v11 += 4;
    *v7 = v13 - v10[8] * *(v11 - 2);
    v7[1] = v10[8] * *(v11 - 1) - *(v11 - 2) * v10[10];
    v7[2] = -v10[14] * *(v11 - 3) - *(v11 - 4) * v10[12];
    v7[3] = *(v11 - 3) * v10[12] - v10[14] * *(v11 - 4);
  }
  while ( v10 >= in );
  v14 = inita;
  v15 = &in[v6 - 8];
  v16 = &init->trig[v8];
  do
  {
    v17 = *(v16 - 2);
    v16 -= 4;
    v18 = v17 * v15[6];
    v15 -= 8;
    v14 = (mdct_lookup *)((char *)v14 + 16);
    *(float *)&v14[-1].log2n = v18 + v16[3] * v15[12];
    *(float *)&v14[-1].trig = v16[2] * v15[12] - v15[14] * v16[3];
    *(float *)&v14[-1].bitrev = v15[8] * v16[1] + *v16 * v15[10];
    v14[-1].scale = v15[8] * *v16 - v16[1] * v15[10];
  }
  while ( v15 >= in );
  v31 = &out[v6];
  mdct_butterflies(init, v31, v6);
  mdct_bitreverse(init, out);
  p_n = (float *)&inita->n;
  v20 = &init->trig[v6];
  v21 = inita;
  v22 = out + 3;
  do
  {
    p_n -= 4;
    v23 = v20[1] * *(v22 - 3);
    v22 += 8;
    v24 = *(v22 - 10) * *v20;
    v21 = (mdct_lookup *)((char *)v21 + 16);
    v20 += 8;
    p_n[3] = v23 - v24;
    *(float *)&v21[-1].log2n = -(*(v22 - 10) * *(v20 - 7) + *(v20 - 8) * *(v22 - 11));
    p_n[2] = *(v22 - 9) * *(v20 - 5) - *(v20 - 6) * *(v22 - 8);
    *(float *)&v21[-1].trig = -(*(v22 - 9) * *(v20 - 6) + *(v20 - 5) * *(v22 - 8));
    p_n[1] = *(v22 - 7) * *(v20 - 3) - *(v22 - 6) * *(v20 - 4);
    *(float *)&v21[-1].bitrev = -(*(v22 - 6) * *(v20 - 3) + *(v22 - 7) * *(v20 - 4));
    *p_n = *(v22 - 5) * *(v20 - 1) - *(v20 - 2) * *(v22 - 4);
    v21[-1].scale = -(*(v20 - 2) * *(v22 - 5) + *(v22 - 4) * *(v20 - 1));
  }
  while ( v22 - 3 < p_n );
  v25 = (float *)&inita->n;
  v26 = &out[v8 + 2];
  v27 = (float *)(&inita->n + 2 - v6);
  do
  {
    v28 = *(v25 - 1);
    v25 -= 4;
    outa = v28;
    v27 -= 4;
    v26 += 4;
    v27[1] = outa;
    *(v26 - 6) = -outa;
    outb = v25[2];
    *v27 = outb;
    *(v26 - 5) = -outb;
    outc = v25[1];
    *(v27 - 1) = outc;
    *(v26 - 4) = -outc;
    outd = *v25;
    *(v27 - 2) = outd;
    *(v26 - 3) = -outd;
  }
  while ( v26 - 2 < v25 );
  v29 = inita;
  v30 = (float *)&inita->n;
  do
  {
    v30 -= 4;
    *v30 = *(float *)&v29->bitrev;
    v29 = (mdct_lookup *)((char *)v29 + 16);
    v30[1] = *(float *)&v29[-1].bitrev;
    v30[2] = *(float *)&v29[-1].trig;
    v30[3] = *(float *)&v29[-1].log2n;
  }
  while ( v30 > v31 );
}
