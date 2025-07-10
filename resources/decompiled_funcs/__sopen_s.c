int __usercall _sopen_s@<eax>(unsigned int a1@<ebx>, int *pfh, const char *path, int oflag, int shflag, int pmode)
{
  return _sopen_helper(a1, path, oflag, shflag, pmode, pfh, 1);
}
