void __thiscall Scaleform::GFx::AS3::Classes::fl_vec::Vector_double::Call(
        Scaleform::GFx::AS3::Classes::fl_vec::Vector_double *this,
        const Scaleform::GFx::AS3::Value *__formal,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value *v6; // edi
  Scaleform::GFx::AS3::Traits *pObject; // eax
  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_double *v8; // esi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double> *Instance; // eax
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *pV; // ebx
  const char ***v11; // eax
  Scaleform::GFx::ASStringNode *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v13; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v15; // eax
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::VM *v17; // esi
  const Scaleform::GFx::AS3::VM::Error *v18; // eax
  Scaleform::GFx::ASStringNode *v19; // eax
  Scaleform::StringDataPtr v20; // [esp-8h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::VM::Error v21; // [esp+10h] [ebp-8h] BYREF

  if ( argc == 1 )
  {
    v6 = argv;
    if ( (argv->Flags & 0x1F) != 0
      && ((argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt)
      && (pObject = this->pTraits.pObject,
          v8 = (Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_double *)pObject[1].__vftable,
          Scaleform::GFx::AS3::VM::GetValueTraits(pObject->pVM, argv) != v8) )
    {
      Instance = Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_double::MakeInstance(
                   (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double> *)&argc,
                   v8);
      pV = Instance->pV;
      if ( Scaleform::GFx::AS3::ArrayBase::AppendCoerce(
             &Instance->pV->V,
             v6,
             Instance->pV->pTraits.pObject->pVM->TraitsNumber.pObject) )
      {
        Scaleform::GFx::AS3::Value::Assign(result, pV);
      }
      else
      {
        v11 = (const char ***)v8->GetName(v8, (Scaleform::GFx::ASString *)&result);
        pVM = (Scaleform::GFx::ASStringNode *)this->pTraits.pObject->pVM;
        Scaleform::StringDataPtr::StringDataPtr(&v20, **v11);
        Scaleform::GFx::AS3::VM::Error::Error(&v21, (Scaleform::GFx::AS3::VM_vtbl *)0x40A, pVM, v6, v20);
        Scaleform::GFx::AS3::VM::ThrowTypeError((Scaleform::GFx::AS3::VM *)pVM, v13);
        pNode = v21.Message.pNode;
        --v21.Message.pNode->RefCount;
        if ( !pNode->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
        v15 = (Scaleform::GFx::ASStringNode *)result;
        --result->value.VS._2.VObj;
        if ( !v15->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v15);
      }
      if ( ((unsigned __int8)pV & 1) == 0 )
      {
        RefCount = pV->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          pV->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pV);
        }
      }
    }
    else
    {
      Scaleform::GFx::AS3::Value::Assign(result, v6);
    }
  }
  else
  {
    v17 = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v21, eCoerceArgumentCountError, (Scaleform::String)v17, argc);
    Scaleform::GFx::AS3::VM::ThrowRangeError(v17, v18);
    v19 = v21.Message.pNode;
    --v21.Message.pNode->RefCount;
    if ( !v19->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v19);
  }
}
