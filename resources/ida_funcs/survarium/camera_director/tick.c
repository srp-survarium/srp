void __usercall survarium::camera_director::tick(survarium::camera_director *this@<ecx>, int a2@<eax>)
{
  if ( *(_DWORD *)(a2 + 132) )
    (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(a2 + 132) + 16))(*(_DWORD *)(a2 + 132));
}
