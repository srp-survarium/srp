int __cdecl append_exp(tag_exp_arg *arg, int exp_tag, int exp_class, int exp_constructed, int exp_pad, int imp_ok)
{
  int imp_tag; // edx
  int exp_count; // esi
  tag_exp_type *v9; // ecx
  int v10; // edx

  imp_tag = arg->imp_tag;
  if ( arg->imp_tag == -1 || imp_ok )
  {
    exp_count = arg->exp_count;
    if ( exp_count == 20 )
    {
      ERR_put_error(0xDu, 176, 174, ".\\crypto\\asn1\\asn1_gen.c", 524);
      return 0;
    }
    else
    {
      v9 = &arg->exp_list[exp_count];
      arg->exp_count = exp_count + 1;
      if ( imp_tag == -1 )
      {
        v9->exp_tag = exp_tag;
        v9->exp_class = exp_class;
        v10 = exp_pad;
      }
      else
      {
        v9->exp_tag = imp_tag;
        v9->exp_class = arg->imp_class;
        v10 = exp_pad;
        arg->imp_tag = -1;
        arg->imp_class = -1;
      }
      v9->exp_constructed = exp_constructed;
      v9->exp_pad = v10;
      return 1;
    }
  }
  else
  {
    ERR_put_error(0xDu, 176, 179, ".\\crypto\\asn1\\asn1_gen.c", 518);
    return 0;
  }
}
