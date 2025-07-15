int __stdcall _seh_longjmp_unwind(int a1)
{
  return _local_unwind2(*(_DWORD *)(a1 + 24), *(_DWORD *)(a1 + 28));
}
