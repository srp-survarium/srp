gjkepa2_impl::EPA::sFace *__usercall gjkepa2_impl::EPA::findbest@<eax>(gjkepa2_impl::EPA *this@<ecx>, int a2@<eax>)
{
  gjkepa2_impl::EPA::sFace *result; // eax
  float p; // xmm3_4
  gjkepa2_impl::EPA::sFace *v4; // ecx
  float v5; // xmm1_4

  result = *(gjkepa2_impl::EPA::sFace **)(a2 + 10324);
  p = result->p;
  v4 = result->l[1];
  v5 = result->d * result->d;
  while ( v4 )
  {
    if ( v4->p >= p && v5 > (float)(v4->d * v4->d) )
    {
      result = v4;
      v5 = v4->d * v4->d;
      p = v4->p;
    }
    v4 = v4->l[1];
  }
  return result;
}
