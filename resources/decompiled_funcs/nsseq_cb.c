int __cdecl nsseq_cb(int operation, asn1_object_st ***pval)
{
  asn1_object_st **v2; // esi

  if ( operation == 1 )
  {
    v2 = *pval;
    *v2 = OBJ_nid2obj(0x4Fu);
  }
  return 1;
}
