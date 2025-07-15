int __usercall nsseq_cb@<eax>(int a1@<ebx>, int operation, asn1_object_st ***pval)
{
  asn1_object_st **v3; // esi

  if ( operation == 1 )
  {
    v3 = *pval;
    *v3 = OBJ_nid2obj(a1, 0x4Fu);
  }
  return 1;
}
