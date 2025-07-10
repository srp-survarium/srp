void __usercall survarium::flash_factory::~flash_factory(survarium::flash_factory *this@<ecx>, _DWORD *a2@<eax>)
{
  _DWORD *v3; // esi

  if ( *a2 )
    (*(void (__thiscall **)(_DWORD, int))(*(_DWORD *)*a2 + 4))(*a2, 1);
  v3 = (_DWORD *)a2[1];
  if ( v3 )
  {
    if ( *v3 )
      (**(void (__thiscall ***)(_DWORD, int))*v3)(*v3, 1);
    operator delete(v3);
  }
}
