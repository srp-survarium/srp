int __usercall _book_maptype1_quantvals@<eax>(const static_codebook *b@<eax>)
{
  int dim; // esi
  int entries; // edi
  int result; // eax
  int v4; // ecx
  int v5; // edx
  int v6; // [esp+40h] [ebp-8h]
  int v7; // [esp+44h] [ebp-4h]

  dim = b->dim;
  entries = b->entries;
  v6 = entries;
  v7 = b->dim;
  for ( result = (int)floor(pow((double)entries, 1.0 / (double)b->dim)); ; ++result )
  {
    while ( 1 )
    {
      v4 = 1;
      v5 = 1;
      if ( dim > 0 )
      {
        do
        {
          v4 *= result;
          v5 *= result + 1;
          --dim;
        }
        while ( dim );
        entries = v6;
        dim = v7;
      }
      if ( v4 <= entries )
        break;
      --result;
    }
    if ( v5 > entries )
      break;
  }
  return result;
}
