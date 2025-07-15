_DWORD *__userpurge vostok::variant<32>::`scalar deleting destructor'@<eax>(
        vostok::variant<32> *this@<ecx>,
        _DWORD *a2@<esi>,
        char a3)
{
  int v3; // ecx

  v3 = a2[10];
  if ( v3 )
  {
    (*(void (__thiscall **)(int, _DWORD *))(*(_DWORD *)v3 + 4))(v3, a2 + 2);
    a2[10] = 0;
  }
  if ( (a3 & 1) != 0 )
    operator delete(a2);
  return a2;
}
