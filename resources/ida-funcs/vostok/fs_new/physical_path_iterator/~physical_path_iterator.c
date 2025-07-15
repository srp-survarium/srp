void __usercall vostok::fs_new::physical_path_iterator::~physical_path_iterator(
        vostok::fs_new::physical_path_iterator *this@<ecx>,
        _DWORD *a2@<esi>)
{
  if ( (a2[79] & a2[78]) != -1 )
  {
    (*(void (__thiscall **)(_DWORD, _DWORD, _DWORD))(*(_DWORD *)*a2 + 52))(*a2, a2[78], a2[79]);
    a2[78] = 0;
    a2[79] = 0;
  }
}
