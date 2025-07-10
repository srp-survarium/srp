void __thiscall Scaleform::GFx::AS3::VM::exec_newcatch(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::VMAbcFile *file,
        Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo *e)
{
  Scaleform::GFx::AS3::Classes::fl::Catch **pObject; // edi
  Scaleform::GFx::AS3::Instances::fl::Catch *pV; // ecx
  bool v6; // zf
  Scaleform::GFx::AS3::Value *pCurrent; // eax
  Scaleform::GFx::AS3::Value v8; // [esp+0h] [ebp-10h] BYREF

  pObject = (Scaleform::GFx::AS3::Classes::fl::Catch **)this->TraitsCatch.pObject->ITraits.pObject;
  if ( !pObject[17] )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl::Catch **))(*pObject)[1]._pRCC)(pObject);
  pV = Scaleform::GFx::AS3::Classes::fl::Catch::MakeInstance(
         pObject[17],
         (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Catch> *)&e,
         file,
         e)->pV;
  v6 = this->OpStack.pCurrent++ == (Scaleform::GFx::AS3::Value *)-16;
  pCurrent = this->OpStack.pCurrent;
  v8.Bonus.pWeakProxy = 0;
  v8.Flags = 12;
  *(_QWORD *)&v8.value.VNumber = (unsigned int)pV;
  if ( !v6 )
  {
    pCurrent->value.VS._1.VInt = (int)pV;
    pCurrent->Flags = 12;
    pCurrent->Bonus.pWeakProxy = 0;
    pCurrent->value.VS._2.VObj = 0;
    Scaleform::GFx::AS3::Value::AddRefInternal(&v8);
  }
  Scaleform::GFx::AS3::Value::ReleaseInternal(&v8);
}
