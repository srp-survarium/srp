void __thiscall Scaleform::GFx::AS3::Classes::fl::Object::Construct(
        Scaleform::GFx::AS3::Classes::fl::Object *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv,
        bool extCall)
{
  Scaleform::GFx::AS3::Traits *pObject; // eax
  const Scaleform::GFx::AS3::Traits *v6; // edi
  unsigned int v7; // edx
  const Scaleform::GFx::AS3::ThunkInfo *VThunk; // esi
  Scaleform::GFx::AS3::Classes::Function *Constructor; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::ThunkFunction> *ThunkFunction; // eax

  pObject = this->pTraits.pObject;
  v6 = (const Scaleform::GFx::AS3::Traits *)pObject[1].__vftable;
  if ( !argc )
    goto LABEL_8;
  v7 = argv->Flags & 0x1F;
  if ( v7 == 5 )
  {
    VThunk = argv->value.VS._1.VThunk;
    Constructor = (Scaleform::GFx::AS3::Classes::Function *)Scaleform::GFx::AS3::Traits::GetConstructor(pObject->pVM->TraitsFunction.pObject->ITraits.pObject);
    ThunkFunction = Scaleform::GFx::AS3::Classes::Function::MakeThunkFunction(
                      Constructor,
                      (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::ThunkFunction> *)&argc,
                      VThunk,
                      v6);
    Scaleform::GFx::AS3::Value::operator=<Scaleform::GFx::AS3::Instances::ThunkFunction>(
      result,
      (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::ThunkFunction>)ThunkFunction->pV);
    return;
  }
  if ( v7 && (v7 - 12 > 3 || argv->value.VS._1.VInt) )
    Scaleform::GFx::AS3::Value::Assign(result, argv);
  else
LABEL_8:
    v6->__vftable[1].ForEachChild_GC(
      v6,
      (Scaleform::GFx::AS3::RefCountCollector<328> *)result,
      (void (__cdecl *)(Scaleform::GFx::AS3::RefCountCollector<328> *, const Scaleform::GFx::AS3::RefCountBaseGC<328> **, const Scaleform::GFx::AS3::RefCountBaseGC<328> *))v6);
}
