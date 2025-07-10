void __usercall _vp_offset_and_mix(
        vorbis_look_psy *p@<esi>,
        float *tone@<ecx>,
        float *noise,
        int offset_select,
        float *logmask,
        float *mdct,
        float *logmdct)
{
  float *v7; // eax
  int v8; // edx
  float *v9; // edi
  double m_val; // st7
  unsigned int v11; // edi
  int v12; // ebp
  float *v13; // edx
  double v14; // st2
  vorbis_info_psy *vi; // ebp
  double noisemaxsupp; // st2
  double v17; // st1
  double v18; // st2
  vorbis_info_psy *v19; // ebp
  double v20; // st2
  double v21; // st1
  double v22; // st2
  vorbis_info_psy *v23; // ebp
  double v24; // st2
  double v25; // st1
  double v26; // st2
  vorbis_info_psy *v27; // ebp
  double v28; // st2
  double v29; // st1
  double v30; // st2
  float *v31; // ebx
  int v32; // edi
  int v33; // ebp
  float *v34; // edx
  int v35; // ebx
  vorbis_info_psy *v36; // ecx
  double v37; // st2
  double v38; // st1
  double v39; // st2
  float vale; // [esp+8h] [ebp-50h]
  float valf; // [esp+8h] [ebp-50h]
  float val; // [esp+8h] [ebp-50h]
  float valg; // [esp+8h] [ebp-50h]
  float valh; // [esp+8h] [ebp-50h]
  float vala; // [esp+8h] [ebp-50h]
  float vali; // [esp+8h] [ebp-50h]
  float valj; // [esp+8h] [ebp-50h]
  float valb; // [esp+8h] [ebp-50h]
  float valk; // [esp+8h] [ebp-50h]
  float vall; // [esp+8h] [ebp-50h]
  float valc; // [esp+8h] [ebp-50h]
  float valm; // [esp+8h] [ebp-50h]
  float valn; // [esp+8h] [ebp-50h]
  float vald; // [esp+8h] [ebp-50h]
  float *v55; // [esp+Ch] [ebp-4Ch]
  float *v56; // [esp+10h] [ebp-48h]
  float toneatt; // [esp+14h] [ebp-44h]
  float *v58; // [esp+18h] [ebp-40h]
  int n; // [esp+1Ch] [ebp-3Ch]
  int i; // [esp+20h] [ebp-38h]
  int v61; // [esp+24h] [ebp-34h]
  int v62; // [esp+28h] [ebp-30h]
  int v63; // [esp+2Ch] [ebp-2Ch]
  int v64; // [esp+30h] [ebp-28h]
  int v65; // [esp+3Ch] [ebp-1Ch]
  int v66; // [esp+4Ch] [ebp-Ch]
  int v67; // [esp+50h] [ebp-8h]

  v7 = logmask;
  n = p->n;
  v8 = 0;
  toneatt = p->vi->tone_masteratt[offset_select];
  v9 = mdct;
  m_val = p->m_val;
  i = 0;
  if ( p->n >= 4 )
  {
    v65 = (char *)mdct - (char *)tone;
    v63 = -4 - (_DWORD)tone;
    v56 = mdct + 3;
    v67 = (char *)logmdct - (char *)mdct;
    v11 = ((unsigned int)(n - 4) >> 2) + 1;
    v64 = (char *)noise - (char *)logmdct;
    v55 = logmask + 2;
    v66 = (char *)mdct - (char *)logmask;
    v12 = offset_select;
    v58 = logmdct;
    v13 = tone + 1;
    i = 4 * v11;
    while ( 1 )
    {
      v14 = *(float *)((char *)v13 + v63 + (unsigned int)p->noiseoffset[v12]) + *(float *)((char *)v58 + v64);
      vi = p->vi;
      vale = v14;
      noisemaxsupp = vale;
      if ( vi->noisemaxsupp < (double)vale )
        noisemaxsupp = vi->noisemaxsupp;
      v17 = *(v13 - 1) + toneatt;
      if ( v17 < noisemaxsupp )
        v17 = noisemaxsupp;
      *(v55 - 2) = v17;
      if ( offset_select == 1 )
      {
        valf = noisemaxsupp - *v58;
        v18 = valf - -17.20000076293945;
        if ( valf <= -17.200001 )
        {
          val = 1.0 - v18 * 0.0003 * m_val;
        }
        else
        {
          val = 1.0 - v18 * 0.005 * m_val;
          if ( val < 0.0 )
          {
            *(v56 - 3) = *(v56 - 3) * (float)0.000099999997;
            goto LABEL_13;
          }
        }
        *(v56 - 3) = *(v56 - 3) * val;
      }
LABEL_13:
      v19 = p->vi;
      valg = *(float *)((char *)v13 + v63 + (unsigned int)p->noiseoffset[offset_select] + 4)
           + *(float *)((char *)v13 + (char *)noise - (char *)tone);
      v20 = valg;
      if ( v19->noisemaxsupp < (double)valg )
        v20 = v19->noisemaxsupp;
      v21 = *v13 + toneatt;
      if ( v21 < v20 )
        v21 = v20;
      *(float *)((char *)v13 + (char *)logmask - (char *)tone) = v21;
      if ( offset_select == 1 )
      {
        valh = v20 - *(float *)((char *)v13 + (char *)logmdct - (char *)tone);
        v22 = valh - -17.20000076293945;
        if ( valh <= -17.200001 )
        {
          vala = 1.0 - v22 * 0.0003 * m_val;
        }
        else
        {
          vala = 1.0 - v22 * 0.005 * m_val;
          if ( vala < 0.0 )
          {
            *(float *)((char *)v13 + v65) = (float)0.000099999997 * *(float *)((char *)v13 + v65);
            goto LABEL_23;
          }
        }
        *(float *)((char *)v13 + v65) = vala * *(float *)((char *)v13 + v65);
      }
LABEL_23:
      v23 = p->vi;
      vali = *(float *)((char *)p->noiseoffset[offset_select] + 4 - (_DWORD)tone + (unsigned int)v13)
           + *(float *)((char *)v55 + (char *)noise - (char *)logmask);
      v24 = vali;
      if ( v23->noisemaxsupp < (double)vali )
        v24 = v23->noisemaxsupp;
      v25 = v13[1] + toneatt;
      if ( v25 < v24 )
        v25 = v24;
      *v55 = v25;
      if ( offset_select == 1 )
      {
        valj = v24 - *(float *)((char *)v55 + (char *)logmdct - (char *)logmask);
        v26 = valj - -17.20000076293945;
        if ( valj <= -17.200001 )
        {
          valb = 1.0 - v26 * 0.0003 * m_val;
        }
        else
        {
          valb = 1.0 - v26 * 0.005 * m_val;
          if ( valb < 0.0 )
          {
            *(float *)((char *)v55 + v66) = (float)0.000099999997 * *(float *)((char *)v55 + v66);
            goto LABEL_33;
          }
        }
        *(float *)((char *)v55 + v66) = valb * *(float *)((char *)v55 + v66);
      }
LABEL_33:
      v27 = p->vi;
      valk = *(float *)((char *)p->noiseoffset[offset_select] + 8 - (_DWORD)tone + (unsigned int)v13)
           + *(float *)((char *)v56 + v67 + v64);
      v28 = valk;
      if ( v27->noisemaxsupp < (double)valk )
        v28 = v27->noisemaxsupp;
      v29 = v13[2] + toneatt;
      if ( v29 < v28 )
        v29 = v28;
      v12 = offset_select;
      v55[1] = v29;
      if ( offset_select != 1 )
        goto LABEL_43;
      vall = v28 - *(float *)((char *)v56 + v67);
      v30 = vall - -17.20000076293945;
      if ( vall <= -17.200001 )
      {
        valc = 1.0 - v30 * 0.0003 * m_val;
LABEL_42:
        *v56 = *v56 * valc;
        goto LABEL_43;
      }
      valc = 1.0 - v30 * 0.005 * m_val;
      if ( valc >= 0.0 )
        goto LABEL_42;
      *v56 = *v56 * (float)0.000099999997;
LABEL_43:
      v58 += 4;
      v55 += 4;
      v56 += 4;
      v13 += 4;
      if ( !--v11 )
      {
        v8 = i;
        v9 = mdct;
        v7 = logmask;
        break;
      }
    }
  }
  if ( v8 < n )
  {
    v62 = (char *)logmdct - (char *)tone;
    v31 = v9;
    v32 = i;
    v33 = (char *)noise - (char *)tone;
    v34 = &tone[v8];
    v61 = (char *)v7 - (char *)tone;
    v35 = (char *)v31 - (char *)tone;
    while ( 1 )
    {
      v36 = p->vi;
      valm = p->noiseoffset[offset_select][v32] + *(float *)((char *)v34 + v33);
      v37 = valm;
      if ( v36->noisemaxsupp < (double)valm )
        v37 = v36->noisemaxsupp;
      v38 = *v34 + toneatt;
      if ( v38 < v37 )
        v38 = v37;
      *(float *)((char *)v34 + v61) = v38;
      if ( offset_select != 1 )
        goto LABEL_57;
      valn = v37 - *(float *)((char *)v34 + v62);
      v39 = valn - -17.20000076293945;
      if ( valn <= -17.200001 )
        break;
      vald = 1.0 - v39 * 0.005 * m_val;
      if ( vald >= 0.0 )
        goto LABEL_56;
      *(float *)((char *)v34 + v35) = (float)0.000099999997 * *(float *)((char *)v34 + v35);
LABEL_57:
      ++v32;
      ++v34;
      if ( v32 >= n )
        return;
    }
    vald = 1.0 - v39 * 0.0003 * m_val;
LABEL_56:
    *(float *)((char *)v34 + v35) = vald * *(float *)((char *)v34 + v35);
    goto LABEL_57;
  }
}
