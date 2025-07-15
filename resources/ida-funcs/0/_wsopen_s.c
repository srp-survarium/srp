int __usercall _wsopen_s@<eax>(int a1@<ebx>, int *pfh, const wchar_t *path, int oflag, int shflag, int pmode)
{
  return _wsopen_helper(a1, path, oflag, shflag, pmode, pfh, 1);
}
