void __usercall setup_crldp(stack_st_X509_EXTENSION *x@<edi>)
{
  stack_st_DIST_POINT *ext_d2i; // eax
  int i; // ebx
  char *v3; // eax

  ext_d2i = (stack_st_DIST_POINT *)X509_get_ext_d2i(x, 103, 0, 0);
  x[3].stack.sorted = (int)ext_d2i;
  for ( i = 0; i < sk_num((const stack_st *)x[3].stack.sorted); ++i )
  {
    v3 = sk_value((const stack_st *)x[3].stack.sorted, i);
    setup_dp((DIST_POINT_st *)v3, (x509_st *)x);
  }
}
