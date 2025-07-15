int __cdecl jpeg_open_backing_store(int a1)
{
  *(_DWORD *)(*(_DWORD *)a1 + 20) = 51;
  return (**(int (__cdecl ***)(int))a1)(a1);
}
