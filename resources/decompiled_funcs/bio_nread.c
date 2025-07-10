int __usercall bio_nread@<eax>(bio_st *bio@<ebx>, char **buf@<edi>, unsigned int num_@<ecx>)
{
  int v3; // esi
  signed int v4; // eax
  _DWORD *v5; // eax
  bool v6; // zf

  v3 = num_;
  if ( num_ > 0x7FFFFFFF )
    v3 = 0x7FFFFFFF;
  v4 = bio_nread0(bio, buf);
  if ( v3 > v4 )
    v3 = v4;
  if ( v3 > 0 )
  {
    v5 = *(_DWORD **)(*(_DWORD *)bio->ptr + 32);
    v6 = v5[2] == v3;
    v5[2] -= v3;
    if ( v6 || (v5[3] += v3, v5[3] == v5[4]) )
      v5[3] = 0;
  }
  return v3;
}
