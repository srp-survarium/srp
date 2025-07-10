int __fastcall bio_nwrite(unsigned int num_, bio_st *bio, char **buf)
{
  int v3; // esi
  signed int v5; // eax

  v3 = num_;
  if ( num_ > 0x7FFFFFFF )
    v3 = 0x7FFFFFFF;
  v5 = bio_nwrite0(bio, buf);
  if ( v3 > v5 )
    v3 = v5;
  if ( v3 > 0 )
    *((_DWORD *)bio->ptr + 2) += v3;
  return v3;
}
