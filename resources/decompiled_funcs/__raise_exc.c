void __cdecl _raise_exc(
        _FPIEEE_RECORD *prec,
        unsigned int *pcw,
        DWORD flags,
        int opcode,
        long double *parg1,
        long double *presult)
{
  _raise_exc_ex(prec, pcw, flags, opcode, (float *)parg1, (float *)presult, 0);
}
