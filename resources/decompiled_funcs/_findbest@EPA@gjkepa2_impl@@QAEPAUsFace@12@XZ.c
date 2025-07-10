gjkepa2_impl::EPA::sFace *__usercall gjkepa2_impl::EPA::findbest@<eax>(gjkepa2_impl::EPA *this@<ecx>, int a2@<eax>)
{
  gjkepa2_impl::EPA::sFace *result; // eax
  gjkepa2_impl::EPA::sFace *v3; // ecx
  float p; // xmm3_4
  float i; // xmm2_4

  result = *(gjkepa2_impl::EPA::sFace **)(a2 + 10324);
  v3 = result->l[1];
  p = result->p;
  for ( i = result->d * result->d; v3; v3 = v3->l[1] )
  {
    if ( v3->p >= p && i > (float)(v3->d * v3->d) )
    {
      result = v3;
      i = v3->d * v3->d;
      p = v3->p;
    }
  }
  return result;
}
