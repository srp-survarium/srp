int (__cdecl *_cfltcvt_init())(long double *arg, char *buffer, unsigned int sizeInBytes, int format, int precision, int caps)
{
  int (__cdecl *result)(long double *, char *, unsigned int, int, int, int); // eax

  result = _cfltcvt;
  _cfltcvt_tab[0] = (void (__cdecl *)())_cfltcvt;
  off_9AEB1C[0] = (int (*)())_cropzeros;
  off_9AEB20[0] = (int (*)())_fassign;
  off_9AEB24[0] = (int (*)())_forcdecpt;
  off_9AEB28[0] = (int (*)())_positive;
  off_9AEB2C[0] = (int (*)())_cfltcvt;
  codedptr = _cfltcvt_l;
  off_9AEB34 = _fassign_l;
  off_9AEB38 = _cropzeros_l;
  off_9AEB3C = _forcdecpt_l;
  return result;
}
