int __usercall _sopen_s@<eax>(int a1@<ebx>, int *pfh, char *path, int oflag, int shflag, int pmode)
{
  return _sopen_helper(a1, path, oflag, shflag, pmode, pfh, 1);
}
