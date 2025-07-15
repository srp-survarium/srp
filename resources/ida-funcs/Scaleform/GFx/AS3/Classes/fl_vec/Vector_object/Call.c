void __thiscall Scaleform::GFx::AS3::Classes::fl_vec::Vector_object::Call(
        Scaleform::GFx::AS3::Classes::fl_vec::Vector_object *this,
        const Scaleform::GFx::AS3::Value *__formal,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value *v6; // edi
  Scaleform::GFx::AS3::Traits *pObject; // eax
  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_object *v8; // esi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *Instance; // eax
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *pV; // ebx
  Scaleform::GFx::AS3::Class *Constructor; // eax
  const char ***v12; // eax
  Scaleform::GFx::ASStringNode *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v14; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v16; // eax
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::VM *v18; // esi
  const Scaleform::GFx::AS3::VM::Error *v19; // eax
  Scaleform::GFx::ASStringNode *v20; // eax
  Scaleform::StringDataPtr v21; // [esp-8h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::VM::Error v22; // [esp+10h] [ebp-8h] BYREF

  if ( argc == 1 )
  {
    v6 = argv;
    if ( (argv->Flags & 0x1F) != 0
      && ((argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt)
      && (pObject = this->pTraits.pObject,
          v8 = (Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_object *)pObject[1].__vftable,
          Scaleform::GFx::AS3::VM::GetValueTraits(pObject->pVM, argv) != v8) )
    {
      Instance = Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_object::MakeInstance(
                   (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&argc,
                   v8);
      pV = Instance->pV;
      Constructor = Scaleform::GFx::AS3::Traits::GetConstructor(Instance->pV->pTraits.pObject);
      if ( Scaleform::GFx::AS3::ArrayBase::AppendCoerce(
             &pV->V,
             v6,
             (Scaleform::GFx::AS3::ClassTraits::Traits *)Constructor->pTraits.pObject[1]._pRCC) )
      {
        Scaleform::GFx::AS3::Value::Assign(result, pV);
      }
      else
      {
        v12 = (const char ***)v8->GetName(v8, (Scaleform::GFx::ASString *)&result);
        pVM = (Scaleform::GFx::ASStringNode *)this->pTraits.pObject->pVM;
        Scaleform::StringDataPtr::StringDataPtr(&v21, **v12);
        Scaleform::GFx::AS3::VM::Error::Error(&v22, (Scaleform::GFx::AS3::VM_vtbl *)0x40A, pVM, v6, v21);
        Scaleform::GFx::AS3::VM::ThrowTypeError((Scaleform::GFx::AS3::VM *)pVM, v14);
        pNode = v22.Message.pNode;
        --v22.Message.pNode->RefCount;
        if ( !pNode->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
        v16 = (Scaleform::GFx::ASStringNode *)result;
        --result->value.VS._2.VObj;
        if ( !v16->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v16);
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
    v18 = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v22, eCoerceArgumentCountError, (Scaleform::String)v18, argc);
    Scaleform::GFx::AS3::VM::ThrowRangeError(v18, v19);
    v20 = v22.Message.pNode;
    --v22.Message.pNode->RefCount;
    if ( !v20->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v20);
  }
}
