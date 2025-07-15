void __usercall setup_crldp(x509_st *x@<edi>)
{
  stack_st_DIST_POINT *ext_d2i; // eax
  int i; // ebx
  char *v3; // eax

  ext_d2i = (stack_st_DIST_POINT *)X509_get_ext_d2i(x, 103, 0, 0);
  x->crldp = ext_d2i;
  for ( i = 0; i < sk_num(&x->crldp->stack); ++i )
  {
    v3 = sk_value(&x->crldp->stack, i);
    setup_dp((DIST_POINT_st *)v3, x);
  }
}
