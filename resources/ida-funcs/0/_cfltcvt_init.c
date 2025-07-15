int (__usercall *_cfltcvt_init())@<eax>(int a1@<ebx>, _CRT_DOUBLE *arg, char *buffer, unsigned int sizeInBytes, int format, int precision, int caps)
{
  int (__usercall *result)@<eax>(int@<ebx>, _CRT_DOUBLE *, char *, unsigned int, int, int, int); // eax

  result = _cfltcvt;
  _cfltcvt_tab[0] = (void (__cdecl *)())_cfltcvt;
  off_86F68C[0] = (int (*)())_cropzeros;
  off_86F690[0] = (int (*)())_fassign;
  off_86F694[0] = (int (*)())_forcdecpt;
  off_86F698[0] = (int (*)())_positive;
  off_86F69C[0] = (int (*)())_cfltcvt;
  codedptr = _cfltcvt_l;
  off_86F6A4[0] = (int (*)())_fassign_l;
  off_86F6A8 = _cropzeros_l;
  off_86F6AC = _forcdecpt_l;
  return result;
}
