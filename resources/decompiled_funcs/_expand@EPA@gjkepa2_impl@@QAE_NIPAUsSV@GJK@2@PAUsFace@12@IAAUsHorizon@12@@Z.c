char __thiscall gjkepa2_impl::EPA::expand(
        gjkepa2_impl::EPA *this,
        unsigned int pass,
        gjkepa2_impl::GJK::sSV *w,
        gjkepa2_impl::EPA::sFace *f,
        unsigned int e,
        gjkepa2_impl::EPA::sHorizon *horizon)
{
  unsigned int v7; // eax
  gjkepa2_impl::EPA::sFace *v8; // eax
  gjkepa2_impl::EPA::sFace *cf; // ecx
  unsigned int v11; // ebx

  if ( f->pass == pass )
    return 0;
  v7 = `gjkepa2_impl::GJK::projectorigin'::`2'::imd3[e];
  if ( (float)((float)((float)((float)(w->w.mVec128.m128_f32[2] * f->n.mVec128.m128_f32[2])
                             + (float)(w->w.mVec128.m128_f32[1] * f->n.mVec128.m128_f32[1]))
                     + (float)(f->n.mVec128.m128_f32[0] * w->w.mVec128.m128_f32[0]))
             - f->d) >= -0.0000099999997 )
  {
    v11 = `gjkepa2_impl::EPA::expand'::`2'::i2m3[e];
    f->pass = pass;
    if ( gjkepa2_impl::EPA::expand(this, pass, w, f->f[v7], f->e[v7], horizon)
      && gjkepa2_impl::EPA::expand(this, pass, w, f->f[v11], f->e[v11], horizon) )
    {
      gjkepa2_impl::EPA::remove(&this->m_hull, f);
      gjkepa2_impl::EPA::append(&this->m_stock, f);
      return 1;
    }
    return 0;
  }
  v8 = gjkepa2_impl::EPA::newface(f->c[v7], this, f->c[e], w, 0);
  if ( !v8 )
    return 0;
  v8->e[0] = e;
  v8->f[0] = f;
  f->e[e] = 0;
  f->f[e] = v8;
  cf = horizon->cf;
  if ( horizon->cf )
  {
    cf->e[1] = 2;
    cf->f[1] = v8;
    v8->e[2] = 1;
    v8->f[2] = cf;
    ++horizon->nf;
  }
  else
  {
    ++horizon->nf;
    horizon->ff = v8;
  }
  horizon->cf = v8;
  return 1;
}
