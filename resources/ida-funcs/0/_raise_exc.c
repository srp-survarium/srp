void __usercall _raise_exc(
        __int16 a1@<fpstat>,
        _FPIEEE_RECORD *prec,
        unsigned int *pcw,
        DWORD flags,
        int opcode,
        long double *parg1,
        long double *presult)
{
  _raise_exc_ex(a1, prec, pcw, flags, opcode, (float *)parg1, (float *)presult, 0);
}
