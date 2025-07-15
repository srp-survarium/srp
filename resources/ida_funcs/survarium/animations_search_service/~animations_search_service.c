void __usercall survarium::animations_search_service::~animations_search_service(
        survarium::animations_search_service *this@<ecx>,
        _DWORD *a2@<esi>)
{
  if ( a2[12] )
  {
    (*(void (__thiscall **)(_DWORD, _DWORD))(***(_DWORD ***)a2[11] + 24))(**(_DWORD **)a2[11], a2[12]);
    a2[12] = 0;
  }
  if ( a2[6] )
  {
    (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)a2[4] + 24))(*(_DWORD *)a2[4], a2[6]);
    a2[6] = 0;
  }
  if ( a2[5] )
  {
    (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)a2[4] + 24))(*(_DWORD *)a2[4], a2[5]);
    a2[5] = 0;
  }
  if ( a2[1] )
  {
    (*(void (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)*a2 + 24))(*a2, a2[1]);
    a2[1] = 0;
  }
}
