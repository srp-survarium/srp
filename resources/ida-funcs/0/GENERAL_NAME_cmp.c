unsigned int __cdecl GENERAL_NAME_cmp(GENERAL_NAME_st *a, GENERAL_NAME_st *b)
{
  unsigned int result; // eax

  result = -1;
  if ( !a || !b || a->type != b->type )
    return -1;
  switch ( a->type )
  {
    case 0:
      result = OTHERNAME_cmp(a->d.otherName, b->d.otherName);
      break;
    case 1:
    case 2:
    case 6:
      result = ASN1_STRING_cmp(a->d.rfc822Name, b->d.rfc822Name);
      break;
    case 3:
    case 5:
      result = ASN1_TYPE_cmp(a->d.rfc822Name, b->d.rfc822Name);
      break;
    case 4:
      result = X509_NAME_cmp(a->d.directoryName, b->d.directoryName);
      break;
    case 7:
      result = ASN1_OCTET_STRING_cmp(a->d.rfc822Name, b->d.rfc822Name);
      break;
    case 8:
      result = OBJ_cmp(a->d.registeredID, b->d.registeredID);
      break;
    default:
      return result;
  }
  return result;
}
