char __thiscall gjkepa2_impl::EPA::expand(
        gjkepa2_impl::EPA *this,
        unsigned int pass,
        gjkepa2_impl::GJK::sSV *w,
        gjkepa2_impl::EPA::sFace *f,
        unsigned int e,
        gjkepa2_impl::EPA::sHorizon *horizon)
{
  float v6; // eax
  gjkepa2_impl::EPA::sFace *v7; // eax
  gjkepa2_impl::EPA::sFace *cf; // ecx
  unsigned int v10; // ebx

  if ( f->pass != pass )
  {
    v6 = `gjkepa2_impl::GJK::projectorigin'::`2'::imd3[e];
    if ( (float)((float)((float)((float)(w->w.mVec128.m128_f32[2] * f->n.mVec128.m128_f32[2])
                               + (float)(w->w.mVec128.m128_f32[1] * f->n.mVec128.m128_f32[1]))
                       + (float)(f->n.mVec128.m128_f32[0] * w->w.mVec128.m128_f32[0]))
               - f->d) >= -0.0000099999997 )
    {
      v10 = `gjkepa2_impl::EPA::expand'::`2'::i2m3[e];
      f->pass = pass;
      if ( gjkepa2_impl::EPA::expand(this, pass, w, f->f[LODWORD(v6)], f->e[LODWORD(v6)], horizon)
        && gjkepa2_impl::EPA::expand(this, pass, w, f->f[v10], f->e[v10], horizon) )
      {
        gjkepa2_impl::EPA::remove(&this->m_hull, f);
        gjkepa2_impl::EPA::append(&this->m_stock, f);
        return 1;
      }
    }
    else
    {
      v7 = gjkepa2_impl::EPA::newface(
             (gjkepa2_impl::EPA *)(4 * e),
             (gjkepa2_impl::GJK::sSV *)this,
             f->c[LODWORD(v6)],
             f->c[e],
             w,
             0);
      if ( v7 )
      {
        v7->e[0] = e;
        v7->f[0] = f;
        f->e[e] = 0;
        f->f[e] = v7;
        cf = horizon->cf;
        if ( horizon->cf )
        {
          cf->e[1] = 2;
          cf->f[1] = v7;
          v7->e[2] = 1;
          v7->f[2] = cf;
        }
        else
        {
          horizon->ff = v7;
        }
        ++horizon->nf;
        horizon->cf = v7;
        return 1;
      }
    }
  }
  return 0;
}
