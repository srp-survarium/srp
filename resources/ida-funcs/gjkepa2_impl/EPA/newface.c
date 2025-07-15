gjkepa2_impl::EPA::sFace *__thiscall gjkepa2_impl::EPA::newface(
        gjkepa2_impl::EPA *this,
        gjkepa2_impl::GJK::sSV *a,
        gjkepa2_impl::GJK::sSV *b,
        gjkepa2_impl::GJK::sSV *c,
        gjkepa2_impl::GJK::sSV *forced,
        char a6)
{
  gjkepa2_impl::EPA::sFace *v6; // edi
  float v7; // xmm3_4
  float v8; // xmm4_4
  float v9; // xmm5_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm7_4
  int *v13; // edi
  gjkepa2_impl::EPA::sFace *v14; // esi
  float v15; // xmm7_4
  float v16; // xmm4_4
  float v17; // xmm5_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  float v20; // xmm0_4
  float v21; // xmm4_4
  float v22; // xmm3_4
  float v23; // xmm2_4
  float v24; // xmm1_4
  float v25; // xmm6_4
  float v26; // xmm4_4
  float v27; // xmm2_4
  float v28; // xmm0_4
  float v29; // xmm3_4
  float v30; // xmm4_4
  float v31; // xmm0_4
  float v32; // xmm7_4
  float v33; // xmm0_4
  float v34; // xmm3_4
  float v35; // xmm1_4
  float v36; // xmm2_4
  float v37; // xmm1_4
  float v38; // xmm0_4
  float v39; // xmm0_4
  float v40; // xmm2_4
  float v41; // xmm3_4
  float *v42; // eax
  float v43; // xmm0_4
  float v44; // xmm2_4
  float v45; // xmm3_4
  float v47; // [esp+Ch] [ebp-34h]
  float v48; // [esp+10h] [ebp-30h]
  float *v49; // [esp+18h] [ebp-28h]
  float v50; // [esp+18h] [ebp-28h]
  float v51; // [esp+1Ch] [ebp-24h] BYREF
  float v52; // [esp+20h] [ebp-20h] BYREF
  float v53; // [esp+24h] [ebp-1Ch] BYREF
  gjkepa2_impl::EPA::sList *v54; // [esp+28h] [ebp-18h]
  gjkepa2_impl::EPA::sList *v55; // [esp+2Ch] [ebp-14h]
  float v56; // [esp+30h] [ebp-10h]
  float v57; // [esp+34h] [ebp-Ch]
  float v58; // [esp+38h] [ebp-8h]
  int v59; // [esp+3Ch] [ebp-4h]

  v6 = (gjkepa2_impl::EPA::sFace *)a[322].w.mVec128.m128_i32[3];
  v55 = (gjkepa2_impl::EPA::sList *)&a[322].w.m_floats[3];
  v49 = (float *)v6;
  if ( v6 )
  {
    gjkepa2_impl::EPA::remove((gjkepa2_impl::EPA::sList *)&a[322].w.m_floats[3], v6);
    v54 = (gjkepa2_impl::EPA::sList *)&a[322].w.m_floats[1];
    gjkepa2_impl::EPA::append((gjkepa2_impl::EPA::sList *)&a[322].w.m_floats[1], v6);
    v6->pass = 0;
    v6->c[0] = b;
    v6->c[1] = c;
    v6->c[2] = forced;
    v7 = c->w.mVec128.m128_f32[1] - b->w.mVec128.m128_f32[1];
    v8 = forced->w.mVec128.m128_f32[0] - b->w.mVec128.m128_f32[0];
    v9 = c->w.mVec128.m128_f32[0] - b->w.mVec128.m128_f32[0];
    v10 = forced->w.mVec128.m128_f32[2] - b->w.mVec128.m128_f32[2];
    v11 = c->w.mVec128.m128_f32[2] - b->w.mVec128.m128_f32[2];
    v12 = forced->w.mVec128.m128_f32[1] - b->w.mVec128.m128_f32[1];
    v58 = (float)(v12 * v9) - (float)(v7 * v8);
    v59 = 0;
    v57 = (float)(v11 * v8) - (float)(v10 * v9);
    v56 = (float)(v7 * v10) - (float)(v12 * v11);
    v6->n.mVec128.m128_f32[0] = v56;
    v13 = &v6->n.mVec128.m128_i32[1];
    *(float *)v13++ = v57;
    *(float *)v13 = v58;
    v13[1] = v59;
    v14 = (gjkepa2_impl::EPA::sFace *)v49;
    v15 = v49[1];
    v16 = *v49;
    v17 = v49[2];
    v48 = v15;
    v47 = *v49;
    v50 = fsqrt((float)((float)(v16 * v16) + (float)(v15 * v15)) + (float)(v17 * v17));
    v18 = forced->w.mVec128.m128_f32[1] - b->w.mVec128.m128_f32[1];
    v19 = forced->w.mVec128.m128_f32[2] - b->w.mVec128.m128_f32[2];
    v20 = forced->w.mVec128.m128_f32[0] - b->w.mVec128.m128_f32[0];
    v21 = v16 * v19;
    v22 = (float)(v15 * v19) - (float)(v17 * v18);
    v23 = (float)(v47 * v18) - (float)(v15 * v20);
    v24 = c->w.mVec128.m128_f32[0] - forced->w.mVec128.m128_f32[0];
    v25 = (float)(v17 * v20) - v21;
    v26 = forced->w.mVec128.m128_f32[2] * v23;
    v27 = c->w.mVec128.m128_f32[1] - forced->w.mVec128.m128_f32[1];
    v28 = forced->w.mVec128.m128_f32[0] * v22;
    v29 = c->w.mVec128.m128_f32[2] - forced->w.mVec128.m128_f32[2];
    v30 = (float)(v26 + (float)(forced->w.mVec128.m128_f32[1] * v25)) + v28;
    v31 = v15;
    v32 = v47 * v29;
    v33 = (float)((float)(v31 * v29) - (float)(v17 * v27)) * c->w.mVec128.m128_f32[0];
    v34 = b->w.mVec128.m128_f32[2] - c->w.mVec128.m128_f32[2];
    v35 = (float)(c->w.mVec128.m128_f32[2] * (float)((float)(v47 * v27) - (float)(v48 * v24)))
        + (float)(c->w.mVec128.m128_f32[1] * (float)((float)(v17 * v24) - v32));
    v36 = b->w.mVec128.m128_f32[1] - c->w.mVec128.m128_f32[1];
    v37 = v35 + v33;
    v38 = b->w.mVec128.m128_f32[0] - c->w.mVec128.m128_f32[0];
    v51 = v47 * v34;
    v53 = v30;
    v52 = v37;
    v39 = (float)((float)(b->w.mVec128.m128_f32[2] * (float)((float)(v47 * v36) - (float)(v48 * v38)))
                + (float)(b->w.mVec128.m128_f32[1] * (float)((float)(v17 * v38) - (float)(v47 * v34))))
        + (float)(b->w.mVec128.m128_f32[0] * (float)((float)(v48 * v34) - (float)(v17 * v36)));
    v40 = s_bm_current_air_resistance;
    v51 = v39;
    if ( v50 <= 0.000099999997 )
      v41 = s_bm_current_air_resistance;
    else
      v41 = v50;
    v42 = &v51;
    if ( v37 <= v39 )
      v42 = &v52;
    if ( v30 <= *v42 )
      v42 = &v53;
    v43 = *v42 / v41;
    v14->p = v43;
    if ( v43 >= -0.0099999998 )
      v43 = 0.0;
    v14->p = v43;
    if ( v50 <= 0.000099999997 )
    {
      a->d.mVec128.m128_i32[0] = 2;
    }
    else
    {
      v44 = v40 / v50;
      v45 = (float)((float)((float)(b->w.mVec128.m128_f32[1] * v48) + (float)(b->w.mVec128.m128_f32[2] * v17))
                  + (float)(v47 * b->w.mVec128.m128_f32[0]))
          * v44;
      v14->d = v45;
      v14->n.mVec128.m128_f32[0] = v47 * v44;
      v14->n.mVec128.m128_f32[1] = v48 * v44;
      v14->n.mVec128.m128_f32[2] = v17 * v44;
      if ( a6 || v45 >= -0.0000099999997 )
        return v14;
      a->d.mVec128.m128_i32[0] = 3;
    }
    gjkepa2_impl::EPA::remove(v54, v14);
    gjkepa2_impl::EPA::append(v55, v14);
  }
  else
  {
    a->d.mVec128.m128_i32[0] = 5;
  }
  return 0;
}
