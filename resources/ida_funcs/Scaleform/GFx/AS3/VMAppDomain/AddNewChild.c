Scaleform::GFx::AS3::VMAppDomain *__thiscall Scaleform::GFx::AS3::VMAppDomain::AddNewChild(
        Scaleform::GFx::AS3::VMAppDomain *this,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::VMAppDomain *v3; // eax
  Scaleform::GFx::AS3::VMAppDomain *v4; // esi
  Scaleform::MemoryHeap *MHeap; // eax

  v3 = (Scaleform::GFx::AS3::VMAppDomain *)vm->MHeap->Alloc(vm->MHeap, 28, 0);
  v4 = v3;
  if ( !v3 )
    return 0;
  v3->__vftable = (Scaleform::GFx::AS3::VMAppDomain_vtbl *)&Scaleform::GFx::AS3::VMAppDomain::`vftable';
  MHeap = vm->MHeap;
  v4->ClassTraitsSet.Entries.mHash.pTable = 0;
  v4->ClassTraitsSet.Entries.mHash.pHeap = MHeap;
  v4->ParentDomain = 0;
  v4->ChildDomains.Data.Data = 0;
  v4->ChildDomains.Data.Size = 0;
  v4->ChildDomains.Data.Policy.Capacity = 0;
  if ( this )
    Scaleform::GFx::AS3::VMAppDomain::AddChild(this, v4);
  return v4;
}
