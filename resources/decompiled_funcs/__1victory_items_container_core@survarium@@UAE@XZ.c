void __usercall survarium::victory_items_container_core::~victory_items_container_core(
        survarium::victory_items_container_core *this@<ecx>,
        int a2@<esi>)
{
  if ( *(_DWORD *)(a2 + 32) )
    (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(a2 + 40) + 24))(*(_DWORD *)(a2 + 40), *(_DWORD *)(a2 + 32));
  survarium::usable_object::~usable_object((survarium::usable_object *)a2);
}
