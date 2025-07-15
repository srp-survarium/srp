void __thiscall Scaleform::GFx::AS3::Classes::fl::Object::Construct(
        Scaleform::GFx::AS3::Classes::fl::Object *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv,
        bool extCall)
{
  Scaleform::GFx::AS3::Traits *pObject; // eax
  unsigned int v6; // esi
  const Scaleform::GFx::AS3::ThunkInfo *VThunk; // esi
  Scaleform::GFx::AS3::Classes::Function *Constructor; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::ThunkFunction> *ThunkFunction; // eax

  pObject = this->pTraits.pObject;
  if ( !argc )
    goto LABEL_8;
  v6 = argv->Flags & 0x1F;
  if ( v6 == 5 )
  {
    VThunk = argv->value.VS._1.VThunk;
    Constructor = (Scaleform::GFx::AS3::Classes::Function *)Scaleform::GFx::AS3::Traits::GetConstructor(pObject->pVM->TraitsFunction.pObject->ITraits.pObject);
    ThunkFunction = Scaleform::GFx::AS3::Classes::Function::MakeThunkFunction(
                      Constructor,
                      (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::ThunkFunction> *)&argc,
                      VThunk);
    Scaleform::GFx::AS3::Value::operator=<Scaleform::GFx::AS3::Instances::ThunkFunction>(
      result,
      (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::ThunkFunction>)ThunkFunction->pV);
    return;
  }
  if ( v6 && (v6 - 12 > 3 || argv->value.VS._1.VInt) )
    Scaleform::GFx::AS3::Value::Assign(result, argv);
  else
LABEL_8:
    (*((void (__stdcall **)(Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Traits_vtbl *))pObject[1].ForEachChild_GC
     + 12))(
      result,
      pObject[1].__vftable);
}
