int __cdecl RSA_X931_hash_id(int nid)
{
  if ( nid <= 673 )
  {
    switch ( nid )
    {
      case 673:
        return 54;
      case 64:
        return 51;
      case 672:
        return 52;
    }
    return -1;
  }
  if ( nid != 674 )
    return -1;
  return 53;
}
