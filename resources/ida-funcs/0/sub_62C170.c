unsigned __int8 *__cdecl sub_62C170(unsigned __int8 *a1, int a2)
{
  while ( 2 )
  {
    switch ( *a1 )
    {
      case 4u:
      case 5u:
        if ( a2 )
          goto LABEL_8;
        return a1;
      case 0x70u:
      case 0x87u:
      case 0x88u:
      case 0x89u:
      case 0x8Au:
      case 0x8Bu:
LABEL_8:
        a1 += (unsigned __int8)_pcre_OP_lengths[*a1];
        continue;
      case 0x78u:
      case 0x79u:
      case 0x7Au:
        if ( a2 )
        {
          do
            a1 += a1[2] | (a1[1] << 8);
          while ( *a1 == 113 );
          a1 += (unsigned __int8)_pcre_OP_lengths[*a1];
          continue;
        }
        return a1;
      default:
        return a1;
    }
  }
}
