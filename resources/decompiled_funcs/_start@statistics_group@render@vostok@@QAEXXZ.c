void __usercall vostok::render::statistics_group::start(
        vostok::render::statistics_group *this@<ecx>,
        _DWORD **a2@<eax>)
{
  _DWORD *i; // esi

  for ( i = *a2; i; i = (_DWORD *)i[36] )
    (*(void (__thiscall **)(_DWORD *))(*i + 4))(i);
}
