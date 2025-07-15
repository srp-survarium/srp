int __usercall append_exp@<eax>(
        int a1@<ebx>,
        tag_exp_arg *arg,
        int exp_tag,
        int exp_class,
        int exp_constructed,
        int exp_pad,
        int imp_ok)
{
  int imp_tag; // edx
  int exp_count; // esi
  tag_exp_type *v10; // ecx
  int v11; // edx

  imp_tag = arg->imp_tag;
  if ( arg->imp_tag == -1 || imp_ok )
  {
    exp_count = arg->exp_count;
    if ( exp_count == 20 )
    {
      ERR_put_error(a1, 0xDu, 176, 174, ".\\crypto\\asn1\\asn1_gen.c", 524);
      return 0;
    }
    else
    {
      v10 = &arg->exp_list[exp_count];
      arg->exp_count = exp_count + 1;
      if ( imp_tag == -1 )
      {
        v10->exp_tag = exp_tag;
        v10->exp_class = exp_class;
        v11 = exp_pad;
      }
      else
      {
        v10->exp_tag = imp_tag;
        v10->exp_class = arg->imp_class;
        v11 = exp_pad;
        arg->imp_tag = -1;
        arg->imp_class = -1;
      }
      v10->exp_constructed = exp_constructed;
      v10->exp_pad = v11;
      return 1;
    }
  }
  else
  {
    ERR_put_error(a1, 0xDu, 176, 179, ".\\crypto\\asn1\\asn1_gen.c", 518);
    return 0;
  }
}
