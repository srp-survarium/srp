Scaleform::GFx::ASString *__usercall Scaleform::GFx::AS3::GetNameSkipVectorNS@<eax>(
        Scaleform::GFx::AS3::Traits_vtbl *tr@<ecx>,
        int a2@<esi>)
{
  Scaleform::GFx::AS3::Traits_vtbl *GetFilePtr; // eax
  int v3; // eax
  Scaleform::GFx::AS3::Traits_vtbl *ForEachChild_GC; // edx

  if ( ((int)tr->InitOnDemand & 0x20) != 0 )
    GetFilePtr = (Scaleform::GFx::AS3::Traits_vtbl *)tr[1].GetFilePtr;
  else
    GetFilePtr = tr;
  v3 = strcmp(**((const char ***)GetFilePtr[1].GetFilePtr + 7), Scaleform::GFx::AS3::NS_Vector);
  ForEachChild_GC = (Scaleform::GFx::AS3::Traits_vtbl *)tr->ForEachChild_GC;
  if ( v3 )
    ((void (__stdcall *)(int, _DWORD))ForEachChild_GC->GetQualifiedName)(a2, 0);
  else
    ((void (__stdcall *)(int))ForEachChild_GC->GetName)(a2);
  return (Scaleform::GFx::ASString *)a2;
}
