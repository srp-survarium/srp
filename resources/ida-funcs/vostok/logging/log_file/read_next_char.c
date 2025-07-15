char __usercall vostok::logging::log_file::read_next_char@<al>(vostok::logging::log_file *this@<ecx>, int a2@<esi>)
{
  unsigned int v2; // eax
  unsigned int v3; // ecx
  unsigned int v4; // ebx
  unsigned __int64 v5; // kr00_8
  char result; // al
  void (__thiscall ***v7)(_DWORD, _DWORD, int, _DWORD); // ecx
  int v8; // eax
  bool v9; // cf
  int v10; // [esp-8h] [ebp-10h]

  v2 = *(_DWORD *)(a2 + 17472);
  v3 = *(_DWORD *)(a2 + 17476);
  v4 = *(_DWORD *)(a2 + 17484);
  v5 = *(_QWORD *)(a2 + 17472) - *(_QWORD *)(a2 + 17480);
  if ( *(_DWORD *)(a2 + 17480) == -1 && !v4
    || v3 < v4
    || v3 <= v4 && v2 < *(_DWORD *)(a2 + 17480)
    || v5 >= *(unsigned int *)(a2 + 17496) )
  {
    *(_DWORD *)(a2 + 17484) = v3;
    v7 = *(void (__thiscall ****)(_DWORD, _DWORD, int, _DWORD))(a2 + 1024);
    v10 = *(_DWORD *)(a2 + 17484);
    *(_DWORD *)(a2 + 17480) = v2;
    (**v7)(v7, *(_DWORD *)(a2 + 17480), v10, 0);
    v8 = (*(int (__thiscall **)(_DWORD, int, int))(**(_DWORD **)(a2 + 1024) + 8))(*(_DWORD *)(a2 + 1024), a2, 1024);
    v9 = __CFADD__((*(_DWORD *)(a2 + 17472))++, 1);
    *(_DWORD *)(a2 + 17496) = v8;
    result = *(_BYTE *)a2;
    *(_DWORD *)(a2 + 17476) += v9;
  }
  else
  {
    *(_QWORD *)(a2 + 17472) = __PAIR64__(v3, v2) + 1;
    return *(_BYTE *)(v5 + a2);
  }
  return result;
}
