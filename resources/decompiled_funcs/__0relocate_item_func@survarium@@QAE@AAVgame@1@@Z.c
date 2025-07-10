void __userpurge survarium::relocate_item_func::relocate_item_func(
        survarium::relocate_item_func *this@<ecx>,
        _DWORD *a2@<esi>,
        survarium::game *g)
{
  Scaleform::MemoryHeap *v3; // ecx
  _DWORD *v4; // eax

  v3 = Scaleform::Memory::pGlobalHeap;
  *a2 = &survarium::flash_function_handler::`vftable';
  v4 = v3->Alloc(v3, 12u, 0);
  if ( v4 )
  {
    *v4 = &Scaleform::RefCountImplCore::`vftable';
    v4[1] = 1;
    *v4 = &survarium::flash_function_handler_impl::`vftable';
    v4[2] = a2;
    a2[1] = v4;
  }
  else
  {
    a2[1] = 0;
  }
  a2[2] = g;
  *a2 = &survarium::relocate_item_func::`vftable';
}
