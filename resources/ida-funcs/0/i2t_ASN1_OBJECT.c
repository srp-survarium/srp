unsigned int __cdecl i2t_ASN1_OBJECT(char *buf, unsigned int buf_len, asn1_object_st *a)
{
  return OBJ_obj2txt(buf, buf_len, a, 0);
}
