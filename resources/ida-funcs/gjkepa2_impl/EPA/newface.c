gjkepa2_impl::EPA::sFace *__userpurge gjkepa2_impl::EPA::newface@<eax>(
        gjkepa2_impl::GJK::sSV *a@<edi>,
        gjkepa2_impl::EPA *this,
        gjkepa2_impl::GJK::sSV *b,
        gjkepa2_impl::GJK::sSV *c,
        bool forced)
{
  gjkepa2_impl::EPA::sFace *root; // esi
  gjkepa2_impl::EPA::sFace *v6; // eax
  gjkepa2_impl::EPA::sFace *v7; // eax
  gjkepa2_impl::EPA::sFace *v8; // eax
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm3_4
  float v12; // xmm4_4
  float v13; // xmm5_4
  float v14; // xmm2_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  long double v17; // st7
  float v18; // xmm1_4
  float v19; // xmm2_4
  float v20; // xmm4_4
  float v21; // xmm5_4
  float v22; // xmm0_4
  float v23; // xmm6_4
  float v24; // xmm3_4
  float v25; // xmm0_4
  float v26; // xmm5_4
  float v27; // xmm4_4
  float v28; // xmm6_4
  float v29; // xmm0_4
  float v30; // xmm4_4
  float v31; // xmm0_4
  float v32; // xmm7_4
  float v33; // xmm4_4
  float v34; // xmm6_4
  float v35; // xmm5_4
  float v36; // xmm4_4
  float v37; // xmm0_4
  float v38; // xmm7_4
  float v39; // xmm6_4
  float v40; // xmm5_4
  float v41; // xmm7_4
  float v42; // xmm0_4
  const vostok::math::float4x4 *v43; // xmm5_4
  float v44; // xmm6_4
  float *v45; // eax
  float v46; // xmm0_4
  float v47; // xmm5_4
  float v48; // xmm4_4
  gjkepa2_impl::EPA::sFace *v50; // eax
  gjkepa2_impl::EPA::sFace *v51; // eax
  gjkepa2_impl::EPA::sFace *v52; // eax
  float v53; // [esp+34h] [ebp-30h] BYREF
  float v54; // [esp+38h] [ebp-2Ch] BYREF
  float v55; // [esp+3Ch] [ebp-28h] BYREF
  float v56; // [esp+40h] [ebp-24h]
  unsigned __int64 v57; // [esp+44h] [ebp-20h]
  unsigned __int64 v58; // [esp+4Ch] [ebp-18h]
  float v59; // [esp+54h] [ebp-10h]

  root = this->m_stock.root;
  if ( root )
  {
    v6 = root->l[1];
    if ( v6 )
      v6->l[0] = root->l[0];
    v7 = root->l[0];
    if ( v7 )
      v7->l[1] = root->l[1];
    if ( root == this->m_stock.root )
      this->m_stock.root = root->l[1];
    --this->m_stock.count;
    root->l[0] = 0;
    root->l[1] = this->m_hull.root;
    v8 = this->m_hull.root;
    if ( v8 )
      v8->l[0] = root;
    ++this->m_hull.count;
    this->m_hull.root = root;
    root->c[1] = b;
    root->c[2] = c;
    root->pass = 0;
    root->c[0] = a;
    v9 = c->w.mVec128.m128_f32[1] - a->w.mVec128.m128_f32[1];
    v10 = b->w.mVec128.m128_f32[2] - a->w.mVec128.m128_f32[2];
    v11 = b->w.mVec128.m128_f32[1] - a->w.mVec128.m128_f32[1];
    v12 = c->w.mVec128.m128_f32[0] - a->w.mVec128.m128_f32[0];
    v13 = b->w.mVec128.m128_f32[0] - a->w.mVec128.m128_f32[0];
    v14 = c->w.mVec128.m128_f32[2] - a->w.mVec128.m128_f32[2];
    *(float *)&v58 = (float)(v9 * v13) - (float)(v11 * v12);
    *((float *)&v57 + 1) = (float)(v10 * v12) - (float)(v14 * v13);
    HIDWORD(v58) = 0;
    *(float *)&v57 = (float)(v11 * v14) - (float)(v10 * v9);
    root->n.mVec128.m128_u64[0] = v57;
    root->n.mVec128.m128_u64[1] = v58;
    v15 = root->n.mVec128.m128_f32[1];
    v16 = root->n.mVec128.m128_f32[2];
    v55 = root->n.mVec128.m128_f32[0];
    v53 = v15;
    v54 = v16;
    v17 = sqrtf((float)((float)(v55 * v55) + (float)(v15 * v15)) + (float)(v16 * v16));
    v56 = v17;
    v18 = v16;
    v19 = v53;
    v20 = c->w.mVec128.m128_f32[1] - a->w.mVec128.m128_f32[1];
    v21 = c->w.mVec128.m128_f32[2] - a->w.mVec128.m128_f32[2];
    v22 = c->w.mVec128.m128_f32[0] - a->w.mVec128.m128_f32[0];
    v23 = (float)(v53 * v21) - (float)(v54 * v20);
    v54 = v54 * v22;
    v24 = v55;
    v55 = v55 * v21;
    v25 = c->w.mVec128.m128_f32[2] * (float)((float)(v24 * v20) - (float)(v53 * v22));
    v26 = b->w.mVec128.m128_f32[1] - c->w.mVec128.m128_f32[1];
    v27 = c->w.mVec128.m128_f32[0] * v23;
    v28 = b->w.mVec128.m128_f32[2] - c->w.mVec128.m128_f32[2];
    v29 = (float)(v25 + (float)(c->w.mVec128.m128_f32[1] * (float)(v54 - v55))) + v27;
    v30 = b->w.mVec128.m128_f32[0] - c->w.mVec128.m128_f32[0];
    v53 = v29;
    v31 = (float)((float)(v19 * v28) - (float)(v18 * v26)) * b->w.mVec128.m128_f32[0];
    v55 = v18 * v30;
    v54 = v24 * v28;
    v32 = (float)(v18 * v30) - (float)(v24 * v28);
    v33 = b->w.mVec128.m128_f32[2] * (float)((float)(v24 * v26) - (float)(v19 * v30));
    v34 = a->w.mVec128.m128_f32[2] - b->w.mVec128.m128_f32[2];
    v35 = a->w.mVec128.m128_f32[1] - b->w.mVec128.m128_f32[1];
    v36 = (float)(v33 + (float)(b->w.mVec128.m128_f32[1] * v32)) + v31;
    v37 = a->w.mVec128.m128_f32[0] - b->w.mVec128.m128_f32[0];
    v54 = v36;
    *(float *)&v58 = v34;
    v59 = (float)(v19 * v34) - (float)(v18 * v35);
    v55 = v18 * v37;
    v38 = (float)(v18 * v37) - (float)(v24 * v34);
    v39 = (float)(v24 * v35) - (float)(v19 * v37);
    v40 = a->w.mVec128.m128_f32[1] * v38;
    v41 = v56;
    v42 = (float)((float)(a->w.mVec128.m128_f32[2] * v39) + v40) + (float)(a->w.mVec128.m128_f32[0] * v59);
    v43 = clear_value;
    v55 = v42;
    if ( v17 <= 0.000099999997 )
      v44 = *(float *)&clear_value;
    else
      v44 = v56;
    v45 = &v55;
    if ( v36 <= v42 )
      v45 = &v54;
    if ( v53 <= *v45 )
      v45 = &v53;
    v46 = *v45 / v44;
    root->p = v46;
    if ( v46 >= -0.0099999998 )
      v46 = 0.0;
    root->p = v46;
    if ( v17 <= 0.000099999997 )
    {
      this->m_status = Failed;
    }
    else
    {
      v47 = *(float *)&v43 / v41;
      v48 = (float)((float)((float)(a->w.mVec128.m128_f32[1] * v19) + (float)(a->w.mVec128.m128_f32[2] * v18))
                  + (float)(v24 * a->w.mVec128.m128_f32[0]))
          * v47;
      root->d = v48;
      root->n.mVec128.m128_f32[0] = v24 * v47;
      root->n.mVec128.m128_f32[1] = v19 * v47;
      root->n.mVec128.m128_f32[2] = v18 * v47;
      if ( forced || v48 >= -0.0000099999997 )
        return root;
      this->m_status = Failed|Inside;
    }
    v50 = root->l[1];
    if ( v50 )
      v50->l[0] = root->l[0];
    v51 = root->l[0];
    if ( v51 )
      v51->l[1] = root->l[1];
    if ( root == this->m_hull.root )
      this->m_hull.root = root->l[1];
    --this->m_hull.count;
    root->l[0] = 0;
    root->l[1] = this->m_stock.root;
    v52 = this->m_stock.root;
    if ( v52 )
      v52->l[0] = root;
    ++this->m_stock.count;
    this->m_stock.root = root;
    return 0;
  }
  else
  {
    this->m_status = 5;
    return 0;
  }
}
