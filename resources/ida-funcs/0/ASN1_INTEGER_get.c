int __cdecl ASN1_INTEGER_get(const asn1_string_st *a)
{
  int v1; // edi
  int result; // eax
  int type; // edx
  int length; // edx
  unsigned __int8 *data; // esi
  int i; // ecx
  int v7; // ebx

  v1 = 0;
  result = 0;
  if ( !a )
    return result;
  type = a->type;
  if ( type == 258 )
  {
    v1 = 1;
  }
  else if ( type != 2 )
  {
    return -1;
  }
  length = a->length;
  if ( a->length > 4 )
    return -1;
  data = a->data;
  if ( !data )
    return 0;
  for ( i = 0; i < length; result = v7 | (result << 8) )
    v7 = data[i++];
  if ( v1 )
    return -result;
  return result;
}
