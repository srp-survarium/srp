ec_pre_comp_st *__usercall ec_pre_comp_new@<eax>(const ec_group_st *group@<edi>)
{
  ec_pre_comp_st *result; // eax

  if ( !group )
    return 0;
  result = (ec_pre_comp_st *)CRYPTO_malloc(28, ".\\crypto\\ec\\ec_mult.c", 105);
  if ( !result )
  {
    ERR_put_error(0x10u, 196, 65, ".\\crypto\\ec\\ec_mult.c", 108);
    return 0;
  }
  result->group = group;
  result->blocksize = 8;
  result->numblocks = 0;
  result->w = 4;
  result->points = 0;
  result->num = 0;
  result->references = 1;
  return result;
}
