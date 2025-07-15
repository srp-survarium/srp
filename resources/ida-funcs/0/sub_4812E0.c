int __usercall sub_4812E0@<eax>(int a1@<eax>, int a2)
{
  *(_DWORD *)(*(_DWORD *)a1 + 20) = 56;
  *(_DWORD *)(*(_DWORD *)a1 + 24) = a2;
  return (**(int (__cdecl ***)(int))a1)(a1);
}
