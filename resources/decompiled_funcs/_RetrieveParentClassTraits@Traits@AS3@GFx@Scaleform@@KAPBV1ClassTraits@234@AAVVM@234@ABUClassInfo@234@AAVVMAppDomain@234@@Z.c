const Scaleform::GFx::AS3::ClassTraits::Traits *__cdecl Scaleform::GFx::AS3::Traits::RetrieveParentClassTraits(
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::ASStringNode *ci,
        Scaleform::GFx::AS3::VMAppDomain *appDomain)
{
  const Scaleform::GFx::AS3::ClassInfo *v3; // edi
  const Scaleform::GFx::AS3::ClassTraits::Traits *v4; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *pV; // ebx
  char *Name; // edi
  const Scaleform::GFx::AS3::ClassTraits::Traits *v7; // esi
  Scaleform::GFx::ASStringNode *v8; // eax
  unsigned int RefCount; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> result; // [esp+4h] [ebp-4h] BYREF

  v3 = (const Scaleform::GFx::AS3::ClassInfo *)ci;
  v4 = 0;
  if ( *((_DWORD *)ci->pData + 3) )
  {
    pV = Scaleform::GFx::AS3::VM::MakeInternedNamespace(
           vm,
           &result,
           NS_Public,
           *(Scaleform::GFx::ASStringNode **)(*((_DWORD *)ci->pData + 3) + 8))->pV;
    Name = (char *)v3->Type->Parent->Name;
    ci = Scaleform::GFx::ASStringManager::CreateConstStringNode(
           vm->StringManagerRef->pStringManager,
           Name,
           strlen(Name),
           0);
    ++ci->RefCount;
    v7 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(vm, (const Scaleform::GFx::ASString *)&ci, pV, appDomain);
    v8 = ci;
    --ci->RefCount;
    if ( !v8->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v8);
    if ( pV && ((unsigned __int8)pV & 1) == 0 )
    {
      RefCount = pV->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
      {
        pV->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pV);
      }
    }
    return v7;
  }
  return v4;
}
