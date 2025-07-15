void __usercall store_num(
        int num@<eax>,
        unsigned int digits@<edx>,
        char **out@<edi>,
        unsigned int *count@<ecx>,
        unsigned int no_lead_zeros)
{
  char *v5; // esi
  int v6; // et2
  char *v7; // eax
  char *v8; // esi
  char v9; // cl
  int v10; // esi
  int v11; // et2
  int v12; // [esp+8h] [ebp-4h]

  v12 = 0;
  if ( no_lead_zeros )
  {
    v5 = *out;
    if ( *count > 1 )
    {
      do
      {
        v6 = num % 10;
        num /= 10;
        *v5++ = v6 + 48;
        --*count;
      }
      while ( num > 0 && *count > 1 );
    }
    v7 = *out;
    *out = v5;
    v8 = v5 - 1;
    do
    {
      v9 = *v8;
      *v8-- = *v7;
      *v7++ = v9;
    }
    while ( v7 < v8 );
  }
  else if ( digits >= *count )
  {
    *count = 0;
  }
  else
  {
    v10 = digits - 1;
    if ( digits )
    {
      do
      {
        v11 = num % 10;
        num /= 10;
        ++v12;
        (*out)[v10--] = v11 + 48;
      }
      while ( v10 != -1 );
    }
    *out += v12;
    *count -= v12;
  }
}
