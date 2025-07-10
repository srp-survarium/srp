void __cdecl _initp_misc_invarg(
        void (__cdecl *enull)(const wchar_t *, const wchar_t *, const wchar_t *, unsigned int, unsigned int))
{
  __pInvalidArgHandler = enull;
}
