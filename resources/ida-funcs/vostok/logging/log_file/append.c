void __userpurge vostok::logging::log_file::append(
        vostok::logging::log_file *this@<ecx>,
        int a2@<edi>,
        char *data,
        unsigned int length)
{
  char *v4; // ebx
  __int64 v5; // rax
  int v6; // ecx
  int v7; // eax
  int v8; // ecx
  bool v9; // cf
  int v10; // eax
  int v11; // edx
  vostok::logging::log_file *v12; // [esp+14h] [ebp-14h]
  char *v13; // [esp+18h] [ebp-10h]
  int value; // [esp+1Ch] [ebp-Ch] BYREF
  __int64 v15; // [esp+20h] [ebp-8h]

  v4 = data;
  if ( length )
  {
    vostok::logging::log_file::start_transaction(this, a2);
    (***(void (__thiscall ****)(_DWORD, _DWORD, _DWORD, int))(a2 + 1024))(*(_DWORD *)(a2 + 1024), 0, 0, 2);
    v5 = ((__int64 (__thiscall *)(_DWORD))*(_DWORD *)(**(_DWORD **)(a2 + 1024) + 4))(*(_DWORD *)(a2 + 1024));
    v6 = *(_DWORD *)(a2 + 1024);
    v15 = v5;
    v7 = (*(int (__thiscall **)(int, char *, unsigned int))(*(_DWORD *)v6 + 12))(v6, data, length);
    v8 = a2 + 17488;
    v9 = __CFADD__(v7, *(_DWORD *)(a2 + 17488));
    *(_DWORD *)(a2 + 17488) += v7;
    v13 = &data[length];
    *(_DWORD *)(a2 + 17492) += v9;
    while ( *v4 )
    {
      strchr(v4, 0xAu);
      if ( v10 )
      {
        v8 = v10 - (_DWORD)v4 + 1;
        v12 = (vostok::logging::log_file *)v8;
      }
      else
      {
        v8 = v13 - v4;
        v12 = (vostok::logging::log_file *)(v13 - v4);
      }
      v15 += (unsigned int)v8;
      if ( v10 )
      {
        ++*(_DWORD *)(a2 + 17464);
        v11 = *(_DWORD *)(a2 + 1040) - *(_DWORD *)(a2 + 1036);
        value = *(_DWORD *)(a2 + 17464);
        if ( v11 >> 2 < ((unsigned int)value >> 8) + 1
          && (unsigned int)((*(_DWORD *)(a2 + 1040) - *(_DWORD *)(a2 + 1036)) >> 2) < 0x1000
          && !(_BYTE)value )
        {
          value = v15;
          vostok::buffer_vector<int>::push_back((vostok::buffer_vector<int> *)v8, a2 + 1036, &value);
          v8 = (int)v12;
        }
      }
      v4 += v8;
    }
    vostok::logging::log_file::end_transaction((vostok::logging::log_file *)v8, a2);
  }
}
