Scaleform::GFx::ASString *__cdecl Scaleform::GFx::AS3::FindClassTraits(
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Multiname *mn,
        Scaleform::GFx::ASStringNode *appDomain)
{
  const Scaleform::GFx::AS3::Multiname *v3; // ebp
  Scaleform::GFx::ASString *result; // eax
  Scaleform::GFx::AS3::GASRefCountBase *pObject; // edi
  Scaleform::GFx::AS3::RefCountCollector<328> *pRCC; // ecx
  _DWORD *v7; // edi
  unsigned int v8; // esi
  Scaleform::GFx::AS3::VMAppDomain *v9; // edx
  const Scaleform::GFx::AS3::ClassTraits::Traits *v10; // ebx
  Scaleform::GFx::ASStringNode *v11; // eax
  unsigned int size; // [esp+4h] [ebp-4h]

  v3 = mn;
  result = 0;
  if ( (mn->Kind & 3u) <= 1 )
    return Scaleform::GFx::AS3::VM::Resolve2ClassTraits(vm, mn, appDomain);
  pObject = mn->Obj.pObject;
  pRCC = pObject[1]._pRCC;
  v7 = &pObject[1].__vftable;
  v8 = 0;
  size = (unsigned int)pRCC;
  if ( pRCC )
  {
    do
    {
      v9 = (Scaleform::GFx::AS3::VMAppDomain *)appDomain;
      mn = (const Scaleform::GFx::AS3::Multiname *)v3->Name.value.VS._1.VInt;
      ++mn->Name.Bonus.pWeakProxy;
      v10 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(
              vm,
              (const Scaleform::GFx::ASString *)&mn,
              *(Scaleform::GFx::AS3::Instances::fl::Namespace **)(*v7 + 4 * v8),
              v9);
      v11 = (Scaleform::GFx::ASStringNode *)mn;
      --mn->Name.Bonus.pWeakProxy;
      if ( !v11->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v11);
      if ( v10 )
        break;
      ++v8;
    }
    while ( v8 < size );
    return (Scaleform::GFx::ASString *)v10;
  }
  return result;
}
