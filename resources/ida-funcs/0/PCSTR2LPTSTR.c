void __usercall PCSTR2LPTSTR(int a1@<ebx>, char *lpszIn, char *lpszOut, unsigned int outSize)
{
  memcpy_s(a1, (unsigned __int8 *)lpszOut, outSize, (unsigned __int8 *)lpszIn, outSize);
}
