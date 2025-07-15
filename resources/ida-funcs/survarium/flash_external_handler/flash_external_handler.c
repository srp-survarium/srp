void __usercall survarium::flash_external_handler::flash_external_handler(
        survarium::flash_external_handler *this@<ecx>,
        _DWORD *a2@<esi>)
{
  Scaleform::MemoryHeap *v2; // ecx
  _DWORD *v3; // eax

  v2 = Scaleform::Memory::pGlobalHeap;
  *a2 = &survarium::flash_external_handler::`vftable';
  v3 = v2->Alloc(v2, 16u, 0);
  if ( v3 )
  {
    *v3 = &Scaleform::RefCountImplCore::`vftable';
    v3[1] = 1;
    v3[2] = 6;
    *v3 = &survarium::flash_external_handler_impl::`vftable';
    v3[3] = a2;
  }
  else
  {
    v3 = 0;
  }
  a2[1] = v3;
}
